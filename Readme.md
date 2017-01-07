<center>
master branch unit test status: Linux: [![Build Status](https://travis-ci.org/ned14/boost.outcome.svg?branch=master)](https://travis-ci.org/ned14/boost.outcome) Windows: [![Build status](https://ci.appveyor.com/api/projects/status/roe4dacos4gnlu66/branch/master?svg=true)](https://ci.appveyor.com/project/ned14/boost-outcome/branch/master)

develop branch unit test status: Linux: [![Build Status](https://travis-ci.org/ned14/boost.outcome.svg?branch=develop)](https://travis-ci.org/ned14/boost.outcome) Windows: [![Build status](https://ci.appveyor.com/api/projects/status/roe4dacos4gnlu66/branch/develop?svg=true)](https://ci.appveyor.com/project/ned14/boost-outcome/branch/develop)

Coverage: [![Coverage Status](https://coveralls.io/repos/ned14/boost.outcome/badge.svg?branch=master)](https://coveralls.io/r/ned14/boost.outcome?branch=master)

CTest dashboard: http://my.cdash.org/index.php?project=Boost.Outcome

Documentation: https://ned14.github.io/boost.outcome/

Latest tarball of source with all tests passing on Linux and Windows: https://dedi4.nedprod.com/static/files/boost.outcome-v1.0-source-latest.tar.xz

Past tarballs of source with all tests passing on Linux and Windows: https://dedi4.nedprod.com/static/files/boost.outcome

Todo:
 - [x] Use "clean" method for getting cmake to not specify /EHsc, eliminate those annoying warnings.
 - [x] Don't define BOOST_* C++ feature macros so we don't collide with Boost anymore.
 - [x] Test relaxed constexpr in VS15 once that is released and delete the hack macro.
 - [ ] `make install` needs to install dependency headers too
 - [ ] Add config where in release mode the exception throwing macros generate link errors
for symbols with the function name and line number in them.
 - [ ] Add nothrow make functions for outcomes, maybe with error lvalue ref constructor editions for results.
 - [ ] Document the exception throwing macros in the tutorial
 - [ ] Solve the apt packaging problem. Either:
   1. boost-lite cmake needs to gain the ability to be called by debian dh (see make_deb.sh).
   This would also solve building binary distros and would let us host on launchpad.
   2. Configure our own simple apt repo https://askubuntu.com/questions/529/how-to-set-up-an-apt-repository
 - Need to write script which uses github API to scan commits on develop branch for CI
saying all passes. If so:
  - [x] Merge that commit from develop branch into master branch
  - [x] Build a complete source distro and place it at https://dedi4.nedprod.com/static/files/
  - [ ] Push to:
   - [ ] launchpad (Ubuntu, Debian). Instructions at https://help.launchpad.net/Packaging/PPA/BuildingASourcePackage
   - [ ] vcpkg (Microsoft). Instructions at https://github.com/Microsoft/vcpkg/blob/master/docs/EXAMPLES.md
   - [ ] homebrew (OS X). Instructions at http://formalfriday.club/2015/01/05/creating-your-own-homebrew-tap-and-formula.html
   - [ ] FreeBSD packages. Instructions at https://www.freebsd.org/doc/handbook/ports-poudriere.html
 
Later:
 - [ ] Add monad_errc error code for when a move or copy constructor throws? If so, what about option<T>?
 - [ ] Add tribool logic programming operator overloads
 - [ ] Add macro helpers to Outcome for returning outcomes out of things which cannot return values
like constructors, and convert said exceptions/TLS back into outcomes.
  - Make use of `std::system_error(errno, system_category, "custom error message");`
 - [ ] Latest version push script really ought to test library in flat boost-lite configuration
and only push if additionally it passes with all latest master branches as well as stamped branches
 - [ ] Create new Win32 and NT error code categories and have make_errored_outcome() use those.
 Have a python script auto generate the code into separate header files. Add those to boost-lite.

</center>
