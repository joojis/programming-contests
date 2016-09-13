#include <bits/stdc++.h>

using namespace std;

void solveCase()
{
  int N;
  ios::sync_with_stdio(false);
  cin >> N;
  vector<int> A(N+1, 0);
  for (int i=0; i<N; i++) {
    cin >> A[i];
  }
  for (int i=0; i<N; i++) {
    cout << A[i] + A[i+1] << " ";
  }
}

int main ()
{
  solveCase();
  return 0;
}
