#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
  int N;
  scanf("%d", &N);

  vector<int> drying(N, 0);
  while (N--) {
    scanf("%d", &drying[N]);
  }
  sort(drying.begin(), drying.end());

  int K;
  scanf("%d", &K);

  int low = 0, high = 1000000000;
  while (low <= high) {
    int mid = (low + high) / 2;

    vector<int>::iterator ub = upper_bound(drying.begin(), drying.end(), mid);
    if (K == 1 && ub != drying.end()) {
      low = mid + 1;
      continue;
    }

printf("low %d, mid: %d, high: %d\n", low, mid, high);
    int useCount = 0;
    while (ub != drying.end() && useCount <= mid) {
      int wet = *ub - mid;
      useCount += (wet + (K - 2)) / (K - 1);

printf("index: %d, wet: %d, useCount: %d\n", ub - drying.begin(), wet, useCount);
      ub++;
    }
    if (ub == drying.end() && useCount <= mid) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  printf("%d\n", low);

  return 0;
}
