+++
title = "ASIO/Networking TS"
description = "How to teach ASIO/Networking TS about Outcome."
tags = [ "asio", "networking-ts" ]
+++

*Thanks to [Christos Stratopoulos](https://github.com/cstratopoulos) for this recipe.*

---

### Introduction

[Boost.ASIO](https://www.boost.org/doc/libs/develop/doc/html/boost_asio.html)
and [standalone ASIO](https://think-async.com/Asio/) provide the
[`async_result`](https://www.boost.org/doc/libs/develop/doc/html/boost_asio/reference/async_result.html)
customisation point for adapting arbitrary third party libraries, such as Outcome, into ASIO.

Historically in ASIO you need to pass completion handler instances
to the ASIO asynchronous i/o initiation functions. These get executed when the i/o
completes.

{{% snippet "boost-only/asio_integration.cpp" "old-use-case" %}}

One of the big value adds of the Coroutines TS is the ability to not have to write
so much boilerplate if you have a Coroutines supporting compiler:

{{% snippet "boost-only/asio_integration.cpp" "new-use-case" %}}

However the default ASIO implementation appears to currently always throw exceptions
from its Coroutines token implementation. This recipe fixes that:

{{% snippet "boost-only/asio_integration.cpp" "outcome-use-case" %}}

---

### Implementation

Todo

---

Here follows a real world, production-level adapation of Outcome into
ASIO, written and maintained by [Christos Stratopoulos](https://github.com/cstratopoulos).
If the following does not load due to Javascript being disabled, you can visit the gist at 
https://gist.github.com/cstratopoulos/901b5cdd41d07c6ce6d83798b09ecf9b.

{{% gist "cstratopoulos" "901b5cdd41d07c6ce6d83798b09ecf9b" %}}
