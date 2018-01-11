+++
title = "iostream support"
weight = 80
+++
# Header file `iostream_support.hpp`

<a id="standardese-iostream_support.hpp"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">namespace</span> <span class="typ dec var fun">outcome_v2_xxx</span>
<span class="pun">{</span>
    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">&gt;</span>
    <span class="typ dec var fun">std::istream</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::operator%3E%3E%3CR,S,P,,%3E(std::istream&amp;,result%3CR,S,P%3E&amp;)"><span class="typ dec var fun">operator&gt;&gt;</span></a><span class="pun">(</span><span class="typ dec var fun">std::istream</span><span class="pun">&amp;</span> <span class="typ dec var fun">s</span><span class="pun">,</span> <a href="result#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>R, S, P<span class="pun">&gt;</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">&gt;</span>
    <span class="typ dec var fun">std::ostream</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::operator%3C%3C%3CR,S,P,,%3E(std::ostream&amp;,result%3CR,S,P%3Econst&amp;)"><span class="typ dec var fun">operator&lt;&lt;</span></a><span class="pun">(</span><span class="typ dec var fun">std::ostream</span><span class="pun">&amp;</span> <span class="typ dec var fun">s</span><span class="pun">,</span> <a href="result#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>R, S, P<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">&gt;</span>
    <span class="typ dec var fun">std::string</span> <a href="#standardese-outcome_v2_xxx::print%3CR,S,P%3E(detail::result_final%3CR,S,P%3Econst&amp;)"><span class="typ dec var fun">print</span></a><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">&gt;</span>
    <span class="typ dec var fun">std::string</span> <a href="#standardese-outcome_v2_xxx::print%3CS,P%3E(detail::result_final%3Cvoid,S,P%3Econst&amp;)"><span class="typ dec var fun">print</span></a><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">&gt;</span>
    <span class="typ dec var fun">std::string</span> <a href="#standardese-outcome_v2_xxx::print%3CR,P%3E(detail::result_final%3CR,void,P%3Econst&amp;)"><span class="typ dec var fun">print</span></a><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">&gt;</span>
    <span class="typ dec var fun">std::string</span> <a href="#standardese-outcome_v2_xxx::print%3CP%3E(detail::result_final%3Cvoid,void,P%3Econst&amp;)"><span class="typ dec var fun">print</span></a><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">N</span><span class="pun">&gt;</span>
    <span class="typ dec var fun">std::istream</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::operator%3E%3E%3CR,S,P,N,,,%3E(std::istream&amp;,outcome%3CR,S,P,N%3E&amp;)"><span class="typ dec var fun">operator&gt;&gt;</span></a><span class="pun">(</span><span class="typ dec var fun">std::istream</span><span class="pun">&amp;</span> <span class="typ dec var fun">s</span><span class="pun">,</span> <a href="outcome#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, N<span class="pun">&gt;</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">N</span><span class="pun">&gt;</span>
    <span class="typ dec var fun">std::ostream</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx::operator%3C%3C%3CR,S,P,N,,,%3E(std::ostream&amp;,outcome%3CR,S,P,N%3Econst&amp;)"><span class="typ dec var fun">operator&lt;&lt;</span></a><span class="pun">(</span><span class="typ dec var fun">std::ostream</span><span class="pun">&amp;</span> <span class="typ dec var fun">s</span><span class="pun">,</span> <a href="outcome#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, N<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">N</span><span class="pun">&gt;</span>
    <span class="typ dec var fun">std::string</span> <a href="#standardese-outcome_v2_xxx::print%3CR,S,P,N%3E(outcome%3CR,S,P,N%3Econst&amp;)"><span class="typ dec var fun">print</span></a><span class="pun">(</span><a href="outcome#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, N<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>
<span class="pun">}</span>
</code></pre>

<a id="standardese-outcome_v2_xxx"></a>

### Function `outcome_v2_xxx::operator>>`

<a id="standardese-outcome_v2_xxx::operator&gt;&gt;&lt;R,S,P,,&gt;(std::istream&amp;,result&lt;R,S,P&gt;&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">&gt;</span>
<span class="typ dec var fun">std::istream</span><span class="pun">&amp;</span> <span class="typ dec var fun">operator&gt;&gt;</span><span class="pun">(</span><span class="typ dec var fun">std::istream</span><span class="pun">&amp;</span> <span class="typ dec var fun">s</span><span class="pun">,</span> <a href="result#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>R, S, P<span class="pun">&gt;</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Deserialise a result. Format is `status_unsigned [value][error]`. Spare storage is preserved.

*Requires:* That `R` and `S` implement `operator>>`.

-----

### Function `outcome_v2_xxx::operator<<`

<a id="standardese-outcome_v2_xxx::operator&lt;&lt;&lt;R,S,P,,&gt;(std::ostream&amp;,result&lt;R,S,P&gt;const&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">&gt;</span>
<span class="typ dec var fun">std::ostream</span><span class="pun">&amp;</span> <span class="typ dec var fun">operator&lt;&lt;</span><span class="pun">(</span><span class="typ dec var fun">std::ostream</span><span class="pun">&amp;</span> <span class="typ dec var fun">s</span><span class="pun">,</span> <a href="result#standardese-outcome_v2_xxx::result%3CR,S,NoValuePolicy%3E"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>R, S, P<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Serialise a result. Format is `status_unsigned [value][error]`. Spare storage is preserved.

*Requires:* That `R` and `S` implement `operator<<`.

If you are printing to a human readable destination, use `print()` instead.

-----

### Function `outcome_v2_xxx::print`

<a id="standardese-outcome_v2_xxx::print&lt;R,S,P&gt;(detail::result_final&lt;R,S,P&gt;const&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">&gt;</span>
<span class="typ dec var fun">std::string</span> <span class="typ dec var fun">print</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Debug print a result into a form suitable for human reading. Format is `value|error`. If the error type is `error_code`, appends `" (ec.message())"` afterwards.

-----

### Function `outcome_v2_xxx::print`

<a id="standardese-outcome_v2_xxx::print&lt;S,P&gt;(detail::result_final&lt;void,S,P&gt;const&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">&gt;</span>
<span class="typ dec var fun">std::string</span> <span class="typ dec var fun">print</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Debug print a result into a form suitable for human reading. Format is `(+void)|error`. If the error type is `error_code`, appends `" (ec.message())"` afterwards.

-----

### Function `outcome_v2_xxx::print`

<a id="standardese-outcome_v2_xxx::print&lt;R,P&gt;(detail::result_final&lt;R,void,P&gt;const&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">&gt;</span>
<span class="typ dec var fun">std::string</span> <span class="typ dec var fun">print</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Debug print a result into a form suitable for human reading. Format is `value|(-void)`.

-----

### Function `outcome_v2_xxx::print`

<a id="standardese-outcome_v2_xxx::print&lt;P&gt;(detail::result_final&lt;void,void,P&gt;const&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">&gt;</span>
<span class="typ dec var fun">std::string</span> <span class="typ dec var fun">print</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Debug print a result into a form suitable for human reading. Format is `(+void)|(-void)`.

-----

### Function `outcome_v2_xxx::operator>>`

<a id="standardese-outcome_v2_xxx::operator&gt;&gt;&lt;R,S,P,N,,,&gt;(std::istream&amp;,outcome&lt;R,S,P,N&gt;&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">N</span><span class="pun">&gt;</span>
<span class="typ dec var fun">std::istream</span><span class="pun">&amp;</span> <span class="typ dec var fun">operator&gt;&gt;</span><span class="pun">(</span><span class="typ dec var fun">std::istream</span><span class="pun">&amp;</span> <span class="typ dec var fun">s</span><span class="pun">,</span> <a href="outcome#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, N<span class="pun">&gt;</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Deserialise an outcome. Format is `status_unsigned [value][error][exception]`. Spare storage is preserved.

*Requires:* That `R`, `S` and `P` implement `operator>>`.

-----

### Function `outcome_v2_xxx::operator<<`

<a id="standardese-outcome_v2_xxx::operator&lt;&lt;&lt;R,S,P,N,,,&gt;(std::ostream&amp;,outcome&lt;R,S,P,N&gt;const&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">N</span><span class="pun">&gt;</span>
<span class="typ dec var fun">std::ostream</span><span class="pun">&amp;</span> <span class="typ dec var fun">operator&lt;&lt;</span><span class="pun">(</span><span class="typ dec var fun">std::ostream</span><span class="pun">&amp;</span> <span class="typ dec var fun">s</span><span class="pun">,</span> <a href="outcome#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, N<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Serialise an outcome. Format is `status_unsigned [value][error][exception]`. Spare storage is preserved.

*Requires:* That `R`, `S` and `P` implement `operator<<`.

If you are printing to a human readable destination, use `print()` instead.

-----

### Function `outcome_v2_xxx::print`

<a id="standardese-outcome_v2_xxx::print&lt;R,S,P,N&gt;(outcome&lt;R,S,P,N&gt;const&amp;)"></a>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">N</span><span class="pun">&gt;</span>
<span class="typ dec var fun">std::string</span> <span class="typ dec var fun">print</span><span class="pun">(</span><a href="outcome#standardese-outcome_v2_xxx::outcome%3CR,S,P,NoValuePolicy%3E"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, N<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Debug print an outcome into a form suitable for human reading. Format is one of:

1.  `value|error|exception`

2.  `{ error, exception }`

If the error type is `error_code`, appends `" (ec.message())"` after the error. Exception type is printed as one of:

1.  `std::system_error code code(): what()`

2.  `std::exception: what()`

3.  `unknown exception`

-----
