+++
title = "Phase 3"
description = ""
weight = 40
+++

We have built our first two phases of construction for `file_handle`,
and for some users they might be happy writing:

{{% snippet "constructors.cpp" "static-use" %}}

... and be done with it.

But wouldn't it be nicer if we could instead write:

{{% snippet "constructors.cpp" "construct-use" %}}

The eye is immediately drawn to the two-stage invocation pattern, so we are
constructing a type `construct<file_handle>` using the arguments with which we wish
to invoke the `file_handle` constructor with, and then invoking the
call operator on that `construct<file_handle>` instance to do the
actual construction.

We think that this is a better approach than alternatives, but we
shall briefly cover those at the end of this section.
