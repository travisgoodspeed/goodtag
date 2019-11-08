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
#include <string.h>

#include "rom.h"



/* Parameters are loaded to 1E02 by the linker.  We take three 16-bit
   words as little endian there for destination, source, and length.
 */
__attribute__((section(".params")))
uint16_t params[3];


/* This little bit of shellcode calls memcpy() with the given
   parameters, returning 0 on success and non-zero on failure.
 */
void __attribute__ ((noinline)) shellcode_main(){
  //Do the memcpy() itself.
  memcpy((void*) params[0], (void*) params[1], params[2]);

  //Return the success or failure as two bytes for proper continuation.
  RF13MTXF=memcmp((void*) params[0], (void*) params[1], params[2]);
  
  return;
}

