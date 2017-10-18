+++
title = "Policies"
description = "Specifying how to deal with incorrect usage e.g. retrieving a value when no value is present."
weight = 60
+++

Something the tutorial has not mentioned yet is what happens if your `EC` type is not
an error code nor an error code enum.

So, let us imagine a some user
defined type (UDT) and some arbitrary error type:

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
