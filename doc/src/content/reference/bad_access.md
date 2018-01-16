+++
title = "Exceptions"
weight = 70
+++
# Header file `bad_access.hpp`

<a id="standardese-bad_access.hpp"></a>
<pre><code class="standardese-language-cpp"><span class="kwd">namespace</span> <span class="typ dec var fun">outcome_v2_xxx</span>
<span class="pun">{</span>
    <span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx::bad_result_access"><span class="typ dec var fun">bad_result_access</span></a><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">&gt;</span>
    <span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx::bad_result_access_with%3CS%3E"><span class="typ dec var fun">bad_result_access_with</span></a><span class="pun">;</span>

    <span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx::bad_outcome_access"><span class="typ dec var fun">bad_outcome_access</span></a><span class="pun">;</span>
<span class="pun">}</span>
</code></pre>

<a id="standardese-outcome_v2_xxx"></a>

### Class `outcome_v2_xxx::bad_result_access`

<a id="standardese-outcome_v2_xxx::bad_result_access"></a>
<pre><code class="standardese-language-cpp"><span class="kwd">class</span> <span class="typ dec var fun">bad_result_access</span>
<span class="pun">:</span> <span class="kwd">public</span> <span class="typ dec var fun">std::logic_error</span>
<span class="pun">{</span>
<span class="kwd">public</span><span class="pun">:</span>
    <span class="kwd">explicit</span> <span class="typ dec var fun">bad_result_access</span><span class="pun">(</span><span class="kwd">char</span> <span class="kwd">const</span><span class="pun">*</span> <span class="typ dec var fun">what</span><span class="pun">)</span><span class="pun">;</span>
<span class="pun">};</span>
</code></pre>

Thrown when you try to access state in a `result<R, S>` which isn’t present.

-----

### Class `outcome_v2_xxx::bad_result_access_with`

<a id="standardese-outcome_v2_xxx::bad_result_access_with&lt;S&gt;"></a>
<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">&gt;</span>
<span class="kwd">class</span> <span class="typ dec var fun">bad_result_access_with</span>
<span class="pun">:</span> <span class="kwd">public</span> <span class="typ dec var fun">bad_result_access</span>
<span class="pun">{</span>
<span class="kwd">public</span><span class="pun">:</span>
    <span class="kwd">explicit</span> <span class="typ dec var fun">bad_result_access_with</span><span class="pun">(</span><span class="typ dec var fun">S</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>

    &#x2F;&#x2F;=== result_error ===&#x2F;&#x2F;
    <span class="typ dec var fun">S</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::bad_result_access_with%3CS%3E::error()const&amp;"><span class="typ dec var fun">error</span></a><span class="pun">(</span><span class="pun">)</span> <span class="kwd">const</span> <span class="pun">&amp;</span><span class="pun">;</span>
    <span class="typ dec var fun">S</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::bad_result_access_with%3CS%3E::error()const&amp;"><span class="typ dec var fun">error</span></a><span class="pun">(</span><span class="pun">)</span> <span class="pun">&amp;</span><span class="pun">;</span>
    <span class="typ dec var fun">S</span> <span class="kwd">const</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::bad_result_access_with%3CS%3E::error()const&amp;"><span class="typ dec var fun">error</span></a><span class="pun">(</span><span class="pun">)</span> <span class="kwd">const</span> <span class="pun">&amp;&amp;</span><span class="pun">;</span>
    <span class="typ dec var fun">S</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::bad_result_access_with%3CS%3E::error()const&amp;"><span class="typ dec var fun">error</span></a><span class="pun">(</span><span class="pun">)</span> <span class="pun">&amp;&amp;</span><span class="pun">;</span>
<span class="pun">};</span>
</code></pre>

Thrown when you try to access a vlue in a `result<R, S>` which isn’t present.

### Function `error`

<a id="standardese-outcome_v2_xxx::bad_result_access_with&lt;S&gt;::error()const&amp;"></a>
<pre><code class="standardese-language-cpp">(1) <span class="typ dec var fun">S</span> <span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">error</span><span class="pun">(</span><span class="pun">)</span> <span class="kwd">const</span> <span class="pun">&amp;</span><span class="pun">;</span>

(2) <span class="typ dec var fun">S</span><span class="pun">&amp;</span> <span class="typ dec var fun">error</span><span class="pun">(</span><span class="pun">)</span> <span class="pun">&amp;</span><span class="pun">;</span>

(3) <span class="typ dec var fun">S</span> <span class="kwd">const</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">error</span><span class="pun">(</span><span class="pun">)</span> <span class="kwd">const</span> <span class="pun">&amp;&amp;</span><span class="pun">;</span>

(4) <span class="typ dec var fun">S</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">error</span><span class="pun">(</span><span class="pun">)</span> <span class="pun">&amp;&amp;</span><span class="pun">;</span>
</code></pre>

Observes the error

-----

-----

### Class `outcome_v2_xxx::bad_outcome_access`

<a id="standardese-outcome_v2_xxx::bad_outcome_access"></a>
<pre><code class="standardese-language-cpp"><span class="kwd">class</span> <span class="typ dec var fun">bad_outcome_access</span>
<span class="pun">:</span> <span class="kwd">public</span> <span class="typ dec var fun">std::logic_error</span>
<span class="pun">{</span>
<span class="kwd">public</span><span class="pun">:</span>
    <span class="kwd">explicit</span> <span class="typ dec var fun">bad_outcome_access</span><span class="pun">(</span><span class="kwd">char</span> <span class="kwd">const</span><span class="pun">*</span> <span class="typ dec var fun">what</span><span class="pun">)</span><span class="pun">;</span>
<span class="pun">};</span>
</code></pre>

Thrown when you try to access state in a `outcome<T, EC, E>` which isn’t present.

-----
