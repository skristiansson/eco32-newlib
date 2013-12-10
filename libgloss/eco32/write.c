/*
 * Stub version of write.
 */

#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <unistd.h>
#undef errno
extern int errno;

static void mywrite(char c)
{
  volatile unsigned int *base;

  if (c == '\n') {
    mywrite('\r');
  }
  base = (unsigned int *) 0xF0300000;
  while ((*(base + 2) & 1) == 0) ;
  *(base + 3) = c;
}

int
_DEFUN (_write, (file, ptr, len),
        int   file  _AND
        char *ptr   _AND
        int   len)
{
  if (STDOUT_FILENO == file || STDERR_FILENO == file)
  {
    int i;
    for(i=0; i<len; i++)
    {
      mywrite(ptr[i]);
    }
    return len;
  }
  else
  {
    errno = EBADF;
    return  -1;
  }
}

