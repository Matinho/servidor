//#include <sys/types.h>
#include <sys/mman.h>
#include <err.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Does not work on OS X, as you can't mmap over /dev/zero */
int main(void)
{
  int numero1[3];
  numero1[1]=10;
  numero1[2]=20;
  numero1[0]=5;

  int parpid = getpid(), childpid;
  int fd = -1;
  int  *anon, *zero;

  if ((fd = open("/dev/zero", O_RDWR, 0)) == -1)
          err(1, "open");

  anon = mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_ANON|MAP_SHARED, -1, 0);
  zero = mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);

  if (anon == MAP_FAILED || zero == MAP_FAILED)
          errx(1, "either mmap");

  anon[0]=numero1[0];
  anon[1]=numero1[1];
  anon[2]=numero1[2];
  *zero=numero1[1];

  printf("PID %d:\tanonymous %d, zero-backed %d\n", parpid,anon[1], *zero);
  switch ((childpid = fork())) {
  case -1:
          err(1, "fork");
          /* NOTREACHED */
  case 0:
          childpid = getpid();
          printf("PID %d:\tanonymous %d, zero-backed %d\n", childpid, anon[2], *zero);
          sleep(3);

          printf("PID %d:\tanonymous %d, zero-backed %d\n", childpid, anon[0], *zero);
          munmap(anon, 4096);
          munmap(zero, 4096);
          close(fd);
          return EXIT_SUCCESS;
  }

  sleep(2);
// *anon=numero1[1];
// *zero=numero1[1];

  printf("PID %d:\tanonymous %d, zero-backed %d\n", parpid, anon[1], *zero);
  munmap(anon, 4096);
  munmap(zero, 4096);
  close(fd);
  return EXIT_SUCCESS;
}
