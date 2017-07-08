+++
title = "Utilities"
slug = "doc_utils.md"
weight = 40
+++
# Header file `utils.hpp`<a id="utils.hpp"></a>

<pre><code class="language-cpp">#define <a href='doc_utils.md#utils.hpp'>OUTCOME_ERROR_FROM_EXCEPTION_HPP</a>

namespace <a href='doc_try.md#try.hpp'>outcome_v2_xxx</a>
{
    <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::error_code'>std::error_code</a> <a href='doc_utils.md#outcome_v2_xxx::error_from_exception(std::exception_ptr&&,std::error_code)'>error_from_exception</a>(<a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::exception_ptr'>std::exception_ptr</a>&amp;&amp; ep, <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::error_code'>std::error_code</a> not_matched = std::make_error_code(std::errc::resource_unavailable_try_again)) noexcept;
}</code></pre>

## Function `outcome_v2_xxx::error_from_exception`<a id="outcome_v2_xxx::error_from_exception(std::exception_ptr&&,std::error_code)"></a>

<pre><code class="language-cpp"><a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::error_code'>std::error_code</a> error_from_exception(<a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::exception_ptr'>std::exception_ptr</a>&amp;&amp; ep, <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::error_code'>std::error_code</a> not_matched = std::make_error_code(std::errc::resource_unavailable_try_again)) noexcept;</code></pre>

Utility function which tries to match the exception in the pointer provided to an equivalent error code. Ought to work for all standard STL types. param e The pointer to an exception to convert. If matched, on exit this is reset to a null pointer. param not\_matched The error code to return if we could not match the exception. Note that a null pointer in returns a null error code.

effects Rethrows the exception in the pointer, and via a long sequence of `catch` clauses attempts to match the equivalent error code. If a match is found, the pointer is reset to null. If a match is not found, *not\_matched* is returned instead and the pointer is left unmodified.

-----
