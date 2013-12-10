/* Supply a definition of errno if one not already provided.  */

#include <errno.h>
#undef errno
extern int errno;
