+++
title = "result<udt, err>.value()"
description = ""
weight = 10
+++

```
ned@lyta:~/outcome/build_posix$ bin/outcome-snippets_udts
32767
ned@lyta:~/outcome/build_posix$
```

Apparently no exception was thrown? Correct. What actually happened was *undefined behaviour*. Let us
turn on the undefined behaviour sanitiser and see what happens instead:

```
ned@lyta:~/outcome/build_posix$ export UBSAN_OPTIONS=print_stacktrace=1
ned@lyta:~/outcome/build_posix$ bin/outcome-snippets_udts
/home/ned/outcome/doc/src/snippets/../../../include/outcome/policy/detail/common.hpp:42:9: runtime error: execution reached a __builtin_unreachable() call
    #0 0x42a0dc in outcome_v2_1c2d524c::policy::detail::base::_ub() (/home/ned/outcome/build_posix/bin/outcome-snippets_udts+0x42a0dc)
    #1 0x42a028 in void outcome_v2_1c2d524c::policy::detail::base::narrow_value_check<outcome_v2_1c2d524c::detail::result_value_observers<outcome_v2_1c2d524c::detail::result_storage<main::udt, main::err, outcome_v2_1c2d524c::policy::all_narrow>, main::udt, outcome_v2_1c2d524c::policy::all_narrow> >(outcome_v2_1c2d524c::detail::result_value_observers<outcome_v2_1c2d524c::detail::result_storage<main::udt, main::err, outcome_v2_1c2d524c::policy::all_narrow>, main::udt, outcome_v2_1c2d524c::policy::all_narrow>*) (/home/ned/outcome/build_posix/bin/outcome-snippets_udts+0x42a028)
    #2 0x429f0c in void outcome_v2_1c2d524c::policy::all_narrow::wide_value_check<outcome_v2_1c2d524c::detail::result_value_observers<outcome_v2_1c2d524c::detail::result_storage<main::udt, main::err, outcome_v2_1c2d524c::policy::all_narrow>, main::udt, outcome_v2_1c2d524c::policy::all_narrow> >(outcome_v2_1c2d524c::detail::result_value_observers<outcome_v2_1c2d524c::detail::result_storage<main::udt, main::err, outcome_v2_1c2d524c::policy::all_narrow>, main::udt, outcome_v2_1c2d524c::policy::all_narrow>*) (/home/ned/outcome/build_posix/bin/outcome-snippets_udts+0x429f0c)
    #3 0x4298d6 in outcome_v2_1c2d524c::detail::result_value_observers<outcome_v2_1c2d524c::detail::result_storage<main::udt, main::err, outcome_v2_1c2d524c::policy::all_narrow>, main::udt, outcome_v2_1c2d524c::policy::all_narrow>::value() & (/home/ned/outcome/build_posix/bin/outcome-snippets_udts+0x4298d6)
    #4 0x4295f1 in main (/home/ned/outcome/build_posix/bin/outcome-snippets_udts+0x4295f1)
    #5 0x7f3bd59c1f44 in __libc_start_main /build/eglibc-SvCtMH/eglibc-2.19/csu/libc-start.c:287
    #6 0x4030c3 in _start (/home/ned/outcome/build_posix/bin/outcome-snippets_udts+0x4030c3)
```

