Howdy y'all,

Unfortunately, we have *very* little space and are still stubborn
enough to try writing our code in C.  Then to make matters worse, we
have to call back into the manufacturer's ROM, so we have to use GCC7
as distributed by TI; we can't use the more efficient build that comes
with Debian.

So we need to build a bit differently, and many handy features just
won't be available.  No libc, no printf(), etc.

--Travis


## Examples

`ndef.c` contains no code, but demonstrates an NDEF-formatted tag that
is readable from iPhone or Android.

`hello.c` is a basic example of a tag that implements an additional
vendor command (`A3`) for raw reads of memory.  It uses the NFC stack
from the ROM, but does not use its sensor graphing features.

