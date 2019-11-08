/* This handly little application is an example NDEF RFID tag,
   implemented by disabling the ROM sensor, choosing 4-byte pages, and
   placing the NDEF bytes at the beginning of the contents.

   The data functions as a wrapper for the NDEF tag data that can be
   produced by ndeftool or libndef's ndef-encode, but the length *must*
   be correct or the reader will reject it.
   
   If you also needed the advanced ROM functions, you could enable
   them by hooking the read functions to keep the NDEF data away from
   the ROM's control registers.
   
   Caveats: 
   
   In this example, we have no main() and therefore static and global
   variables are not initialized.
   
   The NDEF data isn't write protected.  That could be added when
   flashing by JTAG, but can't yet fit within the TI-TXT format for
   OTA flashing.

 */


#include <rf430frl152h.h>
#include <stdint.h>
#include "rom.h"


/* We need to specify the Firmware Control Byte, which decides such
   things as the block size and whether the ROM is handling the sensor
   acquisition, or just the networking stack. */
__attribute__((section(".firmwarecontrolbyte")))
const uint8_t firmwarecontrolbyte = 0x42; //4-byte pages, no ROM sensor support.


/* And we need to load the NDEF tag to early FRAM. */
__attribute__((section(".earlyrom")))
const uint8_t ndefdata[] = {
  
  // Block 0
  0xE1,           // NDEF Magic Number, E1 means no fancy features.
  0x40,           // Version Number, read/write access conditions.
  0x40,           // Total formattable size, I think.
  0x00,           // Keep this zeroed.
  
  // Block 1 begins.
  0x03,           // NDEF Message present
  0x1F,           // Length of the NDEF message.
  

  //The actual NDEF message begins here:
  //ndeftool uri https://github.com/travisgoodspeed | hexdump
  0xd1, 0x01, 0x1b, 0x55, 0x04, 0x67, 0x69, 0x74, 0x68, 0x75, 0x62, 0x2e, 0x63, 0x6f, 0x6d, 0x2f,
  0x74, 0x72, 0x61, 0x76, 0x69, 0x73, 0x67, 0x6f, 0x6f, 0x64, 0x73, 0x70, 0x65, 0x65, 0x64,
  

  
  // We follow with a terminator, which is not a part of the length or
  // the data above.
  0xFE,           // TLV terminator
};


/* We could place more code into later sections, of course.  Quickly
   hooking the read functions would allow the NDEF to change with each
   read.
 */
