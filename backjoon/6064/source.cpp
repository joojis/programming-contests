#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b)
{
  // assert(a>b);
  return b == 0 ? a : GCD(b, a%b);
}

void solveCase()
{
  int M, N, x, y;
  scanf("%d %d %d %d", &M, &N, &x, &y);
  int gcd = GCD(max(M, N), min(M, N));

#ifdef _DEBUG
  printf("GCD: %d\n", gcd);
#endif

  int k = x;
  while (k <= (M / gcd) * N) {
    if (k % N == y % N) {
      printf("%d\n", k);
      return;
    }
    k += M;
  }

  printf("-1\n");
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
