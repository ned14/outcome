+++
title = "Throw bad_result_access"
weight = 70
+++
# Header file `throw_bad_result_access.hpp`

<span id="standardese-throw_bad_result_access-hpp"></span>

<pre><code class="standardese-language-cpp"><span class="pre">#include</span>&nbsp;<span class="pre">&quot;</span><span class="typ dec var fun">detail&#x2F;common.hpp</span><span class="pre">&quot;</span>

<span class="kwd">namespace</span>&nbsp;<span class="typ dec var fun">outcome_v2_xxx</span>
<span class="pun">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">namespace</span>&nbsp;<span class="typ dec var fun">policy</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="pun">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">EC</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">struct</span> <a href="#standardese-outcome_v2_xxx__policy__throw_bad_result_access-EC-"><span class="typ dec var fun">throw_bad_result_access</span></a><span class="pun">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="pun">}</span>
<span class="pun">}</span>
</code></pre>

<span id="standardese-outcome_v2_xxx"></span>

<span id="standardese-outcome_v2_xxx__policy"></span>

### Struct `outcome_v2_xxx::policy::throw_bad_result_access`

<span id="standardese-outcome_v2_xxx__policy__throw_bad_result_access-EC-"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">EC</span><span class="pun">&gt;</span>
<span class="kwd">struct</span>&nbsp;<span class="typ dec var fun">throw_bad_result_access</span>
<span class="pun">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">static</span>&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx__policy__throw_bad_result_access-EC-__wide_value_check-Impl--Impl---"><span class="typ dec var fun">wide_value_check</span></a><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">self</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">static</span>&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx__policy__throw_bad_result_access-EC-__wide_error_check-Impl--Impl---"><span class="typ dec var fun">wide_error_check</span></a><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">self</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">static</span>&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx__policy__throw_bad_result_access-EC-__wide_exception_check-Impl--Impl---"><span class="typ dec var fun">wide_exception_check</span></a><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">self</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">static</span>&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span> <a href="../result_exception_ptr_rethrow#standardese-outcome_v2_xxx__policy__detail__base__narrow_value_check-Impl--Impl---"><span class="typ dec var fun">narrow_value_check</span></a><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">self</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">static</span>&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span> <a href="../result_exception_ptr_rethrow#standardese-outcome_v2_xxx__policy__detail__base__narrow_error_check-Impl--Impl---"><span class="typ dec var fun">narrow_error_check</span></a><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">self</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">static</span>&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span> <a href="../result_exception_ptr_rethrow#standardese-outcome_v2_xxx__policy__detail__base__narrow_exception_check-Impl--Impl---"><span class="typ dec var fun">narrow_exception_check</span></a><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">self</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
<span class="pun">};</span>
</code></pre>

Policy which throws `bad_result_access_with<EC>` or `bad_result_access` during wide checks.

Can be used in `result` only.

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

### Function `outcome_v2_xxx::policy::throw_bad_result_access::wide_value_check`

<span id="standardese-outcome_v2_xxx__policy__throw_bad_result_access-EC-__wide_value_check-Impl--Impl---"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
<span class="kwd">static</span>&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span>&nbsp;<span class="typ dec var fun">wide_value_check</span><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">self</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Performs a wide check of state, used in the value() functions.

*Effects:* If result does not have a value, it throws `bad_result_access_with<EC>`.

-----

### Function `outcome_v2_xxx::policy::throw_bad_result_access::wide_error_check`

<span id="standardese-outcome_v2_xxx__policy__throw_bad_result_access-EC-__wide_error_check-Impl--Impl---"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
<span class="kwd">static</span>&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span>&nbsp;<span class="typ dec var fun">wide_error_check</span><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">self</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Performs a wide check of state, used in the error() functions

*Effects:* If result does not have an error, it throws `bad_result_access`.

-----

### Function `outcome_v2_xxx::policy::throw_bad_result_access::wide_exception_check`

<span id="standardese-outcome_v2_xxx__policy__throw_bad_result_access-EC-__wide_exception_check-Impl--Impl---"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">Impl</span><span class="pun">&gt;</span>
<span class="kwd">static</span>&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span>&nbsp;<span class="typ dec var fun">wide_exception_check</span><span class="pun">(</span><span class="typ dec var fun">Impl</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">self</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Performs a wide check of state, used in the exception() functions

*Effects:* If result does not have an exception, it throws `bad_outcome_access`.

-----

-----
