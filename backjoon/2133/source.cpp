#include <bits/stdc++.h>

int main ()
{
  int N;
  int K = 3;
  int P = 1 << K;
  int A[40][2050] = {0,};
  scanf("%d", &N);

  A[0][P-1] = 1;
  for (int i=1; i<=N; i++) {
    for (int j=0; j<P; j++) {
      int invJ = j ^ (P-1);
      A[i][invJ] += A[i-1][j];
      for (int k=3; k<P-1; k<<=1) {
        if ((invJ&k) == 0) {
          A[i][invJ|k] += A[i-1][j];
        }
      }
    }
#ifdef _DEBUG
    for (int j=0; j<8; j++) {
      printf("A[%d][%d] = %d\n", i, j, A[i][j]);
    }
#endif
  }
  printf("%d\n", A[N][P-1]);
  return 0;
}
