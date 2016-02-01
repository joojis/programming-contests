#include <bits/stdc++.h>

using namespace std;

int main ()
{
  int N;
  scanf("%d", &N);
  vector<unsigned> H(N);
  for (int i=0; i<N; i++) {
    scanf("%u", &H[i]);
  }

  vector<unsigned> L(N+1);
  int ls = N, le = N;
  long long int answer = 0;
  for (int i=N-1; i>=0; i--) {
    int index = upper_bound(L.begin() + ls, L.begin() + le, H[i]) - (L.begin() + ls);
    answer += index != le - ls ? index + 1 : index;
    ls = lower_bound(L.begin() + ls, L.begin() + le, H[i]) - L.begin() - 1;
    L[ls] = H[i];
  }
  printf("%lld\n", answer);

  return 0;
}
