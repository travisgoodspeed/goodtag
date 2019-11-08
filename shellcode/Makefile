# You *MUST* use TI's branch of GCC8.  GCC4 as distributed with Debian
# uses a different calling convention and is not compatible with the
# RF430FRL152H's ROM functions.


# So memory is *very* tight and the FRAM is really more of a patch
# against the main ROM, so rather than link together a complete
# executable with an entry point and RESET vector, we just link all
# the functions together with no start files and then use an addition
# to TI's TXT format to mark the entry point of the shellcode.

# As a rule, one .c file becomes one .txt shellcode.

# GCC 8.2
CC= msp430-elf-gcc -mmcu=rf430frl152h -Wall \
	-I. -I/opt/msp430-gcc-support-files/include -Os -Wl,--no-gc-sections \
	-I../firmware/ \
	-T rf430frl152h-shellcode.ld -nostartfiles


APPS = example.txt memcpy.txt

all: $(APPS)


## General linking for applications.
%.elf: %.c
	$(CC)  $(CFLAGS) $< -o $@

%.hex: %.elf
	msp430-elf-objcopy $< -O ihex $@
%.txt: %.hex
	srec_cat $< -Intel -Output $@ -Texas_Instruments_TeXT

.PHONY: clean
clean:
	rm -f *.elf *.hex *.txt
