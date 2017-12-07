+++
title = "Interoperation"
slug = "doc_convert.md"
weight = 50
+++

# Header file `convert.hpp`

<a id="standardese-convert.hpp"/>

<pre><code class="standardese-language-cpp"><span class="pre">#include</span> <span class="pre">&quot;</span><span class="typ dec var fun">detail&#x2F;result_storage.hpp</span><span class="pre">&quot;</span>

<span class="kwd">namespace</span> <span class="typ dec var fun">outcome_v2_xxx</span>
<span class="pun">{</span>
    <span class="kwd">namespace</span> <a href="standardese_entities.md#standardese-outcome_v2_xxx::convert"><span class="typ dec var fun">convert</span></a>
    <span class="pun">{</span>
        <span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span> <span class="kwd">U</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">ValueOrNone</span> <span class="pun">=</span> <span class="kwd">detail</span><span class="pun">::</span><span class="kwd">ValueOrNone</span><span class="pun">&lt;</span><span class="kwd">U</span><span class="pun">&gt;</span><span class="pun">;</span>

        <span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span> <span class="kwd">U</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">ValueOrError</span> <span class="pun">=</span> <span class="kwd">detail</span><span class="pun">::</span><span class="kwd">ValueOrError</span><span class="pun">&lt;</span><span class="kwd">U</span><span class="pun">&gt;</span><span class="pun">;</span>

        <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">&gt;</span>
        <span class="kwd">struct</span> <a href="doc_convert.md#standardese-outcome_v2_xxx::convert::value_or_error%3CT,U%3E"><span class="typ dec var fun">value_or_error</span></a><span class="pun">;</span>
    <span class="pun">}</span>
<span class="pun">}</span>
</code></pre>

<a id="standardese-outcome_v2_xxx"/>

<a id="standardese-outcome_v2_xxx::convert"/>

### Struct `value_or_error`

<a id="standardese-outcome_v2_xxx::convert::value_or_error<T,U>"/>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">&gt;</span>
<span class="kwd">struct</span> <span class="typ dec var fun">value_or_error</span>
<span class="pun">{</span>
    <span class="kwd">static</span> <span class="kwd">constexpr</span> <span class="kwd">bool</span> <span class="kwd">const</span> <a href="doc_convert.md#standardese-outcome_v2_xxx::convert::value_or_error%3CT,U%3E::enable_result_inputs"><span class="typ dec var fun">enable_result_inputs</span></a><span class="pun">;</span>

    <span class="kwd">static</span> <span class="kwd">constexpr</span> <span class="kwd">bool</span> <span class="kwd">const</span> <a href="doc_convert.md#standardese-outcome_v2_xxx::convert::value_or_error%3CT,U%3E::enable_outcome_inputs"><span class="typ dec var fun">enable_outcome_inputs</span></a><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">X</span><span class="pun">,</span> <span class="kwd">typename</span> <span class="pun">=</span> std::enable_if_t&lt;std::is_same&lt;U,std::decay_t&lt;X&gt;&gt;::value&amp;&amp;ValueOrError&lt;U&gt;&amp;&amp;(std::is_void&lt;typename std::decay_t&lt;X&gt;::value_type&gt;::value||outcome_v2_xxx::detail::is_explicitly_constructible&lt;typename T::value_type,typename std::decay_t&lt;X&gt;::value_type&gt;)&amp;&amp;(std::is_void&lt;typename std::decay_t&lt;X&gt;::error_type&gt;::value||outcome_v2_xxx::detail::is_explicitly_constructible&lt;typename T::error_type,typename std::decay_t&lt;X&gt;::error_type&gt;)&gt;<span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <span class="typ dec var fun">T</span> <a href="doc_convert.md#standardese-outcome_v2_xxx::convert::value_or_error%3CT,U%3E::operator()%3CX,%3E(X&amp;&amp;)"><span class="typ dec var fun">operator()</span></a><span class="pun">(</span><span class="typ dec var fun">X</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>
<span class="pun">};</span>
</code></pre>

Default converter for types matching the `ValueOrError` concept.

You can partially or fully specialise this converter for your own user defined types by injecting specialisations into the `convert` namespace.

### Variable `enable_result_inputs`

<a id="standardese-outcome_v2_xxx::convert::value_or_error<T,U>::enable_result_inputs"/>

<pre><code class="standardese-language-cpp"><span class="kwd">static</span> <span class="kwd">constexpr</span> <span class="kwd">bool</span> <span class="kwd">const</span> <span class="typ dec var fun">enable_result_inputs</span><span class="pun">;</span>
</code></pre>

False to indicate that this converter wants `result`/`outcome` to reject all other `result`

-----

### Variable `enable_outcome_inputs`

<a id="standardese-outcome_v2_xxx::convert::value_or_error<T,U>::enable_outcome_inputs"/>

<pre><code class="standardese-language-cpp"><span class="kwd">static</span> <span class="kwd">constexpr</span> <span class="kwd">bool</span> <span class="kwd">const</span> <span class="typ dec var fun">enable_outcome_inputs</span><span class="pun">;</span>
</code></pre>

False to indicate that this converter wants `outcome` to reject all other `outcome`

-----

### Function `operator()`

<a id="standardese-outcome_v2_xxx::convert::value_or_error<T,U>::operator()<X,>(X&&)"/>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">X</span><span class="pun">,</span> <span class="kwd">typename</span> <span class="pun">=</span> std::enable_if_t&lt;std::is_same&lt;U,std::decay_t&lt;X&gt;&gt;::value&amp;&amp;ValueOrError&lt;U&gt;&amp;&amp;(std::is_void&lt;typename std::decay_t&lt;X&gt;::value_type&gt;::value||outcome_v2_xxx::detail::is_explicitly_constructible&lt;typename T::value_type,typename std::decay_t&lt;X&gt;::value_type&gt;)&amp;&amp;(std::is_void&lt;typename std::decay_t&lt;X&gt;::error_type&gt;::value||outcome_v2_xxx::detail::is_explicitly_constructible&lt;typename T::error_type,typename std::decay_t&lt;X&gt;::error_type&gt;)&gt;<span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">T</span> <span class="typ dec var fun">operator()</span><span class="pun">(</span><span class="typ dec var fun">X</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Default converter for types matching the `ValueOrError` concept.

*Requires:* `std::decay_t<X>` to be the same type as `U`; `ValueOrError<U>` to be true, `U`’s `value_type` be constructible into `T`’s `value_type` and `U`’s `error_type` be constructible into `T`’s `error_type`.

-----

-----
