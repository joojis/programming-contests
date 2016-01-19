#include <stdio.h>

void solveCase ()
{
  printf("1\n");
  int M, N;
  scanf("%d %d", &M, &N);
  if (M == 1) {
    for (int n=0; n<N; n++) {
      printf("(%d,%d)\n", 0, n);
    }
    return;
  }

  for (int n=0; n<N; n++) {
    printf("(%d,%d)\n", 0, n);
  }
  int direction = 1;
  for (int n=N-1; n>=0; n--) {
    for (int m=direction == 1 ? 1 : M-1; 1 <= m && m < M; m += direction) {
      printf("(%d,%d)\n", m, n);
    }
    direction *= -1;
  }
}
int main ()
{
  int N;
  scanf("%d", &N);
  while (N--) {
    solveCase();
  }
  return 0;
}
