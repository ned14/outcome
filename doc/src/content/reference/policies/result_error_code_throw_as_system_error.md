+++
title = "error_code throw as system_error (Result)"
weight = 30
+++
# Header file `result_error_code_throw_as_system_error.hpp`

<span id="standardese-result_error_code_throw_as_system_error-hpp"></span>

<pre><code class="standardese-language-cpp"><span class="pre">#include</span>&nbsp;<span class="pre">&quot;</span><a href="doc_common.md#standardese-common-hpp"><span class="typ dec var fun">detail&#x2F;common.hpp</span></a><span class="pre">&quot;</span>

<span class="kwd">namespace</span>&nbsp;<span class="typ dec var fun">outcome_v2_xxx</span>
<span class="pun">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">namespace</span>&nbsp;<span class="typ dec var fun">policy</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="pun">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">EC</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">struct</span> <a href="outcome_error_code_throw_as_system_error#standardese-outcome_v2_xxx__policy__error_code_throw_as_system_error-T-EC-E-"><span class="typ dec var fun">error_code_throw_as_system_error</span></a><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">,</span>&nbsp;<span class="kwd">EC</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">void</span><span class="pun">&gt;</span><span class="pun">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="pun">}</span>
<span class="pun">}</span>
</code></pre>

<span id="standardese-outcome_v2_xxx"></span>

<span id="standardese-outcome_v2_xxx__policy"></span>

### Struct `outcome_v2_xxx::policy::error_code_throw_as_system_error`

<span id="standardese-outcome_v2_xxx__policy__error_code_throw_as_system_error-T-EC-"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">EC</span><span class="pun">&gt;</span>
<span class="kwd">struct</span> <a href="outcome_error_code_throw_as_system_error#standardese-outcome_v2_xxx__policy__error_code_throw_as_system_error-T-EC-E-"><span class="typ dec var fun">error_code_throw_as_system_error</span></a><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">,</span>&nbsp;<span class="kwd">EC</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">void</span><span class="pun">&gt;</span>
<span class="pun">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">static</span>&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx__policy__error_code_throw_as_system_error-T-EC-__wide_value_check-Impl--Impl---"><span class="typ dec var fun">wide_value_check</span></a><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">self</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">static</span>&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx__policy__error_code_throw_as_system_error-T-EC-__wide_error_check-Impl--Impl---"><span class="typ dec var fun">wide_error_check</span></a><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">self</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">static</span>&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span> <a href="outcome_exception_ptr_rethrow#standardese-outcome_v2_xxx__policy__detail__base__narrow_value_check-Impl--Impl---"><span class="typ dec var fun">narrow_value_check</span></a><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">self</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">static</span>&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span> <a href="outcome_exception_ptr_rethrow#standardese-outcome_v2_xxx__policy__detail__base__narrow_error_check-Impl--Impl---"><span class="typ dec var fun">narrow_error_check</span></a><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">self</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">static</span>&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span> <a href="outcome_exception_ptr_rethrow#standardese-outcome_v2_xxx__policy__detail__base__narrow_exception_check-Impl--Impl---"><span class="typ dec var fun">narrow_exception_check</span></a><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">self</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
<span class="pun">};</span>
</code></pre>

Policy interpreting `EC` as a type for which `trait::has_error_code_v<EC>` is true.

Any wide attempt to access the successful state where there is none causes:

1.  If `trait::has_error_payload_v<EC>` is true, it calls an ADL discovered free function `throw_as_system_error_with_payload(.error())`.

2.  If `trait::has_error_payload_v<EC>` is false, it calls `OUTCOME_THROW_EXCEPTION(std::system_error(policy::error_code(.error())))`

### Function `outcome_v2_xxx::policy::throw_bad_result_access::narrow_value_check`

<span id="standardese-outcome_v2_xxx__policy__detail__base__narrow_value_check-Impl--Impl---"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
<span class="kwd">static</span>&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span>&nbsp;<span class="typ dec var fun">narrow_value_check</span><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">self</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

Performs a narrow check of state, used in the assume\_value() functions.

*Effects:* None.

-----

### Function `outcome_v2_xxx::policy::throw_bad_result_access::narrow_error_check`

<span id="standardese-outcome_v2_xxx__policy__detail__base__narrow_error_check-Impl--Impl---"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
<span class="kwd">static</span>&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span>&nbsp;<span class="typ dec var fun">narrow_error_check</span><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">self</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

Performs a narrow check of state, used in the assume\_error() functions

*Effects:* None.

-----

### Function `outcome_v2_xxx::policy::throw_bad_result_access::narrow_exception_check`

<span id="standardese-outcome_v2_xxx__policy__detail__base__narrow_exception_check-Impl--Impl---"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
<span class="kwd">static</span>&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span>&nbsp;<span class="typ dec var fun">narrow_exception_check</span><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">self</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

Performs a narrow check of state, used in the assume\_exception() functions

*Effects:* None.

-----

### Function `outcome_v2_xxx::policy::error_code_throw_as_system_error::wide_value_check`

<span id="standardese-outcome_v2_xxx__policy__error_code_throw_as_system_error-T-EC-__wide_value_check-Impl--Impl---"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
<span class="kwd">static</span>&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span>&nbsp;<span class="typ dec var fun">wide_value_check</span><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">self</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Performs a wide check of state, used in the value() functions.

*Effects:* See description of class for effects.

-----

### Function `outcome_v2_xxx::policy::error_code_throw_as_system_error::wide_error_check`

<span id="standardese-outcome_v2_xxx__policy__error_code_throw_as_system_error-T-EC-__wide_error_check-Impl--Impl---"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
<span class="kwd">static</span>&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span>&nbsp;<span class="typ dec var fun">wide_error_check</span><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">self</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Performs a wide check of state, used in the error() functions

*Effects:* If result does not have an error, it throws `bad_result_access`.

-----

-----
