Herein lie multiple single header editions of Outcome:

<dl>
  <dt><code>&lt;outcome-basic.hpp&gt;</code></dt>
  <dd>An inclusion of <code>basic_outcome.hpp</code> + <code>try.hpp</code> which includes as few
  system headers as possible in order to give an absolute minimum compile time
  impact edition of Outcome. See <a href="https://github.com/ned14/stl-header-heft">https://github.com/ned14/stl-header-heft</a>.
  </dd>
  <dt><code>&lt;outcome-experimental.hpp&gt;</code></dt>
  <dd>An inclusion of <code>experimental/status_outcome.hpp</code> + <code>try.hpp</code> which
  is the low compile time impact of the basic edition combined with
  <code>status_code</code> from <a href="https://ned14.github.io/status-code/">https://ned14.github.io/status-code/</a>. If you are on an
  embedded system where binary bloat must be absolutely avoided, and don't
  mind the potentially unstable <code>status_code</code>, this is definitely the edition
  for you.
  </dd>
  <dt><code>&lt;outcome.hpp&gt;</code></dt>
  <dd>An inclusion of <code>outcome.hpp</code> which brings in all the specialisations
  for the <code>std</code> STL types, the utilities header, plus iostreams and coroutines
  support. If you don't know which edition to use, you should use this one, it ought to
  "just work".</dd>
</dl>
