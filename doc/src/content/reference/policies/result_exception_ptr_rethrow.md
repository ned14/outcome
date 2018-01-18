+++
title = "exception_ptr rethrow (Result)"
weight = 50
+++
# Header file `result_exception_ptr_rethrow.hpp`

<span id="standardese-result_exception_ptr_rethrow-hpp"></span>

<pre><code class="standardese-language-cpp"><span class="pre">#include</span>&nbsp;<span class="pre">&quot;</span><span class="typ dec var fun">detail&#x2F;common.hpp</span><span class="pre">&quot;</span>

<span class="kwd">namespace</span>&nbsp;<span class="typ dec var fun">outcome_v2_xxx</span>
<span class="pun">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">namespace</span>&nbsp;<span class="typ dec var fun">policy</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="pun">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">EC</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">E</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">struct</span> <a href="../outcome_exception_ptr_rethrow#standardese-outcome_v2_xxx__policy__exception_ptr_rethrow-T-EC-E-"><span class="typ dec var fun">exception_ptr_rethrow</span></a><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">EC</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">struct</span> <a href="../outcome_exception_ptr_rethrow#standardese-outcome_v2_xxx__policy__exception_ptr_rethrow-T-EC-E-"><span class="typ dec var fun">exception_ptr_rethrow</span></a><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">,</span>&nbsp;<span class="kwd">EC</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">void</span><span class="pun">&gt;</span><span class="pun">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="pun">}</span>
<span class="pun">}</span>
</code></pre>

<span id="standardese-outcome_v2_xxx"></span>

<span id="standardese-outcome_v2_xxx__policy"></span>

### Struct `outcome_v2_xxx::policy::exception_ptr_rethrow`

<span id="standardese-outcome_v2_xxx__policy__exception_ptr_rethrow-T-EC-E-"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">EC</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">E</span><span class="pun">&gt;</span>
<span class="kwd">struct</span>&nbsp;<span class="typ dec var fun">exception_ptr_rethrow</span><span class="pun">;</span>
</code></pre>

Policy interpreting `EC` or `E` as a type for which `trait::has_exception_ptr_v<EC|E>` is true.

Any wide attempt to access the successful state where there is none causes: `std::rethrow_exception(policy::exception_ptr(.error()|.exception()))` appropriately.

-----
