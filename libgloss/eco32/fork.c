/*
 * Stub version of fork.
 */

#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#undef errno
extern int errno;

int
_DEFUN (_fork, (),
        _NOARGS)
{
  errno = EAGAIN;
  return -1;
}
