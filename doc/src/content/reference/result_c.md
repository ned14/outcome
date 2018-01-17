+++
title = "C API"
weight = 90
+++
# Header file `result_c`

<span id="standardese-result-h"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">struct</span> <a href="#standardese-cxx_error_code"><span class="typ dec var fun">cxx_error_code</span></a><span class="pun">;</span>

<span class="pre">#define</span> <a href="#standardese-CXX_DECLARE_RESULT"><span class="typ dec var fun">CXX_DECLARE_RESULT</span></a><span class="pre">(</span><span class="pre">R,RD,S,SD</span><span class="pre">)</span>

<span class="pre">#define</span> <a href="#standardese-CXX_DECLARE_RESULT_EC"><span class="typ dec var fun">CXX_DECLARE_RESULT_EC</span></a><span class="pre">(</span><span class="pre">R,RD</span><span class="pre">)</span>

<span class="pre">#define</span> <a href="#standardese-CXX_RESULT"><span class="typ dec var fun">CXX_RESULT</span></a><span class="pre">(</span><span class="pre">R,S</span><span class="pre">)</span>

<span class="pre">#define</span> <a href="#standardese-CXX_RESULT_EC"><span class="typ dec var fun">CXX_RESULT_EC</span></a><span class="pre">(</span><span class="pre">R</span><span class="pre">)</span>

<span class="pre">#define</span> <a href="#standardese-CXX_RESULT_HAS_VALUE"><span class="typ dec var fun">CXX_RESULT_HAS_VALUE</span></a><span class="pre">(</span><span class="pre">r</span><span class="pre">)</span>

<span class="pre">#define</span> <a href="#standardese-CXX_RESULT_HAS_ERROR"><span class="typ dec var fun">CXX_RESULT_HAS_ERROR</span></a><span class="pre">(</span><span class="pre">r</span><span class="pre">)</span>

<span class="pre">#define</span> <a href="#standardese-CXX_RESULT_ERROR_IS_ERRNO"><span class="typ dec var fun">CXX_RESULT_ERROR_IS_ERRNO</span></a><span class="pre">(</span><span class="pre">r</span><span class="pre">)</span>

<span class="pre">#define</span> <a href="#standardese-CXX_RESULT_ERROR"><span class="typ dec var fun">CXX_RESULT_ERROR</span></a><span class="pre">(</span><span class="pre">r</span><span class="pre">)</span>

<span class="pre">#define</span> <a href="#standardese-CXX_RESULT_SET_ERRNO"><span class="typ dec var fun">CXX_RESULT_SET_ERRNO</span></a><span class="pre">(</span><span class="pre">r</span><span class="pre">)</span>
</code></pre>

## Struct `cxx_error_code`

<span id="standardese-cxx_error_code"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">struct</span> <span class="typ dec var fun">cxx_error_code</span>
<span class="pun">{</span>
    <span class="kwd">int</span> <span class="typ dec var fun">code</span><span class="pun">;</span>

    <span class="kwd">void</span><span class="pun">*</span> <span class="typ dec var fun">category</span><span class="pun">;</span>
<span class="pun">};</span>
</code></pre>

A C struct representation of `std::error_code`.

-----

## Macro `CXX_DECLARE_RESULT`

<span id="standardese-CXX_DECLARE_RESULT"></span>

<pre><code class="standardese-language-cpp"><span class="pre">#define</span> <span class="typ dec var fun">CXX_DECLARE_RESULT</span><span class="pre">(</span><span class="pre">R,RD,S,SD</span><span class="pre">)</span> <span class="pre">struct result_##R##_##S { RD value; unsigned flags; SD error; }</span>
</code></pre>

Declares a C struct representation of `result<R, S>`.

-----

## Macro `CXX_DECLARE_RESULT_EC`

<span id="standardese-CXX_DECLARE_RESULT_EC"></span>

<pre><code class="standardese-language-cpp"><span class="pre">#define</span> <span class="typ dec var fun">CXX_DECLARE_RESULT_EC</span><span class="pre">(</span><span class="pre">R,RD</span><span class="pre">)</span> <span class="pre">CXX_DECLARE_RESULT(R, RD, errorcode, struct cxx_error_code)</span>
</code></pre>

Declares a C struct representation of `result<R, std::error_code>`.

-----

## Macro `CXX_RESULT`

<span id="standardese-CXX_RESULT"></span>

<pre><code class="standardese-language-cpp"><span class="pre">#define</span> <span class="typ dec var fun">CXX_RESULT</span><span class="pre">(</span><span class="pre">R,S</span><span class="pre">)</span> <span class="pre">struct result_##R##_##S</span>
</code></pre>

A reference to a previously declared struct by `CXX_DECLARE_RESULT(R, RD, S, SD)`

-----

## Macro `CXX_RESULT_EC`

<span id="standardese-CXX_RESULT_EC"></span>

<pre><code class="standardese-language-cpp"><span class="pre">#define</span> <span class="typ dec var fun">CXX_RESULT_EC</span><span class="pre">(</span><span class="pre">R</span><span class="pre">)</span> <span class="pre">struct result_##R##_errorcode</span>
</code></pre>

A reference to a previously declared struct by `CXX_DECLARE_RESULT_EC(R, RD)`

-----

## Macro `CXX_RESULT_HAS_VALUE`

<span id="standardese-CXX_RESULT_HAS_VALUE"></span>

<pre><code class="standardese-language-cpp"><span class="pre">#define</span> <span class="typ dec var fun">CXX_RESULT_HAS_VALUE</span><span class="pre">(</span><span class="pre">r</span><span class="pre">)</span> <span class="pre">(((r).flags &amp; 1U) == 1U)</span>
</code></pre>

True if a result struct has a valid value

-----

## Macro `CXX_RESULT_HAS_ERROR`

<span id="standardese-CXX_RESULT_HAS_ERROR"></span>

<pre><code class="standardese-language-cpp"><span class="pre">#define</span> <span class="typ dec var fun">CXX_RESULT_HAS_ERROR</span><span class="pre">(</span><span class="pre">r</span><span class="pre">)</span> <span class="pre">(((r).flags &amp; 2U) == 2U)</span>
</code></pre>

True if a result struct has a valid error

-----

## Macro `CXX_RESULT_ERROR_IS_ERRNO`

<span id="standardese-CXX_RESULT_ERROR_IS_ERRNO"></span>

<pre><code class="standardese-language-cpp"><span class="pre">#define</span> <span class="typ dec var fun">CXX_RESULT_ERROR_IS_ERRNO</span><span class="pre">(</span><span class="pre">r</span><span class="pre">)</span> <span class="pre">(((r).flags &amp; (1U &lt;&lt; 4U)) == (1U &lt;&lt; 4U))</span>
</code></pre>

True if a result struct’s `error` or `code` is an `errno` domain code suitable for setting `errno` with.

-----

## Macro `CXX_RESULT_ERROR`

<span id="standardese-CXX_RESULT_ERROR"></span>

<pre><code class="standardese-language-cpp"><span class="pre">#define</span> <span class="typ dec var fun">CXX_RESULT_ERROR</span><span class="pre">(</span><span class="pre">r</span><span class="pre">)</span> <span class="pre">_Generic((r).error, struct cxx_error_code : ((struct cxx_error_code *) &amp;(r).error)-&gt;code, default : (r).error)</span>
</code></pre>

C11 generic selecting a result struct’s `error` or `code` integer member.

-----

## Macro `CXX_RESULT_SET_ERRNO`

<span id="standardese-CXX_RESULT_SET_ERRNO"></span>

<pre><code class="standardese-language-cpp"><span class="pre">#define</span> <span class="typ dec var fun">CXX_RESULT_SET_ERRNO</span><span class="pre">(</span><span class="pre">r</span><span class="pre">)</span> <span class="pre">(errno = CXX_RESULT_HAS_ERROR(r) ? (CXX_RESULT_ERROR_IS_ERRNO(r) ? CXX_RESULT_ERROR(r) : EAGAIN) : 0)</span>
</code></pre>

Convenience macro setting `errno` to a result struct’s `errno` compatible error if present, or `EAGAIN` if errored but incompatible.

-----
