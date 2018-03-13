+++
title = "Changelog"
weight = 80
+++

---
## v2.1 in progress [[project]](https://github.com/ned14/outcome/projects/1)

- [#110](https://github.com/ned14/outcome/issues/110)
    - Separated `result` from its hard coded dependency on the `<system_error>` header.
    - Renamed `result` and `outcome` to `basic_result` and `basic_outcome`.
    - Renamed `result.hpp` into `basic_result.hpp`.
    - Moved `<system_error>` and `<exception>` dependent code into new
    `std_result.hpp` and `std_outcome.hpp` header files.
    - Added `boost_result.hpp` and `boost_outcome.hpp` which use Boost.System
    and Boost.Exception (these are `result.hpp` and `outcome.hpp` in the Boost edition).

---
## v2.0 18th Jan 2018 [[release]](https://github.com/ned14/outcome/releases/tag/v2.0-boost-peer-review)

- Boost peer review edition. This is what was reviewed.
- Changelog from v1 can be found in the release notes above.
