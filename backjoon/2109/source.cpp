#include <bits/stdc++.h>

using namespace std;

struct _S {
  int p, d;
  bool operator< (const _S& other) const {
    return p != other.p ? p < other.p : d < other.d;
  }
} typedef Seminar;

struct DComp {
  bool operator() (const _S& l, const _S& r) const
  {
    return l.d > r.d;
  }
} dComp;

void solveCase ()
{
  int N;
  scanf("%d", &N);
  if (N == 0) {
    printf("0\n");
    return;
  }
  vector<Seminar> S(N);
  for (int i=0; i<N; i++) {
    scanf("%d %d", &S[i].p, &S[i].d);
  }
  sort(S.begin(), S.end(), dComp);
#ifdef _DEBUG
  for (int i=0; i<N; i++) {
    printf("%d %d\n", S[i].p, S[i].d);
  }
#endif
  int answer = 0;
  int day = 10000;
  int i = 0;
  priority_queue<Seminar> pq;
  while (day > 0) {
    while (S[i].d >= day && i < N) {
#ifdef _DEBUG
      printf("push %d %d\n", S[i].d, S[i].p);
#endif
      pq.push(S[i]);
      i++;
    }
    if (pq.empty()) {
      if (i == N) {
        break;
      }
      day = S[i].d;
    } else {
      answer += pq.top().p;
      day = min(pq.top().d - 1, day - 1);
      pq.pop();
    }
  }
  printf("%d\n", answer);
}

int main ()
{
#ifdef _TC
  int T = _TC;
  while (T--) {
#endif
    solveCase();
#ifdef _TC
  }
#endif
  return 0;
}
