+++
title = "History"
weight = 90
+++

Outcome has had an interesting history, and it is worth summarising it here to show how a
Boost library comes to life. The following recollections are by Niall Douglas, and may be
faulty due to his aging memory.

## The genesis of Outcome v1

The git repo began life as a "Boost.Spinlock" in June 2014 hived out of Boost.AFIO v1 where it had existed
for some time as an internal library. In October 2014 I added in the original prototype
Boost.Expected reference library as a git submodule, and began developing a non-allocating
`future<T>`/`promise<T>` as an extension of `expected<T, std::exception_ptr>` as a faster,
monadic future-promise was something which AFIO v1 sorely needed.

The original prototype Boost.Expected library was a large and very complex beastie.
I was fortunate to be employed on a contract in late 2014 early 2015 where I saw it deployed at
scale into an existing large C++ codebase. Expected was really great and powerful, but it absolutely
murdered compile times in a large C++ codebase, and made LTO effectively infeasible.
I also found its implementation non-conducive to implementing
future-promise with it, and so I resolved to implement a much more powerful policy driven
monad factory which could stamp out everything from an `option<T>` right through to a
future-promise pair, all using the exact same `basic_monad<>` and therefore all with a full
monadic programming API, C++ 17 continuations/monadic bind and intelligently convertible into one another.
Moreover, all this needed to have an absolute minimum impact on compile times and runtime
overheads, neither of which were strengths of the original prototype Boost.Expected library.

By August 2015 "Boost.Monad" was delivering on all those requirements and then some, but it lacked
maturity through use in other code. Summer 2015 saw the Boost peer review of AFIO v1 which
was roundly rejected. After considering the ample review feedback, it was realised that
AFIO v2 would be a very different design, one no longer using futures, memory allocation
nor C++ exceptions. As AFIO v2 was started from scratch and using Outcome heavily from the
very beginning (every AFIO v2 API returns a `result<T>`), Outcome began to gain bug fixes and
shed features, with the non-allocating future-promise implementation being dropped in May
2016 and a large chunk of metaprogramming being replaced with cleaner variable templates
in June. After CppCon 2016 in September, then began the long process of getting Outcome
ready for Boost peer review in Q1 2017 which involved a repeated sequence of complete rewrites
of the tutorial in response to multiple rounds of feedback from the C++ community, with
at least four complete rewrites currently at the time of writing.

In parallel to all this development on Outcome, Expected went before the LEWG and entered
the C++ standards track. As the WG21 meetings went by, Expected experienced a period
of being stripped back and much of the complexity which had so murdered compile and
link times in 2014/2015 fell away, thus the Expected proposed in P0323R1 ended up landing
so close to Outcome that in January 2017 it was just a few hours work to implement
Expected using the core `basic_monad` infrastructure in Outcome. That highly flexible
policy based design which made monadic future-promise possible made it similarly easy
to implement a highly conforming Expected, indeed in early 2017 Outcome's Expected was much
closer to P0323R1 than any other implementation including the LEWG reference implementation.
And unlike the LEWG reference implementation, Outcome has had eighteen months of that
finely tuned patina you only get when a library is in use by other code bases.

In February 2017 it became realised that the userbase really wanted a high quality `expected<T, E>`
implementation rather than anything similar but not the same which Outcome had invented.
The only just implemented Expected implementation based on `basic_monad` therefore took
primacy. The final rewrite of the documentation before peer review submission was one
which made it look like Outcome was primarily an `expected<T, E>` implementation with a
few useful extensions like `outcome<T>` and `result<T>`. I was sad to so pivot, but it
was obvious that Outcome would see far wider popularity and usage as primarily an Expected
implementation.

Almost three years after its beginning, Outcome v1 finally went before Boost peer review
in May 2017 which turned into one of the longest and most detailed peer reviews Boost has
done in recent years, with over 800 pieces of review feedback submitted. It was by consensus
rejected, [with substantial feedback on what to do instead](https://lists.boost.org/boost-announce/2017/06/0510.php).

## Outcome v2

During the very lengthy peer review roughly three groups of opinion emerged as to what
a value OR error transporting class ought to look like:

<dl>
<dt><b>1. Lightweight</b></dt>
<dd>A simple-as-possible <code>T</code> and/or <code>E</code> transport without any implementation complexity.</dd>
<dt><b>2. Medium</b></dt>
<dd>A variant stored <code>T</code> or <code>E1</code> ... <code>E<i>n</i></code>
where <code>T</code> is the expected value and <code>E1 ...</code>
are the potential unexpected values. This implemention really ought to be implemented
using C++ 17's <code>std::variant<...></code> except with stronger never-empty guarantees.
</dd>
<dt><b>3. Heavy</b></dt>
<dd>An Either monad participating fully in a wider monadic programming framework for C++.</dd>
</dl>

Peter Dimov was very quickly able to implement an `expected<T, E1, ...>` using his
[variant2](https://github.com/pdimov/variant2) library, and thus there seemed little
point in replicating his work in an Outcome v2.