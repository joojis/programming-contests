#include <stdio.h>

int abs(int x) { return x > 0 ? x : -x; }

int main ()
{
  int L, C, N;
  scanf("%d %d %d", &L, &C, &N);
  for (int i=0; i<C; i++) {
    int S, P;
    scanf("%d %d", &S, &P);
    printf("%d\n", abs(N-P) + S);
  }
  return 0;
}
