/*
 * Stub version of lseek.
 */

#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <unistd.h>
#undef errno
extern int errno;

int
_DEFUN (_lseek, (file, ptr, dir),
        int   file  _AND
        int   ptr   _AND
        int   dir)
{
  if ((STDOUT_FILENO == file) || (STDERR_FILENO == file))
  {
    return 0;
  } 
  else
  {
    errno = EBADF;
    return -1;
  }
}
