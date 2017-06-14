# Recent changes
\anchor changelog

## Next release v1.00:
- Issue #23 Get Outcome working on VS2017 Update 1. Thanks to Vinnie Falco for reporting this.
- Issue #11 Changing state should never cause an empty state if avoidable. Outcomes and Expected will now
not lose previous state during assignment or emplacement if the existing state's type has a nothrow
move or copy constructor. It does this by moving the existing state onto the stack before trying to
set the new state, and if that throws it restores the previous state. This new code path only activates
if any of the types stored have throwing move constructors.
- Issue #12 basic_monad's copy assignment no longer gets instantiated when type T cannot be copied.
- Issue #36 Fixed mingw-w64 build support.


## 20170519 boost_peer_review4:
- Issue #13 The opcode counting CI tests in test/constexprs was severely broken on POSIX.
Thanks to Tom Westerhout for finding the problem and supplying its fix.
- unittests.cpp had become clang-tidy unclean, fixed.
- Issue #15 Move `outcome::expected<T, E>` into `outcome::experimental::expected<T, E>`. Thanks to
Vicente J. Botet Escriba for persuading me to do this.
- Issue #14 Removed all the static asserts in the Expected implementation apart from the nothrow
move constructor check, which is now correct unlike the incorrect assert from before. Thanks to
Vicente J. Botet Escriba for explaining Expected's semantics.
- Issue #21 Correct misspelling of `extended_error_code` with `error_code_extended` in the docs.
Thanks to Deniz Bahadir for reporting this.
- Issue #17 Give credit to Paul Bristow for the name "Outcome". Thanks to Peter Dimov
for finding the correct person.
- Issue #18 `result<T>` had a `.set_exception()` which it should not have had. Thanks to Peter Dimov
for reporting this.
- Issue #19 Remove observers `.is_ready()`, `.get_error_or()`, `.get_exception_or()`. Thanks to Peter
Dimov and Andrzej Krzemienski for suggesting this.
- Issue #20 Rename:
  - `monad_error` to `bad_outcome`
  - `monad_errc` to `bad_outcome_errc`
  - `monad_category` to `bad_outcome_category`
  - `BOOST_OUTCOME_THROW_MONAD_ERROR` to `BOOST_OUTCOME_THROW_BAD_OUTCOME`

  Thanks to Peter Dimov, Andrzej Krzemienski and Paul Bristow for suggesting this.

## 20170511 boost_peer_review3:
- First release for Boost peer review. If you want changelog before this, please consult the git log.
