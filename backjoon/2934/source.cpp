#include <bits/stdc++.h>

using namespace std;

struct _IndexedTree {
  vector<int> L, R;
  int N;
  int K;
  vector<int> result;
  _IndexedTree(int range)
  {
    N = range;
    K = 1;
    while (K < range) K*=2;

    L = vector<int>(K*2, 0);
    R = vector<int>(K*2, 0);
    result = vector<int>(K*2, 0);
    for (int i=K; i<K*2; i++) {
      L[i] = R[i] = i-K+1;
    }
    for (int k=K-1; k>0; k--) {
      L[k] = L[k*2];
      R[k] = R[k*2+1];
    }
  }

  void update(int k, int l, int r, int value)
  {
    if (R[k] < l || r < L[k]) {
      return;
    } else if (l <= L[k] && R[k] <= r) {
      result[k] += value;
    } else {
      update(k*2, l, r, value);
      update(k*2+1, l, r, value);
    }
  }

  int query(int k, int l, int r)
  {
    if (k >= K+N || R[k] < l || r < L[k]) {
      return 0;
    }
    return result[k] + query(k*2, l, r) + query(k*2+1, l, r);
  }
} typedef IndexedTree;

void solveCase ()
{
  IndexedTree it(100000);
  int N;
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    int l = it.query(1, a, a);
    int r = it.query(1, b, b);
#ifdef _DEBUG
    printf("i: %d ... l:%d r:%d\n", i, l, r);
#endif
    printf("%d\n", l+r);
    it.update(1, a, a, -l);
    it.update(1, b, b, -r);
    it.update(1, a+1, b-1, 1);
  }
}

int main ()
{
  solveCase();
  return 0;
}
