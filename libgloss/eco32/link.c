/*
 * Stub version of link.
 */

#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#undef errno
extern int errno;

int
_DEFUN (_link, (existing, new),
        char *existing _AND
        char *new)
{
  errno = EMLINK;
  return -1;
}

