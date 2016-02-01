#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int LL;

int main ()
{
  int N;
  scanf("%d", &N);
  vector<unsigned> H(N);
  for (int i=0; i<N; i++) {
    scanf("%u", &H[i]);
  }


  vector<unsigned> L(N*2);

  int ls = N;
  int le = N;

  LL answer = 0;

  for (int i=N-1; i>=0; i--) {
#ifdef _DEBUG
    int tt = upper_bound(L.begin() + ls, L.begin() + le, H[i]) - (L.begin()) - ls;
    printf("H[%d] = %u ... %d (ls: %d, le: %d) xxxxxxx ", i, H[i], tt, ls, le);
    for (int k=ls; k<le; k++) {
      printf("%d ", L[k]);
    }
    printf("\n");
#endif

    int index = upper_bound(L.begin() + ls, L.begin() + le, H[i]) - (L.begin()) - ls;
    answer += index;
    answer += index != le - ls ? 1 : 0;
    int target = lower_bound(L.begin() + ls, L.begin() + le, H[i]) - (L.begin()) - 1;
    L[target] = H[i];
    ls = target;
  }

  printf("%lld\n", answer);

  return 0;
}
