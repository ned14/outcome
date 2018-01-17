+++
title = "Utilities"
weight = 50
+++
# Header file `utils.hpp`

<span id="standardese-utils-hpp"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">namespace</span>&nbsp;<span class="typ dec var fun">outcome_v2_xxx</span>
<span class="pun">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="typ dec var fun">std::error_code</span> <a href="#standardese-outcome_v2_xxx__error_from_exception-std__exception_ptr---std__error_code-"><span class="typ dec var fun">error_from_exception</span></a><span class="pun">(</span><span class="typ dec var fun">std::exception_ptr</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__error_from_exception-std__exception_ptr---std__error_code--ep"><span class="typ dec var fun">ep</span></a>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">std</span><span class="pun">::</span><span class="kwd">current_exception</span><span class="pun">(</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">std::error_code</span> <a href="#standardese-outcome_v2_xxx__error_from_exception-std__exception_ptr---std__error_code--not_matched"><span class="typ dec var fun">not_matched</span></a>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">std</span><span class="pun">::</span><span class="kwd">make_error_code</span><span class="pun">(</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">errc</span><span class="pun">::</span><span class="kwd">resource_unavailable_try_again</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx__try_throw_std_exception_from_error-std__error_code-std__stringconst--"><span class="typ dec var fun">try_throw_std_exception_from_error</span></a><span class="pun">(</span><span class="typ dec var fun">std::error_code</span> <a href="#standardese-outcome_v2_xxx__try_throw_std_exception_from_error-std__error_code-std__stringconst---ec"><span class="typ dec var fun">ec</span></a><span class="pun">,</span>&nbsp;<span class="typ dec var fun">std::string</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__try_throw_std_exception_from_error-std__error_code-std__stringconst---msg"><span class="typ dec var fun">msg</span></a>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">std</span><span class="pun">::</span><span class="kwd">string</span><span class="pun">{</span><span class="pun">)</span><span class="pun">;</span>
<span class="pun">}</span>
</code></pre>

<span id="standardese-outcome_v2_xxx"></span>

### Function `outcome_v2_xxx::error_from_exception`

<span id="standardese-outcome_v2_xxx__error_from_exception-std__exception_ptr---std__error_code-"></span>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">std::error_code</span>&nbsp;<span class="typ dec var fun">error_from_exception</span><span class="pun">(</span><span class="typ dec var fun">std::exception_ptr</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__error_from_exception-std__exception_ptr---std__error_code--ep"><span class="typ dec var fun">ep</span></a>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">std</span><span class="pun">::</span><span class="kwd">current_exception</span><span class="pun">(</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">std::error_code</span> <a href="#standardese-outcome_v2_xxx__error_from_exception-std__exception_ptr---std__error_code--not_matched"><span class="typ dec var fun">not_matched</span></a>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">std</span><span class="pun">::</span><span class="kwd">make_error_code</span><span class="pun">(</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">errc</span><span class="pun">::</span><span class="kwd">resource_unavailable_try_again</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

Utility function which tries to match the exception in the pointer provided to an equivalent error code. Ought to work for all standard STL types.

*Effects:* Rethrows the exception in the pointer, and via a long sequence of `catch` clauses attempts to match the equivalent error code. If a match is found, the pointer is reset to null. If a match is not found, *not\_matched* is returned instead and the pointer is left unmodified.

#### Parameters

  - `ep` &mdash; The pointer to an exception to convert. If matched, on exit this is reset to a null pointer.

### Parameter `outcome_v2_xxx::not_matched`

<span id="standardese-outcome_v2_xxx__error_from_exception-std__exception_ptr---std__error_code--not_matched"></span>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">std::error_code</span>&nbsp;<span class="typ dec var fun">not_matched</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">std</span><span class="pun">::</span><span class="kwd">make_error_code</span><span class="pun">(</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">errc</span><span class="pun">::</span><span class="kwd">resource_unavailable_try_again</span></code></pre>

The error code to return if we could not match the exception.

Note that a null pointer in returns a null error code.

-----

-----

### Function `outcome_v2_xxx::try_throw_std_exception_from_error`

<span id="standardese-outcome_v2_xxx__try_throw_std_exception_from_error-std__error_code-std__stringconst--"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">void</span>&nbsp;<span class="typ dec var fun">try_throw_std_exception_from_error</span><span class="pun">(</span><span class="typ dec var fun">std::error_code</span> <a href="#standardese-outcome_v2_xxx__try_throw_std_exception_from_error-std__error_code-std__stringconst---ec"><span class="typ dec var fun">ec</span></a><span class="pun">,</span>&nbsp;<span class="typ dec var fun">std::string</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__try_throw_std_exception_from_error-std__error_code-std__stringconst---msg"><span class="typ dec var fun">msg</span></a>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">std</span><span class="pun">::</span><span class="kwd">string</span><span class="pun">{</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Utility function which tries to throw the equivalent STL exception type for some given error code, not including `system_error`.

*Effects:* If the input error code has a category of `generic_category()` (all platforms) or `system_category()` (POSIX only), throw the STL exception type matching the `errno` domained code if one is available. For example, `ENOMEM` would cause `std::bad_alloc()` to be thrown.

#### Parameters

  - `ec` &mdash; The error code to try to convert into a STL exception throw.
  - `msg` &mdash; Optional custom message for the STL exception type.

-----
