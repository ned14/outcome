+++
title = "`void hook_result_move_construction(T *, U &&) noexcept`"
description = "ADL discovered free function hook invoked by the converting move constructors of `basic_result`."
+++

One of the constructor hooks for {{% api "basic_result<T, E, NoValuePolicy>" %}}, generally invoked by the converting move constructors of `basic_result` (NOT the standard move constructor). See each constructor's documentation to see which specific hook it invokes.

*Overridable*: By Argument Dependent Lookup.

*Requires*: Nothing.

*Namespace*: `OUTCOME_V2_NAMESPACE::hooks`

*Header*: `<outcome/basic_result.hpp>`
