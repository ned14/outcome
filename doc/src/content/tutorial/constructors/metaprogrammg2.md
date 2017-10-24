+++
title = "construct<T>"
description = ""
weight = 50
+++

First, we need a base definition for `construct<T>`:

{{% snippet "constructors.cpp" "construct-declaration" %}}

This fails a static assert if the type is ever instantiated unspecialised.

We then specialise for `construct<file_handle>`:

{{% snippet "constructors.cpp" "construct-specialisation" %}}

Because this is a struct, we can list initialise `construct`, and use
default member initialisers to implement default arguments. This can get
you surprisingly far before you need to start writing custom constructors.

But in more complex code, you will usually provide all the initialisation overloads that
you would for the constructors of your main type. You then implement a single phase 2 constructing
function which accepts `construct<YOURTYPE>` as input, and construct solely from
that source.
