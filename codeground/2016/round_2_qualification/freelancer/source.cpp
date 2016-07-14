#include <bits/stdc++.h>

using namespace std;

void solveCase()
{
  int N;
  int P[10001], Q[10001];
  int A[10001];
  cin >> N;
  for (int i=1; i<=N; i++) {
    cin >> P[i];
  }
  for( int i=1; i<=N; i++) {
    cin >> Q[i];
  }

  A[0] = 0;
  A[1] = max(P[1], Q[1]);

  for (int i=2; i<=N; i++) {
    A[i] = max(A[i-1] + P[i], A[i-2] + Q[i]);
  }

  cout << A[N] << endl;
}

int main()
{
  int T;
  scanf("%d\n", &T);
  for (int i=1; i<=T; i++) {
    printf("Case #%d\n", i);
    solveCase();
  }

  return 0;
}
