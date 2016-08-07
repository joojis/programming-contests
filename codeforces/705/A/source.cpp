#include <bits/stdc++.h>

using namespace std;

void solveCase()
{
  int N;
  cin >> N;
  for (int i=1; i<=N; i++) {
    cout << "I " << (i % 2 ? "hate " : "love ");
    if (i < N) {
      cout << "that ";
    }
  }
  cout << "it";
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
