# Installing, building and testing Outcome {#introduction}

[TOC]

Each commit to develop branch is tested by Travis and Appveyor on Linux with GCC and clang,
OS X with Xcode and on Windows with VS2015.
A nightly cronjob figures out for which latest commit all tests passed on all those platforms and
merges that commit to master branch. From that master branch, a source tarball is generated.

Under a default configuration, when you `#include "boost.outcome/include/boost/outcome.hpp"`
you will include a preprocessed single file edition for maximum build performance in
downstream projects. This can interfere with accurate bug reporting in Outcome, so if you
are diagnosing a problem in Outcome itself, predefine
the macro `BOOST_OUTCOME_DISABLE_PREPROCESSED_INTERFACE_FILE` globally. This will cause
the Outcome master include header to include Outcome's constituent files the traditional way.

If you are using CMake, you almost certainly want to use Outcome's
\ref modular_cmake "modular cmake" build support instead, as that will use Outcome as a
C++ Module on supporting compilers.


<br><hr><br>

\section tarball Installing via source tarball

Outcome is a header only C++ library with no external dependencies and therefore requires no
compilation. <a href="https://dedi4.nedprod.com/static/files/boost.outcome-v1.0-source-latest.tar.xz">
Simply download and untar this tarball</a> and you can use Outcome via:

\code #include "boost.outcome/include/boost/outcome.hpp" \endcode

If you need a slightly older Outcome, https://dedi4.nedprod.com/static/files/boost.outcome
retains the last month of CI passing tarballs.

\note On Visual Studio, linking the file "boost.outcome/include/boost/outcome/v1.0/monad.natvis"
into your project consuming Outcome will add debugger visualisation of Outcome's transports.

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


<br><hr><br>

\section modular_cmake Modular CMake build support

If you are using Outcome in a CMake project, Outcome is a "modular cmake" project
using only modern cmake 3 throughout. This lets you add the Outcome directory as a
cmake module with no unexpected consequence on the rest of your cmake. You will need
to be using cmake 3.1 or better, and cmake 3.5 or better if you want C++ Modules to work.

\code
add_subdirectory(
  "${CMAKE_CURRENT_SOURCE_DIR}/boost.outcome"  # path to outcome source
  "${CMAKE_CURRENT_BINARY_DIR}/boost.outcome"  # your choice of where to put binaries
  EXCLUDE_FROM_ALL                             # please only lazy build outcome on demand
)
\endcode

Outcome's cmake has the following useful products:
- `outcome_hl` (target): the Outcome header only library. Add this to any
`target_link_libraries()` in your cmake to bring in Outcome as a C++ Module where
available, or as a precompilable preprocessed header only library. This will also
add to your link (via `PUBLIC`) any debugger visualisation support files, any system library
dependencies and also force all consuming executables to be configured with a minimum
of C++ 14 as Outcome requires a minimum of that.
- `outcome_TEST_TARGETS` (list): a list of targets which generate Outcome's test
suite. You can append this to your own test suite if you wish to run Outcome's test
suite along with your own.
