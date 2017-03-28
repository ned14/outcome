# History and Acknowledgements
\anchor acknowledgements

Outcome has had an interesting history, and it is worth summarising it here to show how a
Boost library comes to life. The git repo
began life as a "Boost.Spinlock" in June 2014 hived out of Boost.AFIO v1 where it had existed
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

It is heartening that the committee have concurrently made most of the changes to
Expected that I also made in Outcome, as that suggests I am on the right track. Outcome's
original very ambitious design may yet still contribute a lot of value simply through
sheer flexibility and extensibility, yet with amazingly low runtime and compile time costs.
I hope users of Outcome will agree.

# Acknowledgements

To whomever it was who proposed the name "Outcome" for the library after a very extended
period of name bikeshedding on boost-dev. I had been minded to call the library "Boost.Donkey"
just to shut everyone up because the name bike shedding was getting ridiculous. But
Outcome is a lot nicer, so thank you to whomever it was.

My thanks to those on boost-dev, Reddit and SG14 for extensive and often very detailed
feedback on the library pretty much from its beginning. You are all too numerous to
remember, but certainly Tongari and Andrzej Krzemienski come to mind as having engaged
in particularly long discussion threads with tons of useful feedback which clarified my
thinking. Andrzej also went through the documentation with a fine toothed comb before the
review, finding many small errata and confusing wording.

Finally, my thanks to Vicente for driving Expected from its beginnings to hopefully
standardisation before 2020. It's many years of work getting something standardised, even
more years than getting a library into Boost which as you can see from the history above
took about three years.
