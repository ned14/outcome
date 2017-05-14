# Recent changes
\anchor changelog

## Next release boost_peer_review4:
- Issue #13 The opcode counting CI tests in test/constexprs was severely broken on POSIX.
Thanks to Tom Westerhout for finding the problem and supplying its fix.
- unittests.cpp had become clang-tidy unclean, fixed.
- Issue #15 Move `outcome::expected<T, E>` into `outcome::experimental::expected<T, E>`. Thanks to
Vicente J. Botet Escriba for persuading me to do this.
- Issue #14 Removed all the static asserts in the Expected implementation apart from the nothrow
move constructor check, which is now correct unlike the incorrect assert from before. Thanks to
Vicente J. Botet Escriba for explaining Expected's semantics.


## 20170511 boost_peer_review3:
- First release for Boost peer review. If you want changelog before this, please consult the git log.
