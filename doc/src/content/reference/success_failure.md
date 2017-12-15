+++
title = "Success/Failure"
weight = 40
+++
# Header file `success_failure.hpp`

<a id="standardese-success_failure.hpp"></a>

<pre><code class="standardese-language-cpp"><span class="pre">#include</span> <span class="pre">&quot;</span><span class="typ dec var fun">config.hpp</span><span class="pre">&quot;</span>

<span class="pre">#include</span> <span class="pre">&lt;</span><span class="typ dec var fun">exception</span><span class="pre">&gt;</span>

<span class="pre">#include</span> <span class="pre">&lt;</span><span class="typ dec var fun">system_error</span><span class="pre">&gt;</span>

<span class="kwd">namespace</span> <span class="typ dec var fun">outcome_v2_xxx</span>
<span class="pun">{</span>
    <span class="kwd">namespace</span> <a href="standardese_entities.md#standardese-outcome_v2_xxx::policy"><span class="typ dec var fun">policy</span></a>
    <span class="pun">{</span>
        <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
        <span class="kwd">constexpr</span> <span class="kwd">auto</span> <a href="#standardese-outcome_v2_xxx::policy::error_code%3CT%3E(T&amp;&amp;)"><span class="typ dec var fun">error_code</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>

        <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
        <span class="kwd">constexpr</span> <span class="kwd">auto</span> <a href="#standardese-outcome_v2_xxx::policy::exception_ptr%3CT%3E(T&amp;&amp;)"><span class="typ dec var fun">exception_ptr</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>

        <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">Error</span><span class="pun">&gt;</span>
        <span class="kwd">constexpr</span> <span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx::policy::throw_as_system_error_with_payload%3CError%3E(Errorconst&amp;)"><span class="typ dec var fun">throw_as_system_error_with_payload</span></a><span class="pun">(</span><span class="typ dec var fun">Error</span> <span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">error</span><span class="pun">)</span><span class="pun">;</span>
    <span class="pun">}</span>

    <span class="kwd">namespace</span> <a href="standardese_entities.md#standardese-outcome_v2_xxx::trait"><span class="typ dec var fun">trait</span></a>
    <span class="pun">{</span>
        <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
        <span class="kwd">struct</span> <a href="#standardese-outcome_v2_xxx::trait::has_error_code%3CT%3E"><span class="typ dec var fun">has_error_code</span></a><span class="pun">;</span>

        <span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span> <span class="kwd">T</span><span class="pun">&gt;</span><span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">has_error_code_v</span> <span class="pun">=</span> <span class="kwd">has_error_code</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>

        <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
        <span class="kwd">struct</span> <a href="#standardese-outcome_v2_xxx::trait::has_exception_ptr%3CT%3E"><span class="typ dec var fun">has_exception_ptr</span></a><span class="pun">;</span>

        <span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span> <span class="kwd">T</span><span class="pun">&gt;</span><span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">has_exception_ptr_v</span> <span class="pun">=</span> <span class="kwd">has_exception_ptr</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>
    <span class="pun">}</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
    <span class="kwd">struct</span> <a href="#standardese-outcome_v2_xxx::success_type%3CT%3E"><span class="typ dec var fun">success_type</span></a><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="pun">&gt;</span>
    <span class="kwd">struct</span> <a href="#standardese-outcome_v2_xxx::success_type%3CT%3E"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span><span class="typ dec var fun">void</span><span class="pun">&gt;</span><span class="pun">;</span>

    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::success_type%3E"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>void<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx::success%3CT%3E(T&amp;&amp;)"><span class="typ dec var fun">success</span></a><span class="pun">(</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::success_type%3CT%3E"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>std::decay_t&lt;T&gt;<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx::success%3CT%3E(T&amp;&amp;)"><span class="typ dec var fun">success</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">EC</span> <span class="pun">=</span> std::error_code<span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">E</span> <span class="pun">=</span> void<span class="pun">&gt;</span>
    <span class="kwd">struct</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E"><span class="typ dec var fun">failure_type</span></a><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">EC</span><span class="pun">&gt;</span>
    <span class="kwd">struct</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span><span class="kwd">EC</span><span class="pun">,</span> <span class="typ dec var fun">void</span><span class="pun">&gt;</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">E</span><span class="pun">&gt;</span>
    <span class="kwd">struct</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span><span class="typ dec var fun">void</span><span class="pun">,</span> <span class="kwd">E</span><span class="pun">&gt;</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">EC</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>std::decay_t&lt;EC&gt;<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx::failure%3CEC%3E(EC&amp;&amp;)"><span class="typ dec var fun">failure</span></a><span class="pun">(</span><span class="typ dec var fun">EC</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">EC</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">E</span><span class="pun">&gt;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>std::decay_t&lt;EC&gt;, std::decay_t&lt;E&gt;<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx::failure%3CEC,E%3E(EC&amp;&amp;,E&amp;&amp;)"><span class="typ dec var fun">failure</span></a><span class="pun">(</span><span class="typ dec var fun">EC</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">v</span><span class="pun">,</span> <span class="typ dec var fun">E</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">w</span><span class="pun">)</span><span class="pun">;</span>
<span class="pun">}</span>
</code></pre>

<a id="standardese-outcome_v2_xxx"></a>

<a id="standardese-outcome_v2_xxx::policy"></a>

### Function `outcome_v2_xxx::policy::error_code`

<a id="standardese-outcome_v2_xxx::policy::error_code&lt;T&gt;(T&amp;&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="kwd">auto</span> <span class="typ dec var fun">error_code</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Used by policies to extract a `std::error_code` from some input `T` via ADL discovery of some `make_error_code(T)` function.

-----

### Function `outcome_v2_xxx::policy::exception_ptr`

<a id="standardese-outcome_v2_xxx::policy::exception_ptr&lt;T&gt;(T&amp;&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="kwd">auto</span> <span class="typ dec var fun">exception_ptr</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Used by policies to extract a `std::exception_ptr` from some input `T` via ADL discovery of some `make_exception_ptr(T)` function.

-----

### Function `outcome_v2_xxx::policy::throw_as_system_error_with_payload`

<a id="standardese-outcome_v2_xxx::policy::throw_as_system_error_with_payload&lt;Error&gt;(Errorconst&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">Error</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <span class="kwd">void</span> <span class="typ dec var fun">throw_as_system_error_with_payload</span><span class="pun">(</span><span class="typ dec var fun">Error</span> <span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">error</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Override to define what the policies which throw a system error with payload ought to do for some particular `result.error()`.

-----

<a id="standardese-outcome_v2_xxx::trait"></a>

### Struct `outcome_v2_xxx::trait::has_error_code`

<a id="standardese-outcome_v2_xxx::trait::has_error_code&lt;T&gt;"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">struct</span> <span class="typ dec var fun">has_error_code</span>
<span class="pun">{</span>
<span class="pun">};</span>
</code></pre>

Trait for whether a free function `make_error_code(T)` returning a `std::error_code` exists or not.

Also returns true if `std::error_code` is convertible from T.

-----

### Unexposed entity `outcome_v2_xxx::trait::has_error_code_v`

<a id="standardese-outcome_v2_xxx::trait::has_error_code_v"></a>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span> <span class="kwd">T</span><span class="pun">&gt;</span><span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">has_error_code_v</span> <span class="pun">=</span> <span class="kwd">has_error_code</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>
</code></pre>

Trait for whether a free function `make_error_code(T)` returning a `std::error_code` exists or not.

Also returns true if `std::error_code` is convertible from T.

-----

### Struct `outcome_v2_xxx::trait::has_exception_ptr`

<a id="standardese-outcome_v2_xxx::trait::has_exception_ptr&lt;T&gt;"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">struct</span> <span class="typ dec var fun">has_exception_ptr</span>
<span class="pun">{</span>
<span class="pun">};</span>
</code></pre>

Trait for whether a free function `make_exception_ptr(T)` returning a `std::exception_ptr` exists or not.

Also returns true if `std::exception_ptr` is convertible from T.

-----

### Unexposed entity `outcome_v2_xxx::trait::has_exception_ptr_v`

<a id="standardese-outcome_v2_xxx::trait::has_exception_ptr_v"></a>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">template</span> <span class="pun">&lt;</span><span class="typ dec var fun">class</span> <span class="kwd">T</span><span class="pun">&gt;</span><span class="typ dec var fun">constexpr</span> <span class="typ dec var fun">bool</span> <span class="kwd">has_exception_ptr_v</span> <span class="pun">=</span> <span class="kwd">has_exception_ptr</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>
</code></pre>

Trait for whether a free function `make_exception_ptr(T)` returning a `std::exception_ptr` exists or not.

Also returns true if `std::exception_ptr` is convertible from T.

-----

### Struct `outcome_v2_xxx::success_type`

<a id="standardese-outcome_v2_xxx::success_type&lt;T&gt;"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">struct</span> <span class="typ dec var fun">success_type</span>
<span class="pun">{</span>
    <span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx::success_type%3CT%3E::value_type"><span class="typ dec var fun">value_type</span></a> <span class="pun">=</span> <span class="typ dec var fun">T</span><span class="pun">;</span>

    <a href="#standardese-outcome_v2_xxx::success_type%3CT%3E::value_type"><span class="typ dec var fun">value_type</span></a> <a href="#standardese-outcome_v2_xxx::success_type%3CT%3E::_value"><span class="typ dec var fun">_value</span></a><span class="pun">;</span>

    &#x2F;&#x2F;=== value ===&#x2F;&#x2F;
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::success_type%3CT%3E::value_type"><span class="typ dec var fun">value_type</span></a><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::success_type%3CT%3E::value()&amp;"><span class="typ dec var fun">value</span></a><span class="pun">(</span><span class="pun">)</span> <span class="pun">&amp;</span><span class="pun">;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::success_type%3CT%3E::value_type"><span class="typ dec var fun">value_type</span></a><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::success_type%3CT%3E::value()&amp;"><span class="typ dec var fun">value</span></a><span class="pun">(</span><span class="pun">)</span> <span class="kwd">const</span> <span class="pun">&amp;</span><span class="pun">;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::success_type%3CT%3E::value_type"><span class="typ dec var fun">value_type</span></a><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::success_type%3CT%3E::value()&amp;"><span class="typ dec var fun">value</span></a><span class="pun">(</span><span class="pun">)</span> <span class="pun">&amp;&amp;</span><span class="pun">;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::success_type%3CT%3E::value_type"><span class="typ dec var fun">value_type</span></a><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::success_type%3CT%3E::value()&amp;"><span class="typ dec var fun">value</span></a><span class="pun">(</span><span class="pun">)</span> <span class="kwd">const</span> <span class="pun">&amp;&amp;</span><span class="pun">;</span>
<span class="pun">};</span>
</code></pre>

Type sugar for implicitly constructing a `result<>` with a successful state.

#### Member variables

  - `_value` &mdash; The value of the successful state.

### Type alias `value_type`

<a id="standardese-outcome_v2_xxx::success_type&lt;T&gt;::value_type"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">using</span> <span class="typ dec var fun">value_type</span> <span class="pun">=</span> <span class="typ dec var fun">T</span><span class="pun">;</span>
</code></pre>

The type of the successful state.

-----

### Function `value`

<a id="standardese-outcome_v2_xxx::success_type&lt;T&gt;::value()&amp;"></a>

<pre><code class="standardese-language-cpp">(1) <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::success_type%3CT%3E::value_type"><span class="typ dec var fun">value_type</span></a><span class="pun">&amp;</span> <span class="typ dec var fun">value</span><span class="pun">(</span><span class="pun">)</span> <span class="pun">&amp;</span><span class="pun">;</span>

(2) <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::success_type%3CT%3E::value_type"><span class="typ dec var fun">value_type</span></a><span class="pun">&amp;</span> <span class="typ dec var fun">value</span><span class="pun">(</span><span class="pun">)</span> <span class="kwd">const</span> <span class="pun">&amp;</span><span class="pun">;</span>

(3) <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::success_type%3CT%3E::value_type"><span class="typ dec var fun">value_type</span></a><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">value</span><span class="pun">(</span><span class="pun">)</span> <span class="pun">&amp;&amp;</span><span class="pun">;</span>

(4) <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::success_type%3CT%3E::value_type"><span class="typ dec var fun">value_type</span></a><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">value</span><span class="pun">(</span><span class="pun">)</span> <span class="kwd">const</span> <span class="pun">&amp;&amp;</span><span class="pun">;</span>
</code></pre>

Access value.

*Returns:* Reference to the held `value_type` according to overload.

-----

-----

### Struct `outcome_v2_xxx::success_type`

<a id="standardese-outcome_v2_xxx::success_type&gt;"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="pun">&gt;</span>
<span class="kwd">struct</span> <a href="#standardese-outcome_v2_xxx::success_type%3CT%3E"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span><span class="typ dec var fun">void</span><span class="pun">&gt;</span>
<span class="pun">{</span>
    <span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx::success_type%3E::value_type"><span class="typ dec var fun">value_type</span></a> <span class="pun">=</span> <span class="kwd">void</span><span class="pun">;</span>
<span class="pun">};</span>
</code></pre>

Type sugar for implicitly constructing a `result<>` with a successful state.

### Type alias `value_type`

<a id="standardese-outcome_v2_xxx::success_type&gt;::value_type"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">using</span> <span class="typ dec var fun">value_type</span> <span class="pun">=</span> <span class="kwd">void</span><span class="pun">;</span>
</code></pre>

The type of the successful state.

-----

-----

### Function `outcome_v2_xxx::success`

<a id="standardese-outcome_v2_xxx::success()"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::success_type%3E"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>void<span class="pun">&gt;</span> <span class="typ dec var fun">success</span><span class="pun">(</span><span class="pun">)</span> <span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

Returns type sugar for implicitly constructing a `result<T>` with a successful state, default constructing `T` if necessary.

-----

### Function `outcome_v2_xxx::success`

<a id="standardese-outcome_v2_xxx::success&lt;T&gt;(T&amp;&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::success_type%3CT%3E"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>std::decay_t&lt;T&gt;<span class="pun">&gt;</span> <span class="typ dec var fun">success</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Returns type sugar for implicitly constructing a `result<T>` with a successful state.

*Effects:* Copies or moves the successful state supplied into the returned type sugar.

-----

### Struct `outcome_v2_xxx::failure_type`

<a id="standardese-outcome_v2_xxx::failure_type&lt;EC,E&gt;"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">EC</span> <span class="pun">=</span> std::error_code<span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">E</span> <span class="pun">=</span> void<span class="pun">&gt;</span>
<span class="kwd">struct</span> <span class="typ dec var fun">failure_type</span>
<span class="pun">{</span>
    <span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E::error_type"><span class="typ dec var fun">error_type</span></a> <span class="pun">=</span> <span class="typ dec var fun">EC</span><span class="pun">;</span>

    <span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E::exception_type"><span class="typ dec var fun">exception_type</span></a> <span class="pun">=</span> <span class="typ dec var fun">E</span><span class="pun">;</span>

    <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E::error_type"><span class="typ dec var fun">error_type</span></a> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E::_error"><span class="typ dec var fun">_error</span></a><span class="pun">;</span>

    <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E::exception_type"><span class="typ dec var fun">exception_type</span></a> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E::_exception"><span class="typ dec var fun">_exception</span></a><span class="pun">;</span>

    &#x2F;&#x2F;=== error ===&#x2F;&#x2F;
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E::error_type"><span class="typ dec var fun">error_type</span></a><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E::error()&amp;"><span class="typ dec var fun">error</span></a><span class="pun">(</span><span class="pun">)</span> <span class="pun">&amp;</span><span class="pun">;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E::error_type"><span class="typ dec var fun">error_type</span></a><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E::error()&amp;"><span class="typ dec var fun">error</span></a><span class="pun">(</span><span class="pun">)</span> <span class="kwd">const</span> <span class="pun">&amp;</span><span class="pun">;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E::error_type"><span class="typ dec var fun">error_type</span></a><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E::error()&amp;"><span class="typ dec var fun">error</span></a><span class="pun">(</span><span class="pun">)</span> <span class="pun">&amp;&amp;</span><span class="pun">;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E::error_type"><span class="typ dec var fun">error_type</span></a><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E::error()&amp;"><span class="typ dec var fun">error</span></a><span class="pun">(</span><span class="pun">)</span> <span class="kwd">const</span> <span class="pun">&amp;&amp;</span><span class="pun">;</span>

    &#x2F;&#x2F;=== exception ===&#x2F;&#x2F;
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E::exception_type"><span class="typ dec var fun">exception_type</span></a><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E::exception()&amp;"><span class="typ dec var fun">exception</span></a><span class="pun">(</span><span class="pun">)</span> <span class="pun">&amp;</span><span class="pun">;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E::exception_type"><span class="typ dec var fun">exception_type</span></a><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E::exception()&amp;"><span class="typ dec var fun">exception</span></a><span class="pun">(</span><span class="pun">)</span> <span class="kwd">const</span> <span class="pun">&amp;</span><span class="pun">;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E::exception_type"><span class="typ dec var fun">exception_type</span></a><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E::exception()&amp;"><span class="typ dec var fun">exception</span></a><span class="pun">(</span><span class="pun">)</span> <span class="pun">&amp;&amp;</span><span class="pun">;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E::exception_type"><span class="typ dec var fun">exception_type</span></a><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E::exception()&amp;"><span class="typ dec var fun">exception</span></a><span class="pun">(</span><span class="pun">)</span> <span class="kwd">const</span> <span class="pun">&amp;&amp;</span><span class="pun">;</span>
<span class="pun">};</span>
</code></pre>

Type sugar for implicitly constructing a `result<>` with a failure state of error code and exception.

#### Member variables

  - `_error` &mdash; The error code
  - `_exception` &mdash; The exception

### Type alias `error_type`

<a id="standardese-outcome_v2_xxx::failure_type&lt;EC,E&gt;::error_type"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">using</span> <span class="typ dec var fun">error_type</span> <span class="pun">=</span> <span class="typ dec var fun">EC</span><span class="pun">;</span>
</code></pre>

The type of the error code

-----

### Type alias `exception_type`

<a id="standardese-outcome_v2_xxx::failure_type&lt;EC,E&gt;::exception_type"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">using</span> <span class="typ dec var fun">exception_type</span> <span class="pun">=</span> <span class="typ dec var fun">E</span><span class="pun">;</span>
</code></pre>

The type of the exception

-----

### Function `error`

<a id="standardese-outcome_v2_xxx::failure_type&lt;EC,E&gt;::error()&amp;"></a>

<pre><code class="standardese-language-cpp">(1) <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E::error_type"><span class="typ dec var fun">error_type</span></a><span class="pun">&amp;</span> <span class="typ dec var fun">error</span><span class="pun">(</span><span class="pun">)</span> <span class="pun">&amp;</span><span class="pun">;</span>

(2) <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E::error_type"><span class="typ dec var fun">error_type</span></a><span class="pun">&amp;</span> <span class="typ dec var fun">error</span><span class="pun">(</span><span class="pun">)</span> <span class="kwd">const</span> <span class="pun">&amp;</span><span class="pun">;</span>

(3) <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E::error_type"><span class="typ dec var fun">error_type</span></a><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">error</span><span class="pun">(</span><span class="pun">)</span> <span class="pun">&amp;&amp;</span><span class="pun">;</span>

(4) <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E::error_type"><span class="typ dec var fun">error_type</span></a><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">error</span><span class="pun">(</span><span class="pun">)</span> <span class="kwd">const</span> <span class="pun">&amp;&amp;</span><span class="pun">;</span>
</code></pre>

Access error.

*Returns:* Reference to the held `error_type` according to overload.

-----

### Function `exception`

<a id="standardese-outcome_v2_xxx::failure_type&lt;EC,E&gt;::exception()&amp;"></a>

<pre><code class="standardese-language-cpp">(1) <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E::exception_type"><span class="typ dec var fun">exception_type</span></a><span class="pun">&amp;</span> <span class="typ dec var fun">exception</span><span class="pun">(</span><span class="pun">)</span> <span class="pun">&amp;</span><span class="pun">;</span>

(2) <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E::exception_type"><span class="typ dec var fun">exception_type</span></a><span class="pun">&amp;</span> <span class="typ dec var fun">exception</span><span class="pun">(</span><span class="pun">)</span> <span class="kwd">const</span> <span class="pun">&amp;</span><span class="pun">;</span>

(3) <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E::exception_type"><span class="typ dec var fun">exception_type</span></a><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">exception</span><span class="pun">(</span><span class="pun">)</span> <span class="pun">&amp;&amp;</span><span class="pun">;</span>

(4) <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E::exception_type"><span class="typ dec var fun">exception_type</span></a><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">exception</span><span class="pun">(</span><span class="pun">)</span> <span class="kwd">const</span> <span class="pun">&amp;&amp;</span><span class="pun">;</span>
</code></pre>

Access exception.

*Returns:* Reference to the held `exception_type` according to overload.

-----

-----

### Struct `outcome_v2_xxx::failure_type`

<a id="standardese-outcome_v2_xxx::failure_type&lt;EC&gt;"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">EC</span><span class="pun">&gt;</span>
<span class="kwd">struct</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span><span class="kwd">EC</span><span class="pun">,</span> <span class="typ dec var fun">void</span><span class="pun">&gt;</span>
<span class="pun">{</span>
    <span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC%3E::error_type"><span class="typ dec var fun">error_type</span></a> <span class="pun">=</span> <span class="typ dec var fun">EC</span><span class="pun">;</span>

    <span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC%3E::exception_type"><span class="typ dec var fun">exception_type</span></a> <span class="pun">=</span> <span class="kwd">void</span><span class="pun">;</span>

    <a href="#standardese-outcome_v2_xxx::failure_type%3CEC%3E::error_type"><span class="typ dec var fun">error_type</span></a> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC%3E::_error"><span class="typ dec var fun">_error</span></a><span class="pun">;</span>

    &#x2F;&#x2F;=== error2 ===&#x2F;&#x2F;
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC%3E::error_type"><span class="typ dec var fun">error_type</span></a><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC%3E::error()&amp;"><span class="typ dec var fun">error</span></a><span class="pun">(</span><span class="pun">)</span> <span class="pun">&amp;</span><span class="pun">;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC%3E::error_type"><span class="typ dec var fun">error_type</span></a><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC%3E::error()&amp;"><span class="typ dec var fun">error</span></a><span class="pun">(</span><span class="pun">)</span> <span class="kwd">const</span> <span class="pun">&amp;</span><span class="pun">;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC%3E::error_type"><span class="typ dec var fun">error_type</span></a><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC%3E::error()&amp;"><span class="typ dec var fun">error</span></a><span class="pun">(</span><span class="pun">)</span> <span class="pun">&amp;&amp;</span><span class="pun">;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC%3E::error_type"><span class="typ dec var fun">error_type</span></a><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC%3E::error()&amp;"><span class="typ dec var fun">error</span></a><span class="pun">(</span><span class="pun">)</span> <span class="kwd">const</span> <span class="pun">&amp;&amp;</span><span class="pun">;</span>
<span class="pun">};</span>
</code></pre>

Type sugar for implicitly constructing a `result<>` with a failure state of error code.

#### Member variables

  - `_error` &mdash; The error code

### Type alias `error_type`

<a id="standardese-outcome_v2_xxx::failure_type&lt;EC&gt;::error_type"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">using</span> <span class="typ dec var fun">error_type</span> <span class="pun">=</span> <span class="typ dec var fun">EC</span><span class="pun">;</span>
</code></pre>

The type of the error code

-----

### Type alias `exception_type`

<a id="standardese-outcome_v2_xxx::failure_type&lt;EC&gt;::exception_type"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">using</span> <span class="typ dec var fun">exception_type</span> <span class="pun">=</span> <span class="kwd">void</span><span class="pun">;</span>
</code></pre>

The type of the exception

-----

### Function `error`

<a id="standardese-outcome_v2_xxx::failure_type&lt;EC&gt;::error()&amp;"></a>

<pre><code class="standardese-language-cpp">(1) <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC%3E::error_type"><span class="typ dec var fun">error_type</span></a><span class="pun">&amp;</span> <span class="typ dec var fun">error</span><span class="pun">(</span><span class="pun">)</span> <span class="pun">&amp;</span><span class="pun">;</span>

(2) <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC%3E::error_type"><span class="typ dec var fun">error_type</span></a><span class="pun">&amp;</span> <span class="typ dec var fun">error</span><span class="pun">(</span><span class="pun">)</span> <span class="kwd">const</span> <span class="pun">&amp;</span><span class="pun">;</span>

(3) <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC%3E::error_type"><span class="typ dec var fun">error_type</span></a><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">error</span><span class="pun">(</span><span class="pun">)</span> <span class="pun">&amp;&amp;</span><span class="pun">;</span>

(4) <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC%3E::error_type"><span class="typ dec var fun">error_type</span></a><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">error</span><span class="pun">(</span><span class="pun">)</span> <span class="kwd">const</span> <span class="pun">&amp;&amp;</span><span class="pun">;</span>
</code></pre>

Access error.

*Returns:* Reference to the held `error_type` according to overload.

-----

-----

### Struct `outcome_v2_xxx::failure_type`

<a id="standardese-outcome_v2_xxx::failure_type&lt;E&gt;"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">E</span><span class="pun">&gt;</span>
<span class="kwd">struct</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span><span class="typ dec var fun">void</span><span class="pun">,</span> <span class="kwd">E</span><span class="pun">&gt;</span>
<span class="pun">{</span>
    <span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CE%3E::error_type"><span class="typ dec var fun">error_type</span></a> <span class="pun">=</span> <span class="kwd">void</span><span class="pun">;</span>

    <span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CE%3E::exception_type"><span class="typ dec var fun">exception_type</span></a> <span class="pun">=</span> <span class="typ dec var fun">E</span><span class="pun">;</span>

    <a href="#standardese-outcome_v2_xxx::failure_type%3CE%3E::exception_type"><span class="typ dec var fun">exception_type</span></a> <a href="#standardese-outcome_v2_xxx::failure_type%3CE%3E::_exception"><span class="typ dec var fun">_exception</span></a><span class="pun">;</span>

    &#x2F;&#x2F;=== exception2 ===&#x2F;&#x2F;
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CE%3E::exception_type"><span class="typ dec var fun">exception_type</span></a><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CE%3E::exception()&amp;"><span class="typ dec var fun">exception</span></a><span class="pun">(</span><span class="pun">)</span> <span class="pun">&amp;</span><span class="pun">;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CE%3E::exception_type"><span class="typ dec var fun">exception_type</span></a><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CE%3E::exception()&amp;"><span class="typ dec var fun">exception</span></a><span class="pun">(</span><span class="pun">)</span> <span class="kwd">const</span> <span class="pun">&amp;</span><span class="pun">;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CE%3E::exception_type"><span class="typ dec var fun">exception_type</span></a><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CE%3E::exception()&amp;"><span class="typ dec var fun">exception</span></a><span class="pun">(</span><span class="pun">)</span> <span class="pun">&amp;&amp;</span><span class="pun">;</span>
    <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CE%3E::exception_type"><span class="typ dec var fun">exception_type</span></a><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CE%3E::exception()&amp;"><span class="typ dec var fun">exception</span></a><span class="pun">(</span><span class="pun">)</span> <span class="kwd">const</span> <span class="pun">&amp;&amp;</span><span class="pun">;</span>
<span class="pun">};</span>
</code></pre>

Type sugar for implicitly constructing a `result<>` with a failure state of exception.

#### Member variables

  - `_exception` &mdash; The exception

### Type alias `error_type`

<a id="standardese-outcome_v2_xxx::failure_type&lt;E&gt;::error_type"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">using</span> <span class="typ dec var fun">error_type</span> <span class="pun">=</span> <span class="kwd">void</span><span class="pun">;</span>
</code></pre>

The type of the error code

-----

### Type alias `exception_type`

<a id="standardese-outcome_v2_xxx::failure_type&lt;E&gt;::exception_type"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">using</span> <span class="typ dec var fun">exception_type</span> <span class="pun">=</span> <span class="typ dec var fun">E</span><span class="pun">;</span>
</code></pre>

The type of the exception

-----

### Function `exception`

<a id="standardese-outcome_v2_xxx::failure_type&lt;E&gt;::exception()&amp;"></a>

<pre><code class="standardese-language-cpp">(1) <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CE%3E::exception_type"><span class="typ dec var fun">exception_type</span></a><span class="pun">&amp;</span> <span class="typ dec var fun">exception</span><span class="pun">(</span><span class="pun">)</span> <span class="pun">&amp;</span><span class="pun">;</span>

(2) <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CE%3E::exception_type"><span class="typ dec var fun">exception_type</span></a><span class="pun">&amp;</span> <span class="typ dec var fun">exception</span><span class="pun">(</span><span class="pun">)</span> <span class="kwd">const</span> <span class="pun">&amp;</span><span class="pun">;</span>

(3) <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CE%3E::exception_type"><span class="typ dec var fun">exception_type</span></a><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">exception</span><span class="pun">(</span><span class="pun">)</span> <span class="pun">&amp;&amp;</span><span class="pun">;</span>

(4) <span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CE%3E::exception_type"><span class="typ dec var fun">exception_type</span></a><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">exception</span><span class="pun">(</span><span class="pun">)</span> <span class="kwd">const</span> <span class="pun">&amp;&amp;</span><span class="pun">;</span>
</code></pre>

Access exception.

*Returns:* Reference to the held `exception_type` according to overload.

-----

-----

### Function `outcome_v2_xxx::failure`

<a id="standardese-outcome_v2_xxx::failure&lt;EC&gt;(EC&amp;&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">EC</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>std::decay_t&lt;EC&gt;<span class="pun">&gt;</span> <span class="typ dec var fun">failure</span><span class="pun">(</span><span class="typ dec var fun">EC</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Returns type sugar for implicitly constructing a `result<T>` with a failure state.

*Effects:* Copies or moves the failure state supplied into the returned type sugar.

-----

### Function `outcome_v2_xxx::failure`

<a id="standardese-outcome_v2_xxx::failure&lt;EC,E&gt;(EC&amp;&amp;,E&amp;&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">EC</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">E</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx::failure_type%3CEC,E%3E"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>std::decay_t&lt;EC&gt;, std::decay_t&lt;E&gt;<span class="pun">&gt;</span> <span class="typ dec var fun">failure</span><span class="pun">(</span><span class="typ dec var fun">EC</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">v</span><span class="pun">,</span> <span class="typ dec var fun">E</span><span class="pun">&amp;&amp;</span> <span class="typ dec var fun">w</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Returns type sugar for implicitly constructing a `result<T>` with a failure state.

*Effects:* Copies or moves the failure state supplied into the returned type sugar.

-----
