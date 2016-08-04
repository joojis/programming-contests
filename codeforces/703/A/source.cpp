#include <bits/stdc++.h>

using namespace std;

void solveCase()
{
  int N;
  cin >> N;

  int mishka = 0, chris = 0;
  for (int i=0; i<N; i++) {
    int a, b;
    cin >> a >> b;
    if (a > b) {
      mishka++;
    } else if (b > a) {
      chris++;
    }
  }

  if (mishka != chris) {
    cout << (mishka > chris ? "Mishka" : "Chris") << endl;
  } else {
    cout << "Friendship is magic!^^" << endl;
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
