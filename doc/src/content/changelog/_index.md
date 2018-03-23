+++
title = "Changelog"
weight = 80
+++

---
## v2.1 in progress [[project]](https://github.com/ned14/outcome/projects/1)

- [#115](https://github.com/ned14/outcome/issues/115)
    - Outcome did not construct correctly from `failure_type`.

- Inexplicably outcome's error + exception constructor had been removed.
Nobody noticed during the Boost peer review, which is worrying seeing as that
constructor is needed for one of the main advertised features to Boost!

- [#107](https://github.com/ned14/outcome/issues/107) and [#116](https://github.com/ned14/outcome/issues/116)
    - `operator==` and `operator!=` now become disabled if the value, error and
    exception types do not implement the same operator.
    - Relatedly, both comparison operators simply didn't work right. Fixed.

- [#109](https://github.com/ned14/outcome/issues/109)
    - `swap()` now has correct `noexcept` calculation and now correctly orders
    the swaps to be whichever is the throwing swap first.

- Added reference dump of v2.1 ABI so we can check if ABI breakage detection
works in the next set of changes, plus Travis job to check ABI and API compatibility
per commit.

- [#124](https://github.com/ned14/outcome/issues/124)
    - `OUTCOME_TRY` is now overloaded and selects `void` or `auto` edition
    according to input parameter count.

- [#120](https://github.com/ned14/outcome/issues/120)
    - Fix generation of double underscored temporary variables in
    `OUTCOME_UNIQUE_NAME`, which is UB.

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
- Changelog from v1 can be found in the release notes for this release.
