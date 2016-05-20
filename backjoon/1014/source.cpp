#include <bits/stdc++.h>

void solveCase()
{
  int M, N;
  scanf("%d %d\n", &M, &N);

  int K[1024] = { 0, };
  for (int i=0; i<(1<<M); i++) {
    int k = i;
    while (k) {
      K[i] += k & 1;
      k /= 2;
    }
  }

  int A[11][11] = { 0, };
  int O[11] = { 0, };

  for (int i=1; i<=M; i++) {
    for (int j=1; j<=N; j++) {
      scanf("%c", A[i] + j);
      if (A[i][j] == 'x') {
        O[j] += 1 << (i-1);
      }
    }
    scanf("\n");
  }

  int R[11][1024] = { 0, };
  for (int j=1; j<=N; j++) {
    for (int k=0; k<(1<<M); k++) {
      if (k & O[j]) continue;
      for(int l=0; l<(1<<M); l++) {
        int lll = (((l<<1) | l | (l>>1)) & ((1<<M)-1));
        if (lll & k) continue;
        if (R[j][k] < R[j-1][l] + K[k]) {
          R[j][k] = R[j-1][l] + K[k];
        }
      }
    }
  }

  int answer = -1;
  for (int i=0; i<(1<<M); i++) {
    answer = std::max(answer, R[N][i]);
  }
  printf("%d\n", answer);
}

int main ()
{
  int T;
  scanf("%d\n", &T);
  while (T--) {
    solveCase();
  }
  return 0;
}
