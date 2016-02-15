#include <bits/stdc++.h>

using namespace std;

vector<int> getLis(vector<int> v)
{
  vector<int> lis(v.size(), 987654321);
  vector<int> result(v.size());
  for (unsigned i=0; i<v.size(); i++) {
    int t = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
    lis[t] = v[i];
    result[i] = t + 1;
  }
#ifdef _DEBUG
  for (unsigned i=0; i<result.size(); i++) {
    printf("%d ", result[i]);
  }
  printf("\n");
#endif
  return result;
}

int main ()
{
  int N;
  scanf("%d", &N);
  vector<int> A(N);
  for (int i=0; i<N; i++) {
    scanf("%d", &A[i]);
  }
  vector<int> L = getLis(A);

  reverse(A.begin(), A.end());
  vector<int> R = getLis(A);
  reverse(R.begin(), R.end());

  int answer = 0;
  for (int i=0; i<N; i++) {
    answer = max(answer, L[i] + R[i] - 1);
  }
  printf("%d\n", answer);
  return 0;
}
