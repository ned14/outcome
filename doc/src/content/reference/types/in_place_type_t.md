+++
title = "`in_place_type_t<T>`"
description = "Either `std::in_place_type_t<T>` or a local emulation, depending on the `OUTCOME_USE_STD_IN_PLACE_TYPE` macro."
+++

Either `std::in_place_type_t<T>` or a local emulation, depending on the
{{% api "OUTCOME_USE_STD_IN_PLACE_TYPE" %}} macro.

Note that the templated variable `in_place_type` is also aliased or emulated locally.

*Requires*: Nothing.

*Namespace*: `OUTCOME_V2_NAMESPACE`

*Header*: `<outcome/config.hpp>`
