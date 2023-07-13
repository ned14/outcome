/* Example use of std::error implicit conversion
(C) 2018-2019 Niall Douglas <http://www.nedproductions.biz/> (5 commits)
File Created: Sept 2018


Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License in the accompanying file
Licence.txt or at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.


Distributed under the Boost Software License, Version 1.0.
    (See accompanying file Licence.txt or copy at
          http://www.boost.org/LICENSE_1_0.txt)
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  // for sprintf

#if !defined(__GNUC__) || __GNUC__ > 6  // GCC 6 chokes on this

#include "../../../include/outcome/experimental/status_result.hpp"
#include "../../../include/outcome/experimental/status-code/include/status-code/nested_status_code.hpp"

/* Original note to WG21:

This code is to prove that proposed P1028 `std::error` need not be more
than two CPU registers in size, yet it can still transport arbitrary
payload.

We firstly will define a custom code domain for a `file_io_error` code whose
value type carries __FILE__ and __LINE__ (i.e. `source_location`) in
addition to the cause of the error. This is what one would expect end
users to do in order to define a specialised failure type local to
a specific piece of code, or library. In our case, `file_io_error`
will be lightweight and deterministic by being trivially copyable.

We secondly will tell the type system that an implicit conversion
between `file_io_error` and `error` exists via `make_status_code_ptr()`.
This bundles the `file_io_error` instance into dynamically allocated
memory, and returns an `error` instance referring to that.

Thus if under P0709 a function with `throws(file_io_error)` is called
by a function with merely `throws(std::error)`, a `std::error` can be
**implicitly** constructed by the compiler from the `file_io_error`. I
prove this in code below (see end).
*/

/********************** Example boilerplate begins ***********************/

//! [preamble]
namespace outcome_e = OUTCOME_V2_NAMESPACE::experimental;

// To define a `file_io_error` which participates in the P1028 world
// of `std::error`, we must first declare, then define, a custom code
// domain which extends `posix_code` (the std error coding for POSIX
// failures). The following is fairly standard boilerplate for defining
// a custom code domain. It is analogous to defining a custom `std::error_category`.

class _file_io_error_domain;
// We define `file_io_error` to be the status code whose domain is `_file_io_error_domain`.
using file_io_error = outcome_e::status_code<_file_io_error_domain>;

// Now we define `_file_io_error_domain`.
class _file_io_error_domain : public outcome_e::posix_code::domain_type
{
  using _base = typename outcome_e::posix_code::domain_type;
  //! [preamble]
  //! [value_type]
public:
  // This is the value type for `file_io_error`. We add line number and source file path.
  struct value_type
  {
    typename outcome_e::posix_code::value_type errcode;  // from POSIX, as we inherit from _posix_code_domain

    // Our additional payload
    int lineno;        // from __LINE__
    const char *file;  // from __FILE__
    // Could also place a backtrace of void *[16] here ...
  };
  //! [value_type]
  //! [constructor]
  // unique id must be from a hard random number source
  // Use https://www.random.org/cgi-bin/randbyte?nbytes=8&format=h to get a hard random 64 bit id.
  // Do NOT make up your own value. Do NOT use zero.
  constexpr explicit _file_io_error_domain(typename _base::unique_id_type id = 0x230f170194fcc6c7) noexcept : _base(id) {}
  static inline constexpr const _file_io_error_domain &get();
  //! [constructor]
  //! [string_ref]
  // Return the name of our custom code domain
  virtual _base::string_ref name() const noexcept override final  // NOLINT
  {
    static string_ref v("file i/o error domain");
    return v;  // NOLINT
  }
  //! [string_ref]
  //! [message]
  // Return a string describing a specific code. We will return the
  // string returned by our POSIX code base domain, with the source
  // file and line number appended
  virtual _base::string_ref _do_message(const outcome_e::status_code<void> &code) const noexcept override final  // NOLINT
  {
    assert(code.domain() == *this);

    // Fetch message from base domain (POSIX)
    auto msg = _base::_do_message(code);
    const auto &c1 = static_cast<const file_io_error &>(code);  // NOLINT
    const value_type &v = c1.value();

    // Append my source file and line number
    if(v.file == nullptr)
    {
      return msg;
    }
    size_t length = strlen(v.file) + 16 + msg.size();
    auto *p = static_cast<char *>(malloc(length));  // NOLINT
    if(p == nullptr)
    {
      return _base::string_ref("failed to get message from system");
    }
    sprintf(p, "%s (%s:%d)", msg.data(), v.file, v.lineno);

    // Return as atomically reference counted string
    return _base::atomic_refcounted_string_ref(p, length);
  }
};
//! [message]
//! [constexpr_source]
// 100% constexpr instantiation
constexpr _file_io_error_domain file_io_error_domain;
inline constexpr const _file_io_error_domain &_file_io_error_domain::get()
{
  return file_io_error_domain;
}
//! [constexpr_source]


//! [implicit_conversion]
// Now tell `error` how it can implicitly construct from `file_io_error`.
// This is done by us defining a free function called `make_status_code()`
// which is discovered using ADL. `error` is an alias to the refinement
// `status_code<erased<intptr_t>>` which is a status code whose value type
// has been erased into an `intptr_t`. `status_code<erased<intptr_t>>`
// (i.e. `error`) are move bitcopying (P1029) i.e. they are move-only
// types whose move operation is defined to leave the source in the same
// representation as a default constructed instance, and for whose
// non-trivial destructor when called upon a default constructed instance
// is guaranteed to do nothing.
inline outcome_e::system_code make_status_code(file_io_error v)
{
  // `make_nested_status_code()` dynamically allocates memory to store an
  // instance of `file_io_error`, then returns a status code whose domain
  // specifies that its value type is a pointer to `file_io_error`. The
  // domain is a templated instance which indirects all observers of the
  // status code to the pointed-to status code.
  //
  // Note that the status code returned's value type is a pointer, which
  // by definition fits into `intptr_t` and is trivially copyable.
  // Therefore `system_code` (which is also a type alias to
  // `status_code<erased<intptr_t>>`) is happy to implicitly construct
  // from the status code returned by `make_nested_status_code()`.
  return make_nested_status_code(std::move(v));
}
//! [implicit_conversion]


/********************** Proof it works begins ***********************/

#include <memory>
#include <utility>

struct file_deleter
{
  void operator()(FILE *h) const
  {
    if(h != nullptr)
      ::fclose(h);
  }
};
using file_handle = std::unique_ptr<FILE, file_deleter>;

//! [typedef]
template <class T, class E = outcome_e::error>
using result =  //
outcome_e::status_result<T, E, outcome_e::policy::default_status_result_policy<T, E>>;
//! [typedef]
//! [open_file]
result<file_handle, file_io_error> open_file(const char *path)  // models throws(file_io_error)
{
  file_handle ret(::fopen(path, "r"));
  if(ret)
    return ret;
  return file_io_error({errno, __LINE__, __FILE__});
}

result<void> open_resource()  // models throws(std::error)
{
  for(;;)
  {
    result<file_handle, file_io_error> r = open_file("some file");
    if(r)
      break;
    file_io_error e = r.error();
    if(e != outcome_e::errc::resource_unavailable_try_again)
    {
      // NOTE this implicitly converts from `file_io_error` to `error` via the
      // `make_status_code()` free function customisation point defined above.
      return e;
    }
  }
  // success continues here ...
  return outcome_e::success();
}

int main(void)
{
  result<void> r = open_resource();
  if(r)
    printf("Success!\n");
  else
  {
    auto e = std::move(r).error();
    // A quick demonstration that the indirection works as indicated
    printf("Returned error has a code domain of '%s', a message of '%s'\n", e.domain().name().c_str(), e.message().c_str());
    printf("\nAnd semantically comparing it to 'errc::no_such_file_or_directory' = %d\n", e == outcome_e::errc::no_such_file_or_directory);
  }
}
//! [open_file]

#else
  
int main(void)
{
  return 0;
}

#endif
