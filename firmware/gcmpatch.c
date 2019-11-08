/* This is a patch that runs inside of the RF430TAL152H tags used in
   glucose monitoring solutions.  It is intended for scientific use,
   and under no circumstances should you use it in real healthcare.
   
   Caveats: 
   
   In this example, we have no main() and therefore static and global
   variables are not initialized.
   
   This runs on a real tag, replacing the manufacturer's own code
   section.  To install it, you must first unlock the tag.

 */


//TODO Addition command for raw_read().
//TODO All stock commands.
//TODO Test in a real sensor.
//TODO 


#include <rf430frl152h.h>
#include <stdint.h>
#include "rom.h"



/* The A1 vendor function is called first, and it takes no parameters.
   Test it by sending "02A107" as the reader does.
 */
uint16_t __attribute__ ((noinline)) cmd_a1(){
  /* For now, just send back what a real tag would.  We'll figure out
     what these bytes mean later. */
  
  RF13MTXF_L=0;    //Success
  RF13MTXF=0x00DF;
  RF13MTXF=0x08;  //FIXME: Harded to israel, ought to be read from memory.
  RF13MTXF=0x0000;

  
  return 0;
}

/* After some stuff has been initialized and both earlydata and
   gcmdata have been read, the A0 command is called to initialize the sensor.
 */
uint16_t __attribute__ ((noinline)) cmd_a0(){
  //These two parameters are a 32-bit password.
  volatile uint16_t param0, param1;
  param0=RF13MRXF; //0xadc2
  param1=RF13MRXF; //0x2175
  
  /* For now, just send back what a real tag would.  We'll figure out
     what these bytes mean later. */
  RF13MTXF_L=0;      //Success
  RF13MTXF=0x00DC;
  RF13MTXF=0x0003;

  
  return 0;
}

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

  //These two parameters are a 32-bit password.
  volatile uint16_t param0, param1;
  param0=RF13MRXF; //0xadc2
  param1=RF13MRXF; //0x2175


  //Then we grab a 16-bit address, and finally an 8-bit length.
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
   (uint16_t) cmd_a3, 0x00A3, //Handler address and command number.
   (uint16_t) cmd_a0, 0x00A0, //Handler address and command number.
   (uint16_t) cmd_a1, 0x00A1, //Handler address and command number.
   0xCECE,  //This ABSOLUTELY MUST be at 0xFFCE or your patch won't load.
  };


