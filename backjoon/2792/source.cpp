#include <bits/stdc++.h>

using namespace std;

int N, M;
int J[300000];

bool isPossible(int k)
{
  int sum = 0;
  for (int i=0; i<M; i++) {
    sum += (J[i]+(k-1)) / k;
    if (sum > N) {
      return false;
    }
  }
  return true;
}

int main ()
{
  scanf("%d %d", &N, &M);
  for (int i=0; i<M; i++) {
    scanf("%d", J+i);
  }
  int s = 1, e = 1000000000;
  while (s<=e) {
    int mid = (s+e)/2;
    if (isPossible(mid)) {
      e = mid-1;
    } else {
      s = mid+1;
    }
  }
  printf("%d\n", s);
  return 0;
}
