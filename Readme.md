<center>
master branch unit test status: Linux & MacOS: [![Build Status](https://travis-ci.org/ned14/boost.outcome.svg?branch=master)](https://travis-ci.org/ned14/boost.outcome) Windows: [![Build status](https://ci.appveyor.com/api/projects/status/roe4dacos4gnlu66/branch/master?svg=true)](https://ci.appveyor.com/project/ned14/boost-outcome/branch/master)

develop branch unit test status: Linux & MacOS: [![Build Status](https://travis-ci.org/ned14/boost.outcome.svg?branch=develop)](https://travis-ci.org/ned14/boost.outcome) Windows: [![Build status](https://ci.appveyor.com/api/projects/status/roe4dacos4gnlu66/branch/develop?svg=true)](https://ci.appveyor.com/project/ned14/boost-outcome/branch/develop)

CTest dashboard: http://my.cdash.org/index.php?project=Boost.Outcome

Documentation: https://ned14.github.io/boost.outcome/

Latest tarball of source with all tests passing on Linux and Windows: https://dedi4.nedprod.com/static/files/boost.outcome-v1.0-source-latest.tar.xz

Past tarballs of source with all tests passing on Linux and Windows: https://dedi4.nedprod.com/static/files/boost.outcome

Todo before Boost peer review:
 - [x] Add docs page on using Outcome from cmake
 - [ ] Write some python scripting which injects the licence boilerplate at the top
 of each source file, along with a list of contributors to that file as gleaned from
 the git history
   - [ ] Change licence to dual Apache 2.0 + Boost
 - [ ] `make install` needs to install dependency headers too. Once this is working,
 get cmake exports working
 (https://cmake.org/Wiki/CMake/Tutorials/Exporting_and_Importing_Targets#Exporting_Targets)
 and update the modular cmake docs.

 
Later:
 - [ ] Create new Win32 and NT error code categories and have make_errored_outcome() use those.
 Have a python script auto generate the code into separate header files. Add those to boost-lite.
 - [ ] Add config where in release mode the exception throwing macros generate link errors
for symbols with the function name and line number in them. This lets you track down all
potentially throwing code.
 - [ ] error_or() ought to have rvalue ref etc overloads, and exception_or()
 - [ ] Add nothrow make functions for outcomes, maybe with error lvalue ref constructor editions for results.
 - [ ] Add monad_errc error code for when a move or copy constructor throws? If so, what about option<T>?
 - [ ] Add tribool logic programming operator overloads
 - [ ] Add macro helpers to Outcome for returning outcomes out of things which cannot return values
like constructors, and convert said exceptions/TLS back into outcomes.
  - Make use of `std::system_error(errno, system_category, "custom error message");`
 - [ ] Latest version push script really ought to test library in flat boost-lite configuration
and only push if additionally it passes with all latest master branches as well as stamped branches


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
