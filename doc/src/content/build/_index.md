+++
title = "Build and install"
weight = 3
+++

Outcome v2 is feature complete, meeting the feedback from the Boost peer review in May 2017.
It is an all new code base, written entirely from scratch during the month of June 2017.
It has completed three months of maturation, and will shortly be sent back to Boost
for a second peer review. As a result, consider this library to **beta**
quality and subject change if a second review demands it.

That said, the essentials here are the same as they were in v1. Indeed most code
written for v1 should be convertible to v2 without too much effort.

## Usage as a single header file

Outcome v2 comes in single header file form. This is regenerated per commit. To fetch
on Linux:

```
wget https://github.com/ned14/outcome/raw/develop/single-header/outcome.hpp
```

On BSD:

```
fetch https://github.com/ned14/outcome/raw/develop/single-header/outcome.hpp
```

If you have `curl` installed:

```
curl -O -J -L https://github.com/ned14/outcome/raw/develop/single-header/outcome.hpp
```

Otherwise, simply download the raw file from above and place it wherever it suits you.


## Usage from the Conan package manager

*(thanks to Théo Delrieu for contributing this support)*

At the command line, add the bintray repo for Outcome to conan:

```
conan remote add outcome https://api.bintray.com/conan/ned14/Outcome
```

Now simply add this to your Conan build:

```
[requires]
Outcome/master@ned14/stable
```

Outcome will be made available by Conan at `<outcome.hpp>`.


## Usage as a git submodule

Given that v2 is still under development, it is currently best used as a git
submodule to your project so you can keep abreast of bug fixes. Here is how:

```
git submodule add https://github.com/ned14/outcome
cd outcome
git checkout develop
git submodule update --init --recursive
```

After this you can bring Outcome into your code using:

```
#include "outcome/include/outcome.hpp"
```

That's it, you are ready to go. From time to time, you may wish to update to
latest:

```
cd outcome
git pull
git submodule update
```

## Usage as a stable source tarball

If you would prefer a single source tarball of the stable branch containing
all the documentation, tests and sources, this can always be retrieved from:

https://dedi5.nedprod.com/static/files/outcome-v2.0-source-latest.tar.xz

This tarball is automatically generated when Outcome fully compiles and passes
all unit tests on all platforms tested by the CIs. This currently includes:

- Linux: GCC 6.3, clang 4.0
- MacOS: XCode 9
- Windows: VS2017

<hr>

# Running the unit test suite

To run the unit test suite you will need cmake 3.1 or later installed.

```
mkdir build
cd build
cmake ..
cmake --build .
ctest
```

On some cmake generators (Visual Studio, Xcode) you may need to tell cmake build a configuration
like Release or Debug. Similarly, ctest needs to be told the same e.g.

```
mkdir build
cd build
cmake ..
cmake --build . --config Release
ctest -C Release
```

[Per commit, tests are run by Travis and uploaded to a CDash dashboard here](http://my.cdash.org/index.php?project=Boost.Outcome).

<hr>

# Modular CMake build support

If you are using Outcome in a CMake project, Outcome is a "modular cmake" project
using only modern cmake 3 throughout. This lets you add the Outcome directory as a
cmake subdirectory with no unexpected consequence on the rest of your cmake. You will need
to be using cmake 3.1 or better.

```
add_subdirectory(
  "${CMAKE_CURRENT_SOURCE_DIR}/outcome"  # path to outcome source
  "${CMAKE_CURRENT_BINARY_DIR}/outcome"  # your choice of where to put binaries
  EXCLUDE_FROM_ALL                       # please only lazy build outcome on demand
)
```

Outcome's cmake has the following useful products:

- `outcome::hl` (target): the Outcome header-only library. Add this to any
`target_link_libraries()` in your cmake to bring in Outcome as a header-only library. This will also
add to your link (via `PUBLIC`) any debugger visualisation support files, any system library
dependencies and also force all consuming executables to be configured with a minimum
of C++ 14 as Outcome requires a minimum of that.
- `outcome_TEST_TARGETS` (list): a list of targets which generate Outcome's test
suite. You can append this to your own test suite if you wish to run Outcome's test
suite along with your own.
