#include <stdio.h>

void solveCase()
{
  int H, W, N;
  scanf("%d %d %d", &H, &W, &N);
  printf("%d%02d\n", (N % H) == 0 ? H : (N % H), (N + H - 1) / H);
}
int main ()
{
  int T;
  scanf("%d", &T);
  while (T--) {
    solveCase();
  }
  return 0;
}
