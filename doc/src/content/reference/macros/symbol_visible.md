+++
title = "`OUTCOME_SYMBOL_VISIBLE`"
+++

Compiler-specific markup used to mark throwable types as always having default ELF symbol visibility, without which it will be impossible to catch throws of such types across shared library boundaries on ELF only.

*Overridable*: Define before inclusion.

*Default*:<dl>
<dt>Standalone Outcome:</dt>
<dd>To `__attribute__((visibility("default"))` on GCC and clang when targeting ELF, otherwise nothing.</dd>
<dt>Boost.Outcome:</dt>
<dd>To `BOOST_SYMBOL_VISIBLE`.</dd>
</dl>
