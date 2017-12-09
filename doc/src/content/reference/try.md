+++
title = "Try operations"
weight = 30
+++
# Header file `try.hpp`

<a id="standardese-try.hpp"></a>

<pre><code class="standardese-language-cpp"><span class="pre">#include</span> <span class="pre">&quot;</span><span class="typ dec var fun">success_failure.hpp</span><span class="pre">&quot;</span>

<span class="kwd">namespace</span> <span class="typ dec var fun">outcome_v2_xxx</span>
<span class="pun">{</span>
    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
    <span class="kwd">auto</span> <a href="#standardese-outcome_v2_xxx::try_operation_return_as%3CT%3E(T&amp;&amp;)"><span class="typ dec var fun">try_operation_return_as</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>
<span class="pun">}</span>

<span class="pre">#define</span> <span class="typ dec var fun">OUTCOME_TRY_GLUE2</span><span class="pre">(</span><span class="pre">x,y</span><span class="pre">)</span>

<span class="pre">#define</span> <span class="typ dec var fun">OUTCOME_TRY_GLUE</span><span class="pre">(</span><span class="pre">x,y</span><span class="pre">)</span>

<span class="pre">#define</span> <span class="typ dec var fun">OUTCOME_TRY_UNIQUE_NAME</span>

<span class="pre">#define</span> <span class="typ dec var fun">OUTCOME_TRYV2</span><span class="pre">(</span><span class="pre">unique,...</span><span class="pre">)</span>

<span class="pre">#define</span> <span class="typ dec var fun">OUTCOME_TRY2</span><span class="pre">(</span><span class="pre">unique,v,...</span><span class="pre">)</span>

<span class="pre">#define</span> <a href="#standardese-OUTCOME_TRYV"><span class="typ dec var fun">OUTCOME_TRYV</span></a><span class="pre">(</span><span class="pre">...</span><span class="pre">)</span>

<span class="pre">#define</span> <a href="#standardese-OUTCOME_TRYX"><span class="typ dec var fun">OUTCOME_TRYX</span></a><span class="pre">(</span><span class="pre">...</span><span class="pre">)</span>

<span class="pre">#define</span> <a href="#standardese-OUTCOME_TRY"><span class="typ dec var fun">OUTCOME_TRY</span></a><span class="pre">(</span><span class="pre">v,...</span><span class="pre">)</span>
</code></pre>

<a id="standardese-outcome_v2_xxx"></a>

### Function `outcome_v2_xxx::try_operation_return_as`

<a id="standardese-outcome_v2_xxx::try_operation_return_as&lt;T&gt;(T&amp;&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">auto</span> <span class="typ dec var fun">try_operation_return_as</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Customisation point for changing what the `OUTCOME_TRY` macros do. This function defaults to returning `std::forward<T>(v).as_failure()`.

*Effects:* Extracts any state apart from value into a `failure_type`.

*Requires:* The input value to have a `.as_failure()` member function.

-----

## Macro `OUTCOME_TRYV`

<a id="standardese-OUTCOME_TRYV"></a>

<pre><code class="standardese-language-cpp"><span class="pre">#define</span> <span class="typ dec var fun">OUTCOME_TRYV</span><span class="pre">(</span><span class="pre">...</span><span class="pre">)</span>
</code></pre>

If the outcome returned by expression … is not valued, propagate any failure by immediately returning that failure state immediately

-----

## Macro `OUTCOME_TRYX`

<a id="standardese-OUTCOME_TRYX"></a>

<pre><code class="standardese-language-cpp"><span class="pre">#define</span> <span class="typ dec var fun">OUTCOME_TRYX</span><span class="pre">(</span><span class="pre">...</span><span class="pre">)</span>
</code></pre>

If the outcome returned by expression … is not valued, propagate any failure by immediately returning that failure state immediately, else become the unwrapped value as an expression. This makes `OUTCOME_TRYX(expr)` an expression which can be used exactly like the `try` operator in other languages.

*Note:*\* This macro makes use of a proprietary extension in GCC and clang and is not portable. The macro is not made available on unsupported compilers, so you can test for its presence using `#ifdef OUTCOME_TRYX`.

-----

## Macro `OUTCOME_TRY`

<a id="standardese-OUTCOME_TRY"></a>

<pre><code class="standardese-language-cpp"><span class="pre">#define</span> <span class="typ dec var fun">OUTCOME_TRY</span><span class="pre">(</span><span class="pre">v,...</span><span class="pre">)</span>
</code></pre>

If the outcome returned by expression … is not valued, propagate any failure by immediately returning that failure immediately, else set *v* to the unwrapped value.

-----
