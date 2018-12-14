+++
title = "`in_place_type_t<T>`"
description = "Either `std::in_place_type_t<T>` if C++ 17 or later, else a local emulation."
+++

Either `std::in_place_type_t<T>` if C++ 17 or later, else a local emulation.

Note that the templated variable `in_place_type` is also aliased or emulated locally.

*Requires*: Nothing.

*Namespace*: `OUTCOME_V2_NAMESPACE`

*Header*: `<outcome/config.hpp>`

*Inclusions*: `<utility>` if C++ 17 or later only, for {{% api "std::in_place_type_t<T>" %}}.
