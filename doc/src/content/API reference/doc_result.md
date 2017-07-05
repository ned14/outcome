+++
title = "result<R, S>"
slug = "doc_result.md"
+++
# Header file `result.hpp`<a id="result.hpp"></a>

<pre><code class="language-cpp">#define <a href='doc_result.md#result.hpp'>OUTCOME_RESULT_HPP</a>

#define <a href='doc_result.md#result.hpp'>OUTCOME_ENABLE_POSITIVE_STATUS</a>

namespace <a href='doc_result.md#result.hpp'>outcome_v2_c9e8c1da</a>
{
    class <a href='doc_result.md#outcome_v2_c9e8c1da::bad_result_access'>bad_result_access</a>;
    
    struct <a href='doc_result.md#outcome_v2_c9e8c1da::no_value_type'>no_value_type</a>;
    
    struct <a href='doc_result.md#outcome_v2_c9e8c1da::no_error_type'>no_error_type</a>;
    
    namespace <a href='doc_result.md#result.hpp'>impl</a>
    {
        template &lt;class R, class EC, class NoValuePolicy&gt;
        class <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_storage-R,EC,NoValuePolicy-'>result_storage</a>;
        
        template &lt;class Base, class R, class NoValuePolicy&gt;
        class <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_value_observers-Base,R,NoValuePolicy-'>result_value_observers</a>;
        
        template &lt;class Base, class NoValuePolicy&gt;
        class <a href='doc_result.md#result.hpp'>result_value_observers&lt;Base, void, NoValuePolicy&gt;</a>;
        
        template &lt;class Base, class EC, class NoValuePolicy&gt;
        class <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_error_observers-Base,EC,NoValuePolicy-'>result_error_observers</a>;
        
        template &lt;class Base, class NoValuePolicy&gt;
        class <a href='doc_result.md#result.hpp'>result_error_observers&lt;Base, void, NoValuePolicy&gt;</a>;
        
        template &lt;class R, class EC, class NoValuePolicy&gt;
        using <a href='doc_result.md#result.hpp'>select_result_impl</a> = <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_error_observers-Base,EC,NoValuePolicy-'>result_error_observers&lt;result_value_observers&lt;result_storage&lt;R, EC, NoValuePolicy&gt;, R, NoValuePolicy&gt;, EC, NoValuePolicy&gt;</a>;
        
        template &lt;class R, class S, class NoValuePolicy&gt;
        class <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_final-R,S,NoValuePolicy-'>result_final</a>;
    }
    
    namespace <a href='doc_result.md#outcome_v2_c9e8c1da::policy'>policy</a>
    {
        template &lt;class EC&gt;
        struct <a href='doc_result.md#outcome_v2_c9e8c1da::policy::throw_directly-EC-'>throw_directly</a>;
        
        template &lt;class EC&gt;
        struct <a href='doc_result.md#outcome_v2_c9e8c1da::policy::error_code_throw_as_system_error-EC-'>error_code_throw_as_system_error</a>;
        
        template &lt;class EC&gt;
        struct <a href='doc_result.md#outcome_v2_c9e8c1da::policy::exception_ptr_rethrow-EC-'>exception_ptr_rethrow</a>;
        
        struct <a href='doc_result.md#outcome_v2_c9e8c1da::policy::terminate'>terminate</a>;
        
        template &lt;class EC&gt;
        using <a href='doc_result.md#outcome_v2_c9e8c1da::policy::default_result_policy-EC-'>default_result_policy</a> = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::conditional_t%3c//std::is_void%3cEC%3e::value,//terminate,//std::conditional_t%3c//detail::is_same_or_constructible%3cstd::error_code,EC%3e,error_code_throw_as_system_error%3cEC%3e,//std::conditional_t%3c//detail::is_same_or_constructible%3cstd::exception_ptr,EC%3e,exception_ptr_rethrow%3cEC%3e,//throw_directly%3cEC%3e//%3e%3e%3e'>std::conditional_t&lt;//std::is_void&lt;EC&gt;::value, //terminate, //std::conditional_t&lt;//detail::is_same_or_constructible&lt;std::error_code, EC&gt;, error_code_throw_as_system_error&lt;EC&gt;, //std::conditional_t&lt;//detail::is_same_or_constructible&lt;std::exception_ptr, EC&gt;, exception_ptr_rethrow&lt;EC&gt;, //throw_directly&lt;EC&gt;//&gt;&gt;&gt;</a>;
    }
    
    template &lt;class T, class U&gt;
    constexpr void <a href='doc_result.md#outcome_v2_c9e8c1da::hook_result_construction(in_place_type_t-T-,U*)'>hook_result_construction</a>(in_place_type_t&lt;T&gt;, U*) noexcept;
    
    template &lt;class T, class U&gt;
    constexpr void <a href='doc_result.md#outcome_v2_c9e8c1da::hook_result_copy_construction(in_place_type_t-T-,U*)'>hook_result_copy_construction</a>(in_place_type_t&lt;T&gt;, U*) noexcept;
    
    template &lt;class T, class U&gt;
    constexpr void <a href='doc_result.md#outcome_v2_c9e8c1da::hook_result_move_construction(in_place_type_t-T-,U*)'>hook_result_move_construction</a>(in_place_type_t&lt;T&gt;, U*) noexcept;
    
    template &lt;class T, class U&gt;
    constexpr void <a href='doc_result.md#outcome_v2_c9e8c1da::hook_result_in_place_construction(in_place_type_t-T-,U*)'>hook_result_in_place_construction</a>(in_place_type_t&lt;T&gt;, U*) noexcept;
    
    template &lt;class R, class S = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::error_code'>std::error_code</a>, class NoValuePolicy = policy::default_result_policy&lt;S&gt;
    class <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-'>result</a>;
}</code></pre>

## Class `outcome_v2_c9e8c1da::bad_result_access`<a id="outcome_v2_c9e8c1da::bad_result_access"></a>

<pre><code class="language-cpp">class bad_result_access
: public <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::logic_error'>std::logic_error</a>
{
public:
    <a href='doc_result.md#outcome_v2_c9e8c1da::bad_result_access'>bad_result_access</a>(const char* what);
};</code></pre>

Thrown when you try to access state in a `result<R, S>` which isn't present.

## Struct `outcome_v2_c9e8c1da::no_value_type`<a id="outcome_v2_c9e8c1da::no_value_type"></a>

<pre><code class="language-cpp">struct no_value_type
{
    <a href='doc_result.md#outcome_v2_c9e8c1da::no_value_type'>no_value_type</a>() = delete;
};</code></pre>

Placeholder type to indicate there is no value type

## Struct `outcome_v2_c9e8c1da::no_error_type`<a id="outcome_v2_c9e8c1da::no_error_type"></a>

<pre><code class="language-cpp">struct no_error_type
{
    <a href='doc_result.md#outcome_v2_c9e8c1da::no_error_type'>no_error_type</a>() = delete;
};</code></pre>

Placeholder type to indicate there is no error type

## Class template `outcome_v2_c9e8c1da::impl::result_storage`<a id="outcome_v2_c9e8c1da::impl::result_storage-R,EC,NoValuePolicy-"></a>

<pre><code class="language-cpp">template &lt;class R, class EC, class NoValuePolicy&gt;
class result_storage
{
protected:
    using <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_storage-R,EC,NoValuePolicy-'>_value_type</a> = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::conditional_t%3cstd::is_same%3cR,EC%3e::value,disable_in_place_value_type,R%3e'>std::conditional_t&lt;std::is_same&lt;R, EC&gt;::value, disable_in_place_value_type, R&gt;</a>;
    
    using <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_storage-R,EC,NoValuePolicy-'>_error_type</a> = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::conditional_t%3cstd::is_same%3cR,EC%3e::value,disable_in_place_error_type,EC%3e'>std::conditional_t&lt;std::is_same&lt;R, EC&gt;::value, disable_in_place_error_type, EC&gt;</a>;
    
    detail::value_storage_select_impl&lt;_value_type&gt; <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_storage-R,EC,NoValuePolicy-'>_state</a>;
    
    detail::devoid&lt;_error_type&gt; <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_storage-R,EC,NoValuePolicy-'>_error</a>;
    
    <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_storage-R,EC,NoValuePolicy-'>result_storage</a>() = default;
    
    template &lt;class ... Args&gt;
    constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_storage-R,EC,NoValuePolicy-'>result_storage</a>(in_place_type_t&lt;_value_type&gt; _, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;_value_type, Args...&gt;::value);
    
    template &lt;class U, class ... Args&gt;
    constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_storage-R,EC,NoValuePolicy-'>result_storage</a>(in_place_type_t&lt;_value_type&gt; _, <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::initializer_list%3cU%3e'>std::initializer_list&lt;U&gt;</a> il, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;_value_type, std::initializer_list&lt;U&gt;, Args...&gt;::value);
    
    template &lt;class ... Args&gt;
    constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_storage-R,EC,NoValuePolicy-'>result_storage</a>(in_place_type_t&lt;_error_type&gt;, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;_error_type, Args...&gt;::value);
    
    template &lt;class U, class ... Args&gt;
    constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_storage-R,EC,NoValuePolicy-'>result_storage</a>(in_place_type_t&lt;_error_type&gt;, <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::initializer_list%3cU%3e'>std::initializer_list&lt;U&gt;</a> il, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;_error_type, std::initializer_list&lt;U&gt;, Args...&gt;::value);
    
    struct <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_storage-R,EC,NoValuePolicy-'>compatible_conversion_tag</a>;
    
    template &lt;class T, class U, class V&gt;
    constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_storage-R,EC,NoValuePolicy-'>result_storage</a>(<a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_storage-R,EC,NoValuePolicy-'>compatible_conversion_tag</a>, const <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_storage-R,EC,NoValuePolicy-'>result_storage&lt;T, U, V&gt;</a>&amp; o) noexcept(std::is_nothrow_constructible&lt;_value_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;_error_type, U&gt;::value);
    
    template &lt;class U, class V&gt;
    constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_storage-R,EC,NoValuePolicy-'>result_storage</a>(<a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_storage-R,EC,NoValuePolicy-'>compatible_conversion_tag</a>, const <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_storage-R,EC,NoValuePolicy-'>result_storage&lt;void, U, V&gt;</a>&amp; o) noexcept(std::is_nothrow_constructible&lt;_error_type, U&gt;::value);
    
    template &lt;class T, class V&gt;
    constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_storage-R,EC,NoValuePolicy-'>result_storage</a>(<a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_storage-R,EC,NoValuePolicy-'>compatible_conversion_tag</a>, const <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_storage-R,EC,NoValuePolicy-'>result_storage&lt;T, void, V&gt;</a>&amp; o) noexcept(std::is_nothrow_constructible&lt;_value_type, T&gt;::value);
    
    template &lt;class T, class U, class V&gt;
    constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_storage-R,EC,NoValuePolicy-'>result_storage</a>(<a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_storage-R,EC,NoValuePolicy-'>compatible_conversion_tag</a>, <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_storage-R,EC,NoValuePolicy-'>result_storage&lt;T, U, V&gt;</a>&amp;&amp; o) noexcept(std::is_nothrow_constructible&lt;_value_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;_error_type, U&gt;::value);
    
    template &lt;class U, class V&gt;
    constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_storage-R,EC,NoValuePolicy-'>result_storage</a>(<a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_storage-R,EC,NoValuePolicy-'>compatible_conversion_tag</a>, <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_storage-R,EC,NoValuePolicy-'>result_storage&lt;void, U, V&gt;</a>&amp;&amp; o) noexcept(std::is_nothrow_constructible&lt;_error_type, U&gt;::value);
    
    template &lt;class T, class V&gt;
    constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_storage-R,EC,NoValuePolicy-'>result_storage</a>(<a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_storage-R,EC,NoValuePolicy-'>compatible_conversion_tag</a>, <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_storage-R,EC,NoValuePolicy-'>result_storage&lt;T, void, V&gt;</a>&amp;&amp; o) noexcept(std::is_nothrow_constructible&lt;_value_type, T&gt;::value);
};</code></pre>

The base implementation type of `result<R, EC, NoValuePolicy>`. Only appears separate due to standardese limitations.

## Class template `outcome_v2_c9e8c1da::impl::result_value_observers`<a id="outcome_v2_c9e8c1da::impl::result_value_observers-Base,R,NoValuePolicy-"></a>

<pre><code class="language-cpp">template &lt;class Base, class R, class NoValuePolicy&gt;
class result_value_observers
: public Base
{
public:
    using <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a> = R;
    
    using Base::Base;
    
    constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a>&amp; <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_value_observers-Base,R,NoValuePolicy-::assume_value()&'>assume_value</a>() &amp; noexcept;
    constexpr const <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a>&amp; <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_value_observers-Base,R,NoValuePolicy-::assume_value()&'>assume_value</a>() const &amp; noexcept;
    constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a>&amp;&amp; <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_value_observers-Base,R,NoValuePolicy-::assume_value()&'>assume_value</a>() &amp;&amp; noexcept;
    constexpr const <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a>&amp;&amp; <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_value_observers-Base,R,NoValuePolicy-::assume_value()&'>assume_value</a>() const &amp;&amp; noexcept;
    
    constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a>&amp; <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_value_observers-Base,R,NoValuePolicy-::value()&'>value</a>() &amp;;
    constexpr const <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a>&amp; <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_value_observers-Base,R,NoValuePolicy-::value()&'>value</a>() const &amp;;
    constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a>&amp;&amp; <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_value_observers-Base,R,NoValuePolicy-::value()&'>value</a>() &amp;&amp;;
    constexpr const <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a>&amp;&amp; <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_value_observers-Base,R,NoValuePolicy-::value()&'>value</a>() const &amp;&amp;;
};</code></pre>

The value observers implementation of `result<R, EC, NoValuePolicy>`. Only appears separate due to standardese limitations.

### Function `outcome_v2_c9e8c1da::impl::result_value_observers::assume_value`<a id="outcome_v2_c9e8c1da::impl::result_value_observers-Base,R,NoValuePolicy-::assume_value()&"></a>

<pre><code class="language-cpp">(1)  constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a>&amp; assume_value() &amp; noexcept;

(2)  constexpr const <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a>&amp; assume_value() const &amp; noexcept;

(3)  constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a>&amp;&amp; assume_value() &amp;&amp; noexcept;

(4)  constexpr const <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a>&amp;&amp; assume_value() const &amp;&amp; noexcept;</code></pre>

Access value without runtime checks.

*Returns*: Reference to the held `value_type` according to overload.

### Function `outcome_v2_c9e8c1da::impl::result_value_observers::value`<a id="outcome_v2_c9e8c1da::impl::result_value_observers-Base,R,NoValuePolicy-::value()&"></a>

<pre><code class="language-cpp">(1)  constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a>&amp; value() &amp;;

(2)  constexpr const <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a>&amp; value() const &amp;;

(3)  constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a>&amp;&amp; value() &amp;&amp;;

(4)  constexpr const <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a>&amp;&amp; value() const &amp;&amp;;</code></pre>

Access value with runtime checks.

*Returns*: Reference to the held `value_type` according to overload.

*Requires*: The result to have a successful state, else whatever `NoValuePolicy` says ought to happen.

-----

## Class template `outcome_v2_c9e8c1da::impl::result_error_observers`<a id="outcome_v2_c9e8c1da::impl::result_error_observers-Base,EC,NoValuePolicy-"></a>

<pre><code class="language-cpp">template &lt;class Base, class EC, class NoValuePolicy&gt;
class result_error_observers
: public Base
{
public:
    using <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a> = EC;
    
    using Base::Base;
    
    constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a>&amp; <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_error_observers-Base,EC,NoValuePolicy-::assume_error()&'>assume_error</a>() &amp; noexcept;
    constexpr const <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a>&amp; <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_error_observers-Base,EC,NoValuePolicy-::assume_error()&'>assume_error</a>() const &amp; noexcept;
    constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a>&amp;&amp; <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_error_observers-Base,EC,NoValuePolicy-::assume_error()&'>assume_error</a>() &amp;&amp; noexcept;
    constexpr const <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a>&amp;&amp; <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_error_observers-Base,EC,NoValuePolicy-::assume_error()&'>assume_error</a>() const &amp;&amp; noexcept;
    
    constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a>&amp; <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_error_observers-Base,EC,NoValuePolicy-::error()&'>error</a>() &amp;;
    constexpr const <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a>&amp; <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_error_observers-Base,EC,NoValuePolicy-::error()&'>error</a>() const &amp;;
    constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a>&amp;&amp; <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_error_observers-Base,EC,NoValuePolicy-::error()&'>error</a>() &amp;&amp;;
    constexpr const <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a>&amp;&amp; <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_error_observers-Base,EC,NoValuePolicy-::error()&'>error</a>() const &amp;&amp;;
};</code></pre>

The error observers implementation of `result<R, EC, NoValuePolicy>`. Only appears separate due to standardese limitations.

### Function `outcome_v2_c9e8c1da::impl::result_error_observers::assume_error`<a id="outcome_v2_c9e8c1da::impl::result_error_observers-Base,EC,NoValuePolicy-::assume_error()&"></a>

<pre><code class="language-cpp">(1)  constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a>&amp; assume_error() &amp; noexcept;

(2)  constexpr const <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a>&amp; assume_error() const &amp; noexcept;

(3)  constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a>&amp;&amp; assume_error() &amp;&amp; noexcept;

(4)  constexpr const <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a>&amp;&amp; assume_error() const &amp;&amp; noexcept;</code></pre>

Access error without runtime checks.

*Returns*: Reference to the held `error_type` according to overload.

### Function `outcome_v2_c9e8c1da::impl::result_error_observers::error`<a id="outcome_v2_c9e8c1da::impl::result_error_observers-Base,EC,NoValuePolicy-::error()&"></a>

<pre><code class="language-cpp">(1)  constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a>&amp; error() &amp;;

(2)  constexpr const <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a>&amp; error() const &amp;;

(3)  constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a>&amp;&amp; error() &amp;&amp;;

(4)  constexpr const <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a>&amp;&amp; error() const &amp;&amp;;</code></pre>

Access error with runtime checks.

*Returns*: Reference to the held `error_type` according to overload.

*Requires*: The result to have a failed state, else whatever `NoValuePolicy` says ought to happen.

-----

## Class template `outcome_v2_c9e8c1da::impl::result_final`<a id="outcome_v2_c9e8c1da::impl::result_final-R,S,NoValuePolicy-"></a>

<pre><code class="language-cpp">template &lt;class R, class S, class NoValuePolicy&gt;
class result_final
: public <a href='doc_result.md#result.hpp'>select_result_impl&lt;R, S, NoValuePolicy&gt;</a>
{
public:
    using <a href='standardese://outcome_v2_c9e8c1da::impl::result_final<R, S, NoValuePolicy>::base/'>base::base</a>;
    
    constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_final-R,S,NoValuePolicy-::operatorbool()const'>operator bool</a>() const noexcept;
    
    constexpr bool <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_final-R,S,NoValuePolicy-::has_value()const'>has_value</a>() const noexcept;
    
    constexpr bool <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_final-R,S,NoValuePolicy-::has_error()const'>has_error</a>() const noexcept;
    
    constexpr bool <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_final-R,S,NoValuePolicy-::has_payload()const'>has_payload</a>() const noexcept;
    
    constexpr bool <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_final-R,S,NoValuePolicy-::has_exception()const'>has_exception</a>() const noexcept;
    
    constexpr bool <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_final-R,S,NoValuePolicy-::has_failure()const'>has_failure</a>() const noexcept;
    
    template &lt;class T, class U, class V, typename = decltype(std::declval&lt;R&gt;()==std::declval&lt;T&gt;()&gt;
    constexpr )//&gt;bool <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_final-R,S,NoValuePolicy-::operator==(constresult_final-T,U,V-&)const'>operator==</a>(const <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_final-R,S,NoValuePolicy-'>result_final&lt;T, U, V&gt;</a>&amp; o) const noexcept(//noexcept(std::declval&lt;R&gt;()==std::declval&lt;T&gt;())//&amp;&amp;noexcept(std::declval&lt;S&gt;()==std::declval&lt;U&gt;()));
    
    template &lt;class T, class U, class V, typename = decltype(std::declval&lt;R&gt;()!=std::declval&lt;T&gt;()&gt;
    constexpr )//&gt;bool <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_final-R,S,NoValuePolicy-::operator!=(constresult_final-T,U,V-&)const'>operator!=</a>(const <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_final-R,S,NoValuePolicy-'>result_final&lt;T, U, V&gt;</a>&amp; o) const noexcept(//noexcept(std::declval&lt;R&gt;()!=std::declval&lt;T&gt;())//&amp;&amp;noexcept(std::declval&lt;S&gt;()!=std::declval&lt;U&gt;()));
};</code></pre>

The assembled implementation type of `result<R, EC, NoValuePolicy>`. Only appears separate due to standardese limitations.

### Conversion operator `outcome_v2_c9e8c1da::impl::result_final::operator bool`<a id="outcome_v2_c9e8c1da::impl::result_final-R,S,NoValuePolicy-::operatorbool()const"></a>

<pre><code class="language-cpp">constexpr operator bool() const noexcept;</code></pre>

Checks if has value.

*Returns*: True if has value.

### Function `outcome_v2_c9e8c1da::impl::result_final::has_value`<a id="outcome_v2_c9e8c1da::impl::result_final-R,S,NoValuePolicy-::has_value()const"></a>

<pre><code class="language-cpp">constexpr bool has_value() const noexcept;</code></pre>

Checks if has value.

*Returns*: True if has value.

### Function `outcome_v2_c9e8c1da::impl::result_final::has_error`<a id="outcome_v2_c9e8c1da::impl::result_final-R,S,NoValuePolicy-::has_error()const"></a>

<pre><code class="language-cpp">constexpr bool has_error() const noexcept;</code></pre>

Checks if has error.

*Returns*: True if has error.

### Function `outcome_v2_c9e8c1da::impl::result_final::has_payload`<a id="outcome_v2_c9e8c1da::impl::result_final-R,S,NoValuePolicy-::has_payload()const"></a>

<pre><code class="language-cpp">constexpr bool has_payload() const noexcept;</code></pre>

Checks if has payload.

*Returns*: True if has payload.

### Function `outcome_v2_c9e8c1da::impl::result_final::has_exception`<a id="outcome_v2_c9e8c1da::impl::result_final-R,S,NoValuePolicy-::has_exception()const"></a>

<pre><code class="language-cpp">constexpr bool has_exception() const noexcept;</code></pre>

Checks if has exception.

*Returns*: True if has exception.

### Function `outcome_v2_c9e8c1da::impl::result_final::has_failure`<a id="outcome_v2_c9e8c1da::impl::result_final-R,S,NoValuePolicy-::has_failure()const"></a>

<pre><code class="language-cpp">constexpr bool has_failure() const noexcept;</code></pre>

Checks if has error or exception.

*Returns*: True if has error or exception.

### Comparison operator `outcome_v2_c9e8c1da::impl::result_final::operator==`<a id="outcome_v2_c9e8c1da::impl::result_final-R,S,NoValuePolicy-::operator==(constresult_final-T,U,V-&)const"></a>

<pre><code class="language-cpp">template &lt;class T, class U, class V, typename = decltype(std::declval&lt;R&gt;()==std::declval&lt;T&gt;()&gt;
constexpr )//&gt;bool operator==(const <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_final-R,S,NoValuePolicy-'>result_final&lt;T, U, V&gt;</a>&amp; o) const noexcept(//noexcept(std::declval&lt;R&gt;()==std::declval&lt;T&gt;())//&amp;&amp;noexcept(std::declval&lt;S&gt;()==std::declval&lt;U&gt;()));</code></pre>

True if equal to the other result.

*Effects*: Calls the `operator==` operation on each of the two stored items until one returns false.

*Requires*: That the expression of calling `operator==` on each of the two stored items is a valid expression.

*Throws*: Any exception the individual `operator==` operations might throw.

**Parameters:**

  - <a id="outcome_v2_c9e8c1da::impl::result_final-R,S,NoValuePolicy-::operator==(constresult_final-T,U,V-&)const.o"></a>`o` - The other result to compare to.

### Comparison operator `outcome_v2_c9e8c1da::impl::result_final::operator!=`<a id="outcome_v2_c9e8c1da::impl::result_final-R,S,NoValuePolicy-::operator!=(constresult_final-T,U,V-&)const"></a>

<pre><code class="language-cpp">template &lt;class T, class U, class V, typename = decltype(std::declval&lt;R&gt;()!=std::declval&lt;T&gt;()&gt;
constexpr )//&gt;bool operator!=(const <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_final-R,S,NoValuePolicy-'>result_final&lt;T, U, V&gt;</a>&amp; o) const noexcept(//noexcept(std::declval&lt;R&gt;()!=std::declval&lt;T&gt;())//&amp;&amp;noexcept(std::declval&lt;S&gt;()!=std::declval&lt;U&gt;()));</code></pre>

True if not equal to the other result.

*Effects*: Calls the `operator!=` operation on each of the two stored items until one returns true.

*Requires*: That the expression of calling `operator!=` on each of the two stored items is a valid expression.

*Throws*: Any exception the individual `operator!=` operations might throw.

**Parameters:**

  - <a id="outcome_v2_c9e8c1da::impl::result_final-R,S,NoValuePolicy-::operator!=(constresult_final-T,U,V-&)const.o"></a>`o` - The other result to compare to.

-----

-----

## Namespace `outcome_v2_c9e8c1da::policy`<a id="outcome_v2_c9e8c1da::policy"></a>

<pre><code class="language-cpp">namespace policy
{
    template &lt;class EC&gt;
    struct <a href='doc_result.md#outcome_v2_c9e8c1da::policy::throw_directly-EC-'>throw_directly</a>;
    
    template &lt;class EC&gt;
    struct <a href='doc_result.md#outcome_v2_c9e8c1da::policy::error_code_throw_as_system_error-EC-'>error_code_throw_as_system_error</a>;
    
    template &lt;class EC&gt;
    struct <a href='doc_result.md#outcome_v2_c9e8c1da::policy::exception_ptr_rethrow-EC-'>exception_ptr_rethrow</a>;
    
    struct <a href='doc_result.md#outcome_v2_c9e8c1da::policy::terminate'>terminate</a>;
    
    template &lt;class EC&gt;
    using <a href='doc_result.md#outcome_v2_c9e8c1da::policy::default_result_policy-EC-'>default_result_policy</a> = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::conditional_t%3c//std::is_void%3cEC%3e::value,//terminate,//std::conditional_t%3c//detail::is_same_or_constructible%3cstd::error_code,EC%3e,error_code_throw_as_system_error%3cEC%3e,//std::conditional_t%3c//detail::is_same_or_constructible%3cstd::exception_ptr,EC%3e,exception_ptr_rethrow%3cEC%3e,//throw_directly%3cEC%3e//%3e%3e%3e'>std::conditional_t&lt;//std::is_void&lt;EC&gt;::value, //terminate, //std::conditional_t&lt;//detail::is_same_or_constructible&lt;std::error_code, EC&gt;, error_code_throw_as_system_error&lt;EC&gt;, //std::conditional_t&lt;//detail::is_same_or_constructible&lt;std::exception_ptr, EC&gt;, exception_ptr_rethrow&lt;EC&gt;, //throw_directly&lt;EC&gt;//&gt;&gt;&gt;</a>;
}</code></pre>

Namespace for policies

### Class template `outcome_v2_c9e8c1da::policy::throw_directly` \[Error code interpretation policy\]<a id="outcome_v2_c9e8c1da::policy::throw_directly-EC-"></a>

<pre><code class="language-cpp">template &lt;class EC&gt;
struct throw_directly
{
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome_v2_c9e8c1da::policy::throw_directly-EC-::narrow_value_check(Impl*)'>narrow_value_check</a>(Impl* self) noexcept;
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome_v2_c9e8c1da::policy::throw_directly-EC-::narrow_error_check(Impl*)'>narrow_error_check</a>(Impl* self) noexcept;
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome_v2_c9e8c1da::policy::throw_directly-EC-::wide_value_check(Impl*)'>wide_value_check</a>(Impl* self);
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome_v2_c9e8c1da::policy::throw_directly-EC-::wide_error_check(Impl*)'>wide_error_check</a>(Impl* self);
};</code></pre>

Policy interpreting EC as a type to be thrown directly during wide checks.

#### Function template `outcome_v2_c9e8c1da::policy::throw_directly::narrow_value_check`<a id="outcome_v2_c9e8c1da::policy::throw_directly-EC-::narrow_value_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void narrow_value_check(Impl* self) noexcept;</code></pre>

Performs a narrow check of state, used in the assume\_value() functions.

*Effects*: None.

#### Function template `outcome_v2_c9e8c1da::policy::throw_directly::narrow_error_check`<a id="outcome_v2_c9e8c1da::policy::throw_directly-EC-::narrow_error_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void narrow_error_check(Impl* self) noexcept;</code></pre>

Performs a narrow check of state, used in the assume\_error() functions

*Effects*: None.

#### Function template `outcome_v2_c9e8c1da::policy::throw_directly::wide_value_check`<a id="outcome_v2_c9e8c1da::policy::throw_directly-EC-::wide_value_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void wide_value_check(Impl* self);</code></pre>

Performs a wide check of state, used in the value() functions.

*Effects*: If result does not have a value, if it has an error it throws that `error()`, else it throws `bad_result_access`.

#### Function template `outcome_v2_c9e8c1da::policy::throw_directly::wide_error_check`<a id="outcome_v2_c9e8c1da::policy::throw_directly-EC-::wide_error_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void wide_error_check(Impl* self);</code></pre>

Performs a wide check of state, used in the error() functions

*Effects*: If result does not have an error, it throws `bad_result_access`.

-----

### Class template `outcome_v2_c9e8c1da::policy::error_code_throw_as_system_error` \[Error code interpretation policy\]<a id="outcome_v2_c9e8c1da::policy::error_code_throw_as_system_error-EC-"></a>

<pre><code class="language-cpp">template &lt;class EC&gt;
struct error_code_throw_as_system_error
{
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome_v2_c9e8c1da::policy::error_code_throw_as_system_error-EC-::narrow_value_check(Impl*)'>narrow_value_check</a>(Impl* self) noexcept;
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome_v2_c9e8c1da::policy::error_code_throw_as_system_error-EC-::narrow_error_check(Impl*)'>narrow_error_check</a>(Impl* self) noexcept;
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome_v2_c9e8c1da::policy::error_code_throw_as_system_error-EC-::wide_value_check(Impl*)'>wide_value_check</a>(Impl* self);
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome_v2_c9e8c1da::policy::error_code_throw_as_system_error-EC-::wide_error_check(Impl*)'>wide_error_check</a>(Impl* self);
};</code></pre>

Policy interpreting EC as a type implementing the `std::error_code` contract and any wide attempt to access the successful state throws the `error_code` wrapped into a `std::system_error`

#### Function template `outcome_v2_c9e8c1da::policy::error_code_throw_as_system_error::narrow_value_check`<a id="outcome_v2_c9e8c1da::policy::error_code_throw_as_system_error-EC-::narrow_value_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void narrow_value_check(Impl* self) noexcept;</code></pre>

Performs a narrow check of state, used in the assume\_value() functions.

*Effects*: None.

#### Function template `outcome_v2_c9e8c1da::policy::error_code_throw_as_system_error::narrow_error_check`<a id="outcome_v2_c9e8c1da::policy::error_code_throw_as_system_error-EC-::narrow_error_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void narrow_error_check(Impl* self) noexcept;</code></pre>

Performs a narrow check of state, used in the assume\_error() functions.

*Effects*: None.

#### Function template `outcome_v2_c9e8c1da::policy::error_code_throw_as_system_error::wide_value_check`<a id="outcome_v2_c9e8c1da::policy::error_code_throw_as_system_error-EC-::wide_value_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void wide_value_check(Impl* self);</code></pre>

Performs a wide check of state, used in the value() functions.

*Effects*: If result does not have a value, if it has an error it throws a `std::system_error(error())`, else it throws `bad_result_access`.

#### Function template `outcome_v2_c9e8c1da::policy::error_code_throw_as_system_error::wide_error_check`<a id="outcome_v2_c9e8c1da::policy::error_code_throw_as_system_error-EC-::wide_error_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void wide_error_check(Impl* self);</code></pre>

Performs a wide check of state, used in the error() functions

*Effects*: If result does not have an error, it throws `bad_result_access`.

-----

### Class template `outcome_v2_c9e8c1da::policy::exception_ptr_rethrow` \[Error code interpretation policy\]<a id="outcome_v2_c9e8c1da::policy::exception_ptr_rethrow-EC-"></a>

<pre><code class="language-cpp">template &lt;class EC&gt;
struct exception_ptr_rethrow
{
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome_v2_c9e8c1da::policy::exception_ptr_rethrow-EC-::narrow_value_check(Impl*)'>narrow_value_check</a>(Impl* self) noexcept;
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome_v2_c9e8c1da::policy::exception_ptr_rethrow-EC-::narrow_error_check(Impl*)'>narrow_error_check</a>(Impl* self) noexcept;
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome_v2_c9e8c1da::policy::exception_ptr_rethrow-EC-::wide_value_check(Impl*)'>wide_value_check</a>(Impl* self);
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome_v2_c9e8c1da::policy::exception_ptr_rethrow-EC-::wide_error_check(Impl*)'>wide_error_check</a>(Impl* self);
};</code></pre>

Policy interpreting EC as a type implementing the `std::exception_ptr` contract and any wide attempt to access the successful state calls `std::rethrow_exception()`.

#### Function template `outcome_v2_c9e8c1da::policy::exception_ptr_rethrow::narrow_value_check`<a id="outcome_v2_c9e8c1da::policy::exception_ptr_rethrow-EC-::narrow_value_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void narrow_value_check(Impl* self) noexcept;</code></pre>

Performs a narrow check of state, used in the assume\_value() functions.

*Effects*: None.

#### Function template `outcome_v2_c9e8c1da::policy::exception_ptr_rethrow::narrow_error_check`<a id="outcome_v2_c9e8c1da::policy::exception_ptr_rethrow-EC-::narrow_error_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void narrow_error_check(Impl* self) noexcept;</code></pre>

Performs a narrow check of state, used in the assume\_error() functions

*Effects*: None.

#### Function template `outcome_v2_c9e8c1da::policy::exception_ptr_rethrow::wide_value_check`<a id="outcome_v2_c9e8c1da::policy::exception_ptr_rethrow-EC-::wide_value_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void wide_value_check(Impl* self);</code></pre>

Performs a wide check of state, used in the value() functions

*Effects*: If result does not have a value, if it has an error it rethrows that error via `std::rethrow_exception()`, else it throws `bad_result_access`.

#### Function template `outcome_v2_c9e8c1da::policy::exception_ptr_rethrow::wide_error_check`<a id="outcome_v2_c9e8c1da::policy::exception_ptr_rethrow-EC-::wide_error_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void wide_error_check(Impl* self);</code></pre>

Performs a wide check of state, used in the value() functions

*Effects*: If result does not have a value, if it has an error it throws that error, else it throws `bad_result_access`.

-----

### Struct `outcome_v2_c9e8c1da::policy::terminate` \[Error code interpretation policy\]<a id="outcome_v2_c9e8c1da::policy::terminate"></a>

<pre><code class="language-cpp">struct terminate
{
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome_v2_c9e8c1da::policy::terminate::narrow_value_check(Impl*)'>narrow_value_check</a>(Impl* self) noexcept;
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome_v2_c9e8c1da::policy::terminate::narrow_error_check(Impl*)'>narrow_error_check</a>(Impl* self) noexcept;
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome_v2_c9e8c1da::policy::terminate::narrow_payload_check(Impl*)'>narrow_payload_check</a>(Impl* self) noexcept;
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome_v2_c9e8c1da::policy::terminate::narrow_exception_check(Impl*)'>narrow_exception_check</a>(Impl* self) noexcept;
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome_v2_c9e8c1da::policy::terminate::wide_value_check(Impl*)'>wide_value_check</a>(Impl* self);
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome_v2_c9e8c1da::policy::terminate::wide_error_check(Impl*)'>wide_error_check</a>(Impl* self) noexcept;
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome_v2_c9e8c1da::policy::terminate::wide_payload_check(Impl*)'>wide_payload_check</a>(Impl* self);
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome_v2_c9e8c1da::policy::terminate::wide_exception_check(Impl*)'>wide_exception_check</a>(Impl* self);
};</code></pre>

Policy implementing any wide attempt to access the successful state as calling `std::terminate`

#### Function template `outcome_v2_c9e8c1da::policy::terminate::narrow_value_check`<a id="outcome_v2_c9e8c1da::policy::terminate::narrow_value_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void narrow_value_check(Impl* self) noexcept;</code></pre>

Performs a narrow check of state, used in the assume\_value() functions.

*Effects*: None.

#### Function template `outcome_v2_c9e8c1da::policy::terminate::narrow_error_check`<a id="outcome_v2_c9e8c1da::policy::terminate::narrow_error_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void narrow_error_check(Impl* self) noexcept;</code></pre>

Performs a narrow check of state, used in the assume\_error() functions

*Effects*: None.

#### Function template `outcome_v2_c9e8c1da::policy::terminate::narrow_payload_check`<a id="outcome_v2_c9e8c1da::policy::terminate::narrow_payload_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void narrow_payload_check(Impl* self) noexcept;</code></pre>

Performs a narrow check of state, used in the assume\_payload() functions

*Effects*: None.

#### Function template `outcome_v2_c9e8c1da::policy::terminate::narrow_exception_check`<a id="outcome_v2_c9e8c1da::policy::terminate::narrow_exception_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void narrow_exception_check(Impl* self) noexcept;</code></pre>

Performs a narrow check of state, used in the assume\_exception() functions

*Effects*: None.

#### Function template `outcome_v2_c9e8c1da::policy::terminate::wide_value_check`<a id="outcome_v2_c9e8c1da::policy::terminate::wide_value_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void wide_value_check(Impl* self);</code></pre>

Performs a wide check of state, used in the value() functions.

*Effects*: If result does not have a value, calls `std::terminate()`.

#### Function template `outcome_v2_c9e8c1da::policy::terminate::wide_error_check`<a id="outcome_v2_c9e8c1da::policy::terminate::wide_error_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void wide_error_check(Impl* self) noexcept;</code></pre>

Performs a wide check of state, used in the error() functions

*Effects*: If result does not have an error, calls `std::terminate()`.

#### Function template `outcome_v2_c9e8c1da::policy::terminate::wide_payload_check`<a id="outcome_v2_c9e8c1da::policy::terminate::wide_payload_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void wide_payload_check(Impl* self);</code></pre>

Performs a wide check of state, used in the payload() functions

*Effects*: If outcome does not have an exception, calls `std::terminate()`.

#### Function template `outcome_v2_c9e8c1da::policy::terminate::wide_exception_check`<a id="outcome_v2_c9e8c1da::policy::terminate::wide_exception_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void wide_exception_check(Impl* self);</code></pre>

Performs a wide check of state, used in the exception() functions

*Effects*: If outcome does not have an exception, calls `std::terminate()`.

-----

### Alias template `outcome_v2_c9e8c1da::policy::default_result_policy` \[Error code interpretation policy\]<a id="outcome_v2_c9e8c1da::policy::default_result_policy-EC-"></a>

<pre><code class="language-cpp">template &lt;class EC&gt;
using default_result_policy = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::conditional_t%3c//std::is_void%3cEC%3e::value,//terminate,//std::conditional_t%3c//detail::is_same_or_constructible%3cstd::error_code,EC%3e,error_code_throw_as_system_error%3cEC%3e,//std::conditional_t%3c//detail::is_same_or_constructible%3cstd::exception_ptr,EC%3e,exception_ptr_rethrow%3cEC%3e,//throw_directly%3cEC%3e//%3e%3e%3e'>std::conditional_t&lt;//std::is_void&lt;EC&gt;::value, //terminate, //std::conditional_t&lt;//detail::is_same_or_constructible&lt;std::error_code, EC&gt;, error_code_throw_as_system_error&lt;EC&gt;, //std::conditional_t&lt;//detail::is_same_or_constructible&lt;std::exception_ptr, EC&gt;, exception_ptr_rethrow&lt;EC&gt;, //throw_directly&lt;EC&gt;//&gt;&gt;&gt;</a>;</code></pre>

Default `result<R, S>` policy selector.

-----

## Function template `outcome_v2_c9e8c1da::hook_result_construction`<a id="outcome_v2_c9e8c1da::hook_result_construction(in_place_type_t-T-,U*)"></a>

<pre><code class="language-cpp">template &lt;class T, class U&gt;
constexpr void hook_result_construction(in_place_type_t&lt;T&gt;, U*) noexcept;</code></pre>

The default instantiation hook implementation called when a `result` is first created by conversion from one of its possible types. Does nothing.

WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should\!

**Parameters:**

  - <a id="outcome_v2_c9e8c1da::hook_result_construction(in_place_type_t-T-,U*).T"></a>`T` - One of  `value_type` or `error_type`.

## Function template `outcome_v2_c9e8c1da::hook_result_copy_construction`<a id="outcome_v2_c9e8c1da::hook_result_copy_construction(in_place_type_t-T-,U*)"></a>

<pre><code class="language-cpp">template &lt;class T, class U&gt;
constexpr void hook_result_copy_construction(in_place_type_t&lt;T&gt;, U*) noexcept;</code></pre>

The default instantiation hook implementation called when a `result` is created by copying from another `result`. Does nothing.

WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should\!

**Parameters:**

  - <a id="outcome_v2_c9e8c1da::hook_result_copy_construction(in_place_type_t-T-,U*).T"></a>`T` - The type of the source.

## Function template `outcome_v2_c9e8c1da::hook_result_move_construction`<a id="outcome_v2_c9e8c1da::hook_result_move_construction(in_place_type_t-T-,U*)"></a>

<pre><code class="language-cpp">template &lt;class T, class U&gt;
constexpr void hook_result_move_construction(in_place_type_t&lt;T&gt;, U*) noexcept;</code></pre>

The default instantiation hook implementation called when a `result` is created by moving from another `result`. Does nothing.

WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should\!

**Parameters:**

  - <a id="outcome_v2_c9e8c1da::hook_result_move_construction(in_place_type_t-T-,U*).T"></a>`T` - The type of the source.

## Function template `outcome_v2_c9e8c1da::hook_result_in_place_construction`<a id="outcome_v2_c9e8c1da::hook_result_in_place_construction(in_place_type_t-T-,U*)"></a>

<pre><code class="language-cpp">template &lt;class T, class U&gt;
constexpr void hook_result_in_place_construction(in_place_type_t&lt;T&gt;, U*) noexcept;</code></pre>

The default instantiation hook implementation called when a `result` is created by in place construction. Does nothing.

WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should\!

**Parameters:**

  - <a id="outcome_v2_c9e8c1da::hook_result_in_place_construction(in_place_type_t-T-,U*).T"></a>`T` - One of  `value_type` or `error_type`.

## Class template `outcome_v2_c9e8c1da::result` \[result\<R, S\> implementation\]<a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-"></a>

<pre><code class="language-cpp">template &lt;class R, class S = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::error_code'>std::error_code</a>, class NoValuePolicy = policy::default_result_policy&lt;S&gt;
class result
: public <a href='doc_result.md#outcome_v2_c9e8c1da::impl::result_final-R,S,NoValuePolicy-'>impl::result_final&lt;R, S, NoValuePolicy&gt;</a>
{
public:
    //=== <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::value_type'>Member types</a> ===//
    using <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::value_type'>value_type</a> = R;
    
    using <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::status_error_type'>status_error_type</a> = S;
    
    using <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::error_type'>error_type</a> = S;
    
    using <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::value_type_if_enabled'>value_type_if_enabled</a> = typename base::_value_type;
    
    using <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::error_type_if_enabled'>error_type_if_enabled</a> = typename base::_error_type;
    
    template &lt;class T, class U = S&gt;
    using <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::rebind-T,U-'>rebind</a> = <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-'>result&lt;T, U&gt;</a>;
    
    //=== <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result()'>Default, copy/move constructors and assignment</a> ===//
    <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result()'>result</a>() = delete;
    
    <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(result-R,S,NoValuePolicy-&&)'>result</a>(<a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-'>result</a>&amp;&amp;) = default;
    
    <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(constresult-R,S,NoValuePolicy-&)'>result</a>(const <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-'>result</a>&amp;) = default;
    
    <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-'>result</a>&amp; <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::operator=(result-R,S,NoValuePolicy-&&)'>operator=</a>(<a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-'>result</a>&amp;&amp;) = default;
    
    <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-'>result</a>&amp; <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::operator=(constresult-R,S,NoValuePolicy-&)'>operator=</a>(const <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-'>result</a>&amp;) = default;
    
    template &lt;class T&gt;
    constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(T&&,outcome_v2_c9e8c1da::result::value_converting_constructor_tag)'>result</a>(T&amp;&amp; t) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value);
    
    template &lt;class T&gt;
    constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(T&&,outcome_v2_c9e8c1da::result::error_converting_constructor_tag)'>result</a>(T&amp;&amp; t) noexcept(std::is_nothrow_constructible&lt;error_type, T&gt;::value);
    
    template &lt;class T, class U, class V&gt;
    constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(constresult-T,U,V-&,outcome_v2_c9e8c1da::result::explicit_compatible_conversion_tag)'>result</a>(const <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-'>result&lt;T, U, V&gt;</a>&amp; o, <a href='standardese://outcome_v2_c9e8c1da::result<R, S, NoValuePolicy>::explicit_compatible_conversion_tag/'>explicit_compatible_conversion_tag</a> = explicit_compatible_conversion_tag()) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;status_error_type, U&gt;::value);
    
    template &lt;class T, class U, class V&gt;
    constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(constresult-T,U,V-&,outcome_v2_c9e8c1da::result::implicit_compatible_conversion_tag)'>result</a>(const <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-'>result&lt;T, U, V&gt;</a>&amp; o, <a href='standardese://outcome_v2_c9e8c1da::result<R, S, NoValuePolicy>::implicit_compatible_conversion_tag/'>implicit_compatible_conversion_tag</a> = implicit_compatible_conversion_tag()) noexcept(std::is_nothrow_constructible&lt;status_error_type, U&gt;::value);
    
    template &lt;class T, class U, class V&gt;
    constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(result-T,U,V-&&,outcome_v2_c9e8c1da::result::explicit_compatible_conversion_tag)'>result</a>(<a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-'>result&lt;T, U, V&gt;</a>&amp;&amp; o, <a href='standardese://outcome_v2_c9e8c1da::result<R, S, NoValuePolicy>::explicit_compatible_conversion_tag/'>explicit_compatible_conversion_tag</a> = explicit_compatible_conversion_tag()) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;status_error_type, U&gt;::value);
    
    template &lt;class T, class U, class V, typename enable_explicit_compatible_conversion = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::enable_if_t%3c//!std::is_same%3cresult%3cT,U,V%3e,result%3e::value//notmytype&&std::is_void%3cT%3e::value//othervaluetypemustbevoid&&(std::is_void%3cU%3e::value%7c%7cdetail::is_same_or_constructible%3cerror_type,typenameresult%3cT,U,V%3e::error_type%3e)//ifourerrortypesareconstructible%3e'>std::enable_if_t&lt;//!std::is_same&lt;result&lt;T, U, V&gt;, result&gt;::value// not my type&amp;&amp;std::is_void&lt;T&gt;::value// other value type must be void&amp;&amp;(std::is_void&lt;U&gt;::value||detail::is_same_or_constructible&lt;error_type, typename result&lt;T, U, V&gt;::error_type&gt;)// if our error types are constructible&gt;</a>&gt;
    constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(result-T,U,V-&&,outcome_v2_c9e8c1da::result::implicit_compatible_conversion_tag)'>result</a>(<a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-'>result&lt;T, U, V&gt;</a>&amp;&amp; o, <a href='standardese://outcome_v2_c9e8c1da::result<R, S, NoValuePolicy>::implicit_compatible_conversion_tag/'>implicit_compatible_conversion_tag</a> = implicit_compatible_conversion_tag()) noexcept(std::is_nothrow_constructible&lt;status_error_type, U&gt;::value);
    
    template &lt;class ... Args&gt;
    constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(in_place_type_t-value_type_if_enabled-,Args&&...)'>result</a>(in_place_type_t&lt;value_type_if_enabled&gt;, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;value_type, Args...&gt;::value);
    
    template &lt;class U, class ... Args&gt;
    constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(in_place_type_t-value_type_if_enabled-,std::initializer_list-U-,Args&&...)'>result</a>(in_place_type_t&lt;value_type_if_enabled&gt;, <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::initializer_list%3cU%3e'>std::initializer_list&lt;U&gt;</a> il, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;value_type, std::initializer_list&lt;U&gt;, Args...&gt;::value);
    
    template &lt;class ... Args&gt;
    constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(in_place_type_t-error_type_if_enabled-,Args&&...)'>result</a>(in_place_type_t&lt;error_type_if_enabled&gt;, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;error_type, Args...&gt;::value);
    
    template &lt;class U, class ... Args&gt;
    constexpr <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(in_place_type_t-error_type_if_enabled-,std::initializer_list-U-,Args&&...)'>result</a>(in_place_type_t&lt;error_type_if_enabled&gt;, <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::initializer_list%3cU%3e'>std::initializer_list&lt;U&gt;</a> il, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;error_type, std::initializer_list&lt;U&gt;, Args...&gt;::value);
    
    <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::rebind-T,U-'>rebind&lt;void&gt;</a> <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::as_void()const&'>as_void</a>() const &amp;;
    
    <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::rebind-T,U-'>rebind&lt;void&gt;</a> <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::as_void()&&'>as_void</a>() &amp;&amp;;
};</code></pre>

Used to return from functions (i) a value (ii) a value and a positive status or (iii) no value and a negative status. `constexpr` capable.

This is a vocabulary type implementing [P0262R0 A Class for Status and Optional Value](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0262r0.html), albeit with types `Status` and `Value` reversed in lexical order. By default `S` is considered to be a *positive* status type used to supply additional information about the successful return of a type `R`. If however the trait `trait::status_type_is_negative<S>` has been specialised to be true, then `S` is considered to be a *negative* status type used to supply information about the cause of failure to return a type `R`.

`trait::status_type_is_negative<S>` is already set to true for these types (you can specialise in your own types easily):

  - `std::error_code`
  - `std::exception_ptr`
  - `void`

When `trait::status_type_is_negative<S>` is false, the default for `NoValuePolicy` is:

1.  If `.status()` called when there is no `status_type`:

<!-- end list -->

  - `throw bad_result_access()` if C++ exceptions are enabled, else call `std::terminate()`.

When `trait::status_type_is_negative<S>` is true, the default for `NoValuePolicy` is:

1.  If `.value()` called when there is no `value_type` but there is an `error_type`:

<!-- end list -->

  - If `S` convertible to a `std::error_code`, then `throw std::system_error(error())` \[`policy::error_code_throw_as_system_error<S>`\] if C++ exceptions are enabled, else call `std::terminate()`.
  - If `S` convertible to a `std::exception_ptr`, then `std::rethrow_exception(error())` \[`policy::exception_ptr_rethrow<S>`\] if C++ exceptions are enabled, else call `std::terminate()`.
  - If `S` is `void`, call `std::terminate()` \[`policy::terminate<S>`\]
  - If `S` is none of the above, then someone has enabled the negative status type trait but did not specify a custom policy. We therefore simply `throw error()` \[`policy::throw_directly<S>`\] if C++ exceptions are enabled, else call `std::terminate`.

<!-- end list -->

2.  If `.error()` called when there is no `error_type`:

<!-- end list -->

  - `throw bad_result_access()` if C++ exceptions are enabled, else call `std::terminate()`.

**Parameters:**

  - <a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-.R"></a>`R` - The optional type of the successful result (use  `void` to disable).

  - <a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-.S"></a>`S` - The optional type of the status result (use  `void` to disable). Must be either `void` or DefaultConstructible.

  - <a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-.NoValuePolicy"></a>`NoValuePolicy` - Policy on how to interpret type  `S` when a wide observation of a not present value occurs.

### Type alias `outcome_v2_c9e8c1da::result::value_type`<a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::value_type"></a>

<pre><code class="language-cpp">using value_type = R;</code></pre>

The success type.

### Type alias `outcome_v2_c9e8c1da::result::status_error_type`<a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::status_error_type"></a>

<pre><code class="language-cpp">using status_error_type = S;</code></pre>

The S type configured

### Type alias `outcome_v2_c9e8c1da::result::error_type`<a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::error_type"></a>

<pre><code class="language-cpp">using error_type = S;</code></pre>

The failure type.

### Type alias `outcome_v2_c9e8c1da::result::value_type_if_enabled`<a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::value_type_if_enabled"></a>

<pre><code class="language-cpp">using value_type_if_enabled = typename base::_value_type;</code></pre>

Used to disable in place type construction when `value_type` and `error_type` are ambiguous.

### Type alias `outcome_v2_c9e8c1da::result::error_type_if_enabled`<a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::error_type_if_enabled"></a>

<pre><code class="language-cpp">using error_type_if_enabled = typename base::_error_type;</code></pre>

Used to disable in place type construction when `value_type` and `error_type` are ambiguous.

### Alias template `outcome_v2_c9e8c1da::result::rebind`<a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::rebind-T,U-"></a>

<pre><code class="language-cpp">template &lt;class T, class U = S&gt;
using rebind = <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-'>result&lt;T, U&gt;</a>;</code></pre>

Used to rebind this result to a different result type

### Default constructor `outcome_v2_c9e8c1da::result::result`<a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result()"></a>

<pre><code class="language-cpp">result() = delete;</code></pre>

Default construction is not permitted.

### Move constructor `outcome_v2_c9e8c1da::result::result`<a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(result-R,S,NoValuePolicy-&&)"></a>

<pre><code class="language-cpp">result(<a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-'>result</a>&amp;&amp;) = default;</code></pre>

Move construction available if `value_type` and `status_error_type` implement it.

### Copy constructor `outcome_v2_c9e8c1da::result::result`<a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(constresult-R,S,NoValuePolicy-&)"></a>

<pre><code class="language-cpp">result(const <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-'>result</a>&amp;) = default;</code></pre>

Copy construction available if `value_type` and `status_error_type` implement it.

### Assignment operator `outcome_v2_c9e8c1da::result::operator=`<a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::operator=(result-R,S,NoValuePolicy-&&)"></a>

<pre><code class="language-cpp"><a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-'>result</a>&amp; operator=(<a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-'>result</a>&amp;&amp;) = default;</code></pre>

Move assignment available if `value_type` and `status_error_type` implement it.

### Assignment operator `outcome_v2_c9e8c1da::result::operator=`<a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::operator=(constresult-R,S,NoValuePolicy-&)"></a>

<pre><code class="language-cpp"><a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-'>result</a>&amp; operator=(const <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-'>result</a>&amp;) = default;</code></pre>

Copy assignment available if `value_type` and `status_error_type` implement it.

### Function template `outcome_v2_c9e8c1da::result::result`<a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(T&&,outcome_v2_c9e8c1da::result::value_converting_constructor_tag)"></a>

<pre><code class="language-cpp">template &lt;class T&gt;
constexpr result(T&amp;&amp; t) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value);</code></pre>

Converting constructor to a successful result.

*Effects*: Initialises the result with a `value_type`.

*Requires*: Type T is constructible to `value_type`, is not constructible to `status_error_type`, and is not `result<R, S>` and not `in_place_type<>`.

*Throws*: Any exception the construction of `value_type(T)` might throw.

**Parameters:**

  - <a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(T&&,outcome_v2_c9e8c1da::result::value_converting_constructor_tag).t"></a>`t` - The value from which to initialise the  `value_type`.

### Function template `outcome_v2_c9e8c1da::result::result`<a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(T&&,outcome_v2_c9e8c1da::result::error_converting_constructor_tag)"></a>

<pre><code class="language-cpp">template &lt;class T&gt;
constexpr result(T&amp;&amp; t) noexcept(std::is_nothrow_constructible&lt;error_type, T&gt;::value);</code></pre>

Converting constructor to a failure result.

*Effects*: Initialises the result with a `error_type`.

*Requires*: `trait::status_type_is_negative<EC>` must be true; Type T is constructible to `error_type`, is not constructible to `value_type`, and is not `result<R, S>` and not `in_place_type<>`.

*Throws*: Any exception the construction of `error_type(T)` might throw.

**Parameters:**

  - <a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(T&&,outcome_v2_c9e8c1da::result::error_converting_constructor_tag).t"></a>`t` - The value from which to initialise the  `error_type`.

### Function template `outcome_v2_c9e8c1da::result::result`<a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(constresult-T,U,V-&,outcome_v2_c9e8c1da::result::explicit_compatible_conversion_tag)"></a>

<pre><code class="language-cpp">template &lt;class T, class U, class V&gt;
constexpr result(const <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-'>result&lt;T, U, V&gt;</a>&amp; o, <a href='standardese://outcome_v2_c9e8c1da::result<R, S, NoValuePolicy>::explicit_compatible_conversion_tag/'>explicit_compatible_conversion_tag</a> = explicit_compatible_conversion_tag()) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;status_error_type, U&gt;::value);</code></pre>

Explicit converting copy constructor from a compatible result type.

*Effects*: Initialises the result with a copy of the compatible result.

*Requires*: Both result's `value_type`, `error_type` and `status_type` need to be constructible, or the source `status_error_type` can be `void`. The source `value_type` cannot be `void`.

*Throws*: Any exception the construction of `value_type(T)` and `status_error_type(U)` might throw.

**Parameters:**

  - <a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(constresult-T,U,V-&,outcome_v2_c9e8c1da::result::explicit_compatible_conversion_tag).o"></a>`o` - The compatible result.

### Function template `outcome_v2_c9e8c1da::result::result`<a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(constresult-T,U,V-&,outcome_v2_c9e8c1da::result::implicit_compatible_conversion_tag)"></a>

<pre><code class="language-cpp">template &lt;class T, class U, class V&gt;
constexpr result(const <a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-'>result&lt;T, U, V&gt;</a>&amp; o, <a href='standardese://outcome_v2_c9e8c1da::result<R, S, NoValuePolicy>::implicit_compatible_conversion_tag/'>implicit_compatible_conversion_tag</a> = implicit_compatible_conversion_tag()) noexcept(std::is_nothrow_constructible&lt;status_error_type, U&gt;::value);</code></pre>

Implicit converting copy constructor from a compatible result type.

*Effects*: Initialises the result with a copy of the compatible result.

*Requires*: Both result's `error_type` and `status_type` need to be constructible, and the source `value_type` must be `void`.

*Throws*: Any exception the construction of `status_error_type(U)` might throw.

**Parameters:**

  - <a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(constresult-T,U,V-&,outcome_v2_c9e8c1da::result::implicit_compatible_conversion_tag).o"></a>`o` - The compatible result.

### Function template `outcome_v2_c9e8c1da::result::result`<a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(result-T,U,V-&&,outcome_v2_c9e8c1da::result::explicit_compatible_conversion_tag)"></a>

<pre><code class="language-cpp">template &lt;class T, class U, class V&gt;
constexpr result(<a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-'>result&lt;T, U, V&gt;</a>&amp;&amp; o, <a href='standardese://outcome_v2_c9e8c1da::result<R, S, NoValuePolicy>::explicit_compatible_conversion_tag/'>explicit_compatible_conversion_tag</a> = explicit_compatible_conversion_tag()) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;status_error_type, U&gt;::value);</code></pre>

Explicit converting move constructor from a compatible result type.

*Effects*: Initialises the result with a move of the compatible result.

*Requires*: Both result's `value_type`, `error_type` and `status_type` need to be constructible, or the source `status_error_type` can be `void`. The source `value_type` cannot be `void`.

*Throws*: Any exception the construction of `value_type(T)` and `status_error_type(U)` might throw.

**Parameters:**

  - <a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(result-T,U,V-&&,outcome_v2_c9e8c1da::result::explicit_compatible_conversion_tag).o"></a>`o` - The compatible result.

### Function template `outcome_v2_c9e8c1da::result::result`<a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(result-T,U,V-&&,outcome_v2_c9e8c1da::result::implicit_compatible_conversion_tag)"></a>

<pre><code class="language-cpp">template &lt;class T, class U, class V, typename enable_explicit_compatible_conversion = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::enable_if_t%3c//!std::is_same%3cresult%3cT,U,V%3e,result%3e::value//notmytype&&std::is_void%3cT%3e::value//othervaluetypemustbevoid&&(std::is_void%3cU%3e::value%7c%7cdetail::is_same_or_constructible%3cerror_type,typenameresult%3cT,U,V%3e::error_type%3e)//ifourerrortypesareconstructible%3e'>std::enable_if_t&lt;//!std::is_same&lt;result&lt;T, U, V&gt;, result&gt;::value// not my type&amp;&amp;std::is_void&lt;T&gt;::value// other value type must be void&amp;&amp;(std::is_void&lt;U&gt;::value||detail::is_same_or_constructible&lt;error_type, typename result&lt;T, U, V&gt;::error_type&gt;)// if our error types are constructible&gt;</a>&gt;
constexpr result(<a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-'>result&lt;T, U, V&gt;</a>&amp;&amp; o, <a href='standardese://outcome_v2_c9e8c1da::result<R, S, NoValuePolicy>::implicit_compatible_conversion_tag/'>implicit_compatible_conversion_tag</a> = implicit_compatible_conversion_tag()) noexcept(std::is_nothrow_constructible&lt;status_error_type, U&gt;::value);</code></pre>

Implicit converting move constructor from a compatible result type.

*Effects*: Initialises the result with a move of the compatible result.

*Requires*: Both result's `error_type` and `status_type` need to be constructible, and the source `value_type` must be `void`.

*Throws*: Any exception the construction of `status_error_type(U)` might throw.

**Parameters:**

  - <a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(result-T,U,V-&&,outcome_v2_c9e8c1da::result::implicit_compatible_conversion_tag).o"></a>`o` - The compatible result.

### Function template `outcome_v2_c9e8c1da::result::result`<a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(in_place_type_t-value_type_if_enabled-,Args&&...)"></a>

<pre><code class="language-cpp">template &lt;class ... Args&gt;
constexpr result(in_place_type_t&lt;value_type_if_enabled&gt;, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;value_type, Args...&gt;::value);</code></pre>

Inplace constructor to a successful result.

*Effects*: Initialises the result with a `value_type`.

*Requires*: `value_type` is void or `Args...` are constructible to `value_type`.

*Throws*: Any exception the construction of `value_type(Args...)` might throw.

**Parameters:**

  - <a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(in_place_type_t-value_type_if_enabled-,Args&&...).args"></a>`args` - Arguments with which to in place construct.

### Function template `outcome_v2_c9e8c1da::result::result`<a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(in_place_type_t-value_type_if_enabled-,std::initializer_list-U-,Args&&...)"></a>

<pre><code class="language-cpp">template &lt;class U, class ... Args&gt;
constexpr result(in_place_type_t&lt;value_type_if_enabled&gt;, <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::initializer_list%3cU%3e'>std::initializer_list&lt;U&gt;</a> il, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;value_type, std::initializer_list&lt;U&gt;, Args...&gt;::value);</code></pre>

Inplace constructor to a successful result.

*Effects*: Initialises the result with a `value_type`.

*Requires*: The initializer list + `Args...` are constructible to `value_type`.

*Throws*: Any exception the construction of `value_type(il, Args...)` might throw.

**Parameters:**

  - <a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(in_place_type_t-value_type_if_enabled-,std::initializer_list-U-,Args&&...)"></a>`il` - An initializer list with which to in place construct.

  - <a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(in_place_type_t-value_type_if_enabled-,std::initializer_list-U-,Args&&...).args"></a>`args` - Arguments with which to in place construct.

### Function template `outcome_v2_c9e8c1da::result::result`<a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(in_place_type_t-error_type_if_enabled-,Args&&...)"></a>

<pre><code class="language-cpp">template &lt;class ... Args&gt;
constexpr result(in_place_type_t&lt;error_type_if_enabled&gt;, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;error_type, Args...&gt;::value);</code></pre>

Inplace constructor to a failure result.

*Effects*: Initialises the result with a `error_type`.

*Requires*: `trait::status_type_is_negative<EC>` must be true; `error_type` is void or `Args...` are constructible to `error_type`.

*Throws*: Any exception the construction of `error_type(Args...)` might throw.

**Parameters:**

  - <a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(in_place_type_t-error_type_if_enabled-,Args&&...).args"></a>`args` - Arguments with which to in place construct.

### Function template `outcome_v2_c9e8c1da::result::result`<a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(in_place_type_t-error_type_if_enabled-,std::initializer_list-U-,Args&&...)"></a>

<pre><code class="language-cpp">template &lt;class U, class ... Args&gt;
constexpr result(in_place_type_t&lt;error_type_if_enabled&gt;, <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::initializer_list%3cU%3e'>std::initializer_list&lt;U&gt;</a> il, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;error_type, std::initializer_list&lt;U&gt;, Args...&gt;::value);</code></pre>

Inplace constructor to a failure result.

*Effects*: Initialises the result with a `error_type`.

*Requires*: `trait::status_type_is_negative<EC>` must be true; The initializer list + `Args...` are constructible to `error_type`.

*Throws*: Any exception the construction of `error_type(il, Args...)` might throw.

**Parameters:**

  - <a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(in_place_type_t-error_type_if_enabled-,std::initializer_list-U-,Args&&...)"></a>`il` - An initializer list with which to in place construct.

  - <a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::result(in_place_type_t-error_type_if_enabled-,std::initializer_list-U-,Args&&...).args"></a>`args` - Arguments with which to in place construct.

### Function `outcome_v2_c9e8c1da::result::as_void`<a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::as_void()const&"></a>

<pre><code class="language-cpp"><a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::rebind-T,U-'>rebind&lt;void&gt;</a> as_void() const &amp;;</code></pre>

Returns this result rebound to void with any errored state copied.

*Requires*: This result to have a failed state, else whatever `assume_error()` would do.

### Function `outcome_v2_c9e8c1da::result::as_void`<a id="outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::as_void()&&"></a>

<pre><code class="language-cpp"><a href='doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy-::rebind-T,U-'>rebind&lt;void&gt;</a> as_void() &amp;&amp;;</code></pre>

Returns this result rebound to void with any errored state moved.

*Requires*: This result to have a failed state, else whatever `assume_error()` would do.

-----

-----
