/* This is an attempt at an emulator for a gluecose monitor tag,
   re-implementing their protocol well enough to work with a reader.
   It doesn't yet work for reads, but it can be initialized by the
   standalone reader.
   
   Caveats: 
   
   In this example, we have no main() and therefore static and global
   variables are not initialized.
   
   Our tag is not write protected, and we do not forge the serial number
   of a real tag.

 */


//GCM constants.
#define USA10DAY    0x02
#define ISRAEL14DAY 0x08

#define STATE_FRESH    0x01
#define STATE_WARMUP   0x02
#define STATE_WORKING  0x03
#define STATE_EXPIRED  0x04
#define STATE_SHUTDOWN 0x05
#define STATE_FAILURE  0x06


//Configuration
#define CONFIG_COUNTRY ISRAEL14DAY
#define CONFIG_STATE STATE_WORKING

#include <rf430frl152h.h>
#include <stdint.h>
#include "rom.h"



/* We need to specify the Firmware Control Byte, which decides such
   things as the block size and whether the ROM is handling the sensor
   acquisition, or just the networking stack. */
__attribute__((section(".firmwarecontrolbyte")))
const uint8_t firmwarecontrolbyte = 0x7f; //8-byte pages, no ROM sensor support.


/* And we need to load the NDEF tag to early FRAM. */
__attribute__((section(".earlyrom")))
const uint8_t earlydata[] = {
  /* In the future, we'll fake specific values here, but for now we
     just duplicate those of a real tag.
   */


  /*---CRC---             STATE */
  0x3d, 0xc7, 0x88, 0x13, CONFIG_STATE, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,         0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,         0x00, 0x00, 0x00, 0x00,
  0x62, 0xc2, 0x00, 0x00,         0x00, 0x00, 0x00, 0x00
};


/* And we need to load the NDEF tag to early FRAM. */
__attribute__((section(".gcmdata")))
const uint8_t gcmdata[] = {
  /* In the future, we'll fake specific values here, but for now we
     just duplicate those of a real tag.
   */
  0x83, 0x4C, 0x00, CONFIG_COUNTRY, 0x33, 0x08, 0x44, 0x51,
  0x14, 0x07, 0x96, 0x80,           0x5A, 0x00, 0xED, 0xA6,
  0x12, 0x89, 0x1A, 0xC8,           0x04, 0x5D, 0x99, 0x6F
};

/* We need to calculate and correct checkums, but there is a hardware
   accelerator to take care of this.
 */
uint16_t crc_calculate(uint16_t *src, uint16_t wordcount){
  uint16_t count;

  //Initialize the CRC engine.
  CRCINIRES=0xFFFF;

  //Feed each 16-bit word to the engine.
  for(count=0; count<wordcount; count++){
    CRCDI=src[count];
  }

  //Return the result.
  return CRCINIRES;
}

/* Fixes the checksums expected by the reader. */
void crc_fixup(){
  /* The real tag expects these checksums, but our address space is
     different in the FRL152.

  f860 = crc(0xF862, 0xB);
  f878 = crc(0xF87A, 0x93);
  */

  SYSCNF_H &= 0xF0;//Unlock FRAM

  //Calculate new checksums.
  *((uint16_t*) (0xF860-8)) = crc_calculate((uint16_t*) (0xF862-8), 0xB);
  *((uint16_t*) (0xF878-8)) = crc_calculate((uint16_t*) (0xF87A-8), 0x93);
  
  SYSCNF_H |= 0x0F;//Lock FRAM
}


/* The A1 vendor function is called first, and it takes no parameters.
   Test it by sending "02A107" as the reader does.
 */
uint16_t __attribute__ ((noinline)) cmd_a1(){
  /* For now, just send back what a real tag would.  We'll figure out
     what these bytes mean later. */
  
  RF13MTXF_L=0;    //Success
  RF13MTXF=0x00DF;
  RF13MTXF=CONFIG_COUNTRY;  //Must match the reader!
  RF13MTXF=0x0000;

  crc_fixup(); //Fix the CRCs.
  
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

  crc_fixup(); //Fix the CRCs.
  
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


