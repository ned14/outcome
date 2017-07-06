+++
title = "outcome<R, S, P>"
slug = "doc_outcome.md"
+++
# Header file `outcome.hpp`<a id="outcome.hpp"></a>

<pre><code class="language-cpp">#define <a href='doc_outcome.md#outcome.hpp'>OUTCOME_OUTCOME_HPP</a>

namespace <a href='doc_try.md#try.hpp'>outcome_v2_6f6309a5</a>
{
    class <a href='doc_outcome.md#outcome_v2_6f6309a5::bad_outcome_access'>bad_outcome_access</a>;
    
    namespace <a href='doc_outcome.md#outcome_v2_6f6309a5::trait'>trait</a>
    {
        template &lt;class P&gt;
        struct <a href='doc_outcome.md#outcome_v2_6f6309a5::trait::is_exception_ptr-P-'>is_exception_ptr</a>;
    }
    
    struct <a href='doc_outcome.md#outcome_v2_6f6309a5::no_payload_type'>no_payload_type</a>;
    
    struct <a href='doc_outcome.md#outcome_v2_6f6309a5::no_exception_type'>no_exception_type</a>;
    
    namespace <a href='doc_result.md#result.hpp'>impl</a>
    {
        template &lt;class Base, class R, class S, class P, class NoValuePolicy&gt;
        class <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>outcome_payload_observers</a>;
        
        template &lt;class Base, class R, class S, class NoValuePolicy&gt;
        class <a href='doc_outcome.md#outcome.hpp'>outcome_payload_observers&lt;Base, R, S, void, NoValuePolicy&gt;</a>;
        
        template &lt;class Base, class R, class S, class P, class NoValuePolicy&gt;
        class <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>outcome_exception_observers</a>;
        
        template &lt;class Base, class R, class S, class NoValuePolicy&gt;
        class <a href='doc_outcome.md#outcome.hpp'>outcome_exception_observers&lt;Base, R, S, void, NoValuePolicy&gt;</a>;
        
        template &lt;class Base, class R, class S, class P, class NoValuePolicy&gt;
        class <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_failure_observers-Base,R,S,P,NoValuePolicy-'>outcome_failure_observers</a>;
        
        template &lt;class Base, class R, class NoValuePolicy&gt;
        class <a href='doc_outcome.md#outcome.hpp'>outcome_failure_observers&lt;Base, R, std::error_code, std::exception_ptr, NoValuePolicy&gt;</a>;
    }
    
    namespace <a href='doc_result.md#outcome_v2_6f6309a5::policy'>policy</a>
    {
        template &lt;class R, class S, class P&gt;
        using <a href='doc_outcome.md#outcome_v2_6f6309a5::policy::default_outcome_policy-R,S,P-'>default_outcome_policy</a> = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::conditional_t%3c//detail::is_same_or_constructible%3cstd::error_code,S%3e&&trait::is_exception_ptr%3cP%3e::value,error_code_throw_as_system_error_exception_rethrow%3cR,S,P%3e,//terminate//%3e'>std::conditional_t&lt;//detail::is_same_or_constructible&lt;std::error_code, S&gt;&amp;&amp;trait::is_exception_ptr&lt;P&gt;::value, error_code_throw_as_system_error_exception_rethrow&lt;R, S, P&gt;, //terminate//&gt;</a>;
    }
    
    template &lt;class T, class U&gt;
    constexpr void <a href='doc_outcome.md#outcome_v2_6f6309a5::hook_outcome_construction(in_place_type_t-T-,U*)'>hook_outcome_construction</a>(in_place_type_t&lt;T&gt;, U*) noexcept;
    
    template &lt;class T, class U&gt;
    constexpr void <a href='doc_outcome.md#outcome_v2_6f6309a5::hook_outcome_copy_construction(in_place_type_t-T-,U*)'>hook_outcome_copy_construction</a>(in_place_type_t&lt;T&gt;, U*) noexcept;
    
    template &lt;class T, class U&gt;
    constexpr void <a href='doc_outcome.md#outcome_v2_6f6309a5::hook_outcome_move_construction(in_place_type_t-T-,U*)'>hook_outcome_move_construction</a>(in_place_type_t&lt;T&gt;, U*) noexcept;
    
    template &lt;class T, class U&gt;
    constexpr void <a href='doc_outcome.md#outcome_v2_6f6309a5::hook_outcome_in_place_construction(in_place_type_t-T-,U*)'>hook_outcome_in_place_construction</a>(in_place_type_t&lt;T&gt;, U*) noexcept;
    
    template &lt;class R, class S = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::error_code'>std::error_code</a>, class P = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::exception_ptr'>std::exception_ptr</a>, class NoValuePolicy = policy::default_outcome_policy&lt;R, S, P&gt;&gt;
    class <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-'>outcome</a>;
    
    template &lt;class T, class U, class V, class R, class S, class P, class N&gt;
    constexpr )//&gt;bool <a href='doc_outcome.md#outcome_v2_6f6309a5::operator==(constresult-T,U,V-&,constoutcome-R,S,P,N-&)'>operator==</a>(const <a href='doc_result.md#outcome_v2_6f6309a5::result-R,S,NoValuePolicy-'>result&lt;T, U, V&gt;</a>&amp; a, const <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-'>outcome&lt;R, S, P, N&gt;</a>&amp; b) noexcept(//noexcept(std::declval&lt;outcome&lt;R, S, P, N&gt;&gt;()==std::declval&lt;result&lt;T, U, V&gt;&gt;()));
    
    template &lt;class T, class U, class V, class R, class S, class P, class N&gt;
    constexpr )//&gt;bool <a href='doc_outcome.md#outcome_v2_6f6309a5::operator!=(constresult-T,U,V-&,constoutcome-R,S,P,N-&)'>operator!=</a>(const <a href='doc_result.md#outcome_v2_6f6309a5::result-R,S,NoValuePolicy-'>result&lt;T, U, V&gt;</a>&amp; a, const <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-'>outcome&lt;R, S, P, N&gt;</a>&amp; b) noexcept(//noexcept(std::declval&lt;outcome&lt;R, S, P, N&gt;&gt;()!=std::declval&lt;result&lt;T, U, V&gt;&gt;()));
    
    namespace <a href='doc_result.md#outcome_v2_6f6309a5::policy'>policy</a>
    {
        template &lt;class R, class S, class P&gt;
        struct <a href='doc_outcome.md#outcome_v2_6f6309a5::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-'>error_code_throw_as_system_error_exception_rethrow</a>;
    }
    
    namespace <a href='doc_result.md#result.hpp'>impl</a>
    {
    }
}</code></pre>

## Class `outcome_v2_6f6309a5::bad_outcome_access`<a id="outcome_v2_6f6309a5::bad_outcome_access"></a>

<pre><code class="language-cpp">class bad_outcome_access
: public <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::logic_error'>std::logic_error</a>
{
public:
    <a href='doc_outcome.md#outcome_v2_6f6309a5::bad_outcome_access'>bad_outcome_access</a>(const char* what);
};</code></pre>

Thrown when you try to access state in a `outcome<T, EC, E>` which isn't present.

## Namespace `outcome_v2_6f6309a5::trait`<a id="outcome_v2_6f6309a5::trait"></a>

<pre><code class="language-cpp">namespace trait
{
    template &lt;class P&gt;
    struct <a href='doc_outcome.md#outcome_v2_6f6309a5::trait::is_exception_ptr-P-'>is_exception_ptr</a>;
}</code></pre>

Namespace for traits

### Class template `outcome_v2_6f6309a5::trait::is_exception_ptr` \[Error code interpretation policy\]<a id="outcome_v2_6f6309a5::trait::is_exception_ptr-P-"></a>

<pre><code class="language-cpp">template &lt;class P&gt;
struct is_exception_ptr
: <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::integral_constant%3c_Bool,std::is_constructible%3cstd::exception_ptr,P%3e::value%3e'>std::integral_constant&lt;_Bool, std::is_constructible&lt;std::exception_ptr, P&gt;::value&gt;</a>
{
};</code></pre>

Trait for whether type `P` is to be considered a payload to an exception.

-----

## Struct `outcome_v2_6f6309a5::no_payload_type`<a id="outcome_v2_6f6309a5::no_payload_type"></a>

<pre><code class="language-cpp">struct no_payload_type
{
    <a href='doc_outcome.md#outcome_v2_6f6309a5::no_payload_type'>no_payload_type</a>() = delete;
};</code></pre>

Placeholder type to indicate there is no payload type

## Struct `outcome_v2_6f6309a5::no_exception_type`<a id="outcome_v2_6f6309a5::no_exception_type"></a>

<pre><code class="language-cpp">struct no_exception_type
{
    <a href='doc_outcome.md#outcome_v2_6f6309a5::no_exception_type'>no_exception_type</a>() = delete;
};</code></pre>

Placeholder type to indicate there is no exception type

## Class template `outcome_v2_6f6309a5::impl::outcome_payload_observers`<a id="outcome_v2_6f6309a5::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-"></a>

<pre><code class="language-cpp">template &lt;class Base, class R, class S, class P, class NoValuePolicy&gt;
class outcome_payload_observers
: public Base
{
public:
    using <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a> = P;
    
    using Base::Base;
    
    constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a>&amp; <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-::assume_payload()&'>assume_payload</a>() &amp; noexcept;
    constexpr const <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a>&amp; <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-::assume_payload()&'>assume_payload</a>() const &amp; noexcept;
    constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a>&amp;&amp; <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-::assume_payload()&'>assume_payload</a>() &amp;&amp; noexcept;
    constexpr const <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a>&amp;&amp; <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-::assume_payload()&'>assume_payload</a>() const &amp;&amp; noexcept;
    
    constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a>&amp; <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-::payload()&'>payload</a>() &amp;;
    constexpr const <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a>&amp; <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-::payload()&'>payload</a>() const &amp;;
    constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a>&amp;&amp; <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-::payload()&'>payload</a>() &amp;&amp;;
    constexpr const <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a>&amp;&amp; <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-::payload()&'>payload</a>() const &amp;&amp;;
};</code></pre>

The payload observers implementation of `outcome<R, S, P>`. Only appears separate due to standardese limitations.

### Function `outcome_v2_6f6309a5::impl::outcome_payload_observers::assume_payload`<a id="outcome_v2_6f6309a5::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-::assume_payload()&"></a>

<pre><code class="language-cpp">(1)  constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a>&amp; assume_payload() &amp; noexcept;

(2)  constexpr const <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a>&amp; assume_payload() const &amp; noexcept;

(3)  constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a>&amp;&amp; assume_payload() &amp;&amp; noexcept;

(4)  constexpr const <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a>&amp;&amp; assume_payload() const &amp;&amp; noexcept;</code></pre>

Access payload without runtime checks.

*Returns*: Reference to the held `payload_type` according to overload.

### Function `outcome_v2_6f6309a5::impl::outcome_payload_observers::payload`<a id="outcome_v2_6f6309a5::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-::payload()&"></a>

<pre><code class="language-cpp">(1)  constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a>&amp; payload() &amp;;

(2)  constexpr const <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a>&amp; payload() const &amp;;

(3)  constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a>&amp;&amp; payload() &amp;&amp;;

(4)  constexpr const <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy-'>payload_type</a>&amp;&amp; payload() const &amp;&amp;;</code></pre>

Access payload with runtime checks.

*Returns*: Reference to the held `payload_type` according to overload.

*Requires*: The outcome to have an payload state, else whatever `NoValuePolicy` says ought to happen.

-----

## Class template `outcome_v2_6f6309a5::impl::outcome_exception_observers`<a id="outcome_v2_6f6309a5::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-"></a>

<pre><code class="language-cpp">template &lt;class Base, class R, class S, class P, class NoValuePolicy&gt;
class outcome_exception_observers
: public Base
{
public:
    using <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a> = P;
    
    using Base::Base;
    
    constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a>&amp; <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-::assume_exception()&'>assume_exception</a>() &amp; noexcept;
    constexpr const <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a>&amp; <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-::assume_exception()&'>assume_exception</a>() const &amp; noexcept;
    constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a>&amp;&amp; <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-::assume_exception()&'>assume_exception</a>() &amp;&amp; noexcept;
    constexpr const <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a>&amp;&amp; <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-::assume_exception()&'>assume_exception</a>() const &amp;&amp; noexcept;
    
    constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a>&amp; <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-::exception()&'>exception</a>() &amp;;
    constexpr const <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a>&amp; <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-::exception()&'>exception</a>() const &amp;;
    constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a>&amp;&amp; <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-::exception()&'>exception</a>() &amp;&amp;;
    constexpr const <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a>&amp;&amp; <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-::exception()&'>exception</a>() const &amp;&amp;;
};</code></pre>

The exception observers implementation of `outcome<R, S, P>`. Only appears separate due to standardese limitations.

### Function `outcome_v2_6f6309a5::impl::outcome_exception_observers::assume_exception`<a id="outcome_v2_6f6309a5::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-::assume_exception()&"></a>

<pre><code class="language-cpp">(1)  constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a>&amp; assume_exception() &amp; noexcept;

(2)  constexpr const <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a>&amp; assume_exception() const &amp; noexcept;

(3)  constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a>&amp;&amp; assume_exception() &amp;&amp; noexcept;

(4)  constexpr const <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a>&amp;&amp; assume_exception() const &amp;&amp; noexcept;</code></pre>

Access exception without runtime checks.

*Returns*: Reference to the held `exception_type` according to overload.

### Function `outcome_v2_6f6309a5::impl::outcome_exception_observers::exception`<a id="outcome_v2_6f6309a5::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-::exception()&"></a>

<pre><code class="language-cpp">(1)  constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a>&amp; exception() &amp;;

(2)  constexpr const <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a>&amp; exception() const &amp;;

(3)  constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a>&amp;&amp; exception() &amp;&amp;;

(4)  constexpr const <a href='doc_outcome.md#outcome_v2_6f6309a5::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy-'>exception_type</a>&amp;&amp; exception() const &amp;&amp;;</code></pre>

Access exception with runtime checks.

*Returns*: Reference to the held `exception_type` according to overload.

*Requires*: The outcome to have an exception state, else whatever `NoValuePolicy` says ought to happen.

-----

## Class template `outcome_v2_6f6309a5::impl::outcome_failure_observers`<a id="outcome_v2_6f6309a5::impl::outcome_failure_observers-Base,R,S,P,NoValuePolicy-"></a>

<pre><code class="language-cpp">template &lt;class Base, class R, class S, class P, class NoValuePolicy&gt;
class outcome_failure_observers
: public Base
{
public:
    using Base::Base;
};</code></pre>

The failure observers implementation of `outcome<R, S, P>`. Only appears separate due to standardese limitations.

-----

## Alias template `outcome_v2_6f6309a5::policy::default_outcome_policy` \[Error code interpretation policy\]<a id="outcome_v2_6f6309a5::policy::default_outcome_policy-R,S,P-"></a>

<pre><code class="language-cpp">template &lt;class R, class S, class P&gt;
using default_outcome_policy = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::conditional_t%3c//detail::is_same_or_constructible%3cstd::error_code,S%3e&&trait::is_exception_ptr%3cP%3e::value,error_code_throw_as_system_error_exception_rethrow%3cR,S,P%3e,//terminate//%3e'>std::conditional_t&lt;//detail::is_same_or_constructible&lt;std::error_code, S&gt;&amp;&amp;trait::is_exception_ptr&lt;P&gt;::value, error_code_throw_as_system_error_exception_rethrow&lt;R, S, P&gt;, //terminate//&gt;</a>;</code></pre>

Default `outcome<R, S, P>` policy selector.

-----

## Function template `outcome_v2_6f6309a5::hook_outcome_construction`<a id="outcome_v2_6f6309a5::hook_outcome_construction(in_place_type_t-T-,U*)"></a>

<pre><code class="language-cpp">template &lt;class T, class U&gt;
constexpr void hook_outcome_construction(in_place_type_t&lt;T&gt;, U*) noexcept;</code></pre>

The default instantiation hook implementation called when a `outcome` is first created by conversion from one of its possible types. Does nothing.

WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should\!

**Parameters:**

  - <a id="outcome_v2_6f6309a5::hook_outcome_construction(in_place_type_t-T-,U*).T"></a>`T` - One of  `value_type`, `error_type`, `std::pair<error_type, payload_type>` or `exception_type`.

## Function template `outcome_v2_6f6309a5::hook_outcome_copy_construction`<a id="outcome_v2_6f6309a5::hook_outcome_copy_construction(in_place_type_t-T-,U*)"></a>

<pre><code class="language-cpp">template &lt;class T, class U&gt;
constexpr void hook_outcome_copy_construction(in_place_type_t&lt;T&gt;, U*) noexcept;</code></pre>

The default instantiation hook implementation called when a `outcome` is created by copying from another `outcome` or `result`. Does nothing.

WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should\!

**Parameters:**

  - <a id="outcome_v2_6f6309a5::hook_outcome_copy_construction(in_place_type_t-T-,U*).T"></a>`T` - The type of the source.

## Function template `outcome_v2_6f6309a5::hook_outcome_move_construction`<a id="outcome_v2_6f6309a5::hook_outcome_move_construction(in_place_type_t-T-,U*)"></a>

<pre><code class="language-cpp">template &lt;class T, class U&gt;
constexpr void hook_outcome_move_construction(in_place_type_t&lt;T&gt;, U*) noexcept;</code></pre>

The default instantiation hook implementation called when a `outcome` is created by moving from another `outcome` or `result`. Does nothing.

WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should\!

**Parameters:**

  - <a id="outcome_v2_6f6309a5::hook_outcome_move_construction(in_place_type_t-T-,U*).T"></a>`T` - The type of the source.

## Function template `outcome_v2_6f6309a5::hook_outcome_in_place_construction`<a id="outcome_v2_6f6309a5::hook_outcome_in_place_construction(in_place_type_t-T-,U*)"></a>

<pre><code class="language-cpp">template &lt;class T, class U&gt;
constexpr void hook_outcome_in_place_construction(in_place_type_t&lt;T&gt;, U*) noexcept;</code></pre>

The default instantiation hook implementation called when a `outcome` is created by in place construction. Does nothing.

WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should\!

**Parameters:**

  - <a id="outcome_v2_6f6309a5::hook_outcome_in_place_construction(in_place_type_t-T-,U*).T"></a>`T` - One of  `value_type`, `error_type`, `std::pair<error_type, payload_type>` or `exception_type`.

## Class template `outcome_v2_6f6309a5::outcome` \[outcome\<R, S, P\> implementation\]<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-"></a>

<pre><code class="language-cpp">template &lt;class R, class S = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::error_code'>std::error_code</a>, class P = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::exception_ptr'>std::exception_ptr</a>, class NoValuePolicy = policy::default_outcome_policy&lt;R, S, P&gt;&gt;
class outcome
: public 'hidden'
{
public:
    //=== <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::value_type'>Member types</a> ===//
    using <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::value_type'>value_type</a> = R;
    
    using <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::status_error_type'>status_error_type</a> = S;
    
    using <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::error_type'>error_type</a> = S;
    
    using <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::payload_exception_type'>payload_exception_type</a> = P;
    
    using <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::payload_type'>payload_type</a> = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::conditional_t%3ctrait::is_exception_ptr%3cP%3e::value,no_payload_type,P%3e'>std::conditional_t&lt;trait::is_exception_ptr&lt;P&gt;::value, no_payload_type, P&gt;</a>;
    
    using <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::exception_type'>exception_type</a> = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::conditional_t%3c!trait::is_exception_ptr%3cP%3e::value,no_exception_type,P%3e'>std::conditional_t&lt;!trait::is_exception_ptr&lt;P&gt;::value, no_exception_type, P&gt;</a>;
    
    template &lt;class T, class U = S, class V = P&gt;
    using <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::rebind-T,U,V-'>rebind</a> = <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-'>outcome&lt;T, U, P&gt;</a>;
    
    using <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::value_type_if_enabled'>value_type_if_enabled</a> = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::conditional_t%3cstd::is_same%3cvalue_type,error_type%3e::value%7c%7cstd::is_same%3cvalue_type,payload_exception_type%3e::value,typenamebase::_value_type,value_type%3e'>std::conditional_t&lt;std::is_same&lt;value_type, error_type&gt;::value||std::is_same&lt;value_type, payload_exception_type&gt;::value, typename base::_value_type, value_type&gt;</a>;
    
    using <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::error_type_if_enabled'>error_type_if_enabled</a> = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::conditional_t%3cstd::is_same%3cerror_type,value_type%3e::value%7c%7cstd::is_same%3cerror_type,payload_exception_type%3e::value,typenamebase::_error_type,error_type%3e'>std::conditional_t&lt;std::is_same&lt;error_type, value_type&gt;::value||std::is_same&lt;error_type, payload_exception_type&gt;::value, typename base::_error_type, error_type&gt;</a>;
    
    using <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::payload_exception_type_if_enabled'>payload_exception_type_if_enabled</a> = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::conditional_t%3cstd::is_same%3cpayload_exception_type,value_type%3e::value%7c%7cstd::is_same%3cpayload_exception_type,error_type%3e::value,disable_in_place_payload_exception_type,payload_exception_type%3e'>std::conditional_t&lt;std::is_same&lt;payload_exception_type, value_type&gt;::value||std::is_same&lt;payload_exception_type, error_type&gt;::value, disable_in_place_payload_exception_type, payload_exception_type&gt;</a>;
    
protected:
    detail::devoid&lt;payload_exception_type&gt; <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-'>_ptr</a>;
    
public:
    template &lt;class T&gt;
    constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(T&&,outcome_v2_6f6309a5::outcome::value_converting_constructor_tag)'>outcome</a>(T&amp;&amp; t) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value);
    
    template &lt;class T&gt;
    constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(T&&,outcome_v2_6f6309a5::outcome::error_converting_constructor_tag)'>outcome</a>(T&amp;&amp; t) noexcept(std::is_nothrow_constructible&lt;error_type, T&gt;::value);
    
    template &lt;class T, class U&gt;
    constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(T&&,U&&,outcome_v2_6f6309a5::outcome::error_payload_converting_constructor_tag)'>outcome</a>(T&amp;&amp; t, U&amp;&amp; u) noexcept(std::is_nothrow_constructible&lt;error_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;payload_exception_type, U&gt;::value);
    
    template &lt;class T&gt;
    constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(T&&,outcome_v2_6f6309a5::outcome::exception_converting_constructor_tag)'>outcome</a>(T&amp;&amp; t) noexcept(std::is_nothrow_constructible&lt;exception_type, T&gt;::value);
    
    template &lt;class T, class U, class V, class W&gt;
    constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(constoutcome-T,U,V,W-&,outcome_v2_6f6309a5::outcome::explicit_compatible_conversion_tag)'>outcome</a>(const <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-'>outcome&lt;T, U, V, W&gt;</a>&amp; o, <a href='standardese://outcome_v2_6f6309a5::outcome<R, S, P, NoValuePolicy>::explicit_compatible_conversion_tag/'>explicit_compatible_conversion_tag</a> = explicit_compatible_conversion_tag()) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;status_error_type, U&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;payload_exception_type, V&gt;::value);
    
    template &lt;class T, class U, class V, class W&gt;
    constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(constoutcome-T,U,V,W-&,outcome_v2_6f6309a5::outcome::implicit_compatible_conversion_tag)'>outcome</a>(const <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-'>outcome&lt;T, U, V, W&gt;</a>&amp; o, <a href='standardese://outcome_v2_6f6309a5::outcome<R, S, P, NoValuePolicy>::implicit_compatible_conversion_tag/'>implicit_compatible_conversion_tag</a> = implicit_compatible_conversion_tag()) noexcept(std::is_nothrow_constructible&lt;payload_exception_type, V&gt;::value);
    
    template &lt;class T, class U, class V, class W&gt;
    constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(outcome-T,U,V,W-&&,outcome_v2_6f6309a5::outcome::explicit_compatible_conversion_tag)'>outcome</a>(<a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-'>outcome&lt;T, U, V, W&gt;</a>&amp;&amp; o, <a href='standardese://outcome_v2_6f6309a5::outcome<R, S, P, NoValuePolicy>::explicit_compatible_conversion_tag/'>explicit_compatible_conversion_tag</a> = explicit_compatible_conversion_tag()) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;status_error_type, U&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;payload_exception_type, V&gt;::value);
    
    template &lt;class T, class U, class V, class W&gt;
    constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(outcome-T,U,V,W-&&,outcome_v2_6f6309a5::outcome::implicit_compatible_conversion_tag)'>outcome</a>(<a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-'>outcome&lt;T, U, V, W&gt;</a>&amp;&amp; o, <a href='standardese://outcome_v2_6f6309a5::outcome<R, S, P, NoValuePolicy>::implicit_compatible_conversion_tag/'>implicit_compatible_conversion_tag</a> = implicit_compatible_conversion_tag()) noexcept(std::is_nothrow_constructible&lt;status_error_type, U&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;payload_exception_type, V&gt;::value);
    
    template &lt;class T, class U, class V&gt;
    constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(constresult-T,U,V-&,outcome_v2_6f6309a5::outcome::explicit_compatible_conversion_tag)'>outcome</a>(const <a href='doc_result.md#outcome_v2_6f6309a5::result-R,S,NoValuePolicy-'>result&lt;T, U, V&gt;</a>&amp; o, <a href='standardese://outcome_v2_6f6309a5::outcome<R, S, P, NoValuePolicy>::explicit_compatible_conversion_tag/'>explicit_compatible_conversion_tag</a> = explicit_compatible_conversion_tag()) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;status_error_type, U&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;payload_exception_type&gt;::value);
    
    template &lt;class T, class U, class V&gt;
    constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(constresult-T,U,V-&,outcome_v2_6f6309a5::outcome::implicit_compatible_conversion_tag)'>outcome</a>(const <a href='doc_result.md#outcome_v2_6f6309a5::result-R,S,NoValuePolicy-'>result&lt;T, U, V&gt;</a>&amp; o, <a href='standardese://outcome_v2_6f6309a5::outcome<R, S, P, NoValuePolicy>::implicit_compatible_conversion_tag/'>implicit_compatible_conversion_tag</a> = implicit_compatible_conversion_tag()) noexcept(std::is_nothrow_constructible&lt;status_error_type, U&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;payload_exception_type&gt;::value);
    
    template &lt;class T, class U, class V&gt;
    constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(result-T,U,V-&&,outcome_v2_6f6309a5::outcome::explicit_compatible_conversion_tag)'>outcome</a>(<a href='doc_result.md#outcome_v2_6f6309a5::result-R,S,NoValuePolicy-'>result&lt;T, U, V&gt;</a>&amp;&amp; o, <a href='standardese://outcome_v2_6f6309a5::outcome<R, S, P, NoValuePolicy>::explicit_compatible_conversion_tag/'>explicit_compatible_conversion_tag</a> = explicit_compatible_conversion_tag()) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;status_error_type, U&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;payload_exception_type&gt;::value);
    
    template &lt;class T, class U, class V&gt;
    constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(result-T,U,V-&&,outcome_v2_6f6309a5::outcome::implicit_compatible_conversion_tag)'>outcome</a>(<a href='doc_result.md#outcome_v2_6f6309a5::result-R,S,NoValuePolicy-'>result&lt;T, U, V&gt;</a>&amp;&amp; o, <a href='standardese://outcome_v2_6f6309a5::outcome<R, S, P, NoValuePolicy>::implicit_compatible_conversion_tag/'>implicit_compatible_conversion_tag</a> = implicit_compatible_conversion_tag()) noexcept(std::is_nothrow_constructible&lt;status_error_type, U&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;payload_exception_type&gt;::value);
    
    template &lt;class ... Args&gt;
    constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-value_type_if_enabled-,Args&&...)'>outcome</a>(in_place_type_t&lt;value_type_if_enabled&gt; _, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;value_type, Args...&gt;::value);
    
    template &lt;class U, class ... Args&gt;
    constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-value_type_if_enabled-,std::initializer_list-U-,Args&&...)'>outcome</a>(in_place_type_t&lt;value_type_if_enabled&gt; _, <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::initializer_list%3cU%3e'>std::initializer_list&lt;U&gt;</a> il, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;value_type, std::initializer_list&lt;U&gt;, Args...&gt;::value);
    
    template &lt;class ... Args&gt;
    constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-error_type_if_enabled-,Args&&...)'>outcome</a>(in_place_type_t&lt;error_type_if_enabled&gt; _, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;error_type, Args...&gt;::value);
    
    template &lt;class U, class ... Args&gt;
    constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-error_type_if_enabled-,std::initializer_list-U-,Args&&...)'>outcome</a>(in_place_type_t&lt;error_type_if_enabled&gt; _, <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::initializer_list%3cU%3e'>std::initializer_list&lt;U&gt;</a> il, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;error_type, std::initializer_list&lt;U&gt;, Args...&gt;::value);
    
    template &lt;class ... Args&gt;
    constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-payload_exception_type_if_enabled-,Args&&...)'>outcome</a>(in_place_type_t&lt;payload_exception_type_if_enabled&gt;, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;payload_exception_type, Args...&gt;::value);
    
    template &lt;class U, class ... Args&gt;
    constexpr <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-payload_exception_type_if_enabled-,std::initializer_list-U-,Args&&...)'>outcome</a>(in_place_type_t&lt;payload_exception_type_if_enabled&gt;, <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::initializer_list%3cU%3e'>std::initializer_list&lt;U&gt;</a> il, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;payload_exception_type, std::initializer_list&lt;U&gt;, Args...&gt;::value);
    
    template &lt;class T, class U, class V, class W&gt;
    constexpr )//&gt;bool <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::operator==(constoutcome-T,U,V,W-&)const'>operator==</a>(const <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-'>outcome&lt;T, U, V, W&gt;</a>&amp; o) const noexcept(//noexcept(std::declval&lt;R&gt;()==std::declval&lt;T&gt;())//&amp;&amp;noexcept(std::declval&lt;S&gt;()==std::declval&lt;U&gt;())//&amp;&amp;noexcept(std::declval&lt;P&gt;()==std::declval&lt;V&gt;()));
    
    template &lt;class T, class U, class V, class W&gt;
    constexpr )//&gt;bool <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::operator!=(constoutcome-T,U,V,W-&)const'>operator!=</a>(const <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-'>outcome&lt;T, U, V, W&gt;</a>&amp; o) const noexcept(//noexcept(std::declval&lt;R&gt;()!=std::declval&lt;T&gt;())//&amp;&amp;noexcept(std::declval&lt;S&gt;()!=std::declval&lt;U&gt;())//&amp;&amp;noexcept(std::declval&lt;P&gt;()!=std::declval&lt;V&gt;()));
    
    template &lt;class T, class U, class V, typename = decltype(std::declval&lt;R&gt;()==std::declval&lt;T&gt;()&gt;
    constexpr )//&gt;bool <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::operator==(constresult-T,U,V-&)const'>operator==</a>(const <a href='doc_result.md#outcome_v2_6f6309a5::result-R,S,NoValuePolicy-'>result&lt;T, U, V&gt;</a>&amp; o) const noexcept(//noexcept(std::declval&lt;R&gt;()==std::declval&lt;T&gt;())//&amp;&amp;noexcept(std::declval&lt;S&gt;()==std::declval&lt;U&gt;()));
    
    template &lt;class T, class U, class V, typename = decltype(std::declval&lt;R&gt;()!=std::declval&lt;T&gt;()&gt;
    constexpr )//&gt;bool <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::operator!=(constresult-T,U,V-&)const'>operator!=</a>(const <a href='doc_result.md#outcome_v2_6f6309a5::result-R,S,NoValuePolicy-'>result&lt;T, U, V&gt;</a>&amp; o) const noexcept(//noexcept(std::declval&lt;R&gt;()!=std::declval&lt;T&gt;())//&amp;&amp;noexcept(std::declval&lt;S&gt;()!=std::declval&lt;U&gt;()));
    
    <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::rebind-T,U,V-'>rebind&lt;void&gt;</a> <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::as_void()const&'>as_void</a>() const &amp;;
    
    <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::rebind-T,U,V-'>rebind&lt;void&gt;</a> <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::as_void()&&'>as_void</a>() &amp;&amp;;
};</code></pre>

Used to return from functions (i) a value and (a positive status and/or a payload) or (ii) no value and (a negative status and/or a payload). `constexpr` capable.

**Parameters:**

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-.R"></a>`R` - The optional type of the successful result (use  `void` to disable).

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-.S"></a>`S` - The optional type of the status result (use  `void` to disable). Must be either `void` or DefaultConstructible.

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-.P"></a>`P` - The optional type of the payload/exception result (use  `void` to disable). Must be either `void` or DefaultConstructible.

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-.NoValuePolicy"></a>`NoValuePolicy` - Policy on how to interpret types  `S` and `P` when a wide observation of a not present value occurs.

### Type alias `outcome_v2_6f6309a5::outcome::value_type`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::value_type"></a>

<pre><code class="language-cpp">using value_type = R;</code></pre>

The success type.

### Type alias `outcome_v2_6f6309a5::outcome::status_error_type`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::status_error_type"></a>

<pre><code class="language-cpp">using status_error_type = S;</code></pre>

The S type configured

### Type alias `outcome_v2_6f6309a5::outcome::error_type`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::error_type"></a>

<pre><code class="language-cpp">using error_type = S;</code></pre>

The failure type.

### Type alias `outcome_v2_6f6309a5::outcome::payload_exception_type`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::payload_exception_type"></a>

<pre><code class="language-cpp">using payload_exception_type = P;</code></pre>

The P type configured.

### Type alias `outcome_v2_6f6309a5::outcome::payload_type`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::payload_type"></a>

<pre><code class="language-cpp">using payload_type = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::conditional_t%3ctrait::is_exception_ptr%3cP%3e::value,no_payload_type,P%3e'>std::conditional_t&lt;trait::is_exception_ptr&lt;P&gt;::value, no_payload_type, P&gt;</a>;</code></pre>

The payload type, always `no_payload_type` if `trait::is_exception_ptr<P>` is true.

### Type alias `outcome_v2_6f6309a5::outcome::exception_type`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::exception_type"></a>

<pre><code class="language-cpp">using exception_type = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::conditional_t%3c!trait::is_exception_ptr%3cP%3e::value,no_exception_type,P%3e'>std::conditional_t&lt;!trait::is_exception_ptr&lt;P&gt;::value, no_exception_type, P&gt;</a>;</code></pre>

The exception type, always `no_exception_type` if `trait::is_exception_ptr<P>` is false.

### Alias template `outcome_v2_6f6309a5::outcome::rebind`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::rebind-T,U,V-"></a>

<pre><code class="language-cpp">template &lt;class T, class U = S, class V = P&gt;
using rebind = <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-'>outcome&lt;T, U, P&gt;</a>;</code></pre>

Used to rebind this outcome to a different outcome type

### Type alias `outcome_v2_6f6309a5::outcome::value_type_if_enabled`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::value_type_if_enabled"></a>

<pre><code class="language-cpp">using value_type_if_enabled = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::conditional_t%3cstd::is_same%3cvalue_type,error_type%3e::value%7c%7cstd::is_same%3cvalue_type,payload_exception_type%3e::value,typenamebase::_value_type,value_type%3e'>std::conditional_t&lt;std::is_same&lt;value_type, error_type&gt;::value||std::is_same&lt;value_type, payload_exception_type&gt;::value, typename base::_value_type, value_type&gt;</a>;</code></pre>

Used to disable in place type construction when `value_type` is ambiguous with `error_type` or `payload_exception_type`.

### Type alias `outcome_v2_6f6309a5::outcome::error_type_if_enabled`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::error_type_if_enabled"></a>

<pre><code class="language-cpp">using error_type_if_enabled = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::conditional_t%3cstd::is_same%3cerror_type,value_type%3e::value%7c%7cstd::is_same%3cerror_type,payload_exception_type%3e::value,typenamebase::_error_type,error_type%3e'>std::conditional_t&lt;std::is_same&lt;error_type, value_type&gt;::value||std::is_same&lt;error_type, payload_exception_type&gt;::value, typename base::_error_type, error_type&gt;</a>;</code></pre>

Used to disable in place type construction when `error_type` is ambiguous with `value_type` or `payload_exception_type`.

### Type alias `outcome_v2_6f6309a5::outcome::payload_exception_type_if_enabled`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::payload_exception_type_if_enabled"></a>

<pre><code class="language-cpp">using payload_exception_type_if_enabled = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::conditional_t%3cstd::is_same%3cpayload_exception_type,value_type%3e::value%7c%7cstd::is_same%3cpayload_exception_type,error_type%3e::value,disable_in_place_payload_exception_type,payload_exception_type%3e'>std::conditional_t&lt;std::is_same&lt;payload_exception_type, value_type&gt;::value||std::is_same&lt;payload_exception_type, error_type&gt;::value, disable_in_place_payload_exception_type, payload_exception_type&gt;</a>;</code></pre>

Used to disable in place type construction when `payload_exception_type` is ambiguous with `value_type` or `error_type`.

### Function template `outcome_v2_6f6309a5::outcome::outcome`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(T&&,outcome_v2_6f6309a5::outcome::value_converting_constructor_tag)"></a>

<pre><code class="language-cpp">template &lt;class T&gt;
constexpr outcome(T&amp;&amp; t) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value);</code></pre>

Converting constructor to a successful outcome.

*Effects*: Initialises the outcome with a `value_type`.

*Requires*: Type T is constructible to `value_type`, is not constructible to `status_error_type`, is not constructible to `exception_type` and is not `outcome<R, S, P>` and not `in_place_type<>`.

*Throws*: Any exception the construction of `value_type(T)` might throw.

**Parameters:**

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(T&&,outcome_v2_6f6309a5::outcome::value_converting_constructor_tag).t"></a>`t` - The value from which to initialise the  `value_type`.

### Function template `outcome_v2_6f6309a5::outcome::outcome`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(T&&,outcome_v2_6f6309a5::outcome::error_converting_constructor_tag)"></a>

<pre><code class="language-cpp">template &lt;class T&gt;
constexpr outcome(T&amp;&amp; t) noexcept(std::is_nothrow_constructible&lt;error_type, T&gt;::value);</code></pre>

Converting constructor to an errored outcome.

*Effects*: Initialises the outcome with a `error_type`.

*Requires*: `trait::status_type_is_negative<EC>` must be true; Type T is constructible to `error_type`, is not constructible to `value_type`, is not constructible to `payload_exception_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`.

*Throws*: Any exception the construction of `error_type(T)` might throw.

**Parameters:**

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(T&&,outcome_v2_6f6309a5::outcome::error_converting_constructor_tag).t"></a>`t` - The value from which to initialise the  `error_type`.

### Function template `outcome_v2_6f6309a5::outcome::outcome`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(T&&,U&&,outcome_v2_6f6309a5::outcome::error_payload_converting_constructor_tag)"></a>

<pre><code class="language-cpp">template &lt;class T, class U&gt;
constexpr outcome(T&amp;&amp; t, U&amp;&amp; u) noexcept(std::is_nothrow_constructible&lt;error_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;payload_exception_type, U&gt;::value);</code></pre>

Converting constructor to an errored outcome + payload/exception.

*Effects*: Initialises the outcome with a `error_type` and a `payload_exception_type`.

*Requires*: `trait::status_type_is_negative<EC>` must be true; Type T is constructible to `error_type`, is not constructible to `value_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`; Type `U` is constructible to `payload_exception_type`, is not constructible to `value_type`.

*Throws*: Any exception the construction of `error_type(T)` and `payload_exception_type(U)` might throw.

**Parameters:**

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(T&&,U&&,outcome_v2_6f6309a5::outcome::error_payload_converting_constructor_tag).t"></a>`t` - The value from which to initialise the  `error_type`.

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(T&&,U&&,outcome_v2_6f6309a5::outcome::error_payload_converting_constructor_tag).u"></a>`u` - The value from which to initialise the  `payload_exception_type`.

### Function template `outcome_v2_6f6309a5::outcome::outcome`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(T&&,outcome_v2_6f6309a5::outcome::exception_converting_constructor_tag)"></a>

<pre><code class="language-cpp">template &lt;class T&gt;
constexpr outcome(T&amp;&amp; t) noexcept(std::is_nothrow_constructible&lt;exception_type, T&gt;::value);</code></pre>

Converting constructor to an excepted outcome.

*Effects*: Initialises the outcome with a `exception_type`.

*Requires*: `trait::is_exception_ptr<P>` must be true; Type T is constructible to `exception_type`, is not constructible to `value_type`, is not constructible to `status_error_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`.

*Throws*: Any exception the construction of `exception_type(T)` might throw.

**Parameters:**

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(T&&,outcome_v2_6f6309a5::outcome::exception_converting_constructor_tag).t"></a>`t` - The value from which to initialise the  `exception_type`.

### Function template `outcome_v2_6f6309a5::outcome::outcome`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(constoutcome-T,U,V,W-&,outcome_v2_6f6309a5::outcome::explicit_compatible_conversion_tag)"></a>

<pre><code class="language-cpp">template &lt;class T, class U, class V, class W&gt;
constexpr outcome(const <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-'>outcome&lt;T, U, V, W&gt;</a>&amp; o, <a href='standardese://outcome_v2_6f6309a5::outcome<R, S, P, NoValuePolicy>::explicit_compatible_conversion_tag/'>explicit_compatible_conversion_tag</a> = explicit_compatible_conversion_tag()) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;status_error_type, U&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;payload_exception_type, V&gt;::value);</code></pre>

Explicit converting copy constructor from a compatible outcome type.

*Effects*: Initialises the outcome with a copy of the compatible outcome.

*Requires*: Both outcome's `value_type`, `error_type`, `status_type`, `payload_type` and `exception_type` need to be constructible, or the source `void`. The source `value_type` cannot be `void`.

*Throws*: Any exception the construction of `value_type(T)`, `status_error_type(U)` or `payload_exception_type(V)` might throw.

**Parameters:**

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(constoutcome-T,U,V,W-&,outcome_v2_6f6309a5::outcome::explicit_compatible_conversion_tag).o"></a>`o` - The compatible outcome.

### Function template `outcome_v2_6f6309a5::outcome::outcome`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(constoutcome-T,U,V,W-&,outcome_v2_6f6309a5::outcome::implicit_compatible_conversion_tag)"></a>

<pre><code class="language-cpp">template &lt;class T, class U, class V, class W&gt;
constexpr outcome(const <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-'>outcome&lt;T, U, V, W&gt;</a>&amp; o, <a href='standardese://outcome_v2_6f6309a5::outcome<R, S, P, NoValuePolicy>::implicit_compatible_conversion_tag/'>implicit_compatible_conversion_tag</a> = implicit_compatible_conversion_tag()) noexcept(std::is_nothrow_constructible&lt;payload_exception_type, V&gt;::value);</code></pre>

Implicit converting copy constructor from a compatible outcome type.

*Effects*: Initialises the outcome with a copy of the compatible outcome.

*Requires*: Both outcome's `error_type`, `status_type`, `payload_type` and `exception_type` need to be constructible, or the source `void`. The source `value_type` must be `void`.

*Throws*: Any exception the construction of `status_error_type(U)` or `payload_exception_type(V)` might throw.

**Parameters:**

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(constoutcome-T,U,V,W-&,outcome_v2_6f6309a5::outcome::implicit_compatible_conversion_tag).o"></a>`o` - The compatible outcome.

### Function template `outcome_v2_6f6309a5::outcome::outcome`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(outcome-T,U,V,W-&&,outcome_v2_6f6309a5::outcome::explicit_compatible_conversion_tag)"></a>

<pre><code class="language-cpp">template &lt;class T, class U, class V, class W&gt;
constexpr outcome(<a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-'>outcome&lt;T, U, V, W&gt;</a>&amp;&amp; o, <a href='standardese://outcome_v2_6f6309a5::outcome<R, S, P, NoValuePolicy>::explicit_compatible_conversion_tag/'>explicit_compatible_conversion_tag</a> = explicit_compatible_conversion_tag()) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;status_error_type, U&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;payload_exception_type, V&gt;::value);</code></pre>

Explicit converting move constructor from a compatible outcome type.

*Effects*: Initialises the outcome with a move of the compatible outcome.

*Requires*: Both outcome's `value_type`, `error_type`, `status_type`, `payload_type` and `exception_type` need to be constructible, or the source `void`. The source `value_type` cannot be `void`.

*Throws*: Any exception the construction of `value_type(T)`, `status_error_type(U)` or `payload_exception_type(V)` might throw.

**Parameters:**

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(outcome-T,U,V,W-&&,outcome_v2_6f6309a5::outcome::explicit_compatible_conversion_tag).o"></a>`o` - The compatible outcome.

### Function template `outcome_v2_6f6309a5::outcome::outcome`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(outcome-T,U,V,W-&&,outcome_v2_6f6309a5::outcome::implicit_compatible_conversion_tag)"></a>

<pre><code class="language-cpp">template &lt;class T, class U, class V, class W&gt;
constexpr outcome(<a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-'>outcome&lt;T, U, V, W&gt;</a>&amp;&amp; o, <a href='standardese://outcome_v2_6f6309a5::outcome<R, S, P, NoValuePolicy>::implicit_compatible_conversion_tag/'>implicit_compatible_conversion_tag</a> = implicit_compatible_conversion_tag()) noexcept(std::is_nothrow_constructible&lt;status_error_type, U&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;payload_exception_type, V&gt;::value);</code></pre>

Implicit converting move constructor from a compatible outcome type.

*Effects*: Initialises the outcome with a move of the compatible outcome.

*Requires*: Both outcome's `error_type`, `status_type`, `payload_type` and `exception_type` need to be constructible, or the source `void`. The source `value_type` must be `void`.

*Throws*: Any exception the construction of `status_error_type(U)` or `payload_exception_type(V)` might throw.

**Parameters:**

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(outcome-T,U,V,W-&&,outcome_v2_6f6309a5::outcome::implicit_compatible_conversion_tag).o"></a>`o` - The compatible outcome.

### Function template `outcome_v2_6f6309a5::outcome::outcome`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(constresult-T,U,V-&,outcome_v2_6f6309a5::outcome::explicit_compatible_conversion_tag)"></a>

<pre><code class="language-cpp">template &lt;class T, class U, class V&gt;
constexpr outcome(const <a href='doc_result.md#outcome_v2_6f6309a5::result-R,S,NoValuePolicy-'>result&lt;T, U, V&gt;</a>&amp; o, <a href='standardese://outcome_v2_6f6309a5::outcome<R, S, P, NoValuePolicy>::explicit_compatible_conversion_tag/'>explicit_compatible_conversion_tag</a> = explicit_compatible_conversion_tag()) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;status_error_type, U&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;payload_exception_type&gt;::value);</code></pre>

Explicit converting copy constructor from a compatible result type.

*Effects*: Initialises the outcome with a copy of the compatible result.

*Requires*: Both outcome's `value_type`, `error_type` and `status_type` need to be constructible, or the source `void`. The source `value_type` cannot be `void`.

*Throws*: Any exception the construction of `value_type(T)`, `status_error_type(U)` or `payload_exception_type()` might throw.

**Parameters:**

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(constresult-T,U,V-&,outcome_v2_6f6309a5::outcome::explicit_compatible_conversion_tag).o"></a>`o` - The compatible result.

### Function template `outcome_v2_6f6309a5::outcome::outcome`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(constresult-T,U,V-&,outcome_v2_6f6309a5::outcome::implicit_compatible_conversion_tag)"></a>

<pre><code class="language-cpp">template &lt;class T, class U, class V&gt;
constexpr outcome(const <a href='doc_result.md#outcome_v2_6f6309a5::result-R,S,NoValuePolicy-'>result&lt;T, U, V&gt;</a>&amp; o, <a href='standardese://outcome_v2_6f6309a5::outcome<R, S, P, NoValuePolicy>::implicit_compatible_conversion_tag/'>implicit_compatible_conversion_tag</a> = implicit_compatible_conversion_tag()) noexcept(std::is_nothrow_constructible&lt;status_error_type, U&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;payload_exception_type&gt;::value);</code></pre>

Implicit converting copy constructor from a compatible result type.

*Effects*: Initialises the outcome with a copy of the compatible result.

*Requires*: Both outcome's`error_type` and `status_type` need to be constructible, or the source `void`. The source `value_type` must be `void`.

*Throws*: Any exception the construction of`status_error_type(U)` or `payload_exception_type()` might throw.

**Parameters:**

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(constresult-T,U,V-&,outcome_v2_6f6309a5::outcome::implicit_compatible_conversion_tag).o"></a>`o` - The compatible result.

### Function template `outcome_v2_6f6309a5::outcome::outcome`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(result-T,U,V-&&,outcome_v2_6f6309a5::outcome::explicit_compatible_conversion_tag)"></a>

<pre><code class="language-cpp">template &lt;class T, class U, class V&gt;
constexpr outcome(<a href='doc_result.md#outcome_v2_6f6309a5::result-R,S,NoValuePolicy-'>result&lt;T, U, V&gt;</a>&amp;&amp; o, <a href='standardese://outcome_v2_6f6309a5::outcome<R, S, P, NoValuePolicy>::explicit_compatible_conversion_tag/'>explicit_compatible_conversion_tag</a> = explicit_compatible_conversion_tag()) noexcept(std::is_nothrow_constructible&lt;value_type, T&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;status_error_type, U&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;payload_exception_type&gt;::value);</code></pre>

Explicit converting move constructor from a compatible result type.

*Effects*: Initialises the outcome with a move of the compatible result.

*Requires*: Both outcome's `value_type`, `error_type` and `status_type` need to be constructible, or the source `void`. The source `value_type` cannot be `void`.

*Throws*: Any exception the construction of `value_type(T)`, `status_error_type(U)` or `payload_exception_type()` might throw.

**Parameters:**

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(result-T,U,V-&&,outcome_v2_6f6309a5::outcome::explicit_compatible_conversion_tag).o"></a>`o` - The compatible result.

### Function template `outcome_v2_6f6309a5::outcome::outcome`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(result-T,U,V-&&,outcome_v2_6f6309a5::outcome::implicit_compatible_conversion_tag)"></a>

<pre><code class="language-cpp">template &lt;class T, class U, class V&gt;
constexpr outcome(<a href='doc_result.md#outcome_v2_6f6309a5::result-R,S,NoValuePolicy-'>result&lt;T, U, V&gt;</a>&amp;&amp; o, <a href='standardese://outcome_v2_6f6309a5::outcome<R, S, P, NoValuePolicy>::implicit_compatible_conversion_tag/'>implicit_compatible_conversion_tag</a> = implicit_compatible_conversion_tag()) noexcept(std::is_nothrow_constructible&lt;status_error_type, U&gt;::value&amp;&amp;std::is_nothrow_constructible&lt;payload_exception_type&gt;::value);</code></pre>

Implicit converting move constructor from a compatible result type.

*Effects*: Initialises the outcome with a move of the compatible result.

*Requires*: Both outcome's `error_type` and `status_type` need to be constructible, or the source `void`. The source `value_type` must be `void`.

*Throws*: Any exception the construction of `status_error_type(U)` or `payload_exception_type()` might throw.

**Parameters:**

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(result-T,U,V-&&,outcome_v2_6f6309a5::outcome::implicit_compatible_conversion_tag).o"></a>`o` - The compatible result.

### Function template `outcome_v2_6f6309a5::outcome::outcome`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-value_type_if_enabled-,Args&&...)"></a>

<pre><code class="language-cpp">template &lt;class ... Args&gt;
constexpr outcome(in_place_type_t&lt;value_type_if_enabled&gt; _, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;value_type, Args...&gt;::value);</code></pre>

Inplace constructor to a successful value.

*Effects*: Initialises the outcome with a `value_type`.

*Requires*: `value_type` is void or `Args...` are constructible to `value_type`.

*Throws*: Any exception the construction of `value_type(Args...)` might throw.

**Parameters:**

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-value_type_if_enabled-,Args&&...)._"></a>Tag type to indicate we are doing in place construction of  `value_type`.

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-value_type_if_enabled-,Args&&...).args"></a>`args` - Arguments with which to in place construct.

### Function template `outcome_v2_6f6309a5::outcome::outcome`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-value_type_if_enabled-,std::initializer_list-U-,Args&&...)"></a>

<pre><code class="language-cpp">template &lt;class U, class ... Args&gt;
constexpr outcome(in_place_type_t&lt;value_type_if_enabled&gt; _, <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::initializer_list%3cU%3e'>std::initializer_list&lt;U&gt;</a> il, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;value_type, std::initializer_list&lt;U&gt;, Args...&gt;::value);</code></pre>

Inplace constructor to a successful value.

*Effects*: Initialises the outcome with a `value_type`.

*Requires*: The initializer list + `Args...` are constructible to `value_type`.

*Throws*: Any exception the construction of `value_type(il, Args...)` might throw.

**Parameters:**

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-value_type_if_enabled-,std::initializer_list-U-,Args&&...)._"></a>Tag type to indicate we are doing in place construction of  `value_type`.

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-value_type_if_enabled-,std::initializer_list-U-,Args&&...)"></a>`il` - An initializer list with which to in place construct.

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-value_type_if_enabled-,std::initializer_list-U-,Args&&...).args"></a>`args` - Arguments with which to in place construct.

### Function template `outcome_v2_6f6309a5::outcome::outcome`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-error_type_if_enabled-,Args&&...)"></a>

<pre><code class="language-cpp">template &lt;class ... Args&gt;
constexpr outcome(in_place_type_t&lt;error_type_if_enabled&gt; _, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;error_type, Args...&gt;::value);</code></pre>

Inplace constructor to an unsuccessful error.

*Effects*: Initialises the outcome with a `error_type`.

*Requires*: `trait::status_type_is_negative<EC>` must be true; `error_type` is void or `Args...` are constructible to `error_type`.

*Throws*: Any exception the construction of `error_type(Args...)` might throw.

**Parameters:**

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-error_type_if_enabled-,Args&&...)._"></a>Tag type to indicate we are doing in place construction of  `error_type`.

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-error_type_if_enabled-,Args&&...).args"></a>`args` - Arguments with which to in place construct.

### Function template `outcome_v2_6f6309a5::outcome::outcome`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-error_type_if_enabled-,std::initializer_list-U-,Args&&...)"></a>

<pre><code class="language-cpp">template &lt;class U, class ... Args&gt;
constexpr outcome(in_place_type_t&lt;error_type_if_enabled&gt; _, <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::initializer_list%3cU%3e'>std::initializer_list&lt;U&gt;</a> il, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;error_type, std::initializer_list&lt;U&gt;, Args...&gt;::value);</code></pre>

Inplace constructor to an unsuccessful error.

*Effects*: Initialises the outcome with a `error_type`.

*Requires*: `trait::status_type_is_negative<EC>` must be true; The initializer list + `Args...` are constructible to `error_type`.

*Throws*: Any exception the construction of `error_type(il, Args...)` might throw.

**Parameters:**

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-error_type_if_enabled-,std::initializer_list-U-,Args&&...)._"></a>Tag type to indicate we are doing in place construction of  `error_type`.

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-error_type_if_enabled-,std::initializer_list-U-,Args&&...)"></a>`il` - An initializer list with which to in place construct.

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-error_type_if_enabled-,std::initializer_list-U-,Args&&...).args"></a>`args` - Arguments with which to in place construct.

### Function template `outcome_v2_6f6309a5::outcome::outcome`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-payload_exception_type_if_enabled-,Args&&...)"></a>

<pre><code class="language-cpp">template &lt;class ... Args&gt;
constexpr outcome(in_place_type_t&lt;payload_exception_type_if_enabled&gt;, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;payload_exception_type, Args...&gt;::value);</code></pre>

Inplace constructor to an unsuccessful payload/exception.

*Effects*: Initialises the outcome with a `payload_exception_type`.

*Requires*: `payload_exception_type` is void or `Args...` are constructible to `payload_exception_type`.

*Throws*: Any exception the construction of `payload_exception_type(Args...)` might throw.

**Parameters:**

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-payload_exception_type_if_enabled-,Args&&...).args"></a>`args` - Arguments with which to in place construct.

### Function template `outcome_v2_6f6309a5::outcome::outcome`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-payload_exception_type_if_enabled-,std::initializer_list-U-,Args&&...)"></a>

<pre><code class="language-cpp">template &lt;class U, class ... Args&gt;
constexpr outcome(in_place_type_t&lt;payload_exception_type_if_enabled&gt;, <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::initializer_list%3cU%3e'>std::initializer_list&lt;U&gt;</a> il, Args&amp;&amp;... args) noexcept(std::is_nothrow_constructible&lt;payload_exception_type, std::initializer_list&lt;U&gt;, Args...&gt;::value);</code></pre>

Inplace constructor to an unsuccessful payload/exception.

*Effects*: Initialises the outcome with a `payload_exception_type`.

*Requires*: The initializer list + `Args...` are constructible to `payload_exception_type`.

*Throws*: Any exception the construction of `payload_exception_type(il, Args...)` might throw.

**Parameters:**

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-payload_exception_type_if_enabled-,std::initializer_list-U-,Args&&...)"></a>`il` - An initializer list with which to in place construct.

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::outcome(in_place_type_t-payload_exception_type_if_enabled-,std::initializer_list-U-,Args&&...).args"></a>`args` - Arguments with which to in place construct.

### Comparison operator `outcome_v2_6f6309a5::outcome::operator==`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::operator==(constoutcome-T,U,V,W-&)const"></a>

<pre><code class="language-cpp">template &lt;class T, class U, class V, class W&gt;
constexpr )//&gt;bool operator==(const <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-'>outcome&lt;T, U, V, W&gt;</a>&amp; o) const noexcept(//noexcept(std::declval&lt;R&gt;()==std::declval&lt;T&gt;())//&amp;&amp;noexcept(std::declval&lt;S&gt;()==std::declval&lt;U&gt;())//&amp;&amp;noexcept(std::declval&lt;P&gt;()==std::declval&lt;V&gt;()));</code></pre>

True if equal to the other outcome.

*Effects*: Calls the `operator==` operation on each of the three stored items until one returns false.

*Requires*: That the expression of calling `operator==` on each of the three stored items is a valid expression.

*Throws*: Any exception the individual `operator==` operations might throw.

**Parameters:**

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::operator==(constoutcome-T,U,V,W-&)const.o"></a>`o` - The other outcome to compare to.

### Comparison operator `outcome_v2_6f6309a5::outcome::operator!=`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::operator!=(constoutcome-T,U,V,W-&)const"></a>

<pre><code class="language-cpp">template &lt;class T, class U, class V, class W&gt;
constexpr )//&gt;bool operator!=(const <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-'>outcome&lt;T, U, V, W&gt;</a>&amp; o) const noexcept(//noexcept(std::declval&lt;R&gt;()!=std::declval&lt;T&gt;())//&amp;&amp;noexcept(std::declval&lt;S&gt;()!=std::declval&lt;U&gt;())//&amp;&amp;noexcept(std::declval&lt;P&gt;()!=std::declval&lt;V&gt;()));</code></pre>

True if not equal to the other outcome.

*Effects*: Calls the `operator!=` operation on each of the three stored items until one returns true.

*Requires*: That the expression of calling `operator!=` on each of the three stored items is a valid expression.

*Throws*: Any exception the individual `operator!=` operations might throw.

**Parameters:**

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::operator!=(constoutcome-T,U,V,W-&)const.o"></a>`o` - The other outcome to compare to.

### Comparison operator `outcome_v2_6f6309a5::outcome::operator==`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::operator==(constresult-T,U,V-&)const"></a>

<pre><code class="language-cpp">template &lt;class T, class U, class V, typename = decltype(std::declval&lt;R&gt;()==std::declval&lt;T&gt;()&gt;
constexpr )//&gt;bool operator==(const <a href='doc_result.md#outcome_v2_6f6309a5::result-R,S,NoValuePolicy-'>result&lt;T, U, V&gt;</a>&amp; o) const noexcept(//noexcept(std::declval&lt;R&gt;()==std::declval&lt;T&gt;())//&amp;&amp;noexcept(std::declval&lt;S&gt;()==std::declval&lt;U&gt;()));</code></pre>

True if equal to the other result.

*Effects*: Calls the `operator==` operation on each of the two stored items until one returns false.

*Requires*: That the expression of calling `operator==` on each of the two stored items is a valid expression.

*Throws*: Any exception the individual `operator==` operations might throw.

**Parameters:**

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::operator==(constresult-T,U,V-&)const.o"></a>`o` - The other result to compare to.

### Comparison operator `outcome_v2_6f6309a5::outcome::operator!=`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::operator!=(constresult-T,U,V-&)const"></a>

<pre><code class="language-cpp">template &lt;class T, class U, class V, typename = decltype(std::declval&lt;R&gt;()!=std::declval&lt;T&gt;()&gt;
constexpr )//&gt;bool operator!=(const <a href='doc_result.md#outcome_v2_6f6309a5::result-R,S,NoValuePolicy-'>result&lt;T, U, V&gt;</a>&amp; o) const noexcept(//noexcept(std::declval&lt;R&gt;()!=std::declval&lt;T&gt;())//&amp;&amp;noexcept(std::declval&lt;S&gt;()!=std::declval&lt;U&gt;()));</code></pre>

True if not equal to the other result.

*Effects*: Calls the `operator!=` operation on each of the two stored items until one returns true.

*Requires*: That the expression of calling `operator!=` on each of the two stored items is a valid expression.

*Throws*: Any exception the individual `operator!=` operations might throw.

**Parameters:**

  - <a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::operator!=(constresult-T,U,V-&)const.o"></a>`o` - The other result to compare to.

### Function `outcome_v2_6f6309a5::outcome::as_void`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::as_void()const&"></a>

<pre><code class="language-cpp"><a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::rebind-T,U,V-'>rebind&lt;void&gt;</a> as_void() const &amp;;</code></pre>

Returns this outcome rebound to void with any errored and payload state copied.

*Requires*: This outcome to have a failed state, else whatever `assume_error()` would do.

### Function `outcome_v2_6f6309a5::outcome::as_void`<a id="outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::as_void()&&"></a>

<pre><code class="language-cpp"><a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-::rebind-T,U,V-'>rebind&lt;void&gt;</a> as_void() &amp;&amp;;</code></pre>

Returns this outcome rebound to void with any errored and payload state moved.

*Requires*: This outcome to have a failed state, else whatever `assume_error()` would do.

-----

## Comparison operator `outcome_v2_6f6309a5::operator==`<a id="outcome_v2_6f6309a5::operator==(constresult-T,U,V-&,constoutcome-R,S,P,N-&)"></a>

<pre><code class="language-cpp">template &lt;class T, class U, class V, class R, class S, class P, class N&gt;
constexpr )//&gt;bool operator==(const <a href='doc_result.md#outcome_v2_6f6309a5::result-R,S,NoValuePolicy-'>result&lt;T, U, V&gt;</a>&amp; a, const <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-'>outcome&lt;R, S, P, N&gt;</a>&amp; b) noexcept(//noexcept(std::declval&lt;outcome&lt;R, S, P, N&gt;&gt;()==std::declval&lt;result&lt;T, U, V&gt;&gt;()));</code></pre>

True if the result is equal to the outcome

*Effects*: Calls `b == a`.

*Requires*: That the expression `b == a` is a valid expression.

*Throws*: Any exception that `b == a` might throw.

**Parameters:**

  - <a id="outcome_v2_6f6309a5::operator==(constresult-T,U,V-&,constoutcome-R,S,P,N-&)"></a>`a` - The result to compare.

  - <a id="outcome_v2_6f6309a5::operator==(constresult-T,U,V-&,constoutcome-R,S,P,N-&).b"></a>`b` - The outcome to compare.

## Comparison operator `outcome_v2_6f6309a5::operator!=`<a id="outcome_v2_6f6309a5::operator!=(constresult-T,U,V-&,constoutcome-R,S,P,N-&)"></a>

<pre><code class="language-cpp">template &lt;class T, class U, class V, class R, class S, class P, class N&gt;
constexpr )//&gt;bool operator!=(const <a href='doc_result.md#outcome_v2_6f6309a5::result-R,S,NoValuePolicy-'>result&lt;T, U, V&gt;</a>&amp; a, const <a href='doc_outcome.md#outcome_v2_6f6309a5::outcome-R,S,P,NoValuePolicy-'>outcome&lt;R, S, P, N&gt;</a>&amp; b) noexcept(//noexcept(std::declval&lt;outcome&lt;R, S, P, N&gt;&gt;()!=std::declval&lt;result&lt;T, U, V&gt;&gt;()));</code></pre>

True if the result is not equal to the outcome

*Effects*: Calls `b != a`.

*Requires*: That the expression `b != a` is a valid expression.

*Throws*: Any exception that `b != a` might throw.

**Parameters:**

  - <a id="outcome_v2_6f6309a5::operator!=(constresult-T,U,V-&,constoutcome-R,S,P,N-&)"></a>`a` - The result to compare.

  - <a id="outcome_v2_6f6309a5::operator!=(constresult-T,U,V-&,constoutcome-R,S,P,N-&).b"></a>`b` - The outcome to compare.

## Class template `outcome_v2_6f6309a5::policy::error_code_throw_as_system_error_exception_rethrow` \[Error code interpretation policy\]<a id="outcome_v2_6f6309a5::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-"></a>

<pre><code class="language-cpp">template &lt;class R, class S, class P&gt;
struct error_code_throw_as_system_error_exception_rethrow
{
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_outcome.md#outcome_v2_6f6309a5::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-::narrow_value_check(Impl*)'>narrow_value_check</a>(Impl* self) noexcept;
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_outcome.md#outcome_v2_6f6309a5::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-::narrow_error_check(Impl*)'>narrow_error_check</a>(Impl* self) noexcept;
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_outcome.md#outcome_v2_6f6309a5::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-::narrow_payload_check(Impl*)'>narrow_payload_check</a>(Impl* self) noexcept;
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_outcome.md#outcome_v2_6f6309a5::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-::narrow_exception_check(Impl*)'>narrow_exception_check</a>(Impl* self) noexcept;
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_outcome.md#outcome_v2_6f6309a5::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-::wide_value_check(Impl*)'>wide_value_check</a>(Impl* self);
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_outcome.md#outcome_v2_6f6309a5::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-::wide_error_check(Impl*)'>wide_error_check</a>(Impl* self);
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_outcome.md#outcome_v2_6f6309a5::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-::wide_payload_check(Impl*)'>wide_payload_check</a>(Impl* self);
    
    template &lt;class Impl&gt;
    static constexpr void <a href='doc_outcome.md#outcome_v2_6f6309a5::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-::wide_exception_check(Impl*)'>wide_exception_check</a>(Impl* self);
};</code></pre>

Policy interpreting S as a type implementing the `std::error_code` contract, E as a type implementing the `std::exception_ptr` contract, and any wide attempt to access the successful state throws the `exception_ptr` if available, then the `error_code` wrapped into a `std::system_error`.

### Function template `outcome_v2_6f6309a5::policy::error_code_throw_as_system_error_exception_rethrow::narrow_value_check`<a id="outcome_v2_6f6309a5::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-::narrow_value_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void narrow_value_check(Impl* self) noexcept;</code></pre>

Performs a narrow check of state, used in the assume\_value() functions.

*Effects*: None.

### Function template `outcome_v2_6f6309a5::policy::error_code_throw_as_system_error_exception_rethrow::narrow_error_check`<a id="outcome_v2_6f6309a5::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-::narrow_error_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void narrow_error_check(Impl* self) noexcept;</code></pre>

Performs a narrow check of state, used in the assume\_error() functions.

*Effects*: None.

### Function template `outcome_v2_6f6309a5::policy::error_code_throw_as_system_error_exception_rethrow::narrow_payload_check`<a id="outcome_v2_6f6309a5::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-::narrow_payload_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void narrow_payload_check(Impl* self) noexcept;</code></pre>

Performs a narrow check of state, used in the assume\_payload() functions.

*Effects*: None.

### Function template `outcome_v2_6f6309a5::policy::error_code_throw_as_system_error_exception_rethrow::narrow_exception_check`<a id="outcome_v2_6f6309a5::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-::narrow_exception_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void narrow_exception_check(Impl* self) noexcept;</code></pre>

Performs a narrow check of state, used in the assume\_exception() functions.

*Effects*: None.

### Function template `outcome_v2_6f6309a5::policy::error_code_throw_as_system_error_exception_rethrow::wide_value_check`<a id="outcome_v2_6f6309a5::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-::wide_value_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void wide_value_check(Impl* self);</code></pre>

Performs a wide check of state, used in the value() functions.

*Effects*: If outcome does not have a value, if it has an exception it rethrows it via `std::rethrow_exception()`, if has an error it throws a `std::system_error(error())`, else it throws `bad_outcome_access`.

### Function template `outcome_v2_6f6309a5::policy::error_code_throw_as_system_error_exception_rethrow::wide_error_check`<a id="outcome_v2_6f6309a5::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-::wide_error_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void wide_error_check(Impl* self);</code></pre>

Performs a wide check of state, used in the error() functions

*Effects*: If outcome does not have an error, it throws `bad_outcome_access`.

### Function template `outcome_v2_6f6309a5::policy::error_code_throw_as_system_error_exception_rethrow::wide_payload_check`<a id="outcome_v2_6f6309a5::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-::wide_payload_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void wide_payload_check(Impl* self);</code></pre>

Performs a wide check of state, used in the payload() functions

*Effects*: If outcome does not have a payload, it throws `bad_outcome_access`.

### Function template `outcome_v2_6f6309a5::policy::error_code_throw_as_system_error_exception_rethrow::wide_exception_check`<a id="outcome_v2_6f6309a5::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P-::wide_exception_check(Impl*)"></a>

<pre><code class="language-cpp">template &lt;class Impl&gt;
static constexpr void wide_exception_check(Impl* self);</code></pre>

Performs a wide check of state, used in the exception() functions

*Effects*: If outcome does not have an exception, it throws `bad_outcome_access`.

-----

-----

-----
