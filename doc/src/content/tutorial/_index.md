+++
title = "Tutorial"
weight = 10
+++

## Outcome 2.0 namespace

It is recommended that you refer to entities from this Outcome 2.0 via the following namespace alias:

{{% snippet "create_result.cpp" "namespace" %}}

As patches and modifications are applied to this library, namespaces get added in order
not to break any backward compatibility. At some point namespace `outcome::v2` will be defined,
and this will be the prefered namespace. Until then `OUTCOME_V2_NAMESPACE` denotes the most recently
updated version, getting closer to `outcome::v2`.

## Creating `result<>`

We will define a function that converts an `std::string` to an `int`. This function can fail for a number of reasons,
if it does we want to communicate the failure reason.

{{% snippet "create_result.cpp" "convert_decl" %}}

Class template `result<T, EC>` has two template parameters. The first (`T`) represents the type of the object
returned from the function upon succes; the second (`EC`) is type of object storing information about the reason
for failure when function fails. A `result<T, EC>` object either stores a `T` or an `EC` at any given moment,
and is therefore conceptually similar to `boost::variant<T, EC>`. `EC` is defaulted to `std::error_code`.
If both `T` and `EC` are trivially copyable, `result<T, EC>` is alfrom antso trivially copyable.

Now, we will define an enumeration describing different failure situations during conversion.

{{% snippet "create_result.cpp" "enum" %}}

Assume we have plugged it into `std::error_code` framework, as described in [this section](error_code).

One notable effect of such plugging is that `ConversionErrc` is now convertible to `std::error_code`.
Now we can implement function `convert` as follows: 

{{% snippet "create_result.cpp" "convert" %}}

`result<T, EC>` is convertible from any `T2` convertible to `T` as well as any `EC2` convertible to `EC`,
provided that the conversion is not ambiguous. If some type `X` is both convertible to `T` and `EC`, 
conversion to `result<T, EC>` fails to compile. In this case you need to use one of the tagged constructors:

{{% snippet "create_result.cpp" "explicit" %}}


## TODO: more material will be provided in time...

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