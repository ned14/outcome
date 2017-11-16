+++
title = "Interoperation"
description = "Tying all of the above into non-intrusive namespace-boundary result and outcome interoperation."
weight = 90
+++

This is the final section of the tutorial, and it is quite lengthy. It ties
together all of the tutorial topics described above into a single worked example
utilising all of the facilities of Outcome at once.

One thing which Outcome solves -- which alternatives do not -- is how to
non-intrusively tie together multiple third party libraries, each using
Outcome with custom incommensurate `E` types, or indeed arbitrary return
types which have no relation whatsoever to a `T|E` return type. Solving
this well is the *coup de grâce* of Outcome against alternative approaches
to this problem domain,
including `std::expected<T, E>`. It is the major reason why you should
strongly consider using Outcome over alternatives, including Expected.

Firstly we shall explore some of the problems faced by the software
developer when `T|E` return type based code proliferates at scale,
where dozens of libraries may be using completely incompatible `T|E` return types.
We will also briefly cover some of the design patterns common in the
wild which return failure by returning from functions, rather than
throwing exceptions.

We shall then step through a worked example which mocks up a realistic
situation that the software developer may find themselves in: tying
together disparate third party libraries, whose source code cannot be
modified, into an application-wide, mixed-mode `T|E` and exception
throwing universal error handling system which is capable of
accurately representing the original failure, but also propagating it
in a way that the application can deal with universally.
