#include <bits/stdc++.h>

using namespace std;

typedef pair<long long int, int> PII;

struct Comp {
  bool operator() (const PII& a, const PII& b) const { return a.first != b.first ? a.first < b.first : a.second > b.second; }
} comp;

struct _IndexTree {
  int k;
  vector<long long int> tree;
  vector<int> L, R;
  _IndexTree(int n)
  {
    k=1;
    while (k < n) k*=2;
    tree = vector<long long int>(k*2, 0);
    L = vector<int>(k*2);
    R = vector<int>(k*2);
    for (int i=k; i<k*2; i++) {
      L[i]=R[i]=i-k;
    }
    for (int i=k-1; i>0; i--) {
      L[i]=L[i*2];
      R[i]=R[i*2+1];
    }
  }

  void update(int position, long long int val)
  {
    int p = k + position;
    tree[p] = val;
    while (p > 1) {
      p /= 2;
      tree[p] = max(tree[p*2], tree[p*2+1]);
    }
  }

  long long int query(int kk, int a, int b)
  {
    if (a > b) return 0;

    if (a <= L[kk] && R[kk] <= b) {
      return tree[kk];
    } else if (R[kk] < a || b < L[kk]) {
      return 0;
    } else {
      return max(query(kk*2, a, b), query(kk*2+1, a, b));
    }
  }
} typedef IndexTree;

int main ()
{
  int N;
  scanf("%d", &N);
  vector<PII> volumns(N);
  for (int i=0; i<N; i++) {
    int r, h;
    scanf("%d %d", &r, &h);
    volumns[i].first = (long long int)r*r*h;
    volumns[i].second = i;
  }
  sort(volumns.begin(), volumns.end(), comp);
#ifdef _DEBUG
  for (int i=0; i<N; i++) {
    printf("%I64d %d\n", volumns[i].first, volumns[i].second);
  }
#endif
  IndexTree it(N);
  for (int i=0; i<N; i++) {
    it.update(volumns[i].second, volumns[i].first + it.query(1, 0, volumns[i].second-1));
  }
  const double PI = atan(1) * 4;
  printf("%.8lf\n", it.query(1, 0, N-1) * PI);

  return 0;
}
