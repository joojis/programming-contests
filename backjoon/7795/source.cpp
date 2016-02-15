#include <bits/stdc++.h>

void solveCase()
{
  int N, M;
  scanf("%d %d", &N, &M);
  int A[20000], B[20000];
  for (int i=0; i<N; i++) {
    scanf("%d", A+i);
  }
  for (int i=0; i<M; i++) {
    scanf("%d", B+i);
  }
  std::sort(B, B+M);

  int answer = 0;
  for (int i=0; i<N; i++) {
    answer += std::lower_bound(B, B+M, A[i]) - B;
  }
  printf("%d\n", answer);
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
