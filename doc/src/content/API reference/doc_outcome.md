+++
title = "outcome<R, S, P>"
slug = "doc_outcome.md"
+++
# Header file `outcome.hpp`<a id="outcome.hpp"></a>

<pre><code class="language-cpp">#define <a href='doc_outcome.md#outcome.hpp'>OUTCOME_OUTCOME_HPP</a>

namespace <a href='doc_result.md#result.hpp'>outcome</a>
{
    class <a href='doc_outcome.md#outcome::bad_outcome_access'>bad_outcome_access</a>;
    
    namespace <a href='doc_outcome.md#outcome::trait'>trait</a>
    {
        template &lt;class P&gt;
        struct <a href='doc_outcome.md#outcome::trait::is_exception_ptr-P-'>is_exception_ptr</a>;
    }
    
    struct <a href='doc_outcome.md#outcome::no_payload_type'>no_payload_type</a>;
    
    struct <a href='doc_outcome.md#outcome::no_exception_type'>no_exception_type</a>;
    
    namespace <a href='doc_result.md#result.hpp'>impl</a>
    {
        template &lt;class Base, class R, class S, class P, class NoValuePolicy&gt;
        class <a href='doc_outcome.md#outcome::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>outcome_payload_observers</a>;
        
        template &lt;class Base, class R, class S, class NoValuePolicy&gt;
        class <a href='doc_outcome.md#outcome.hpp'>outcome_payload_observers&lt;Base, R, S, void, NoValuePolicy&gt;</a>;
        
        template &lt;class Base, class R, class S, class P, class NoValuePolicy&gt;
        class <a href='doc_outcome.md#outcome::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>outcome_exception_observers</a>;
        
        template &lt;class Base, class R, class S, class NoValuePolicy&gt;
        class <a href='doc_outcome.md#outcome.hpp'>outcome_exception_observers&lt;Base, R, S, void, NoValuePolicy&gt;</a>;
    }
    
    namespace <a href='doc_result.md#outcome::policy'>policy</a>
    {
        template &lt;class R, class S, class P&gt;
        using <a href='doc_outcome.md#outcome::policy::default_outcome_policy-R,S,P-'>default_outcome_policy</a> = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::conditional_t%3c//detail::is_same_or_constructible%3cstd::error_code,S%3e&&trait::is_exception_ptr%3cP%3e::value,error_code_throw_as_system_error_exception_rethrow%3cR,S,P%3e,//terminate//%3e'>std::conditional_t&lt;//detail::is_same_or_constructible&lt;std::error_code, S&gt;&amp;&amp;trait::is_exception_ptr&lt;P&gt;::value, error_code_throw_as_system_error_exception_rethrow&lt;R, S, P&gt;, //terminate//&gt;</a>;
    }
    
    template &lt;class R, class S = error_code_extended, class P = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::exception_ptr'>std::exception_ptr</a>, class NoValuePolicy = policy::default_outcome_policy&lt;R, S, P&gt;&gt;
    class <a href='doc_outcome.md#outcome::outcome-R,S,P,NoValuePolicy-'>outcome</a>;
    
    namespace <a href='doc_result.md#outcome::policy'>policy</a>
    {
        template &lt;class R, class S, class P&gt;
        struct <a href='doc_outcome.md#outcome::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-'>error_code_throw_as_system_error_exception_rethrow</a>;
    }
    
    namespace <a href='doc_result.md#result.hpp'>impl</a>
    {
    }
}</code></pre>

## Class `outcome::bad_outcome_access`<a id="outcome::bad_outcome_access"></a>

<pre><code class="language-cpp">class bad_outcome_access
: public <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::logic_error'>std::logic_error</a>
{
public:
    <a href='doc_outcome.md#outcome::bad_outcome_access'>bad_outcome_access</a>(const char* what);
};</code></pre>

Thrown when you try to access state in a `outcome<T, EC, E>` which isn't present.

## Namespace `outcome::trait`<a id="outcome::trait"></a>

<pre><code class="language-cpp">namespace trait
{
    template &lt;class P&gt;
    struct <a href='doc_outcome.md#outcome::trait::is_exception_ptr-P-'>is_exception_ptr</a>;
}</code></pre>

Namespace for traits

### Class template `outcome::trait::is_exception_ptr` \[Error code interpretation policy\]<a id="outcome::trait::is_exception_ptr-P-"></a>

<pre><code class="language-cpp">template &lt;class P&gt;
struct is_exception_ptr
: <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::integral_constant%3c_Bool,std::is_constructible%3cstd::exception_ptr,P%3e::value%3e'>std::integral_constant&lt;_Bool, std::is_constructible&lt;std::exception_ptr, P&gt;::value&gt;</a>
{
};</code></pre>

Trait for whether type `P` is to be considered a payload to an exception.

-----

## Struct `outcome::no_payload_type`<a id="outcome::no_payload_type"></a>

<pre><code class="language-cpp">struct no_payload_type
{
    <a href='doc_outcome.md#outcome::no_payload_type'>no_payload_type</a>() = delete;
};</code></pre>

Placeholder type to indicate there is no payload type

## Struct `outcome::no_exception_type`<a id="outcome::no_exception_type"></a>

<pre><code class="language-cpp">struct no_exception_type
{
    <a href='doc_outcome.md#outcome::no_exception_type'>no_exception_type</a>() = delete;
};</code></pre>

Placeholder type to indicate there is no exception type

## Class template `outcome::impl::outcome_payload_observers`<a id="outcome::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-"></a>

<pre><code class="language-cpp">template &lt;class Base, class R, class S, class P, class NoValuePolicy&gt;
class outcome_payload_observers
: public Base
{
public:
    using <a href='doc_outcome.md#outcome::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a> = P;
    
    using Base::Base;
    
    constexpr <a href='doc_outcome.md#outcome::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a>&amp; <a href='doc_outcome.md#outcome::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-::assume_payload()&'>assume_payload</a>() &amp; noexcept;
    constexpr const <a href='doc_outcome.md#outcome::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a>&amp; <a href='doc_outcome.md#outcome::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-::assume_payload()&'>assume_payload</a>() const &amp; noexcept;
    constexpr <a href='doc_outcome.md#outcome::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a>&amp;&amp; <a href='doc_outcome.md#outcome::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-::assume_payload()&'>assume_payload</a>() &amp;&amp; noexcept;
    constexpr const <a href='doc_outcome.md#outcome::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a>&amp;&amp; <a href='doc_outcome.md#outcome::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-::assume_payload()&'>assume_payload</a>() const &amp;&amp; noexcept;
    
    constexpr <a href='doc_outcome.md#outcome::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a>&amp; <a href='doc_outcome.md#outcome::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-::payload()&'>payload</a>() &amp;;
    constexpr const <a href='doc_outcome.md#outcome::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a>&amp; <a href='doc_outcome.md#outcome::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-::payload()&'>payload</a>() const &amp;;
    constexpr <a href='doc_outcome.md#outcome::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a>&amp;&amp; <a href='doc_outcome.md#outcome::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-::payload()&'>payload</a>() &amp;&amp;;
    constexpr const <a href='doc_outcome.md#outcome::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a>&amp;&amp; <a href='doc_outcome.md#outcome::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-::payload()&'>payload</a>() const &amp;&amp;;
};</code></pre>

The payload observers implementation of `outcome<R, S, P>`. Only appears separate due to standardese limitations.

### Function `outcome::impl::outcome_payload_observers::assume_payload`<a id="outcome::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-::assume_payload()&"></a>

<pre><code class="language-cpp">(1)  constexpr <a href='doc_outcome.md#outcome::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a>&amp; assume_payload() &amp; noexcept;

(2)  constexpr const <a href='doc_outcome.md#outcome::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a>&amp; assume_payload() const &amp; noexcept;

(3)  constexpr <a href='doc_outcome.md#outcome::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a>&amp;&amp; assume_payload() &amp;&amp; noexcept;

(4)  constexpr const <a href='doc_outcome.md#outcome::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a>&amp;&amp; assume_payload() const &amp;&amp; noexcept;</code></pre>

Access payload without runtime checks.

*Returns*: Reference to the held `payload_type` according to overload.

### Function `outcome::impl::outcome_payload_observers::payload`<a id="outcome::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-::payload()&"></a>

<pre><code class="language-cpp">(1)  constexpr <a href='doc_outcome.md#outcome::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a>&amp; payload() &amp;;

(2)  constexpr const <a href='doc_outcome.md#outcome::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a>&amp; payload() const &amp;;

(3)  constexpr <a href='doc_outcome.md#outcome::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a>&amp;&amp; payload() &amp;&amp;;

(4)  constexpr const <a href='doc_outcome.md#outcome::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a>&amp;&amp; payload() const &amp;&amp;;</code></pre>

Access payload with runtime checks.

*Returns*: Reference to the held `payload_type` according to overload.

*Requires*: The outcome to have an payload state, else whatever `NoValuePolicy` says ought to happen.

-----

## Class template `outcome::impl::outcome_exception_observers`<a id="outcome::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-"></a>

<pre><code class="language-cpp">template &lt;class Base, class R, class S, class P, class NoValuePolicy&gt;
class outcome_exception_observers
: public Base
{
public:
    using <a href='doc_outcome.md#outcome::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a> = P;
    
    using Base::Base;
    
    constexpr <a href='doc_outcome.md#outcome::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a>&amp; <a href='doc_outcome.md#outcome::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-::assume_exception()&'>assume_exception</a>() &amp; noexcept;
    constexpr const <a href='doc_outcome.md#outcome::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a>&amp; <a href='doc_outcome.md#outcome::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-::assume_exception()&'>assume_exception</a>() const &amp; noexcept;
    constexpr <a href='doc_outcome.md#outcome::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a>&amp;&amp; <a href='doc_outcome.md#outcome::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-::assume_exception()&'>assume_exception</a>() &amp;&amp; noexcept;
    constexpr const <a href='doc_outcome.md#outcome::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a>&amp;&amp; <a href='doc_outcome.md#outcome::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-::assume_exception()&'>assume_exception</a>() const &amp;&amp; noexcept;
    
    constexpr <a href='doc_outcome.md#outcome::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a>&amp; <a href='doc_outcome.md#outcome::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-::exception()&'>exception</a>() &amp;;
    constexpr const <a href='doc_outcome.md#outcome::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a>&amp; <a href='doc_outcome.md#outcome::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-::exception()&'>exception</a>() const &amp;;
    constexpr <a href='doc_outcome.md#outcome::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a>&amp;&amp; <a href='doc_outcome.md#outcome::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-::exception()&'>exception</a>() &amp;&amp;;
    constexpr const <a href='doc_outcome.md#outcome::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a>&amp;&amp; <a href='doc_outcome.md#outcome::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-::exception()&'>exception</a>() const &amp;&amp;;
};</code></pre>

The exception observers implementation of `outcome<R, S, P>`. Only appears separate due to standardese limitations.

### Function `outcome::impl::outcome_exception_observers::assume_exception`<a id="outcome::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-::assume_exception()&"></a>

<pre><code class="language-cpp">(1)  constexpr <a href='doc_outcome.md#outcome::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a>&amp; assume_exception() &amp; noexcept;

(2)  constexpr const <a href='doc_outcome.md#outcome::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a>&amp; assume_exception() const &amp; noexcept;

(3)  constexpr <a href='doc_outcome.md#outcome::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a>&amp;&amp; assume_exception() &amp;&amp; noexcept;

(4)  constexpr const <a href='doc_outcome.md#outcome::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a>&amp;&amp; assume_exception() const &amp;&amp; noexcept;</code></pre>

Access exception without runtime checks.

*Returns*: Reference to the held `exception_type` according to overload.

### Function `outcome::impl::outcome_exception_observers::exception`<a id="outcome::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-::exception()&"></a>

<pre><code class="language-cpp">(1)  constexpr <a href='doc_outcome.md#outcome::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a>&amp; exception() &amp;;

(2)  constexpr const <a href='doc_outcome.md#outcome::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a>&amp; exception() const &amp;;

(3)  constexpr <a href='doc_outcome.md#outcome::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a>&amp;&amp; exception() &amp;&amp;;

(4)  constexpr const <a href='doc_outcome.md#outcome::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a>&amp;&amp; exception() const &amp;&amp;;</code></pre>

Access exception with runtime checks.

*Returns*: Reference to the held `exception_type` according to overload.

*Requires*: The outcome to have an exception state, else whatever `NoValuePolicy` says ought to happen.

-----

-----

## Alias template `outcome::policy::default_outcome_policy` \[Error code interpretation policy\]<a id="outcome::policy::default_outcome_policy-R,S,P-"></a>

<pre><code class="language-cpp">template &lt;class R, class S, class P&gt;
using default_outcome_policy = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::conditional_t%3c//detail::is_same_or_constructible%3cstd::error_code,S%3e&&trait::is_exception_ptr%3cP%3e::value,error_code_throw_as_system_error_exception_rethrow%3cR,S,P%3e,//terminate//%3e'>std::conditional_t&lt;//detail::is_same_or_constructible&lt;std::error_code, S&gt;&amp;&amp;trait::is_exception_ptr&lt;P&gt;::value, error_code_throw_as_system_error_exception_rethrow&lt;R, S, P&gt;, //terminate//&gt;</a>;</code></pre>

Default `outcome<R, S, P>` policy selector.

-----

## Class template `outcome::outcome` \[outcome\<R, S, P\> implementation\]<a id="outcome::outcome-R,S,P,NoValuePolicy-"></a>

<pre><code class="language-cpp">template &lt;class R, class S = error_code_extended, class P = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::exception_ptr'>std::exception_ptr</a>, class NoValuePolicy = policy::default_outcome_policy&lt;R, S, P&gt;&gt;
class outcome
: public 'hidden'
{
public:
    //=== <a href='doc_outcome.md#outcome::outcome-R,S,P,NoValuePolicy-::value_type'>Member types</a> ===//
    using <a href='doc_outcome.md#outcome::outcome-R,S,P,NoValuePolicy-::value_type'>value_type</a> = typename base::value_type;
    
    using <a href='doc_outcome.md#outcome::outcome-R,S,P,NoValuePolicy-::status_error_type'>status_error_type</a> = typename base::status_error_type;
    
    using <a href='doc_outcome.md#outcome::outcome-R,S,P,NoValuePolicy-::error_type'>error_type</a> = typename base::error_type;
    
    using <a href='doc_outcome.md#outcome::outcome-R,S,P,NoValuePolicy-::payload_exception_type'>payload_exception_type</a> = P;
    
    using <a href='doc_outcome.md#outcome::outcome-R,S,P,NoValuePolicy-::payload_type'>payload_type</a> = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::conditional_t%3c!trait::is_exception_ptr%3cP%3e::value,no_payload_type,P%3e'>std::conditional_t&lt;!trait::is_exception_ptr&lt;P&gt;::value, no_payload_type, P&gt;</a>;
    
    using <a href='doc_outcome.md#outcome::outcome-R,S,P,NoValuePolicy-::exception_type'>exception_type</a> = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::conditional_t%3ctrait::is_exception_ptr%3cP%3e::value,no_exception_type,P%3e'>std::conditional_t&lt;trait::is_exception_ptr&lt;P&gt;::value, no_exception_type, P&gt;</a>;
    
protected:
    'hidden' <a href='doc_outcome.md#outcome::outcome-R,S,P,NoValuePolicy-'>_ptr</a>;
    
public:
    template &lt;class T&gt;
    constexpr <a href='doc_outcome.md#outcome::outcome-R,S,P,NoValuePolicy-::outcome(T&&,outcome::outcome::value_converting_constructor_tag)'>outcome</a>(T&amp;&amp; t) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value);
    
    template &lt;class T, class U&gt;
    constexpr <a href='doc_outcome.md#outcome::outcome-R,S,P,NoValuePolicy-::outcome(T&&,U&&,outcome::outcome::value_payload_converting_constructor_tag)'>outcome</a>(T&amp;&amp; t, U&amp;&amp; u) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;payload_exception_type, U&gt;::value);
    
    template &lt;class T&gt;
    constexpr <a href='doc_outcome.md#outcome::outcome-R,S,P,NoValuePolicy-::outcome(T&&,outcome::outcome::error_converting_constructor_tag)'>outcome</a>(T&amp;&amp; t) noexcept(std::is_nothrow_constructible&lt;error_type, T&gt;::value);
    
    template &lt;class T, class U&gt;
    constexpr <a href='doc_outcome.md#outcome::outcome-R,S,P,NoValuePolicy-::outcome(T&&,U&&,outcome::outcome::error_payload_converting_constructor_tag)'>outcome</a>(T&amp;&amp; t, U&amp;&amp; u) noexcept(std::is_nothrow_constructible&lt;error_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;payload_exception_type, U&gt;::value);
    
    template &lt;class T, class U, class V, class W&gt;
    constexpr <a href='doc_outcome.md#outcome::outcome-R,S,P,NoValuePolicy-::outcome(constoutcome-T,U,V,W-&)'>outcome</a>(const <a href='doc_outcome.md#outcome::outcome-R,S,P,NoValuePolicy-'>outcome&lt;T, U, V, W&gt;</a>&amp; o) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;status_error_type, U&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;payload_exception_type, V&gt;::value);
    
    template &lt;class T, class U, class V, class W&gt;
    constexpr <a href='doc_outcome.md#outcome::outcome-R,S,P,NoValuePolicy-::outcome(outcome-T,U,V,W-&&)'>outcome</a>(<a href='doc_outcome.md#outcome::outcome-R,S,P,NoValuePolicy-'>outcome&lt;T, U, V, W&gt;</a>&amp;&amp; o) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;status_error_type, U&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;payload_exception_type, V&gt;::value);
    
    template &lt;class T, class U, class V&gt;
    constexpr <a href='doc_outcome.md#outcome::outcome-R,S,P,NoValuePolicy-::outcome(constresult-T,U,V-&)'>outcome</a>(const <a href='doc_result.md#outcome::result-R,S,NoValuePolicy-'>result&lt;T, U, V&gt;</a>&amp; o) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;status_error_type, U&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;payload_exception_type&gt;::value);
    
    template &lt;class T, class U, class V&gt;
    constexpr <a href='doc_outcome.md#outcome::outcome-R,S,P,NoValuePolicy-::outcome(result-T,U,V-&&)'>outcome</a>(<a href='doc_result.md#outcome::result-R,S,NoValuePolicy-'>result&lt;T, U, V&gt;</a>&amp;&amp; o) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;status_error_type, U&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;payload_exception_type&gt;::value);
    
    template &lt;class ... Args&gt;
    constexpr <a href='doc_outcome.md#outcome::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-value_type-,Args&&...)'>outcome</a>(<a href='doc_result.md#outcome::in_place_type_t-T-'>in_place_type_t&lt;value_type&gt;</a> _, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;value_type, Args...&gt;::value);
    
    template &lt;class U, class ... Args&gt;
    constexpr <a href='doc_outcome.md#outcome::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-value_type-,std::initializer_list-U-,Args&&...)'>outcome</a>(<a href='doc_result.md#outcome::in_place_type_t-T-'>in_place_type_t&lt;value_type&gt;</a> _, <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::initializer_list%3cU%3e'>std::initializer_list&lt;U&gt;</a> il, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;value_type, std::initializer_list&lt;U&gt;, Args...&gt;::value);
    
    template &lt;class ... Args&gt;
    constexpr <a href='doc_outcome.md#outcome::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-error_type-,Args&&...)'>outcome</a>(<a href='doc_result.md#outcome::in_place_type_t-T-'>in_place_type_t&lt;error_type&gt;</a> _, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;error_type, Args...&gt;::value);
    
    template &lt;class U, class ... Args&gt;
    constexpr <a href='doc_outcome.md#outcome::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-error_type-,std::initializer_list-U-,Args&&...)'>outcome</a>(<a href='doc_result.md#outcome::in_place_type_t-T-'>in_place_type_t&lt;error_type&gt;</a> _, <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::initializer_list%3cU%3e'>std::initializer_list&lt;U&gt;</a> il, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;error_type, std::initializer_list&lt;U&gt;, Args...&gt;::value);
    
    template &lt;class ... Args&gt;
    constexpr <a href='doc_outcome.md#outcome::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-payload_exception_type-,Args&&...)'>outcome</a>(<a href='doc_result.md#outcome::in_place_type_t-T-'>in_place_type_t&lt;payload_exception_type&gt;</a> _, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;payload_exception_type, Args...&gt;::value);
    
    template &lt;class U, class ... Args&gt;
    constexpr <a href='doc_outcome.md#outcome::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-payload_exception_type-,std::initializer_list-U-,Args&&...)'>outcome</a>(<a href='doc_result.md#outcome::in_place_type_t-T-'>in_place_type_t&lt;payload_exception_type&gt;</a> _, <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::initializer_list%3cU%3e'>std::initializer_list&lt;U&gt;</a> il, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;payload_exception_type, std::initializer_list&lt;U&gt;, Args...&gt;::value);
};</code></pre>

Used to return from functions (i) a value and (a positive status and/or a payload) or (ii) no value and (a negative status and/or a payload). `constexpr` capable.

**Parameters:**

  - <a id="outcome::outcome-R,S,P,NoValuePolicy-.R"></a>`R` - The optional type of the successful result (use  `void` to disable).

  - <a id="outcome::outcome-R,S,P,NoValuePolicy-.S"></a>`S` - The optional type of the status result (use  `void` to disable). Must be either `void` or DefaultConstructible.

  - <a id="outcome::outcome-R,S,P,NoValuePolicy-.P"></a>`P` - The optional type of the payload/exception result (use  `void` to disable). Must be either `void` or DefaultConstructible.

  - <a id="outcome::outcome-R,S,P,NoValuePolicy-.NoValuePolicy"></a>`NoValuePolicy` - Policy on how to interpret types  `S` and `P` when a wide observation of a not present value occurs.

### Type alias `outcome::outcome::value_type`<a id="outcome::outcome-R,S,P,NoValuePolicy-::value_type"></a>

<pre><code class="language-cpp">using value_type = typename base::value_type;</code></pre>

The success type.

### Type alias `outcome::outcome::status_error_type`<a id="outcome::outcome-R,S,P,NoValuePolicy-::status_error_type"></a>

<pre><code class="language-cpp">using status_error_type = typename base::status_error_type;</code></pre>

The S type configured

### Type alias `outcome::outcome::error_type`<a id="outcome::outcome-R,S,P,NoValuePolicy-::error_type"></a>

<pre><code class="language-cpp">using error_type = typename base::error_type;</code></pre>

The failure type, always `no_error_type` if `trait::status_type_is_negative<S>` is false.

### Type alias `outcome::outcome::payload_exception_type`<a id="outcome::outcome-R,S,P,NoValuePolicy-::payload_exception_type"></a>

<pre><code class="language-cpp">using payload_exception_type = P;</code></pre>

The P type configured.

### Type alias `outcome::outcome::payload_type`<a id="outcome::outcome-R,S,P,NoValuePolicy-::payload_type"></a>

<pre><code class="language-cpp">using payload_type = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::conditional_t%3c!trait::is_exception_ptr%3cP%3e::value,no_payload_type,P%3e'>std::conditional_t&lt;!trait::is_exception_ptr&lt;P&gt;::value, no_payload_type, P&gt;</a>;</code></pre>

The payload type, always `no_payload_type` if `trait::is_exception_ptr<P>` is true.

### Type alias `outcome::outcome::exception_type`<a id="outcome::outcome-R,S,P,NoValuePolicy-::exception_type"></a>

<pre><code class="language-cpp">using exception_type = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::conditional_t%3ctrait::is_exception_ptr%3cP%3e::value,no_exception_type,P%3e'>std::conditional_t&lt;trait::is_exception_ptr&lt;P&gt;::value, no_exception_type, P&gt;</a>;</code></pre>

The exception type, always `no_exception_type` if `trait::is_exception_ptr<P>` is false.

### Function template `outcome::outcome::outcome`<a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(T&&,outcome::outcome::value_converting_constructor_tag)"></a>

<pre><code class="language-cpp">template &lt;class T&gt;
constexpr outcome(T&amp;&amp; t) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value);</code></pre>

Converting constructor to a successful outcome.

*Effects*: Initialises the outcome with a `value_type`.

*Requires*: Type T is constructible to `value_type`, is not constructible to `status_error_type`, is not constructible to `payload_exception_type` and is not `outcome<R, S, P>` and not `in_place_type<>`.

*Throws*: Any exception the construction of `value_type(T)` might throw.

**Parameters:**

  - <a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(T&&,outcome::outcome::value_converting_constructor_tag).t"></a>`t` - The value from which to initialise the  `value_type`.

### Function template `outcome::outcome::outcome`<a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(T&&,U&&,outcome::outcome::value_payload_converting_constructor_tag)"></a>

<pre><code class="language-cpp">template &lt;class T, class U&gt;
constexpr outcome(T&amp;&amp; t, U&amp;&amp; u) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;payload_exception_type, U&gt;::value);</code></pre>

Converting constructor to a successful outcome + payload.

*Effects*: Initialises the outcome with a `value_type` and a `payload_type`.

*Requires*: `trait::is_exception_ptr<P>` must be false; Type `T` is constructible to `value_type`, is not constructible to `status_error_type`, is not constructible to `payload_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`; Type `U` is constructible to `payload_type`, is not constructible to `value_type`, and is not constructible to `status_error_type`.

*Throws*: Any exception the construction of `value_type(T)` and `payload_type(U)` might throw.

**Parameters:**

  - <a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(T&&,U&&,outcome::outcome::value_payload_converting_constructor_tag).t"></a>`t` - The value from which to initialise the  `value_type`.

  - <a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(T&&,U&&,outcome::outcome::value_payload_converting_constructor_tag).u"></a>`u` - The value from which to initialise the  `payload_type`.

### Function template `outcome::outcome::outcome`<a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(T&&,outcome::outcome::error_converting_constructor_tag)"></a>

<pre><code class="language-cpp">template &lt;class T&gt;
constexpr outcome(T&amp;&amp; t) noexcept(std::is_nothrow_constructible&lt;error_type, T&gt;::value);</code></pre>

Converting constructor to an errored outcome.

*Effects*: Initialises the outcome with a `error_type`.

*Requires*: `trait::status_type_is_negative<EC>` must be true; Type T is constructible to `error_type`, is not constructible to `value_type`, is not constructible to `payload_exception_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`.

*Throws*: Any exception the construction of `error_type(T)` might throw.

**Parameters:**

  - <a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(T&&,outcome::outcome::error_converting_constructor_tag).t"></a>`t` - The value from which to initialise the  `error_type`.

### Function template `outcome::outcome::outcome`<a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(T&&,U&&,outcome::outcome::error_payload_converting_constructor_tag)"></a>

<pre><code class="language-cpp">template &lt;class T, class U&gt;
constexpr outcome(T&amp;&amp; t, U&amp;&amp; u) noexcept(std::is_nothrow_constructible&lt;error_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;payload_exception_type, U&gt;::value);</code></pre>

Converting constructor to an errored outcome + payload/exception.

*Effects*: Initialises the outcome with a `error_type` and a `payload_exception_type`.

*Requires*: `trait::status_type_is_negative<EC>` must be true; Type T is constructible to `error_type`, is not constructible to `value_type`, is not constructible to `payload_exception_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`; Type `U` is constructible to `payload_exception_type`, is not constructible to `value_type`, and is not constructible to `error_type`.

*Throws*: Any exception the construction of `error_type(T)` and `payload_exception_type(U)` might throw.

**Parameters:**

  - <a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(T&&,U&&,outcome::outcome::error_payload_converting_constructor_tag).t"></a>`t` - The value from which to initialise the  `error_type`.

  - <a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(T&&,U&&,outcome::outcome::error_payload_converting_constructor_tag).u"></a>`u` - The value from which to initialise the  `payload_exception_type`.

### Function template `outcome::outcome::outcome`<a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(constoutcome-T,U,V,W-&)"></a>

<pre><code class="language-cpp">template &lt;class T, class U, class V, class W&gt;
constexpr outcome(const <a href='doc_outcome.md#outcome::outcome-R,S,P,NoValuePolicy-'>outcome&lt;T, U, V, W&gt;</a>&amp; o) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;status_error_type, U&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;payload_exception_type, V&gt;::value);</code></pre>

Converting copy constructor from a compatible outcome type.

*Effects*: Initialises the outcome with a copy of the compatible outcome.

*Requires*: Both outcome's `value_type`, `error_type`, `status_type`, `payload_type` and `exception_type` need to be constructible, or the source `void`.

*Throws*: Any exception the construction of `value_type(T)`, `status_error_type(U)` or `payload_exception_type(V)` might throw.

**Parameters:**

  - <a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(constoutcome-T,U,V,W-&).o"></a>`o` - The compatible outcome.

### Function template `outcome::outcome::outcome`<a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(outcome-T,U,V,W-&&)"></a>

<pre><code class="language-cpp">template &lt;class T, class U, class V, class W&gt;
constexpr outcome(<a href='doc_outcome.md#outcome::outcome-R,S,P,NoValuePolicy-'>outcome&lt;T, U, V, W&gt;</a>&amp;&amp; o) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;status_error_type, U&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;payload_exception_type, V&gt;::value);</code></pre>

Converting move constructor from a compatible outcome type.

*Effects*: Initialises the outcome with a move of the compatible outcome.

*Requires*: Both outcome's `value_type`, `error_type`, `status_type`, `payload_type` and `exception_type` need to be constructible, or the source `void`.

*Throws*: Any exception the construction of `value_type(T)`, `status_error_type(U)` or `payload_exception_type(V)` might throw.

**Parameters:**

  - <a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(outcome-T,U,V,W-&&).o"></a>`o` - The compatible outcome.

### Function template `outcome::outcome::outcome`<a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(constresult-T,U,V-&)"></a>

<pre><code class="language-cpp">template &lt;class T, class U, class V&gt;
constexpr outcome(const <a href='doc_result.md#outcome::result-R,S,NoValuePolicy-'>result&lt;T, U, V&gt;</a>&amp; o) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;status_error_type, U&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;payload_exception_type&gt;::value);</code></pre>

Converting copy constructor from a compatible result type.

*Effects*: Initialises the outcome with a copy of the compatible result.

*Requires*: Both outcome's `value_type`, `error_type` and `status_type` need to be constructible, or the source `void`.

*Throws*: Any exception the construction of `value_type(T)`, `status_error_type(U)` or `payload_exception_type()` might throw.

**Parameters:**

  - <a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(constresult-T,U,V-&).o"></a>`o` - The compatible result.

### Function template `outcome::outcome::outcome`<a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(result-T,U,V-&&)"></a>

<pre><code class="language-cpp">template &lt;class T, class U, class V&gt;
constexpr outcome(<a href='doc_result.md#outcome::result-R,S,NoValuePolicy-'>result&lt;T, U, V&gt;</a>&amp;&amp; o) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;status_error_type, U&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;payload_exception_type&gt;::value);</code></pre>

Converting move constructor from a compatible result type.

*Effects*: Initialises the outcome with a move of the compatible result.

*Requires*: Both outcome's `value_type`, `error_type` and `status_type` need to be constructible, or the source `void`.

*Throws*: Any exception the construction of `value_type(T)`, `status_error_type(U)` or `payload_exception_type()` might throw.

**Parameters:**

  - <a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(result-T,U,V-&&).o"></a>`o` - The compatible result.

### Function template `outcome::outcome::outcome`<a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-value_type-,Args&&...)"></a>

<pre><code class="language-cpp">template &lt;class ... Args&gt;
constexpr outcome(<a href='doc_result.md#outcome::in_place_type_t-T-'>in_place_type_t&lt;value_type&gt;</a> _, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;value_type, Args...&gt;::value);</code></pre>

Inplace constructor to a successful value.

*Effects*: Initialises the outcome with a `value_type`.

*Requires*: `value_type` is void or `Args...` are constructible to `value_type`.

*Throws*: Any exception the construction of `value_type(Args...)` might throw.

**Parameters:**

  - <a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-value_type-,Args&&...)._"></a>Tag type to indicate we are doing in place construction of  `value_type`.

  - <a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-value_type-,Args&&...).args"></a>`args` - Arguments with which to in place construct.

### Function template `outcome::outcome::outcome`<a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-value_type-,std::initializer_list-U-,Args&&...)"></a>

<pre><code class="language-cpp">template &lt;class U, class ... Args&gt;
constexpr outcome(<a href='doc_result.md#outcome::in_place_type_t-T-'>in_place_type_t&lt;value_type&gt;</a> _, <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::initializer_list%3cU%3e'>std::initializer_list&lt;U&gt;</a> il, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;value_type, std::initializer_list&lt;U&gt;, Args...&gt;::value);</code></pre>

Inplace constructor to a successful value.

*Effects*: Initialises the outcome with a `value_type`.

*Requires*: The initializer list + `Args...` are constructible to `value_type`.

*Throws*: Any exception the construction of `value_type(il, Args...)` might throw.

**Parameters:**

  - <a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-value_type-,std::initializer_list-U-,Args&&...)._"></a>Tag type to indicate we are doing in place construction of  `value_type`.

  - <a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-value_type-,std::initializer_list-U-,Args&&...)"></a>`il` - An initializer list with which to in place construct.

  - <a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-value_type-,std::initializer_list-U-,Args&&...).args"></a>`args` - Arguments with which to in place construct.

### Function template `outcome::outcome::outcome`<a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-error_type-,Args&&...)"></a>

<pre><code class="language-cpp">template &lt;class ... Args&gt;
constexpr outcome(<a href='doc_result.md#outcome::in_place_type_t-T-'>in_place_type_t&lt;error_type&gt;</a> _, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;error_type, Args...&gt;::value);</code></pre>

Inplace constructor to an unsuccessful error.

*Effects*: Initialises the outcome with a `error_type`.

*Requires*: `trait::status_type_is_negative<EC>` must be true; `error_type` is void or `Args...` are constructible to `error_type`.

*Throws*: Any exception the construction of `error_type(Args...)` might throw.

**Parameters:**

  - <a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-error_type-,Args&&...)._"></a>Tag type to indicate we are doing in place construction of  `error_type`.

  - <a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-error_type-,Args&&...).args"></a>`args` - Arguments with which to in place construct.

### Function template `outcome::outcome::outcome`<a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-error_type-,std::initializer_list-U-,Args&&...)"></a>

<pre><code class="language-cpp">template &lt;class U, class ... Args&gt;
constexpr outcome(<a href='doc_result.md#outcome::in_place_type_t-T-'>in_place_type_t&lt;error_type&gt;</a> _, <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::initializer_list%3cU%3e'>std::initializer_list&lt;U&gt;</a> il, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;error_type, std::initializer_list&lt;U&gt;, Args...&gt;::value);</code></pre>

Inplace constructor to an unsuccessful error.

*Effects*: Initialises the outcome with a `error_type`.

*Requires*: `trait::status_type_is_negative<EC>` must be true; The initializer list + `Args...` are constructible to `error_type`.

*Throws*: Any exception the construction of `error_type(il, Args...)` might throw.

**Parameters:**

  - <a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-error_type-,std::initializer_list-U-,Args&&...)._"></a>Tag type to indicate we are doing in place construction of  `error_type`.

  - <a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-error_type-,std::initializer_list-U-,Args&&...)"></a>`il` - An initializer list with which to in place construct.

  - <a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-error_type-,std::initializer_list-U-,Args&&...).args"></a>`args` - Arguments with which to in place construct.

### Function template `outcome::outcome::outcome`<a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-payload_exception_type-,Args&&...)"></a>

<pre><code class="language-cpp">template &lt;class ... Args&gt;
constexpr outcome(<a href='doc_result.md#outcome::in_place_type_t-T-'>in_place_type_t&lt;payload_exception_type&gt;</a> _, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;payload_exception_type, Args...&gt;::value);</code></pre>

Inplace constructor to an unsuccessful payload/exception.

*Effects*: Initialises the outcome with a `payload_exception_type`.

*Requires*: `payload_exception_type` is void or `Args...` are constructible to `payload_exception_type`.

*Throws*: Any exception the construction of `payload_exception_type(Args...)` might throw.

**Parameters:**

  - <a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-payload_exception_type-,Args&&...)._"></a>Tag type to indicate we are doing in place construction of  `payload_exception_type`.

  - <a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-payload_exception_type-,Args&&...).args"></a>`args` - Arguments with which to in place construct.

### Function template `outcome::outcome::outcome`<a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-payload_exception_type-,std::initializer_list-U-,Args&&...)"></a>

<pre><code class="language-cpp">template &lt;class U, class ... Args&gt;
constexpr outcome(<a href='doc_result.md#outcome::in_place_type_t-T-'>in_place_type_t&lt;payload_exception_type&gt;</a> _, <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::initializer_list%3cU%3e'>std::initializer_list&lt;U&gt;</a> il, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;payload_exception_type, std::initializer_list&lt;U&gt;, Args...&gt;::value);</code></pre>

Inplace constructor to an unsuccessful payload/exception.

*Effects*: Initialises the outcome with a `payload_exception_type`.

*Requires*: The initializer list + `Args...` are constructible to `payload_exception_type`.

*Throws*: Any exception the construction of `payload_exception_type(il, Args...)` might throw.

**Parameters:**

  - <a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-payload_exception_type-,std::initializer_list-U-,Args&&...)._"></a>Tag type to indicate we are doing in place construction of  `payload_exception_type`.

  - <a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-payload_exception_type-,std::initializer_list-U-,Args&&...)"></a>`il` - An initializer list with which to in place construct.

  - <a id="outcome::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-payload_exception_type-,std::initializer_list-U-,Args&&...).args"></a>`args` - Arguments with which to in place construct.

-----

## Class template `outcome::policy::error_code_throw_as_system_error_exception_rethrow` \[Error code interpretation policy\]<a id="outcome::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-"></a>

<pre><code class="language-cpp">template &lt;class R, class S, class P&gt;
struct error_code_throw_as_system_error_exception_rethrow
{
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_outcome.md#outcome::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-::narrow_value_check(Impl*)'>narrow_value_check</a>(Impl* self) noexcept;
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_outcome.md#outcome::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-::narrow_error_check(Impl*)'>narrow_error_check</a>(Impl* self) noexcept;
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_outcome.md#outcome::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-::narrow_payload_check(Impl*)'>narrow_payload_check</a>(Impl* self) noexcept;
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_outcome.md#outcome::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-::narrow_exception_check(Impl*)'>narrow_exception_check</a>(Impl* self) noexcept;
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_outcome.md#outcome::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-::wide_value_check(Impl*)'>wide_value_check</a>(Impl* self);
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_outcome.md#outcome::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-::wide_error_check(Impl*)'>wide_error_check</a>(Impl* self);
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_outcome.md#outcome::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-::wide_payload_check(Impl*)'>wide_payload_check</a>(Impl* self);
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_outcome.md#outcome::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-::wide_exception_check(Impl*)'>wide_exception_check</a>(Impl* self);
};</code></pre>

Policy interpreting S as a type implementing the `std::error_code` contract, E as a type implementing the `std::exception_ptr` contract, and any wide attempt to access the successful state throws the `exception_ptr` if available, then the `error_code` wrapped into a `std::system_error`.

### Function template `outcome::policy::error_code_throw_as_system_error_exception_rethrow::narrow_value_check`<a id="outcome::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-::narrow_value_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void narrow_value_check(Impl* self) noexcept;</code></pre>

Performs a narrow check of state, used in the assume\_value() functions.

*Effects*: None.

### Function template `outcome::policy::error_code_throw_as_system_error_exception_rethrow::narrow_error_check`<a id="outcome::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-::narrow_error_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void narrow_error_check(Impl* self) noexcept;</code></pre>

Performs a narrow check of state, used in the assume\_error() functions.

*Effects*: None.

### Function template `outcome::policy::error_code_throw_as_system_error_exception_rethrow::narrow_payload_check`<a id="outcome::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-::narrow_payload_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void narrow_payload_check(Impl* self) noexcept;</code></pre>

Performs a narrow check of state, used in the assume\_payload() functions.

*Effects*: None.

### Function template `outcome::policy::error_code_throw_as_system_error_exception_rethrow::narrow_exception_check`<a id="outcome::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-::narrow_exception_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void narrow_exception_check(Impl* self) noexcept;</code></pre>

Performs a narrow check of state, used in the assume\_exception() functions.

*Effects*: None.

### Function template `outcome::policy::error_code_throw_as_system_error_exception_rethrow::wide_value_check`<a id="outcome::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-::wide_value_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void wide_value_check(Impl* self);</code></pre>

Performs a wide check of state, used in the value() functions.

*Effects*: If outcome does not have a value, if it has an exception it rethrows it via `std::rethrow_exception()`, if has an error it throws a `std::system_error(error())`, else it throws `bad_outcome_access`.

### Function template `outcome::policy::error_code_throw_as_system_error_exception_rethrow::wide_error_check`<a id="outcome::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-::wide_error_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void wide_error_check(Impl* self);</code></pre>

Performs a wide check of state, used in the error() functions

*Effects*: If outcome does not have an error, it throws `bad_outcome_access`.

### Function template `outcome::policy::error_code_throw_as_system_error_exception_rethrow::wide_payload_check`<a id="outcome::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-::wide_payload_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void wide_payload_check(Impl* self);</code></pre>

Performs a wide check of state, used in the payload() functions

*Effects*: If outcome does not have a payload, it throws `bad_outcome_access`.

### Function template `outcome::policy::error_code_throw_as_system_error_exception_rethrow::wide_exception_check`<a id="outcome::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-::wide_exception_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void wide_exception_check(Impl* self);</code></pre>

Performs a wide check of state, used in the exception() functions

*Effects*: If outcome does not have an exception, it throws `bad_outcome_access`.

-----

-----

-----
