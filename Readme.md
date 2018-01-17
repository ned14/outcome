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
 - [x] Restore testing of C++ exceptions disabled.
 - [x] Code snippets in doc/src/snippets should be compiled.
 - [x] Conan package support
 - [x] Make `result`'s explicit converting constructors accept any type providing a
 `.has_value()`, `.value()` and `.error()` (i.e. Expected)
 - [x] Regen docs and submit bugs to Standardese
 - [x] Translate docs into Boost edition
 - [x] Get AFIO et al working with latest Outcome
 - [x] Hyperlink all the tutorial mentions of things to the reference docs.
 - [x] Freshen list of tests in Boost edition
 - [x] Test with AFIO before code freeze
 - [x] Check all files in Boost edition have licence boilerplate (issue #38)
 - [x] Do clang-tidy pass until it's completely clean. Sigh.
 - [ ] Disable develop to master branch merging
 - [ ] Disable documentation updates by Travis

# Changes since v1:

As per the Boost peer review feedback, v2 Outcome has been pared down to
no more than the barest of bare essentials. The plan is to participate
in a generalised [C++ Monadic interface (P0650R0)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0650r0.pdf)
so all the monadic stuff is removed.

- Major changes:
   - You can now customise types directly, same as Expected, so `result<T, EC =
   std::error_code>` and `outcome<T, EC = std::error_code, E =
   std::exception_ptr>`.
   - Default construction no longer permitted, as per review feedback.
   - Empty state no longer possible, as per review feedback. Write
   `optional<result<T, E>>` if you want that.
   - As per review feedback, Variant storage gone, it's now a struct-based
   type for simplicity.
   - `EC` and `E` types are interpreted via `trait::has_error_code_v<EC>`
   and `trait::has_exception_ptr_v<E>`. This allows custom payloads to
   be easily attached to `error_code` and `exception_ptr`.
   - C interoperability is now available, and some C macros for
   working with `struct result_TYPE` are available in result.h.
   - Concepts TS is used when available, otherwise a partial
   SFINAE-based emulation is used.
   - Types `EC` and `E` must be default constructible. `T` need not
   be so.
   - Constructors now follow those of `std::variant`, so it will
   implicitly convert from any input constructible to any of its types so
   long as it is not ambiguous. As with `std::variant`, in place
   construction is achieved via `in_place_type<T>` tagging. Explicit
   conversion construction also works, we replicate `std::variant`'s
   value semantics very closely despite not having variant storage.
   - New type sugar types `success<T>`, `failure<EC, E>` for being
   explicit about which kind of `result` or `outcome` we are constructing.
   - We implement construction from `ValueOrError` Concept matching
   types which include `std::expected<T, E>`, as per the `ValueOrError`
   paper https://wg21.link/P0786.
   - `.has_value()`, `.has_error()` and `.has_exception()` now only
   return true if that specific member is present. A new
   `.has_failure()` is true if errored or excepted.
   - `.value()` throws `bad_result_access|bad_outcome_access`
   or `std::system_error(EC)` or `std::rethrow_exception(EC)` or UB
   if no value or returns a reference to the value.
   - `.error()` throws `bad_result_access|bad_outcome_access` or UB if no
   error or returns a reference to the error.
   - `.exception()` throws `bad_result_access|bad_outcome_access` or UB if no
   exception or returns a reference to the exception.
   - `.failure()` returns the exception if present, else a synthesised
   `exception_ptr` from the error, else a null `exception_ptr`.
   - `.assume_value()`, `.assume_error()`, `.assume_payload()` and
   `.assume_exception()` all provide runtime unchecked UB access to the
   underlying storage.
   - The doxygen docs which were widely criticised have been replaced
   with an experimental Standardese + Hugo based solution instead.

 - Stuff removed:
   - Anything even faintly smelling of monads.
   - All the `make_XXX()` functions. The `std::variant` based constructor
   interface make them no longer necessary.
   - All preprocessor assembly of code fragments. You now have an
   equally complex rabbit warren of policy and trait driven composited
   fragments of template into implementation. I did warn reviewers during
   the v1 review that a pure C++ v2 would be no better in this regard than
   the preprocessor assembled v1.
   - All macro based customisation points. We now use an ADL function
   based, or injection of type specialisation, customisation points. 100% C++.
   - `error_code_extended` is gone for now. It is believed that via the
   customisation points you can easily implement your own. There is
   a worked example at
   https://ned14.github.io/outcome/tutorial/hooks/keeping_state
   - Any operators apart from boolean test, strict equality and
   inequality comparison.
   - Any ability to change state after construction.
   - LEWG `expected<T, E>` is gone. The new `checked<T, E>`
   is a close substitute to Expected. See the FAQ entry on how to adapt
   a `result<T, E>` into an `expected<T, E>` with a simple shim class.

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
   better, GCC 6 or better, VS2017 or better. Ideally with Concepts
   enabled.
   - Compile time load may now be higher than with v1. In my own
   code, there is an approx 15% compile time regression in v2 over v1.

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
