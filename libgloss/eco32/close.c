/*
 * Stub version of close.
 */

#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#undef errno
extern int errno;


int
_DEFUN (_close, (fildes),
        int fildes)
{
  errno = EBADF;
  return -1;
}
