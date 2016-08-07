#include <bits/stdc++.h>

using namespace std;

void solveCase()
{
  int N;
  cin >> N;
  long long int sum = 0;
  for (int i=0 ; i<N; i++) {
    int k;
    cin >> k;
    sum += k-1;
    cout << 2 - (sum & 1) << endl;
  }
}

int main()
{
#ifdef _DEBUG
  int T;
  scanf("%d\n", &T);
  while (T--) {
#endif
    solveCase();
#ifdef _DEBUG
  }
#endif
  return 0;
}
