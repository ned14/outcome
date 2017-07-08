+++
title = "iostream support"
slug = "iostream_support.md"
weight = 50
+++
# Header file `iostream_support.hpp`<a id="iostream_support.hpp"></a>

<pre><code class="language-cpp">#define <a href='doc_iostream_support.md#iostream_support.hpp'>OUTCOME_IOSTREAM_SUPPORT_HPP</a>

namespace <a href='doc_try.md#try.hpp'>outcome_v2_xxx</a>
{
    template &lt;class R, class S, class P&gt;
    <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::istream'>std::istream</a>&amp; <a href='doc_iostream_support.md#outcome_v2_xxx::operator--(std::istream&,result-R,S,P-&)'>operator&gt;&gt;</a>(<a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::istream'>std::istream</a>&amp; s, <a href='doc_result.md#outcome_v2_xxx::result-R,S,NoValuePolicy-'>result&lt;R, S, P&gt;</a>&amp; v);
    
    template &lt;class R, class S, class P&gt;
    <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::ostream'>std::ostream</a>&amp; <a href='doc_iostream_support.md#outcome_v2_xxx::operator--(std::ostream&,constresult-R,S,P-&)'>operator&lt;&lt;</a>(<a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::ostream'>std::ostream</a>&amp; s, const <a href='doc_result.md#outcome_v2_xxx::result-R,S,NoValuePolicy-'>result&lt;R, S, P&gt;</a>&amp; v);
    
    template &lt;class R, class S, class P&gt;
    <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::string'>std::string</a> <a href='doc_iostream_support.md#outcome_v2_xxx::print(constresult-R,S,P-&)'>print</a>(const <a href='doc_result.md#outcome_v2_xxx::result-R,S,NoValuePolicy-'>result&lt;R, S, P&gt;</a>&amp; v);
    
    template &lt;class R, class S, class P, class N&gt;
    <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::istream'>std::istream</a>&amp; <a href='doc_iostream_support.md#outcome_v2_xxx::operator--(std::istream&,outcome-R,S,P,N-&)'>operator&gt;&gt;</a>(<a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::istream'>std::istream</a>&amp; s, <a href='doc_outcome.md#outcome_v2_xxx::outcome-R,S,P,NoValuePolicy-'>outcome&lt;R, S, P, N&gt;</a>&amp; v);
    
    template &lt;class R, class S, class P, class N&gt;
    <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::ostream'>std::ostream</a>&amp; <a href='doc_iostream_support.md#outcome_v2_xxx::operator--(std::ostream&,constoutcome-R,S,P,N-&)'>operator&lt;&lt;</a>(<a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::ostream'>std::ostream</a>&amp; s, const <a href='doc_outcome.md#outcome_v2_xxx::outcome-R,S,P,NoValuePolicy-'>outcome&lt;R, S, P, N&gt;</a>&amp; v);
    
    template &lt;class R, class S, class P, class N&gt;
    <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::string'>std::string</a> <a href='doc_iostream_support.md#outcome_v2_xxx::print(constoutcome-R,S,P,N-&)'>print</a>(const <a href='doc_outcome.md#outcome_v2_xxx::outcome-R,S,P,NoValuePolicy-'>outcome&lt;R, S, P, N&gt;</a>&amp; v);
}</code></pre>

## Input operator `outcome_v2_xxx::operator>>`<a id="outcome_v2_xxx::operator--(std::istream&,result-R,S,P-&)"></a>

<pre><code class="language-cpp">template &lt;class R, class S, class P&gt;
<a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::istream'>std::istream</a>&amp; operator&gt;&gt;(<a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::istream'>std::istream</a>&amp; s, <a href='doc_result.md#outcome_v2_xxx::result-R,S,NoValuePolicy-'>result&lt;R, S, P&gt;</a>&amp; v);</code></pre>

Deserialise a result

## Output operator `outcome_v2_xxx::operator<<`<a id="outcome_v2_xxx::operator--(std::ostream&,constresult-R,S,P-&)"></a>

<pre><code class="language-cpp">template &lt;class R, class S, class P&gt;
<a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::ostream'>std::ostream</a>&amp; operator&lt;&lt;(<a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::ostream'>std::ostream</a>&amp; s, const <a href='doc_result.md#outcome_v2_xxx::result-R,S,NoValuePolicy-'>result&lt;R, S, P&gt;</a>&amp; v);</code></pre>

Serialise a result

## Function template `outcome_v2_xxx::print`<a id="outcome_v2_xxx::print(constresult-R,S,P-&)"></a>

<pre><code class="language-cpp">template &lt;class R, class S, class P&gt;
<a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::string'>std::string</a> print(const <a href='doc_result.md#outcome_v2_xxx::result-R,S,NoValuePolicy-'>result&lt;R, S, P&gt;</a>&amp; v);</code></pre>

Debug print a result

## Input operator `outcome_v2_xxx::operator>>`<a id="outcome_v2_xxx::operator--(std::istream&,outcome-R,S,P,N-&)"></a>

<pre><code class="language-cpp">template &lt;class R, class S, class P, class N&gt;
<a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::istream'>std::istream</a>&amp; operator&gt;&gt;(<a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::istream'>std::istream</a>&amp; s, <a href='doc_outcome.md#outcome_v2_xxx::outcome-R,S,P,NoValuePolicy-'>outcome&lt;R, S, P, N&gt;</a>&amp; v);</code></pre>

Deserialise an outcome

## Output operator `outcome_v2_xxx::operator<<`<a id="outcome_v2_xxx::operator--(std::ostream&,constoutcome-R,S,P,N-&)"></a>

<pre><code class="language-cpp">template &lt;class R, class S, class P, class N&gt;
<a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::ostream'>std::ostream</a>&amp; operator&lt;&lt;(<a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::ostream'>std::ostream</a>&amp; s, const <a href='doc_outcome.md#outcome_v2_xxx::outcome-R,S,P,NoValuePolicy-'>outcome&lt;R, S, P, N&gt;</a>&amp; v);</code></pre>

Serialise an outcome

## Function template `outcome_v2_xxx::print`<a id="outcome_v2_xxx::print(constoutcome-R,S,P,N-&)"></a>

<pre><code class="language-cpp">template &lt;class R, class S, class P, class N&gt;
<a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::string'>std::string</a> print(const <a href='doc_outcome.md#outcome_v2_xxx::outcome-R,S,P,NoValuePolicy-'>outcome&lt;R, S, P, N&gt;</a>&amp; v);</code></pre>

Debug print an outcome

-----
