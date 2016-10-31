<center>
master branch unit test status:

Linux: [![Build Status](https://travis-ci.org/ned14/boost.outcome.svg?branch=master)](https://travis-ci.org/ned14/boost.outcome) Windows: [![Build status](https://ci.appveyor.com/api/projects/status/roe4dacos4gnlu66/branch/master?svg=true)](https://ci.appveyor.com/project/ned14/boost-outcome/branch/master) Coverage: [![Coverage Status](https://coveralls.io/repos/ned14/boost.outcome/badge.svg?branch=master)](https://coveralls.io/r/ned14/boost.outcome?branch=master) CTest dashboard: http://my.cdash.org/index.php?project=Boost.Outcome

Documentation: https://ned14.github.io/boost.outcome/

Tarballs of source with all unit tests passing: https://dedi4.nedprod.com/static/files/

Todo:
 - [ ] Audit all uses of `std::error_code.code()` and replace with `std::errc::whatever` as
appropriate.
 - [ ] Move the detailed `basic_monad` docs out of the group monad page and onto the front page
  - Also add a tutorial
 - [ ] Test relaxed constexpr in VS15 once that is released and delete the hack macro.
 - Need to write script which uses github API to scan commits on develop branch for CI
saying all passes. If so:
  - [ ] Merge that commit from develop branch into master branch
  - [ ] Build a complete source distro and place it at https://dedi4.nedprod.com/static/files/
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

</center>
