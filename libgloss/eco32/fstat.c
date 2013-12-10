/*
 * Stub version of fstat.
 */

#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#undef errno
extern int errno;


int
_DEFUN (_fstat, (file, st),
        int          file _AND
        struct stat *st)
{
  if ((STDOUT_FILENO == file) || (STDIN_FILENO == file) || (STDERR_FILENO == file))
      {
        st->st_mode = S_IFCHR;
        return  0;
  } else
      {
        errno = EBADF;
        return  -1;
  }
}

