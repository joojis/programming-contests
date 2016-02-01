#include <bits/stdc++.h>

using namespace std;

vector<int> bit;

inline int lsb (int i)
{
  return i & -i;
}

int sum (int i)
{
  if (i >= bit.size()) {
    while (true);
  }
  return i == 0 ? 0 : bit[i] + sum(i - lsb(i));
}

void add (int i, int val)
{
  if (i >= bit.size()) {
    return;
  }
  bit[i] += val;
  add(i + lsb(i), val);
}

struct Comp {
  int val;
  int index;
  bool operator< (const Comp& other) const
  {
    return val < other.val;
  }
};

int main ()
{
  int N;
  scanf("%d", &N);

  vector<Comp> v(N);
  for (int i=1; i<=N; i++) {
    scanf("%d", &v[i-1].val);
    v[i-1].index = i;
  }

  sort(v.begin(), v.end());

  bit = vector<int>(N+1);
  long long int answer = 0;
  for (int i=0; i<N; i++) {
    answer += i - sum(v[i].index);
    add(v[i].index, 1);
  }

  printf("%lld\n", answer);

  return 0;
}
