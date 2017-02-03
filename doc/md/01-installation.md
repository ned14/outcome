# Installing, building and testing Outcome {#introduction}

[TOC]

Each commit to develop branch is tested by Travis and Appveyor on Linux with GCC and clang,
OS X with Xcode and on Windows with VS2015.
A nightly cronjob figures out for which latest commit all tests passed on all those platforms and
merges that commit to master branch. From that master branch, a distribution is made to the following package
repositories.

<br><hr><br>

\section tarball Installing via source tarball

Outcome is a header only C++ library with no external dependencies and therefore requires no
compilation. <a href="https://dedi4.nedprod.com/static/files/boost.outcome-v1.0-source-latest.tar.xz">
Simply download and untar this tarball</a> and you can use Outcome via:

\code #include "boost.outcome/include/boost/outcome.hpp" \endcode

If you need a slightly older Outcome, https://dedi4.nedprod.com/static/files/boost.outcome
retains the last month of CI passing tarballs.


<br><hr><br>

\section gitsubrepo Installing via git subrepository into your project's git repository

This route has the big advantage of automatically staying up to date with bugs fixes in
Outcome. Simply do:

<pre>git submodule add https://github.com/ned14/boost.outcome
cd boost.outcome
git submodule update --init --recursive
</pre>

After this you can find Outcome in your code using:

\code #include "boost.outcome/include/boost/outcome.hpp" \endcode


<br><hr><br>

\section unittests Running the unit test suite

To run the unit test suite you will need cmake 3.1 or later installed.

<pre>
mkdir build
cd build
cmake ..
cmake --build .
ctest
</pre>

On some cmake generators (Visual Studio, Xcode) you may need to tell cmake build a configuration
like Release or Debug. Similarly, ctest needs to be told the same e.g.

<pre>
mkdir build
cd build
cmake ..
cmake --build . --config Release
ctest -C Release
</pre>

In case you are curious why there is a "noexcept" edition of the unit tests, this is
the unit test suite compiled with C++ exceptions and RTTI disabled and apart from not
including the C++ exception specific tests, is otherwise identical.
