#include <stdio.h>

int main ()
{
  int N = 100000;
  printf("1\n");
  printf("%d 0\n", N);
  for (int i=0; i<N; i++) {
    printf("%d ", i % 20000 + 1);
  }
  return 0;
}
