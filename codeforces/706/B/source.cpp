#include <bits/stdc++.h>

using namespace std;

void solveCase()
{
  int N;
  cin >> N;
  vector<int> prices(N);
  for (int i=0; i<N; i++) {
    cin >> prices[i];
  }
  sort(prices.begin(), prices.end());
  int Q;
  cin >> Q;
  for (int i=0; i<Q; i++) {
    int coins;
    cin >> coins;
    int answer = upper_bound(prices.begin(), prices.end(), coins) - prices.begin();
    cout << answer << endl;
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
