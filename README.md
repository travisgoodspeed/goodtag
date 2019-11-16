# GoodTag

Howdy y'all!

For a long while I've been interested in the RF430FRL152H, which is a
passive RFID tag for 13.56 MHz built around an MSP430 microcontroller.
As few open source examples were available, I found myself first
building a development kit

In this repository, and its
[wiki](https://github.com/travisgoodspeed/goodtag/wiki), you will find
examples and documentation for programming this fine chip, as well as
CAD for hardware boards that use the chip.  This should help you build
your own NFC Type V (ISO 15693) sensor tags, or to emulate existing ones.

This project cannot implement ISO 7816 or ISO 14443 interfaces of
older NFC tags.  For that, you probably need a board designed around
the LPC8N04 or some other microcontroller.

It has partial support for the RF430TAL152H chip found in some medical
devices, written as part of a research project with Axelle Apvrille,
which we presented as [The Inner Guts of a Connected Glucose Sensor
for
Diabetes](https://github.com/cryptax/talks/blob/master/BlackAlps-2019/glucose-blackalps2019.pdf)
at BlackAlps 2019.

73 from Yverdon les Bains,

--Travis Goodspeed

## Getting Started

A tutorial on building a first project will be added to the [GoodTag
Wiki](https://github.com/travisgoodspeed/goodtag/wiki) as soon as I
find time.  You will need an assembled board, a Linux shell account,
and a recent Android phone, such as the Pixel 3.

## Toolchain

The C examples in this project *must* be compiled with TI's branch of
[GCC for
MSP430](http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSPGCC/latest/index_FDS.html).
We sadly cannot be compatible with the GCC4 branch shipped with Debian
because the function calling conventions are incompatible with the
mask ROM.  You will need both the toolchain and its support files.

See my [GoodV](https://github.com/travisgoodspeed/GoodV) project for
an example Android app that communicates with the chip over NfcV.  It
can write firmware to the tags in the TI-TXT format, as well as dump
their existing contents.

For convenient programming from Linux, the [GreatFET
Hydrangea](https://github.com/travisgoodspeed/hydrangea/) board ought
to be handy.  We'll tie it into the `Makefile` once that project is
functional.

## Documentation

An extensive [goodtag
wiki](https://github.com/travisgoodspeed/goodtag/wiki) covers such
nifty topics as the
[RF430FRL152H](https://github.com/travisgoodspeed/goodtag/wiki/RF430FRL152H)
chip, the contents of [its
ROM](https://github.com/travisgoodspeed/goodtag/wiki/ROM), and the use
of its brother, the otherwise undocumented
[RF430TAL152H](https://github.com/travisgoodspeed/goodtag/wiki/RF430TAL152H).


## Firmware

In the `firmware/` directory, you will be find a few example projects.
Most of them are designed to compile as patches to the ROM, hooking
NFC commands rather than being called through the `RESET` vector, so
it's important to remember that global and static variables will *not*
be initialized.

You will probably want to start with `hello.c` and then add your own
vendor extension commands.  `gcmemu.c` is an unfinished emulator for
a commercial glucose sensor tag, and `ndef.c` is an NFC business card
in the NDEF format, which can be read by the
[Decode](https://apps.apple.com/us/app/decode-nfc-scanner/id964303354)
app on an iPhone.

Unlike large applications in which multiple modules are linked
together, this project is organized as individually executable modules
that share no code with one another.  This is considered necessary,
given the pitiful amounts of FRAM code memory.

## Shellcode

In the `shellcode/` directory, you will find short examples of code
that can be run ephemerally from SRAM, without permanent changes to
the target.  See the [Shellcode
page](https://github.com/travisgoodspeed/goodtag/wiki/Shellcode) of
the wiki for a more detailed explanation.

## Hardware Designs

For development, I began by using the
[RF430FRL152HEVM](http://www.ti.com/tool/RF430FRL152HEVM) and
[RF430-TMPSNS-EVM](http://www.ti.com/tool/RF430-TMPSNS-EVM) kits from
Texas Instruments.

As these are now in short supply, I've designed the
[GoodTag11](https://github.com/travisgoodspeed/goodtag/wiki/GoodTag11)
in Kicad as my own development kit.  Expect future designs in this
series.

## Related Projects

[GoodV](https://github.com/travisgoodspeed/GoodV) is an Android app
for interacting with RF430FRL152H devices.  You will probably develop
first with JTAG and then use this to flash your code from a handy
phone.

[The GoodTag Wiki](https://github.com/travisgoodspeed/goodtag/wiki)
contains plenty of documentation about the RF430FRL152H and related
chips.



