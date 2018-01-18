+++
title = "outcome<R, S, P>"
weight = 10
+++
# Header file `outcome.hpp`

<span id="standardese-outcome-hpp"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">namespace</span>&nbsp;<span class="typ dec var fun">outcome_v2_xxx</span>
<span class="pun">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx__is_outcome-T-"><span class="typ dec var fun">is_outcome</span></a>&nbsp;<span class="pun">=</span>&nbsp;<span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span>&nbsp;<span class="kwd">T</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">is_outcome_v</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">detail</span><span class="pun">::</span><span class="kwd">is_outcome</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">namespace</span>&nbsp;<span class="typ dec var fun">hooks</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="pun">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx__hooks__hook_outcome_construction-T-U--T--U---"><span class="typ dec var fun">hook_outcome_construction</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">*</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&amp;&amp;</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx__hooks__hook_outcome_copy_construction-T-U--T--U---"><span class="typ dec var fun">hook_outcome_copy_construction</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">*</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&amp;&amp;</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx__hooks__hook_outcome_move_construction-T-U--T--U---"><span class="typ dec var fun">hook_outcome_move_construction</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">*</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&amp;&amp;</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="pun">...</span>&nbsp;<span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx__hooks__hook_outcome_in_place_construction-T-U-Args--T--in_place_type_t-U--Args------"><span class="typ dec var fun">hook_outcome_in_place_construction</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">*</span><span class="pun">,</span> <span class="typ dec var fun">in_place_type_t</span><span class="pun">&lt;</span>U<span class="pun">&gt;</span><span class="pun">,</span> Args &amp;&amp;...<span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">R</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">S</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">P</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">NoValuePolicy</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx__hooks__override_outcome_exception-R-S-P-NoValuePolicy-U--outcome-R-S-P-NoValuePolicy---U---"><span class="typ dec var fun">override_outcome_exception</span></a><span class="pun">(</span><a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, NoValuePolicy<span class="pun">&gt;</span><span class="pun">*</span>&nbsp;<span class="typ dec var fun">o</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">v</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="pun">}</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy--R"><span class="typ dec var fun">R</span></a><span class="pun">,</span>&nbsp;<span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy--S"><span class="typ dec var fun">S</span></a><span class="pun">,</span>&nbsp;<span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy--P"><span class="typ dec var fun">P</span></a><span class="pun">,</span>&nbsp;<span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy--NoValuePolicy"><span class="typ dec var fun">NoValuePolicy</span></a><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-"><span class="typ dec var fun">outcome</span></a><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">V</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">R</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">S</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">P</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">N</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span> <a href="#standardese-outcome_v2_xxx__operator---T-U-V-R-S-P-N---result-T-U-V-const--outcome-R-S-P-N-const--"><span class="typ dec var fun">operator==</span></a><span class="pun">(</span><a href="../result#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>T, U, V<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__operator---T-U-V-R-S-P-N---result-T-U-V-const--outcome-R-S-P-N-const---a"><span class="typ dec var fun">a</span></a><span class="pun">,</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, N<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__operator---T-U-V-R-S-P-N---result-T-U-V-const--outcome-R-S-P-N-const---b"><span class="typ dec var fun">b</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">V</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">R</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">S</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">P</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">N</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span> <a href="#standardese-outcome_v2_xxx__operator---T-U-V-R-S-P-N---result-T-U-V-const--outcome-R-S-P-N-const--"><span class="typ dec var fun">operator!=</span></a><span class="pun">(</span><a href="../result#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>T, U, V<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__operator---T-U-V-R-S-P-N---result-T-U-V-const--outcome-R-S-P-N-const---a"><span class="typ dec var fun">a</span></a><span class="pun">,</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, N<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__operator---T-U-V-R-S-P-N---result-T-U-V-const--outcome-R-S-P-N-const---b"><span class="typ dec var fun">b</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">R</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">S</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">P</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">N</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx__swap-R-S-P-N--outcome-R-S-P-N---outcome-R-S-P-N---"><span class="typ dec var fun">swap</span></a><span class="pun">(</span><a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, N<span class="pun">&gt;</span><span class="pun">&amp;</span>&nbsp;<span class="typ dec var fun">a</span><span class="pun">,</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, N<span class="pun">&gt;</span><span class="pun">&amp;</span>&nbsp;<span class="typ dec var fun">b</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">namespace</span>&nbsp;<span class="typ dec var fun">hooks</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="pun">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">R</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">S</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">P</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">NoValuePolicy</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx__hooks__override_outcome_exception-R-S-P-NoValuePolicy-U--outcome-R-S-P-NoValuePolicy---U---"><span class="typ dec var fun">override_outcome_exception</span></a><span class="pun">(</span><a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, NoValuePolicy<span class="pun">&gt;</span><span class="pun">*</span> <a href="#standardese-outcome_v2_xxx__hooks__override_outcome_exception-R-S-P-NoValuePolicy-U--outcome-R-S-P-NoValuePolicy---U---"><span class="typ dec var fun">o</span></a><span class="pun">,</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__hooks__override_outcome_exception-R-S-P-NoValuePolicy-U--outcome-R-S-P-NoValuePolicy---U---"><span class="typ dec var fun">v</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="pun">}</span>
<span class="pun">}</span>
</code></pre>

<span id="standardese-outcome_v2_xxx"></span>

### Alias template `outcome_v2_xxx::is_outcome`

<span id="standardese-outcome_v2_xxx__is_outcome-T-"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">using</span>&nbsp;<span class="typ dec var fun">is_outcome</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">;</span>
</code></pre>

True if an outcome

-----

### Unexposed entity `outcome_v2_xxx::is_outcome_v`

<span id="standardese-outcome_v2_xxx__is_outcome_v"></span>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span>&nbsp;<span class="kwd">T</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">is_outcome_v</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">detail</span><span class="pun">::</span><span class="kwd">is_outcome</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>
</code></pre>

True if an outcome

-----

<span id="standardese-outcome_v2_xxx__hooks"></span>

### Function `outcome_v2_xxx::hooks::hook_outcome_construction`

<span id="standardese-outcome_v2_xxx__hooks__hook_outcome_construction-T-U--T--U---"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span>&nbsp;<span class="typ dec var fun">hook_outcome_construction</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">*</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&amp;&amp;</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

The default instantiation hook implementation called when a `outcome` is first created by conversion from one of its possible types. Does nothing.

WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should\!

#### Parameters

  - `  ` &mdash; Some `outcome<...>` being constructed.

-----

### Function `outcome_v2_xxx::hooks::hook_outcome_copy_construction`

<span id="standardese-outcome_v2_xxx__hooks__hook_outcome_copy_construction-T-U--T--U---"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span>&nbsp;<span class="typ dec var fun">hook_outcome_copy_construction</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">*</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&amp;&amp;</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

The default instantiation hook implementation called when a `outcome` is created by copying from another `outcome` or `result`. Does nothing.

WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should\!

#### Parameters

  - `  ` &mdash; Some `outcome<...>` being constructed.

-----

### Function `outcome_v2_xxx::hooks::hook_outcome_move_construction`

<span id="standardese-outcome_v2_xxx__hooks__hook_outcome_move_construction-T-U--T--U---"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span>&nbsp;<span class="typ dec var fun">hook_outcome_move_construction</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">*</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&amp;&amp;</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

The default instantiation hook implementation called when a `outcome` is created by moving from another `outcome` or `result`. Does nothing.

WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should\!

#### Parameters

  - `  ` &mdash; Some `outcome<...>` being constructed.

-----

### Function `outcome_v2_xxx::hooks::hook_outcome_in_place_construction`

<span id="standardese-outcome_v2_xxx__hooks__hook_outcome_in_place_construction-T-U-Args--T--in_place_type_t-U--Args------"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="pun">...</span>&nbsp;<span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span>&nbsp;<span class="typ dec var fun">hook_outcome_in_place_construction</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">*</span><span class="pun">,</span> <span class="typ dec var fun">in_place_type_t</span><span class="pun">&lt;</span>U<span class="pun">&gt;</span><span class="pun">,</span> Args &amp;&amp;...<span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

The default instantiation hook implementation called when a `outcome` is created by in place construction. Does nothing.

WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should\!

#### Parameters

  - `  ` &mdash; Some `outcome<...>` being constructed.
  - `  ` &mdash; The type of in place construction occurring.

-----

### Function `outcome_v2_xxx::hooks::override_outcome_exception`

<span id="standardese-outcome_v2_xxx__hooks__override_outcome_exception-R-S-P-NoValuePolicy-U--outcome-R-S-P-NoValuePolicy---U---"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">R</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">S</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">P</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">NoValuePolicy</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span>&nbsp;<span class="typ dec var fun">override_outcome_exception</span><span class="pun">(</span><a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, NoValuePolicy<span class="pun">&gt;</span><span class="pun">*</span>&nbsp;<span class="typ dec var fun">o</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">v</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

Used in hook implementations to override the payload/exception to something other than what was constructed.

-----

### Class `outcome_v2_xxx::outcome`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy--R"><span class="typ dec var fun">R</span></a><span class="pun">,</span>&nbsp;<span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy--S"><span class="typ dec var fun">S</span></a><span class="pun">,</span>&nbsp;<span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy--P"><span class="typ dec var fun">P</span></a><span class="pun">,</span>&nbsp;<span class="kwd">class</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy--NoValuePolicy"><span class="typ dec var fun">NoValuePolicy</span></a><span class="pun">&gt;</span>
<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">outcome</span>
<span class="pun">{</span>
<span class="kwd">public</span><span class="pun">:</span>
    &#x2F;&#x2F;=== Member types ===&#x2F;&#x2F;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__value_type"><span class="typ dec var fun">value_type</span></a>&nbsp;<span class="pun">=</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy--R"><span class="typ dec var fun">R</span></a><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__error_type"><span class="typ dec var fun">error_type</span></a>&nbsp;<span class="pun">=</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy--S"><span class="typ dec var fun">S</span></a><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__exception_type"><span class="typ dec var fun">exception_type</span></a>&nbsp;<span class="pun">=</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy--P"><span class="typ dec var fun">P</span></a><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span>&nbsp;<span class="pun">=</span> S<span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">V</span>&nbsp;<span class="pun">=</span> P<span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">W</span>&nbsp;<span class="pun">=</span> policy::default_policy&lt;T,U,V&gt;<span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__rebind-T-U-V-W-"><span class="typ dec var fun">rebind</span></a>&nbsp;<span class="pun">=</span>&nbsp;<span class="typ dec var fun">outcome</span><span class="pun">&lt;</span>T, U, V, W<span class="pun">&gt;</span><span class="pun">;</span>

<span class="kwd">protected</span><span class="pun">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">struct</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__predicate"><span class="typ dec var fun">predicate</span></a><span class="pun">;</span>

<span class="kwd">public</span><span class="pun">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__value_type_if_enabled"><span class="typ dec var fun">value_type_if_enabled</span></a>&nbsp;<span class="pun">=</span>&nbsp;<span class="typ dec var fun">std::conditional_t</span><span class="pun">&lt;</span>std::is_same&lt;value_type, error_type&gt;::value || std::is_same&lt;value_type, exception_type&gt;::value, disable_in_place_value_type, value_type<span class="pun">&gt;</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__error_type_if_enabled"><span class="typ dec var fun">error_type_if_enabled</span></a>&nbsp;<span class="pun">=</span>&nbsp;<span class="typ dec var fun">std::conditional_t</span><span class="pun">&lt;</span>std::is_same&lt;error_type, value_type&gt;::value || std::is_same&lt;error_type, exception_type&gt;::value, disable_in_place_error_type, error_type<span class="pun">&gt;</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">using</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__exception_type_if_enabled"><span class="typ dec var fun">exception_type_if_enabled</span></a>&nbsp;<span class="pun">=</span>&nbsp;<span class="typ dec var fun">std::conditional_t</span><span class="pun">&lt;</span>std::is_same&lt;exception_type, value_type&gt;::value || std::is_same&lt;exception_type, error_type&gt;::value, disable_in_place_exception_type, exception_type<span class="pun">&gt;</span><span class="pun">;</span>

<span class="kwd">protected</span><span class="pun">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="typ dec var fun">&#x27;hidden&#x27;</span>&nbsp;<span class="typ dec var fun">_ptr</span><span class="pun">;</span>

<span class="kwd">public</span><span class="pun">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T---T---outcome_v2_xxx__outcome__value_converting_constructor_tag-"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T---T---outcome_v2_xxx__outcome__value_converting_constructor_tag--t"><span class="typ dec var fun">t</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T---T---outcome_v2_xxx__outcome__error_converting_constructor_tag-"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T---T---outcome_v2_xxx__outcome__error_converting_constructor_tag--t"><span class="typ dec var fun">t</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">ErrorCondEnum</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-ErrorCondEnum----ErrorCondEnum---outcome_v2_xxx__outcome__error_condition_converting_constructor_tag-"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><span class="typ dec var fun">ErrorCondEnum</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-ErrorCondEnum----ErrorCondEnum---outcome_v2_xxx__outcome__error_condition_converting_constructor_tag--t"><span class="typ dec var fun">t</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T---T---outcome_v2_xxx__outcome__exception_converting_constructor_tag-"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T---T---outcome_v2_xxx__outcome__exception_converting_constructor_tag--t"><span class="typ dec var fun">t</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T-----T---outcome_v2_xxx__outcome__explicit_valueorerror_converting_constructor_tag-"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T-----T---outcome_v2_xxx__outcome__explicit_valueorerror_converting_constructor_tag--o"><span class="typ dec var fun">o</span></a><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">V</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">W</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T-U-V-W---outcome-T-U-V-W-const--"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><span class="typ dec var fun">outcome</span><span class="pun">&lt;</span>T, U, V, W<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T-U-V-W---outcome-T-U-V-W-const---o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">V</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">W</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T-U-V-W---outcome-T-U-V-W----"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><span class="typ dec var fun">outcome</span><span class="pun">&lt;</span>T, U, V, W<span class="pun">&gt;</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T-U-V-W---outcome-T-U-V-W-----o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">V</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T-U-V---result-T-U-V-const--"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><a href="../result#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>T, U, V<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T-U-V---result-T-U-V-const---o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">V</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T-U-V---result-T-U-V----"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><a href="../result#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>T, U, V<span class="pun">&gt;</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T-U-V---result-T-U-V-----o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="pun">...</span>&nbsp;<span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-Args---in_place_type_t-outcome_v2_xxx__outcome__value_type_if_enabled--Args------"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><span class="typ dec var fun">in_place_type_t</span><span class="pun">&lt;</span>outcome_v2_xxx::outcome::value_type_if_enabled<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-Args---in_place_type_t-outcome_v2_xxx__outcome__value_type_if_enabled--Args-------_"><span class="typ dec var fun">_</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-Args---in_place_type_t-outcome_v2_xxx__outcome__value_type_if_enabled--Args-------args"><span class="typ dec var fun">args</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="pun">...</span>&nbsp;<span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-U-Args---in_place_type_t-outcome_v2_xxx__outcome__value_type_if_enabled--std__initializer_list-U--Args------"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><span class="typ dec var fun">in_place_type_t</span><span class="pun">&lt;</span>outcome_v2_xxx::outcome::value_type_if_enabled<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-U-Args---in_place_type_t-outcome_v2_xxx__outcome__value_type_if_enabled--std__initializer_list-U--Args-------_"><span class="typ dec var fun">_</span></a><span class="pun">,</span>&nbsp;<span class="typ dec var fun">std::initializer_list</span><span class="pun">&lt;</span>U<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-U-Args---in_place_type_t-outcome_v2_xxx__outcome__value_type_if_enabled--std__initializer_list-U--Args-------il"><span class="typ dec var fun">il</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-U-Args---in_place_type_t-outcome_v2_xxx__outcome__value_type_if_enabled--std__initializer_list-U--Args-------args"><span class="typ dec var fun">args</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="pun">...</span>&nbsp;<span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-Args---in_place_type_t-outcome_v2_xxx__outcome__error_type_if_enabled--Args------"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><span class="typ dec var fun">in_place_type_t</span><span class="pun">&lt;</span>outcome_v2_xxx::outcome::error_type_if_enabled<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-Args---in_place_type_t-outcome_v2_xxx__outcome__error_type_if_enabled--Args-------_"><span class="typ dec var fun">_</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-Args---in_place_type_t-outcome_v2_xxx__outcome__error_type_if_enabled--Args-------args"><span class="typ dec var fun">args</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="pun">...</span>&nbsp;<span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-U-Args---in_place_type_t-outcome_v2_xxx__outcome__error_type_if_enabled--std__initializer_list-U--Args------"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><span class="typ dec var fun">in_place_type_t</span><span class="pun">&lt;</span>outcome_v2_xxx::outcome::error_type_if_enabled<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-U-Args---in_place_type_t-outcome_v2_xxx__outcome__error_type_if_enabled--std__initializer_list-U--Args-------_"><span class="typ dec var fun">_</span></a><span class="pun">,</span>&nbsp;<span class="typ dec var fun">std::initializer_list</span><span class="pun">&lt;</span>U<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-U-Args---in_place_type_t-outcome_v2_xxx__outcome__error_type_if_enabled--std__initializer_list-U--Args-------il"><span class="typ dec var fun">il</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-U-Args---in_place_type_t-outcome_v2_xxx__outcome__error_type_if_enabled--std__initializer_list-U--Args-------args"><span class="typ dec var fun">args</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="pun">...</span>&nbsp;<span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-Args---in_place_type_t-outcome_v2_xxx__outcome__exception_type_if_enabled--Args------"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><span class="typ dec var fun">in_place_type_t</span><span class="pun">&lt;</span>outcome_v2_xxx::outcome::exception_type_if_enabled<span class="pun">&gt;</span><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-Args---in_place_type_t-outcome_v2_xxx__outcome__exception_type_if_enabled--Args-------args"><span class="typ dec var fun">args</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="pun">...</span>&nbsp;<span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-U-Args---in_place_type_t-outcome_v2_xxx__outcome__exception_type_if_enabled--std__initializer_list-U--Args------"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><span class="typ dec var fun">in_place_type_t</span><span class="pun">&lt;</span>outcome_v2_xxx::outcome::exception_type_if_enabled<span class="pun">&gt;</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">std::initializer_list</span><span class="pun">&lt;</span>U<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-U-Args---in_place_type_t-outcome_v2_xxx__outcome__exception_type_if_enabled--std__initializer_list-U--Args-------il"><span class="typ dec var fun">il</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-U-Args---in_place_type_t-outcome_v2_xxx__outcome__exception_type_if_enabled--std__initializer_list-U--Args-------args"><span class="typ dec var fun">args</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">A1</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">A2</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="pun">...</span>&nbsp;<span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-A1-A2-Args---A1---A2---Args------"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><span class="typ dec var fun">A1</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">a1</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">A2</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">a2</span><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-A1-A2-Args---A1---A2---Args-------args"><span class="typ dec var fun">args</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-success_type-void-const--"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><a href="../success_failure#standardese-outcome_v2_xxx__success_type-T-"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>void<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-success_type-void-const---o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T---success_type-T-const--"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><a href="../success_failure#standardese-outcome_v2_xxx__success_type-T-"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>T<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T---success_type-T-const---o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T---success_type-T----"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><a href="../success_failure#standardese-outcome_v2_xxx__success_type-T-"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>T<span class="pun">&gt;</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T---success_type-T-----o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T-U---failure_type-T-U-const--"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><a href="../success_failure#standardese-outcome_v2_xxx__failure_type-EC-E-"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>T, U<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T-U---failure_type-T-U-const---o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T-U---failure_type-T-U----"><span class="typ dec var fun">outcome</span></a><span class="pun">(</span><a href="../success_failure#standardese-outcome_v2_xxx__failure_type-EC-E-"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>T, U<span class="pun">&gt;</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T-U---failure_type-T-U-----o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">V</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">W</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__operator---T-U-V-W--outcome-T-U-V-W-const--const"><span class="typ dec var fun">operator==</span></a><span class="pun">(</span><span class="typ dec var fun">outcome</span><span class="pun">&lt;</span>T, U, V, W<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__operator---T-U-V-W--outcome-T-U-V-W-const--const-o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__operator---T-U--failure_type-T-U-const--const"><span class="typ dec var fun">operator==</span></a><span class="pun">(</span><a href="../success_failure#standardese-outcome_v2_xxx__failure_type-EC-E-"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>T, U<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__operator---T-U--failure_type-T-U-const--const-o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">V</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">W</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__operator---T-U-V-W--outcome-T-U-V-W-const--const"><span class="typ dec var fun">operator!=</span></a><span class="pun">(</span><span class="typ dec var fun">outcome</span><span class="pun">&lt;</span>T, U, V, W<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__operator---T-U-V-W--outcome-T-U-V-W-const--const-o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__operator---T-U--failure_type-T-U-const--const"><span class="typ dec var fun">operator!=</span></a><span class="pun">(</span><a href="../success_failure#standardese-outcome_v2_xxx__failure_type-EC-E-"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>T, U<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__operator---T-U--failure_type-T-U-const--const-o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">void</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__swap-outcome-R-S-P-NoValuePolicy---"><span class="typ dec var fun">swap</span></a><span class="pun">(</span>outcome&lt;R, S, P, NoValuePolicy&gt;<span class="pun">&amp;</span>&nbsp;<span class="typ dec var fun">o</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

    <a href="../success_failure#standardese-outcome_v2_xxx__failure_type-EC-E-"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>outcome_v2_xxx::outcome::error_type, outcome_v2_xxx::outcome::exception_type<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__as_failure--const-"><span class="typ dec var fun">as_failure</span></a><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="pun">&amp;</span><span class="pun">;</span>

    <a href="../success_failure#standardese-outcome_v2_xxx__failure_type-EC-E-"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>outcome_v2_xxx::outcome::error_type, outcome_v2_xxx::outcome::exception_type<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__as_failure----"><span class="typ dec var fun">as_failure</span></a><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="pun">&amp;&amp;</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">using</span>&nbsp;<span class="typ dec var fun">exception_type</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="typ dec var fun">std::exception_ptr</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="typ dec var fun">exception_type</span> <a href="#standardese-outcome_v2_xxx__detail__outcome_failure_observers-Base-R-S-P-NoValuePolicy-__failure--const"><span class="typ dec var fun">failure</span></a><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">using</span>&nbsp;<span class="typ dec var fun">exception_type</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">;</span>

    &#x2F;&#x2F;=== assume_exception ===&#x2F;&#x2F;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">exception_type</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__detail__outcome_exception_observers-Base-R-S-P-NoValuePolicy-__assume_exception---"><span class="typ dec var fun">assume_exception</span></a><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="pun">&amp;</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">exception_type</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__detail__outcome_exception_observers-Base-R-S-P-NoValuePolicy-__assume_exception---"><span class="typ dec var fun">assume_exception</span></a><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="pun">&amp;</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">exception_type</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__detail__outcome_exception_observers-Base-R-S-P-NoValuePolicy-__assume_exception---"><span class="typ dec var fun">assume_exception</span></a><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="pun">&amp;&amp;</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">exception_type</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__detail__outcome_exception_observers-Base-R-S-P-NoValuePolicy-__assume_exception---"><span class="typ dec var fun">assume_exception</span></a><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="pun">&amp;&amp;</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>

    &#x2F;&#x2F;=== exception ===&#x2F;&#x2F;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">exception_type</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__detail__outcome_exception_observers-Base-R-S-P-NoValuePolicy-__exception---"><span class="typ dec var fun">exception</span></a><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="pun">&amp;</span><span class="pun">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">exception_type</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__detail__outcome_exception_observers-Base-R-S-P-NoValuePolicy-__exception---"><span class="typ dec var fun">exception</span></a><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="pun">&amp;</span><span class="pun">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">exception_type</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__detail__outcome_exception_observers-Base-R-S-P-NoValuePolicy-__exception---"><span class="typ dec var fun">exception</span></a><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="pun">&amp;&amp;</span><span class="pun">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">exception_type</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__detail__outcome_exception_observers-Base-R-S-P-NoValuePolicy-__exception---"><span class="typ dec var fun">exception</span></a><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="pun">&amp;&amp;</span><span class="pun">;</span>

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
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span> <a href="#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T-U-V--result_final-T-U-V-const--const"><span class="typ dec var fun">operator==</span></a><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">o</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span> <a href="#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T--success_type-T-const--const"><span class="typ dec var fun">operator==</span></a><span class="pun">(</span><a href="../success_failure#standardese-outcome_v2_xxx__success_type-T-"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>T<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">o</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span> <a href="#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---success_type-void-const--const"><span class="typ dec var fun">operator==</span></a><span class="pun">(</span><a href="../success_failure#standardese-outcome_v2_xxx__success_type-T-"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>void<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">o</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span> <a href="#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T--failure_type-T-void-const--const"><span class="typ dec var fun">operator==</span></a><span class="pun">(</span><a href="../success_failure#standardese-outcome_v2_xxx__failure_type-EC-E-"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>T, void<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">o</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">V</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span> <a href="#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T-U-V--result_final-T-U-V-const--const"><span class="typ dec var fun">operator!=</span></a><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">o</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span> <a href="#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T--success_type-T-const--const"><span class="typ dec var fun">operator!=</span></a><span class="pun">(</span><a href="../success_failure#standardese-outcome_v2_xxx__success_type-T-"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>T<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">o</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span> <a href="#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---success_type-void-const--const"><span class="typ dec var fun">operator!=</span></a><span class="pun">(</span><a href="../success_failure#standardese-outcome_v2_xxx__success_type-T-"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>void<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">o</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span> <a href="#standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T--failure_type-T-void-const--const"><span class="typ dec var fun">operator!=</span></a><span class="pun">(</span><a href="../success_failure#standardese-outcome_v2_xxx__failure_type-EC-E-"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>T, void<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">o</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
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
    
      - If {{<api "success_failure/#unexposed-entity-outcome-v2-xxx-trait-has-exception-ptr-v" "trait::has_exception_ptr_v<P>" >}} is true, then `std::rethrow_exception(exception()|make_exception_ptr(exception()))` \[{{<api "policies/outcome_exception_ptr_rethrow/" "policy::exception_ptr_rethrow<R, S, P>">}}\]

2.  If `.value()` called when there is no `value_type` but there is an `error_type`:
    
      - If {{<api "success_failure/#unexposed-entity-outcome-v2-xxx-trait-has-error-code-v" "trait::has_error_code_v<S>" >}}d is true, then `throw std::system_error(error()|make_error_code(error()))` \[{{<api "policies/outcome_error_code_throw_as_system_error/" "policy::error_code_throw_as_system_error<S>">}}\]
    
      - If `trait::has_exception_ptr_v<S>`, then `std::rethrow_exception(error()|make_exception_ptr(error()))` \[{{<api "policies/result_exception_ptr_rethrow/" "policy::exception_ptr_rethrow<R, S, void>">}}\]
    
      - If `S` is `void`, call `std::terminate()` \[{{<api "policies/terminate/" "policy::terminate">}}\]
    
      - If `S` is none of the above, then it is undefined behaviour \[{{<api "policies/all_narrow/" "policy::all_narrow">}}\]

3.  If `.exception()` called when there is no `exception_type`:
    
      - If `trait::has_exception_ptr_v<P>`, or if `P` is `void`, do `throw bad_outcome_access()`
    
      - If `P` is none of the above, then it is undefined behaviour \[`policy::all_narrow`\]

4.  If `.error()` called when there is no `error_type`:
    
      - If `trait::has_error_code_v<S>`, or if `trait::has_exception_ptr_v<S>`, or if `S` is `void`, do `throw bad_outcome_access()`
    
      - If `S` is none of the above, then it is undefined behaviour \[`policy::all_narrow`\]

#### Template parameters

  - `R` &mdash; The optional type of the successful result (use `void` to disable). Cannot be a reference, a `in_place_type_t<>`, `success<>`, `failure<>`, an array, a function or non-destructible.
  - `S` &mdash; The optional type of the first failure result (use `void` to disable). Must be either `void` or `DefaultConstructible`. Cannot be a reference, a `in_place_type_t<>`, `success<>`, `failure<>`, an array, a function or non-destructible.
  - `P` &mdash; The optional type of the second failure result (use `void` to disable). Must be either `void` or `DefaultConstructible`. Cannot be a reference, a `in_place_type_t<>`, `success<>`, `failure<>`, an array, a function or non-destructible.
  - `NoValuePolicy` &mdash; Policy on how to interpret types `S` and `P` when a wide observation of a not present value occurs.

### Function `outcome_v2_xxx::outcome::failure`

<span id="standardese-outcome_v2_xxx__detail__outcome_failure_observers-Base-R-S-P-NoValuePolicy-__failure--const"></span>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">exception_type</span>&nbsp;<span class="typ dec var fun">failure</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

Synthesise exception where possible.

*Requires:* `trait::has_error_code_v<S>` and `trait::has_exception_ptr_v<P>` to be true, else it does not appear.

*Returns:* A synthesised exception type: if excepted, `exception()`; if errored, `std::make_exception_ptr(std::system_error(error()))`; otherwise a default constructed exception type.

-----

### Function `outcome_v2_xxx::outcome::assume_exception`

<span id="standardese-outcome_v2_xxx__detail__outcome_exception_observers-Base-R-S-P-NoValuePolicy-__assume_exception---"></span>

<pre><code class="standardese-language-cpp">(1)&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">exception_type</span><span class="pun">&amp;</span>&nbsp;<span class="typ dec var fun">assume_exception</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="pun">&amp;</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>

(2)&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">exception_type</span><span class="pun">&amp;</span>&nbsp;<span class="typ dec var fun">assume_exception</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="pun">&amp;</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>

(3)&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">exception_type</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">assume_exception</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="pun">&amp;&amp;</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>

(4)&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">exception_type</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">assume_exception</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="pun">&amp;&amp;</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

Access exception without runtime checks.

*Preconditions:* The outcome to have an exception state, otherwise it is undefined behaviour.

*Returns:* Reference to the held `exception_type` according to overload.

-----

### Function `outcome_v2_xxx::outcome::exception`

<span id="standardese-outcome_v2_xxx__detail__outcome_exception_observers-Base-R-S-P-NoValuePolicy-__exception---"></span>

<pre><code class="standardese-language-cpp">(1)&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">exception_type</span><span class="pun">&amp;</span>&nbsp;<span class="typ dec var fun">exception</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="pun">&amp;</span><span class="pun">;</span>

(2)&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">exception_type</span><span class="pun">&amp;</span>&nbsp;<span class="typ dec var fun">exception</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="pun">&amp;</span><span class="pun">;</span>

(3)&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">exception_type</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">exception</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="pun">&amp;&amp;</span><span class="pun">;</span>

(4)&nbsp;<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">exception_type</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">exception</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="pun">&amp;&amp;</span><span class="pun">;</span>
</code></pre>

Access exception with runtime checks.

*Returns:* Reference to the held `exception_type` according to overload.

*Requires:* The outcome to have an exception state, else whatever `NoValuePolicy` says ought to happen.

-----

### Function `outcome_v2_xxx::outcome::assume_error`

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

### Function `outcome_v2_xxx::outcome::error`

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

### Conversion operator `outcome_v2_xxx::outcome::operator bool`

<span id="standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operatorbool--const"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">explicit</span>&nbsp;<span class="kwd">operator</span>&nbsp;<span class="kwd">bool</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

Checks if has value.

*Returns:* True if has value.

-----

### Function `outcome_v2_xxx::outcome::has_value`

<span id="standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__has_value--const"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span>&nbsp;<span class="typ dec var fun">has_value</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

Checks if has value.

*Returns:* True if has value.

-----

### Function `outcome_v2_xxx::outcome::has_error`

<span id="standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__has_error--const"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span>&nbsp;<span class="typ dec var fun">has_error</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

Checks if has error.

*Returns:* True if has error.

-----

### Function `outcome_v2_xxx::outcome::has_exception`

<span id="standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__has_exception--const"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span>&nbsp;<span class="typ dec var fun">has_exception</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

Checks if has exception.

*Returns:* True if has exception.

-----

### Function `outcome_v2_xxx::outcome::has_failure`

<span id="standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__has_failure--const"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span>&nbsp;<span class="typ dec var fun">has_failure</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

Checks if has error or exception.

*Returns:* True if has error or exception.

-----

### Function `outcome_v2_xxx::outcome::operator==`

<span id="standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T-U-V--result_final-T-U-V-const--const"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">V</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span>&nbsp;<span class="typ dec var fun">operator==</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">o</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

True if equal to the other result.

*Effects:* If a valid expression to do so, calls the `operator==` operation on each of the two stored items returning true if both are true. Otherwise returns false.

*Throws:* Any exception the individual `operator==` operations might throw.

#### Parameters

  - `o` &mdash; The other result to compare to.

-----

### Function `outcome_v2_xxx::outcome::operator==`

<span id="standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T--success_type-T-const--const"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span>&nbsp;<span class="typ dec var fun">operator==</span><span class="pun">(</span><a href="../success_failure#standardese-outcome_v2_xxx__success_type-T-"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>T<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">o</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

True if equal to the success type sugar.

*Effects:* If a valid expression to do so, calls the `operator==` operation on the successful item returning true if equal. Otherwise returns false.

*Throws:* Any exception the `operator==` operation might throw.

#### Parameters

  - `o` &mdash; The success type sugar to compare to.

-----

### Function `outcome_v2_xxx::outcome::operator==`

<span id="standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---success_type-void-const--const"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span>&nbsp;<span class="typ dec var fun">operator==</span><span class="pun">(</span><a href="../success_failure#standardese-outcome_v2_xxx__success_type-T-"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>void<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">o</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

True if equal to the success type sugar.

*Effects:* If a valid expression to do so, calls the `operator==` operation on the successful item returning true if equal. Otherwise returns false.

*Throws:* Any exception the `operator==` operation might throw.

#### Parameters

  - `o` &mdash; The success type sugar to compare to.

-----

### Function `outcome_v2_xxx::outcome::operator==`

<span id="standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T--failure_type-T-void-const--const"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span>&nbsp;<span class="typ dec var fun">operator==</span><span class="pun">(</span><a href="../success_failure#standardese-outcome_v2_xxx__failure_type-EC-E-"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>T, void<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">o</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
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
<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span>&nbsp;<span class="typ dec var fun">operator!=</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">o</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
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
<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span>&nbsp;<span class="typ dec var fun">operator!=</span><span class="pun">(</span><a href="../success_failure#standardese-outcome_v2_xxx__success_type-T-"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>T<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">o</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

True if not equal to the success type sugar.

*Effects:* If a valid expression to do so, calls the `operator!=` operation on the successful item returning true if not equal. Otherwise returns false.

*Throws:* Any exception the `operator!=` operation might throw.

#### Parameters

  - `o` &mdash; The success type sugar to compare to.

-----

### Function `outcome_v2_xxx::outcome::operator!=`

<span id="standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---success_type-void-const--const"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span>&nbsp;<span class="typ dec var fun">operator!=</span><span class="pun">(</span><a href="../success_failure#standardese-outcome_v2_xxx__success_type-T-"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>void<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">o</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

True if not equal to the success type sugar.

*Effects:* If a valid expression to do so, calls the `operator!=` operation on the successful item returning true if not equal. Otherwise returns false.

*Throws:* Any exception the `operator!=` operation might throw.

#### Parameters

  - `o` &mdash; The success type sugar to compare to.

-----

### Function `outcome_v2_xxx::outcome::operator!=`

<span id="standardese-outcome_v2_xxx__detail__result_final-R-S-NoValuePolicy-__operator---T--failure_type-T-void-const--const"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span>&nbsp;<span class="typ dec var fun">operator!=</span><span class="pun">(</span><a href="../success_failure#standardese-outcome_v2_xxx__failure_type-EC-E-"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>T, void<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <span class="typ dec var fun">o</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

True if not equal to the failure type sugar.

*Effects:* If a valid expression to do so, calls the `operator!=` operation on the failure item returning true if not equal. Otherwise returns false.

*Throws:* Any exception the `operator!=` operation might throw.

#### Parameters

  - `o` &mdash; The failure type sugar to compare to.

-----

### Type alias `outcome_v2_xxx::outcome::value_type`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__value_type"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">using</span>&nbsp;<span class="typ dec var fun">value_type</span>&nbsp;<span class="pun">=</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy--R"><span class="typ dec var fun">R</span></a><span class="pun">;</span>
</code></pre>

The success type.

-----

### Type alias `outcome_v2_xxx::outcome::error_type`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__error_type"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">using</span>&nbsp;<span class="typ dec var fun">error_type</span>&nbsp;<span class="pun">=</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy--S"><span class="typ dec var fun">S</span></a><span class="pun">;</span>
</code></pre>

The failure type.

-----

### Type alias `outcome_v2_xxx::outcome::exception_type`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__exception_type"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">using</span>&nbsp;<span class="typ dec var fun">exception_type</span>&nbsp;<span class="pun">=</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy--P"><span class="typ dec var fun">P</span></a><span class="pun">;</span>
</code></pre>

The exception type

-----

### Alias template `outcome_v2_xxx::outcome::rebind`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__rebind-T-U-V-W-"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span>&nbsp;<span class="pun">=</span> S<span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">V</span>&nbsp;<span class="pun">=</span> P<span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">W</span>&nbsp;<span class="pun">=</span> policy::default_policy&lt;T,U,V&gt;<span class="pun">&gt;</span>
<span class="kwd">using</span>&nbsp;<span class="typ dec var fun">rebind</span>&nbsp;<span class="pun">=</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>T, U, V, W<span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

Used to rebind this outcome to a different outcome type

-----

### Struct `outcome_v2_xxx::outcome::predicate`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__predicate"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">struct</span>&nbsp;<span class="typ dec var fun">predicate</span>
<span class="pun">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">using</span>&nbsp;<span class="typ dec var fun">base</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span>&nbsp;<span class="kwd">T</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">enable_value_converting_constructor</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">,</span>&nbsp;<span class="kwd">outcome</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span>&nbsp;<span class="pun">&amp;&amp;</span>&nbsp;<span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>&nbsp;&nbsp;<span class="kwd">enable_value_converting_constructor</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span>&nbsp;<span class="kwd">T</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">enable_error_converting_constructor</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">,</span>&nbsp;<span class="kwd">outcome</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span>&nbsp;<span class="pun">&amp;&amp;</span>&nbsp;<span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>&nbsp;&nbsp;<span class="kwd">enable_error_converting_constructor</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span>&nbsp;<span class="kwd">ErrorCondEnum</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">enable_error_condition_converting_constructor</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">ErrorCondEnum</span><span class="pun">&gt;</span><span class="pun">,</span>&nbsp;<span class="kwd">outcome</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span>&nbsp;<span class="pun">&amp;&amp;</span>&nbsp;<span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>&nbsp;&nbsp;<span class="kwd">enable_error_condition_converting_constructor</span><span class="pun">&lt;</span><span class="kwd">ErrorCondEnum</span><span class="pun">&gt;</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span>&nbsp;<span class="kwd">T</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">enable_exception_converting_constructor</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">,</span>&nbsp;<span class="kwd">outcome</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span>&nbsp;<span class="pun">&amp;&amp;</span>&nbsp;<span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>&nbsp;&nbsp;<span class="kwd">enable_exception_converting_constructor</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span>&nbsp;<span class="kwd">T</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">class</span>&nbsp;<span class="kwd">U</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">class</span>&nbsp;<span class="kwd">V</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">class</span>&nbsp;<span class="kwd">W</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">enable_compatible_conversion</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">outcome</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">,</span>&nbsp;<span class="kwd">U</span><span class="pun">,</span>&nbsp;<span class="kwd">V</span><span class="pun">,</span>&nbsp;<span class="kwd">W</span><span class="pun">&gt;</span><span class="pun">,</span>&nbsp;<span class="kwd">outcome</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span>&nbsp;<span class="pun">&amp;&amp;</span>&nbsp;<span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>&nbsp;&nbsp;<span class="kwd">enable_compatible_conversion</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">,</span>&nbsp;<span class="kwd">U</span><span class="pun">,</span>&nbsp;<span class="kwd">V</span><span class="pun">,</span>&nbsp;<span class="kwd">W</span><span class="pun">&gt;</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span><span class="pun">...</span><span class="kwd">Args</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">enable_inplace_value_constructor</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_void</span><span class="pun">&lt;</span><span class="kwd">value_type</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span>&nbsp;<span class="pun">||</span>&nbsp;<span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_constructible</span><span class="pun">&lt;</span><span class="kwd">value_type</span><span class="pun">,</span>&nbsp;<span class="kwd">Args</span><span class="pun">...</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span><span class="pun">...</span><span class="kwd">Args</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">enable_inplace_error_constructor</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_void</span><span class="pun">&lt;</span><span class="kwd">error_type</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span>&nbsp;<span class="pun">||</span>&nbsp;<span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_constructible</span><span class="pun">&lt;</span><span class="kwd">error_type</span><span class="pun">,</span>&nbsp;<span class="kwd">Args</span><span class="pun">...</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span><span class="pun">...</span><span class="kwd">Args</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">enable_inplace_exception_constructor</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_void</span><span class="pun">&lt;</span><span class="kwd">exception_type</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span>&nbsp;<span class="pun">||</span>&nbsp;<span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_constructible</span><span class="pun">&lt;</span><span class="kwd">exception_type</span><span class="pun">,</span>&nbsp;<span class="kwd">Args</span><span class="pun">...</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span><span class="pun">...</span><span class="kwd">Args</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">enable_inplace_value_error_exception_constructor</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>&nbsp;&nbsp;<span class="kwd">enable_inplace_value_error_exception_constructor</span><span class="pun">&lt;</span><span class="kwd">Args</span><span class="pun">...</span><span class="pun">&gt;</span><span class="pun">;</span>

&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="pun">...</span>&nbsp;<span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class="kwd">using</span>&nbsp;<span class="typ dec var fun">choose_inplace_value_error_exception_constructor</span>&nbsp;<span class="pun">=</span> typename base::choose_inplace_value_error_exception_constructor&lt;Args...&gt;<span class="pun">;</span>
<span class="pun">};</span>
</code></pre>

Requirement predicates for outcome.

### Unexposed entity `outcome_v2_xxx::outcome::predicate::enable_value_converting_constructor`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__predicate__enable_value_converting_constructor"></span>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span>&nbsp;<span class="kwd">T</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">enable_value_converting_constructor</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">,</span>&nbsp;<span class="kwd">outcome</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span>&nbsp;<span class="pun">&amp;&amp;</span>&nbsp;<span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>&nbsp;&nbsp;<span class="kwd">enable_value_converting_constructor</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

Predicate for the value converting constructor to be available.

-----

### Unexposed entity `outcome_v2_xxx::outcome::predicate::enable_error_converting_constructor`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__predicate__enable_error_converting_constructor"></span>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span>&nbsp;<span class="kwd">T</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">enable_error_converting_constructor</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">,</span>&nbsp;<span class="kwd">outcome</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span>&nbsp;<span class="pun">&amp;&amp;</span>&nbsp;<span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>&nbsp;&nbsp;<span class="kwd">enable_error_converting_constructor</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

Predicate for the error converting constructor to be available.

-----

### Unexposed entity `outcome_v2_xxx::outcome::predicate::enable_error_condition_converting_constructor`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__predicate__enable_error_condition_converting_constructor"></span>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span>&nbsp;<span class="kwd">ErrorCondEnum</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">enable_error_condition_converting_constructor</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">decay_t</span><span class="pun">&lt;</span><span class="kwd">ErrorCondEnum</span><span class="pun">&gt;</span><span class="pun">,</span>&nbsp;<span class="kwd">outcome</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span>&nbsp;<span class="pun">&amp;&amp;</span>&nbsp;<span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>&nbsp;&nbsp;<span class="kwd">enable_error_condition_converting_constructor</span><span class="pun">&lt;</span><span class="kwd">ErrorCondEnum</span><span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

Predicate for the error condition converting constructor to be available.

-----

### Unexposed entity `outcome_v2_xxx::outcome::predicate::enable_compatible_conversion`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__predicate__enable_compatible_conversion"></span>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span>&nbsp;<span class="kwd">T</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">class</span>&nbsp;<span class="kwd">U</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">class</span>&nbsp;<span class="kwd">V</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">class</span>&nbsp;<span class="kwd">W</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">enable_compatible_conversion</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="pun">!</span><span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_same</span><span class="pun">&lt;</span><span class="kwd">outcome</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">,</span>&nbsp;<span class="kwd">U</span><span class="pun">,</span>&nbsp;<span class="kwd">V</span><span class="pun">,</span>&nbsp;<span class="kwd">W</span><span class="pun">&gt;</span><span class="pun">,</span>&nbsp;<span class="kwd">outcome</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span>&nbsp;<span class="pun">&amp;&amp;</span>&nbsp;<span class="kwd">base</span><span class="pun">::</span><span class="typ dec var fun">template</span>&nbsp;&nbsp;<span class="kwd">enable_compatible_conversion</span><span class="pun">&lt;</span><span class="kwd">T</span><span class="pun">,</span>&nbsp;<span class="kwd">U</span><span class="pun">,</span>&nbsp;<span class="kwd">V</span><span class="pun">,</span>&nbsp;<span class="kwd">W</span><span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

Predicate for the converting constructor from a compatible input to be available.

-----

### Unexposed entity `outcome_v2_xxx::outcome::predicate::enable_inplace_value_constructor`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__predicate__enable_inplace_value_constructor"></span>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span><span class="pun">...</span><span class="kwd">Args</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">enable_inplace_value_constructor</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_void</span><span class="pun">&lt;</span><span class="kwd">value_type</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span>&nbsp;<span class="pun">||</span>&nbsp;<span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_constructible</span><span class="pun">&lt;</span><span class="kwd">value_type</span><span class="pun">,</span>&nbsp;<span class="kwd">Args</span><span class="pun">...</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>
</code></pre>

Predicate for the inplace construction of value to be available.

-----

### Unexposed entity `outcome_v2_xxx::outcome::predicate::enable_inplace_error_constructor`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__predicate__enable_inplace_error_constructor"></span>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span><span class="pun">...</span><span class="kwd">Args</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">enable_inplace_error_constructor</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_void</span><span class="pun">&lt;</span><span class="kwd">error_type</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span>&nbsp;<span class="pun">||</span>&nbsp;<span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_constructible</span><span class="pun">&lt;</span><span class="kwd">error_type</span><span class="pun">,</span>&nbsp;<span class="kwd">Args</span><span class="pun">...</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>
</code></pre>

Predicate for the inplace construction of error to be available.

-----

### Unexposed entity `outcome_v2_xxx::outcome::predicate::enable_inplace_exception_constructor`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__predicate__enable_inplace_exception_constructor"></span>

<pre><code class="standardese-language-cpp"><span class="typ dec var fun">template</span>&nbsp;<span class="pun">&lt;</span><span class="typ dec var fun">class</span><span class="pun">...</span><span class="kwd">Args</span><span class="pun">&gt;</span><span class="typ dec var fun">static</span>&nbsp;<span class="typ dec var fun">constexpr</span>&nbsp;<span class="typ dec var fun">bool</span>&nbsp;<span class="kwd">enable_inplace_exception_constructor</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_void</span><span class="pun">&lt;</span><span class="kwd">exception_type</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span>&nbsp;<span class="pun">||</span>&nbsp;<span class="kwd">std</span><span class="pun">::</span><span class="kwd">is_constructible</span><span class="pun">&lt;</span><span class="kwd">exception_type</span><span class="pun">,</span>&nbsp;<span class="kwd">Args</span><span class="pun">...</span><span class="pun">&gt;</span><span class="pun">::</span><span class="kwd">value</span><span class="pun">;</span>
</code></pre>

Predicate for the inplace construction of exception to be available.

-----

-----

### Type alias `outcome_v2_xxx::outcome::value_type_if_enabled`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__value_type_if_enabled"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">using</span>&nbsp;<span class="typ dec var fun">value_type_if_enabled</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="typ dec var fun">std::conditional_t</span><span class="pun">&lt;</span>std::is_same&lt;value_type, error_type&gt;::value || std::is_same&lt;value_type, exception_type&gt;::value, disable_in_place_value_type, value_type<span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

Used to disable in place type construction when `value_type` is ambiguous with `error_type` or `exception_type`.

-----

### Type alias `outcome_v2_xxx::outcome::error_type_if_enabled`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__error_type_if_enabled"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">using</span>&nbsp;<span class="typ dec var fun">error_type_if_enabled</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="typ dec var fun">std::conditional_t</span><span class="pun">&lt;</span>std::is_same&lt;error_type, value_type&gt;::value || std::is_same&lt;error_type, exception_type&gt;::value, disable_in_place_error_type, error_type<span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

Used to disable in place type construction when `error_type` is ambiguous with `value_type` or `exception_type`.

-----

### Type alias `outcome_v2_xxx::outcome::exception_type_if_enabled`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__exception_type_if_enabled"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">using</span>&nbsp;<span class="typ dec var fun">exception_type_if_enabled</span>&nbsp;<span class="pun">=</span>&nbsp;<span class="typ dec var fun">std::conditional_t</span><span class="pun">&lt;</span>std::is_same&lt;exception_type, value_type&gt;::value || std::is_same&lt;exception_type, error_type&gt;::value, disable_in_place_exception_type, exception_type<span class="pun">&gt;</span><span class="pun">;</span>
</code></pre>

Used to disable in place type construction when `exception_type` is ambiguous with `value_type` or `error_type`.

-----

### Constructor `outcome_v2_xxx::outcome::outcome`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T---T---outcome_v2_xxx__outcome__value_converting_constructor_tag-"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">outcome</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T---T---outcome_v2_xxx__outcome__value_converting_constructor_tag--t"><span class="typ dec var fun">t</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Converting constructor to a successful outcome.

*Effects:* Initialises the outcome with a `value_type`.

*Requires:* Type T is implicitly constructible to `value_type`, is not implicitly constructible to `error_type`, is not implicitly constructible to `exception_type` and is not `outcome<R, S, P>` and not `in_place_type<>`.

*Throws:* Any exception the construction of `value_type(T)` might throw.

#### Parameters

  - `t` &mdash; The value from which to initialise the `value_type`.

-----

### Constructor `outcome_v2_xxx::outcome::outcome`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T---T---outcome_v2_xxx__outcome__error_converting_constructor_tag-"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">outcome</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T---T---outcome_v2_xxx__outcome__error_converting_constructor_tag--t"><span class="typ dec var fun">t</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Converting constructor to an errored outcome.

*Effects:* Initialises the outcome with a `error_type`.

*Requires:* Type T is implicitly constructible to `error_type`, is not implicitly constructible to `value_type`, is not implicitly constructible to `exception_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`.

*Throws:* Any exception the construction of `error_type(T)` might throw.

#### Parameters

  - `t` &mdash; The value from which to initialise the `error_type`.

-----

### Constructor `outcome_v2_xxx::outcome::outcome`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-ErrorCondEnum----ErrorCondEnum---outcome_v2_xxx__outcome__error_condition_converting_constructor_tag-"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">ErrorCondEnum</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">outcome</span><span class="pun">(</span><span class="typ dec var fun">ErrorCondEnum</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-ErrorCondEnum----ErrorCondEnum---outcome_v2_xxx__outcome__error_condition_converting_constructor_tag--t"><span class="typ dec var fun">t</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Special error condition converting constructor to an errored outcome.

*Effects:* Initialises the outcome with a `error_type` constructed via `make_error_code(t)`.

*Requires:* `std::is_error_condition_enum<ErrorCondEnum>` must be true, `ErrorCondEnum` is not implicitly constructible to `value_type`, `error_type` nor `exception_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`; Finally, the expression `error_type(make_error_code(ErrorCondEnum()))` must be valid.

*Throws:* Any exception the construction of `error_type(make_error_code(t))` might throw.

#### Parameters

  - `t` &mdash; The error condition from which to initialise the `error_type`.

-----

### Constructor `outcome_v2_xxx::outcome::outcome`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T---T---outcome_v2_xxx__outcome__exception_converting_constructor_tag-"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">outcome</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T---T---outcome_v2_xxx__outcome__exception_converting_constructor_tag--t"><span class="typ dec var fun">t</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Converting constructor to an excepted outcome.

*Effects:* Initialises the outcome with a `exception_type`.

*Requires:* `trait::is_exception_ptr<P>` must be true; Type T is implicitly constructible to `exception_type`, is not implicitly constructible to `value_type`, is not implicitly constructible to `error_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`.

*Throws:* Any exception the construction of `exception_type(T)` might throw.

#### Parameters

  - `t` &mdash; The value from which to initialise the `exception_type`.

-----

### Constructor `outcome_v2_xxx::outcome::outcome`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T-----T---outcome_v2_xxx__outcome__explicit_valueorerror_converting_constructor_tag-"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">outcome</span><span class="pun">(</span><span class="typ dec var fun">T</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T-----T---outcome_v2_xxx__outcome__explicit_valueorerror_converting_constructor_tag--o"><span class="typ dec var fun">o</span></a><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Explicit converting constructor from a compatible `ValueOrError` type.

*Effects:* Initialises the outcome with the contents of the compatible input.

*Requires:* That `convert::value_or_error<outcome, std::decay_t<T>>{}(std::forward<T>(o))` be available. The default implementation will consume `T`’s matching the `ValueOrError` concept type. `ValueOrError` concept matches any type with a `value_type`, an `error_type`, a `.value()`, an `.error()` and a `.has_value()`.

#### Parameters

  - `o` &mdash; The input for which a `convert::value_or_error<outcome, std::decay_t<T>>{}(std::forward<T>(o))` is available.

-----

### Constructor `outcome_v2_xxx::outcome::outcome`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T-U-V-W---outcome-T-U-V-W-const--"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">V</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">W</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">outcome</span><span class="pun">(</span><a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>T, U, V, W<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T-U-V-W---outcome-T-U-V-W-const---o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Explicit converting copy constructor from a compatible outcome type.

*Effects:* Initialises the outcome with a copy of the compatible outcome.

*Requires:* Both outcome’s `value_type`, `error_type`, and `exception_type` need to be constructible, or the source `void`.

*Throws:* Any exception the construction of `value_type(T)`, `error_type(U)` or `exception_type(V)` might throw.

#### Parameters

  - `o` &mdash; The compatible outcome.

-----

### Constructor `outcome_v2_xxx::outcome::outcome`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T-U-V-W---outcome-T-U-V-W----"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">V</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">W</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">outcome</span><span class="pun">(</span><a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>T, U, V, W<span class="pun">&gt;</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T-U-V-W---outcome-T-U-V-W-----o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Explicit converting move constructor from a compatible outcome type.

*Effects:* Initialises the outcome with a move of the compatible outcome.

*Requires:* Both outcome’s `value_type`, `error_type`, and `exception_type` need to be constructible, or the source `void`.

*Throws:* Any exception the construction of `value_type(T)`, `error_type(U)` or `exception_type(V)` might throw.

#### Parameters

  - `o` &mdash; The compatible outcome.

-----

### Constructor `outcome_v2_xxx::outcome::outcome`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T-U-V---result-T-U-V-const--"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">V</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">outcome</span><span class="pun">(</span><a href="../result#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>T, U, V<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T-U-V---result-T-U-V-const---o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Explicit converting copy constructor from a compatible result type.

*Effects:* Initialises the outcome with a copy of the compatible result.

*Requires:* Both outcome’s `value_type` and `error_type` need to be constructible, or the source `void`.

*Throws:* Any exception the construction of `value_type(T)`, `error_type(U)` or `exception_type()` might throw.

#### Parameters

  - `o` &mdash; The compatible result.

-----

### Constructor `outcome_v2_xxx::outcome::outcome`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T-U-V---result-T-U-V----"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">V</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">outcome</span><span class="pun">(</span><a href="../result#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>T, U, V<span class="pun">&gt;</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T-U-V---result-T-U-V-----o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Explicit converting move constructor from a compatible result type.

*Effects:* Initialises the outcome with a move of the compatible result.

*Requires:* Both outcome’s `value_type` and `error_type` need to be constructible, or the source `void`.

*Throws:* Any exception the construction of `value_type(T)`, `error_type(U)` or `exception_type()` might throw.

#### Parameters

  - `o` &mdash; The compatible result.

-----

### Constructor `outcome_v2_xxx::outcome::outcome`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-Args---in_place_type_t-outcome_v2_xxx__outcome__value_type_if_enabled--Args------"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="pun">...</span>&nbsp;<span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">outcome</span><span class="pun">(</span><span class="typ dec var fun">in_place_type_t</span><span class="pun">&lt;</span>outcome_v2_xxx::outcome::value_type_if_enabled<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-Args---in_place_type_t-outcome_v2_xxx__outcome__value_type_if_enabled--Args-------_"><span class="typ dec var fun">_</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-Args---in_place_type_t-outcome_v2_xxx__outcome__value_type_if_enabled--Args-------args"><span class="typ dec var fun">args</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Inplace constructor to a successful value.

*Effects:* Initialises the outcome with a `value_type`.

*Requires:* `value_type` is void or `Args...` are constructible to `value_type`.

*Throws:* Any exception the construction of `value_type(Args...)` might throw.

#### Parameters

  - `_` &mdash; Tag type to indicate we are doing in place construction of `value_type`.
  - `args` &mdash; Arguments with which to in place construct.

-----

### Constructor `outcome_v2_xxx::outcome::outcome`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-U-Args---in_place_type_t-outcome_v2_xxx__outcome__value_type_if_enabled--std__initializer_list-U--Args------"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="pun">...</span>&nbsp;<span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">outcome</span><span class="pun">(</span><span class="typ dec var fun">in_place_type_t</span><span class="pun">&lt;</span>outcome_v2_xxx::outcome::value_type_if_enabled<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-U-Args---in_place_type_t-outcome_v2_xxx__outcome__value_type_if_enabled--std__initializer_list-U--Args-------_"><span class="typ dec var fun">_</span></a><span class="pun">,</span>&nbsp;<span class="typ dec var fun">std::initializer_list</span><span class="pun">&lt;</span>U<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-U-Args---in_place_type_t-outcome_v2_xxx__outcome__value_type_if_enabled--std__initializer_list-U--Args-------il"><span class="typ dec var fun">il</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-U-Args---in_place_type_t-outcome_v2_xxx__outcome__value_type_if_enabled--std__initializer_list-U--Args-------args"><span class="typ dec var fun">args</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
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

### Constructor `outcome_v2_xxx::outcome::outcome`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-Args---in_place_type_t-outcome_v2_xxx__outcome__error_type_if_enabled--Args------"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="pun">...</span>&nbsp;<span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">outcome</span><span class="pun">(</span><span class="typ dec var fun">in_place_type_t</span><span class="pun">&lt;</span>outcome_v2_xxx::outcome::error_type_if_enabled<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-Args---in_place_type_t-outcome_v2_xxx__outcome__error_type_if_enabled--Args-------_"><span class="typ dec var fun">_</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-Args---in_place_type_t-outcome_v2_xxx__outcome__error_type_if_enabled--Args-------args"><span class="typ dec var fun">args</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Inplace constructor to an unsuccessful error.

*Effects:* Initialises the outcome with a `error_type`.

*Requires:* `error_type` is void or `Args...` are constructible to `error_type`.

*Throws:* Any exception the construction of `error_type(Args...)` might throw.

#### Parameters

  - `_` &mdash; Tag type to indicate we are doing in place construction of `error_type`.
  - `args` &mdash; Arguments with which to in place construct.

-----

### Constructor `outcome_v2_xxx::outcome::outcome`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-U-Args---in_place_type_t-outcome_v2_xxx__outcome__error_type_if_enabled--std__initializer_list-U--Args------"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="pun">...</span>&nbsp;<span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">outcome</span><span class="pun">(</span><span class="typ dec var fun">in_place_type_t</span><span class="pun">&lt;</span>outcome_v2_xxx::outcome::error_type_if_enabled<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-U-Args---in_place_type_t-outcome_v2_xxx__outcome__error_type_if_enabled--std__initializer_list-U--Args-------_"><span class="typ dec var fun">_</span></a><span class="pun">,</span>&nbsp;<span class="typ dec var fun">std::initializer_list</span><span class="pun">&lt;</span>U<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-U-Args---in_place_type_t-outcome_v2_xxx__outcome__error_type_if_enabled--std__initializer_list-U--Args-------il"><span class="typ dec var fun">il</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-U-Args---in_place_type_t-outcome_v2_xxx__outcome__error_type_if_enabled--std__initializer_list-U--Args-------args"><span class="typ dec var fun">args</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
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

### Constructor `outcome_v2_xxx::outcome::outcome`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-Args---in_place_type_t-outcome_v2_xxx__outcome__exception_type_if_enabled--Args------"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="pun">...</span>&nbsp;<span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">outcome</span><span class="pun">(</span><span class="typ dec var fun">in_place_type_t</span><span class="pun">&lt;</span>outcome_v2_xxx::outcome::exception_type_if_enabled<span class="pun">&gt;</span><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-Args---in_place_type_t-outcome_v2_xxx__outcome__exception_type_if_enabled--Args-------args"><span class="typ dec var fun">args</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Inplace constructor to an unsuccessful exception.

*Effects:* Initialises the outcome with an `exception_type`.

*Requires:* `exception_type` is void or `Args...` are constructible to `exception_type`.

*Throws:* Any exception the construction of `exception_type(Args...)` might throw.

#### Parameters

  - `args` &mdash; Arguments with which to in place construct.

-----

### Constructor `outcome_v2_xxx::outcome::outcome`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-U-Args---in_place_type_t-outcome_v2_xxx__outcome__exception_type_if_enabled--std__initializer_list-U--Args------"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="pun">...</span>&nbsp;<span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">outcome</span><span class="pun">(</span><span class="typ dec var fun">in_place_type_t</span><span class="pun">&lt;</span>outcome_v2_xxx::outcome::exception_type_if_enabled<span class="pun">&gt;</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">std::initializer_list</span><span class="pun">&lt;</span>U<span class="pun">&gt;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-U-Args---in_place_type_t-outcome_v2_xxx__outcome__exception_type_if_enabled--std__initializer_list-U--Args-------il"><span class="typ dec var fun">il</span></a><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-U-Args---in_place_type_t-outcome_v2_xxx__outcome__exception_type_if_enabled--std__initializer_list-U--Args-------args"><span class="typ dec var fun">args</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Inplace constructor to an unsuccessful exception.

*Effects:* Initialises the outcome with an `exception_type`.

*Requires:* The initializer list + `Args...` are constructible to `exception_type`.

*Throws:* Any exception the construction of `exception_type(il, Args...)` might throw.

#### Parameters

  - `il` &mdash; An initializer list with which to in place construct.
  - `args` &mdash; Arguments with which to in place construct.

-----

### Constructor `outcome_v2_xxx::outcome::outcome`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-A1-A2-Args---A1---A2---Args------"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">A1</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">A2</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="pun">...</span>&nbsp;<span class="typ dec var fun">Args</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">outcome</span><span class="pun">(</span><span class="typ dec var fun">A1</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">a1</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">A2</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">a2</span><span class="pun">,</span> Args &amp;&amp;... <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-A1-A2-Args---A1---A2---Args-------args"><span class="typ dec var fun">args</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Implicit inplace constructor to successful value, or unsuccessful error, or unsuccessful exception.

*Effects:* Calls the appropriate `in_place_type_t<...>` constructor depending on constructibility of args.

*Requires:* That the args can construct exactly one of `value_type` or `error_type` or `exception_type`.

*Throws:* Any exception the `in_place_type_t<...>` constructor might throw.

#### Parameters

  - `args` &mdash; Arguments with which to in place construct.

-----

### Constructor `outcome_v2_xxx::outcome::outcome`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-success_type-void-const--"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">outcome</span><span class="pun">(</span><a href="../success_failure#standardese-outcome_v2_xxx__success_type-T-"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>void<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-success_type-void-const---o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Implicit tagged constructor of a successful outcome.

*Effects:* Initialises the outcome with a default constructed success type.

*Requires:* `value_type` to be default constructible, or `void`.

*Throws:* Any exception the construction of `value_type()` might throw.

#### Parameters

  - `o` &mdash; The compatible success type sugar.

-----

### Constructor `outcome_v2_xxx::outcome::outcome`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T---success_type-T-const--"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">outcome</span><span class="pun">(</span><a href="../success_failure#standardese-outcome_v2_xxx__success_type-T-"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>T<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T---success_type-T-const---o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Implicit tagged constructor of a successful outcome.

*Effects:* Initialises the outcome with a copy of the value in the type sugar.

*Requires:* Both outcome and success’ `value_type` need to be constructible. The source cannot be `void`.

*Throws:* Any exception the construction of `value_type(T)` might throw.

#### Parameters

  - `o` &mdash; The compatible success type sugar.

-----

### Constructor `outcome_v2_xxx::outcome::outcome`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T---success_type-T----"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">outcome</span><span class="pun">(</span><a href="../success_failure#standardese-outcome_v2_xxx__success_type-T-"><span class="typ dec var fun">success_type</span></a><span class="pun">&lt;</span>T<span class="pun">&gt;</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T---success_type-T-----o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Implicit tagged constructor of a successful outcome.

*Effects:* Initialises the outcome with a move of the value in the type sugar.

*Requires:* Both outcome and success’ `value_type` need to be constructible. The source cannot be `void`.

*Throws:* Any exception the construction of `value_type(T)` might throw.

#### Parameters

  - `o` &mdash; The compatible success type sugar.

-----

### Constructor `outcome_v2_xxx::outcome::outcome`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T-U---failure_type-T-U-const--"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">outcome</span><span class="pun">(</span><a href="../success_failure#standardese-outcome_v2_xxx__failure_type-EC-E-"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>T, U<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T-U---failure_type-T-U-const---o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Implicit tagged constructor of a failure outcome.

*Effects:* Initialises the outcome with a copy of the error and/or exception in the type sugar.

*Requires:* Both outcome and failure’s `error_type` and `exception_type` need to be constructible, or the source can be `void`.

*Throws:* Any exception the construction of `error_type(T)` and/or `exception_type(U)` might throw.

#### Parameters

  - `o` &mdash; The compatible failure type sugar.

-----

### Constructor `outcome_v2_xxx::outcome::outcome`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T-U---failure_type-T-U----"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="typ dec var fun">outcome</span><span class="pun">(</span><a href="../success_failure#standardese-outcome_v2_xxx__failure_type-EC-E-"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>T, U<span class="pun">&gt;</span><span class="pun">&amp;&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__outcome-T-U---failure_type-T-U-----o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Implicit tagged constructor of a failure outcome.

*Effects:* Initialises the outcome with a copy of the error and/or exception in the type sugar.

*Requires:* Both outcome and failure’s `error_type` and `exception_type` need to be constructible, or the source can be `void`.

*Throws:* Any exception the construction of `error_type(T)` and/or `exception_type(U)` might throw.

#### Parameters

  - `o` &mdash; The compatible failure type sugar.

-----

### Function `outcome_v2_xxx::outcome::operator==`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__operator---T-U-V-W--outcome-T-U-V-W-const--const"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">V</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">W</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span>&nbsp;<span class="typ dec var fun">operator==</span><span class="pun">(</span><a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>T, U, V, W<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__operator---T-U-V-W--outcome-T-U-V-W-const--const-o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

True if equal to the other outcome.

*Effects:* If a valid expression to do so, calls the `operator==` operation on each of the three stored items returning true if both are true. Otherwise returns false.

*Throws:* Any exception the individual `operator==` operations might throw.

#### Parameters

  - `o` &mdash; The other outcome to compare to.

-----

### Function `outcome_v2_xxx::outcome::operator==`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__operator---T-U--failure_type-T-U-const--const"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span>&nbsp;<span class="typ dec var fun">operator==</span><span class="pun">(</span><a href="../success_failure#standardese-outcome_v2_xxx__failure_type-EC-E-"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>T, U<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__operator---T-U--failure_type-T-U-const--const-o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

True if equal to the failure type sugar.

*Effects:* If a valid expression to do so, calls the `operator==` operation on the failure items returning true if equal. Otherwise returns false.

*Throws:* Any exception the `operator==` operations might throw.

#### Parameters

  - `o` &mdash; The failure type sugar to compare to.

-----

### Function `outcome_v2_xxx::outcome::operator!=`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__operator---T-U-V-W--outcome-T-U-V-W-const--const"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">V</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">W</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span>&nbsp;<span class="typ dec var fun">operator!=</span><span class="pun">(</span><a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>T, U, V, W<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__operator---T-U-V-W--outcome-T-U-V-W-const--const-o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

True if not equal to the other outcome.

*Effects:* If a valid expression to do so, calls the `operator!=` operation on each of the three stored items, returning true if any are not equal. Otherwise returns true.

*Throws:* Any exception the individual `operator!=` operations might throw.

#### Parameters

  - `o` &mdash; The other outcome to compare to.

-----

### Function `outcome_v2_xxx::outcome::operator!=`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__operator---T-U--failure_type-T-U-const--const"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span>&nbsp;<span class="typ dec var fun">operator!=</span><span class="pun">(</span><a href="../success_failure#standardese-outcome_v2_xxx__failure_type-EC-E-"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>T, U<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__operator---T-U--failure_type-T-U-const--const-o"><span class="typ dec var fun">o</span></a><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

True if not equal to the failure type sugar.

*Effects:* If a valid expression to do so, calls the `operator!=` operation on the failure items returning true if not equal. Otherwise returns false.

*Throws:* Any exception the `operator!=` operations might throw.

#### Parameters

  - `o` &mdash; The failure type sugar to compare to.

-----

### Function `outcome_v2_xxx::outcome::swap`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__swap-outcome-R-S-P-NoValuePolicy---"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">void</span>&nbsp;<span class="typ dec var fun">swap</span><span class="pun">(</span>outcome&lt;R, S, P, NoValuePolicy&gt;<span class="pun">&amp;</span>&nbsp;<span class="typ dec var fun">o</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Swaps this result with another result

*Effects:* Any `R` and/or `S` is swapped along with the metadata tracking them.

-----

### Function `outcome_v2_xxx::outcome::as_failure`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__as_failure--const-"></span>

<pre><code class="standardese-language-cpp"><a href="../success_failure#standardese-outcome_v2_xxx__failure_type-EC-E-"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>outcome_v2_xxx::outcome::error_type, outcome_v2_xxx::outcome::exception_type<span class="pun">&gt;</span>&nbsp;<span class="typ dec var fun">as_failure</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="kwd">const</span>&nbsp;<span class="pun">&amp;</span><span class="pun">;</span>
</code></pre>

Returns this outcome as a `failure_type` with any errored and/or excepted state copied.

*Requires:* This outcome to have a failed state, else whatever `assume_error()` would do.

-----

### Function `outcome_v2_xxx::outcome::as_failure`

<span id="standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-__as_failure----"></span>

<pre><code class="standardese-language-cpp"><a href="../success_failure#standardese-outcome_v2_xxx__failure_type-EC-E-"><span class="typ dec var fun">failure_type</span></a><span class="pun">&lt;</span>outcome_v2_xxx::outcome::error_type, outcome_v2_xxx::outcome::exception_type<span class="pun">&gt;</span>&nbsp;<span class="typ dec var fun">as_failure</span><span class="pun">(</span><span class="pun">)</span>&nbsp;<span class="pun">&amp;&amp;</span><span class="pun">;</span>
</code></pre>

Returns this outcome as a `failure_type` with any errored and/or excepted state moved.

*Requires:* This outcome to have a failed state, else whatever `assume_error()` would do.

-----

-----

### Function `outcome_v2_xxx::operator==`

<span id="standardese-outcome_v2_xxx__operator---T-U-V-R-S-P-N---result-T-U-V-const--outcome-R-S-P-N-const--"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">V</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">R</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">S</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">P</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">N</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span>&nbsp;<span class="typ dec var fun">operator==</span><span class="pun">(</span><a href="../result#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>T, U, V<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__operator---T-U-V-R-S-P-N---result-T-U-V-const--outcome-R-S-P-N-const---a"><span class="typ dec var fun">a</span></a><span class="pun">,</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, N<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__operator---T-U-V-R-S-P-N---result-T-U-V-const--outcome-R-S-P-N-const---b"><span class="typ dec var fun">b</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

True if the result is equal to the outcome

*Remarks:* Implemented as `b == a`.

*Requires:* That the expression `b == a` is a valid expression.

*Throws:* Any exception that `b == a` might throw.

#### Parameters

  - `a` &mdash; The result to compare.
  - `b` &mdash; The outcome to compare.

-----

### Function `outcome_v2_xxx::operator!=`

<span id="standardese-outcome_v2_xxx__operator---T-U-V-R-S-P-N---result-T-U-V-const--outcome-R-S-P-N-const--"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">T</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">V</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">R</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">S</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">P</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">N</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="kwd">bool</span>&nbsp;<span class="typ dec var fun">operator!=</span><span class="pun">(</span><a href="../result#standardese-outcome_v2_xxx__result-R-S-NoValuePolicy-"><span class="typ dec var fun">result</span></a><span class="pun">&lt;</span>T, U, V<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__operator---T-U-V-R-S-P-N---result-T-U-V-const--outcome-R-S-P-N-const---a"><span class="typ dec var fun">a</span></a><span class="pun">,</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, N<span class="pun">&gt;</span>&nbsp;<span class="kwd">const</span><span class="pun">&amp;</span> <a href="#standardese-outcome_v2_xxx__operator---T-U-V-R-S-P-N---result-T-U-V-const--outcome-R-S-P-N-const---b"><span class="typ dec var fun">b</span></a><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

True if the result is not equal to the outcome

*Remarks:* Implemented as `b != a`.

*Requires:* That the expression `b != a` is a valid expression.

*Throws:* Any exception that `b != a` might throw.

#### Parameters

  - `a` &mdash; The result to compare.
  - `b` &mdash; The outcome to compare.

-----

### Function `outcome_v2_xxx::swap`

<span id="standardese-outcome_v2_xxx__swap-R-S-P-N--outcome-R-S-P-N---outcome-R-S-P-N---"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">R</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">S</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">P</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">N</span><span class="pun">&gt;</span>
<span class="kwd">void</span>&nbsp;<span class="typ dec var fun">swap</span><span class="pun">(</span><a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, N<span class="pun">&gt;</span><span class="pun">&amp;</span>&nbsp;<span class="typ dec var fun">a</span><span class="pun">,</span> <a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, N<span class="pun">&gt;</span><span class="pun">&amp;</span>&nbsp;<span class="typ dec var fun">b</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">(</span><span class="typ dec var fun">&#x27;hidden&#x27;</span><span class="pun">)</span><span class="pun">;</span>
</code></pre>

Specialise swap for outcome.

*Effects:* Calls `a.swap(b)`.

-----

<span id="standardese-outcome_v2_xxx__hooks"></span>

### Function `outcome_v2_xxx::hooks::override_outcome_exception`

<span id="standardese-outcome_v2_xxx__hooks__override_outcome_exception-R-S-P-NoValuePolicy-U--outcome-R-S-P-NoValuePolicy---U---"></span>

<pre><code class="standardese-language-cpp"><span class="kwd">template</span>&nbsp;<span class="pun">&lt;</span><span class="kwd">class</span>&nbsp;<span class="typ dec var fun">R</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">S</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">P</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">NoValuePolicy</span><span class="pun">,</span>&nbsp;<span class="kwd">class</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&gt;</span>
<span class="kwd">constexpr</span>&nbsp;<span class="kwd">void</span>&nbsp;<span class="typ dec var fun">override_outcome_exception</span><span class="pun">(</span><a href="#standardese-outcome_v2_xxx__outcome-R-S-P-NoValuePolicy-"><span class="typ dec var fun">outcome</span></a><span class="pun">&lt;</span>R, S, P, NoValuePolicy<span class="pun">&gt;</span><span class="pun">*</span>&nbsp;<span class="typ dec var fun">o</span><span class="pun">,</span>&nbsp;<span class="typ dec var fun">U</span><span class="pun">&amp;&amp;</span>&nbsp;<span class="typ dec var fun">v</span><span class="pun">)</span>&nbsp;<span class="kwd">noexcept</span><span class="pun">;</span>
</code></pre>

Used to set/override an exception during a construction hook implementation.

*Effects:* Sets the exception of the outcome to the given value.

#### Parameters

  - `o` &mdash; The outcome you wish to change.
  - `v` &mdash; Exception to be set.

-----
