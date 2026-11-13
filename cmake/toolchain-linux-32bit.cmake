# A genuine 32-bit build on a 64-bit runner.
#
# Issue #325 was a 16-byte ABI shape asserted over two intptr_t fields: on any
# 32-bit target that struct is 8 bytes, so the assertion fired and the whole
# unit-test target failed to compile. Nothing caught it because no lane compiled
# for a 32-bit target at all - the tests were only ever built where intptr_t is
# 8 bytes, which is exactly the assumption the test was making.
#
# The flags live in a toolchain file rather than in CXXFLAGS for two reasons:
# they then reach CMake's own compiler-capability and try_compile probes, so the
# configure step tests 32-bit behaviour instead of 64-bit; and the linker flags
# travel with them, which a bare CXXFLAGS does not do (a -m32 object cannot be
# linked by an unflaged 64-bit link step). gcc-multilib supplies the 32-bit
# libstdc++ and libgcc.
set(CMAKE_C_FLAGS_INIT "-m32")
set(CMAKE_CXX_FLAGS_INIT "-m32")
set(CMAKE_EXE_LINKER_FLAGS_INIT "-m32")
set(CMAKE_MODULE_LINKER_FLAGS_INIT "-m32")
set(CMAKE_SHARED_LINKER_FLAGS_INIT "-m32")
