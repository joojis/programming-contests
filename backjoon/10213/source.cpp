#include <bits/stdc++.h>

using namespace std;

void solveCase ()
{
  int N;
  scanf("%d", &N);
  vector<int> answer(N);
  stack<pair<long long int, int> > stk;
  for (int i=0; i<N; i++) {
    long long int sum;
    scanf("%lld", &sum);
    int count = 1;
    while (!stk.empty() && stk.top().first * count > sum * stk.top().second) {
      sum += stk.top().first;
      count += stk.top().second;
      stk.pop();
    }
    stk.push(make_pair(sum, count));
    answer[i] = stk.top().second;
  }

  int Q;
  scanf("%d", &Q);
  for (int i=0; i<Q; i++) {
    int t;
    scanf("%d", &t);
    printf("%d ", answer[t-2]);
  }
  printf("\n");
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
