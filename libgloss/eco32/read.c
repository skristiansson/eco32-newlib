/*
 * Stub version of read.
 */

#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <unistd.h>
#undef errno
extern int errno;

static void mywritea(char c)
{
  volatile unsigned int *base;

  if (c == '\n') {
    mywritea('\r');
  }
  base = (unsigned int *) 0xF0300000;
  while ((*(base + 2) & 1) == 0) ;
  *(base + 3) = c;
}

static char myread(void)
{
  volatile unsigned int  *base = (unsigned int*) 0xF0300000;
  char c;
  while ((*(base + 0) & 1) == 0) ;
  c = (char) *(base + 1);
  if (c == '\r') {
    c = '\n';
  }
  mywritea(c);
  return c;
}

int
_DEFUN (_read, (file, ptr, len),
        int   file  _AND
        char *ptr   _AND
        int   len)
{
if (STDIN_FILENO == file)
  {
    int i;
    for(i=0; i<len; i++)
    {
      ptr[i]=myread();
      if('\n'==ptr[i])
      {
        return i+1;
      }
        
    }
    return i;
  }
  else
  {
    errno = EBADF;
    return  -1;
  }
}
