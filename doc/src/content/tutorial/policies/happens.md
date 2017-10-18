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
/home/ned/outcome/doc/src/snippets/../../../include/outcome/policy/detail/common.hpp:46:32: runtime error: execution reached a __builtin_unreachable() call
    #0 0x400efc in void outcome_v2_1c2d524c::policy::detail::base::narrow_value_check<outcome_v2_1c2d524c::detail::result_value_observers<outcome_v2_1c2d524c::detail::result_storage<main::udt, main::err, outcome_v2_1c2d524c::policy::all_narrow>, main::udt, outcome_v2_1c2d524c::policy::all_narrow> >(outcome_v2_1c2d524c::detail::result_value_observers<outcome_v2_1c2d524c::detail::result_storage<main::udt, main::err, outcome_v2_1c2d524c::policy::all_narrow>, main::udt, outcome_v2_1c2d524c::policy::all_narrow>*) (/home/ned/outcome/build_posix/bin/outcome-snippets_udts+0x400efc)
    #1 0x400eae in void outcome_v2_1c2d524c::policy::all_narrow::wide_value_check<outcome_v2_1c2d524c::detail::result_value_observers<outcome_v2_1c2d524c::detail::result_storage<main::udt, main::err, outcome_v2_1c2d524c::policy::all_narrow>, main::udt, outcome_v2_1c2d524c::policy::all_narrow> >(outcome_v2_1c2d524c::detail::result_value_observers<outcome_v2_1c2d524c::detail::result_storage<main::udt, main::err, outcome_v2_1c2d524c::policy::all_narrow>, main::udt, outcome_v2_1c2d524c::policy::all_narrow>*) (/home/ned/outcome/build_posix/bin/outcome-snippets_udts+0x400eae)
    #2 0x400e66 in outcome_v2_1c2d524c::detail::result_value_observers<outcome_v2_1c2d524c::detail::result_storage<main::udt, main::err, outcome_v2_1c2d524c::policy::all_narrow>, main::udt, outcome_v2_1c2d524c::policy::all_narrow>::value() & (/home/ned/outcome/build_posix/bin/outcome-snippets_udts+0x400e66)
    #3 0x400fec in main (/home/ned/outcome/build_posix/bin/outcome-snippets_udts+0x400fec)
    #4 0x7f0dab211f44 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x21f44)
    #5 0x400998  (/home/ned/outcome/build_posix/bin/outcome-snippets_udts+0x400998)
```

