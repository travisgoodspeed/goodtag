/*! \file rom.h
  \author Travis Goodspeed
  \brief quick definitions for RF430FRL152H ROM functions.

  The RF430FRL152H has an 8kB mask ROM that already includes many
  standard functions.  Rather than waste our precious FRAM code memory
  with reproducing them, we'll call the original functions wherever
  possible.
  
  Symbol addresses are defined in rom/symbols.ld of the goodtag
  repository.  So far as we know from dumping and from TI's examples,
  there is only one version of the ROM in production chips.

*/

void ROM_RESET();
