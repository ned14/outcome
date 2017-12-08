+++
title = "Throw bad_result_access"
slug = "doc_throw_bad_result_access.md"
weight = 40
+++

# Header file `throw_bad_result_access.hpp`

<a id="standardese-throw_bad_result_access.hpp"/>

<pre><code class="standardese-language-cpp"><span class="pre">#include</span> <span class="pre">&quot;</span><span class="typ dec var fun">..&#x2F;bad_access.hpp</span><span class="pre">&quot;</span>

<span class="pre">#include</span> <span class="pre">&quot;</span><span class="typ dec var fun">detail&#x2F;common.hpp</span><span class="pre">&quot;</span>

<span class="kwd">namespace</span> <span class="typ dec var fun">outcome_v2_xxx</span>
<span class="pun">{</span>
    <span class="kwd">namespace</span> <span class="typ dec var fun">policy</span>
    <span class="pun">{</span>
        <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">EC</span><span class="pun">&gt;</span>
        <span class="kwd">struct</span> <a href="doc_throw_bad_result_access.md#standardese-outcome_v2_xxx::policy::throw_bad_result_access%3CEC%3E"><span class="typ dec var fun">throw_bad_result_access</span></a><span class="pun">;</span>
    <span class="pun">}</span>
<span class="pun">}</span>
</code></pre>

<a id="standardese-outcome_v2_xxx"/>

<a id="standardese-outcome_v2_xxx::policy"/>

### Struct `throw_bad_result_access`

<a id="standardese-outcome_v2_xxx::policy::throw_bad_result_access<EC>"/>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">EC</span><span class="pun">&gt;</span>
<span class="kwd">struct</span> <span class="typ dec var fun">throw_bad_result_access</span>
<span class="pun">:</span> <span class="typ dec var fun">detail::base</span>
<span class="pun">{</span>
    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
    <span class="kwd">static</span> <span class="kwd">constexpr</span> <span class="kwd">void</span> <a href="doc_throw_bad_result_access.md#standardese-outcome_v2_xxx::policy::throw_bad_result_access%3CEC%3E::wide_value_check%3CImpl%3E(Impl&amp;&amp;)"><span class="typ dec var fun">wide_value_check</span></a><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">self</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
    <span class="kwd">static</span> <span class="kwd">constexpr</span> <span class="kwd">void</span> <a href="doc_throw_bad_result_access.md#standardese-outcome_v2_xxx::policy::throw_bad_result_access%3CEC%3E::wide_error_check%3CImpl%3E(Impl&amp;&amp;)"><span class="typ dec var fun">wide_error_check</span></a><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">self</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
    <span class="kwd">static</span> <span class="kwd">constexpr</span> <span class="kwd">void</span> <a href="doc_throw_bad_result_access.md#standardese-outcome_v2_xxx::policy::throw_bad_result_access%3CEC%3E::wide_exception_check%3CImpl%3E(Impl&amp;&amp;)"><span class="typ dec var fun">wide_exception_check</span></a><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">self</span><span class="pun">)</span><span class="pun">;</span>
<span class="pun">};</span>
</code></pre>

Policy which throws `bad_result_access_with<EC>` or `bad_result_access` during wide checks.

Can be used in `result` only.

### Function `wide_value_check`

<a id="standardese-outcome_v2_xxx::policy::throw_bad_result_access<EC>::wide_value_check<Impl>(Impl&&)"/>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
<span class="kwd">static</span> <span class="kwd">constexpr</span> <span class="kwd">void</span> <span class="typ dec var fun">wide_value_check</span><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">self</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Performs a wide check of state, used in the value() functions.

*Effects:* If result does not have a value, it throws `bad_result_access_with<EC>`.

-----

### Function `wide_error_check`

<a id="standardese-outcome_v2_xxx::policy::throw_bad_result_access<EC>::wide_error_check<Impl>(Impl&&)"/>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
<span class="kwd">static</span> <span class="kwd">constexpr</span> <span class="kwd">void</span> <span class="typ dec var fun">wide_error_check</span><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">self</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Performs a wide check of state, used in the error() functions

*Effects:* If result does not have an error, it throws `bad_result_access`.

-----

### Function `wide_exception_check`

<a id="standardese-outcome_v2_xxx::policy::throw_bad_result_access<EC>::wide_exception_check<Impl>(Impl&&)"/>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
<span class="kwd">static</span> <span class="kwd">constexpr</span> <span class="kwd">void</span> <span class="typ dec var fun">wide_exception_check</span><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">self</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Performs a wide check of state, used in the exception() functions

*Effects:* If result does not have an exception, it throws `bad_outcome_access`.

-----

-----
