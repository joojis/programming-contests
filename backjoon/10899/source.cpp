#include <bits/stdc++.h>

using namespace std;

int main ()
{
  int P, N;
  scanf("%d %d", &P, &N);
  P--;
  priority_queue<int, vector<int>, greater<int> > pq;
  for (int i=0; i<N; i++) {
    int temp;
    scanf("%d", &temp);
    pq.push(temp);
  }
  long long int answer = 0;
  while (!pq.empty() && P - pq.top() >= 0) {
    answer += P;
    P -= pq.top();
    pq.pop();
  }
  printf("%d %lld\n", N-pq.size(), answer);
  return 0;
}
