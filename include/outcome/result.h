/* C interface for result
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: Aug 2017


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

#ifndef OUTCOME_RESULT_H
#define OUTCOME_RESULT_H

/// \output_name result_c

//! A C struct representation of `std::error_code`.
struct cxx_error_code
{
  int code;
  void *category;
};

/*! Declares a C struct representation of `result<R, S>`.
\param R The unique postfix for `struct result_##R##_##S`.
\param RD The declaration for the `R` type.
\param S The unique postfix for
\param SD The declaration for the `S` type.
*/
#define CXX_DECLARE_RESULT(R, RD, S, SD)                                                                                                                                                                                                                                                                                       \
  struct result_##R##_##S                                                                                                                                                                                                                                                                                                      \
  {                                                                                                                                                                                                                                                                                                                            \
    RD value;                                                                                                                                                                                                                                                                                                                  \
    unsigned flags;                                                                                                                                                                                                                                                                                                            \
    SD error;                                                                                                                                                                                                                                                                                                                  \
  }
/*! Declares a C struct representation of `result<R, std::error_code>`.
\param R The unique postfix for `struct result_##R##_##S`.
\param RD The declaration for the `R` type.
*/
#define CXX_DECLARE_RESULT_EC(R, RD) CXX_DECLARE_RESULT(R, RD, errorcode, struct cxx_error_code)
//! A reference to a previously declared struct by `CXX_DECLARE_RESULT(R, RD, S, SD)`
#define CXX_RESULT(R, S) struct result_##R##_##S
//! A reference to a previously declared struct by `CXX_DECLARE_RESULT_EC(R, RD)`
#define CXX_RESULT_EC(R) struct result_##R##_errorcode
//! True if a result struct has a valid value
#define CXX_RESULT_HAS_VALUE(r) (((r).flags & 1) == 1)
//! True if a result struct has a valid error
#define CXX_RESULT_HAS_ERROR(r) (((r).flags & 1) == 0)
//! True if a result struct's `error` or `code` is an `errno` domain code suitable for setting `errno` with.
#define CXX_RESULT_ERROR_IS_ERRNO(r) (((r).flags & (1 << 4)) == (1 << 4))
//! C11 generic selecting a result struct's `error` or `code` integer member.
#define CXX_RESULT_ERROR(r) _Generic((r).error, struct cxx_error_code : ((struct cxx_error_code *) &(r).error)->code, default : (r).error)
//! Convenience macro setting `errno` to a result struct's `errno` compatible error if present, or `EAGAIN` if errored but incompatible.
#define CXX_RESULT_SET_ERRNO(r) (errno = CXX_RESULT_HAS_ERROR(r) ? (CXX_RESULT_ERROR_IS_ERRNO(r) ? CXX_RESULT_ERROR(r) : EAGAIN) : 0)

#endif
