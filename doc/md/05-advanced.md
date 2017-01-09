# Advanced usage: Outcome as a Monad {#advanced}

99% of Outcome users already have everything they will ever need - Outcome is a very
simple library. However "full fat" monadic functional programming is also provided
using a very clean and powerful API, albeit at a fair cost to compile times.

\subsection functional Functional programming extensions (optional)

\note All code in this section can be enabled by defining `BOOST_OUTCOME_ENABLE_OPERATORS`.
By default only `next()` is available. This prevents you writing code which impacts build times.

It is assumed in this section that you already understand monadic functional programming. This
section is simply to explain how these are implemented in Outcome.

Classic monadic programming consists of a sequence of nested functional operations:
<dl>
  <dt>JOIN (single): `outcome<outcome<T>>.value()` -> `outcome<T>`</dt>
  <dt>JOIN (maximum): `outcome<outcome<outcome<outcome<T>>>>.unwrap()` -> `outcome<T>`</dt>
    <dd>Whatever is the first monad containing a non-monad is returned.</dd>
  <dt>MAP: `outcome<T>.map(R(T))` -> `outcome<R>`</dt>
    <dd>If callable maps `T` to `R`, `map()` maps an `outcome<T>` to an `outcome<R>` if `outcome<T>`
    contains a `T`. If it contains an error or is empty, that is passed through.</dd>
  <dt>BIND: `outcome<T>.bind(outcome<R>(T))` -> `outcome<R>`</dt>
  <dt>BIND: `outcome<T>.bind(R(T))` -> `outcome<R>`</dt>
    <dd>If callable maps `T` to `outcome<R>` and if `outcome<T>` contains a `T`, then `bind()` maps
    an `outcome<T>` to an `outcome<R>` else if callable maps `T` to `R` and if `outcome<T>` contains a `T`,
    `bind()` maps an `outcome<T>` to an `outcome<R>`. In other words, returning a monad from the
    callable does not wrap it in another monad. If the originating monad did not
    contain a `T`, that is passed through.</dd>
</dl>
We also support `outcome<T>.next(R(outcome<T>))` for semantic equivalence to futures where the
callable is called with the originating monad. This
acts like `bind()`, so if the callable returns a monad it is not wrapped in another
monad. Unlike `map()` or `bind()`, `next()` always calls the callable no matter what the
monad contains, so it is up to you to interrogate the monad. Note that the originating
monad is passed by const lvalue ref unless the callable takes a rvalue ref to the monad.

A quick use example:
\snippet monad_example.cpp monad_bind_example
\snippet unittests.cpp monad_match_example
\snippet unittests.cpp monad_operators_example

You will note in the code example that the type of the callable for `bind()` and `map()`
determines what operation happens. Here are the rules:
- If the monad contains a `T` and the callable takes a `T` or an `auto`, then:
  - If the callable takes a `T` or any reference to a `T` which isn't an rvalue reference,
  the `T` is passed by const lvalue reference (i.e. copy semantics).
  - If the callable takes a `T` by non-const rvalue reference, the `T` is passed by rvalue ref.
  This lets you move from the value held by the originating monad if so desired.
  - If the callable takes the originating monad or any reference to such which isn't a
  rvalue reference, then the originating monad is passed by const lvalue reference.
  - If the callable takes the originating monad by non-const rvalue reference, the
  originating monad is passed by rvalue reference.
The ability to take the originating monad makes `bind()` identical to `next()` though much
harder on build times. Note that these options let you rebind the type of the monad,
so if your callable returns a different type from the originating monad then the resulting
monad is based on that different return type.
\warning The current implementation requires you to specify a non-dependent return
type for all generic lambdas, else you'll get compile errors where the compiler tried
to insert `error_type`, `exception_type` etc when it was trying to figure out if the
return type is correct. A future implementation (once MSVC has Expression SFINAE) may
remove this restriction, until then just hard specify your return types if your lambdas
take an `auto`, or use lambdas not taking `auto`.

- If the monad contains an `error_type` and the callable takes an `error_type`, then
call the callable, else pass through the monad. For this reason, any callable taking
an `error_type` must always return the same monad type as the originating monad.
- If the monad contains an `error_type` or an `exception_type` and the callable takes
an `exception_type`, then call the callable, else pass through the monad. For this reason,
any callable taking an `exception_type` must always return the same monad type as the
originating monad.
- If the monad is empty and the callable takes an `empty_type`, then call the callable,
else pass through the monad. For this reason, any callable with an `empty_type` parameter must
always return the same monad type as the originating monad.

Note that for nested monads e.g. `outcome<outcome<int>>`, either or both of the inner or outer
monads can be with value or with error or empty. You should have your binds and maps
work appropriately.

For maximum build performance, try to avoid `bind()` and `map()` as these use some hefty
metaprogramming to deduce what kind of bind and map you're doing based on the callables
passed. `unwrap()` is implemented using a recursively expanded structure which is probably
okay for low unwrap depths. `next()` is probably the least weighty of the monadic operators
as it's relatively dumb and the only metaprogramming is to determine whether to wrap
the return type with a monad or not. Because of this impact on compile times, by default
all operations apart from `next()` are not compiled in without the `BOOST_OUTCOME_ENABLE_OPERATORS`
macro being defined beforehand.

### Acknowledgements ###
To T.C. on Stack Overflow for answering my question at https://stackoverflow.com/questions/30802404/how-to-detect-whether-some-callable-takes-a-rvalue-reference
and without whose excellent answer the intelligent `map()` and `bind()` above could not work.

