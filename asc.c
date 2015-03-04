#include <stdio.h>
void f(unsigned long long d) {
  int loop = sizeof(unsigned long long)  * 8;
  // 8 bytes == 64 bits
  printf("Loop: %d\n", loop);
  unsigned long long temp = d;
  while (loop > 0) {
    printf("%llu\n", temp);
    temp = (temp << 1) + 0b1;
    loop--;
  }
}

int main(void) {
  f(0b1);
  //                           1 152 921 504 606 846 976
  // max unsigned long long : 18 446 744 073 709 551 615
  printf("0xff ff ff ff ff ff ff ff = %llu\n",  (unsigned long long) 0xffffffffffffffff);
  return 0;
}
