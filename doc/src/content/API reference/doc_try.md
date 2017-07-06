+++
title = "Try operations"
slug = "doc_try.md"
+++
# Header file `try.hpp`<a id="try.hpp"></a>

<pre><code class="language-cpp">#define <a href='doc_try.md#try.hpp'>OUTCOME_TRY_HPP</a>

#define <a href='doc_try.md#try.hpp'>OUTCOME_TRY_GLUE2</a>(x, y)

#define <a href='doc_try.md#try.hpp'>OUTCOME_TRY_GLUE</a>(x, y)

#define <a href='doc_try.md#try.hpp'>OUTCOME_TRY_UNIQUE_NAME</a>

#define <a href='doc_try.md#try.hpp'>OUTCOME_TRYV2</a>(unique, m)

#define <a href='doc_try.md#try.hpp'>OUTCOME_TRY2</a>(unique, v, m)

#define <a href='doc_try.md#OUTCOME_TRYV'>OUTCOME_TRYV</a>(m)

#define <a href='doc_try.md#OUTCOME_TRYX'>OUTCOME_TRYX</a>(m)

#define <a href='doc_try.md#OUTCOME_TRY'>OUTCOME_TRY</a>(v, m)

namespace <a href='doc_try.md#try.hpp'>outcome_v2_6f6309a5</a>
{
    template &lt;class T&gt;
    typename T::template rebind&lt;void&gt; <a href='doc_try.md#outcome_v2_6f6309a5::try_operation_return_as(T&&)'>try_operation_return_as</a>(T&amp;&amp; v);
}</code></pre>

## Macro `OUTCOME_TRYV`<a id="OUTCOME_TRYV"></a>

<pre><code class="language-cpp">#define OUTCOME_TRYV(m)</code></pre>

If the outcome returned by expression *m* is not valued, propagate any failure by immediately returning that failure state immediately

## Macro `OUTCOME_TRYX`<a id="OUTCOME_TRYX"></a>

<pre><code class="language-cpp">#define OUTCOME_TRYX(m)</code></pre>

If the outcome returned by expression *m* is not valued, propagate any failure by immediately returning that failure state immediately, else become the unwrapped value as an expression. This makes `OUTCOME_TRYX(expr)` an expression which can be used exactly like the `try` operator in other languages.

portable. The macro is not made available on unsupported compilers, so you can test for its presence using `#ifdef OUTCOME_TRYX`.

## Macro `OUTCOME_TRY`<a id="OUTCOME_TRY"></a>

<pre><code class="language-cpp">#define OUTCOME_TRY(v, m)</code></pre>

If the outcome returned by expression *m* is not valued, propagate any failure by immediately returning that failure immediately, else set \*v( to the unwrapped value

## Function template `outcome_v2_6f6309a5::try_operation_return_as`<a id="outcome_v2_6f6309a5::try_operation_return_as(T&&)"></a>

<pre><code class="language-cpp">template &lt;class T&gt;
typename T::template rebind&lt;void&gt; try_operation_return_as(T&amp;&amp; v);</code></pre>

Customisation point for changing what the `OUTCOME_TRY` macros do. This function defaults to returning `std::move(v).as_void()`.

*Effects*: Extracts any state apart from value into a `void` rebound equivalent.

*Requires*: The input value to have a `.as_void()` member function.

-----
