+++
title = "outcome<R, S, P>"
weight = 10
+++
# Header file `outcome.hpp`

<a id="standardese-outcome.hpp"></a>

<pre><code class="standardese-language-cpp"><span class="pre">#include</span> <span class="pre">&quot;</span><span class="typ dec var fun">detail&#x2F;outcome_exception_observers.hpp</span><span class="pre">&quot;</span>

<span class="pre">#include</span> <span class="pre">&quot;</span><span class="typ dec var fun">detail&#x2F;outcome_failure_observers.hpp</span><span class="pre">&quot;</span>

<span class="pre">#include</span> <span class="pre">&quot;</span><span class="typ dec var fun">result.hpp</span><span class="pre">&quot;</span>

<span class="pre">#include</span> <span class="pre">&lt;</span><span class="typ dec var fun">memory</span><span class="pre">&gt;</span>

<span class="pre">#include</span> <span class="pre">&quot;</span><span class="typ dec var fun">detail&#x2F;outcome_exception_observers_impl.hpp</span><span class="pre">&quot;</span>

<span class="pre">#include</span> <span class="pre">&quot;</span><span class="typ dec var fun">policy&#x2F;outcome_error_code_throw_as_system_error.hpp</span><span class="pre">&quot;</span>

<span class="pre">#include</span> <span class="pre">&quot;</span><span class="typ dec var fun">policy&#x2F;outcome_exception_ptr_rethrow.hpp</span><span class="pre">&quot;</span>

<span class="kwd">namespace</span> <span class="typ dec var fun">outcome_v2_xxx</span>
<span class="pun">{</span>
    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
    <span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx::is_outcome%3CT%3E"><span class="typ dec var fun">is_outcome</span></a> <span class="pun">=</span> <span class="typ dec var fun">detail::is_outcome</span><span class="pun">&lt;</span>std::decay_t&lt;T&gt;<span class="pun">&gt;</span><span class="pun">;</span>

    <span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span> <span class="kwd">T</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">is_outcome_v</span> <span class="pun">=</span> <span class="kwd">detail</span><span class="pun">::</span><span class="kwd">is_outcome</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>

    <span class="kwd">namespace</span> <span class="typ dec var fun">hooks</span>
    <span class="pun">{</span>
        <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">&gt;</span>
        <span class="kwd">constexpr</span> <span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx::hooks::hook_outcome_construction%3CT,U%3E(T*,U&amp;&amp;)"><span class="typ dec var fun">hook_outcome_construction</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">*</span><span class="pun">,</span> <span class="typ dec var fun">U</span><span class="pun">&amp;&amp;</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">;</span>

        <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">&gt;</span>
        <span class="kwd">constexpr</span> <span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx::hooks::hook_outcome_copy_construction%3CT,U%3E(T*,U&amp;&amp;)"><span class="typ dec var fun">hook_outcome_copy_construction</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">*</span><span class="pun">,</span> <span class="typ dec var fun">U</span><span class="pun">&amp;&amp;</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">;</span>

        <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">&gt;</span>
        <span class="kwd">constexpr</span> <span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx::hooks::hook_outcome_move_construction%3CT,U%3E(T*,U&amp;&amp;)"><span class="typ dec var fun">hook_outcome_move_construction</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">*</span><span class="pun">,</span> <span class="typ dec var fun">U</span><span class="pun">&amp;&amp;</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">;</span>

        <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="pun">...</span> <span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
        <span class="kwd">constexpr</span> <span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx::hooks::hook_outcome_in_place_construction%3CT,U,Args%3E(T*,in_place_type_t%3CU%3E,Args&amp;&amp;...)"><span class="typ dec var fun">hook_outcome_in_place_construction</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">*</span><span class="pun">,</span> <span class="typ dec var fun">in_place_type_t</span><span class="pun">&lt;</span>U<span class="pun">&gt;</span><span class="pun">,</span> Args &amp;&amp;...<span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">;</span>

        <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">NoValuePolicy</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">&gt;</span>
        <span class="kwd">constexpr</span> <span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx::hooks::override_outcome_exception%3CR,S,P,NoValuePolicy,U%3E(outcome%3CR,S,P,NoValuePolicy%3E*,U&amp;&amp;)"><span class="typ dec var fun">override_outcome_exception</span></a><span class="pun">(</span><a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, NoValuePolicy<span class="pun">&gt;</span><span class="pun">*</span> <span class="typ dec var fun">o</span><span class="pun">,</span> <span class="typ dec var fun">U</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">;</span>
    <span class="pun">}</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E.R"><span class="typ dec var fun">R</span></a><span class="pun">,</span> <span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E.S"><span class="typ dec var fun">S</span></a><span class="pun">,</span> <span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E.P"><span class="typ dec var fun">P</span></a><span class="pun">,</span> <span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E.NoValuePolicy"><span class="typ dec var fun">NoValuePolicy</span></a><span class="pun">&gt;</span>
    <span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E"><span class="typ dec var fun">outcome</span></a><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">V</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">N</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <span class="kwd">bool</span> <a href="#standardese-outcome_v2_xxx::operator==%3CT,U,V,R,S,P,N,%3E(result%3CT,U,V%3Econst&amp;,outcome%3CR,S,P,N%3Econst&amp;)"><span class="typ dec var fun">operator==</span></a><span class="pun">(</span><a href="result#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>T, U, V<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::operator==%3CT,U,V,R,S,P,N,%3E(result%3CT,U,V%3Econst&amp;,outcome%3CR,S,P,N%3Econst&amp;).a"><span class="typ dec var fun">a</span></a><span class="pun">,</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, N<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::operator==%3CT,U,V,R,S,P,N,%3E(result%3CT,U,V%3Econst&amp;,outcome%3CR,S,P,N%3Econst&amp;).b"><span class="typ dec var fun">b</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">V</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">N</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <span class="kwd">bool</span> <a href="#standardese-outcome_v2_xxx::operator!=%3CT,U,V,R,S,P,N,%3E(result%3CT,U,V%3Econst&amp;,outcome%3CR,S,P,N%3Econst&amp;)"><span class="typ dec var fun">operator!=</span></a><span class="pun">(</span><a href="result#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>T, U, V<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::operator!=%3CT,U,V,R,S,P,N,%3E(result%3CT,U,V%3Econst&amp;,outcome%3CR,S,P,N%3Econst&amp;).a"><span class="typ dec var fun">a</span></a><span class="pun">,</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, N<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::operator!=%3CT,U,V,R,S,P,N,%3E(result%3CT,U,V%3Econst&amp;,outcome%3CR,S,P,N%3Econst&amp;).b"><span class="typ dec var fun">b</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">N</span><span class="pun">&gt;</span>
    <span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx::swap%3CR,S,P,N%3E(outcome%3CR,S,P,N%3E&amp;,outcome%3CR,S,P,N%3E&amp;)"><span class="typ dec var fun">swap</span></a><span class="pun">(</span><a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, N<span class="pun">&gt;</span><span class="pun">&amp;</span> <span class="typ dec var fun">a</span><span class="pun">,</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, N<span class="pun">&gt;</span><span class="pun">&amp;</span> <span class="typ dec var fun">b</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">namespace</span> <span class="typ dec var fun">hooks</span>
    <span class="pun">{</span>
        <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">NoValuePolicy</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">&gt;</span>
        <span class="kwd">constexpr</span> <span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx::hooks::override_outcome_exception%3CR,S,P,NoValuePolicy,U%3E(outcome%3CR,S,P,NoValuePolicy%3E*,U&amp;&amp;)"><span class="typ dec var fun">override_outcome_exception</span></a><span class="pun">(</span><a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, NoValuePolicy<span class="pun">&gt;</span><span class="pun">*</span> <a href="#standardese-outcome_v2_xxx::hooks::override_outcome_exception%3CR,S,P,NoValuePolicy,U%3E(outcome%3CR,S,P,NoValuePolicy%3E*,U&amp;&amp;)"><span class="typ dec var fun">o</span></a><span class="pun">,</span> <span class="typ dec var fun">U</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::hooks::override_outcome_exception%3CR,S,P,NoValuePolicy,U%3E(outcome%3CR,S,P,NoValuePolicy%3E*,U&amp;&amp;)"><span class="typ dec var fun">v</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">;</span>
    <span class="pun">}</span>
<span class="pun">}</span>
</code></pre>

<a id="standardese-outcome_v2_xxx"></a>

### Alias template `outcome_v2_xxx::is_outcome`

<a id="standardese-outcome_v2_xxx::is_outcome&lt;T&gt;"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">using</span> <span class="typ dec var fun">is_outcome</span> <span class="pun">=</span> <span class="typ dec var fun">detail::is_outcome</span><span class="pun">&lt;</span>std::decay_t&lt;T&gt;<span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

True if an outcome

-----

### Unexposed entity `outcome_v2_xxx::is_outcome_v`

<a id="standardese-outcome_v2_xxx::is_outcome_v"></a>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span> <span class="kwd">T</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">is_outcome_v</span> <span class="pun">=</span> <span class="kwd">detail</span><span class="pun">::</span><span class="kwd">is_outcome</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>
</code></pre>

True if an outcome

-----

<a id="standardese-outcome_v2_xxx::hooks"></a>

### Function `outcome_v2_xxx::hooks::hook_outcome_construction`

<a id="standardese-outcome_v2_xxx::hooks::hook_outcome_construction&lt;T,U&gt;(T*,U&amp;&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="kwd">void</span> <span class="typ dec var fun">hook_outcome_construction</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">*</span><span class="pun">,</span> <span class="typ dec var fun">U</span><span class="pun">&amp;&amp;</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

The default instantiation hook implementation called when a `outcome` is first created by conversion from one of its possible types. Does nothing.

WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should\!

#### Parameters

  - `  ` &mdash; Some `outcome<...>` being constructed.

-----

### Function `outcome_v2_xxx::hooks::hook_outcome_copy_construction`

<a id="standardese-outcome_v2_xxx::hooks::hook_outcome_copy_construction&lt;T,U&gt;(T*,U&amp;&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="kwd">void</span> <span class="typ dec var fun">hook_outcome_copy_construction</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">*</span><span class="pun">,</span> <span class="typ dec var fun">U</span><span class="pun">&amp;&amp;</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

The default instantiation hook implementation called when a `outcome` is created by copying from another `outcome` or `result`. Does nothing.

WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should\!

#### Parameters

  - `  ` &mdash; Some `outcome<...>` being constructed.

-----

### Function `outcome_v2_xxx::hooks::hook_outcome_move_construction`

<a id="standardese-outcome_v2_xxx::hooks::hook_outcome_move_construction&lt;T,U&gt;(T*,U&amp;&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="kwd">void</span> <span class="typ dec var fun">hook_outcome_move_construction</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">*</span><span class="pun">,</span> <span class="typ dec var fun">U</span><span class="pun">&amp;&amp;</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

The default instantiation hook implementation called when a `outcome` is created by moving from another `outcome` or `result`. Does nothing.

WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should\!

#### Parameters

  - `  ` &mdash; Some `outcome<...>` being constructed.

-----

### Function `outcome_v2_xxx::hooks::hook_outcome_in_place_construction`

<a id="standardese-outcome_v2_xxx::hooks::hook_outcome_in_place_construction&lt;T,U,Args&gt;(T*,in_place_type_t&lt;U&gt;,Args&amp;&amp;...)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="pun">...</span> <span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="kwd">void</span> <span class="typ dec var fun">hook_outcome_in_place_construction</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">*</span><span class="pun">,</span> <span class="typ dec var fun">in_place_type_t</span><span class="pun">&lt;</span>U<span class="pun">&gt;</span><span class="pun">,</span> Args &amp;&amp;...<span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

The default instantiation hook implementation called when a `outcome` is created by in place construction. Does nothing.

WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should\!

#### Parameters

  - `  ` &mdash; Some `outcome<...>` being constructed.
  - `  ` &mdash; The type of in place construction occurring.

-----

### Function `outcome_v2_xxx::hooks::override_outcome_exception`

<a id="standardese-outcome_v2_xxx::hooks::override_outcome_exception&lt;R,S,P,NoValuePolicy,U&gt;(outcome&lt;R,S,P,NoValuePolicy&gt;*,U&amp;&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">NoValuePolicy</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="kwd">void</span> <span class="typ dec var fun">override_outcome_exception</span><span class="pun">(</span><a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, NoValuePolicy<span class="pun">&gt;</span><span class="pun">*</span> <span class="typ dec var fun">o</span><span class="pun">,</span> <span class="typ dec var fun">U</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

Used in hook implementations to override the payload/exception to something other than what was constructed.

-----

### Class `outcome_v2_xxx::outcome`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E.R"><span class="typ dec var fun">R</span></a><span class="pun">,</span> <span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E.S"><span class="typ dec var fun">S</span></a><span class="pun">,</span> <span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E.P"><span class="typ dec var fun">P</span></a><span class="pun">,</span> <span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E.NoValuePolicy"><span class="typ dec var fun">NoValuePolicy</span></a><span class="pun">&gt;</span>
<span class="kwd">class</span> <span class="typ dec var fun">outcome</span>
<span class="pun">{</span>
<span class="kwd">public</span><span class="pun">:</span>
    &#x2F;&#x2F;=== Member types ===&#x2F;&#x2F;
    <span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::value_type"><span class="typ dec var fun">value_type</span></a> <span class="pun">=</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E.R"><span class="typ dec var fun">R</span></a><span class="pun">;</span>

    <span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::error_type"><span class="typ dec var fun">error_type</span></a> <span class="pun">=</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E.S"><span class="typ dec var fun">S</span></a><span class="pun">;</span>

    <span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::exception_type"><span class="typ dec var fun">exception_type</span></a> <span class="pun">=</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E.P"><span class="typ dec var fun">P</span></a><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span> <span class="pun">=</span> S<span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">V</span> <span class="pun">=</span> P<span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">W</span> <span class="pun">=</span> policy::default_policy&lt;T,U,V&gt;<span class="pun">&gt;</span>
    <span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::rebind%3CT,U,V,W%3E"><span class="typ dec var fun">rebind</span></a> <span class="pun">=</span> <span class="typ dec var fun">outcome</span><span class="pun">&lt;</span>T, U, V, W<span class="pun">&gt;</span><span class="pun">;</span>

<span class="kwd">protected</span><span class="pun">:</span>
    <span class="kwd">struct</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::predicate"><span class="typ dec var fun">predicate</span></a><span class="pun">;</span>

<span class="kwd">public</span><span class="pun">:</span>
    <span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::value_type_if_enabled"><span class="typ dec var fun">value_type_if_enabled</span></a> <span class="pun">=</span> <span class="typ dec var fun">std::conditional_t</span><span class="pun">&lt;</span>std::is_same&lt;value_type, error_type&gt;::value || std::is_same&lt;value_type, exception_type&gt;::value, disable_in_place_value_type, value_type<span class="pun">&gt;</span><span class="pun">;</span>

    <span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::error_type_if_enabled"><span class="typ dec var fun">error_type_if_enabled</span></a> <span class="pun">=</span> <span class="typ dec var fun">std::conditional_t</span><span class="pun">&lt;</span>std::is_same&lt;error_type, value_type&gt;::value || std::is_same&lt;error_type, exception_type&gt;::value, disable_in_place_error_type, error_type<span class="pun">&gt;</span><span class="pun">;</span>

    <span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::exception_type_if_enabled"><span class="typ dec var fun">exception_type_if_enabled</span></a> <span class="pun">=</span> <span class="typ dec var fun">std::conditional_t</span><span class="pun">&lt;</span>std::is_same&lt;exception_type, value_type&gt;::value || std::is_same&lt;exception_type, error_type&gt;::value, disable_in_place_exception_type, exception_type<span class="pun">&gt;</span><span class="pun">;</span>

<span class="kwd">protected</span><span class="pun">:</span>
    <span class="typ dec var fun">detail::devoid</span><span class="pun">&lt;</span>exception_type<span class="pun">&gt;</span> <span class="typ dec var fun">_ptr</span><span class="pun">;</span>

<span class="kwd">public</span><span class="pun">:</span>
    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,%3E(T&amp;&amp;,outcome_v2_xxx::outcome::value_converting_constructor_tag)"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,%3E(T&amp;&amp;,outcome_v2_xxx::outcome::value_converting_constructor_tag).t"><span class="typ dec var fun">t</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,%3E(T&amp;&amp;,outcome_v2_xxx::outcome::error_converting_constructor_tag)"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,%3E(T&amp;&amp;,outcome_v2_xxx::outcome::error_converting_constructor_tag).t"><span class="typ dec var fun">t</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">ErrorCondEnum</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CErrorCondEnum,,%3E(ErrorCondEnum&amp;&amp;,outcome_v2_xxx::outcome::error_condition_converting_constructor_tag)"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><span class="typ dec var fun">ErrorCondEnum</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CErrorCondEnum,,%3E(ErrorCondEnum&amp;&amp;,outcome_v2_xxx::outcome::error_condition_converting_constructor_tag).t"><span class="typ dec var fun">t</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,%3E(T&amp;&amp;,outcome_v2_xxx::outcome::exception_converting_constructor_tag)"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,%3E(T&amp;&amp;,outcome_v2_xxx::outcome::exception_converting_constructor_tag).t"><span class="typ dec var fun">t</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,,,%3E(T&amp;&amp;,outcome_v2_xxx::outcome::explicit_valueorerror_converting_constructor_tag)"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,,,%3E(T&amp;&amp;,outcome_v2_xxx::outcome::explicit_valueorerror_converting_constructor_tag).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">V</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">W</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,U,V,W,%3E(outcome%3CT,U,V,W%3Econst&amp;)"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><span class="typ dec var fun">outcome</span><span class="pun">&lt;</span>T, U, V, W<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,U,V,W,%3E(outcome%3CT,U,V,W%3Econst&amp;).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">V</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">W</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,U,V,W,%3E(outcome%3CT,U,V,W%3E&amp;&amp;)"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><span class="typ dec var fun">outcome</span><span class="pun">&lt;</span>T, U, V, W<span class="pun">&gt;</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,U,V,W,%3E(outcome%3CT,U,V,W%3E&amp;&amp;).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">V</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,U,V,%3E(result%3CT,U,V%3Econst&amp;)"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><a href="result#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>T, U, V<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,U,V,%3E(result%3CT,U,V%3Econst&amp;).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">V</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,U,V,%3E(result%3CT,U,V%3E&amp;&amp;)"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><a href="result#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>T, U, V<span class="pun">&gt;</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,U,V,%3E(result%3CT,U,V%3E&amp;&amp;).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="pun">...</span> <span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CArgs,%3E(in_place_type_t%3Coutcome_v2_xxx::outcome::value_type_if_enabled%3E,Args&amp;&amp;...)"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><span class="typ dec var fun">in_place_type_t</span><span class="pun">&lt;</span>outcome_v2_xxx::outcome::value_type_if_enabled<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CArgs,%3E(in_place_type_t%3Coutcome_v2_xxx::outcome::value_type_if_enabled%3E,Args&amp;&amp;...)._"><span class="typ dec var fun">_</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CArgs,%3E(in_place_type_t%3Coutcome_v2_xxx::outcome::value_type_if_enabled%3E,Args&amp;&amp;...).args"><span class="typ dec var fun">args</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="pun">...</span> <span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::outcome::value_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...)"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><span class="typ dec var fun">in_place_type_t</span><span class="pun">&lt;</span>outcome_v2_xxx::outcome::value_type_if_enabled<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::outcome::value_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...)._"><span class="typ dec var fun">_</span></a><span class="pun">,</span> <span class="typ dec var fun">std::initializer_list</span><span class="pun">&lt;</span>U<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::outcome::value_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...).il"><span class="typ dec var fun">il</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::outcome::value_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...).args"><span class="typ dec var fun">args</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="pun">...</span> <span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CArgs,%3E(in_place_type_t%3Coutcome_v2_xxx::outcome::error_type_if_enabled%3E,Args&amp;&amp;...)"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><span class="typ dec var fun">in_place_type_t</span><span class="pun">&lt;</span>outcome_v2_xxx::outcome::error_type_if_enabled<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CArgs,%3E(in_place_type_t%3Coutcome_v2_xxx::outcome::error_type_if_enabled%3E,Args&amp;&amp;...)._"><span class="typ dec var fun">_</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CArgs,%3E(in_place_type_t%3Coutcome_v2_xxx::outcome::error_type_if_enabled%3E,Args&amp;&amp;...).args"><span class="typ dec var fun">args</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="pun">...</span> <span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::outcome::error_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...)"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><span class="typ dec var fun">in_place_type_t</span><span class="pun">&lt;</span>outcome_v2_xxx::outcome::error_type_if_enabled<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::outcome::error_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...)._"><span class="typ dec var fun">_</span></a><span class="pun">,</span> <span class="typ dec var fun">std::initializer_list</span><span class="pun">&lt;</span>U<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::outcome::error_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...).il"><span class="typ dec var fun">il</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::outcome::error_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...).args"><span class="typ dec var fun">args</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="pun">...</span> <span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CArgs,%3E(in_place_type_t%3Coutcome_v2_xxx::outcome::exception_type_if_enabled%3E,Args&amp;&amp;...)"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><span class="typ dec var fun">in_place_type_t</span><span class="pun">&lt;</span>outcome_v2_xxx::outcome::exception_type_if_enabled<span class="pun">&gt;</span><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CArgs,%3E(in_place_type_t%3Coutcome_v2_xxx::outcome::exception_type_if_enabled%3E,Args&amp;&amp;...).args"><span class="typ dec var fun">args</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="pun">...</span> <span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::outcome::exception_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...)"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><span class="typ dec var fun">in_place_type_t</span><span class="pun">&lt;</span>outcome_v2_xxx::outcome::exception_type_if_enabled<span class="pun">&gt;</span><span class="pun">,</span> <span class="typ dec var fun">std::initializer_list</span><span class="pun">&lt;</span>U<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::outcome::exception_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...).il"><span class="typ dec var fun">il</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::outcome::exception_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...).args"><span class="typ dec var fun">args</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">A1</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">A2</span><span class="pun">,</span> <span class="kwd">class</span> <span class="pun">...</span> <span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CA1,A2,Args,%3E(A1&amp;&amp;,A2&amp;&amp;,Args&amp;&amp;...)"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><span class="typ dec var fun">A1</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">a1</span><span class="pun">,</span> <span class="typ dec var fun">A2</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">a2</span><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CA1,A2,Args,%3E(A1&amp;&amp;,A2&amp;&amp;,Args&amp;&amp;...).args"><span class="typ dec var fun">args</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome(success_type%3Cvoid%3Econst&amp;)"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx::success_type%3E"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>void<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome(success_type%3Cvoid%3Econst&amp;).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,%3E(success_type%3CT%3Econst&amp;)"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx::success_type%3CT%3E"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>T<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,%3E(success_type%3CT%3Econst&amp;).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,%3E(success_type%3CT%3E&amp;&amp;)"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx::success_type%3CT%3E"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>T<span class="pun">&gt;</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,%3E(success_type%3CT%3E&amp;&amp;).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,U,%3E(failure_type%3CT,U%3Econst&amp;)"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>T, U<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,U,%3E(failure_type%3CT,U%3Econst&amp;).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,U,%3E(failure_type%3CT,U%3E&amp;&amp;)"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>T, U<span class="pun">&gt;</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,U,%3E(failure_type%3CT,U%3E&amp;&amp;).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    &#x2F;&#x2F;=== Comparison operators ===&#x2F;&#x2F;
    <span class="kwd">using</span> <span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">;</span>

    <span class="kwd">using</span> <span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">V</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">W</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <span class="kwd">bool</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::operator==%3CT,U,V,W%3E(outcome%3CT,U,V,W%3Econst&amp;)const"><span class="typ dec var fun">operator==</span></a><span class="pun">(</span><span class="typ dec var fun">outcome</span><span class="pun">&lt;</span>T, U, V, W<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::operator==%3CT,U,V,W%3E(outcome%3CT,U,V,W%3Econst&amp;)const.o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">const</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <span class="kwd">bool</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::operator==%3CT,U%3E(failure_type%3CT,U%3Econst&amp;)const"><span class="typ dec var fun">operator==</span></a><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>T, U<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::operator==%3CT,U%3E(failure_type%3CT,U%3Econst&amp;)const.o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">const</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">V</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">W</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <span class="kwd">bool</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::operator!=%3CT,U,V,W%3E(outcome%3CT,U,V,W%3Econst&amp;)const"><span class="typ dec var fun">operator!=</span></a><span class="pun">(</span><span class="typ dec var fun">outcome</span><span class="pun">&lt;</span>T, U, V, W<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::operator!=%3CT,U,V,W%3E(outcome%3CT,U,V,W%3Econst&amp;)const.o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">const</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <span class="kwd">bool</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::operator!=%3CT,U%3E(failure_type%3CT,U%3Econst&amp;)const"><span class="typ dec var fun">operator!=</span></a><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>T, U<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::operator!=%3CT,U%3E(failure_type%3CT,U%3Econst&amp;)const.o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">const</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::swap(outcome%3CR,S,P,NoValuePolicy%3E&amp;)"><span class="typ dec var fun">swap</span></a><span class="pun">(</span>outcome&lt;R, S, P, NoValuePolicy&gt;<span class="pun">&amp;</span> <span class="typ dec var fun">o</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <a href="success_failure#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>outcome_v2_xxx::outcome::error_type, outcome_v2_xxx::outcome::exception_type<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::as_failure()const&amp;"><span class="typ dec var fun">as_failure</span></a><span class="pun">(</span><span class="pun">)</span> <span class="kwd">const</span> <span class="pun">&amp;</span><span class="pun">;</span>

    <a href="success_failure#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>outcome_v2_xxx::outcome::error_type, outcome_v2_xxx::outcome::exception_type<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::as_failure()&amp;&amp;"><span class="typ dec var fun">as_failure</span></a><span class="pun">(</span><span class="pun">)</span> <span class="pun">&amp;&amp;</span><span class="pun">;</span>
<span class="pun">};</span>
</code></pre>

Used to return from functions one of (i) a successful value (ii) a cause of failure (ii) a different cause of failure. `constexpr` capable.

This is an extension of `result<R, S>` and it allows an alternative failure to be stored of type `P`, which can be observed with the member functions `.exception()` and `.assume_exception()`. The `P` state takes precedence during no-value observation over any `S` state, and it is possible to store `S + P` simultaneously such that `outcome` could have any one the states:

1.  `R` (`value_type`)

2.  `S` (`error_type`)

3.  `P` (`exception_type`)

4.  `S + P` (`error_type + exception_type`)

Similarly to `result`, `NoValuePolicy` defaults to a policy selected according to the characteristics of types `S` and `P`:

1.  If `.value()` called when there is no `value_type` but there is an `exception_type`:

<!-- end list -->

  - If `trait::has_exception_ptr_v<P>`, then `std::rethrow_exception(exception()|make_exception_ptr(exception()))` \[`policy::exception_ptr_rethrow<R, S, P>`\]

<!-- end list -->

1.  If `.value()` called when there is no `value_type` but there is an `error_type`:

<!-- end list -->

  - If `trait::has_error_code_v<S>` is true, then `throw std::system_error(error()|make_error_code(error()))` \[\\verbatim {{\<api “policies/result\_error\_code\_throw\_as\_system\_error” “policy::error\_code\_throw\_as\_system\_error\<S\>”\>}} \\endverbatim\]

  - If `trait::has_exception_ptr_v<S>`, then `std::rethrow_exception(error()|make_exception_ptr(error()))` \[`policy::exception_ptr_rethrow<R, S, void>`\]

  - If `S` is `void`, call `std::terminate()` \[`policy::terminate`\]

  - If `S` is none of the above, then it is undefined behaviour \[`policy::all_narrow`\]

<!-- end list -->

1.  If `.exception()` called when there is no `exception_type`:

<!-- end list -->

  - If `trait::has_exception_ptr_v<P>`, or if `P` is `void`, do `throw bad_outcome_access()`

  - If `P` is none of the above, then it is undefined behaviour \[`policy::all_narrow`\]

<!-- end list -->

1.  If `.error()` called when there is no `error_type`:

<!-- end list -->

  - If `trait::has_error_code_v<S>`, or if `trait::has_exception_ptr_v<S>`, or if `S` is `void`, do `throw bad_outcome_access()`

  - If `S` is none of the above, then it is undefined behaviour \[`policy::all_narrow`\]

#### Template parameters

  - `NoValuePolicy` &mdash; Policy on how to interpret types `S` and `P` when a wide observation of a not present value occurs.

### Template parameter `R`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;.R"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">class</span> <span class="typ dec var fun">R</span></code></pre>

The optional type of the successful result (use `void` to disable).

Cannot be a reference, a `in_place_type_t<>`, `success<>`, `failure<>`, an array, a function or non-destructible.

-----

### Template parameter `S`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;.S"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">class</span> <span class="typ dec var fun">S</span></code></pre>

The optional type of the first failure result (use `void` to disable). Must be either `void` or `DefaultConstructible`.

Cannot be a reference, a `in_place_type_t<>`, `success<>`, `failure<>`, an array, a function or non-destructible.

-----

### Template parameter `P`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;.P"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">class</span> <span class="typ dec var fun">P</span></code></pre>

The optional type of the second failure result (use `void` to disable). Must be either `void` or `DefaultConstructible`.

Cannot be a reference, a `in_place_type_t<>`, `success<>`, `failure<>`, an array, a function or non-destructible.

-----

### Type alias `value_type`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::value_type"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">using</span> <span class="typ dec var fun">value_type</span> <span class="pun">=</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E.R"><span class="typ dec var fun">R</span></a><span class="pun">;</span>
</code></pre>

The success type.

-----

### Type alias `error_type`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::error_type"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">using</span> <span class="typ dec var fun">error_type</span> <span class="pun">=</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E.S"><span class="typ dec var fun">S</span></a><span class="pun">;</span>
</code></pre>

The failure type.

-----

### Type alias `exception_type`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::exception_type"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">using</span> <span class="typ dec var fun">exception_type</span> <span class="pun">=</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E.P"><span class="typ dec var fun">P</span></a><span class="pun">;</span>
</code></pre>

The exception type

-----

### Alias template `rebind`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::rebind&lt;T,U,V,W&gt;"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span> <span class="pun">=</span> S<span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">V</span> <span class="pun">=</span> P<span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">W</span> <span class="pun">=</span> policy::default_policy&lt;T,U,V&gt;<span class="pun">&gt;</span>
<span class="kwd">using</span> <span class="typ dec var fun">rebind</span> <span class="pun">=</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>T, U, V, W<span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

Used to rebind this outcome to a different outcome type

-----

### Struct `predicate`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::predicate"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">struct</span> <span class="typ dec var fun">predicate</span>
<span class="pun">{</span>
    <span class="kwd">using</span> <span class="typ dec var fun">base</span> <span class="pun">=</span> <span class="typ dec var fun">detail::outcome_predicates</span><span class="pun">&lt;</span>value_type, error_type, exception_type<span class="pun">&gt;</span><span class="pun">;</span>

    <span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span> <span class="kwd">T</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">enable_value_converting_constructor</span> <span class="pun">=</span> <span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">,</span> <span class="kwd">outcome</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span> <span class="pun">&amp;&amp;</span> <span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>  <span class="kwd">enable_value_converting_constructor</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">;</span>

    <span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span> <span class="kwd">T</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">enable_error_converting_constructor</span> <span class="pun">=</span> <span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">,</span> <span class="kwd">outcome</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span> <span class="pun">&amp;&amp;</span> <span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>  <span class="kwd">enable_error_converting_constructor</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">;</span>

    <span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span> <span class="kwd">ErrorCondEnum</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">enable_error_condition_converting_constructor</span> <span class="pun">=</span> <span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">ErrorCondEnum</span><span class="pun">&gt;</span><span class="pun">,</span> <span class="kwd">outcome</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span> <span class="pun">&amp;&amp;</span> <span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>  <span class="kwd">enable_error_condition_converting_constructor</span><span class="pun">&lt;</span><span class="kwd">ErrorCondEnum</span><span class="pun">&gt;</span><span class="pun">;</span>

    <span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span> <span class="kwd">T</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">enable_exception_converting_constructor</span> <span class="pun">=</span> <span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">,</span> <span class="kwd">outcome</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span> <span class="pun">&amp;&amp;</span> <span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>  <span class="kwd">enable_exception_converting_constructor</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">;</span>

    <span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span> <span class="kwd">T</span><span class="pun">,</span> <span class="typ dec var fun">class</span> <span class="kwd">U</span><span class="pun">,</span> <span class="typ dec var fun">class</span> <span class="kwd">V</span><span class="pun">,</span> <span class="typ dec var fun">class</span> <span class="kwd">W</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">enable_compatible_conversion</span> <span class="pun">=</span> <span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">outcome</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">,</span> <span class="kwd">U</span><span class="pun">,</span> <span class="kwd">V</span><span class="pun">,</span> <span class="kwd">W</span><span class="pun">&gt;</span><span class="pun">,</span> <span class="kwd">outcome</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span> <span class="pun">&amp;&amp;</span> <span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>  <span class="kwd">enable_compatible_conversion</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">,</span> <span class="kwd">U</span><span class="pun">,</span> <span class="kwd">V</span><span class="pun">,</span> <span class="kwd">W</span><span class="pun">&gt;</span><span class="pun">;</span>

    <span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span><span class="pun">...</span><span class="kwd">Args</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">enable_inplace_value_constructor</span> <span class="pun">=</span> <span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_void</span><span class="pun">&lt;</span><span class="kwd">value_type</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span> <span class="pun">||</span> <span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_constructible</span><span class="pun">&lt;</span><span class="kwd">value_type</span><span class="pun">,</span> <span class="kwd">Args</span><span class="pun">...</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>

    <span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span><span class="pun">...</span><span class="kwd">Args</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">enable_inplace_error_constructor</span> <span class="pun">=</span> <span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_void</span><span class="pun">&lt;</span><span class="kwd">error_type</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span> <span class="pun">||</span> <span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_constructible</span><span class="pun">&lt;</span><span class="kwd">error_type</span><span class="pun">,</span> <span class="kwd">Args</span><span class="pun">...</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>

    <span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span><span class="pun">...</span><span class="kwd">Args</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">enable_inplace_exception_constructor</span> <span class="pun">=</span> <span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_void</span><span class="pun">&lt;</span><span class="kwd">exception_type</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span> <span class="pun">||</span> <span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_constructible</span><span class="pun">&lt;</span><span class="kwd">exception_type</span><span class="pun">,</span> <span class="kwd">Args</span><span class="pun">...</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>

    <span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span><span class="pun">...</span><span class="kwd">Args</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">enable_inplace_value_error_exception_constructor</span> <span class="pun">=</span> <span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>  <span class="kwd">enable_inplace_value_error_exception_constructor</span><span class="pun">&lt;</span><span class="kwd">Args</span><span class="pun">...</span><span class="pun">&gt;</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="pun">...</span> <span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
    <span class="kwd">using</span> <span class="typ dec var fun">choose_inplace_value_error_exception_constructor</span> <span class="pun">=</span> typename base::choose_inplace_value_error_exception_constructor&lt;Args...&gt;<span class="pun">;</span>
<span class="pun">};</span>
</code></pre>

Requirement predicates for outcome.

### Unexposed entity `enable_value_converting_constructor`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::predicate::enable_value_converting_constructor"></a>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span> <span class="kwd">T</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">enable_value_converting_constructor</span> <span class="pun">=</span> <span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">,</span> <span class="kwd">outcome</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span> <span class="pun">&amp;&amp;</span> <span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>  <span class="kwd">enable_value_converting_constructor</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

Predicate for the value converting constructor to be available.

-----

### Unexposed entity `enable_error_converting_constructor`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::predicate::enable_error_converting_constructor"></a>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span> <span class="kwd">T</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">enable_error_converting_constructor</span> <span class="pun">=</span> <span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">,</span> <span class="kwd">outcome</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span> <span class="pun">&amp;&amp;</span> <span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>  <span class="kwd">enable_error_converting_constructor</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

Predicate for the error converting constructor to be available.

-----

### Unexposed entity `enable_error_condition_converting_constructor`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::predicate::enable_error_condition_converting_constructor"></a>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span> <span class="kwd">ErrorCondEnum</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">enable_error_condition_converting_constructor</span> <span class="pun">=</span> <span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">ErrorCondEnum</span><span class="pun">&gt;</span><span class="pun">,</span> <span class="kwd">outcome</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span> <span class="pun">&amp;&amp;</span> <span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>  <span class="kwd">enable_error_condition_converting_constructor</span><span class="pun">&lt;</span><span class="kwd">ErrorCondEnum</span><span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

Predicate for the error condition converting constructor to be available.

-----

### Unexposed entity `enable_compatible_conversion`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::predicate::enable_compatible_conversion"></a>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span> <span class="kwd">T</span><span class="pun">,</span> <span class="typ dec var fun">class</span> <span class="kwd">U</span><span class="pun">,</span> <span class="typ dec var fun">class</span> <span class="kwd">V</span><span class="pun">,</span> <span class="typ dec var fun">class</span> <span class="kwd">W</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">enable_compatible_conversion</span> <span class="pun">=</span> <span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">outcome</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">,</span> <span class="kwd">U</span><span class="pun">,</span> <span class="kwd">V</span><span class="pun">,</span> <span class="kwd">W</span><span class="pun">&gt;</span><span class="pun">,</span> <span class="kwd">outcome</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span> <span class="pun">&amp;&amp;</span> <span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>  <span class="kwd">enable_compatible_conversion</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">,</span> <span class="kwd">U</span><span class="pun">,</span> <span class="kwd">V</span><span class="pun">,</span> <span class="kwd">W</span><span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

Predicate for the converting constructor from a compatible input to be available.

-----

### Unexposed entity `enable_inplace_value_constructor`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::predicate::enable_inplace_value_constructor"></a>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span><span class="pun">...</span><span class="kwd">Args</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">enable_inplace_value_constructor</span> <span class="pun">=</span> <span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_void</span><span class="pun">&lt;</span><span class="kwd">value_type</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span> <span class="pun">||</span> <span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_constructible</span><span class="pun">&lt;</span><span class="kwd">value_type</span><span class="pun">,</span> <span class="kwd">Args</span><span class="pun">...</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>
</code></pre>

Predicate for the inplace construction of value to be available.

-----

### Unexposed entity `enable_inplace_error_constructor`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::predicate::enable_inplace_error_constructor"></a>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span><span class="pun">...</span><span class="kwd">Args</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">enable_inplace_error_constructor</span> <span class="pun">=</span> <span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_void</span><span class="pun">&lt;</span><span class="kwd">error_type</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span> <span class="pun">||</span> <span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_constructible</span><span class="pun">&lt;</span><span class="kwd">error_type</span><span class="pun">,</span> <span class="kwd">Args</span><span class="pun">...</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>
</code></pre>

Predicate for the inplace construction of error to be available.

-----

### Unexposed entity `enable_inplace_exception_constructor`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::predicate::enable_inplace_exception_constructor"></a>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span><span class="pun">...</span><span class="kwd">Args</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span> <span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">enable_inplace_exception_constructor</span> <span class="pun">=</span> <span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_void</span><span class="pun">&lt;</span><span class="kwd">exception_type</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span> <span class="pun">||</span> <span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_constructible</span><span class="pun">&lt;</span><span class="kwd">exception_type</span><span class="pun">,</span> <span class="kwd">Args</span><span class="pun">...</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>
</code></pre>

Predicate for the inplace construction of exception to be available.

-----

-----

### Type alias `value_type_if_enabled`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::value_type_if_enabled"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">using</span> <span class="typ dec var fun">value_type_if_enabled</span> <span class="pun">=</span> <span class="typ dec var fun">std::conditional_t</span><span class="pun">&lt;</span>std::is_same&lt;value_type, error_type&gt;::value || std::is_same&lt;value_type, exception_type&gt;::value, disable_in_place_value_type, value_type<span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

Used to disable in place type construction when `value_type` is ambiguous with `error_type` or `exception_type`.

-----

### Type alias `error_type_if_enabled`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::error_type_if_enabled"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">using</span> <span class="typ dec var fun">error_type_if_enabled</span> <span class="pun">=</span> <span class="typ dec var fun">std::conditional_t</span><span class="pun">&lt;</span>std::is_same&lt;error_type, value_type&gt;::value || std::is_same&lt;error_type, exception_type&gt;::value, disable_in_place_error_type, error_type<span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

Used to disable in place type construction when `error_type` is ambiguous with `value_type` or `exception_type`.

-----

### Type alias `exception_type_if_enabled`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::exception_type_if_enabled"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">using</span> <span class="typ dec var fun">exception_type_if_enabled</span> <span class="pun">=</span> <span class="typ dec var fun">std::conditional_t</span><span class="pun">&lt;</span>std::is_same&lt;exception_type, value_type&gt;::value || std::is_same&lt;exception_type, error_type&gt;::value, disable_in_place_exception_type, exception_type<span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

Used to disable in place type construction when `exception_type` is ambiguous with `value_type` or `error_type`.

-----

### Constructor `outcome`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::outcome&lt;T,&gt;(T&amp;&amp;,outcome_v2_xxx::outcome::value_converting_constructor_tag)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">outcome</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,%3E(T&amp;&amp;,outcome_v2_xxx::outcome::value_converting_constructor_tag).t"><span class="typ dec var fun">t</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Converting constructor to a successful outcome.

*Effects:* Initialises the outcome with a `value_type`.

*Requires:* Type T is implicitly constructible to `value_type`, is not implicitly constructible to `error_type`, is not implicitly constructible to `exception_type` and is not `outcome<R, S, P>` and not `in_place_type<>`.

*Throws:* Any exception the construction of `value_type(T)` might throw.

#### Parameters

  - `t` &mdash; The value from which to initialise the `value_type`.

-----

### Constructor `outcome`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::outcome&lt;T,&gt;(T&amp;&amp;,outcome_v2_xxx::outcome::error_converting_constructor_tag)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">outcome</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,%3E(T&amp;&amp;,outcome_v2_xxx::outcome::error_converting_constructor_tag).t"><span class="typ dec var fun">t</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Converting constructor to an errored outcome.

*Effects:* Initialises the outcome with a `error_type`.

*Requires:* Type T is implicitly constructible to `error_type`, is not implicitly constructible to `value_type`, is not implicitly constructible to `exception_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`.

*Throws:* Any exception the construction of `error_type(T)` might throw.

#### Parameters

  - `t` &mdash; The value from which to initialise the `error_type`.

-----

### Constructor `outcome`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::outcome&lt;ErrorCondEnum,,&gt;(ErrorCondEnum&amp;&amp;,outcome_v2_xxx::outcome::error_condition_converting_constructor_tag)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">ErrorCondEnum</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">outcome</span><span class="pun">(</span><span class="typ dec var fun">ErrorCondEnum</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CErrorCondEnum,,%3E(ErrorCondEnum&amp;&amp;,outcome_v2_xxx::outcome::error_condition_converting_constructor_tag).t"><span class="typ dec var fun">t</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Special error condition converting constructor to an errored outcome.

*Effects:* Initialises the outcome with a `error_type` constructed via `make_error_code(t)`.

*Requires:* `std::is_error_condition_enum<ErrorCondEnum>` must be true, `ErrorCondEnum` is not implicitly constructible to `value_type`, `error_type` nor `exception_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`; Finally, the expression `error_type(make_error_code(ErrorCondEnum()))` must be valid.

*Throws:* Any exception the construction of `error_type(make_error_code(t))` might throw.

#### Parameters

  - `t` &mdash; The error condition from which to initialise the `error_type`.

-----

### Constructor `outcome`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::outcome&lt;T,&gt;(T&amp;&amp;,outcome_v2_xxx::outcome::exception_converting_constructor_tag)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">outcome</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,%3E(T&amp;&amp;,outcome_v2_xxx::outcome::exception_converting_constructor_tag).t"><span class="typ dec var fun">t</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Converting constructor to an excepted outcome.

*Effects:* Initialises the outcome with a `exception_type`.

*Requires:* `trait::is_exception_ptr<P>` must be true; Type T is implicitly constructible to `exception_type`, is not implicitly constructible to `value_type`, is not implicitly constructible to `error_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`.

*Throws:* Any exception the construction of `exception_type(T)` might throw.

#### Parameters

  - `t` &mdash; The value from which to initialise the `exception_type`.

-----

### Constructor `outcome`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::outcome&lt;T,,,&gt;(T&amp;&amp;,outcome_v2_xxx::outcome::explicit_valueorerror_converting_constructor_tag)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">outcome</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,,,%3E(T&amp;&amp;,outcome_v2_xxx::outcome::explicit_valueorerror_converting_constructor_tag).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Explicit converting constructor from a compatible `ValueOrError` type.

*Effects:* Initialises the outcome with the contents of the compatible input.

*Requires:* That `convert::value_or_error<outcome, std::decay_t<T>>{}(std::forward<T>(o))` be available. The default implementation will consume `T`’s matching the `ValueOrError` concept type. `ValueOrError` concept matches any type with a `value_type`, an `error_type`, a `.value()`, an `.error()` and a `.has_value()`.

#### Parameters

  - `o` &mdash; The input for which a `convert::value_or_error<outcome, std::decay_t<T>>{}(std::forward<T>(o))` is available.

-----

### Constructor `outcome`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::outcome&lt;T,U,V,W,&gt;(outcome&lt;T,U,V,W&gt;const&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">V</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">W</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">outcome</span><span class="pun">(</span><a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>T, U, V, W<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,U,V,W,%3E(outcome%3CT,U,V,W%3Econst&amp;).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Explicit converting copy constructor from a compatible outcome type.

*Effects:* Initialises the outcome with a copy of the compatible outcome.

*Requires:* Both outcome’s `value_type`, `error_type`, and `exception_type` need to be constructible, or the source `void`.

*Throws:* Any exception the construction of `value_type(T)`, `error_type(U)` or `exception_type(V)` might throw.

#### Parameters

  - `o` &mdash; The compatible outcome.

-----

### Constructor `outcome`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::outcome&lt;T,U,V,W,&gt;(outcome&lt;T,U,V,W&gt;&amp;&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">V</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">W</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">outcome</span><span class="pun">(</span><a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>T, U, V, W<span class="pun">&gt;</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,U,V,W,%3E(outcome%3CT,U,V,W%3E&amp;&amp;).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Explicit converting move constructor from a compatible outcome type.

*Effects:* Initialises the outcome with a move of the compatible outcome.

*Requires:* Both outcome’s `value_type`, `error_type`, and `exception_type` need to be constructible, or the source `void`.

*Throws:* Any exception the construction of `value_type(T)`, `error_type(U)` or `exception_type(V)` might throw.

#### Parameters

  - `o` &mdash; The compatible outcome.

-----

### Constructor `outcome`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::outcome&lt;T,U,V,&gt;(result&lt;T,U,V&gt;const&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">V</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">outcome</span><span class="pun">(</span><a href="result#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>T, U, V<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,U,V,%3E(result%3CT,U,V%3Econst&amp;).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Explicit converting copy constructor from a compatible result type.

*Effects:* Initialises the outcome with a copy of the compatible result.

*Requires:* Both outcome’s `value_type` and `error_type` need to be constructible, or the source `void`.

*Throws:* Any exception the construction of `value_type(T)`, `error_type(U)` or `exception_type()` might throw.

#### Parameters

  - `o` &mdash; The compatible result.

-----

### Constructor `outcome`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::outcome&lt;T,U,V,&gt;(result&lt;T,U,V&gt;&amp;&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">V</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">outcome</span><span class="pun">(</span><a href="result#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>T, U, V<span class="pun">&gt;</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,U,V,%3E(result%3CT,U,V%3E&amp;&amp;).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Explicit converting move constructor from a compatible result type.

*Effects:* Initialises the outcome with a move of the compatible result.

*Requires:* Both outcome’s `value_type` and `error_type` need to be constructible, or the source `void`.

*Throws:* Any exception the construction of `value_type(T)`, `error_type(U)` or `exception_type()` might throw.

#### Parameters

  - `o` &mdash; The compatible result.

-----

### Constructor `outcome`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::outcome&lt;Args,&gt;(in_place_type_t&lt;outcome_v2_xxx::outcome::value_type_if_enabled&gt;,Args&amp;&amp;...)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="pun">...</span> <span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">outcome</span><span class="pun">(</span><span class="typ dec var fun">in_place_type_t</span><span class="pun">&lt;</span>outcome_v2_xxx::outcome::value_type_if_enabled<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CArgs,%3E(in_place_type_t%3Coutcome_v2_xxx::outcome::value_type_if_enabled%3E,Args&amp;&amp;...)._"><span class="typ dec var fun">_</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CArgs,%3E(in_place_type_t%3Coutcome_v2_xxx::outcome::value_type_if_enabled%3E,Args&amp;&amp;...).args"><span class="typ dec var fun">args</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Inplace constructor to a successful value.

*Effects:* Initialises the outcome with a `value_type`.

*Requires:* `value_type` is void or `Args...` are constructible to `value_type`.

*Throws:* Any exception the construction of `value_type(Args...)` might throw.

#### Parameters

  - `_` &mdash; Tag type to indicate we are doing in place construction of `value_type`.
  - `args` &mdash; Arguments with which to in place construct.

-----

### Constructor `outcome`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::outcome&lt;U,Args,&gt;(in_place_type_t&lt;outcome_v2_xxx::outcome::value_type_if_enabled&gt;,std::initializer_list&lt;U&gt;,Args&amp;&amp;...)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="pun">...</span> <span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">outcome</span><span class="pun">(</span><span class="typ dec var fun">in_place_type_t</span><span class="pun">&lt;</span>outcome_v2_xxx::outcome::value_type_if_enabled<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::outcome::value_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...)._"><span class="typ dec var fun">_</span></a><span class="pun">,</span> <span class="typ dec var fun">std::initializer_list</span><span class="pun">&lt;</span>U<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::outcome::value_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...).il"><span class="typ dec var fun">il</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::outcome::value_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...).args"><span class="typ dec var fun">args</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Inplace constructor to a successful value.

*Effects:* Initialises the outcome with a `value_type`.

*Requires:* The initializer list + `Args...` are constructible to `value_type`.

*Throws:* Any exception the construction of `value_type(il, Args...)` might throw.

#### Parameters

  - `_` &mdash; Tag type to indicate we are doing in place construction of `value_type`.
  - `il` &mdash; An initializer list with which to in place construct.
  - `args` &mdash; Arguments with which to in place construct.

-----

### Constructor `outcome`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::outcome&lt;Args,&gt;(in_place_type_t&lt;outcome_v2_xxx::outcome::error_type_if_enabled&gt;,Args&amp;&amp;...)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="pun">...</span> <span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">outcome</span><span class="pun">(</span><span class="typ dec var fun">in_place_type_t</span><span class="pun">&lt;</span>outcome_v2_xxx::outcome::error_type_if_enabled<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CArgs,%3E(in_place_type_t%3Coutcome_v2_xxx::outcome::error_type_if_enabled%3E,Args&amp;&amp;...)._"><span class="typ dec var fun">_</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CArgs,%3E(in_place_type_t%3Coutcome_v2_xxx::outcome::error_type_if_enabled%3E,Args&amp;&amp;...).args"><span class="typ dec var fun">args</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Inplace constructor to an unsuccessful error.

*Effects:* Initialises the outcome with a `error_type`.

*Requires:* `error_type` is void or `Args...` are constructible to `error_type`.

*Throws:* Any exception the construction of `error_type(Args...)` might throw.

#### Parameters

  - `_` &mdash; Tag type to indicate we are doing in place construction of `error_type`.
  - `args` &mdash; Arguments with which to in place construct.

-----

### Constructor `outcome`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::outcome&lt;U,Args,&gt;(in_place_type_t&lt;outcome_v2_xxx::outcome::error_type_if_enabled&gt;,std::initializer_list&lt;U&gt;,Args&amp;&amp;...)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="pun">...</span> <span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">outcome</span><span class="pun">(</span><span class="typ dec var fun">in_place_type_t</span><span class="pun">&lt;</span>outcome_v2_xxx::outcome::error_type_if_enabled<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::outcome::error_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...)._"><span class="typ dec var fun">_</span></a><span class="pun">,</span> <span class="typ dec var fun">std::initializer_list</span><span class="pun">&lt;</span>U<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::outcome::error_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...).il"><span class="typ dec var fun">il</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::outcome::error_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...).args"><span class="typ dec var fun">args</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Inplace constructor to an unsuccessful error.

*Effects:* Initialises the outcome with a `error_type`.

*Requires:* The initializer list + `Args...` are constructible to `error_type`.

*Throws:* Any exception the construction of `error_type(il, Args...)` might throw.

#### Parameters

  - `_` &mdash; Tag type to indicate we are doing in place construction of `error_type`.
  - `il` &mdash; An initializer list with which to in place construct.
  - `args` &mdash; Arguments with which to in place construct.

-----

### Constructor `outcome`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::outcome&lt;Args,&gt;(in_place_type_t&lt;outcome_v2_xxx::outcome::exception_type_if_enabled&gt;,Args&amp;&amp;...)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="pun">...</span> <span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">outcome</span><span class="pun">(</span><span class="typ dec var fun">in_place_type_t</span><span class="pun">&lt;</span>outcome_v2_xxx::outcome::exception_type_if_enabled<span class="pun">&gt;</span><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CArgs,%3E(in_place_type_t%3Coutcome_v2_xxx::outcome::exception_type_if_enabled%3E,Args&amp;&amp;...).args"><span class="typ dec var fun">args</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Inplace constructor to an unsuccessful exception.

*Effects:* Initialises the outcome with an `exception_type`.

*Requires:* `exception_type` is void or `Args...` are constructible to `exception_type`.

*Throws:* Any exception the construction of `exception_type(Args...)` might throw.

#### Parameters

  - `args` &mdash; Arguments with which to in place construct.

-----

### Constructor `outcome`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::outcome&lt;U,Args,&gt;(in_place_type_t&lt;outcome_v2_xxx::outcome::exception_type_if_enabled&gt;,std::initializer_list&lt;U&gt;,Args&amp;&amp;...)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="pun">...</span> <span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">outcome</span><span class="pun">(</span><span class="typ dec var fun">in_place_type_t</span><span class="pun">&lt;</span>outcome_v2_xxx::outcome::exception_type_if_enabled<span class="pun">&gt;</span><span class="pun">,</span> <span class="typ dec var fun">std::initializer_list</span><span class="pun">&lt;</span>U<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::outcome::exception_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...).il"><span class="typ dec var fun">il</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CU,Args,%3E(in_place_type_t%3Coutcome_v2_xxx::outcome::exception_type_if_enabled%3E,std::initializer_list%3CU%3E,Args&amp;&amp;...).args"><span class="typ dec var fun">args</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Inplace constructor to an unsuccessful exception.

*Effects:* Initialises the outcome with an `exception_type`.

*Requires:* The initializer list + `Args...` are constructible to `exception_type`.

*Throws:* Any exception the construction of `exception_type(il, Args...)` might throw.

#### Parameters

  - `il` &mdash; An initializer list with which to in place construct.
  - `args` &mdash; Arguments with which to in place construct.

-----

### Constructor `outcome`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::outcome&lt;A1,A2,Args,&gt;(A1&amp;&amp;,A2&amp;&amp;,Args&amp;&amp;...)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">A1</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">A2</span><span class="pun">,</span> <span class="kwd">class</span> <span class="pun">...</span> <span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">outcome</span><span class="pun">(</span><span class="typ dec var fun">A1</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">a1</span><span class="pun">,</span> <span class="typ dec var fun">A2</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">a2</span><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CA1,A2,Args,%3E(A1&amp;&amp;,A2&amp;&amp;,Args&amp;&amp;...).args"><span class="typ dec var fun">args</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Implicit inplace constructor to successful value, or unsuccessful error, or unsuccessful exception.

*Effects:* Calls the appropriate `in_place_type_t<...>` constructor depending on constructibility of args.

*Requires:* That the args can construct exactly one of `value_type` or `error_type` or `exception_type`.

*Throws:* Any exception the `in_place_type_t<...>` constructor might throw.

#### Parameters

  - `args` &mdash; Arguments with which to in place construct.

-----

### Constructor `outcome`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::outcome(success_type&lt;void&gt;const&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">constexpr</span> <span class="typ dec var fun">outcome</span><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx::success_type%3E"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>void<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome(success_type%3Cvoid%3Econst&amp;).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Implicit tagged constructor of a successful outcome.

*Effects:* Initialises the outcome with a default constructed success type.

*Requires:* `value_type` to be default constructible, or `void`.

*Throws:* Any exception the construction of `value_type()` might throw.

#### Parameters

  - `o` &mdash; The compatible success type sugar.

-----

### Constructor `outcome`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::outcome&lt;T,&gt;(success_type&lt;T&gt;const&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">outcome</span><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx::success_type%3CT%3E"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>T<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,%3E(success_type%3CT%3Econst&amp;).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Implicit tagged constructor of a successful outcome.

*Effects:* Initialises the outcome with a copy of the value in the type sugar.

*Requires:* Both outcome and success’ `value_type` need to be constructible. The source cannot be `void`.

*Throws:* Any exception the construction of `value_type(T)` might throw.

#### Parameters

  - `o` &mdash; The compatible success type sugar.

-----

### Constructor `outcome`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::outcome&lt;T,&gt;(success_type&lt;T&gt;&amp;&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">outcome</span><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx::success_type%3CT%3E"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>T<span class="pun">&gt;</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,%3E(success_type%3CT%3E&amp;&amp;).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Implicit tagged constructor of a successful outcome.

*Effects:* Initialises the outcome with a move of the value in the type sugar.

*Requires:* Both outcome and success’ `value_type` need to be constructible. The source cannot be `void`.

*Throws:* Any exception the construction of `value_type(T)` might throw.

#### Parameters

  - `o` &mdash; The compatible success type sugar.

-----

### Constructor `outcome`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::outcome&lt;T,U,&gt;(failure_type&lt;T,U&gt;const&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">outcome</span><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>T, U<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,U,%3E(failure_type%3CT,U%3Econst&amp;).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Implicit tagged constructor of a failure outcome.

*Effects:* Initialises the outcome with a copy of the error and/or exception in the type sugar.

*Requires:* Both outcome and failure’s `error_type` and `exception_type` need to be constructible, or the source can be `void`.

*Throws:* Any exception the construction of `error_type(T)` and/or `exception_type(U)` might throw.

#### Parameters

  - `o` &mdash; The compatible failure type sugar.

-----

### Constructor `outcome`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::outcome&lt;T,U,&gt;(failure_type&lt;T,U&gt;&amp;&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="typ dec var fun">outcome</span><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>T, U<span class="pun">&gt;</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::outcome%3CT,U,%3E(failure_type%3CT,U%3E&amp;&amp;).o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Implicit tagged constructor of a failure outcome.

*Effects:* Initialises the outcome with a copy of the error and/or exception in the type sugar.

*Requires:* Both outcome and failure’s `error_type` and `exception_type` need to be constructible, or the source can be `void`.

*Throws:* Any exception the construction of `error_type(T)` and/or `exception_type(U)` might throw.

#### Parameters

  - `o` &mdash; The compatible failure type sugar.

-----

### Function `operator==`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::operator==&lt;T,U,V,W&gt;(outcome&lt;T,U,V,W&gt;const&amp;)const"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">V</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">W</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="kwd">bool</span> <span class="typ dec var fun">operator==</span><span class="pun">(</span><a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>T, U, V, W<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::operator==%3CT,U,V,W%3E(outcome%3CT,U,V,W%3Econst&amp;)const.o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">const</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

True if equal to the other outcome.

*Effects:* If a valid expression to do so, calls the `operator==` operation on each of the three stored items returning true if both are true. Otherwise returns false.

*Throws:* Any exception the individual `operator==` operations might throw.

#### Parameters

  - `o` &mdash; The other outcome to compare to.

-----

### Function `operator==`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::operator==&lt;T,U&gt;(failure_type&lt;T,U&gt;const&amp;)const"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="kwd">bool</span> <span class="typ dec var fun">operator==</span><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>T, U<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::operator==%3CT,U%3E(failure_type%3CT,U%3Econst&amp;)const.o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">const</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

True if equal to the failure type sugar.

*Effects:* If a valid expression to do so, calls the `operator==` operation on the failure items returning true if equal. Otherwise returns false.

*Throws:* Any exception the `operator==` operations might throw.

#### Parameters

  - `o` &mdash; The failure type sugar to compare to.

-----

### Function `operator!=`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::operator!=&lt;T,U,V,W&gt;(outcome&lt;T,U,V,W&gt;const&amp;)const"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">V</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">W</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="kwd">bool</span> <span class="typ dec var fun">operator!=</span><span class="pun">(</span><a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>T, U, V, W<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::operator!=%3CT,U,V,W%3E(outcome%3CT,U,V,W%3Econst&amp;)const.o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">const</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

True if not equal to the other outcome.

*Effects:* If a valid expression to do so, calls the `operator!=` operation on each of the three stored items, returning true if any are not equal. Otherwise returns true.

*Throws:* Any exception the individual `operator!=` operations might throw.

#### Parameters

  - `o` &mdash; The other outcome to compare to.

-----

### Function `operator!=`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::operator!=&lt;T,U&gt;(failure_type&lt;T,U&gt;const&amp;)const"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="kwd">bool</span> <span class="typ dec var fun">operator!=</span><span class="pun">(</span><a href="success_failure#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>T, U<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E::operator!=%3CT,U%3E(failure_type%3CT,U%3Econst&amp;)const.o"><span class="typ dec var fun">o</span></a><span class="pun">)</span> <span class="kwd">const</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

True if not equal to the failure type sugar.

*Effects:* If a valid expression to do so, calls the `operator!=` operation on the failure items returning true if not equal. Otherwise returns false.

*Throws:* Any exception the `operator!=` operations might throw.

#### Parameters

  - `o` &mdash; The failure type sugar to compare to.

-----

### Function `swap`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::swap(outcome&lt;R,S,P,NoValuePolicy&gt;&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">void</span> <span class="typ dec var fun">swap</span><span class="pun">(</span>outcome&lt;R, S, P, NoValuePolicy&gt;<span class="pun">&amp;</span> <span class="typ dec var fun">o</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Swaps this result with another result

*Effects:* Any `R` and/or `S` is swapped along with the metadata tracking them.

-----

### Function `as_failure`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::as_failure()const&amp;"></a>

<pre><code class="standardese-language-cpp"><a href="success_failure#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>outcome_v2_xxx::outcome::error_type, outcome_v2_xxx::outcome::exception_type<span class="pun">&gt;</span> <span class="typ dec var fun">as_failure</span><span class="pun">(</span><span class="pun">)</span> <span class="kwd">const</span> <span class="pun">&amp;</span><span class="pun">;</span>
</code></pre>

Returns this outcome as a `failure_type` with any errored and/or excepted state copied.

*Requires:* This outcome to have a failed state, else whatever `assume_error()` would do.

-----

### Function `as_failure`

<a id="standardese-outcome_v2_xxx::outcome&lt;R,S,P,NoValuePolicy&gt;::as_failure()&amp;&amp;"></a>

<pre><code class="standardese-language-cpp"><a href="success_failure#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>outcome_v2_xxx::outcome::error_type, outcome_v2_xxx::outcome::exception_type<span class="pun">&gt;</span> <span class="typ dec var fun">as_failure</span><span class="pun">(</span><span class="pun">)</span> <span class="pun">&amp;&amp;</span><span class="pun">;</span>
</code></pre>

Returns this outcome as a `failure_type` with any errored and/or excepted state moved.

*Requires:* This outcome to have a failed state, else whatever `assume_error()` would do.

-----

-----

### Function `outcome_v2_xxx::operator==`

<a id="standardese-outcome_v2_xxx::operator==&lt;T,U,V,R,S,P,N,&gt;(result&lt;T,U,V&gt;const&amp;,outcome&lt;R,S,P,N&gt;const&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">V</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">N</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="kwd">bool</span> <span class="typ dec var fun">operator==</span><span class="pun">(</span><a href="result#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>T, U, V<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::operator==%3CT,U,V,R,S,P,N,%3E(result%3CT,U,V%3Econst&amp;,outcome%3CR,S,P,N%3Econst&amp;).a"><span class="typ dec var fun">a</span></a><span class="pun">,</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, N<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::operator==%3CT,U,V,R,S,P,N,%3E(result%3CT,U,V%3Econst&amp;,outcome%3CR,S,P,N%3Econst&amp;).b"><span class="typ dec var fun">b</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

True if the result is equal to the outcome

*Effects:* Calls `b == a`.

*Requires:* That the expression `b == a` is a valid expression.

*Throws:* Any exception that `b == a` might throw.

#### Parameters

  - `a` &mdash; The result to compare.
  - `b` &mdash; The outcome to compare.

-----

### Function `outcome_v2_xxx::operator!=`

<a id="standardese-outcome_v2_xxx::operator!=&lt;T,U,V,R,S,P,N,&gt;(result&lt;T,U,V&gt;const&amp;,outcome&lt;R,S,P,N&gt;const&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">V</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">N</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="kwd">bool</span> <span class="typ dec var fun">operator!=</span><span class="pun">(</span><a href="result#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>T, U, V<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::operator!=%3CT,U,V,R,S,P,N,%3E(result%3CT,U,V%3Econst&amp;,outcome%3CR,S,P,N%3Econst&amp;).a"><span class="typ dec var fun">a</span></a><span class="pun">,</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, N<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::operator!=%3CT,U,V,R,S,P,N,%3E(result%3CT,U,V%3Econst&amp;,outcome%3CR,S,P,N%3Econst&amp;).b"><span class="typ dec var fun">b</span></a><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

True if the result is not equal to the outcome

*Effects:* Calls `b != a`.

*Requires:* That the expression `b != a` is a valid expression.

*Throws:* Any exception that `b != a` might throw.

#### Parameters

  - `a` &mdash; The result to compare.
  - `b` &mdash; The outcome to compare.

-----

### Function `outcome_v2_xxx::swap`

<a id="standardese-outcome_v2_xxx::swap&lt;R,S,P,N&gt;(outcome&lt;R,S,P,N&gt;&amp;,outcome&lt;R,S,P,N&gt;&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">N</span><span class="pun">&gt;</span>
<span class="kwd">void</span> <span class="typ dec var fun">swap</span><span class="pun">(</span><a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, N<span class="pun">&gt;</span><span class="pun">&amp;</span> <span class="typ dec var fun">a</span><span class="pun">,</span> <a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, N<span class="pun">&gt;</span><span class="pun">&amp;</span> <span class="typ dec var fun">b</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Specialise swap for outcome.

*Effects:* Calls `a.swap(b)`.

-----

<a id="standardese-outcome_v2_xxx::hooks"></a>

### Function `outcome_v2_xxx::hooks::override_outcome_exception`

<a id="standardese-outcome_v2_xxx::hooks::override_outcome_exception&lt;R,S,P,NoValuePolicy,U&gt;(outcome&lt;R,S,P,NoValuePolicy&gt;*,U&amp;&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">NoValuePolicy</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">U</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="kwd">void</span> <span class="typ dec var fun">override_outcome_exception</span><span class="pun">(</span><a href="#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, NoValuePolicy<span class="pun">&gt;</span><span class="pun">*</span> <span class="typ dec var fun">o</span><span class="pun">,</span> <span class="typ dec var fun">U</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

Used to set/override an exception during a construction hook implementation.

*Effects:* Sets the exception of the outcome to the given value.

#### Parameters

  - `o` &mdash; The outcome you wish to change.
  - `v` &mdash; Exception to be set.

-----
