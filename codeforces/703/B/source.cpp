#include <bits/stdc++.h>

using namespace std;

void solveCase()
{
  int N, M;
  cin >> N >> M;

  int C[100000];
  int isCapital[100000] = {0,};
  int isCounted[100000] = {0,};
  vector<int> caps;
  for (int i=0; i<N; i++) {
    cin >> C[i];
  }

  if (N == 2) {
    cout << C[0] * C[1] << endl;
    return;
  }

  for (int i=0; i<M; i++) {
    int k;
    cin >> k;
    isCapital[k-1] = 1;
    caps.push_back(k-1);
  }

  long long int sum = 0;
  long long int answer = 0;
  for (int i=0; i<N; i++) {
    sum += C[i];
    answer += C[i] * C[(i+1)%N];
  }

  int capsSum = 0;
  for (int i=0; i<caps.size(); i++) {
    int curr = caps[i];
    int next = (curr + 1) % N;
    int prev = (curr + N - 1) % N;

    capsSum += C[curr];
    isCounted[curr] = 1;

    long long int targetSum = sum - C[prev] - C[next] - capsSum;
    if (isCapital[prev] && isCounted[prev]) {
      targetSum += C[prev];
    }
    if (isCapital[next] && isCounted[next]) {
      targetSum += C[next];
    }

    answer += targetSum * C[curr];
  }

  cout << answer << endl << endl;
}

int main()
{
#ifdef _DEBUG
  int T;
  scanf("%d\n", &T);
  while (T--) {
#endif
    solveCase();
#ifdef _DEBUG
  }
#endif
  return 0;
}
