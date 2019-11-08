Howdy y'all,

The GoodTag10 is my first attempt at an NFC tag emulator, based around
the RF430FRL152H chip.  As the first attempt, it likely has some
errata that I've not yet found.  Sorry about that.

The passive values roughly come from the Texas Instruments reference
design in SLOA247C.  I've brought a few pins out unnecessarily, in
case bodge wires are needed, but they will be more firmly grounded in
future designs.

For the antenna tuning, I don't really know what I'm doing.  Pull
requests are welcome.

--Travis
