+++
title = "Tutorial"
weight = 10
+++

## Outcome 2.0 namespace

It is recommended that you refer to entities from this Outcome 2.0 via the following namespace alias:

{{% snippet "using_result.cpp" "namespace" %}}

As patches and modifications are applied to this library, namespaces get added in order
not to break any backward compatibility. At some point namespace `outcome::v2` will be defined,
and this will be the prefered namespace. Until then `OUTCOME_V2_NAMESPACE` denotes the most recently
updated version, getting closer to `outcome::v2`.

## Creating `result<>`

We will define a function that converts an `std::string` to an `int`. This function can fail for a number of reasons,
if it does we want to communicate the failure reason.

{{% snippet "using_result.cpp" "convert_decl" %}}

Class template `result<T, EC>` has two template parameters. The first (`T`) represents the type of the object
returned from the function upon succes; the second (`EC`) is type of object storing information about the reason
for failure when function fails. A `result<T, EC>` object either stores a `T` or an `EC` at any given moment,
and is therefore conceptually similar to `boost::variant<T, EC>`. `EC` is defaulted to `std::error_code`.
If both `T` and `EC` are trivially copyable, `result<T, EC>` is alfrom antso trivially copyable.

Now, we will define an enumeration describing different failure situations during conversion.

{{% snippet "using_result.cpp" "enum" %}}

Assume we have plugged it into `std::error_code` framework, as described in [this section](error_code).

One notable effect of such plugging is that `ConversionErrc` is now convertible to `std::error_code`.
Now we can implement function `convert` as follows: 

{{% snippet "using_result.cpp" "convert" %}}

`result<T, EC>` is convertible from any `T2` convertible to `T` as well as any `EC2` convertible to `EC`,
provided that the conversion is not ambiguous. If some type `X` is both convertible to `T` and `EC`, 
conversion to `result<T, EC>` fails to compile. In this case you need to use one of the tagged constructors:

{{% snippet "using_result.cpp" "explicit" %}}

## Inspecting `result<>`

Suppose we will be wiriting function `print_halve` that takes an integral number (however big) represented in `std::string` and outputs a nuber which is twice smaller:

{{% snippet "using_result.cpp" "half_decl" %}}

Type `result<void>` means that there is no value to be retuned upon success, but that the operation might still fail, and we may be interested in inspecting the cause of the failure. Class template `rebind` is declared with attribute `[[nodiscard]]`, which means compiler will warn you if you forget to inspect the returned object.

The implementation will do the following: if the integral number can be represnted by an `int`, we will convert to `int` and use its arithmetical operations. If the number is too large, we will fall back to using a custom `BigInt` implementation taht needs to allocate memory. In the implementation we will use function `convert` defined in the previous section.

{{% snippet "using_result.cpp" "half_impl" %}}

#1. You test if `result` object represents a cuccessful operation with contextual conversion to `bool`.

#2. Function `value` extracts the successfully returned result.

#3. Function `error` allows you to inspect the error sub-object, representing information about the reason for failure.

#4. Macro `OUTCOME_TRY` represents a control statement. It implies that function call in the second argument returns a `result<>`. It is defined as:

{{% snippet "using_result.cpp" "from_string" %}}

   Our control statement means: if `fromString` returned failure, this same error information should be returned from `print_half`, even though the type of `result<>` is different. If `fromString` returned success, we create  variable `i` of type `int` with the value returned from `fromString`. If control goes to subsequent line, it means `fromString` succeeded and variable of type `int` is in scope.

#5. In the return statement we extract the error information and use it to initialize the return value from `print_half`.

#6. Function `success` returns an object of type `result<foid>` representing success.

## TODO: more material will be provided in time...

This will include TRY operations, customizing `result` and using outcome

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