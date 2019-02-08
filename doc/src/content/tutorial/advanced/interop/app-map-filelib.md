+++
title = "Mapping the File I/O library into the Application"
weight = 40
+++

To handle the File I/O library, once again we turn to custom `ValueOrError`
converters:

{{% snippet "finale.cpp" "app_map_filelib" %}}

Note that the conversion exactly duplicates the implementation of
`throw_as_system_error_with_payload(failure_info fi)` from
namespace `filelib`.
