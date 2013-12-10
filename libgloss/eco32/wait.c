/*
 * Stub version of wait.
 */

#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#undef errno
extern int errno;

int
_DEFUN (_wait, (status),
        int  *status)
{
  errno = ECHILD;
  return -1;
}
