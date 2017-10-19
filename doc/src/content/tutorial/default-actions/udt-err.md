+++
title = "User defined error types"
description = ""
weight = 5
+++

Let us imagine a some user defined value type (`udt`) and some user defined error type (`err`):

{{% snippet "udts.cpp" "udts" %}}

Firstly, note that both the `udt` and `err` types can be constructed from an `int`.
Thus this won't compile:

{{% snippet "udts.cpp" "implicit" %}}

This is because all the implicit constructors self-disable because it could be ambiguous whether you
might mean `udt` or `err`. This is not a problem, it just requires typing some more so you
are explicit as to which you intend:

{{% snippet "udts.cpp" "explicit" %}}

Now, what do you think will happen if we try to retrieve a `udt` from this `result` holding an `err`?

{{% snippet "udts.cpp" "access" %}}
