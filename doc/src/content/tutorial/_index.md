+++
title = "Tutorial"
weight = 10
+++
Todo

{{<mermaid>}}
graph TD
    A1{"result#lt;T, E#gt;"} --"Success"--> B1["T value()"]
    A1 --"Failure"--> C1["E error()"]
    A2{"outcome#lt;T, EC, E|P#gt;"} --"Success"--> B2["T value()"]
    A2 --"Failure"--> C2["EC error()"]
    A2 --> D2(("Either"))
    D2 --"Abort"--> E2["E exception()"]
    D2 --"Payload"--> F2["P payload()"]
{{</mermaid>}}