#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/user.h>

// 00 40 07 70 -> 70 07 40 00
char * sc = "\xb8\x01\x00\x00\x00\xbf\x01\x00\x00\x00\x48\xbe\x70\x07\x40\x00\x00\x00\x00\x00\xba\x0b\x00\x00\x00\x0f\x05\xb8\x3c\x00\x00\x00\xbf\x00\x00\x00\x00\x0f\x05";


static char * helloworld = "helloworld\n";

int main(void) {

  void * blah = 0x400770;
  fprintf(stdout, "0x%x\n", (void *) helloworld);
  //fprintf(stdout, "%s", blah);
  write(1, blah, 0xb);

  void * page_start = (unsigned int) sc & ~(PAGE_SIZE - 1);
  mprotect((void *) page_start, PAGE_SIZE, PROT_READ | PROT_EXEC | PROT_WRITE);

  printf("\nafter mprotect()\n");
  (*(int(*)())sc)();
  return 0;
}
