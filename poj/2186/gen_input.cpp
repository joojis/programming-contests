#include <stdio.h>

int main()
{
  int N = 10000;
  int M = 9999;

  printf("%d %d\n", N, M);
  for (int i = 0; i < M; i++) {
    printf("%d %d\n", i + 1, i + 2);
  }

  return 0;
}
