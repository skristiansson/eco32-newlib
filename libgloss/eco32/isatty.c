/*
 * Stub version of isatty.
 */

#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <unistd.h>
#undef errno
extern int errno;

int
_DEFUN (_isatty, (fd),
        int fd)
{
  if ((STDOUT_FILENO == fd) || (STDIN_FILENO == fd) || (STDERR_FILENO == fd))
      {
        return  1;
  } else
      {
        errno = EBADF;
        return  -1;
  }
}
