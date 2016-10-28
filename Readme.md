<center>
master branch unit test status:

Linux: [![Build Status](https://travis-ci.org/ned14/boost.outcome.svg?branch=master)](https://travis-ci.org/ned14/boost.outcome) Windows: [![Build status](https://ci.appveyor.com/api/projects/status/roe4dacos4gnlu66/branch/master?svg=true)](https://ci.appveyor.com/project/ned14/boost-outcome/branch/master) Coverage: [![Coverage Status](https://coveralls.io/repos/ned14/boost.outcome/badge.svg?branch=master)](https://coveralls.io/r/ned14/boost.outcome?branch=master) CTest dashboard: http://my.cdash.org/index.php?project=Boost.Outcome

Documentation: https://ned14.github.io/boost.outcome/

Tarballs of source with all unit tests passing: https://dedi4.nedprod.com/static/files/

Todo:
 - [ ] Add a new `-fno-exceptions` compatible Boost.Test emulation to Boost-lite and get Outcome's
unit tests passing under that.
 - [ ] Add clang-tidy support to Boost lite and get it running regularly.
 - [ ] Add macro helpers to Outcome for returning outcomes out of things which cannot return values
like constructors, and convert said exceptions/TLS back into outcomes.
  - Make use of `std::system_error(errno, system_category, "custom error message");`
 - [ ] Audit all uses of `std::error_code.code()` and replace with `std::errc::whatever` as
appropriate.
 - [ ] Split all uses of `BOOST_OUTCOME_THROW()` into separate macros for each throw site and type,
each of which default to `BOOST_OUTCOME_THROW()`.
  - `BOOST_OUTCOME_THROW()` should print a stack backtrace before fatal exiting.
 - [ ] Fix all remaining uses of `monad<T>` (e.g. doxygen docs).
 - [ ] Move the detailed `basic_monad` docs out of the group monad page and onto the front page
  - Also add a tutorial
 - [ ] Test relaxed constexpr in VS15 once that is released and delete the hack macro.
 - Jenkins to upload per commit to package distros **source packages** for these:
  - [ ] launchpad (Ubuntu, Debian). Instructions at https://help.launchpad.net/Packaging/PPA/BuildingASourcePackage
  - [ ] vcpkg (Microsoft). Instructions at https://github.com/Microsoft/vcpkg/blob/master/docs/EXAMPLES.md
  - [ ] homebrew (OS X). Instructions at http://formalfriday.club/2015/01/05/creating-your-own-homebrew-tap-and-formula.html
  - [ ] FreeBSD packages. Instructions at https://www.freebsd.org/doc/handbook/ports-poudriere.html
 - [x] Loosen explicit basic_monad constructors to allow option => result => monad implicitly.
 - [x] Pack bools in basic_promise_future_storage into value_storage_impl, thus saving 8 bytes
 - [x] Get the constexpr tests firing per-commit in Travis (and maybe Appveyor)
 - [x] Add comparison operators for monad (long overdue!). These need to be able to compare
heterogeneous monad types (add unit tests proving this).
 - [x] Add constexpr compile unit tests for when `<T>` is a LiteralType.
 - [x] Add unit tests for `result<int>` being trivially destructible
 - [x] Add debugging visualisers for Monad for VS2015 as a minimum (it's getting painful to work
on AFIO without these!)
 
Later:
 - [ ] Add monad_errc error code for when a move or copy constructor throws? If so, what about option<T>?
 - [ ] Add tribool logic programming operator overloads

</center>
