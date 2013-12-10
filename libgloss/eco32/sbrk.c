/* Version of sbrk for no operating system.  */

#include "config.h"
#include <_syslist.h>

void *
_sbrk (incr)
     int incr;
{ 
   extern unsigned int   _ebss; /* Set by crt0.s.  */
   static unsigned int * heap_end  = & _ebss;; 
   unsigned int *        prev_heap_end; 

   prev_heap_end = heap_end; 
   incr = (incr + 3) / 4;
   heap_end += incr; 

   return (void *) prev_heap_end; 
} 
