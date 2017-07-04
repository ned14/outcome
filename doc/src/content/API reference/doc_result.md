+++
title = "result<R, S>"
slug = "doc_result.md"
+++
# Header file `result.hpp`<a id="result.hpp"></a>

<pre><code class="language-cpp">#define <a href='doc_result.md#result.hpp'>OUTCOME_RESULT_HPP</a>

#define <a href='doc_result.md#result.hpp'>OUTCOME_SYMBOL_VISIBLE</a>

#define <a href='doc_result.md#result.hpp'>OUTCOME_NODISCARD</a>

#define <a href='doc_result.md#OUTCOME_ENABLE_POSITIVE_STATUS'>OUTCOME_ENABLE_POSITIVE_STATUS</a>

namespace <a href='doc_result.md#result.hpp'>outcome</a>
{
    template &lt;class T&gt;
    struct <a href='doc_result.md#outcome::in_place_type_t-T-'>in_place_type_t</a>;
    
    class <a href='doc_result.md#outcome::bad_result_access'>bad_result_access</a>;
    
    struct <a href='doc_result.md#outcome::no_error_type'>no_error_type</a>;
    
    namespace <a href='doc_result.md#result.hpp'>impl</a>
    {
        template &lt;class R, class EC, class NoValuePolicy&gt;
        class <a href='doc_result.md#outcome::impl::result_storage-R,EC,NoValuePolicy-'>result_storage</a>;
        
        template &lt;class Base, class R, class NoValuePolicy&gt;
        class <a href='doc_result.md#outcome::impl::result_value_observers-Base,R,NoValuePolicy-'>result_value_observers</a>;
        
        template &lt;class Base, class NoValuePolicy&gt;
        class <a href='doc_result.md#result.hpp'>result_value_observers&lt;Base, void, NoValuePolicy&gt;</a>;
        
        template &lt;class Base, class EC, class NoValuePolicy&gt;
        class <a href='doc_result.md#outcome::impl::result_error_observers-Base,EC,NoValuePolicy-'>result_error_observers</a>;
        
        template &lt;class Base, class NoValuePolicy&gt;
        class <a href='doc_result.md#result.hpp'>result_error_observers&lt;Base, void, NoValuePolicy&gt;</a>;
        
        template &lt;class R, class EC, class NoValuePolicy&gt;
        using <a href='doc_result.md#result.hpp'>select_result_impl</a> = <a href='doc_result.md#outcome::impl::result_error_observers-Base,EC,NoValuePolicy-'>result_error_observers&lt;result_value_observers&lt;result_storage&lt;R, EC, NoValuePolicy&gt;, R, NoValuePolicy&gt;, EC, NoValuePolicy&gt;</a>;
        
        template &lt;class R, class S, class NoValuePolicy&gt;
        class <a href='doc_result.md#outcome::impl::result_final-R,S,NoValuePolicy-'>result_final</a>;
    }
    
    namespace <a href='doc_result.md#outcome::policy'>policy</a>
    {
        template &lt;class EC&gt;
        struct <a href='doc_result.md#outcome::policy::throw_directly-EC-'>throw_directly</a>;
        
        template &lt;class EC&gt;
        struct <a href='doc_result.md#outcome::policy::error_code_throw_as_system_error-EC-'>error_code_throw_as_system_error</a>;
        
        template &lt;class EC&gt;
        struct <a href='doc_result.md#outcome::policy::exception_ptr_rethrow-EC-'>exception_ptr_rethrow</a>;
        
        struct <a href='doc_result.md#outcome::policy::terminate'>terminate</a>;
        
        template &lt;class EC&gt;
        using <a href='doc_result.md#outcome::policy::default_result_policy-EC-'>default_result_policy</a> = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::conditional_t%3c//std::is_void%3cEC%3e::value,//terminate,//std::conditional_t%3c//detail::is_same_or_constructible%3cstd::error_code,EC%3e,error_code_throw_as_system_error%3cEC%3e,//std::conditional_t%3c//detail::is_same_or_constructible%3cstd::exception_ptr,EC%3e,exception_ptr_rethrow%3cEC%3e,//throw_directly%3cEC%3e//%3e%3e%3e'>std::conditional_t&lt;//std::is_void&lt;EC&gt;::value, //terminate, //std::conditional_t&lt;//detail::is_same_or_constructible&lt;std::error_code, EC&gt;, error_code_throw_as_system_error&lt;EC&gt;, //std::conditional_t&lt;//detail::is_same_or_constructible&lt;std::exception_ptr, EC&gt;, exception_ptr_rethrow&lt;EC&gt;, //throw_directly&lt;EC&gt;//&gt;&gt;&gt;</a>;
    }
    
    template &lt;class R, class S = error_code_extended, class NoValuePolicy = policy::default_result_policy&lt;S&gt;
    class <a href='doc_result.md#outcome::result-R,S,NoValuePolicy-'>result</a>;
    
    template &lt;class NoValuePolicy&gt;
    class <a href='doc_result.md#outcome::result-void,void,NoValuePolicy-'>result&lt;void, void, NoValuePolicy&gt;</a>;
}</code></pre>

## Macro `OUTCOME_ENABLE_POSITIVE_STATUS`<a id="OUTCOME_ENABLE_POSITIVE_STATUS"></a>

<pre><code class="language-cpp">#define OUTCOME_ENABLE_POSITIVE_STATUS</code></pre>

Define to enable positive value + status returns

## Class template `outcome::in_place_type_t`<a id="outcome::in_place_type_t-T-"></a>

<pre><code class="language-cpp">template &lt;class T&gt;
struct in_place_type_t
{
    <a href='doc_result.md#outcome::in_place_type_t-T-'>in_place_type_t</a>() = default;
};</code></pre>

Aliases `std::in_place_type_t<T>` if on C++ 17 or later, else defined locally.

## Class `outcome::bad_result_access`<a id="outcome::bad_result_access"></a>

<pre><code class="language-cpp">class bad_result_access
: public <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::logic_error'>std::logic_error</a>
{
public:
    <a href='doc_result.md#outcome::bad_result_access'>bad_result_access</a>(const char* what);
};</code></pre>

Thrown when you try to access state in a `result<R, S>` which isn't present.

## Struct `outcome::no_error_type`<a id="outcome::no_error_type"></a>

<pre><code class="language-cpp">struct no_error_type
{
    <a href='doc_result.md#outcome::no_error_type'>no_error_type</a>() = delete;
};</code></pre>

Placeholder type to indicate there is no error type

## Class template `outcome::impl::result_storage`<a id="outcome::impl::result_storage-R,EC,NoValuePolicy-"></a>

<pre><code class="language-cpp">template &lt;class R, class EC, class NoValuePolicy&gt;
class result_storage
{
protected:
    'hidden' <a href='doc_result.md#outcome::impl::result_storage-R,EC,NoValuePolicy-'>_state</a>;
    
    'hidden' <a href='doc_result.md#outcome::impl::result_storage-R,EC,NoValuePolicy-'>_error</a>;
    
    <a href='doc_result.md#outcome::impl::result_storage-R,EC,NoValuePolicy-'>result_storage</a>() = default;
    
    template &lt;class ... Args&gt;
    constexpr <a href='doc_result.md#outcome::impl::result_storage-R,EC,NoValuePolicy-'>result_storage</a>(<a href='doc_result.md#outcome::in_place_type_t-T-'>in_place_type_t&lt;value_type&gt;</a> _, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;value_type, Args...&gt;::value);
    
    template &lt;class U, class ... Args&gt;
    constexpr <a href='doc_result.md#outcome::impl::result_storage-R,EC,NoValuePolicy-'>result_storage</a>(<a href='doc_result.md#outcome::in_place_type_t-T-'>in_place_type_t&lt;value_type&gt;</a> _, <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::initializer_list%3cU%3e'>std::initializer_list&lt;U&gt;</a> il, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;value_type, std::initializer_list&lt;U&gt;, Args...&gt;::value);
    
    template &lt;class ... Args&gt;
    constexpr <a href='doc_result.md#outcome::impl::result_storage-R,EC,NoValuePolicy-'>result_storage</a>(<a href='doc_result.md#outcome::in_place_type_t-T-'>in_place_type_t&lt;error_type&gt;</a>, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;error_type, Args...&gt;::value);
    
    template &lt;class U, class ... Args&gt;
    constexpr <a href='doc_result.md#outcome::impl::result_storage-R,EC,NoValuePolicy-'>result_storage</a>(<a href='doc_result.md#outcome::in_place_type_t-T-'>in_place_type_t&lt;error_type&gt;</a>, <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::initializer_list%3cU%3e'>std::initializer_list&lt;U&gt;</a> il, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;error_type, std::initializer_list&lt;U&gt;, Args...&gt;::value);
    
    struct <a href='doc_result.md#outcome::impl::result_storage-R,EC,NoValuePolicy-'>compatible_conversion_tag</a>;
    
    template &lt;class T, class U, class V&gt;
    constexpr <a href='doc_result.md#outcome::impl::result_storage-R,EC,NoValuePolicy-'>result_storage</a>(<a href='doc_result.md#outcome::impl::result_storage-R,EC,NoValuePolicy-'>compatible_conversion_tag</a>, const <a href='doc_result.md#outcome::impl::result_storage-R,EC,NoValuePolicy-'>result_storage&lt;T, U, V&gt;</a>&amp; o) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;error_type, U&gt;::value);
    
    template &lt;class U, class V&gt;
    constexpr <a href='doc_result.md#outcome::impl::result_storage-R,EC,NoValuePolicy-'>result_storage</a>(<a href='doc_result.md#outcome::impl::result_storage-R,EC,NoValuePolicy-'>compatible_conversion_tag</a>, const <a href='doc_result.md#outcome::impl::result_storage-R,EC,NoValuePolicy-'>result_storage&lt;void, U, V&gt;</a>&amp; o) noexcept(std::is_nothrow_constructible&lt;error_type, U&gt;::value);
    
    template &lt;class T, class V&gt;
    constexpr <a href='doc_result.md#outcome::impl::result_storage-R,EC,NoValuePolicy-'>result_storage</a>(<a href='doc_result.md#outcome::impl::result_storage-R,EC,NoValuePolicy-'>compatible_conversion_tag</a>, const <a href='doc_result.md#outcome::impl::result_storage-R,EC,NoValuePolicy-'>result_storage&lt;T, void, V&gt;</a>&amp; o) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value);
    
    template &lt;class T, class U, class V&gt;
    constexpr <a href='doc_result.md#outcome::impl::result_storage-R,EC,NoValuePolicy-'>result_storage</a>(<a href='doc_result.md#outcome::impl::result_storage-R,EC,NoValuePolicy-'>compatible_conversion_tag</a>, <a href='doc_result.md#outcome::impl::result_storage-R,EC,NoValuePolicy-'>result_storage&lt;T, U, V&gt;</a>&amp;&amp; o) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;error_type, U&gt;::value);
    
    template &lt;class U, class V&gt;
    constexpr <a href='doc_result.md#outcome::impl::result_storage-R,EC,NoValuePolicy-'>result_storage</a>(<a href='doc_result.md#outcome::impl::result_storage-R,EC,NoValuePolicy-'>compatible_conversion_tag</a>, <a href='doc_result.md#outcome::impl::result_storage-R,EC,NoValuePolicy-'>result_storage&lt;void, U, V&gt;</a>&amp;&amp; o) noexcept(std::is_nothrow_constructible&lt;error_type, U&gt;::value);
    
    template &lt;class T, class V&gt;
    constexpr <a href='doc_result.md#outcome::impl::result_storage-R,EC,NoValuePolicy-'>result_storage</a>(<a href='doc_result.md#outcome::impl::result_storage-R,EC,NoValuePolicy-'>compatible_conversion_tag</a>, <a href='doc_result.md#outcome::impl::result_storage-R,EC,NoValuePolicy-'>result_storage&lt;T, void, V&gt;</a>&amp;&amp; o) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value);
};</code></pre>

The base implementation type of `result<R, EC, NoValuePolicy>`. Only appears separate due to standardese limitations.

## Class template `outcome::impl::result_value_observers`<a id="outcome::impl::result_value_observers-Base,R,NoValuePolicy-"></a>

<pre><code class="language-cpp">template &lt;class Base, class R, class NoValuePolicy&gt;
class result_value_observers
: public Base
{
public:
    using <a href='doc_result.md#outcome::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a> = R;
    
    using Base::Base;
    
    constexpr <a href='doc_result.md#outcome::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a>&amp; <a href='doc_result.md#outcome::impl::result_value_observers-Base,R,NoValuePolicy-::assume_value()&'>assume_value</a>() &amp; noexcept;
    constexpr const <a href='doc_result.md#outcome::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a>&amp; <a href='doc_result.md#outcome::impl::result_value_observers-Base,R,NoValuePolicy-::assume_value()&'>assume_value</a>() const &amp; noexcept;
    constexpr <a href='doc_result.md#outcome::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a>&amp;&amp; <a href='doc_result.md#outcome::impl::result_value_observers-Base,R,NoValuePolicy-::assume_value()&'>assume_value</a>() &amp;&amp; noexcept;
    constexpr const <a href='doc_result.md#outcome::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a>&amp;&amp; <a href='doc_result.md#outcome::impl::result_value_observers-Base,R,NoValuePolicy-::assume_value()&'>assume_value</a>() const &amp;&amp; noexcept;
    
    constexpr <a href='doc_result.md#outcome::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a>&amp; <a href='doc_result.md#outcome::impl::result_value_observers-Base,R,NoValuePolicy-::value()&'>value</a>() &amp;;
    constexpr const <a href='doc_result.md#outcome::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a>&amp; <a href='doc_result.md#outcome::impl::result_value_observers-Base,R,NoValuePolicy-::value()&'>value</a>() const &amp;;
    constexpr <a href='doc_result.md#outcome::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a>&amp;&amp; <a href='doc_result.md#outcome::impl::result_value_observers-Base,R,NoValuePolicy-::value()&'>value</a>() &amp;&amp;;
    constexpr const <a href='doc_result.md#outcome::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a>&amp;&amp; <a href='doc_result.md#outcome::impl::result_value_observers-Base,R,NoValuePolicy-::value()&'>value</a>() const &amp;&amp;;
};</code></pre>

The value observers implementation of `result<R, EC, NoValuePolicy>`. Only appears separate due to standardese limitations.

### Function `outcome::impl::result_value_observers::assume_value`<a id="outcome::impl::result_value_observers-Base,R,NoValuePolicy-::assume_value()&"></a>

<pre><code class="language-cpp">(1)  constexpr <a href='doc_result.md#outcome::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a>&amp; assume_value() &amp; noexcept;

(2)  constexpr const <a href='doc_result.md#outcome::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a>&amp; assume_value() const &amp; noexcept;

(3)  constexpr <a href='doc_result.md#outcome::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a>&amp;&amp; assume_value() &amp;&amp; noexcept;

(4)  constexpr const <a href='doc_result.md#outcome::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a>&amp;&amp; assume_value() const &amp;&amp; noexcept;</code></pre>

Access value without runtime checks.

*Returns*: Reference to the held `value_type` according to overload.

### Function `outcome::impl::result_value_observers::value`<a id="outcome::impl::result_value_observers-Base,R,NoValuePolicy-::value()&"></a>

<pre><code class="language-cpp">(1)  constexpr <a href='doc_result.md#outcome::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a>&amp; value() &amp;;

(2)  constexpr const <a href='doc_result.md#outcome::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a>&amp; value() const &amp;;

(3)  constexpr <a href='doc_result.md#outcome::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a>&amp;&amp; value() &amp;&amp;;

(4)  constexpr const <a href='doc_result.md#outcome::impl::result_value_observers-Base,R,NoValuePolicy-'>value_type</a>&amp;&amp; value() const &amp;&amp;;</code></pre>

Access value with runtime checks.

*Returns*: Reference to the held `value_type` according to overload.

*Requires*: The result to have a successful state, else whatever `NoValuePolicy` says ought to happen.

-----

## Class template `outcome::impl::result_error_observers`<a id="outcome::impl::result_error_observers-Base,EC,NoValuePolicy-"></a>

<pre><code class="language-cpp">template &lt;class Base, class EC, class NoValuePolicy&gt;
class result_error_observers
: public Base
{
public:
    using <a href='doc_result.md#outcome::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a> = EC;
    
    using Base::Base;
    
    constexpr <a href='doc_result.md#outcome::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a>&amp; <a href='doc_result.md#outcome::impl::result_error_observers-Base,EC,NoValuePolicy-::assume_error()&'>assume_error</a>() &amp; noexcept;
    constexpr const <a href='doc_result.md#outcome::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a>&amp; <a href='doc_result.md#outcome::impl::result_error_observers-Base,EC,NoValuePolicy-::assume_error()&'>assume_error</a>() const &amp; noexcept;
    constexpr <a href='doc_result.md#outcome::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a>&amp;&amp; <a href='doc_result.md#outcome::impl::result_error_observers-Base,EC,NoValuePolicy-::assume_error()&'>assume_error</a>() &amp;&amp; noexcept;
    constexpr const <a href='doc_result.md#outcome::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a>&amp;&amp; <a href='doc_result.md#outcome::impl::result_error_observers-Base,EC,NoValuePolicy-::assume_error()&'>assume_error</a>() const &amp;&amp; noexcept;
    
    constexpr <a href='doc_result.md#outcome::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a>&amp; <a href='doc_result.md#outcome::impl::result_error_observers-Base,EC,NoValuePolicy-::error()&'>error</a>() &amp;;
    constexpr const <a href='doc_result.md#outcome::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a>&amp; <a href='doc_result.md#outcome::impl::result_error_observers-Base,EC,NoValuePolicy-::error()&'>error</a>() const &amp;;
    constexpr <a href='doc_result.md#outcome::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a>&amp;&amp; <a href='doc_result.md#outcome::impl::result_error_observers-Base,EC,NoValuePolicy-::error()&'>error</a>() &amp;&amp;;
    constexpr const <a href='doc_result.md#outcome::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a>&amp;&amp; <a href='doc_result.md#outcome::impl::result_error_observers-Base,EC,NoValuePolicy-::error()&'>error</a>() const &amp;&amp;;
};</code></pre>

The error observers implementation of `result<R, EC, NoValuePolicy>`. Only appears separate due to standardese limitations.

### Function `outcome::impl::result_error_observers::assume_error`<a id="outcome::impl::result_error_observers-Base,EC,NoValuePolicy-::assume_error()&"></a>

<pre><code class="language-cpp">(1)  constexpr <a href='doc_result.md#outcome::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a>&amp; assume_error() &amp; noexcept;

(2)  constexpr const <a href='doc_result.md#outcome::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a>&amp; assume_error() const &amp; noexcept;

(3)  constexpr <a href='doc_result.md#outcome::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a>&amp;&amp; assume_error() &amp;&amp; noexcept;

(4)  constexpr const <a href='doc_result.md#outcome::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a>&amp;&amp; assume_error() const &amp;&amp; noexcept;</code></pre>

Access error without runtime checks.

*Returns*: Reference to the held `error_type` according to overload.

### Function `outcome::impl::result_error_observers::error`<a id="outcome::impl::result_error_observers-Base,EC,NoValuePolicy-::error()&"></a>

<pre><code class="language-cpp">(1)  constexpr <a href='doc_result.md#outcome::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a>&amp; error() &amp;;

(2)  constexpr const <a href='doc_result.md#outcome::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a>&amp; error() const &amp;;

(3)  constexpr <a href='doc_result.md#outcome::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a>&amp;&amp; error() &amp;&amp;;

(4)  constexpr const <a href='doc_result.md#outcome::impl::result_error_observers-Base,EC,NoValuePolicy-'>error_type</a>&amp;&amp; error() const &amp;&amp;;</code></pre>

Access error with runtime checks.

*Returns*: Reference to the held `error_type` according to overload.

*Requires*: The result to have a failed state, else whatever `NoValuePolicy` says ought to happen.

-----

## Class template `outcome::impl::result_final`<a id="outcome::impl::result_final-R,S,NoValuePolicy-"></a>

<pre><code class="language-cpp">template &lt;class R, class S, class NoValuePolicy&gt;
class result_final
: public <a href='doc_result.md#result.hpp'>select_result_impl&lt;R, S, NoValuePolicy&gt;</a>
{
public:
    //=== <a href='doc_result.md#outcome::impl::result_final-R,S,NoValuePolicy-::value_type'>Member types</a> ===//
    using <a href='doc_result.md#outcome::impl::result_final-R,S,NoValuePolicy-::value_type'>value_type</a> = R;
    
    using <a href='doc_result.md#outcome::impl::result_final-R,S,NoValuePolicy-::status_error_type'>status_error_type</a> = S;
    
    using <a href='doc_result.md#outcome::impl::result_final-R,S,NoValuePolicy-::error_type'>error_type</a> = S;
    
    using <a href='standardese://outcome::impl::result_final<R, S, NoValuePolicy>::base/'>base::base</a>;
    
    constexpr <a href='doc_result.md#outcome::impl::result_final-R,S,NoValuePolicy-::operatorbool()const'>operator bool</a>() const noexcept;
    
    constexpr bool <a href='doc_result.md#outcome::impl::result_final-R,S,NoValuePolicy-::has_value()const'>has_value</a>() const noexcept;
    
    constexpr bool <a href='doc_result.md#outcome::impl::result_final-R,S,NoValuePolicy-::has_error()const'>has_error</a>() const noexcept;
    
    constexpr bool <a href='doc_result.md#outcome::impl::result_final-R,S,NoValuePolicy-::has_payload()const'>has_payload</a>() const noexcept;
    
    constexpr bool <a href='doc_result.md#outcome::impl::result_final-R,S,NoValuePolicy-::has_exception()const'>has_exception</a>() const noexcept;
};</code></pre>

The assembled implementation type of `result<R, EC, NoValuePolicy>`. Only appears separate due to standardese limitations.

### Type alias `outcome::impl::result_final::value_type`<a id="outcome::impl::result_final-R,S,NoValuePolicy-::value_type"></a>

<pre><code class="language-cpp">using value_type = R;</code></pre>

The success type.

### Type alias `outcome::impl::result_final::status_error_type`<a id="outcome::impl::result_final-R,S,NoValuePolicy-::status_error_type"></a>

<pre><code class="language-cpp">using status_error_type = S;</code></pre>

The S type configured

### Type alias `outcome::impl::result_final::error_type`<a id="outcome::impl::result_final-R,S,NoValuePolicy-::error_type"></a>

<pre><code class="language-cpp">using error_type = S;</code></pre>

The failure type.

### Conversion operator `outcome::impl::result_final::operator bool`<a id="outcome::impl::result_final-R,S,NoValuePolicy-::operatorbool()const"></a>

<pre><code class="language-cpp">constexpr operator bool() const noexcept;</code></pre>

Checks if has value.

*Returns*: True if has value.

### Function `outcome::impl::result_final::has_value`<a id="outcome::impl::result_final-R,S,NoValuePolicy-::has_value()const"></a>

<pre><code class="language-cpp">constexpr bool has_value() const noexcept;</code></pre>

Checks if has value.

*Returns*: True if has value.

### Function `outcome::impl::result_final::has_error`<a id="outcome::impl::result_final-R,S,NoValuePolicy-::has_error()const"></a>

<pre><code class="language-cpp">constexpr bool has_error() const noexcept;</code></pre>

Checks if has error.

*Returns*: True if has error.

### Function `outcome::impl::result_final::has_payload`<a id="outcome::impl::result_final-R,S,NoValuePolicy-::has_payload()const"></a>

<pre><code class="language-cpp">constexpr bool has_payload() const noexcept;</code></pre>

Checks if has payload.

*Returns*: True if has payload.

### Function `outcome::impl::result_final::has_exception`<a id="outcome::impl::result_final-R,S,NoValuePolicy-::has_exception()const"></a>

<pre><code class="language-cpp">constexpr bool has_exception() const noexcept;</code></pre>

Checks if has exception.

*Returns*: True if has exception.

-----

-----

## Namespace `outcome::policy`<a id="outcome::policy"></a>

<pre><code class="language-cpp">namespace policy
{
    template &lt;class EC&gt;
    struct <a href='doc_result.md#outcome::policy::throw_directly-EC-'>throw_directly</a>;
    
    template &lt;class EC&gt;
    struct <a href='doc_result.md#outcome::policy::error_code_throw_as_system_error-EC-'>error_code_throw_as_system_error</a>;
    
    template &lt;class EC&gt;
    struct <a href='doc_result.md#outcome::policy::exception_ptr_rethrow-EC-'>exception_ptr_rethrow</a>;
    
    struct <a href='doc_result.md#outcome::policy::terminate'>terminate</a>;
    
    template &lt;class EC&gt;
    using <a href='doc_result.md#outcome::policy::default_result_policy-EC-'>default_result_policy</a> = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::conditional_t%3c//std::is_void%3cEC%3e::value,//terminate,//std::conditional_t%3c//detail::is_same_or_constructible%3cstd::error_code,EC%3e,error_code_throw_as_system_error%3cEC%3e,//std::conditional_t%3c//detail::is_same_or_constructible%3cstd::exception_ptr,EC%3e,exception_ptr_rethrow%3cEC%3e,//throw_directly%3cEC%3e//%3e%3e%3e'>std::conditional_t&lt;//std::is_void&lt;EC&gt;::value, //terminate, //std::conditional_t&lt;//detail::is_same_or_constructible&lt;std::error_code, EC&gt;, error_code_throw_as_system_error&lt;EC&gt;, //std::conditional_t&lt;//detail::is_same_or_constructible&lt;std::exception_ptr, EC&gt;, exception_ptr_rethrow&lt;EC&gt;, //throw_directly&lt;EC&gt;//&gt;&gt;&gt;</a>;
}</code></pre>

Namespace for policies

### Class template `outcome::policy::throw_directly` \[Error code interpretation policy\]<a id="outcome::policy::throw_directly-EC-"></a>

<pre><code class="language-cpp">template &lt;class EC&gt;
struct throw_directly
{
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome::policy::throw_directly-EC-::narrow_value_check(Impl*)'>narrow_value_check</a>(Impl* self) noexcept;
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome::policy::throw_directly-EC-::narrow_error_check(Impl*)'>narrow_error_check</a>(Impl* self) noexcept;
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome::policy::throw_directly-EC-::wide_value_check(Impl*)'>wide_value_check</a>(Impl* self);
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome::policy::throw_directly-EC-::wide_error_check(Impl*)'>wide_error_check</a>(Impl* self);
};</code></pre>

Policy interpreting EC as a type to be thrown directly during wide checks.

#### Function template `outcome::policy::throw_directly::narrow_value_check`<a id="outcome::policy::throw_directly-EC-::narrow_value_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void narrow_value_check(Impl* self) noexcept;</code></pre>

Performs a narrow check of state, used in the assume\_value() functions.

*Effects*: None.

#### Function template `outcome::policy::throw_directly::narrow_error_check`<a id="outcome::policy::throw_directly-EC-::narrow_error_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void narrow_error_check(Impl* self) noexcept;</code></pre>

Performs a narrow check of state, used in the assume\_error() functions

*Effects*: None.

#### Function template `outcome::policy::throw_directly::wide_value_check`<a id="outcome::policy::throw_directly-EC-::wide_value_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void wide_value_check(Impl* self);</code></pre>

Performs a wide check of state, used in the value() functions.

*Effects*: If result does not have a value, if it has an error it throws that `error()`, else it throws `bad_result_access`.

#### Function template `outcome::policy::throw_directly::wide_error_check`<a id="outcome::policy::throw_directly-EC-::wide_error_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void wide_error_check(Impl* self);</code></pre>

Performs a wide check of state, used in the error() functions

*Effects*: If result does not have an error, it throws `bad_result_access`.

-----

### Class template `outcome::policy::error_code_throw_as_system_error` \[Error code interpretation policy\]<a id="outcome::policy::error_code_throw_as_system_error-EC-"></a>

<pre><code class="language-cpp">template &lt;class EC&gt;
struct error_code_throw_as_system_error
{
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome::policy::error_code_throw_as_system_error-EC-::narrow_value_check(Impl*)'>narrow_value_check</a>(Impl* self) noexcept;
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome::policy::error_code_throw_as_system_error-EC-::narrow_error_check(Impl*)'>narrow_error_check</a>(Impl* self) noexcept;
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome::policy::error_code_throw_as_system_error-EC-::wide_value_check(Impl*)'>wide_value_check</a>(Impl* self);
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome::policy::error_code_throw_as_system_error-EC-::wide_error_check(Impl*)'>wide_error_check</a>(Impl* self);
};</code></pre>

Policy interpreting EC as a type implementing the `std::error_code` contract and any wide attempt to access the successful state throws the `error_code` wrapped into a `std::system_error`

#### Function template `outcome::policy::error_code_throw_as_system_error::narrow_value_check`<a id="outcome::policy::error_code_throw_as_system_error-EC-::narrow_value_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void narrow_value_check(Impl* self) noexcept;</code></pre>

Performs a narrow check of state, used in the assume\_value() functions.

*Effects*: None.

#### Function template `outcome::policy::error_code_throw_as_system_error::narrow_error_check`<a id="outcome::policy::error_code_throw_as_system_error-EC-::narrow_error_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void narrow_error_check(Impl* self) noexcept;</code></pre>

Performs a narrow check of state, used in the assume\_error() functions.

*Effects*: None.

#### Function template `outcome::policy::error_code_throw_as_system_error::wide_value_check`<a id="outcome::policy::error_code_throw_as_system_error-EC-::wide_value_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void wide_value_check(Impl* self);</code></pre>

Performs a wide check of state, used in the value() functions.

*Effects*: If result does not have a value, if it has an error it throws a `std::system_error(error())`, else it throws `bad_result_access`.

#### Function template `outcome::policy::error_code_throw_as_system_error::wide_error_check`<a id="outcome::policy::error_code_throw_as_system_error-EC-::wide_error_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void wide_error_check(Impl* self);</code></pre>

Performs a wide check of state, used in the error() functions

*Effects*: If result does not have an error, it throws `bad_result_access`.

-----

### Class template `outcome::policy::exception_ptr_rethrow` \[Error code interpretation policy\]<a id="outcome::policy::exception_ptr_rethrow-EC-"></a>

<pre><code class="language-cpp">template &lt;class EC&gt;
struct exception_ptr_rethrow
{
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome::policy::exception_ptr_rethrow-EC-::narrow_value_check(Impl*)'>narrow_value_check</a>(Impl* self) noexcept;
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome::policy::exception_ptr_rethrow-EC-::narrow_error_check(Impl*)'>narrow_error_check</a>(Impl* self) noexcept;
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome::policy::exception_ptr_rethrow-EC-::wide_value_check(Impl*)'>wide_value_check</a>(Impl* self);
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome::policy::exception_ptr_rethrow-EC-::wide_error_check(Impl*)'>wide_error_check</a>(Impl* self);
};</code></pre>

Policy interpreting EC as a type implementing the `std::exception_ptr` contract and any wide attempt to access the successful state calls `std::rethrow_exception()`.

#### Function template `outcome::policy::exception_ptr_rethrow::narrow_value_check`<a id="outcome::policy::exception_ptr_rethrow-EC-::narrow_value_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void narrow_value_check(Impl* self) noexcept;</code></pre>

Performs a narrow check of state, used in the assume\_value() functions.

*Effects*: None.

#### Function template `outcome::policy::exception_ptr_rethrow::narrow_error_check`<a id="outcome::policy::exception_ptr_rethrow-EC-::narrow_error_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void narrow_error_check(Impl* self) noexcept;</code></pre>

Performs a narrow check of state, used in the assume\_error() functions

*Effects*: None.

#### Function template `outcome::policy::exception_ptr_rethrow::wide_value_check`<a id="outcome::policy::exception_ptr_rethrow-EC-::wide_value_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void wide_value_check(Impl* self);</code></pre>

Performs a wide check of state, used in the value() functions

*Effects*: If result does not have a value, if it has an error it rethrows that error via `std::rethrow_exception()`, else it throws `bad_result_access`.

#### Function template `outcome::policy::exception_ptr_rethrow::wide_error_check`<a id="outcome::policy::exception_ptr_rethrow-EC-::wide_error_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void wide_error_check(Impl* self);</code></pre>

Performs a wide check of state, used in the value() functions

*Effects*: If result does not have a value, if it has an error it throws that error, else it throws `bad_result_access`.

-----

### Struct `outcome::policy::terminate` \[Error code interpretation policy\]<a id="outcome::policy::terminate"></a>

<pre><code class="language-cpp">struct terminate
{
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome::policy::terminate::narrow_value_check(Impl*)'>narrow_value_check</a>(Impl* self) noexcept;
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome::policy::terminate::narrow_error_check(Impl*)'>narrow_error_check</a>(Impl* self) noexcept;
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome::policy::terminate::narrow_payload_check(Impl*)'>narrow_payload_check</a>(Impl* self) noexcept;
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome::policy::terminate::narrow_exception_check(Impl*)'>narrow_exception_check</a>(Impl* self) noexcept;
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome::policy::terminate::wide_value_check(Impl*)'>wide_value_check</a>(Impl* self);
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome::policy::terminate::wide_error_check(Impl*)'>wide_error_check</a>(Impl* self) noexcept;
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome::policy::terminate::wide_payload_check(Impl*)'>wide_payload_check</a>(Impl* self);
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_result.md#outcome::policy::terminate::wide_exception_check(Impl*)'>wide_exception_check</a>(Impl* self);
};</code></pre>

Policy implementing any wide attempt to access the successful state as calling `std::terminate`

#### Function template `outcome::policy::terminate::narrow_value_check`<a id="outcome::policy::terminate::narrow_value_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void narrow_value_check(Impl* self) noexcept;</code></pre>

Performs a narrow check of state, used in the assume\_value() functions.

*Effects*: None.

#### Function template `outcome::policy::terminate::narrow_error_check`<a id="outcome::policy::terminate::narrow_error_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void narrow_error_check(Impl* self) noexcept;</code></pre>

Performs a narrow check of state, used in the assume\_error() functions

*Effects*: None.

#### Function template `outcome::policy::terminate::narrow_payload_check`<a id="outcome::policy::terminate::narrow_payload_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void narrow_payload_check(Impl* self) noexcept;</code></pre>

Performs a narrow check of state, used in the assume\_payload() functions

*Effects*: None.

#### Function template `outcome::policy::terminate::narrow_exception_check`<a id="outcome::policy::terminate::narrow_exception_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void narrow_exception_check(Impl* self) noexcept;</code></pre>

Performs a narrow check of state, used in the assume\_exception() functions

*Effects*: None.

#### Function template `outcome::policy::terminate::wide_value_check`<a id="outcome::policy::terminate::wide_value_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void wide_value_check(Impl* self);</code></pre>

Performs a wide check of state, used in the value() functions.

*Effects*: If result does not have a value, calls `std::terminate()`.

#### Function template `outcome::policy::terminate::wide_error_check`<a id="outcome::policy::terminate::wide_error_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void wide_error_check(Impl* self) noexcept;</code></pre>

Performs a wide check of state, used in the error() functions

*Effects*: If result does not have an error, calls `std::terminate()`.

#### Function template `outcome::policy::terminate::wide_payload_check`<a id="outcome::policy::terminate::wide_payload_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void wide_payload_check(Impl* self);</code></pre>

Performs a wide check of state, used in the payload() functions

*Effects*: If outcome does not have an exception, calls `std::terminate()`.

#### Function template `outcome::policy::terminate::wide_exception_check`<a id="outcome::policy::terminate::wide_exception_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void wide_exception_check(Impl* self);</code></pre>

Performs a wide check of state, used in the exception() functions

*Effects*: If outcome does not have an exception, calls `std::terminate()`.

-----

### Alias template `outcome::policy::default_result_policy` \[Error code interpretation policy\]<a id="outcome::policy::default_result_policy-EC-"></a>

<pre><code class="language-cpp">template &lt;class EC&gt;
using default_result_policy = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::conditional_t%3c//std::is_void%3cEC%3e::value,//terminate,//std::conditional_t%3c//detail::is_same_or_constructible%3cstd::error_code,EC%3e,error_code_throw_as_system_error%3cEC%3e,//std::conditional_t%3c//detail::is_same_or_constructible%3cstd::exception_ptr,EC%3e,exception_ptr_rethrow%3cEC%3e,//throw_directly%3cEC%3e//%3e%3e%3e'>std::conditional_t&lt;//std::is_void&lt;EC&gt;::value, //terminate, //std::conditional_t&lt;//detail::is_same_or_constructible&lt;std::error_code, EC&gt;, error_code_throw_as_system_error&lt;EC&gt;, //std::conditional_t&lt;//detail::is_same_or_constructible&lt;std::exception_ptr, EC&gt;, exception_ptr_rethrow&lt;EC&gt;, //throw_directly&lt;EC&gt;//&gt;&gt;&gt;</a>;</code></pre>

Default `result<R, S>` policy selector.

-----

## Class template `outcome::result` \[result\<R, S\> implementation\]<a id="outcome::result-R,S,NoValuePolicy-"></a>

<pre><code class="language-cpp">template &lt;class R, class S = error_code_extended, class NoValuePolicy = policy::default_result_policy&lt;S&gt;
class result
: public <a href='doc_result.md#outcome::impl::result_final-R,S,NoValuePolicy-'>impl::result_final&lt;R, S, NoValuePolicy&gt;</a>
{
public:
    //=== <a href='doc_result.md#outcome::result-R,S,NoValuePolicy-::value_type'>Member types</a> ===//
    using <a href='doc_result.md#outcome::result-R,S,NoValuePolicy-::value_type'>value_type</a> = R;
    
    using <a href='doc_result.md#outcome::result-R,S,NoValuePolicy-::status_error_type'>status_error_type</a> = S;
    
    using <a href='doc_result.md#outcome::result-R,S,NoValuePolicy-::error_type'>error_type</a> = typename base::error_type;
    
    //=== <a href='doc_result.md#outcome::result-R,S,NoValuePolicy-::result()'>Default, copy/move constructors and assignment</a> ===//
    <a href='doc_result.md#outcome::result-R,S,NoValuePolicy-::result()'>result</a>() = delete;
    
    <a href='doc_result.md#outcome::result-R,S,NoValuePolicy-::result(result-R,S,NoValuePolicy-&&)'>result</a>(<a href='doc_result.md#outcome::result-R,S,NoValuePolicy-'>result</a>&amp;&amp;) = default;
    
    <a href='doc_result.md#outcome::result-R,S,NoValuePolicy-::result(constresult-R,S,NoValuePolicy-&)'>result</a>(const <a href='doc_result.md#outcome::result-R,S,NoValuePolicy-'>result</a>&amp;) = default;
    
    <a href='doc_result.md#outcome::result-R,S,NoValuePolicy-'>result</a>&amp; <a href='doc_result.md#outcome::result-R,S,NoValuePolicy-::operator=(result-R,S,NoValuePolicy-&&)'>operator=</a>(<a href='doc_result.md#outcome::result-R,S,NoValuePolicy-'>result</a>&amp;&amp;) = default;
    
    <a href='doc_result.md#outcome::result-R,S,NoValuePolicy-'>result</a>&amp; <a href='doc_result.md#outcome::result-R,S,NoValuePolicy-::operator=(constresult-R,S,NoValuePolicy-&)'>operator=</a>(const <a href='doc_result.md#outcome::result-R,S,NoValuePolicy-'>result</a>&amp;) = default;
    
    template &lt;class T&gt;
    constexpr <a href='doc_result.md#outcome::result-R,S,NoValuePolicy-::result(T&&,outcome::result::value_converting_constructor_tag)'>result</a>(T&amp;&amp; t) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value);
    
    template &lt;class T&gt;
    constexpr <a href='doc_result.md#outcome::result-R,S,NoValuePolicy-::result(T&&,outcome::result::error_converting_constructor_tag)'>result</a>(T&amp;&amp; t) noexcept(std::is_nothrow_constructible&lt;error_type, T&gt;::value);
    
    template &lt;class T, class U, class V&gt;
    constexpr <a href='doc_result.md#outcome::result-R,S,NoValuePolicy-::result(constresult-T,U,V-&)'>result</a>(const <a href='doc_result.md#outcome::result-R,S,NoValuePolicy-'>result&lt;T, U, V&gt;</a>&amp; o) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;status_error_type, U&gt;::value);
    
    template &lt;class T, class U, class V&gt;
    constexpr <a href='doc_result.md#outcome::result-R,S,NoValuePolicy-::result(result-T,U,V-&&)'>result</a>(<a href='doc_result.md#outcome::result-R,S,NoValuePolicy-'>result&lt;T, U, V&gt;</a>&amp;&amp; o) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;status_error_type, U&gt;::value);
    
    template &lt;class ... Args&gt;
    constexpr <a href='doc_result.md#outcome::result-R,S,NoValuePolicy-::result(in_place_type_t-value_type-,Args&&...)'>result</a>(<a href='doc_result.md#outcome::in_place_type_t-T-'>in_place_type_t&lt;value_type&gt;</a> _, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;value_type, Args...&gt;::value);
    
    template &lt;class U, class ... Args&gt;
    constexpr <a href='doc_result.md#outcome::result-R,S,NoValuePolicy-::result(in_place_type_t-value_type-,std::initializer_list-U-,Args&&...)'>result</a>(<a href='doc_result.md#outcome::in_place_type_t-T-'>in_place_type_t&lt;value_type&gt;</a> _, <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::initializer_list%3cU%3e'>std::initializer_list&lt;U&gt;</a> il, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;value_type, std::initializer_list&lt;U&gt;, Args...&gt;::value);
    
    template &lt;class ... Args&gt;
    constexpr <a href='doc_result.md#outcome::result-R,S,NoValuePolicy-::result(in_place_type_t-error_type-,Args&&...)'>result</a>(<a href='doc_result.md#outcome::in_place_type_t-T-'>in_place_type_t&lt;error_type&gt;</a> _, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;error_type, Args...&gt;::value);
    
    template &lt;class U, class ... Args&gt;
    constexpr <a href='doc_result.md#outcome::result-R,S,NoValuePolicy-::result(in_place_type_t-error_type-,std::initializer_list-U-,Args&&...)'>result</a>(<a href='doc_result.md#outcome::in_place_type_t-T-'>in_place_type_t&lt;error_type&gt;</a> _, <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::initializer_list%3cU%3e'>std::initializer_list&lt;U&gt;</a> il, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;error_type, std::initializer_list&lt;U&gt;, Args...&gt;::value);
};</code></pre>

Used to return from functions (i) a value (ii) a value and a positive status or (iii) no value and a negative status. `constexpr` capable.

This is a vocabulary type implementing [P0262R0 A Class for Status and Optional Value](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0262r0.html), albeit with types `Status` and `Value` reversed in lexical order. By default `S` is considered to be a *positive* status type used to supply additional information about the successful return of a type `R`. If however the trait `trait::status_type_is_negative<S>` has been specialised to be true, then `S` is considered to be a *negative* status type used to supply information about the cause of failure to return a type `R`.

`trait::status_type_is_negative<S>` is already set to true for these types (you can specialise in your own types easily):

  - `std::error_code`
  - `error_code_extended`
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

  - <a id="outcome::result-R,S,NoValuePolicy-.R"></a>`R` - The optional type of the successful result (use  `void` to disable).

  - <a id="outcome::result-R,S,NoValuePolicy-.S"></a>`S` - The optional type of the status result (use  `void` to disable). Must be either `void` or DefaultConstructible.

  - <a id="outcome::result-R,S,NoValuePolicy-.NoValuePolicy"></a>`NoValuePolicy` - Policy on how to interpret type  `S` when a wide observation of a not present value occurs.

### Type alias `outcome::result::value_type`<a id="outcome::result-R,S,NoValuePolicy-::value_type"></a>

<pre><code class="language-cpp">using value_type = R;</code></pre>

The success type.

### Type alias `outcome::result::status_error_type`<a id="outcome::result-R,S,NoValuePolicy-::status_error_type"></a>

<pre><code class="language-cpp">using status_error_type = S;</code></pre>

The S type configured

### Type alias `outcome::result::error_type`<a id="outcome::result-R,S,NoValuePolicy-::error_type"></a>

<pre><code class="language-cpp">using error_type = typename base::error_type;</code></pre>

The failure type.

### Default constructor `outcome::result::result`<a id="outcome::result-R,S,NoValuePolicy-::result()"></a>

<pre><code class="language-cpp">result() = delete;</code></pre>

Default construction is not permitted.

### Move constructor `outcome::result::result`<a id="outcome::result-R,S,NoValuePolicy-::result(result-R,S,NoValuePolicy-&&)"></a>

<pre><code class="language-cpp">result(<a href='doc_result.md#outcome::result-R,S,NoValuePolicy-'>result</a>&amp;&amp;) = default;</code></pre>

Move construction available if `value_type` and `status_type`/`error_type` implement it.

### Copy constructor `outcome::result::result`<a id="outcome::result-R,S,NoValuePolicy-::result(constresult-R,S,NoValuePolicy-&)"></a>

<pre><code class="language-cpp">result(const <a href='doc_result.md#outcome::result-R,S,NoValuePolicy-'>result</a>&amp;) = default;</code></pre>

Copy construction available if `value_type` and `status_type`/`error_type` implement it.

### Assignment operator `outcome::result::operator=`<a id="outcome::result-R,S,NoValuePolicy-::operator=(result-R,S,NoValuePolicy-&&)"></a>

<pre><code class="language-cpp"><a href='doc_result.md#outcome::result-R,S,NoValuePolicy-'>result</a>&amp; operator=(<a href='doc_result.md#outcome::result-R,S,NoValuePolicy-'>result</a>&amp;&amp;) = default;</code></pre>

Move assignment available if `value_type` and `status_type`/`error_type` implement it.

### Assignment operator `outcome::result::operator=`<a id="outcome::result-R,S,NoValuePolicy-::operator=(constresult-R,S,NoValuePolicy-&)"></a>

<pre><code class="language-cpp"><a href='doc_result.md#outcome::result-R,S,NoValuePolicy-'>result</a>&amp; operator=(const <a href='doc_result.md#outcome::result-R,S,NoValuePolicy-'>result</a>&amp;) = default;</code></pre>

Copy assignment available if `value_type` and `status_type`/`error_type` implement it.

### Function template `outcome::result::result`<a id="outcome::result-R,S,NoValuePolicy-::result(T&&,outcome::result::value_converting_constructor_tag)"></a>

<pre><code class="language-cpp">template &lt;class T&gt;
constexpr result(T&amp;&amp; t) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value);</code></pre>

Converting constructor to a successful result.

*Effects*: Initialises the result with a `value_type`.

*Requires*: Type T is constructible to `value_type`, is not constructible to `status_error_type`, and is not `result<R, S>` and not `in_place_type<>`.

*Throws*: Any exception the construction of `value_type(T)` might throw.

**Parameters:**

  - <a id="outcome::result-R,S,NoValuePolicy-::result(T&&,outcome::result::value_converting_constructor_tag).t"></a>`t` - The value from which to initialise the  `value_type`.

### Function template `outcome::result::result`<a id="outcome::result-R,S,NoValuePolicy-::result(T&&,outcome::result::error_converting_constructor_tag)"></a>

<pre><code class="language-cpp">template &lt;class T&gt;
constexpr result(T&amp;&amp; t) noexcept(std::is_nothrow_constructible&lt;error_type, T&gt;::value);</code></pre>

Converting constructor to a failure result.

*Effects*: Initialises the result with a `error_type`.

*Requires*: `trait::status_type_is_negative<EC>` must be true; Type T is constructible to `error_type`, is not constructible to `value_type`, and is not `result<R, S>` and not `in_place_type<>`.

*Throws*: Any exception the construction of `error_type(T)` might throw.

**Parameters:**

  - <a id="outcome::result-R,S,NoValuePolicy-::result(T&&,outcome::result::error_converting_constructor_tag).t"></a>`t` - The value from which to initialise the  `error_type`.

### Function template `outcome::result::result`<a id="outcome::result-R,S,NoValuePolicy-::result(constresult-T,U,V-&)"></a>

<pre><code class="language-cpp">template &lt;class T, class U, class V&gt;
constexpr result(const <a href='doc_result.md#outcome::result-R,S,NoValuePolicy-'>result&lt;T, U, V&gt;</a>&amp; o) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;status_error_type, U&gt;::value);</code></pre>

Converting copy constructor from a compatible result type.

*Effects*: Initialises the result with a copy of the compatible result.

*Requires*: Both result's `value_type`, `error_type` and `status_type` need to be constructible, or the source `void`.

*Throws*: Any exception the construction of `value_type(T)` and `status_error_type(U)` might throw.

**Parameters:**

  - <a id="outcome::result-R,S,NoValuePolicy-::result(constresult-T,U,V-&).o"></a>`o` - The compatible result.

### Function template `outcome::result::result`<a id="outcome::result-R,S,NoValuePolicy-::result(result-T,U,V-&&)"></a>

<pre><code class="language-cpp">template &lt;class T, class U, class V&gt;
constexpr result(<a href='doc_result.md#outcome::result-R,S,NoValuePolicy-'>result&lt;T, U, V&gt;</a>&amp;&amp; o) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;status_error_type, U&gt;::value);</code></pre>

Converting move constructor from a compatible result type.

*Effects*: Initialises the result with a move of the compatible result.

*Requires*: Both result's `value_type`, `error_type` and `status_type` need to be constructible, or the source `void`.

*Throws*: Any exception the construction of `value_type(T)` and `status_error_type(U)` might throw.

**Parameters:**

  - <a id="outcome::result-R,S,NoValuePolicy-::result(result-T,U,V-&&).o"></a>`o` - The compatible result.

### Function template `outcome::result::result`<a id="outcome::result-R,S,NoValuePolicy-::result(in_place_type_t-value_type-,Args&&...)"></a>

<pre><code class="language-cpp">template &lt;class ... Args&gt;
constexpr result(<a href='doc_result.md#outcome::in_place_type_t-T-'>in_place_type_t&lt;value_type&gt;</a> _, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;value_type, Args...&gt;::value);</code></pre>

Inplace constructor to a successful result.

*Effects*: Initialises the result with a `value_type`.

*Requires*: `value_type` is void or `Args...` are constructible to `value_type`.

*Throws*: Any exception the construction of `value_type(Args...)` might throw.

**Parameters:**

  - <a id="outcome::result-R,S,NoValuePolicy-::result(in_place_type_t-value_type-,Args&&...)._"></a>Tag type to indicate we are doing in place construction of  `value_type`.

  - <a id="outcome::result-R,S,NoValuePolicy-::result(in_place_type_t-value_type-,Args&&...).args"></a>`args` - Arguments with which to in place construct.

### Function template `outcome::result::result`<a id="outcome::result-R,S,NoValuePolicy-::result(in_place_type_t-value_type-,std::initializer_list-U-,Args&&...)"></a>

<pre><code class="language-cpp">template &lt;class U, class ... Args&gt;
constexpr result(<a href='doc_result.md#outcome::in_place_type_t-T-'>in_place_type_t&lt;value_type&gt;</a> _, <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::initializer_list%3cU%3e'>std::initializer_list&lt;U&gt;</a> il, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;value_type, std::initializer_list&lt;U&gt;, Args...&gt;::value);</code></pre>

Inplace constructor to a successful result.

*Effects*: Initialises the result with a `value_type`.

*Requires*: The initializer list + `Args...` are constructible to `value_type`.

*Throws*: Any exception the construction of `value_type(il, Args...)` might throw.

**Parameters:**

  - <a id="outcome::result-R,S,NoValuePolicy-::result(in_place_type_t-value_type-,std::initializer_list-U-,Args&&...)._"></a>Tag type to indicate we are doing in place construction of  `value_type`.

  - <a id="outcome::result-R,S,NoValuePolicy-::result(in_place_type_t-value_type-,std::initializer_list-U-,Args&&...)"></a>`il` - An initializer list with which to in place construct.

  - <a id="outcome::result-R,S,NoValuePolicy-::result(in_place_type_t-value_type-,std::initializer_list-U-,Args&&...).args"></a>`args` - Arguments with which to in place construct.

### Function template `outcome::result::result`<a id="outcome::result-R,S,NoValuePolicy-::result(in_place_type_t-error_type-,Args&&...)"></a>

<pre><code class="language-cpp">template &lt;class ... Args&gt;
constexpr result(<a href='doc_result.md#outcome::in_place_type_t-T-'>in_place_type_t&lt;error_type&gt;</a> _, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;error_type, Args...&gt;::value);</code></pre>

Inplace constructor to a failure result.

*Effects*: Initialises the result with a `error_type`.

*Requires*: `trait::status_type_is_negative<EC>` must be true; `error_type` is void or `Args...` are constructible to `error_type`.

*Throws*: Any exception the construction of `error_type(Args...)` might throw.

**Parameters:**

  - <a id="outcome::result-R,S,NoValuePolicy-::result(in_place_type_t-error_type-,Args&&...)._"></a>Tag type to indicate we are doing in place construction of  `error_type`.

  - <a id="outcome::result-R,S,NoValuePolicy-::result(in_place_type_t-error_type-,Args&&...).args"></a>`args` - Arguments with which to in place construct.

### Function template `outcome::result::result`<a id="outcome::result-R,S,NoValuePolicy-::result(in_place_type_t-error_type-,std::initializer_list-U-,Args&&...)"></a>

<pre><code class="language-cpp">template &lt;class U, class ... Args&gt;
constexpr result(<a href='doc_result.md#outcome::in_place_type_t-T-'>in_place_type_t&lt;error_type&gt;</a> _, <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::initializer_list%3cU%3e'>std::initializer_list&lt;U&gt;</a> il, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;error_type, std::initializer_list&lt;U&gt;, Args...&gt;::value);</code></pre>

Inplace constructor to a failure result.

*Effects*: Initialises the result with a `error_type`.

*Requires*: `trait::status_type_is_negative<EC>` must be true; The initializer list + `Args...` are constructible to `error_type`.

*Throws*: Any exception the construction of `error_type(il, Args...)` might throw.

**Parameters:**

  - <a id="outcome::result-R,S,NoValuePolicy-::result(in_place_type_t-error_type-,std::initializer_list-U-,Args&&...)._"></a>Tag type to indicate we are doing in place construction of  `error_type`.

  - <a id="outcome::result-R,S,NoValuePolicy-::result(in_place_type_t-error_type-,std::initializer_list-U-,Args&&...)"></a>`il` - An initializer list with which to in place construct.

  - <a id="outcome::result-R,S,NoValuePolicy-::result(in_place_type_t-error_type-,std::initializer_list-U-,Args&&...).args"></a>`args` - Arguments with which to in place construct.

-----

## Class template `outcome::result<void, void, NoValuePolicy>`<a id="outcome::result-void,void,NoValuePolicy-"></a>

<pre><code class="language-cpp">template &lt;class NoValuePolicy&gt;
class result&lt;void, void, NoValuePolicy&gt;
{
public:
    //=== <a href='doc_result.md#outcome::result-void,void,NoValuePolicy-::value_type'>Member types</a> ===//
    using <a href='doc_result.md#outcome::result-void,void,NoValuePolicy-::value_type'>value_type</a> = void;
    
    using <a href='doc_result.md#outcome::result-void,void,NoValuePolicy-::status_error_type'>status_error_type</a> = void;
    
    using <a href='doc_result.md#outcome::result-void,void,NoValuePolicy-::error_type'>error_type</a> = void;
    
    constexpr void <a href='doc_result.md#outcome::result-void,void,NoValuePolicy-::assume_value()const'>assume_value</a>() const noexcept;
    
    constexpr void <a href='doc_result.md#outcome::result-void,void,NoValuePolicy-::assume_error()const'>assume_error</a>() const noexcept;
    
    constexpr void <a href='doc_result.md#outcome::result-void,void,NoValuePolicy-::value()const'>value</a>() const;
    
    constexpr void <a href='doc_result.md#outcome::result-void,void,NoValuePolicy-::error()const'>error</a>() const;
    
    constexpr <a href='doc_result.md#outcome::result-void,void,NoValuePolicy-::operatorbool()const'>operator bool</a>() const noexcept;
    
    constexpr bool <a href='doc_result.md#outcome::result-void,void,NoValuePolicy-::has_value()const'>has_value</a>() const noexcept;
    
    constexpr bool <a href='doc_result.md#outcome::result-void,void,NoValuePolicy-::has_error()const'>has_error</a>() const noexcept;
};</code></pre>

`result<void, void>` specialisation.

### Type alias `outcome::result<void, void, NoValuePolicy>::value_type`<a id="outcome::result-void,void,NoValuePolicy-::value_type"></a>

<pre><code class="language-cpp">using value_type = void;</code></pre>

The success type.

### Type alias `outcome::result<void, void, NoValuePolicy>::status_error_type`<a id="outcome::result-void,void,NoValuePolicy-::status_error_type"></a>

<pre><code class="language-cpp">using status_error_type = void;</code></pre>

The S type configured

### Type alias `outcome::result<void, void, NoValuePolicy>::error_type`<a id="outcome::result-void,void,NoValuePolicy-::error_type"></a>

<pre><code class="language-cpp">using error_type = void;</code></pre>

The failure type.

### Function `outcome::result<void, void, NoValuePolicy>::assume_value`<a id="outcome::result-void,void,NoValuePolicy-::assume_value()const"></a>

<pre><code class="language-cpp">constexpr void assume_value() const noexcept;</code></pre>

Does nothing

*Returns*: Nothing.

### Function `outcome::result<void, void, NoValuePolicy>::assume_error`<a id="outcome::result-void,void,NoValuePolicy-::assume_error()const"></a>

<pre><code class="language-cpp">constexpr void assume_error() const noexcept;</code></pre>

Does nothing

*Returns*: Nothing.

### Function `outcome::result<void, void, NoValuePolicy>::value`<a id="outcome::result-void,void,NoValuePolicy-::value()const"></a>

<pre><code class="language-cpp">constexpr void value() const;</code></pre>

Does nothing.

*Returns*: Nothing.

### Function `outcome::result<void, void, NoValuePolicy>::error`<a id="outcome::result-void,void,NoValuePolicy-::error()const"></a>

<pre><code class="language-cpp">constexpr void error() const;</code></pre>

Does nothing.

*Returns*: Nothing.

### Conversion operator `outcome::result<void, void, NoValuePolicy>::operator bool`<a id="outcome::result-void,void,NoValuePolicy-::operatorbool()const"></a>

<pre><code class="language-cpp">constexpr operator bool() const noexcept;</code></pre>

Checks if has value.

*Returns*: False.

### Function `outcome::result<void, void, NoValuePolicy>::has_value`<a id="outcome::result-void,void,NoValuePolicy-::has_value()const"></a>

<pre><code class="language-cpp">constexpr bool has_value() const noexcept;</code></pre>

Checks if has value.

*Returns*: False.

### Function `outcome::result<void, void, NoValuePolicy>::has_error`<a id="outcome::result-void,void,NoValuePolicy-::has_error()const"></a>

<pre><code class="language-cpp">constexpr bool has_error() const noexcept;</code></pre>

Checks if has error.

*Returns*: False.

-----

-----
