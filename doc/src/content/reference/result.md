+++
title = "result<R, S>"
weight = 20
+++
# Header file `result.hpp`

<a id="standardese-result.hpp"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">namespace</span> <span class="typ dec var fun">outcome_v2_xxx</span>
<span class="pun">{</span>
    <span class="kwd">namespace</span> <a href="standardese_entities.md#standardese-outcome_v2_xxx::policy"><span class="typ dec var fun">policy</span></a>
    <span class="pun">{</span>
        <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">EC</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">E</span><span class="pun">&gt;</span>
        <span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx::policy::default_policy%3CT,EC,E%3E"><span class="typ dec var fun">default_policy</span></a> <span class="pun">=</span> <span class="typ dec var fun">std::conditional_t</span><span class="pun">&lt;</span>std::is_void&lt;EC&gt;::value &amp;&amp; std::is_void&lt;E&gt;::value, terminate, std::conditional_t&lt;trait::has_error_code_v&lt;EC&gt;, error_code_throw_as_system_error&lt;T, EC, E&gt;, std::conditional_t&lt;trait::has_exception_ptr_v&lt;EC&gt; || trait::has_exception_ptr_v&lt;E&gt;, exception_ptr_rethrow&lt;T, EC, E&gt;, all_narrow&gt; &gt;<span class="pun">&gt;</span><span class="pun">;</span>
    <span class="pun">}</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
    <span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx::is_result%3CT%3E"><span class="typ dec var fun">is_result</span></a> <span class="pun">=</span> <span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">;</span>

    <span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span> <span class="kwd">T</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">is_result_v</span> <span class="pun">=</span> <span class="kwd">detail</span><span class="pun">::</span><span class="kwd">is_result</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>

    <span class="kwd">namespace</span> <a href="standardese_entities.md#standardese-outcome_v2_xxx::hooks"><span class="typ dec var fun">hooks</span></a>
    <span class="pun">{</span>
        <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">&gt;</span>
        <span class="kwd">constexpr</span> <span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx::hooks::hook_result_construction%3CT,U%3E(T*,U&amp;&amp;)"><span class="typ dec var fun">hook_result_construction</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">*</span><span class="pun">,</span> <span class="typ dec var fun">U</span><span class="pun">&amp;&amp;</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">;</span>

        <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">&gt;</span>
        <span class="kwd">constexpr</span> <span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx::hooks::hook_result_copy_construction%3CT,U%3E(T*,U&amp;&amp;)"><span class="typ dec var fun">hook_result_copy_construction</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">*</span><span class="pun">,</span> <span class="typ dec var fun">U</span><span class="pun">&amp;&amp;</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">;</span>

        <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">&gt;</span>
        <span class="kwd">constexpr</span> <span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx::hooks::hook_result_move_construction%3CT,U%3E(T*,U&amp;&amp;)"><span class="typ dec var fun">hook_result_move_construction</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">*</span><span class="pun">,</span> <span class="typ dec var fun">U</span><span class="pun">&amp;&amp;</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">;</span>

        <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="pun">...</span> <span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
        <span class="kwd">constexpr</span> <span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx::hooks::hook_result_in_place_construction%3CT,U,Args%3E(T*,in_place_type_t%3CU%3E,Args&amp;&amp;...)"><span class="typ dec var fun">hook_result_in_place_construction</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">*</span><span class="pun">,</span> <a href="doc_value_storage.md#standardese-outcome_v2_xxx::in_place_type_t%3CT%3E"><span class="typ dec var fun">in_place_type_t</span></a><span class="pun">&lt;</span>U<span class="pun">&gt;</span><span class="pun">,</span> Args &amp;&amp;...<span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">;</span>

        <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">NoValuePolicy</span><span class="pun">&gt;</span>
        <span class="kwd">constexpr</span> <span class="typ dec var fun">uint16_t</span> <a href="#standardese-outcome_v2_xxx::hooks::spare_storage%3CR,S,NoValuePolicy%3E(detail::result_final%3CR,S,NoValuePolicy%3Econst*)"><span class="typ dec var fun">spare_storage</span></a><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span> <span class="kwd">const</span><span class="pun">*</span> <span class="typ dec var fun">r</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">;</span>

        <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">NoValuePolicy</span><span class="pun">&gt;</span>
        <span class="kwd">constexpr</span> <span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx::hooks::set_spare_storage%3CR,S,NoValuePolicy%3E(detail::result_final%3CR,S,NoValuePolicy%3E*,uint16_t)"><span class="typ dec var fun">set_spare_storage</span></a><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">*</span> <span class="typ dec var fun">r</span><span class="pun">,</span> <span class="typ dec var fun">uint16_t</span> <span class="typ dec var fun">v</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">;</span>
    <span class="pun">}</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E.R"><span class="typ dec var fun">R</span></a><span class="pun">,</span> <span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E.S"><span class="typ dec var fun">S</span></a><span class="pun">,</span> <span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E.NoValuePolicy"><span class="typ dec var fun">NoValuePolicy</span></a><span class="pun">&gt;</span>
    <span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E"><span class="typ dec var fun">result</span></a><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">&gt;</span>
    <span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx::swap%3CR,S,P%3E(result%3CR,S,P%3E&amp;,result%3CR,S,P%3E&amp;)"><span class="typ dec var fun">swap</span></a><span class="pun">(</span><a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>R, S, P<span class="pun">&gt;</span><span class="pun">&amp;</span> <span class="typ dec var fun">a</span><span class="pun">,</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>R, S, P<span class="pun">&gt;</span><span class="pun">&amp;</span> <span class="typ dec var fun">b</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">is_result_v</span> <span class="pun">=</span> <span class="kwd">detail</span><span class="pun">::</span><span class="kwd">is_result</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>

    <span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">is_result_v</span> <span class="pun">=</span> <span class="kwd">detail</span><span class="pun">::</span><span class="kwd">is_result</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span> <span class="pun">=</span> std::error_code<span class="pun">&gt;</span>
    <span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx::unchecked%3CR,S%3E"><span class="typ dec var fun">unchecked</span></a> <span class="pun">=</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>R, S, policy::all_narrow<span class="pun">&gt;</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span> <span class="pun">=</span> std::error_code<span class="pun">&gt;</span>
    <span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx::checked%3CR,S%3E"><span class="typ dec var fun">checked</span></a> <span class="pun">=</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>R, S, policy::throw_bad_result_access&lt;S&gt;<span class="pun">&gt;</span><span class="pun">;</span>
<span class="pun">}</span>
</code></pre>

<a id="standardese-outcome_v2_xxx"></a>

<a id="standardese-outcome_v2_xxx::policy"></a>

### Alias template `outcome_v2_xxx::policy::default_policy`

<a id="standardese-outcome_v2_xxx::policy::default_policy&lt;T,EC,E&gt;"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">EC</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">E</span><span class="pun">&gt;</span>
<span class="kwd">using</span> <span class="typ dec var fun">default_policy</span> <span class="pun">=</span> <span class="typ dec var fun">std::conditional_t</span><span class="pun">&lt;</span>std::is_void&lt;EC&gt;::value &amp;&amp; std::is_void&lt;E&gt;::value, terminate, std::conditional_t&lt;trait::has_error_code_v&lt;EC&gt;, error_code_throw_as_system_error&lt;T, EC, E&gt;, std::conditional_t&lt;trait::has_exception_ptr_v&lt;EC&gt; || trait::has_exception_ptr_v&lt;E&gt;, exception_ptr_rethrow&lt;T, EC, E&gt;, all_narrow&gt; &gt;<span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

Default policy selector.

-----

### Alias template `outcome_v2_xxx::is_result`

<a id="standardese-outcome_v2_xxx::is_result&lt;T&gt;"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">using</span> <span class="typ dec var fun">is_result</span> <span class="pun">=</span> <span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">;</span>
</code></pre>

True if a result

-----

### Unexposed entity `outcome_v2_xxx::is_result_v`

<a id="standardese-outcome_v2_xxx::is_result_v"></a>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span> <span class="kwd">T</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">is_result_v</span> <span class="pun">=</span> <span class="kwd">detail</span><span class="pun">::</span><span class="kwd">is_result</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>
</code></pre>

True if a result

-----

<a id="standardese-outcome_v2_xxx::hooks"></a>

### Function `outcome_v2_xxx::hooks::hook_result_construction`

<a id="standardese-outcome_v2_xxx::hooks::hook_result_construction&lt;T,U&gt;(T*,U&amp;&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="kwd">void</span> <span class="typ dec var fun">hook_result_construction</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">*</span><span class="pun">,</span> <span class="typ dec var fun">U</span><span class="pun">&amp;&amp;</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

The default instantiation hook implementation called when a `result` is first created by conversion from one of its possible types. Does nothing.

WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should\!

#### Parameters

  - `  ` &mdash; Some `result<...>` being constructed.

-----

### Function `outcome_v2_xxx::hooks::hook_result_copy_construction`

<a id="standardese-outcome_v2_xxx::hooks::hook_result_copy_construction&lt;T,U&gt;(T*,U&amp;&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="kwd">void</span> <span class="typ dec var fun">hook_result_copy_construction</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">*</span><span class="pun">,</span> <span class="typ dec var fun">U</span><span class="pun">&amp;&amp;</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

The default instantiation hook implementation called when a `result` is created by copying from another `result`. Does nothing.

WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should\!

#### Parameters

  - `  ` &mdash; Some `result<...>` being constructed.

-----

### Function `outcome_v2_xxx::hooks::hook_result_move_construction`

<a id="standardese-outcome_v2_xxx::hooks::hook_result_move_construction&lt;T,U&gt;(T*,U&amp;&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="kwd">void</span> <span class="typ dec var fun">hook_result_move_construction</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">*</span><span class="pun">,</span> <span class="typ dec var fun">U</span><span class="pun">&amp;&amp;</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

The default instantiation hook implementation called when a `result` is created by moving from another `result`. Does nothing.

WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should\!

#### Parameters

  - `  ` &mdash; Some `result<...>` being constructed.

-----

### Function `outcome_v2_xxx::hooks::hook_result_in_place_construction`

<a id="standardese-outcome_v2_xxx::hooks::hook_result_in_place_construction&lt;T,U,Args&gt;(T*,in_place_type_t&lt;U&gt;,Args&amp;&amp;...)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="pun">...</span> <span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="kwd">void</span> <span class="typ dec var fun">hook_result_in_place_construction</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">*</span><span class="pun">,</span> <a href="doc_value_storage.md#standardese-outcome_v2_xxx::in_place_type_t%3CT%3E"><span class="typ dec var fun">in_place_type_t</span></a><span class="pun">&lt;</span>U<span class="pun">&gt;</span><span class="pun">,</span> Args &amp;&amp;...<span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

The default instantiation hook implementation called when a `result` is created by in place construction. Does nothing.

WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should\!

#### Parameters

  - `  ` &mdash; Some `result<...>` being constructed.
  - `  ` &mdash; The type of in place construction occurring.

-----

### Function `outcome_v2_xxx::hooks::spare_storage`

<a id="standardese-outcome_v2_xxx::hooks::spare_storage&lt;R,S,NoValuePolicy&gt;(detail::result_final&lt;R,S,NoValuePolicy&gt;const*)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">NoValuePolicy</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">uint16_t</span> <span class="typ dec var fun">spare_storage</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span> <span class="kwd">const</span><span class="pun">*</span> <span class="typ dec var fun">r</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

Retrieves the 16 bits of spare storage in result/outcome.

-----

### Function `outcome_v2_xxx::hooks::set_spare_storage`

<a id="standardese-outcome_v2_xxx::hooks::set_spare_storage&lt;R,S,NoValuePolicy&gt;(detail::result_final&lt;R,S,NoValuePolicy&gt;*,uint16_t)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">NoValuePolicy</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="kwd">void</span> <span class="typ dec var fun">set_spare_storage</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">*</span> <span class="typ dec var fun">r</span><span class="pun">,</span> <span class="typ dec var fun">uint16_t</span> <span class="typ dec var fun">v</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

Sets the 16 bits of spare storage in result/outcome.

-----

### Class `outcome_v2_xxx::result`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E.R"><span class="typ dec var fun">R</span></a><span class="pun">,</span> <span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E.S"><span class="typ dec var fun">S</span></a><span class="pun">,</span> <span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E.NoValuePolicy"><span class="typ dec var fun">NoValuePolicy</span></a><span class="pun">&gt;</span>
<span class="kwd">class</span> <span class="typ dec var fun">result</span>
<span class="pun">{</span>
<span class="kwd">public</span><span class="pun">:</span>
    &#x2F;&#x2F;=== Member types ===&#x2F;&#x2F;
    <span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::value_type"><span class="typ dec var fun">value_type</span></a> <span class="pun">=</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E.R"><span class="typ dec var fun">R</span></a><span class="pun">;</span>

    <span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::error_type"><span class="typ dec var fun">error_type</span></a> <span class="pun">=</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E.S"><span class="typ dec var fun">S</span></a><span class="pun">;</span>

    <span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::value_type_if_enabled"><span class="typ dec var fun">value_type_if_enabled</span></a> <span class="pun">=</span> typename base::_value_type<span class="pun">;</span>

    <span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::error_type_if_enabled"><span class="typ dec var fun">error_type_if_enabled</span></a> <span class="pun">=</span> typename base::_error_type<span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span> <span class="pun">=</span> S<span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">V</span> <span class="pun">=</span> policy::default_policy&lt;T,U,void&gt;<span class="pun">&gt;</span>
    <span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::rebind%3CT,U,V%3E"><span class="typ dec var fun">rebind</span></a> <span class="pun">=</span> <span class="typ dec var fun">result</span><span class="pun">&lt;</span>T, U, V<span class="pun">&gt;</span><span class="pun">;</span>

<span class="kwd">protected</span><span class="pun">:</span>
    <span class="kwd">struct</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::predicate"><span class="typ dec var fun">predicate</span></a><span class="pun">;</span>

<span class="kwd">public</span><span class="pun">:</span>
    &#x2F;&#x2F;=== Default, copy&#x2F;move constructors and assignment ===&#x2F;&#x2F;
    <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result()"><span class="typ dec var fun">result</span></a><span class="pun">(</span><span class="pun">)</span> <span class="pun">=</span> <span class="kwd">delete</span><span class="pun">;</span>

    <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result(result%3CR,S,NoValuePolicy%3E&amp;&amp;)"><span class="typ dec var fun">result</span></a><span class="pun">(</span>result&lt;R, S, NoValuePolicy&gt;<span class="pun">&amp;&amp;</span><span class="pun">)</span> <span class="pun">=</span> <span class="kwd">default</span><span class="pun">;</span>

    <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result(constresult%3CR,S,NoValuePolicy%3E&amp;)"><span class="typ dec var fun">result</span></a><span class="pun">(</span>const result&lt;R, S, NoValuePolicy&gt;<span class="pun">&amp;</span><span class="pun">)</span> <span class="pun">=</span> <span class="kwd">default</span><span class="pun">;</span>

    result&lt;R, S, NoValuePolicy&gt;<span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::operator=(result%3CR,S,NoValuePolicy%3E&amp;&amp;)"><span class="typ dec var fun">operator=</span></a><span class="pun">(</span>result&lt;R, S, NoValuePolicy&gt;<span class="pun">&amp;&amp;</span><span class="pun">)</span> <span class="pun">=</span> <span class="kwd">default</span><span class="pun">;</span>

    result&lt;R, S, NoValuePolicy&gt;<span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::operator=(constresult%3CR,S,NoValuePolicy%3E&amp;)"><span class="typ dec var fun">operator=</span></a><span class="pun">(</span>const result&lt;R, S, NoValuePolicy&gt;<span class="pun">&amp;</span><span class="pun">)</span> <span class="pun">=</span> <span class="kwd">default</span><span class="pun">;</span>

    <span class="typ dec var fun">~result</span><span class="pun">(</span><span class="pun">)</span> <span class="pun">=</span> <span class="kwd">default</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CT,%3E(T&amp;&amp;,outcome_v2_xxx::result::value_converting_constructor_tag)"><span class="typ dec var fun">result</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CT,%3E(T&amp;&amp;,outcome_v2_xxx::result::value_converting_constructor_tag).t"><span class="typ dec var fun">t</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CT,%3E(T&amp;&amp;,outcome_v2_xxx::result::error_converting_constructor_tag)"><span class="typ dec var fun">result</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CT,%3E(T&amp;&amp;,outcome_v2_xxx::result::error_converting_constructor_tag).t"><span class="typ dec var fun">t</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">ErrorCondEnum</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CErrorCondEnum,,%3E(ErrorCondEnum&amp;&amp;,outcome_v2_xxx::result::error_condition_converting_constructor_tag)"><span class="typ dec var fun">result</span></a><span class="pun">(</span><span class="typ dec var fun">ErrorCondEnum</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CErrorCondEnum,,%3E(ErrorCondEnum&amp;&amp;,outcome_v2_xxx::result::error_condition_converting_constructor_tag).t"><span class="typ dec var fun">t</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CT,,%3E(T&amp;&amp;,outcome_v2_xxx::result::explicit_valueorerror_converting_constructor_tag)"><span class="typ dec var fun">result</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CT,,%3E(T&amp;&amp;,outcome_v2_xxx::result::explicit_valueorerror_converting_constructor_tag).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">V</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CT,U,V,%3E(result%3CT,U,V%3Econst&amp;)"><span class="typ dec var fun">result</span></a><span class="pun">(</span><span class="typ dec var fun">result</span><span class="pun">&lt;</span>T, U, V<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CT,U,V,%3E(result%3CT,U,V%3Econst&amp;).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">V</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CT,U,V,%3E(result%3CT,U,V%3E&amp;&amp;)"><span class="typ dec var fun">result</span></a><span class="pun">(</span><span class="typ dec var fun">result</span><span class="pun">&lt;</span>T, U, V<span class="pun">&gt;</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CT,U,V,%3E(result%3CT,U,V%3E&amp;&amp;).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="pun">...</span> <span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CArgs,%3E(in_place_type_t%3Coutcome_v2_xxx::result::value_type_if_enabled%3E,Args&amp;&amp;...)"><span class="typ dec var fun">result</span></a><span class="pun">(</span><a href="doc_value_storage.md#standardese-outcome_v2_xxx::in_place_type_t%3CT%3E"><span class="typ dec var fun">in_place_type_t</span></a><span class="pun">&lt;</span>outcome_v2_xxx::result::value_type_if_enabled<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CArgs,%3E(in_place_type_t%3Coutcome_v2_xxx::result::value_type_if_enabled%3E,Args&amp;&amp;...)._"><span class="typ dec var fun">_</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CArgs,%3E(in_place_type_t%3Coutcome_v2_xxx::result::value_type_if_enabled%3E,Args&amp;&amp;...).args"><span class="typ dec var fun">args</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="pun">...</span> <span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::result::value_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...)"><span class="typ dec var fun">result</span></a><span class="pun">(</span><a href="doc_value_storage.md#standardese-outcome_v2_xxx::in_place_type_t%3CT%3E"><span class="typ dec var fun">in_place_type_t</span></a><span class="pun">&lt;</span>outcome_v2_xxx::result::value_type_if_enabled<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::result::value_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...)._"><span class="typ dec var fun">_</span></a><span class="pun">,</span> <span class="typ dec var fun">std::initializer_list</span><span class="pun">&lt;</span>U<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::result::value_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...).il"><span class="typ dec var fun">il</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::result::value_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...).args"><span class="typ dec var fun">args</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="pun">...</span> <span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CArgs,%3E(in_place_type_t%3Coutcome_v2_xxx::result::error_type_if_enabled%3E,Args&amp;&amp;...)"><span class="typ dec var fun">result</span></a><span class="pun">(</span><a href="doc_value_storage.md#standardese-outcome_v2_xxx::in_place_type_t%3CT%3E"><span class="typ dec var fun">in_place_type_t</span></a><span class="pun">&lt;</span>outcome_v2_xxx::result::error_type_if_enabled<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CArgs,%3E(in_place_type_t%3Coutcome_v2_xxx::result::error_type_if_enabled%3E,Args&amp;&amp;...)._"><span class="typ dec var fun">_</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CArgs,%3E(in_place_type_t%3Coutcome_v2_xxx::result::error_type_if_enabled%3E,Args&amp;&amp;...).args"><span class="typ dec var fun">args</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="pun">...</span> <span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::result::error_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...)"><span class="typ dec var fun">result</span></a><span class="pun">(</span><a href="doc_value_storage.md#standardese-outcome_v2_xxx::in_place_type_t%3CT%3E"><span class="typ dec var fun">in_place_type_t</span></a><span class="pun">&lt;</span>outcome_v2_xxx::result::error_type_if_enabled<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::result::error_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...)._"><span class="typ dec var fun">_</span></a><span class="pun">,</span> <span class="typ dec var fun">std::initializer_list</span><span class="pun">&lt;</span>U<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::result::error_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...).il"><span class="typ dec var fun">il</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::result::error_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...).args"><span class="typ dec var fun">args</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">A1</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">A2</span><span class="pun">,</span> <span class="kwd">class</span> <span class="pun">...</span> <span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CA1,A2,Args,%3E(A1&amp;&amp;,A2&amp;&amp;,Args&amp;&amp;...)"><span class="typ dec var fun">result</span></a><span class="pun">(</span><span class="typ dec var fun">A1</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">a1</span><span class="pun">,</span> <span class="typ dec var fun">A2</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">a2</span><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CA1,A2,Args,%3E(A1&amp;&amp;,A2&amp;&amp;,Args&amp;&amp;...).args"><span class="typ dec var fun">args</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result(success_type%3Cvoid%3Econst&amp;)"><span class="typ dec var fun">result</span></a><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx::success_type%3CT%3E"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>void<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result(success_type%3Cvoid%3Econst&amp;).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CT,%3E(success_type%3CT%3Econst&amp;)"><span class="typ dec var fun">result</span></a><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx::success_type%3CT%3E"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>T<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CT,%3E(success_type%3CT%3Econst&amp;).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CT,%3E(success_type%3CT%3E&amp;&amp;)"><span class="typ dec var fun">result</span></a><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx::success_type%3CT%3E"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>T<span class="pun">&gt;</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CT,%3E(success_type%3CT%3E&amp;&amp;).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CT,%3E(failure_type%3CT%3Econst&amp;)"><span class="typ dec var fun">result</span></a><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>T<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CT,%3E(failure_type%3CT%3Econst&amp;).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CT,%3E(failure_type%3CT%3E&amp;&amp;)"><span class="typ dec var fun">result</span></a><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>T<span class="pun">&gt;</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CT,%3E(failure_type%3CT%3E&amp;&amp;).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::swap(result%3CR,S,NoValuePolicy%3E&amp;)"><span class="typ dec var fun">swap</span></a><span class="pun">(</span>result&lt;R, S, NoValuePolicy&gt;<span class="pun">&amp;</span> <span class="typ dec var fun">o</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">auto</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::as_failure()const&amp;"><span class="typ dec var fun">as_failure</span></a><span class="pun">(</span><span class="pun">)</span> <span class="kwd">const</span> <span class="pun">&amp;</span><span class="pun">;</span>

    <span class="kwd">auto</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::as_failure()&amp;&amp;"><span class="typ dec var fun">as_failure</span></a><span class="pun">(</span><span class="pun">)</span> <span class="pun">&amp;&amp;</span><span class="pun">;</span>
<span class="pun">};</span>
</code></pre>

Used to return from functions either (i) a successful value (ii) a cause of failure. `constexpr` capable.

Any `R` (`value_type`) state can be observed using the member functions `.value()` and `.assume_value()`. Any `S` (`error_type`) state can be observed using the member functions `.error()` and `.assume_error()`.

`NoValuePolicy` defaults to a policy selected according to the characteristics of type `S`:

1.  If `.value()` called when there is no `value_type` but there is an `error_type`:

<!-- end list -->

  - If `trait::has_error_code_v<S>` is true, then `throw std::system_error(error()|make_error_code(error()))` \[\\verbatim {{\<api “policies/result\_error\_code\_throw\_as\_system\_error” “policy::error\_code\_throw\_as\_system\_error\<S\>”\>}} \\endverbatim\]

  - If `trait::has_exception_ptr_v<S>`, then `std::rethrow_exception(error()|make_exception_ptr(error()))` \[`policy::exception_ptr_rethrow<R, S, void>`\]

  - If `S` is `void`, call `std::terminate()` \[`policy::terminate`\]

  - If `S` is none of the above, then it is undefined behaviour \[`policy::all_narrow`\]

<!-- end list -->

1.  If `.error()` called when there is no `error_type`:

<!-- end list -->

  - If `trait::has_error_code_v<S>`, or if `trait::has_exception_ptr_v<S>`, or if `S` is `void`, do `throw bad_result_access()`

  - If `S` is none of the above, then it is undefined behaviour \[`policy::all_narrow`\]

#### Template parameters

  - `R` &mdash; The optional type of the successful result (use `void` to disable). Cannot be a reference, a `in_place_type_t<>`, `success<>`, `failure<>`, an array, a function or non-destructible.
  - `S` &mdash; The optional type of the failure result (use `void` to disable). Must be either `void` or `DefaultConstructible`. Cannot be a reference, a `in_place_type_t<>`, `success<>`, `failure<>`, an array, a function or non-destructible.
  - `NoValuePolicy` &mdash; Policy on how to interpret type `S` when a wide observation of a not present value occurs.

### Type alias `value_type`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::value_type"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">using</span> <span class="typ dec var fun">value_type</span> <span class="pun">=</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E.R"><span class="typ dec var fun">R</span></a><span class="pun">;</span>
</code></pre>

The success type.

-----

### Type alias `error_type`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::error_type"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">using</span> <span class="typ dec var fun">error_type</span> <span class="pun">=</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E.S"><span class="typ dec var fun">S</span></a><span class="pun">;</span>
</code></pre>

The failure type.

-----

### Type alias `value_type_if_enabled`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::value_type_if_enabled"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">using</span> <span class="typ dec var fun">value_type_if_enabled</span> <span class="pun">=</span> typename base::_value_type<span class="pun">;</span>
</code></pre>

Used to disable in place type construction when `value_type` and `error_type` are ambiguous.

-----

### Type alias `error_type_if_enabled`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::error_type_if_enabled"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">using</span> <span class="typ dec var fun">error_type_if_enabled</span> <span class="pun">=</span> typename base::_error_type<span class="pun">;</span>
</code></pre>

Used to disable in place type construction when `value_type` and `error_type` are ambiguous.

-----

### Alias template `rebind`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::rebind&lt;T,U,V&gt;"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span> <span class="pun">=</span> S<span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">V</span> <span class="pun">=</span> policy::default_policy&lt;T,U,void&gt;<span class="pun">&gt;</span>
<span class="kwd">using</span> <span class="typ dec var fun">rebind</span> <span class="pun">=</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>T, U, V<span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

Used to rebind this result to a different result type.

-----

### Struct `predicate`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::predicate"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">struct</span> <span class="typ dec var fun">predicate</span>
<span class="pun">{</span>
    <span class="kwd">using</span> <span class="typ dec var fun">base</span> <span class="pun">=</span> <span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">;</span>

    <span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span> <span class="kwd">T</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">enable_value_converting_constructor</span> <span class="pun">=</span> <span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">,</span> <span class="kwd">result</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span> <span class="pun">&amp;&amp;</span> <span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>  <span class="kwd">enable_value_converting_constructor</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">;</span>

    <span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span> <span class="kwd">T</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">enable_error_converting_constructor</span> <span class="pun">=</span> <span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">,</span> <span class="kwd">result</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span> <span class="pun">&amp;&amp;</span> <span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>  <span class="kwd">enable_error_converting_constructor</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">;</span>

    <span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span> <span class="kwd">ErrorCondEnum</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">enable_error_condition_converting_constructor</span> <span class="pun">=</span> <span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">ErrorCondEnum</span><span class="pun">&gt;</span><span class="pun">,</span> <span class="kwd">result</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span> <span class="pun">&amp;&amp;</span> <span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>  <span class="kwd">enable_error_condition_converting_constructor</span><span class="pun">&lt;</span><span class="kwd">ErrorCondEnum</span><span class="pun">&gt;</span><span class="pun">;</span>

    <span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span> <span class="kwd">T</span><span class="pun">,</span> <span class="typ dec var fun">class</span> <span class="kwd">U</span><span class="pun">,</span> <span class="typ dec var fun">class</span> <span class="kwd">V</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">enable_compatible_conversion</span> <span class="pun">=</span> <span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">result</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">,</span> <span class="kwd">U</span><span class="pun">,</span> <span class="kwd">V</span><span class="pun">&gt;</span><span class="pun">,</span> <span class="kwd">result</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span> <span class="pun">&amp;&amp;</span> <span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>  <span class="kwd">enable_compatible_conversion</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">,</span> <span class="kwd">U</span><span class="pun">,</span> <span class="kwd">V</span><span class="pun">&gt;</span><span class="pun">;</span>

    <span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span><span class="pun">...</span><span class="kwd">Args</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">enable_inplace_value_constructor</span> <span class="pun">=</span> <span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_void</span><span class="pun">&lt;</span><span class="kwd">value_type</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span> <span class="pun">||</span> <span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_constructible</span><span class="pun">&lt;</span><span class="kwd">value_type</span><span class="pun">,</span> <span class="kwd">Args</span><span class="pun">...</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>

    <span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span><span class="pun">...</span><span class="kwd">Args</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">enable_inplace_error_constructor</span> <span class="pun">=</span> <span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_void</span><span class="pun">&lt;</span><span class="kwd">error_type</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span> <span class="pun">||</span> <span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_constructible</span><span class="pun">&lt;</span><span class="kwd">error_type</span><span class="pun">,</span> <span class="kwd">Args</span><span class="pun">...</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>

    <span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span><span class="pun">...</span><span class="kwd">Args</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">enable_inplace_value_error_constructor</span> <span class="pun">=</span> <span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>  <span class="kwd">enable_inplace_value_error_constructor</span><span class="pun">&lt;</span><span class="kwd">Args</span><span class="pun">...</span><span class="pun">&gt;</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="pun">...</span> <span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
    <span class="kwd">using</span> <span class="typ dec var fun">choose_inplace_value_error_constructor</span> <span class="pun">=</span> typename base::choose_inplace_value_error_constructor&lt;Args...&gt;<span class="pun">;</span>
<span class="pun">};</span>
</code></pre>

Requirement predicates for result.

### Unexposed entity `enable_value_converting_constructor`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::predicate::enable_value_converting_constructor"></a>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span> <span class="kwd">T</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">enable_value_converting_constructor</span> <span class="pun">=</span> <span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">,</span> <span class="kwd">result</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span> <span class="pun">&amp;&amp;</span> <span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>  <span class="kwd">enable_value_converting_constructor</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

Predicate for the value converting constructor to be available.

-----

### Unexposed entity `enable_error_converting_constructor`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::predicate::enable_error_converting_constructor"></a>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span> <span class="kwd">T</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">enable_error_converting_constructor</span> <span class="pun">=</span> <span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">,</span> <span class="kwd">result</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span> <span class="pun">&amp;&amp;</span> <span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>  <span class="kwd">enable_error_converting_constructor</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

Predicate for the error converting constructor to be available.

-----

### Unexposed entity `enable_error_condition_converting_constructor`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::predicate::enable_error_condition_converting_constructor"></a>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span> <span class="kwd">ErrorCondEnum</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">enable_error_condition_converting_constructor</span> <span class="pun">=</span> <span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">ErrorCondEnum</span><span class="pun">&gt;</span><span class="pun">,</span> <span class="kwd">result</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span> <span class="pun">&amp;&amp;</span> <span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>  <span class="kwd">enable_error_condition_converting_constructor</span><span class="pun">&lt;</span><span class="kwd">ErrorCondEnum</span><span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

Predicate for the error condition converting constructor to be available.

-----

### Unexposed entity `enable_compatible_conversion`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::predicate::enable_compatible_conversion"></a>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span> <span class="kwd">T</span><span class="pun">,</span> <span class="typ dec var fun">class</span> <span class="kwd">U</span><span class="pun">,</span> <span class="typ dec var fun">class</span> <span class="kwd">V</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">enable_compatible_conversion</span> <span class="pun">=</span> <span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">result</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">,</span> <span class="kwd">U</span><span class="pun">,</span> <span class="kwd">V</span><span class="pun">&gt;</span><span class="pun">,</span> <span class="kwd">result</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span> <span class="pun">&amp;&amp;</span> <span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>  <span class="kwd">enable_compatible_conversion</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">,</span> <span class="kwd">U</span><span class="pun">,</span> <span class="kwd">V</span><span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

Predicate for the converting copy constructor from a compatible input to be available.

-----

### Unexposed entity `enable_inplace_value_constructor`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::predicate::enable_inplace_value_constructor"></a>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span><span class="pun">...</span><span class="kwd">Args</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">enable_inplace_value_constructor</span> <span class="pun">=</span> <span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_void</span><span class="pun">&lt;</span><span class="kwd">value_type</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span> <span class="pun">||</span> <span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_constructible</span><span class="pun">&lt;</span><span class="kwd">value_type</span><span class="pun">,</span> <span class="kwd">Args</span><span class="pun">...</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>
</code></pre>

Predicate for the inplace construction of value to be available.

-----

### Unexposed entity `enable_inplace_error_constructor`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::predicate::enable_inplace_error_constructor"></a>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span><span class="pun">...</span><span class="kwd">Args</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">enable_inplace_error_constructor</span> <span class="pun">=</span> <span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_void</span><span class="pun">&lt;</span><span class="kwd">error_type</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span> <span class="pun">||</span> <span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_constructible</span><span class="pun">&lt;</span><span class="kwd">error_type</span><span class="pun">,</span> <span class="kwd">Args</span><span class="pun">...</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>
</code></pre>

Predicate for the inplace construction of error to be available.

-----

-----

### Constructor `result`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::result()"></a>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">result</span><span class="pun">(</span><span class="pun">)</span> <span class="pun">=</span> <span class="kwd">delete</span><span class="pun">;</span>
</code></pre>

Default construction is not permitted.

-----

### Constructor `result`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::result(result&lt;R,S,NoValuePolicy&gt;&amp;&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">result</span><span class="pun">(</span>result&lt;R, S, NoValuePolicy&gt;<span class="pun">&amp;&amp;</span><span class="pun">)</span> <span class="pun">=</span> <span class="kwd">default</span><span class="pun">;</span>
</code></pre>

Move construction available if `value_type` and `error_type` implement it.

-----

### Constructor `result`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::result(constresult&lt;R,S,NoValuePolicy&gt;&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">result</span><span class="pun">(</span>const result&lt;R, S, NoValuePolicy&gt;<span class="pun">&amp;</span><span class="pun">)</span> <span class="pun">=</span> <span class="kwd">default</span><span class="pun">;</span>
</code></pre>

Copy construction available if `value_type` and `error_type` implement it.

-----

### Function `operator=`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::operator=(result&lt;R,S,NoValuePolicy&gt;&amp;&amp;)"></a>

<pre><code class="standardese-language-cpp">result&lt;R, S, NoValuePolicy&gt;<span class="pun">&amp;</span> <span class="typ dec var fun">operator=</span><span class="pun">(</span>result&lt;R, S, NoValuePolicy&gt;<span class="pun">&amp;&amp;</span><span class="pun">)</span> <span class="pun">=</span> <span class="kwd">default</span><span class="pun">;</span>
</code></pre>

Move assignment available if `value_type` and `error_type` implement it.

-----

### Function `operator=`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::operator=(constresult&lt;R,S,NoValuePolicy&gt;&amp;)"></a>

<pre><code class="standardese-language-cpp">result&lt;R, S, NoValuePolicy&gt;<span class="pun">&amp;</span> <span class="typ dec var fun">operator=</span><span class="pun">(</span>const result&lt;R, S, NoValuePolicy&gt;<span class="pun">&amp;</span><span class="pun">)</span> <span class="pun">=</span> <span class="kwd">default</span><span class="pun">;</span>
</code></pre>

Copy assignment available if `value_type` and `error_type` implement it.

-----

### Constructor `result`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::result&lt;T,&gt;(T&amp;&amp;,outcome_v2_xxx::result::value_converting_constructor_tag)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">result</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CT,%3E(T&amp;&amp;,outcome_v2_xxx::result::value_converting_constructor_tag).t"><span class="typ dec var fun">t</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Implicit converting constructor to a successful result.

*Effects:* Initialises the result with a `value_type`.

*Requires:* Type T is implicitly constructible to `value_type`, is not implicitly constructible to `error_type`, and is not `result<R, S>` and not `in_place_type<>`.

*Throws:* Any exception the construction of `value_type(T)` might throw.

#### Parameters

  - `t` &mdash; The value from which to initialise the `value_type`.

-----

### Constructor `result`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::result&lt;T,&gt;(T&amp;&amp;,outcome_v2_xxx::result::error_converting_constructor_tag)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">result</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CT,%3E(T&amp;&amp;,outcome_v2_xxx::result::error_converting_constructor_tag).t"><span class="typ dec var fun">t</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Implicit converting constructor to a failure result.

*Effects:* Initialises the result with a `error_type`.

*Requires:* Type T is implicitly constructible to `error_type`, is not implicitly constructible to `value_type`, and is not `result<R, S>` and not `in_place_type<>`.

*Throws:* Any exception the construction of `error_type(T)` might throw.

#### Parameters

  - `t` &mdash; The value from which to initialise the `error_type`.

-----

### Constructor `result`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::result&lt;ErrorCondEnum,,&gt;(ErrorCondEnum&amp;&amp;,outcome_v2_xxx::result::error_condition_converting_constructor_tag)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">ErrorCondEnum</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">result</span><span class="pun">(</span><span class="typ dec var fun">ErrorCondEnum</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CErrorCondEnum,,%3E(ErrorCondEnum&amp;&amp;,outcome_v2_xxx::result::error_condition_converting_constructor_tag).t"><span class="typ dec var fun">t</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Implicit special error condition converting constructor to a failure result.

*Effects:* Initialises the result with a `error_type` constructed via `make_error_code(t)`.

*Requires:* `std::is_error_condition_enum<ErrorCondEnum>` must be true, `ErrorCondEnum` is not implicitly constructible to `value_type` nor `error_type`, and is not `result<R, S>` and not `in_place_type<>`; Finally, the expression `error_type(make_error_code(ErrorCondEnum()))` must be valid.

*Throws:* Any exception the construction of `error_type(make_error_code(t))` might throw.

#### Parameters

  - `t` &mdash; The error condition from which to initialise the `error_type`.

-----

### Constructor `result`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::result&lt;T,,&gt;(T&amp;&amp;,outcome_v2_xxx::result::explicit_valueorerror_converting_constructor_tag)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">result</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CT,,%3E(T&amp;&amp;,outcome_v2_xxx::result::explicit_valueorerror_converting_constructor_tag).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Explicit converting constructor from a compatible `ValueOrError` type.

*Effects:* Initialises the result with the contents of the compatible input.

*Requires:* That `convert::value_or_error<result, std::decay_t<T>>{}(std::forward<T>(o))` be available. The default implementation will consume `T`’s matching the `ValueOrError` concept type. `ValueOrError` concept matches any type with a `value_type`, an `error_type`, a `.value()`, an `.error()` and a `.has_value()`.

#### Parameters

  - `o` &mdash; The input for which a `convert::value_or_error<result, std::decay_t<T>>{}(std::forward<T>(o))` is available.

-----

### Constructor `result`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::result&lt;T,U,V,&gt;(result&lt;T,U,V&gt;const&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">V</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">result</span><span class="pun">(</span><a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>T, U, V<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CT,U,V,%3E(result%3CT,U,V%3Econst&amp;).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Explicit converting copy constructor from a compatible result type.

*Effects:* Initialises the result with a copy of the compatible result.

*Requires:* Both result’s `value_type` and `error_type` need to be constructible, or the source can be `void`.

*Throws:* Any exception the construction of `value_type(T)` and `error_type(U)` might throw.

#### Parameters

  - `o` &mdash; The compatible result.

-----

### Constructor `result`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::result&lt;T,U,V,&gt;(result&lt;T,U,V&gt;&amp;&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">V</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">result</span><span class="pun">(</span><a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>T, U, V<span class="pun">&gt;</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CT,U,V,%3E(result%3CT,U,V%3E&amp;&amp;).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Explicit converting move constructor from a compatible result type.

*Effects:* Initialises the result with a move of the compatible result.

*Requires:* Both result’s `value_type` and `error_type` need to be constructible, or the source can be `void`.

*Throws:* Any exception the construction of `value_type(T)` and `error_type(U)` might throw.

#### Parameters

  - `o` &mdash; The compatible result.

-----

### Constructor `result`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::result&lt;Args,&gt;(in_place_type_t&lt;outcome_v2_xxx::result::value_type_if_enabled&gt;,Args&amp;&amp;...)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="pun">...</span> <span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">result</span><span class="pun">(</span><a href="doc_value_storage.md#standardese-outcome_v2_xxx::in_place_type_t%3CT%3E"><span class="typ dec var fun">in_place_type_t</span></a><span class="pun">&lt;</span>outcome_v2_xxx::result::value_type_if_enabled<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CArgs,%3E(in_place_type_t%3Coutcome_v2_xxx::result::value_type_if_enabled%3E,Args&amp;&amp;...)._"><span class="typ dec var fun">_</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CArgs,%3E(in_place_type_t%3Coutcome_v2_xxx::result::value_type_if_enabled%3E,Args&amp;&amp;...).args"><span class="typ dec var fun">args</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Explicit inplace constructor to a successful result.

*Effects:* Initialises the result with a `value_type`.

*Requires:* `value_type` is void or `Args...` are constructible to `value_type`.

*Throws:* Any exception the construction of `value_type(Args...)` might throw.

#### Parameters

  - `_` &mdash; Tag type to indicate we are doing in place construction of `value_type`.
  - `args` &mdash; Arguments with which to in place construct.

-----

### Constructor `result`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::result&lt;U,Args,&gt;(in_place_type_t&lt;outcome_v2_xxx::result::value_type_if_enabled&gt;,std::initializer_list&lt;U&gt;,Args&amp;&amp;...)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="pun">...</span> <span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">result</span><span class="pun">(</span><a href="doc_value_storage.md#standardese-outcome_v2_xxx::in_place_type_t%3CT%3E"><span class="typ dec var fun">in_place_type_t</span></a><span class="pun">&lt;</span>outcome_v2_xxx::result::value_type_if_enabled<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::result::value_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...)._"><span class="typ dec var fun">_</span></a><span class="pun">,</span> <span class="typ dec var fun">std::initializer_list</span><span class="pun">&lt;</span>U<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::result::value_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...).il"><span class="typ dec var fun">il</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::result::value_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...).args"><span class="typ dec var fun">args</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
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

### Constructor `result`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::result&lt;Args,&gt;(in_place_type_t&lt;outcome_v2_xxx::result::error_type_if_enabled&gt;,Args&amp;&amp;...)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="pun">...</span> <span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">result</span><span class="pun">(</span><a href="doc_value_storage.md#standardese-outcome_v2_xxx::in_place_type_t%3CT%3E"><span class="typ dec var fun">in_place_type_t</span></a><span class="pun">&lt;</span>outcome_v2_xxx::result::error_type_if_enabled<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CArgs,%3E(in_place_type_t%3Coutcome_v2_xxx::result::error_type_if_enabled%3E,Args&amp;&amp;...)._"><span class="typ dec var fun">_</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CArgs,%3E(in_place_type_t%3Coutcome_v2_xxx::result::error_type_if_enabled%3E,Args&amp;&amp;...).args"><span class="typ dec var fun">args</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Explicit inplace constructor to a failure result.

*Effects:* Initialises the result with a `error_type`.

*Requires:* `error_type` is void or `Args...` are constructible to `error_type`.

*Throws:* Any exception the construction of `error_type(Args...)` might throw.

#### Parameters

  - `_` &mdash; Tag type to indicate we are doing in place construction of `error_type`.
  - `args` &mdash; Arguments with which to in place construct.

-----

### Constructor `result`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::result&lt;U,Args,&gt;(in_place_type_t&lt;outcome_v2_xxx::result::error_type_if_enabled&gt;,std::initializer_list&lt;U&gt;,Args&amp;&amp;...)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="pun">...</span> <span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">result</span><span class="pun">(</span><a href="doc_value_storage.md#standardese-outcome_v2_xxx::in_place_type_t%3CT%3E"><span class="typ dec var fun">in_place_type_t</span></a><span class="pun">&lt;</span>outcome_v2_xxx::result::error_type_if_enabled<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::result::error_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...)._"><span class="typ dec var fun">_</span></a><span class="pun">,</span> <span class="typ dec var fun">std::initializer_list</span><span class="pun">&lt;</span>U<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::result::error_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...).il"><span class="typ dec var fun">il</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::result::error_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...).args"><span class="typ dec var fun">args</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
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

### Constructor `result`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::result&lt;A1,A2,Args,&gt;(A1&amp;&amp;,A2&amp;&amp;,Args&amp;&amp;...)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">A1</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">A2</span><span class="pun">,</span> <span class="kwd">class</span> <span class="pun">...</span> <span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">result</span><span class="pun">(</span><span class="typ dec var fun">A1</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">a1</span><span class="pun">,</span> <span class="typ dec var fun">A2</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">a2</span><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CA1,A2,Args,%3E(A1&amp;&amp;,A2&amp;&amp;,Args&amp;&amp;...).args"><span class="typ dec var fun">args</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Implicit inplace constructor to successful or failure result.

*Effects:* Calls the appropriate `in_place_type_t<...>` constructor depending on constructibility of args.

*Requires:* That the args can construct exactly one of `value_type` or `error_type`.

*Throws:* Any exception the `in_place_type_t<...>` constructor might throw.

#### Parameters

  - `args` &mdash; Arguments with which to in place construct.

-----

### Constructor `result`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::result(success_type&lt;void&gt;const&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">constexpr</span> <span class="typ dec var fun">result</span><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx::success_type%3CT%3E"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>void<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result(success_type%3Cvoid%3Econst&amp;).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Implicit tagged constructor of a successful result.

*Effects:* Initialises the result with a default constructed success type.

*Requires:* `value_type` to be default constructible, or `void`.

*Throws:* Any exception the construction of `value_type()` might throw.

#### Parameters

  - `o` &mdash; The compatible success type sugar.

-----

### Constructor `result`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::result&lt;T,&gt;(success_type&lt;T&gt;const&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">result</span><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx::success_type%3CT%3E"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>T<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CT,%3E(success_type%3CT%3Econst&amp;).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Implicit tagged constructor of a successful result.

*Effects:* Initialises the result with a copy of the value in the type sugar.

*Requires:* Both result and success’ `value_type` need to be constructible, or the source can be `void`.

*Throws:* Any exception the construction of `value_type(T)` might throw.

#### Parameters

  - `o` &mdash; The compatible success type sugar.

-----

### Constructor `result`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::result&lt;T,&gt;(success_type&lt;T&gt;&amp;&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">result</span><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx::success_type%3CT%3E"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>T<span class="pun">&gt;</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CT,%3E(success_type%3CT%3E&amp;&amp;).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Implicit tagged constructor of a successful result.

*Effects:* Initialises the result with a move of the value in the type sugar.

*Requires:* Both result and success’ `value_type` need to be constructible. The source cannot be `void`.

*Throws:* Any exception the construction of `value_type(T)` might throw.

#### Parameters

  - `o` &mdash; The compatible success type sugar.

-----

### Constructor `result`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::result&lt;T,&gt;(failure_type&lt;T&gt;const&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">result</span><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>T<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CT,%3E(failure_type%3CT%3Econst&amp;).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Implicit tagged constructor of a failure result.

*Effects:* Initialises the result with a copy of the error in the type sugar.

*Requires:* Both result and failure’s `error_type` need to be constructible, or the source can be `void`.

*Throws:* Any exception the construction of `error_type(T)` might throw.

#### Parameters

  - `o` &mdash; The compatible failure type sugar.

-----

### Constructor `result`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::result&lt;T,&gt;(failure_type&lt;T&gt;&amp;&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">result</span><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>T<span class="pun">&gt;</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E::result%3CT,%3E(failure_type%3CT%3E&amp;&amp;).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Implicit tagged constructor of a failure result.

*Effects:* Initialises the result with a move of the error in the type sugar.

*Requires:* Both result and failure’s `error_type` need to be constructible, or the source can be `void`.

*Throws:* Any exception the construction of `error_type(T)` might throw.

#### Parameters

  - `o` &mdash; The compatible failure type sugar.

-----

### Function `swap`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::swap(result&lt;R,S,NoValuePolicy&gt;&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">void</span> <span class="typ dec var fun">swap</span><span class="pun">(</span>result&lt;R, S, NoValuePolicy&gt;<span class="pun">&amp;</span> <span class="typ dec var fun">o</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Swaps this result with another result

*Effects:* Any `R` and/or `S` is swapped along with the metadata tracking them.

-----

### Function `as_failure`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::as_failure()const&amp;"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">auto</span> <span class="typ dec var fun">as_failure</span><span class="pun">(</span><span class="pun">)</span> <span class="kwd">const</span> <span class="pun">&amp;</span><span class="pun">;</span>
</code></pre>

Returns this result as a `failure_type` with any errored state copied.

*Requires:* This result to have a failed state, else whatever `assume_error()` would do.

-----

### Function `as_failure`

<a id="standardese-outcome_v2_xxx::result&lt;R,S,NoValuePolicy&gt;::as_failure()&amp;&amp;"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">auto</span> <span class="typ dec var fun">as_failure</span><span class="pun">(</span><span class="pun">)</span> <span class="pun">&amp;&amp;</span><span class="pun">;</span>
</code></pre>

Returns this result as a `failure_type` with any errored state moved.

*Requires:* This result to have a failed state, else whatever `assume_error()` would do.

-----

-----

### Function `outcome_v2_xxx::swap`

<a id="standardese-outcome_v2_xxx::swap&lt;R,S,P&gt;(result&lt;R,S,P&gt;&amp;,result&lt;R,S,P&gt;&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">&gt;</span>
<span class="kwd">void</span> <span class="typ dec var fun">swap</span><span class="pun">(</span><a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>R, S, P<span class="pun">&gt;</span><span class="pun">&amp;</span> <span class="typ dec var fun">a</span><span class="pun">,</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>R, S, P<span class="pun">&gt;</span><span class="pun">&amp;</span> <span class="typ dec var fun">b</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Specialise swap for result.

*Effects:* Calls `a.swap(b)`.

-----

### Alias template `outcome_v2_xxx::unchecked`

<a id="standardese-outcome_v2_xxx::unchecked&lt;R,S&gt;"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span> <span class="pun">=</span> std::error_code<span class="pun">&gt;</span>
<span class="kwd">using</span> <span class="typ dec var fun">unchecked</span> <span class="pun">=</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>R, S, policy::all_narrow<span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

An “unchecked” edition of `result<T, E>` which does no special handling of specific `E` types at all.

Attempting to access `T` when there is an `E` results in nothing happening at all, it is treated with a narrow contract (i.e. undefined behaviour).

-----

### Alias template `outcome_v2_xxx::checked`

<a id="standardese-outcome_v2_xxx::checked&lt;R,S&gt;"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span> <span class="pun">=</span> std::error_code<span class="pun">&gt;</span>
<span class="kwd">using</span> <span class="typ dec var fun">checked</span> <span class="pun">=</span> <a href="#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>R, S, policy::throw_bad_result_access&lt;S&gt;<span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

A “checked” edition of `result<T, E>` which does no special handling of specific `E` types at all.

Attempting to access `T` when there is an `E` results in `bad_result_access<E>` being thrown. Nothing else.

Note that this approximates the proposed `expected<T, E>` up for standardisation, see the FAQ for more detail.

-----
