+++
title = "result<R, S>"
weight = 20
+++
# Header file `result.hpp`

<span id="standardese-result-hpp"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">namespace</span>&nbsp;<span class="typ dec var fun">outcome_v2_xxx</span>
<span class="pun">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">namespace</span> <span class="typ dec var fun">policy</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="pun">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">EC</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">E</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx__policy__default_policy-T-EC-E-"><span class="typ dec var fun">default_policy</span></a>&nbsp;<span class="pun">=</span>&nbsp;<span class="typ dec var fun">std::conditional_t</span><span class="pun">&lt;</span>std::is_void&lt;EC&gt;::value &amp;&amp; std::is_void&lt;E&gt;::value, terminate, std::conditional_t&lt;trait::has_error_code_v&lt;EC&gt;, error_code_throw_as_system_error&lt;T, EC, E&gt;, std::conditional_t&lt;trait::has_exception_ptr_v&lt;EC&gt; || trait::has_exception_ptr_v&lt;E&gt;, exception_ptr_rethrow&lt;T, EC, E&gt;, all_narrow&gt; &gt;<span class="pun">&gt;</span><span class="pun">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="pun">}</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx__is_result-T-"><span class="typ dec var fun">is_result</span></a>&nbsp;<span class="pun">=</span>&nbsp;<span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span>&nbsp;<span class="kwd">T</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">is_result_v</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">detail</span><span class="pun">::</span><span class="kwd">is_result</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">namespace</span> <span class="typ dec var fun">hooks</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="pun">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx__hooks__hook_result_construction-T-U--T--U---"><span class="typ dec var fun">hook_result_construction</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">*</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&amp;&amp;</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx__hooks__hook_result_copy_construction-T-U--T--U---"><span class="typ dec var fun">hook_result_copy_construction</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">*</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&amp;&amp;</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx__hooks__hook_result_move_construction-T-U--T--U---"><span class="typ dec var fun">hook_result_move_construction</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">*</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&amp;&amp;</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="pun">...</span>&nbsp;<span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx__hooks__hook_result_in_place_construction-T-U-Args--T--in_place_type_t-U--Args------"><span class="typ dec var fun">hook_result_in_place_construction</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">*</span><span class="pun">,</span> <a href="doc_value_storage.md#standardese-outcome_v2_xxx__in_place_type_t-T-"><span class="typ dec var fun">in_place_type_t</span></a><span class="pun">&lt;</span>U<span class="pun">&gt;</span><span class="pun">,</span> Args &amp;&amp;...<span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">R</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">S</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">NoValuePolicy</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">uint16_t</span> <a href="#standardese-outcome_v2_xxx__hooks__spare_storage-R-S-NoValuePolicy--detail__result_final-R-S-NoValuePolicy-const--"><span class="typ dec var fun">spare_storage</span></a><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span>&nbsp;<span class="kwd">const</span><span class="pun">*</span>&nbsp;<span class="typ dec var fun">r</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">R</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">S</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">NoValuePolicy</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx__hooks__set_spare_storage-R-S-NoValuePolicy--detail__result_final-R-S-NoValuePolicy---uint16_t-"><span class="typ dec var fun">set_spare_storage</span></a><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">*</span>&nbsp;<span class="typ dec var fun">r</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">uint16_t</span>&nbsp;<span class="typ dec var fun">v</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="pun">}</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy--R"><span class="typ dec var fun">R</span></a><span class="pun">,</span>&nbsp;<span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy--S"><span class="typ dec var fun">S</span></a><span class="pun">,</span>&nbsp;<span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy--NoValuePolicy"><span class="typ dec var fun">NoValuePolicy</span></a><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-"><span class="typ dec var fun">result</span></a><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">R</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">S</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">P</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx__swap-R-S-P--result-R-S-P---result-R-S-P---"><span class="typ dec var fun">swap</span></a><span class="pun">(</span><a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>R, S, P<span class="pun">&gt;</span><span class="pun">&amp;</span>&nbsp;<span class="typ dec var fun">a</span><span class="pun">,</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>R, S, P<span class="pun">&gt;</span><span class="pun">&amp;</span>&nbsp;<span class="typ dec var fun">b</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">is_result_v</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">detail</span><span class="pun">::</span><span class="kwd">is_result</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">is_result_v</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">detail</span><span class="pun">::</span><span class="kwd">is_result</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">R</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">S</span>&nbsp;<span class="pun">=</span> std::error_code<span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx__unchecked-R-S-"><span class="typ dec var fun">unchecked</span></a>&nbsp;<span class="pun">=</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>R, S, policy::all_narrow<span class="pun">&gt;</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">R</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">S</span>&nbsp;<span class="pun">=</span> std::error_code<span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx__checked-R-S-"><span class="typ dec var fun">checked</span></a>&nbsp;<span class="pun">=</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>R, S, policy::throw_bad_result_access&lt;S&gt;<span class="pun">&gt;</span><span class="pun">;</span>
<span class="pun">}</span>
</code></pre>

<span id="standardese-outcome_v2_xxx"></span>

<span id="standardese-outcome_v2_xxx__policy"></span>

### Alias template `outcome_v2_xxx::policy::default_policy`

<span id="standardese-outcome_v2_xxx__policy__default_policy-T-EC-E-"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">EC</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">E</span><span class="pun">&gt;</span>
<span class="kwd">using</span>&nbsp;<span class="typ dec var fun">default_policy</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="typ dec var fun">std::conditional_t</span><span class="pun">&lt;</span>std::is_void&lt;EC&gt;::value &amp;&amp; std::is_void&lt;E&gt;::value, terminate, std::conditional_t&lt;trait::has_error_code_v&lt;EC&gt;, error_code_throw_as_system_error&lt;T, EC, E&gt;, std::conditional_t&lt;trait::has_exception_ptr_v&lt;EC&gt; || trait::has_exception_ptr_v&lt;E&gt;, exception_ptr_rethrow&lt;T, EC, E&gt;, all_narrow&gt; &gt;<span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

Default policy selector.

-----

### Alias template `outcome_v2_xxx::is_result`

<span id="standardese-outcome_v2_xxx__is_result-T-"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">using</span>&nbsp;<span class="typ dec var fun">is_result</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">;</span>
</code></pre>

True if a result

-----

### Unexposed entity `outcome_v2_xxx::is_result_v`

<span id="standardese-outcome_v2_xxx__is_result_v"></span>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span>&nbsp;<span class="kwd">T</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">is_result_v</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">detail</span><span class="pun">::</span><span class="kwd">is_result</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>
</code></pre>

True if a result

-----

<span id="standardese-outcome_v2_xxx__hooks"></span>

### Function `outcome_v2_xxx::hooks::hook_result_construction`

<span id="standardese-outcome_v2_xxx__hooks__hook_result_construction-T-U--T--U---"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span>&nbsp;<span class="typ dec var fun">hook_result_construction</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">*</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&amp;&amp;</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

The default instantiation hook implementation called when a `result` is first created by conversion from one of its possible types. Does nothing.

WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should\!

#### Parameters

  - `  ` &mdash; Some `result<...>` being constructed.

-----

### Function `outcome_v2_xxx::hooks::hook_result_copy_construction`

<span id="standardese-outcome_v2_xxx__hooks__hook_result_copy_construction-T-U--T--U---"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span>&nbsp;<span class="typ dec var fun">hook_result_copy_construction</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">*</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&amp;&amp;</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

The default instantiation hook implementation called when a `result` is created by copying from another `result`. Does nothing.

WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should\!

#### Parameters

  - `  ` &mdash; Some `result<...>` being constructed.

-----

### Function `outcome_v2_xxx::hooks::hook_result_move_construction`

<span id="standardese-outcome_v2_xxx__hooks__hook_result_move_construction-T-U--T--U---"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span>&nbsp;<span class="typ dec var fun">hook_result_move_construction</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">*</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&amp;&amp;</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

The default instantiation hook implementation called when a `result` is created by moving from another `result`. Does nothing.

WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should\!

#### Parameters

  - `  ` &mdash; Some `result<...>` being constructed.

-----

### Function `outcome_v2_xxx::hooks::hook_result_in_place_construction`

<span id="standardese-outcome_v2_xxx__hooks__hook_result_in_place_construction-T-U-Args--T--in_place_type_t-U--Args------"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="pun">...</span>&nbsp;<span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span>&nbsp;<span class="typ dec var fun">hook_result_in_place_construction</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">*</span><span class="pun">,</span> <a href="doc_value_storage.md#standardese-outcome_v2_xxx__in_place_type_t-T-"><span class="typ dec var fun">in_place_type_t</span></a><span class="pun">&lt;</span>U<span class="pun">&gt;</span><span class="pun">,</span> Args &amp;&amp;...<span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

The default instantiation hook implementation called when a `result` is created by in place construction. Does nothing.

WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should\!

#### Parameters

  - `  ` &mdash; Some `result<...>` being constructed.
  - `  ` &mdash; The type of in place construction occurring.

-----

### Function `outcome_v2_xxx::hooks::spare_storage`

<span id="standardese-outcome_v2_xxx__hooks__spare_storage-R-S-NoValuePolicy--detail__result_final-R-S-NoValuePolicy-const--"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">R</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">S</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">NoValuePolicy</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">uint16_t</span>&nbsp;<span class="typ dec var fun">spare_storage</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span>&nbsp;<span class="kwd">const</span><span class="pun">*</span>&nbsp;<span class="typ dec var fun">r</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

Retrieves the 16 bits of spare storage in result/outcome.

-----

### Function `outcome_v2_xxx::hooks::set_spare_storage`

<span id="standardese-outcome_v2_xxx__hooks__set_spare_storage-R-S-NoValuePolicy--detail__result_final-R-S-NoValuePolicy---uint16_t-"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">R</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">S</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">NoValuePolicy</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span>&nbsp;<span class="typ dec var fun">set_spare_storage</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">*</span>&nbsp;<span class="typ dec var fun">r</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">uint16_t</span>&nbsp;<span class="typ dec var fun">v</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

Sets the 16 bits of spare storage in result/outcome.

-----

### Class `outcome_v2_xxx::result`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy--R"><span class="typ dec var fun">R</span></a><span class="pun">,</span>&nbsp;<span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy--S"><span class="typ dec var fun">S</span></a><span class="pun">,</span>&nbsp;<span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy--NoValuePolicy"><span class="typ dec var fun">NoValuePolicy</span></a><span class="pun">&gt;</span>
<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">result</span>
<span class="pun">{</span>
<span class="kwd">public</span><span class="pun">:</span>
    &#x2F;&#x2F;=== Member types ===&#x2F;&#x2F;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__value_type"><span class="typ dec var fun">value_type</span></a>&nbsp;<span class="pun">=</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy--R"><span class="typ dec var fun">R</span></a><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__error_type"><span class="typ dec var fun">error_type</span></a>&nbsp;<span class="pun">=</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy--S"><span class="typ dec var fun">S</span></a><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__value_type_if_enabled"><span class="typ dec var fun">value_type_if_enabled</span></a>&nbsp;<span class="pun">=</span> typename base::_value_type<span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__error_type_if_enabled"><span class="typ dec var fun">error_type_if_enabled</span></a>&nbsp;<span class="pun">=</span> typename base::_error_type<span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span>&nbsp;<span class="pun">=</span> S<span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">V</span>&nbsp;<span class="pun">=</span> policy::default_policy&lt;T,U,void&gt;<span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__rebind-T-U-V-"><span class="typ dec var fun">rebind</span></a>&nbsp;<span class="pun">=</span>&nbsp;<span class="typ dec var fun">result</span><span class="pun">&lt;</span>T, U, V<span class="pun">&gt;</span><span class="pun">;</span>

<span class="kwd">protected</span><span class="pun">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">struct</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__predicate"><span class="typ dec var fun">predicate</span></a><span class="pun">;</span>

<span class="kwd">public</span><span class="pun">:</span>
    &#x2F;&#x2F;=== Default, copy&#x2F;move constructors and assignment ===&#x2F;&#x2F;
    <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result--"><span class="typ dec var fun">result</span></a><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">delete</span><span class="pun">;</span>

    <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-result-R-S-NoValuePolicy----"><span class="typ dec var fun">result</span></a><span class="pun">(</span>result&lt;R, S, NoValuePolicy&gt;<span class="pun">&amp;&amp;</span><span class="pun">)</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">default</span><span class="pun">;</span>

    <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-constresult-R-S-NoValuePolicy---"><span class="typ dec var fun">result</span></a><span class="pun">(</span>const result&lt;R, S, NoValuePolicy&gt;<span class="pun">&amp;</span><span class="pun">)</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">default</span><span class="pun">;</span>

    result&lt;R, S, NoValuePolicy&gt;<span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__operator--result-R-S-NoValuePolicy----"><span class="typ dec var fun">operator=</span></a><span class="pun">(</span>result&lt;R, S, NoValuePolicy&gt;<span class="pun">&amp;&amp;</span><span class="pun">)</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">default</span><span class="pun">;</span>

    result&lt;R, S, NoValuePolicy&gt;<span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__operator--constresult-R-S-NoValuePolicy---"><span class="typ dec var fun">operator=</span></a><span class="pun">(</span>const result&lt;R, S, NoValuePolicy&gt;<span class="pun">&amp;</span><span class="pun">)</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">default</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="typ dec var fun">~result</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">default</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T---T---outcome_v2_xxx__result__value_converting_constructor_tag-"><span class="typ dec var fun">result</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T---T---outcome_v2_xxx__result__value_converting_constructor_tag--t"><span class="typ dec var fun">t</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T---T---outcome_v2_xxx__result__error_converting_constructor_tag-"><span class="typ dec var fun">result</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T---T---outcome_v2_xxx__result__error_converting_constructor_tag--t"><span class="typ dec var fun">t</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">ErrorCondEnum</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-ErrorCondEnum----ErrorCondEnum---outcome_v2_xxx__result__error_condition_converting_constructor_tag-"><span class="typ dec var fun">result</span></a><span class="pun">(</span><span class="typ dec var fun">ErrorCondEnum</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-ErrorCondEnum----ErrorCondEnum---outcome_v2_xxx__result__error_condition_converting_constructor_tag--t"><span class="typ dec var fun">t</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T----T---outcome_v2_xxx__result__explicit_valueorerror_converting_constructor_tag-"><span class="typ dec var fun">result</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T----T---outcome_v2_xxx__result__explicit_valueorerror_converting_constructor_tag--o"><span class="typ dec var fun">o</span></a><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">V</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T-U-V---result-T-U-V-const--"><span class="typ dec var fun">result</span></a><span class="pun">(</span><span class="typ dec var fun">result</span><span class="pun">&lt;</span>T, U, V<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T-U-V---result-T-U-V-const---o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">V</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T-U-V---result-T-U-V----"><span class="typ dec var fun">result</span></a><span class="pun">(</span><span class="typ dec var fun">result</span><span class="pun">&lt;</span>T, U, V<span class="pun">&gt;</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T-U-V---result-T-U-V-----o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="pun">...</span>&nbsp;<span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-Args---in_place_type_t-outcome_v2_xxx__result__value_type_if_enabled--Args------"><span class="typ dec var fun">result</span></a><span class="pun">(</span><a href="doc_value_storage.md#standardese-outcome_v2_xxx__in_place_type_t-T-"><span class="typ dec var fun">in_place_type_t</span></a><span class="pun">&lt;</span>outcome_v2_xxx::result::value_type_if_enabled<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-Args---in_place_type_t-outcome_v2_xxx__result__value_type_if_enabled--Args-------_"><span class="typ dec var fun">_</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-Args---in_place_type_t-outcome_v2_xxx__result__value_type_if_enabled--Args-------args"><span class="typ dec var fun">args</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="pun">...</span>&nbsp;<span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-U-Args---in_place_type_t-outcome_v2_xxx__result__value_type_if_enabled--std__initializer_list-U--Args------"><span class="typ dec var fun">result</span></a><span class="pun">(</span><a href="doc_value_storage.md#standardese-outcome_v2_xxx__in_place_type_t-T-"><span class="typ dec var fun">in_place_type_t</span></a><span class="pun">&lt;</span>outcome_v2_xxx::result::value_type_if_enabled<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-U-Args---in_place_type_t-outcome_v2_xxx__result__value_type_if_enabled--std__initializer_list-U--Args-------_"><span class="typ dec var fun">_</span></a><span class="pun">,</span>&nbsp;<span class="typ dec var fun">std::initializer_list</span><span class="pun">&lt;</span>U<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-U-Args---in_place_type_t-outcome_v2_xxx__result__value_type_if_enabled--std__initializer_list-U--Args-------il"><span class="typ dec var fun">il</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-U-Args---in_place_type_t-outcome_v2_xxx__result__value_type_if_enabled--std__initializer_list-U--Args-------args"><span class="typ dec var fun">args</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="pun">...</span>&nbsp;<span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-Args---in_place_type_t-outcome_v2_xxx__result__error_type_if_enabled--Args------"><span class="typ dec var fun">result</span></a><span class="pun">(</span><a href="doc_value_storage.md#standardese-outcome_v2_xxx__in_place_type_t-T-"><span class="typ dec var fun">in_place_type_t</span></a><span class="pun">&lt;</span>outcome_v2_xxx::result::error_type_if_enabled<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-Args---in_place_type_t-outcome_v2_xxx__result__error_type_if_enabled--Args-------_"><span class="typ dec var fun">_</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-Args---in_place_type_t-outcome_v2_xxx__result__error_type_if_enabled--Args-------args"><span class="typ dec var fun">args</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="pun">...</span>&nbsp;<span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-U-Args---in_place_type_t-outcome_v2_xxx__result__error_type_if_enabled--std__initializer_list-U--Args------"><span class="typ dec var fun">result</span></a><span class="pun">(</span><a href="doc_value_storage.md#standardese-outcome_v2_xxx__in_place_type_t-T-"><span class="typ dec var fun">in_place_type_t</span></a><span class="pun">&lt;</span>outcome_v2_xxx::result::error_type_if_enabled<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-U-Args---in_place_type_t-outcome_v2_xxx__result__error_type_if_enabled--std__initializer_list-U--Args-------_"><span class="typ dec var fun">_</span></a><span class="pun">,</span>&nbsp;<span class="typ dec var fun">std::initializer_list</span><span class="pun">&lt;</span>U<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-U-Args---in_place_type_t-outcome_v2_xxx__result__error_type_if_enabled--std__initializer_list-U--Args-------il"><span class="typ dec var fun">il</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-U-Args---in_place_type_t-outcome_v2_xxx__result__error_type_if_enabled--std__initializer_list-U--Args-------args"><span class="typ dec var fun">args</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">A1</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">A2</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="pun">...</span>&nbsp;<span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-A1-A2-Args---A1---A2---Args------"><span class="typ dec var fun">result</span></a><span class="pun">(</span><span class="typ dec var fun">A1</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">a1</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">A2</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">a2</span><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-A1-A2-Args---A1---A2---Args-------args"><span class="typ dec var fun">args</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-success_type-void-const--"><span class="typ dec var fun">result</span></a><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx__success_type-T-"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>void<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-success_type-void-const---o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T---success_type-T-const--"><span class="typ dec var fun">result</span></a><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx__success_type-T-"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>T<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T---success_type-T-const---o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T---success_type-T----"><span class="typ dec var fun">result</span></a><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx__success_type-T-"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>T<span class="pun">&gt;</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T---success_type-T-----o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T---failure_type-T-const--"><span class="typ dec var fun">result</span></a><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx__failure_type-EC-E-"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>T<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T---failure_type-T-const---o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T---failure_type-T----"><span class="typ dec var fun">result</span></a><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx__failure_type-EC-E-"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>T<span class="pun">&gt;</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T---failure_type-T-----o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__swap-result-R-S-NoValuePolicy---"><span class="typ dec var fun">swap</span></a><span class="pun">(</span>result&lt;R, S, NoValuePolicy&gt;<span class="pun">&amp;</span>&nbsp;<span class="typ dec var fun">o</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">auto</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__as_failure--const-"><span class="typ dec var fun">as_failure</span></a><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="pun">&amp;</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">auto</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__as_failure----"><span class="typ dec var fun">as_failure</span></a><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="pun">&amp;&amp;</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">using</span>&nbsp;<span class="typ dec var fun">error_type</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">;</span>

    &#x2F;&#x2F;=== assume_error ===&#x2F;&#x2F;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">error_type</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__detail__result_error_observers-Base-EC-NoValuePolicy-__assume_error---"><span class="typ dec var fun">assume_error</span></a><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="pun">&amp;</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">error_type</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__detail__result_error_observers-Base-EC-NoValuePolicy-__assume_error---"><span class="typ dec var fun">assume_error</span></a><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="pun">&amp;</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">error_type</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__detail__result_error_observers-Base-EC-NoValuePolicy-__assume_error---"><span class="typ dec var fun">assume_error</span></a><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="pun">&amp;&amp;</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">error_type</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__detail__result_error_observers-Base-EC-NoValuePolicy-__assume_error---"><span class="typ dec var fun">assume_error</span></a><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="pun">&amp;&amp;</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>

    &#x2F;&#x2F;=== error ===&#x2F;&#x2F;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">error_type</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__detail__result_error_observers-Base-EC-NoValuePolicy-__error---"><span class="typ dec var fun">error</span></a><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="pun">&amp;</span><span class="pun">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">error_type</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__detail__result_error_observers-Base-EC-NoValuePolicy-__error---"><span class="typ dec var fun">error</span></a><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="pun">&amp;</span><span class="pun">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">error_type</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__detail__result_error_observers-Base-EC-NoValuePolicy-__error---"><span class="typ dec var fun">error</span></a><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="pun">&amp;&amp;</span><span class="pun">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">error_type</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__detail__result_error_observers-Base-EC-NoValuePolicy-__error---"><span class="typ dec var fun">error</span></a><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="pun">&amp;&amp;</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">explicit</span>&nbsp;<span class="kwd">operator</span>&nbsp;<span class="kwd">bool</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span> <a href="#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__has_value--const"><span class="typ dec var fun">has_value</span></a><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span> <a href="#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__has_error--const"><span class="typ dec var fun">has_error</span></a><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span> <a href="#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__has_exception--const"><span class="typ dec var fun">has_exception</span></a><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span> <a href="#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__has_failure--const"><span class="typ dec var fun">has_failure</span></a><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">V</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span> <a href="#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T-U-V--result_final-T-U-V-const--const"><span class="typ dec var fun">operator==</span></a><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="doc_result_final.md#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T-U-V--result_final-T-U-V-const--const-o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span> <a href="#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T--success_type-T-const--const"><span class="typ dec var fun">operator==</span></a><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx__success_type-T-"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>T<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="doc_result_final.md#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T--success_type-T-const--const-o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span> <a href="#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---success_type-void-const--const"><span class="typ dec var fun">operator==</span></a><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx__success_type-T-"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>void<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="doc_result_final.md#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---success_type-void-const--const-o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span> <a href="#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T--failure_type-T-void-const--const"><span class="typ dec var fun">operator==</span></a><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx__failure_type-EC-E-"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>T, void<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="doc_result_final.md#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T--failure_type-T-void-const--const-o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">V</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span> <a href="#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T-U-V--result_final-T-U-V-const--const"><span class="typ dec var fun">operator!=</span></a><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="doc_result_final.md#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T-U-V--result_final-T-U-V-const--const-o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span> <a href="#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T--success_type-T-const--const"><span class="typ dec var fun">operator!=</span></a><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx__success_type-T-"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>T<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="doc_result_final.md#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T--success_type-T-const--const-o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span> <a href="#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---success_type-void-const--const"><span class="typ dec var fun">operator!=</span></a><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx__success_type-T-"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>void<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="doc_result_final.md#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---success_type-void-const--const-o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span> <a href="#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T--failure_type-T-void-const--const"><span class="typ dec var fun">operator!=</span></a><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx__failure_type-EC-E-"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>T, void<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="doc_result_final.md#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T--failure_type-T-void-const--const-o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
<span class="pun">};</span>
</code></pre>

Used to return from functions either (i) a successful value (ii) a cause of failure. `constexpr` capable.

Any `R` (`value_type`) state can be observed using the member functions `.value()` and `.assume_value()`. Any `S` (`error_type`) state can be observed using the member functions `.error()` and `.assume_error()`.

`NoValuePolicy` defaults to a policy selected according to the characteristics of type `S`:

1.  If `.value()` called when there is no `value_type` but there is an `error_type`:
    
      - If {{<api "success_failure/#unexposed-entity-outcome-v2-xxx-trait-has-error-code-v" "trait::has_error_code_v<S>">}} is true, then `throw std::system_error(error()|make_error_code(error()))` \[{{<api "policies/result_error_code_throw_as_system_error" "policy::error_code_throw_as_system_error<S>">}}\]
    
      - If {{<api "success_failure/#unexposed-entity-outcome-v2-xxx-trait-has-exception-ptr-v" "trait::has_exception_ptr_v<S>">}} is true, then `std::rethrow_exception(error()|make_exception_ptr(error()))` \[{{<api "policies/result_exception_ptr_rethrow/" "policy::exception_ptr_rethrow<R, S, void>">}}\]
    
      - If `S` is `void`, call `std::terminate()` \[{{<api "policies/terminate/" "policy::terminate">}}\]
    
      - If `S` is none of the above, then it is undefined behaviour \[{{<api "policies/all_narrow/" "policy::all_narrow">}}\]

2.  If `.error()` called when there is no `error_type`:
    
      - If `trait::has_error_code_v<S>`, or if `trait::has_exception_ptr_v<S>`, or if `S` is `void`, do `throw bad_result_access()`
    
      - If `S` is none of the above, then it is undefined behaviour \[`policy::all_narrow`\]

#### Template parameters

  - `R` &mdash; The optional type of the successful result (use `void` to disable). Cannot be a reference, a `in_place_type_t<>`, `success<>`, `failure<>`, an array, a function or non-destructible.
  - `S` &mdash; The optional type of the failure result (use `void` to disable). Must be either `void` or `DefaultConstructible`. Cannot be a reference, a `in_place_type_t<>`, `success<>`, `failure<>`, an array, a function or non-destructible.
  - `NoValuePolicy` &mdash; Policy on how to interpret type `S` when a wide observation of a not present value occurs.

### Function `outcome_v2_xxx::result::assume_error`

<span id="standardese-outcome_v2_xxx__detail__result_error_observers-Base-EC-NoValuePolicy-__assume_error---"></span>

<pre><code class="standardese-language-cpp">(1)&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">error_type</span><span class="pun">&amp;</span>&nbsp;<span class="typ dec var fun">assume_error</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="pun">&amp;</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>

(2)&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">error_type</span><span class="pun">&amp;</span>&nbsp;<span class="typ dec var fun">assume_error</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="pun">&amp;</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>

(3)&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">error_type</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">assume_error</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="pun">&amp;&amp;</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>

(4)&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">error_type</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">assume_error</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="pun">&amp;&amp;</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

Access error without runtime checks.

*Preconditions:* The result to have a failed state, otherwise it is undefined behaviour.

*Returns:* Reference to the held `error_type` according to overload.

-----

### Function `outcome_v2_xxx::result::error`

<span id="standardese-outcome_v2_xxx__detail__result_error_observers-Base-EC-NoValuePolicy-__error---"></span>

<pre><code class="standardese-language-cpp">(1)&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">error_type</span><span class="pun">&amp;</span>&nbsp;<span class="typ dec var fun">error</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="pun">&amp;</span><span class="pun">;</span>

(2)&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">error_type</span><span class="pun">&amp;</span>&nbsp;<span class="typ dec var fun">error</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="pun">&amp;</span><span class="pun">;</span>

(3)&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">error_type</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">error</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="pun">&amp;&amp;</span><span class="pun">;</span>

(4)&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">error_type</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">error</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="pun">&amp;&amp;</span><span class="pun">;</span>
</code></pre>

Access error with runtime checks.

*Returns:* Reference to the held `error_type` according to overload.

*Requires:* The result to have a failed state, else whatever `NoValuePolicy` says ought to happen.

-----

### Conversion operator `outcome_v2_xxx::result::operator bool`

<span id="standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operatorbool--const"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">explicit</span>&nbsp;<span class="kwd">operator</span>&nbsp;<span class="kwd">bool</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

Checks if has value.

*Returns:* True if has value.

-----

### Function `outcome_v2_xxx::result::has_value`

<span id="standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__has_value--const"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span>&nbsp;<span class="typ dec var fun">has_value</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

Checks if has value.

*Returns:* True if has value.

-----

### Function `outcome_v2_xxx::result::has_error`

<span id="standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__has_error--const"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span>&nbsp;<span class="typ dec var fun">has_error</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

Checks if has error.

*Returns:* True if has error.

-----

### Function `outcome_v2_xxx::result::has_exception`

<span id="standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__has_exception--const"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span>&nbsp;<span class="typ dec var fun">has_exception</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

Checks if has exception.

*Returns:* True if has exception.

-----

### Function `outcome_v2_xxx::result::has_failure`

<span id="standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__has_failure--const"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span>&nbsp;<span class="typ dec var fun">has_failure</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

Checks if has error or exception.

*Returns:* True if has error or exception.

-----

### Function `outcome_v2_xxx::result::operator==`

<span id="standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T-U-V--result_final-T-U-V-const--const"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">V</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span>&nbsp;<span class="typ dec var fun">operator==</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="doc_result_final.md#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T-U-V--result_final-T-U-V-const--const-o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

True if equal to the other result.

*Effects:* If a valid expression to do so, calls the `operator==` operation on each of the two stored items returning true if both are true. Otherwise returns false.

*Throws:* Any exception the individual `operator==` operations might throw.

#### Parameters

  - `o` &mdash; The other result to compare to.

-----

### Function `outcome_v2_xxx::result::operator==`

<span id="standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T--success_type-T-const--const"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span>&nbsp;<span class="typ dec var fun">operator==</span><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx__success_type-T-"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>T<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="doc_result_final.md#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T--success_type-T-const--const-o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

True if equal to the success type sugar.

*Effects:* If a valid expression to do so, calls the `operator==` operation on the successful item returning true if equal. Otherwise returns false.

*Throws:* Any exception the `operator==` operation might throw.

#### Parameters

  - `o` &mdash; The success type sugar to compare to.

-----

### Function `outcome_v2_xxx::result::operator==`

<span id="standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---success_type-void-const--const"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span>&nbsp;<span class="typ dec var fun">operator==</span><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx__success_type-T-"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>void<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="doc_result_final.md#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---success_type-void-const--const-o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

True if equal to the success type sugar.

*Effects:* If a valid expression to do so, calls the `operator==` operation on the successful item returning true if equal. Otherwise returns false.

*Throws:* Any exception the `operator==` operation might throw.

#### Parameters

  - `o` &mdash; The success type sugar to compare to.

-----

### Function `outcome_v2_xxx::result::operator==`

<span id="standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T--failure_type-T-void-const--const"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span>&nbsp;<span class="typ dec var fun">operator==</span><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx__failure_type-EC-E-"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>T, void<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="doc_result_final.md#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T--failure_type-T-void-const--const-o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

True if equal to the failure type sugar.

*Effects:* If a valid expression to do so, calls the `operator==` operation on the failure item returning true if equal. Otherwise returns false.

*Throws:* Any exception the `operator==` operation might throw.

#### Parameters

  - `o` &mdash; The failure type sugar to compare to.

-----

### Function `outcome_v2_xxx::outcome::operator!=`

<span id="standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T-U-V--result_final-T-U-V-const--const"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">V</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span>&nbsp;<span class="typ dec var fun">operator!=</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="doc_result_final.md#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T-U-V--result_final-T-U-V-const--const-o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

True if not equal to the other result.

*Effects:* If a valid expression to do so, calls the `operator!=` operation on each of the two stored items, returning true if any are not equal. Otherwise returns true.

*Throws:* Any exception the individual `operator!=` operations might throw.

#### Parameters

  - `o` &mdash; The other result to compare to.

-----

### Function `outcome_v2_xxx::outcome::operator!=`

<span id="standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T--success_type-T-const--const"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span>&nbsp;<span class="typ dec var fun">operator!=</span><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx__success_type-T-"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>T<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="doc_result_final.md#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T--success_type-T-const--const-o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

True if not equal to the success type sugar.

*Effects:* If a valid expression to do so, calls the `operator!=` operation on the successful item returning true if not equal. Otherwise returns false.

*Throws:* Any exception the `operator!=` operation might throw.

#### Parameters

  - `o` &mdash; The success type sugar to compare to.

-----

### Function `outcome_v2_xxx::outcome::operator!=`

<span id="standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---success_type-void-const--const"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span>&nbsp;<span class="typ dec var fun">operator!=</span><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx__success_type-T-"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>void<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="doc_result_final.md#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---success_type-void-const--const-o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

True if not equal to the success type sugar.

*Effects:* If a valid expression to do so, calls the `operator!=` operation on the successful item returning true if not equal. Otherwise returns false.

*Throws:* Any exception the `operator!=` operation might throw.

#### Parameters

  - `o` &mdash; The success type sugar to compare to.

-----

### Function `outcome_v2_xxx::result::operator!=`

<span id="standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T--failure_type-T-void-const--const"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span>&nbsp;<span class="typ dec var fun">operator!=</span><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx__failure_type-EC-E-"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>T, void<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="doc_result_final.md#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T--failure_type-T-void-const--const-o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

True if not equal to the failure type sugar.

*Effects:* If a valid expression to do so, calls the `operator!=` operation on the failure item returning true if not equal. Otherwise returns false.

*Throws:* Any exception the `operator!=` operation might throw.

#### Parameters

  - `o` &mdash; The failure type sugar to compare to.

-----

### Type alias `outcome_v2_xxx::result::value_type`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__value_type"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">using</span>&nbsp;<span class="typ dec var fun">value_type</span>&nbsp;<span class="pun">=</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy--R"><span class="typ dec var fun">R</span></a><span class="pun">;</span>
</code></pre>

The success type.

-----

### Type alias `outcome_v2_xxx::result::error_type`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__error_type"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">using</span>&nbsp;<span class="typ dec var fun">error_type</span>&nbsp;<span class="pun">=</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy--S"><span class="typ dec var fun">S</span></a><span class="pun">;</span>
</code></pre>

The failure type.

-----

### Type alias `outcome_v2_xxx::result::value_type_if_enabled`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__value_type_if_enabled"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">using</span>&nbsp;<span class="typ dec var fun">value_type_if_enabled</span>&nbsp;<span class="pun">=</span> typename base::_value_type<span class="pun">;</span>
</code></pre>

Used to disable in place type construction when `value_type` and `error_type` are ambiguous.

-----

### Type alias `outcome_v2_xxx::result::error_type_if_enabled`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__error_type_if_enabled"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">using</span>&nbsp;<span class="typ dec var fun">error_type_if_enabled</span>&nbsp;<span class="pun">=</span> typename base::_error_type<span class="pun">;</span>
</code></pre>

Used to disable in place type construction when `value_type` and `error_type` are ambiguous.

-----

### Alias template `outcome_v2_xxx::result::rebind`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__rebind-T-U-V-"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span>&nbsp;<span class="pun">=</span> S<span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">V</span>&nbsp;<span class="pun">=</span> policy::default_policy&lt;T,U,void&gt;<span class="pun">&gt;</span>
<span class="kwd">using</span>&nbsp;<span class="typ dec var fun">rebind</span>&nbsp;<span class="pun">=</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>T, U, V<span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

Used to rebind this result to a different result type.

-----

### Struct `outcome_v2_xxx::result::predicate`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__predicate"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">struct</span>&nbsp;<span class="typ dec var fun">predicate</span>
<span class="pun">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">using</span>&nbsp;<span class="typ dec var fun">base</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span>&nbsp;<span class="kwd">T</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">enable_value_converting_constructor</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">,</span>&nbsp;<span class="kwd">result</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span>&nbsp;<span class="pun">&amp;&amp;</span>&nbsp;<span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>&nbsp;&nbsp;<span class="kwd">enable_value_converting_constructor</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span>&nbsp;<span class="kwd">T</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">enable_error_converting_constructor</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">,</span>&nbsp;<span class="kwd">result</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span>&nbsp;<span class="pun">&amp;&amp;</span>&nbsp;<span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>&nbsp;&nbsp;<span class="kwd">enable_error_converting_constructor</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span>&nbsp;<span class="kwd">ErrorCondEnum</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">enable_error_condition_converting_constructor</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">ErrorCondEnum</span><span class="pun">&gt;</span><span class="pun">,</span>&nbsp;<span class="kwd">result</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span>&nbsp;<span class="pun">&amp;&amp;</span>&nbsp;<span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>&nbsp;&nbsp;<span class="kwd">enable_error_condition_converting_constructor</span><span class="pun">&lt;</span><span class="kwd">ErrorCondEnum</span><span class="pun">&gt;</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span>&nbsp;<span class="kwd">T</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">class</span>&nbsp;<span class="kwd">U</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">class</span>&nbsp;<span class="kwd">V</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">enable_compatible_conversion</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">result</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">,</span>&nbsp;<span class="kwd">U</span><span class="pun">,</span>&nbsp;<span class="kwd">V</span><span class="pun">&gt;</span><span class="pun">,</span>&nbsp;<span class="kwd">result</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span>&nbsp;<span class="pun">&amp;&amp;</span>&nbsp;<span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>&nbsp;&nbsp;<span class="kwd">enable_compatible_conversion</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">,</span>&nbsp;<span class="kwd">U</span><span class="pun">,</span>&nbsp;<span class="kwd">V</span><span class="pun">&gt;</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span><span class="pun">...</span><span class="kwd">Args</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">enable_inplace_value_constructor</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_void</span><span class="pun">&lt;</span><span class="kwd">value_type</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span>&nbsp;<span class="pun">||</span>&nbsp;<span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_constructible</span><span class="pun">&lt;</span><span class="kwd">value_type</span><span class="pun">,</span>&nbsp;<span class="kwd">Args</span><span class="pun">...</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span><span class="pun">...</span><span class="kwd">Args</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">enable_inplace_error_constructor</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_void</span><span class="pun">&lt;</span><span class="kwd">error_type</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span>&nbsp;<span class="pun">||</span>&nbsp;<span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_constructible</span><span class="pun">&lt;</span><span class="kwd">error_type</span><span class="pun">,</span>&nbsp;<span class="kwd">Args</span><span class="pun">...</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span><span class="pun">...</span><span class="kwd">Args</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">enable_inplace_value_error_constructor</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>&nbsp;&nbsp;<span class="kwd">enable_inplace_value_error_constructor</span><span class="pun">&lt;</span><span class="kwd">Args</span><span class="pun">...</span><span class="pun">&gt;</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="pun">...</span>&nbsp;<span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">using</span>&nbsp;<span class="typ dec var fun">choose_inplace_value_error_constructor</span>&nbsp;<span class="pun">=</span> typename base::choose_inplace_value_error_constructor&lt;Args...&gt;<span class="pun">;</span>
<span class="pun">};</span>
</code></pre>

Requirement predicates for result.

### Unexposed entity `outcome_v2_xxx::result::predicate::enable_value_converting_constructor`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__predicate__enable_value_converting_constructor"></span>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span>&nbsp;<span class="kwd">T</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">enable_value_converting_constructor</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">,</span>&nbsp;<span class="kwd">result</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span>&nbsp;<span class="pun">&amp;&amp;</span>&nbsp;<span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>&nbsp;&nbsp;<span class="kwd">enable_value_converting_constructor</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

Predicate for the value converting constructor to be available.

-----

### Unexposed entity `outcome_v2_xxx::result::predicate::enable_error_converting_constructor`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__predicate__enable_error_converting_constructor"></span>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span>&nbsp;<span class="kwd">T</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">enable_error_converting_constructor</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">,</span>&nbsp;<span class="kwd">result</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span>&nbsp;<span class="pun">&amp;&amp;</span>&nbsp;<span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>&nbsp;&nbsp;<span class="kwd">enable_error_converting_constructor</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

Predicate for the error converting constructor to be available.

-----

### Unexposed entity `outcome_v2_xxx::result::predicate::enable_error_condition_converting_constructor`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__predicate__enable_error_condition_converting_constructor"></span>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span>&nbsp;<span class="kwd">ErrorCondEnum</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">enable_error_condition_converting_constructor</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">ErrorCondEnum</span><span class="pun">&gt;</span><span class="pun">,</span>&nbsp;<span class="kwd">result</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span>&nbsp;<span class="pun">&amp;&amp;</span>&nbsp;<span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>&nbsp;&nbsp;<span class="kwd">enable_error_condition_converting_constructor</span><span class="pun">&lt;</span><span class="kwd">ErrorCondEnum</span><span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

Predicate for the error condition converting constructor to be available.

-----

### Unexposed entity `outcome_v2_xxx::result::predicate::enable_compatible_conversion`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__predicate__enable_compatible_conversion"></span>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span>&nbsp;<span class="kwd">T</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">class</span>&nbsp;<span class="kwd">U</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">class</span>&nbsp;<span class="kwd">V</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">enable_compatible_conversion</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">result</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">,</span>&nbsp;<span class="kwd">U</span><span class="pun">,</span>&nbsp;<span class="kwd">V</span><span class="pun">&gt;</span><span class="pun">,</span>&nbsp;<span class="kwd">result</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span>&nbsp;<span class="pun">&amp;&amp;</span>&nbsp;<span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>&nbsp;&nbsp;<span class="kwd">enable_compatible_conversion</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">,</span>&nbsp;<span class="kwd">U</span><span class="pun">,</span>&nbsp;<span class="kwd">V</span><span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

Predicate for the converting copy constructor from a compatible input to be available.

-----

### Unexposed entity `outcome_v2_xxx::result::predicate::enable_inplace_value_constructor`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__predicate__enable_inplace_value_constructor"></span>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span><span class="pun">...</span><span class="kwd">Args</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">enable_inplace_value_constructor</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_void</span><span class="pun">&lt;</span><span class="kwd">value_type</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span>&nbsp;<span class="pun">||</span>&nbsp;<span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_constructible</span><span class="pun">&lt;</span><span class="kwd">value_type</span><span class="pun">,</span>&nbsp;<span class="kwd">Args</span><span class="pun">...</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>
</code></pre>

Predicate for the inplace construction of value to be available.

-----

### Unexposed entity `outcome_v2_xxx::result::predicate::enable_inplace_error_constructor`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__predicate__enable_inplace_error_constructor"></span>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span><span class="pun">...</span><span class="kwd">Args</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">enable_inplace_error_constructor</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_void</span><span class="pun">&lt;</span><span class="kwd">error_type</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span>&nbsp;<span class="pun">||</span>&nbsp;<span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_constructible</span><span class="pun">&lt;</span><span class="kwd">error_type</span><span class="pun">,</span>&nbsp;<span class="kwd">Args</span><span class="pun">...</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>
</code></pre>

Predicate for the inplace construction of error to be available.

-----

-----

### Constructor `outcome_v2_xxx::result::result`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result--"></span>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">result</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">delete</span><span class="pun">;</span>
</code></pre>

Default construction is not permitted.

-----

### Constructor `outcome_v2_xxx::result::result`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-result-R-S-NoValuePolicy----"></span>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">result</span><span class="pun">(</span>result&lt;R, S, NoValuePolicy&gt;<span class="pun">&amp;&amp;</span><span class="pun">)</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">default</span><span class="pun">;</span>
</code></pre>

Move construction available if `value_type` and `error_type` implement it.

-----

### Constructor `outcome_v2_xxx::result::result`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-constresult-R-S-NoValuePolicy---"></span>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">result</span><span class="pun">(</span>const result&lt;R, S, NoValuePolicy&gt;<span class="pun">&amp;</span><span class="pun">)</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">default</span><span class="pun">;</span>
</code></pre>

Copy construction available if `value_type` and `error_type` implement it.

-----

### Function `outcome_v2_xxx::result::operator=`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__operator--result-R-S-NoValuePolicy----"></span>

<pre><code class="standardese-language-cpp">result&lt;R, S, NoValuePolicy&gt;<span class="pun">&amp;</span>&nbsp;<span class="typ dec var fun">operator=</span><span class="pun">(</span>result&lt;R, S, NoValuePolicy&gt;<span class="pun">&amp;&amp;</span><span class="pun">)</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">default</span><span class="pun">;</span>
</code></pre>

Move assignment available if `value_type` and `error_type` implement it.

-----

### Function `outcome_v2_xxx::result::operator=`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__operator--constresult-R-S-NoValuePolicy---"></span>

<pre><code class="standardese-language-cpp">result&lt;R, S, NoValuePolicy&gt;<span class="pun">&amp;</span>&nbsp;<span class="typ dec var fun">operator=</span><span class="pun">(</span>const result&lt;R, S, NoValuePolicy&gt;<span class="pun">&amp;</span><span class="pun">)</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">default</span><span class="pun">;</span>
</code></pre>

Copy assignment available if `value_type` and `error_type` implement it.

-----

### Constructor `outcome_v2_xxx::result::result`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T---T---outcome_v2_xxx__result__value_converting_constructor_tag-"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">result</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T---T---outcome_v2_xxx__result__value_converting_constructor_tag--t"><span class="typ dec var fun">t</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Implicit converting constructor to a successful result.

*Effects:* Initialises the result with a `value_type`.

*Requires:* Type T is implicitly constructible to `value_type`, is not implicitly constructible to `error_type`, and is not `result<R, S>` and not `in_place_type<>`.

*Throws:* Any exception the construction of `value_type(T)` might throw.

#### Parameters

  - `t` &mdash; The value from which to initialise the `value_type`.

-----

### Constructor `outcome_v2_xxx::result::result`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T---T---outcome_v2_xxx__result__error_converting_constructor_tag-"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">result</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T---T---outcome_v2_xxx__result__error_converting_constructor_tag--t"><span class="typ dec var fun">t</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Implicit converting constructor to a failure result.

*Effects:* Initialises the result with a `error_type`.

*Requires:* Type T is implicitly constructible to `error_type`, is not implicitly constructible to `value_type`, and is not `result<R, S>` and not `in_place_type<>`.

*Throws:* Any exception the construction of `error_type(T)` might throw.

#### Parameters

  - `t` &mdash; The value from which to initialise the `error_type`.

-----

### Constructor `outcome_v2_xxx::result::result`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-ErrorCondEnum----ErrorCondEnum---outcome_v2_xxx__result__error_condition_converting_constructor_tag-"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">ErrorCondEnum</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">result</span><span class="pun">(</span><span class="typ dec var fun">ErrorCondEnum</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-ErrorCondEnum----ErrorCondEnum---outcome_v2_xxx__result__error_condition_converting_constructor_tag--t"><span class="typ dec var fun">t</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Implicit special error condition converting constructor to a failure result.

*Effects:* Initialises the result with a `error_type` constructed via `make_error_code(t)`.

*Requires:* `std::is_error_condition_enum<ErrorCondEnum>` must be true, `ErrorCondEnum` is not implicitly constructible to `value_type` nor `error_type`, and is not `result<R, S>` and not `in_place_type<>`; Finally, the expression `error_type(make_error_code(ErrorCondEnum()))` must be valid.

*Throws:* Any exception the construction of `error_type(make_error_code(t))` might throw.

#### Parameters

  - `t` &mdash; The error condition from which to initialise the `error_type`.

-----

### Constructor `outcome_v2_xxx::result::result`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T----T---outcome_v2_xxx__result__explicit_valueorerror_converting_constructor_tag-"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">result</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T----T---outcome_v2_xxx__result__explicit_valueorerror_converting_constructor_tag--o"><span class="typ dec var fun">o</span></a><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Explicit converting constructor from a compatible `ValueOrError` type.

*Effects:* Initialises the result with the contents of the compatible input.

*Requires:* That `convert::value_or_error<result, std::decay_t<T>>{}(std::forward<T>(o))` be available. The default implementation will consume `T`’s matching the `ValueOrError` concept type. `ValueOrError` concept matches any type with a `value_type`, an `error_type`, a `.value()`, an `.error()` and a `.has_value()`.

#### Parameters

  - `o` &mdash; The input for which a `convert::value_or_error<result, std::decay_t<T>>{}(std::forward<T>(o))` is available.

-----

### Constructor `outcome_v2_xxx::result::result`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T-U-V---result-T-U-V-const--"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">V</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">result</span><span class="pun">(</span><a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>T, U, V<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T-U-V---result-T-U-V-const---o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Explicit converting copy constructor from a compatible result type.

*Effects:* Initialises the result with a copy of the compatible result.

*Requires:* Both result’s `value_type` and `error_type` need to be constructible, or the source can be `void`.

*Throws:* Any exception the construction of `value_type(T)` and `error_type(U)` might throw.

#### Parameters

  - `o` &mdash; The compatible result.

-----

### Constructor `outcome_v2_xxx::result::result`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T-U-V---result-T-U-V----"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">V</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">result</span><span class="pun">(</span><a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>T, U, V<span class="pun">&gt;</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T-U-V---result-T-U-V-----o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Explicit converting move constructor from a compatible result type.

*Effects:* Initialises the result with a move of the compatible result.

*Requires:* Both result’s `value_type` and `error_type` need to be constructible, or the source can be `void`.

*Throws:* Any exception the construction of `value_type(T)` and `error_type(U)` might throw.

#### Parameters

  - `o` &mdash; The compatible result.

-----

### Constructor `outcome_v2_xxx::result::result`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-Args---in_place_type_t-outcome_v2_xxx__result__value_type_if_enabled--Args------"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="pun">...</span>&nbsp;<span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">result</span><span class="pun">(</span><a href="doc_value_storage.md#standardese-outcome_v2_xxx__in_place_type_t-T-"><span class="typ dec var fun">in_place_type_t</span></a><span class="pun">&lt;</span>outcome_v2_xxx::result::value_type_if_enabled<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-Args---in_place_type_t-outcome_v2_xxx__result__value_type_if_enabled--Args-------_"><span class="typ dec var fun">_</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-Args---in_place_type_t-outcome_v2_xxx__result__value_type_if_enabled--Args-------args"><span class="typ dec var fun">args</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Explicit inplace constructor to a successful result.

*Effects:* Initialises the result with a `value_type`.

*Requires:* `value_type` is void or `Args...` are constructible to `value_type`.

*Throws:* Any exception the construction of `value_type(Args...)` might throw.

#### Parameters

  - `_` &mdash; Tag type to indicate we are doing in place construction of `value_type`.
  - `args` &mdash; Arguments with which to in place construct.

-----

### Constructor `outcome_v2_xxx::result::result`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-U-Args---in_place_type_t-outcome_v2_xxx__result__value_type_if_enabled--std__initializer_list-U--Args------"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="pun">...</span>&nbsp;<span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">result</span><span class="pun">(</span><a href="doc_value_storage.md#standardese-outcome_v2_xxx__in_place_type_t-T-"><span class="typ dec var fun">in_place_type_t</span></a><span class="pun">&lt;</span>outcome_v2_xxx::result::value_type_if_enabled<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-U-Args---in_place_type_t-outcome_v2_xxx__result__value_type_if_enabled--std__initializer_list-U--Args-------_"><span class="typ dec var fun">_</span></a><span class="pun">,</span>&nbsp;<span class="typ dec var fun">std::initializer_list</span><span class="pun">&lt;</span>U<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-U-Args---in_place_type_t-outcome_v2_xxx__result__value_type_if_enabled--std__initializer_list-U--Args-------il"><span class="typ dec var fun">il</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-U-Args---in_place_type_t-outcome_v2_xxx__result__value_type_if_enabled--std__initializer_list-U--Args-------args"><span class="typ dec var fun">args</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Explicit inplace constructor to a successful result.

*Effects:* Initialises the result with a `value_type`.

*Requires:* The initializer list + `Args...` are constructible to `value_type`.

*Throws:* Any exception the construction of `value_type(il, Args...)` might throw.

#### Parameters

  - `_` &mdash; Tag type to indicate we are doing in place construction of `value_type`.
  - `il` &mdash; An initializer list with which to in place construct.
  - `args` &mdash; Arguments with which to in place construct.

-----

### Constructor `outcome_v2_xxx::result::result`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-Args---in_place_type_t-outcome_v2_xxx__result__error_type_if_enabled--Args------"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="pun">...</span>&nbsp;<span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">result</span><span class="pun">(</span><a href="doc_value_storage.md#standardese-outcome_v2_xxx__in_place_type_t-T-"><span class="typ dec var fun">in_place_type_t</span></a><span class="pun">&lt;</span>outcome_v2_xxx::result::error_type_if_enabled<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-Args---in_place_type_t-outcome_v2_xxx__result__error_type_if_enabled--Args-------_"><span class="typ dec var fun">_</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-Args---in_place_type_t-outcome_v2_xxx__result__error_type_if_enabled--Args-------args"><span class="typ dec var fun">args</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Explicit inplace constructor to a failure result.

*Effects:* Initialises the result with a `error_type`.

*Requires:* `error_type` is void or `Args...` are constructible to `error_type`.

*Throws:* Any exception the construction of `error_type(Args...)` might throw.

#### Parameters

  - `_` &mdash; Tag type to indicate we are doing in place construction of `error_type`.
  - `args` &mdash; Arguments with which to in place construct.

-----

### Constructor `outcome_v2_xxx::result::result`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-U-Args---in_place_type_t-outcome_v2_xxx__result__error_type_if_enabled--std__initializer_list-U--Args------"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="pun">...</span>&nbsp;<span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">result</span><span class="pun">(</span><a href="doc_value_storage.md#standardese-outcome_v2_xxx__in_place_type_t-T-"><span class="typ dec var fun">in_place_type_t</span></a><span class="pun">&lt;</span>outcome_v2_xxx::result::error_type_if_enabled<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-U-Args---in_place_type_t-outcome_v2_xxx__result__error_type_if_enabled--std__initializer_list-U--Args-------_"><span class="typ dec var fun">_</span></a><span class="pun">,</span>&nbsp;<span class="typ dec var fun">std::initializer_list</span><span class="pun">&lt;</span>U<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-U-Args---in_place_type_t-outcome_v2_xxx__result__error_type_if_enabled--std__initializer_list-U--Args-------il"><span class="typ dec var fun">il</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-U-Args---in_place_type_t-outcome_v2_xxx__result__error_type_if_enabled--std__initializer_list-U--Args-------args"><span class="typ dec var fun">args</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Explicit inplace constructor to a failure result.

*Effects:* Initialises the result with a `error_type`.

*Requires:* The initializer list + `Args...` are constructible to `error_type`.

*Throws:* Any exception the construction of `error_type(il, Args...)` might throw.

#### Parameters

  - `_` &mdash; Tag type to indicate we are doing in place construction of `error_type`.
  - `il` &mdash; An initializer list with which to in place construct.
  - `args` &mdash; Arguments with which to in place construct.

-----

### Constructor `outcome_v2_xxx::result::result`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-A1-A2-Args---A1---A2---Args------"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">A1</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">A2</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="pun">...</span>&nbsp;<span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">result</span><span class="pun">(</span><span class="typ dec var fun">A1</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">a1</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">A2</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">a2</span><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-A1-A2-Args---A1---A2---Args-------args"><span class="typ dec var fun">args</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Implicit inplace constructor to successful or failure result.

*Effects:* Calls the appropriate `in_place_type_t<...>` constructor depending on constructibility of args.

*Requires:* That the args can construct exactly one of `value_type` or `error_type`.

*Throws:* Any exception the `in_place_type_t<...>` constructor might throw.

#### Parameters

  - `args` &mdash; Arguments with which to in place construct.

-----

### Constructor `outcome_v2_xxx::result::result`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-success_type-void-const--"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">result</span><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx__success_type-T-"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>void<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-success_type-void-const---o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Implicit tagged constructor of a successful result.

*Effects:* Initialises the result with a default constructed success type.

*Requires:* `value_type` to be default constructible, or `void`.

*Throws:* Any exception the construction of `value_type()` might throw.

#### Parameters

  - `o` &mdash; The compatible success type sugar.

-----

### Constructor `outcome_v2_xxx::result::result`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T---success_type-T-const--"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">result</span><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx__success_type-T-"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>T<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T---success_type-T-const---o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Implicit tagged constructor of a successful result.

*Effects:* Initialises the result with a copy of the value in the type sugar.

*Requires:* Both result and success’ `value_type` need to be constructible, or the source can be `void`.

*Throws:* Any exception the construction of `value_type(T)` might throw.

#### Parameters

  - `o` &mdash; The compatible success type sugar.

-----

### Constructor `outcome_v2_xxx::result::result`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T---success_type-T----"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">result</span><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx__success_type-T-"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>T<span class="pun">&gt;</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T---success_type-T-----o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Implicit tagged constructor of a successful result.

*Effects:* Initialises the result with a move of the value in the type sugar.

*Requires:* Both result and success’ `value_type` need to be constructible. The source cannot be `void`.

*Throws:* Any exception the construction of `value_type(T)` might throw.

#### Parameters

  - `o` &mdash; The compatible success type sugar.

-----

### Constructor `outcome_v2_xxx::result::result`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T---failure_type-T-const--"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">result</span><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx__failure_type-EC-E-"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>T<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T---failure_type-T-const---o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Implicit tagged constructor of a failure result.

*Effects:* Initialises the result with a copy of the error in the type sugar.

*Requires:* Both result and failure’s `error_type` need to be constructible, or the source can be `void`.

*Throws:* Any exception the construction of `error_type(T)` might throw.

#### Parameters

  - `o` &mdash; The compatible failure type sugar.

-----

### Constructor `outcome_v2_xxx::result::result`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T---failure_type-T----"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">result</span><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx__failure_type-EC-E-"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>T<span class="pun">&gt;</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__result-T---failure_type-T-----o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Implicit tagged constructor of a failure result.

*Effects:* Initialises the result with a move of the error in the type sugar.

*Requires:* Both result and failure’s `error_type` need to be constructible, or the source can be `void`.

*Throws:* Any exception the construction of `error_type(T)` might throw.

#### Parameters

  - `o` &mdash; The compatible failure type sugar.

-----

### Function `outcome_v2_xxx::result::swap`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__swap-result-R-S-NoValuePolicy---"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">void</span>&nbsp;<span class="typ dec var fun">swap</span><span class="pun">(</span>result&lt;R, S, NoValuePolicy&gt;<span class="pun">&amp;</span>&nbsp;<span class="typ dec var fun">o</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Swaps this result with another result

*Effects:* Any `R` and/or `S` is swapped along with the metadata tracking them.

-----

### Function `outcome_v2_xxx::result::as_failure`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__as_failure--const-"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">auto</span>&nbsp;<span class="typ dec var fun">as_failure</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="pun">&amp;</span><span class="pun">;</span>
</code></pre>

Returns this result as a `failure_type` with any errored state copied.

*Requires:* This result to have a failed state, else whatever `assume_error()` would do.

-----

### Function `outcome_v2_xxx::result::as_failure`

<span id="standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-__as_failure----"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">auto</span>&nbsp;<span class="typ dec var fun">as_failure</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="pun">&amp;&amp;</span><span class="pun">;</span>
</code></pre>

Returns this result as a `failure_type` with any errored state moved.

*Requires:* This result to have a failed state, else whatever `assume_error()` would do.

-----

-----

### Function `outcome_v2_xxx::swap`

<span id="standardese-outcome_v2_xxx__swap-R-S-P--result-R-S-P---result-R-S-P---"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">R</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">S</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">P</span><span class="pun">&gt;</span>
<span class="kwd">void</span>&nbsp;<span class="typ dec var fun">swap</span><span class="pun">(</span><a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>R, S, P<span class="pun">&gt;</span><span class="pun">&amp;</span>&nbsp;<span class="typ dec var fun">a</span><span class="pun">,</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>R, S, P<span class="pun">&gt;</span><span class="pun">&amp;</span>&nbsp;<span class="typ dec var fun">b</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Specialise swap for result.

*Effects:* Calls `a.swap(b)`.

-----

### Alias template `outcome_v2_xxx::unchecked`

<span id="standardese-outcome_v2_xxx__unchecked-R-S-"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">R</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">S</span>&nbsp;<span class="pun">=</span> std::error_code<span class="pun">&gt;</span>
<span class="kwd">using</span>&nbsp;<span class="typ dec var fun">unchecked</span>&nbsp;<span class="pun">=</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>R, S, policy::all_narrow<span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

An “unchecked” edition of `result<T, E>` which does no special handling of specific `E` types at all.

Attempting to access `T` when there is an `E` results in nothing happening at all, it is treated with a narrow contract (i.e. undefined behaviour).

-----

### Alias template `outcome_v2_xxx::checked`

<span id="standardese-outcome_v2_xxx__checked-R-S-"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">R</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">S</span>&nbsp;<span class="pun">=</span> std::error_code<span class="pun">&gt;</span>
<span class="kwd">using</span>&nbsp;<span class="typ dec var fun">checked</span>&nbsp;<span class="pun">=</span> <a href="#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>R, S, policy::throw_bad_result_access&lt;S&gt;<span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

A “checked” edition of `result<T, E>` which resembles fairly closely a `std::expected<T, E>`.

Attempting to access `T` when there is an `E` results in `bad_result_access<E>` being thrown. Nothing else.

Note that this approximates the proposed `expected<T, E>` up for standardisation, see the FAQ for more detail.

-----
