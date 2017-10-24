+++
title = "A file handle"
description = ""
weight = 20
+++

Borrowing from [`afio::file_handle`](https://ned14.github.io/afio/classafio__v2__xxx_1_1file__handle.html)
which uses this design pattern, here is a simplified `file_handle` implementation:

{{% snippet "constructors.cpp" "file_handle" %}}

Note the default member initialisers, these are particularly convenient for
implementing phase 1 of construction. Note also the `constexpr` constructor,
which thanks to the default member initialisers is otherwise empty.

File handles are very expensive to copy as they involve a syscall to duplicate
the file descriptor, so we enable moves only.

The destructor closes the file descriptor if it is not -1, and if the close
fails, seeing as there is nothing else we can do without leaking the file
descriptor, we fatal exit the process.

Finally we declare the phase 2 constructor which is a static member function.
