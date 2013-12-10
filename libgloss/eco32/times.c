/*
 * Stub version of times.
 */

#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <sys/times.h>
#include <errno.h>
#undef errno
extern int errno;

clock_t
_DEFUN (_times, (buf),
        struct tms *buf)
{
  errno = EACCES;
  return  -1;
}
