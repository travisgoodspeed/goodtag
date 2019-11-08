/* This is an empty shellcode example for the rf430frl152h, which you
   might use as an example for your own projects and patches.  It is
   designed not for permanent placement in the FRAM, but to run
   temporarily as shellcode from within SRAM by a temporary patch of
   the command handler functions.
   
   See the goodtag wiki for a clean example of how this should behave.
   
   https://github.com/travisgoodspeed/goodtag/wiki/Shellcode
*/


#include <rf430frl152h.h>
#include <stdint.h>
#include "rom.h"

volatile uint32_t array[64];

/* This replacement function needs to send two bytes for re-entry, as it
   is replacing the error command handler.
 */

void __attribute__ ((noinline)) shellcode_main(){
  int i;

  //Fills up a RAM array for no reason.
  for(i=0;i<64;i++)
    array[i]=0xFFFFFFFF;

  //Send two bytes for continuation.
  RF13MTXF=1;
  
  return;
}

