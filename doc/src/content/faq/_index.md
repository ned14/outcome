+++
title = "Frequently asked questions"
weight = 30
+++

# Why is implicit default construction disabled?

This was one of the more interesting points of discussion during the peer review of
Outcome v1. v1 had a formal empty state. This came with many advantages, but it
was not felt to be STL idiomatic as `std::optional<result<T>>` is what was meant, so
v2 has eliminated any legal possibility of being empty.

The `expected<T, E>` proposal of that time (May 2017) did permit default construction
if its `T` type allowed default construction. This was specifically done to make
`expected<T, E>` more useful in STL containers as one can say resize a vector without
having to supply an `expected<T, E>` instance to fill the new items with. However
there was some unease with that design choice, because it may cause programmers to
use some type `T` whose default constructed state is overloaded with additional meaning,
typically "to be filled" i.e. a de facto empty state via choosing a magic value.

For the v2 redesign, the various arguments during the v1 review were considered.
Unlike `expected<T, E>` which is intended to be a general purpose Either monad
vocabulary type, Outcome's types are meant primarily for returning success or failure
from functions. The API should therefore encourage the programmer to not overload
the successful type with additional meaning of "to be filled" e.g. `result<std::optional<T>>`.
The decision was therefore taken to disable *implicit* default construction, but
still permit *explicit* default construction by making the programmer spell out their
intention with extra typing.

To therefore explicitly default construct a `result<T>` or `outcome<T>`, use one
of these forms as is the most appropriate for the use case:

1. Construct with just `in_place_type<T>` e.g. `result<T>(in_place_type<T>)`.
2. Construct via `success()` e.g. `outcome<T>(success())`.
3. Construct from a `void` form e.g. `result<T>(result<void>(in_place_type<void>))`.
