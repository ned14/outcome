+++
title = "C++ exception throws"
description = "How C++ exception throws compare to Outcome"
weight = 10
+++

(Note that we assume a table-based EH implementation here, a SJLJ EH implementaton would be a lot more even with Outcome. Table-based EH implementations are almost universal on x64, ARM and AArch64 targets)

Pros:

- Zero runtime overhead on the happy path.


Cons:

- Unpredictable runtime overhead on the sad path.