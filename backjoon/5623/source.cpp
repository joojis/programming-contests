#include <bits/stdc++.h>

int main ()
{
  int N;
  int A[2][1000], tt;
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      int t;
      scanf("%d", &t);
      if (j == (i+1)%N) {
        if (i == 0) {
          tt = t;
        } else {
          if (N > 2) {
            printf("%d ", ((A[(i+1)%2][j]+A[(i+1)%2][(j-1+N)%N])-t)/2);
          }
#ifdef _DEBUG
          printf("..... A[%d] + A[%d]\n", j, (j-1+N)%N);
#endif
        }
      }
      A[i%2][j] = t;
    }
  }
  if (N > 2) {
    printf("%d\n", (A[(N-1)%2][0]+A[(N-1)%2][1]-tt)/2);
  } else { // if N == 2
    printf("%d %d\n", A[1][0] / 2, A[1][0] / 2);
  }

  return 0;
}
