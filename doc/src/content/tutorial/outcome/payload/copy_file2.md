+++
title = "Upgrading the Filesystem TS"
weight = 20
+++

An Outcome based solution looks deceptively simple initially, but there is more to it than it appears.

{{% snippet "outcome_payload.cpp" "filesystem_api_fixed" %}}

Starting at the bottom, there is now a single `copy_file()` function which returns a `fs_result<void>`.
As outcomes are either successful or not, there is no longer any point in returning a boolean, so we
simply return `void` on success. On failure, as the template alias `fs_result<T>` above it shows,
we are returned an error code plus a `failure_info` structure containing the same additional information
as `filesystem_error` provides.

It is important to note that the fact that `failure_info` is defined in namespace `filesystem2` is very
important. This is because Outcome has no idea, for obvious reasons, what to do when someone tries to
access the successful state of an errored outcome with payload. We therefore must tell Outcome by declaring
a special free function discovered via ADL what to do.