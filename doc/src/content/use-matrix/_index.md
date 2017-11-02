+++
title = "Decision matrix"
weight = 5
+++

To help you decide whether Outcome would be useful for your particular problem, the
following decision matrix may be useful.

{{<mermaid>}}
graph LR;
    FAILURE{Failure is regularly passed up<br/>the stack to be handled?}
    FAILURE =="Yes"==> FREQUENT{Occasional failure is likely?}
    FREQUENT =="Yes"==> OUTCOME[Use Outcome]
    EXCEPTION[Use C++ exception<br/>throws]
    FREQUENT --"No"--> EXCEPTION
{{</mermaid>}}

{{<mermaid>}}
graph LR;
    FIXED{Worst case<br/>bounded execution times<br/>are important to you?}
    TABLE{Your compiler uses<br/>table-based EH?}
    OUTCOME[Use Outcome]
    EXCEPTION[Use C++ exception<br/>throws]
    FIXED =="Yes"==> TABLE
    TABLE =="Yes"==> OUTCOME
    FIXED --"No"--> EXCEPTION
    TABLE --"No"--> EXCEPTION
{{</mermaid>}}

{{<mermaid>}}
graph TD;
    FAILURE{Failure handling<br/>logic is as important or<br/>more important than<br/>success handling logic?}
    COST{The cost of fully<br/>testing your code<br/>for exception safety<br/>isn't worth it to<br/>your organisation?}
    AUDIT{Code peer review<br/>checks correctness of<br/>failure handling first?}
    EXCEPTIONS{You compile with<br/>C++ exceptions<br/>globally disabled?}
    SAFETY{You wish to start<br/>adding exception<br/>throwing code into<br/>an older codebase<br/>not written to be<br/>exception safe?}
    OUTCOME[Use Outcome]
    EXCEPTION[Use C++ exception<br/>throws]
    FAILURE =="Yes"==> OUTCOME
    AUDIT =="Yes"==> OUTCOME
    COST =="Yes"==> OUTCOME
    EXCEPTIONS =="Yes"==> OUTCOME
    SAFETY =="Yes"==> OUTCOME
    FAILURE --"No"--> EXCEPTION
    AUDIT --"No"--> EXCEPTION
    COST --"No"--> EXCEPTION
    EXCEPTIONS --"No"--> EXCEPTION
    SAFETY --"No"--> EXCEPTION
{{</mermaid>}}
