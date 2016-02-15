#include <bits/stdc++.h>

using namespace std;

vector<int> bit;

void addOne(unsigned k)
{
  while (k < bit.size()) {
    bit[k]++;
    k += k & -k;
  }
}

int getSum(unsigned k)
{
  int answer = 0;
  while (k > 0) {
    answer += bit[k];
    k -= k & -k;
  }
  return answer;
}

struct _P {
  int x, y;
} typedef P;

struct xAsc {
  bool operator() (const P& a, const P& b) const { return a.x < b.x; }
};

struct yDesc {
  // bool operator() (const P& a, const P& b) const { return a.y != b.y ? a.y > b.y : a.x < b.x; }
  bool operator() (const P& a, const P& b) const { return a.y > b.y; }
};

void solveCase()
{
  int N;
  scanf("%d", &N);
  P p[75000];
  for (int i=0; i<N; i++) {
    scanf("%d %d", &p[i].x, &p[i].y);
  }
  sort(p, p+N, xAsc());
  vector<int> rank(N);
  rank[0] = 1;
  for (int i=1; i<N; i++) {
    rank[i] = p[i].x != p[i-1].x ? (i+1) : rank[i-1];
  }
  for (int i=0; i<N; i++) {
    p[i].x = rank[i];
#ifdef _DEBUG
    printf("%d ", rank[i]);
#endif
  }
  stable_sort(p, p+N, yDesc());
  long long int answer = 0;
  bit = vector<int>(N+2, 0);
  for (int i=0; i<N; i++) {
    answer += getSum(p[i].x);
    addOne(p[i].x);
  }
  printf("%lld\n", answer);
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
