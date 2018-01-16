+++
title = "exception_ptr rethrow (Result)"
weight = 50
+++
# Header file `result_exception_ptr_rethrow.hpp`

<a id="standardese-result_exception_ptr_rethrow.hpp" style="display: none"></a>

<pre><code class="standardese-language-cpp"><span class="pre">#include</span> <span class="pre">&quot;</span><a href="doc_common.md#standardese-common.hpp"><span class="typ dec var fun">detail&#x2F;common.hpp</span></a><span class="pre">&quot;</span>

<span class="kwd">namespace</span> <span class="typ dec var fun">outcome_v2_xxx</span>
<span class="pun">{</span>
    <span class="kwd">namespace</span> <span class="typ dec var fun">policy</span>
    <span class="pun">{</span>
        <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">EC</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">E</span><span class="pun">&gt;</span>
        <span class="kwd">struct</span> <a href="outcome_exception_ptr_rethrow#standardese-outcome_v2_xxx::policy::exception_ptr_rethrow%3CT,EC,E%3E"><span class="typ dec var fun">exception_ptr_rethrow</span></a><span class="pun">;</span>

        <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">EC</span><span class="pun">&gt;</span>
        <span class="kwd">struct</span> <a href="outcome_exception_ptr_rethrow#standardese-outcome_v2_xxx::policy::exception_ptr_rethrow%3CT,EC,E%3E"><span class="typ dec var fun">exception_ptr_rethrow</span></a><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">,</span> <span class="kwd">EC</span><span class="pun">,</span> <span class="typ dec var fun">void</span><span class="pun">&gt;</span><span class="pun">;</span>
    <span class="pun">}</span>
<span class="pun">}</span>
</code></pre>

<a id="standardese-outcome_v2_xxx" style="display: none"></a>

<a id="standardese-outcome_v2_xxx::policy" style="display: none"></a>

### Struct `outcome_v2_xxx::policy::exception_ptr_rethrow`

<a id="standardese-outcome_v2_xxx::policy::exception_ptr_rethrow&lt;T,EC,E&gt;" style="display: none"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">EC</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">E</span><span class="pun">&gt;</span>
<span class="kwd">struct</span> <span class="typ dec var fun">exception_ptr_rethrow</span><span class="pun">;</span>
</code></pre>

Policy interpreting `EC` or `E` as a type for which `trait::has_exception_ptr_v<EC|E>` is true.

Any wide attempt to access the successful state where there is none causes: `std::rethrow_exception(policy::exception_ptr(.error()|.exception()))` appropriately.

-----
