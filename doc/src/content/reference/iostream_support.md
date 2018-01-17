+++
title = "iostream support"
weight = 80
+++
# Header file `iostream_support.hpp`

<span id="standardese-iostream_support-hpp"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">namespace</span> <span class="typ dec var fun">outcome_v2_xxx</span>
<span class="pun">{</span>
    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">&gt;</span>
    <span class="typ dec var fun">std::istream</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__operator---R-S-P----std__istream--result-R-S-P---"><span class="typ dec var fun">operator&gt;&gt;</span></a><span class="pun">(</span><span class="typ dec var fun">std::istream</span><span class="pun">&amp;</span> <span class="typ dec var fun">s</span><span class="pun">,</span> <a href="result#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>R, S, P<span class="pun">&gt;</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">&gt;</span>
    <span class="typ dec var fun">std::ostream</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__operator---R-S-P----std__ostream--result-R-S-P-const--"><span class="typ dec var fun">operator&lt;&lt;</span></a><span class="pun">(</span><span class="typ dec var fun">std::ostream</span><span class="pun">&amp;</span> <span class="typ dec var fun">s</span><span class="pun">,</span> <a href="result#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>R, S, P<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">&gt;</span>
    <span class="typ dec var fun">std::string</span> <a href="#standardese-outcome_v2_xxx__print-R-S-P--detail__result_final-R-S-P-const--"><span class="typ dec var fun">print</span></a><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">&gt;</span>
    <span class="typ dec var fun">std::string</span> <a href="#standardese-outcome_v2_xxx__print-S-P--detail__result_final-void-S-P-const--"><span class="typ dec var fun">print</span></a><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">&gt;</span>
    <span class="typ dec var fun">std::string</span> <a href="#standardese-outcome_v2_xxx__print-R-P--detail__result_final-R-void-P-const--"><span class="typ dec var fun">print</span></a><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">&gt;</span>
    <span class="typ dec var fun">std::string</span> <a href="#standardese-outcome_v2_xxx__print-P--detail__result_final-void-void-P-const--"><span class="typ dec var fun">print</span></a><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">N</span><span class="pun">&gt;</span>
    <span class="typ dec var fun">std::istream</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__operator---R-S-P-N-----std__istream--outcome-R-S-P-N---"><span class="typ dec var fun">operator&gt;&gt;</span></a><span class="pun">(</span><span class="typ dec var fun">std::istream</span><span class="pun">&amp;</span> <span class="typ dec var fun">s</span><span class="pun">,</span> <a href="outcome#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, N<span class="pun">&gt;</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">N</span><span class="pun">&gt;</span>
    <span class="typ dec var fun">std::ostream</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__operator---R-S-P-N-----std__ostream--outcome-R-S-P-N-const--"><span class="typ dec var fun">operator&lt;&lt;</span></a><span class="pun">(</span><span class="typ dec var fun">std::ostream</span><span class="pun">&amp;</span> <span class="typ dec var fun">s</span><span class="pun">,</span> <a href="outcome#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, N<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>

    <span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">N</span><span class="pun">&gt;</span>
    <span class="typ dec var fun">std::string</span> <a href="#standardese-outcome_v2_xxx__print-R-S-P-N--outcome-R-S-P-N-const--"><span class="typ dec var fun">print</span></a><span class="pun">(</span><a href="outcome#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, N<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>
<span class="pun">}</span>
</code></pre>

<span id="standardese-outcome_v2_xxx"></span>

### Function `outcome_v2_xxx::operator>>`

<span id="standardese-outcome_v2_xxx__operator---R-S-P----std__istream--result-R-S-P---"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">&gt;</span>
<span class="typ dec var fun">std::istream</span><span class="pun">&amp;</span> <span class="typ dec var fun">operator&gt;&gt;</span><span class="pun">(</span><span class="typ dec var fun">std::istream</span><span class="pun">&amp;</span> <span class="typ dec var fun">s</span><span class="pun">,</span> <a href="result#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>R, S, P<span class="pun">&gt;</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Deserialise a result. Format is `status_unsigned [value][error]`. Spare storage is preserved.

*Requires:* That `R` and `S` implement `operator>>`.

-----

### Function `outcome_v2_xxx::operator<<`

<span id="standardese-outcome_v2_xxx__operator---R-S-P----std__ostream--result-R-S-P-const--"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">&gt;</span>
<span class="typ dec var fun">std::ostream</span><span class="pun">&amp;</span> <span class="typ dec var fun">operator&lt;&lt;</span><span class="pun">(</span><span class="typ dec var fun">std::ostream</span><span class="pun">&amp;</span> <span class="typ dec var fun">s</span><span class="pun">,</span> <a href="result#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>R, S, P<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Serialise a result. Format is `status_unsigned [value][error]`. Spare storage is preserved.

*Requires:* That `R` and `S` implement `operator<<`.

If you are printing to a human readable destination, use `print()` instead.

-----

### Function `outcome_v2_xxx::print`

<span id="standardese-outcome_v2_xxx__print-R-S-P--detail__result_final-R-S-P-const--"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">&gt;</span>
<span class="typ dec var fun">std::string</span> <span class="typ dec var fun">print</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Debug print a result into a form suitable for human reading. Format is `value|error`. If the error type is `error_code`, appends `" (ec.message())"` afterwards.

-----

### Function `outcome_v2_xxx::print`

<span id="standardese-outcome_v2_xxx__print-S-P--detail__result_final-void-S-P-const--"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">&gt;</span>
<span class="typ dec var fun">std::string</span> <span class="typ dec var fun">print</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Debug print a result into a form suitable for human reading. Format is `(+void)|error`. If the error type is `error_code`, appends `" (ec.message())"` afterwards.

-----

### Function `outcome_v2_xxx::print`

<span id="standardese-outcome_v2_xxx__print-R-P--detail__result_final-R-void-P-const--"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">&gt;</span>
<span class="typ dec var fun">std::string</span> <span class="typ dec var fun">print</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Debug print a result into a form suitable for human reading. Format is `value|(-void)`.

-----

### Function `outcome_v2_xxx::print`

<span id="standardese-outcome_v2_xxx__print-P--detail__result_final-void-void-P-const--"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">&gt;</span>
<span class="typ dec var fun">std::string</span> <span class="typ dec var fun">print</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Debug print a result into a form suitable for human reading. Format is `(+void)|(-void)`.

-----

### Function `outcome_v2_xxx::operator>>`

<span id="standardese-outcome_v2_xxx__operator---R-S-P-N-----std__istream--outcome-R-S-P-N---"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">N</span><span class="pun">&gt;</span>
<span class="typ dec var fun">std::istream</span><span class="pun">&amp;</span> <span class="typ dec var fun">operator&gt;&gt;</span><span class="pun">(</span><span class="typ dec var fun">std::istream</span><span class="pun">&amp;</span> <span class="typ dec var fun">s</span><span class="pun">,</span> <a href="outcome#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, N<span class="pun">&gt;</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Deserialise an outcome. Format is `status_unsigned [value][error][exception]`. Spare storage is preserved.

*Requires:* That `R`, `S` and `P` implement `operator>>`.

-----

### Function `outcome_v2_xxx::operator<<`

<span id="standardese-outcome_v2_xxx__operator---R-S-P-N-----std__ostream--outcome-R-S-P-N-const--"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">N</span><span class="pun">&gt;</span>
<span class="typ dec var fun">std::ostream</span><span class="pun">&amp;</span> <span class="typ dec var fun">operator&lt;&lt;</span><span class="pun">(</span><span class="typ dec var fun">std::ostream</span><span class="pun">&amp;</span> <span class="typ dec var fun">s</span><span class="pun">,</span> <a href="outcome#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, N<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Serialise an outcome. Format is `status_unsigned [value][error][exception]`. Spare storage is preserved.

*Requires:* That `R`, `S` and `P` implement `operator<<`.

If you are printing to a human readable destination, use `print()` instead.

-----

### Function `outcome_v2_xxx::print`

<span id="standardese-outcome_v2_xxx__print-R-S-P-N--outcome-R-S-P-N-const--"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span> <span class="pun">&lt;</span><span class="kwd">class</span> <span class="typ dec var fun">R</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">S</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">P</span><span class="pun">,</span> <span class="kwd">class</span> <span class="typ dec var fun">N</span><span class="pun">&gt;</span>
<span class="typ dec var fun">std::string</span> <span class="typ dec var fun">print</span><span class="pun">(</span><a href="outcome#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, N<span class="pun">&gt;</span> <span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">v</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Debug print an outcome into a form suitable for human reading. Format is one of:

1.  `value|error|exception`

2.  `{ error, exception }`

If the error type is `error_code`, appends `" (ec.message())"` after the error. Exception type is printed as one of:

1.  `std::system_error code code(): what()`

2.  `std::exception: what()`

3.  `unknown exception`

-----
