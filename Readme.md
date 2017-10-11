master branch unit test status: Linux & MacOS: [![Build Status](https://travis-ci.org/ned14/outcome.svg?branch=master)](https://travis-ci.org/ned14/outcome) Windows: [![Build status](https://ci.appveyor.com/api/projects/status/q8s29koot2v3nity/branch/master?svg=true)](https://ci.appveyor.com/project/ned14/outcome/branch/master)

develop branch unit test status: Linux & MacOS: [![Build Status](https://travis-ci.org/ned14/outcome.svg?branch=develop)](https://travis-ci.org/ned14/outcome) Windows: [![Build status](https://ci.appveyor.com/api/projects/status/q8s29koot2v3nity/branch/develop?svg=true)](https://ci.appveyor.com/project/ned14/outcome/branch/develop)

CTest dashboard: http://my.cdash.org/index.php?project=Boost.Outcome

Documentation: https://ned14.github.io/outcome/

## Usage as a single header file

Outcome v2 comes in single header file form. This is regenerated per commit. To fetch
on Linux:

```
wget https://github.com/ned14/outcome/raw/develop/single-header/outcome.hpp
```

On BSD and OS X:

```
fetch https://github.com/ned14/outcome/raw/develop/single-header/outcome.hpp
```

On Windows, simply download the raw file from above and place it wherever it suits you.

## Post peer review todo:

 - [x] Implement `result<T, EC>` as per peer review feedback
 - [x] Write up each API with C++ standardese and feed to Standardese
 - [x] Replace doxygen with Standardese + Hugo
 - [x] Implement `outcome<T, EC, E>` as per peer review feedback
 - [x] Replace existing Outcome with peer review Outcome
 - [x] Retarget unit test suite at peer review Outcome
 - [x] Redo .natvis
 - [x] Replace SFINAEd constructors with Concepts instead.
 - [x] Manually copy & paste together a basic synopsis of result and outcome
 to serve as "the docs" until Standardese can be persuaded to produce better
 output.
 - [x] Make an "expected" policy and `expected<T, E>` from it.
 - [x] Code snippets in docs should provide link to github original.
 - [ ] Conan package support
 
Maybe?
 - [ ] Make `result`'s explicit converting constructors accept any type providing a
 `.has_value()`, `.value()` and `.error()` (i.e. Expected)

# Changes since v1:

As per the Boost peer review feedback, v2 Outcome has been pared down to
no more than the barest of bare essentials. The plan is to occupy the lowest
level in a generalised [C++ Monadic interface (P0650R0)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0650r0.pdf)
as an adjunct to the [primary C++ monad object Expected (P0323R2)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0323r2.pdf).
You can find a reference implemenetation for the proposed standardised Result
at https://github.com/ned14/outcome/tree/develop/include/outcome/experimental/.

- Major changes:
   - You can now customise types directly, so `result<T, EC =
   std::error_code>` and `outcome<T, EC = std::error_code, P|E =
   std::exception_ptr>`.
   - Default construction no longer permitted.
   - Empty state no longer possible.
   - Variant storage gone, it's now a standard layout type. This enables returning
   an error code with additional exception ptr as per Peter Dimov's
   request. It also very considerably simplifies implementation.
     - You can choose between a payload type `P` or an exception ptr
     `E`, so  an error code with additional arbitrary non-exception ptr
     payload `P` is also possible.
     - C interoperability is now available, and some C macros for
     working with `struct result_TYPE` are available in result.h.
   - Concepts TS is used when available, otherwise a partial
   SFINAE-based emulation is used.
   - Types `EC`, `P` and `E` must be default constructible. `T` need not
   be so.
   - Constructors now follow those of `std::variant`, so it will
   implicitly convert from any input convertible to any of its types so
   long as it is not ambiguous. As with `std::variant`, in place
   construction is achieved via `in_place_type<T>` tagging. Explicit
   conversion construction also works, we replicate `std::variant`'s
   value semantics very closely despite not having variant storage.
   - New type sugar types `success<T>`, `failure<EC, E>` for being
   explicit about which kind of `result` or `outcome` we are constructing.
   - `.has_value()`, `.has_error()` and `.has_exception()` now only
   return true if that specific member is present. A new
   `.has_failure()` is true if errored or excepted.
   - `.value()` throws exception or `std::system_error(EC)` if no value
   or returns a reference to the value.
   - `.error()` throws `bad_result_access|bad_outcome_access` if no
   error or returns a reference to the error.
   - `.payload()` throws `bad_result_access|bad_outcome_access` if no
   payload or returns a reference to the payload.
   - `.exception()` throws `bad_result_access|bad_outcome_access` if no
   exception or returns a reference to the exception.
   - `.failure()` returns the exception if present, else a synthesised
   `exception_ptr` from the error, else a null `exception_ptr`.
   - `.assume_value()`, `.assume_error()`, `.assume_payload()` and
   `.assume_exception()` all provide runtime unchecked access to the
   underlying storage.
   - The doxygen docs which were widely criticised have been replaced
   with an experimental Standardese + Hugo based solution instead.

 - Stuff removed:
   - Anything even faintly smelling of monads.
   - All the `make_XXX()` functions. The `std::variant` based constructor
   interface make them no longer necessary.
   - All preprocessor assembly of code fragments. You now have an
   equally complex rabbit warren of policy and trait driven composited
   fragments of template into implementation. Standardese (the
   documentation tool) really struggles with this. Doxygen simply blows
   up.
   - All macro based customisation points. We now use an ADL function
   based customisation point design, 100% C++.
   - `error_code_extended` is gone for now. It is believed that via the
   ADL customisation points you can easily implement your own. There is
   a worked example at
   https://github.com/ned14/outcome/blob/develop/example/error_code_extended.cpp.
   - Any operators apart from boolean test, strict equality and
   inequality comparison.
   - Any ability to change state after construction.
   - LEWG `expected<T, E>` is gone. The new templatised `result<T, E>`
   is a much slimmer edition of Expected providing the same core
   functionality but in a much smaller package and with
   `std::variant<>`'s look and feel instead of new type sugar like
   `make_unexpected`.

 - Stuff retained:
   - `OUTCOME_TRY`, `OUTCOME_TRYV`, `OUTCOME_TRYX` all work as before.
   - `noexcept` propagation from types chosen works correctly.
   - Triviality of copy, move and destruction from types
   chosen is propagated correctly.
   - v1 unit test has been almost entirely ported over to v2 without
   much change other than what was needed. Porting v1 based code to v2
   should be 95% possible using find regex in files and replace.

 - Stuff gained:
   - Type traits now work direct on all member functions. Member
   variable traits are no longer necessary, and so have been removed.
   - Outcome v2 now conforms in every way to a typical STL vocabulary
   type. No unusual design tradeoffs or changes.

 - Stuff lost:
   - Outcome v2 needs a much newer compiler than before: clang 4 or
   better, GCC 6 or better, ideally with Concepts enabled. Sorry, no
   MSVC support, I've submitted repros of the ICEs for VS2017.3. I've
   been careful to keep MSVC's frontend happy, the ICEs are all in the
   backend, so it'll likely start working soon.
   - Compile time load may now be higher than with v1. Almost every
   function is compile time enabled depending on input types (we do use
   template variables to cache previously calculated results) with
   calculated noexcept. It'll get a lot better as compilers make better
   use of the boolean logic supplied by Concepts.

## Commits and tags in this git repository can be verified using:
<pre>
-----BEGIN PGP PUBLIC KEY BLOCK-----
Version: GnuPG v2

mDMEVvMacRYJKwYBBAHaRw8BAQdAp+Qn6djfxWQYtAEvDmv4feVmGALEQH/pYpBC
llaXNQe0WE5pYWxsIERvdWdsYXMgKHMgW3VuZGVyc2NvcmVdIHNvdXJjZWZvcmdl
IHthdH0gbmVkcHJvZCBbZG90XSBjb20pIDxzcGFtdHJhcEBuZWRwcm9kLmNvbT6I
eQQTFggAIQUCVvMacQIbAwULCQgHAgYVCAkKCwIEFgIDAQIeAQIXgAAKCRCELDV4
Zvkgx4vwAP9gxeQUsp7ARMFGxfbR0xPf6fRbH+miMUg2e7rYNuHtLQD9EUoR32We
V8SjvX4r/deKniWctvCi5JccgfUwXkVzFAk=
=puFk
-----END PGP PUBLIC KEY BLOCK-----
</pre>

</center>
