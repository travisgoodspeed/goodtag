/* This is a bare bones application for the rf430frl152h, which you
   might use as an example for your own projects and patches.  It
   hooks the vendor-proprietary A3 command to provide for a raw-read
   function, and places that command into the command table.

   Remember that we only have 2kB of FRAM, so you must be *very*
   conservative in how your code works.  If you call printf("hello"),
   you will overflow all of available code memory three or four times!
   Every byte counts, and two kilobytes are your entire budget.
   
   There are some saving graces, though.  The chip includes an 8kB ROM
   region, whose functions we can reuse and call back into.

   There is also a patch table, which allows us to add new NFC
   commands or even to patch the ROM functions.
   
   Caveats: 
   
   In this example, we have no main() and therefore static and global
   variables are not initialized.
   
 */


#include <rf430frl152h.h>
#include <stdint.h>
#include "rom.h"


/* We need to specify the Firmware Control Byte, which decides such
   things as the block size and whether the ROM is handling the sensor
   acquisition, or just the networking stack. */
__attribute__((section(".firmwarecontrolbyte")))
const uint8_t firmwarecontrolbyte = 0x7F; //8-byte pages, no ROM sensor support.


/* This vendor function allows for a raw read of words from an
   address.  It is roughly like the A3 command found in the
   RF430TAL152H devices.
   
   To try it, 'make hello.txt' and then flash it using GoodV.  Then
   use NFC Tools to send "02:a3:07:FEFF:01" by NfcV, which ought to
   result in "00:12:50".  The value at FFFE is 5012.
 */
uint16_t __attribute__ ((noinline)) cmd_a3(){
  uint16_t *adr;
  uint8_t words;

  //First we grab a 16-bit address, then an 8-bit length.
  adr=(uint16_t*) RF13MRXF;
  words=RF13MRXF_L;

  if(words<16){
    //Zero byte for success.
    RF13MTXF_L = 0;

    //Then the data.
    while(words){
      RF13MTXF = *adr;
      adr++;
      words--;
    }
  }else{
    //One for failure.
    RF13MRXF=1;
  }
  
  return 0;
}



/* And we need a patch table, and it has very strict rules about
   placement and alignment.

   1) The patch table is read backward from the start marker CECE at 0xFFCE.
   2) It must end with CECE after all valid records. (Lower address.)
   3) Entries  < 0x0100 are command hooks.
   4) Entries >= 0x0100 are patches to the ROM hook table.
*/

__attribute__((section(".rompatch")))
const uint16_t patchtable[0x12] =
  {
   0xCECE, 
   0xCECE, 0xCECE,
   0xCECE, 0xCECE,
   0xCECE, 0xCECE,
   0xCECE, 0xCECE,
   0xCECE, 0xCECE,
   0xCECE, 0xCECE,
   0xCECE, 0xCECE,
   
   (uint16_t) cmd_a3, 0x00A3, //Handler address and command number.
   0xCECE,  //This ABSOLUTELY MUST be at 0xFFCE or your patch won't load.
  };


