+++
title = "Variations"
description = ""
weight = 40
+++

You can of course choose your own `E` type so long as it has standard layout
and is trivially copyable. You would declare that with {{< api "result_c/#standardese-CXX_DECLARE_RESULT" "CXX_DECLARE_RESULT(t_ident, t_decl, e_ident, e_decl)" >}},
refer to it with {{< api "result_c/#standardese-CXX_RESULT" "CXX_RESULT(t_ident, e_ident)" >}} and need to do your own
decoding of errors from your `E` type. By using the `_EC` postfixed macros,
you are in fact using `E =`

```c
struct cxx_error_code
{
  int code;
  void *category;
};
```

... which is declared for you by `result.h`.

Outcome's C support was designed assuming that you do not wish to penalise the performance
of C++ code calling these C-compatible C++ functions, but if you don't care
about that, then always setting `errno` to any error in a `result<T>` is easily
implemented and thus the natural C use pattern becomes available:

```c
extern size_t to_string(char *buffer, size_t bufferlen, int v);
...
size_t len = to_string(buffer, sizeof(buffer), v);
if(errno != 0)
  ...
```

Implementing this via boilerplate generating script is straightforward,
and is left as an exercise to the interested reader.
