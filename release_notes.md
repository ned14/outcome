<center><table border="0">
<tr>
<td align="center"> <a href="http://my.cdash.org/index.php?project=Boost.Outcome">CTest summary</a><br/><a href="http://my.cdash.org/index.php?project=Boost.Outcome">dashboard</a> </td>
<td align="center"> <a href="https://travis-ci.org/ned14/boost.outcome">Linux CI:</a><img src="https://travis-ci.org/ned14/boost.outcome.svg?branch=master"/> </td>
<td align="center"> <a href="https://ci.appveyor.com/project/ned14/boost-outcome/branch/master">Windows CI:</a><img src="https://ci.appveyor.com/api/projects/status/roe4dacos4gnlu66/branch/master?svg=true"/> </td>
<td align="center"> <a href="https://coveralls.io/r/ned14/boost.outcome?branch=master">Coverage:</a><img src="https://coveralls.io/repos/ned14/boost.outcome/badge.svg?branch=master"/> </td>
</tr>
</table></center>

\tableofcontents

\section description Description

This is the proposed Boost.Outcome library, a Boost C++ 14 library providing
a factory and family of policy driven lightweight monadic value-or-error transports with
the convenience specialisations of `outcome<T>`, `result<T>` and `option<T>`.
Its main intended usage is as an ultra light weight error handling framework,
providing a more expressive and type safe alternative to error code integers
or enums, yet much lower overhead than exception throws, and unlike alternatives
it works perfectly with exceptions and RTTI disabled. It may be lower overhead
than the `expected<T, E>` heading for standardisation, if not then it
is certainly more convenient to program with for error handling than using
`expected<T, E>` as it was specifically designed and tailored for this purpose.

If you are familiar with C++ 17's `optional<T>` or Rust's `Result<T>` and `Option<T>`,
you will find almost identical semantics in the transports provided here.
One can therefore write systems programming code using these transports in C++
in the same design pattern as when writing in Rust or Swift.

\section prerequisites Prerequisites and Installation

Boost.Outcome is a header only library known to work on these compilers or better:
- GCC 5.0
- clang 3.7
- VS2015 Update 2
- clang 3.7 with Microsoft Codegen ("winclang")

Its sole mandatory dependency is on https://github.com/ned14/boost-lite, a minimal
emulation of Boost for C++ 14. A copy is embedded internally so a copy of Boost is
**not** required to use this library. You can simply drop Outcome into your project
and go, including Outcome using one of these depending on how you install Outcome:

- \code #include <boost/outcome.hpp> \endcode
- \code #include "boost.outcome/include/boost/outcome.hpp" \endcode

Each commit is tested by Travis and Appveyor. A nightly cronjob figures out which
latest commit all tests passed for and pushes a distribution to the following
package repositories:

\subsection windows Installing on Windows

If you are using VS15 or better it comes with VCPkg, a package manager. Open
a Developer Tools prompt and type:

`vcpkg install boost.outcome`

Once installed it is available for usage in any Visual Studio project.

\subsection linux Installing on Ubuntu/Debian

<pre>add-apt-repository ppa:ned14/boost.outcome
apt-get install boost.outcome</pre>

\subsection osx Installing on OS X

Assuming you have <a href="http://brew.sh/">homebrew</a> installed, then:

<pre>brew tap ned14/tap
brew install boost.outcome</pre>

\subsection source Installing via source archive

Visit https://dedi4.nedprod.com/static/files/ and download the latest boost.outcome
tarball. Tarballs are only uploaded if everything built and all tests passed.

\subsection repo Installing via git subrepository

`git submodule add https://github.com/ned14/boost.outcome`

The master branch is automatically set to whichever was the last commit on develop
branch to pass all unit tests.

\section support Support

<a href="https://stackoverflow.com/">StackOverflow</a> with the boost-outcome tag is the preferred place to ask questions on usage.

If you have a problem, please review the FAQ and the wiki. Searching
<a href="https://github.com/ned14/boost.outcome/issues">the issues</a>
for your problem is also a good idea. If you are encountering what you
think is a bug, please open an issue.

To be continued ...
