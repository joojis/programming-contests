#include <bits/stdc++.h>

void solveCase ()
{
  bool check[1001] = { 0, };
  int N;
  int A[1001];
  scanf("%d", &N);
  for (int i=1; i<=N; i++) {
    scanf("%d", A+i);
  }
  int answer = 0;
  for (int i=1; i<=N; i++) {
    if (check[i]) {
      continue;
    }
    answer++;
    int k = i;
    do {
      check[k] = true;
      k = A[k];
    } while (!check[k]);
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
