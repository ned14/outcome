<table width="100%">
<tr><th>master branch<th>develop branch
<tr><td align="center"><img src="https://github.com/ned14/outcome/workflows/Documentation/badge.svg?branch=master"><td align="center"><img src="https://github.com/ned14/outcome/workflows/Documentation/badge.svg?branch=develop">
<tr><td align="center"><img src="https://github.com/ned14/outcome/workflows/Installability/badge.svg?branch=master"><td align="center"><img src="https://github.com/ned14/outcome/workflows/Installability/badge.svg?branch=develop">
<tr><td align="center"><a href="https://github.com/ned14/outcome/actions?query=workflow%3A%22Unit+tests+Linux%22"><img src="https://github.com/ned14/outcome/workflows/Unit%20tests%20Linux/badge.svg?branch=master"></a><td align="center"><a href="https://github.com/ned14/outcome/actions?query=workflow%3A%22Unit+tests+Linux%22"><img src="https://github.com/ned14/outcome/workflows/Unit%20tests%20Linux/badge.svg?branch=develop"></a>
<tr><td align="center"><a href="https://github.com/ned14/outcome/actions?query=workflow%3A%22Unit+tests+Mac+OS%22"><img src="https://github.com/ned14/outcome/workflows/Unit%20tests%20Mac%20OS/badge.svg?branch=master"></a><td align="center"><a href="https://github.com/ned14/outcome/actions?query=workflow%3A%22Unit+tests+Mac+OS%22"><img src="https://github.com/ned14/outcome/workflows/Unit%20tests%20Mac%20OS/badge.svg?branch=develop"></a>
<tr><td align="center"><a href="https://github.com/ned14/outcome/actions?query=workflow%3A%22Unit+tests+Windows%22"><img src="https://github.com/ned14/outcome/workflows/Unit%20tests%20Windows/badge.svg?branch=master"></a><td align="center"><a href="https://github.com/ned14/outcome/actions?query=workflow%3A%22Unit+tests+Windows%22"><img src="https://github.com/ned14/outcome/workflows/Unit%20tests%20Windows/badge.svg?branch=develop"></a>
</table>

CTest dashboard: https://my.cdash.org/index.php?project=Boost.Outcome

All tests passing source tarballs: https://github.com/ned14/outcome/releases

Documentation: https://ned14.github.io/outcome/


## Purpose of this library

Outcome is a C++14 library for reporting and handling function failures. It can be used as a substitute for, or a complement to, the exception handling mechanism.

One use case is for contexts where using C++ exception handling is unsuitable for different reasons:

 * The high relative cost of throwing and catching a C++ exception.
 * Making some or all control paths explicitly detailed to aid code correctness auditing, as opposed to having hidden control paths caused by exceptions potentially thrown from any place.
 * Company policy to compile with exceptions disabled.
 * Maintaining a code base that was never designed with exception-safety in mind.
 * Parts of the programs/frameworks that themselves implement exception handling and cannot afford to use exceptions, like propagating failure reports across threads, tasks, fibers…


## Usage as a single header file

Outcome v2 comes in single header file form. This is regenerated per commit. To fetch
on Linux:

```
wget https://github.com/ned14/outcome/raw/master/single-header/outcome.hpp
```

On BSD:

```
fetch https://github.com/ned14/outcome/raw/master/single-header/outcome.hpp
```

If you have `curl` installed:

```
curl -O -J -L https://github.com/ned14/outcome/raw/master/single-header/outcome.hpp
```

Otherwise, simply download the raw file from above and place it wherever it suits you.
If you might be debugging using Microsoft Visual Studio, you may find the debugger
visualisation file at https://github.com/ned14/outcome/raw/master/include/outcome/outcome.natvis
useful to include into your build.

## Commits and tags in this git repository can be verified using:
<pre>
-----BEGIN PGP PUBLIC KEY BLOCK-----
Version: GnuPG v2

mDMEVvMacRYJKwYBBAHaRw8BAQdAp+Qn6djfxWQYtAEvDmv4feVmGALEQH/pYpBC
llaXNQe0WE5pYWxsIERvdWdsYXMgKHMgW3VuZGVyc2NvcmVdIHNvdXJjZWZvcmdl
IHthdH0gbmVkcHJvZCBbZG90XSBjb20pIDxzcGFtdHJhcEBuZWRwcm9kLmNvbT6I
eQQTFggAIQUCVvMacQIbAwULCQgHAgYVCAkKCwIEFgIDAQIeAQIXgAAKCRCELDV4
Zvkgx4vwAP9gxeQUsp7ARMFGxfbR0xPf6fRbH+miMUg2e7rYNuHtLQD9EUoR32We
V8SjvX4r/deKniWctvCi5JccgfUwXkVzFAk=
=puFk
-----END PGP PUBLIC KEY BLOCK-----
</pre>

</center>
