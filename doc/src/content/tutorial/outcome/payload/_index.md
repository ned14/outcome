+++
title = "Outcome with payload"
weight = 40
+++

`outcome<T, EC, EP>` actually comes in two editions:

- If `trait::is_exception_ptr<EP>` is true, you get the semantics we have seen already
where any `EP` is rethrown before throwing a `system_error` exception made from `EC`.
`EP` is accessed via a `.exception()` observer.
- If `trait::is_exception_ptr<EP>` is false, then `EP` is considered to be an additional
payload accompanying the `EC`. In this situation, there is no `.exception()` observer,
and instead there is a `.payload()` observer.

It might seem strange that these two editions of `outcome<>` are not separate types,
however they are in fact much more closely related than it appears initially.

{{<mermaid>}}
graph LR
    RESULT{"result#lt;T, EC#gt;"} --"result AND payload"--> OUTCOME1{"outcome#lt;T, EC, P#gt;"}
    RESULT --"result OR exception_ptr"--> OUTCOME2{"outcome#lt;T, EC, EX#gt;"}
    OUTCOME1 --> OUTCOME1a["if(has_payload())<br/>throw_as_system_error_with_payload();<br/>if(has_error())<br/>throw system_error(error());<br/>"]
    OUTCOME2 --> OUTCOME2a["if(has_exception())<br/>rethrow_exception(exception());<br/>if(has_error())<br/>throw system_error(error());<br/>"]
{{</mermaid>}}

The non-obvious part is that Outcome can be told how to convert an error code + payload
into a customised exception throw i.e. to synthesise an exception ptr on demand. This
is useful for a lot of reasons, not least that constructing an exception ptr is quite
expensive (at least a few thousand CPU cycles), so constructing one just in case it might
be thrown is therefore an unacceptable overhead.
