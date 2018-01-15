+++
title = "error_code throw as system_error (Result)"
weight = 30
+++
# Header file `result_error_code_throw_as_system_error.hpp`

<a id="standardese-result_error_code_throw_as_system_error.hpp"></a><pre><code class="standardese-language-cpp"><span class="pre">#include</span> <span class="pre">&quot;</span><a href="doc_common.md#standardese-common.hpp"><span class="typ dec var fun">detail&#x2F;common.hpp</span></a><span class="pre">&quot;</span>

<span class="kwd">namespace</span> <span class="typ dec var fun">outcome_v2_xxx</span>
<span class="pun">{</span>
    <span class="kwd">namespace</span> <span class="typ dec var fun">policy</span>
    <span class="pun">{</span>
        <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">EC</span><span class="pun">&gt;</span>
        <span class="kwd">struct</span> <a href="outcome_error_code_throw_as_system_error#standardese-outcome_v2_xxx::policy::error_code_throw_as_system_error%3CT,EC,E%3E"><span class="typ dec var fun">error_code_throw_as_system_error</span></a><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">,</span> <span class="kwd">EC</span><span class="pun">,</span> <span class="typ dec var fun">void</span><span class="pun">&gt;</span><span class="pun">;</span>
    <span class="pun">}</span>
<span class="pun">}</span>
</code></pre>

<a id="standardese-outcome_v2_xxx"></a>

<a id="standardese-outcome_v2_xxx::policy"></a>

### Struct `outcome_v2_xxx::policy::error_code_throw_as_system_error`

<a id="standardese-outcome_v2_xxx::policy::error_code_throw_as_system_error&lt;T,EC&gt;"></a><pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">EC</span><span class="pun">&gt;</span>
<span class="kwd">struct</span> <a href="outcome_error_code_throw_as_system_error#standardese-outcome_v2_xxx::policy::error_code_throw_as_system_error%3CT,EC,E%3E"><span class="typ dec var fun">error_code_throw_as_system_error</span></a><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">,</span> <span class="kwd">EC</span><span class="pun">,</span> <span class="typ dec var fun">void</span><span class="pun">&gt;</span>
<span class="pun">{</span>
    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
    <span class="kwd">static</span> <span class="kwd">constexpr</span> <span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx::policy::error_code_throw_as_system_error%3CT,EC%3E::wide_value_check%3CImpl%3E(Impl&amp;&amp;)"><span class="typ dec var fun">wide_value_check</span></a><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">self</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
    <span class="kwd">static</span> <span class="kwd">constexpr</span> <span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx::policy::error_code_throw_as_system_error%3CT,EC%3E::wide_error_check%3CImpl%3E(Impl&amp;&amp;)"><span class="typ dec var fun">wide_error_check</span></a><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">self</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
    <span class="kwd">static</span> <span class="kwd">constexpr</span> <span class="kwd">void</span> <a href="throw_bad_result_access#standardese-outcome_v2_xxx::policy::detail::base::narrow_value_check%3CImpl%3E(Impl&amp;&amp;)"><span class="typ dec var fun">narrow_value_check</span></a><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">self</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
    <span class="kwd">static</span> <span class="kwd">constexpr</span> <span class="kwd">void</span> <a href="throw_bad_result_access#standardese-outcome_v2_xxx::policy::detail::base::narrow_error_check%3CImpl%3E(Impl&amp;&amp;)"><span class="typ dec var fun">narrow_error_check</span></a><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">self</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
    <span class="kwd">static</span> <span class="kwd">constexpr</span> <span class="kwd">void</span> <a href="throw_bad_result_access#standardese-outcome_v2_xxx::policy::detail::base::narrow_exception_check%3CImpl%3E(Impl&amp;&amp;)"><span class="typ dec var fun">narrow_exception_check</span></a><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">self</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">;</span>
<span class="pun">};</span>
</code></pre>

Policy interpreting `EC` as a type for which `trait::has_error_code_v<EC>` is true.

Any wide attempt to access the successful state where there is none causes:

1.  If `trait::has_error_payload_v<EC>` is true, it calls an ADL discovered free function `throw_as_system_error_with_payload(.error())`.

2.  If `trait::has_error_payload_v<EC>` is false, it calls `OUTCOME_THROW_EXCEPTION(std::system_error(policy::error_code(.error())))`

### Function `narrow_value_check`

<a id="standardese-outcome_v2_xxx::policy::detail::base::narrow_value_check&lt;Impl&gt;(Impl&amp;&amp;)"></a><pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
<span class="kwd">static</span> <span class="kwd">constexpr</span> <span class="kwd">void</span> <span class="typ dec var fun">narrow_value_check</span><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">self</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

Performs a narrow check of state, used in the assume\_value() functions.

*Effects:* None.

-----

### Function `narrow_error_check`

<a id="standardese-outcome_v2_xxx::policy::detail::base::narrow_error_check&lt;Impl&gt;(Impl&amp;&amp;)"></a><pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
<span class="kwd">static</span> <span class="kwd">constexpr</span> <span class="kwd">void</span> <span class="typ dec var fun">narrow_error_check</span><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">self</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

Performs a narrow check of state, used in the assume\_error() functions

*Effects:* None.

-----

### Function `narrow_exception_check`

<a id="standardese-outcome_v2_xxx::policy::detail::base::narrow_exception_check&lt;Impl&gt;(Impl&amp;&amp;)"></a><pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
<span class="kwd">static</span> <span class="kwd">constexpr</span> <span class="kwd">void</span> <span class="typ dec var fun">narrow_exception_check</span><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">self</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

Performs a narrow check of state, used in the assume\_exception() functions

*Effects:* None.

-----

### Function `wide_value_check`

<a id="standardese-outcome_v2_xxx::policy::error_code_throw_as_system_error&lt;T,EC&gt;::wide_value_check&lt;Impl&gt;(Impl&amp;&amp;)"></a><pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
<span class="kwd">static</span> <span class="kwd">constexpr</span> <span class="kwd">void</span> <span class="typ dec var fun">wide_value_check</span><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">self</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Performs a wide check of state, used in the value() functions.

*Effects:* See description of class for effects.

-----

### Function `wide_error_check`

<a id="standardese-outcome_v2_xxx::policy::error_code_throw_as_system_error&lt;T,EC&gt;::wide_error_check&lt;Impl&gt;(Impl&amp;&amp;)"></a><pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
<span class="kwd">static</span> <span class="kwd">constexpr</span> <span class="kwd">void</span> <span class="typ dec var fun">wide_error_check</span><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">self</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Performs a wide check of state, used in the error() functions

*Effects:* If result does not have an error, it throws `bad_result_access`.

-----

-----
