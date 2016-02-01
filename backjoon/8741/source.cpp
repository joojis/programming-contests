#include <stdio.h>

int main ()
{
  int N;
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    printf("1");
  }
  for (int i=1; i<N; i++) {
    printf("0");
  }
  return 0;
}
