#include <stdio.h>
#include <vector>

#define int long long int

using namespace std;

vector<int> D;
int dp (int k)
{
  if (D[k] != -1) {
    return D[k];
  }
  D[k] = 0;
  for (int i=2; i<=k; i+=2) {
    int l = dp(i-2);
    int r = dp(k-i);
    if (l && r) {
      D[k] += l * r;
    } else if (l || r) {
      D[k] += l + r;
    }
  }
  return D[k];
}

main ()
{
  int N;
  scanf("%lld", &N);
  D = vector<int>(N * 2 + 1, -1);
  D[0] = 0;
  D[2] = 1;
  printf("%lld\n", dp(N * 2));
  return 0;
}
