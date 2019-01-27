+++
title = "`status_result` and `status_outcome`"
weight = 30
+++

`status_result` and `status_outcome` are type aliases to {{< api "basic_result<T, E, NoValuePolicy>" >}}
and {{< api "basic_outcome<T, EC, EP, NoValuePolicy>" >}}, just the same as
{{< api "std_result<T, E = std::error_code, NoValuePolicy = policy::default_policy<T, E, void>>" >}}
and {{< api "std_outcome<T, EC = std::error_code, EP = std::exception_ptr, NoValuePolicy = policy::default_policy<T, EC, EP>>" >}}.

There is however a slight difference in template parameters because the
payload of `status_code<DomainType>` is determined by `DomainType`, so
instead the specification is:

```c++
experimental::status_result<T, DomainType = typename experimental::generic_code::domain_type>
```

The resulting `basic_result` implementation gains an `error_type` of
`experimental::status_code<DomainType>`.

The same applies to `status_outcome`, where the specification is:

```c++
experimental::status_outcome<T, DomainType = typename experimental::generic_code::domain_type, EP = std::exception_ptr>
```
