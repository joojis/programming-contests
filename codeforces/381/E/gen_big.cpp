#include <stdio.h>

int main()
{
  for (int i=0; i<1000000; i++) {
    printf("%c", i < 500000 ? '(' : ')');
  }
  printf("\n");

  int N = 10;
  printf("%d\n", N);
  for (int i=0; i<N; i++) {
    printf("%d %d\n", i+1, i+10);
  }
  return 0;
}
