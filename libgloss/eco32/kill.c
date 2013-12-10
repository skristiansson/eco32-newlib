/*
 * Stub version of kill.
 */

#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#undef errno
extern int errno;

int
_DEFUN (_kill, (pid, sig),
        int pid  _AND
        int sig)
{
  errno = EINVAL;
  return -1;
}
