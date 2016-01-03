#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int main ()
{
  int M, N, L;
  scanf("%d %d %d", &M, &N, &L);

  vector<int> guns(M, 0);
  while (M--) {
    scanf("%d", &guns[M]);
  }

  sort(guns.begin(), guns.end());

  int answer = 0;
  while (N--) {
    int a, b;
    scanf("%d %d", &a, &b);

    vector<int>::iterator lb = lower_bound(guns.begin(), guns.end(), a) - 1, ub = lower_bound(guns.begin(), guns.end(), a);
    vector<int>::iterator nearest;

    if (ub == guns.end()) {
      nearest = lb;
    } else if (ub == guns.begin()) {
      nearest = ub;
    } else if (abs(*lb - a) < abs(*ub - a)) {
      nearest = lb;
    } else {
      nearest = ub;
    }

    if (abs(*nearest - a) <= L - b) {
      answer++;
    }
  }

  printf("%d\n", answer);


  return 0;
}
