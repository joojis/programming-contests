#include <bits/stdc++.h>

using namespace std;

void solveCase()
{
  char str[100002];
  cin >> str;

  int i = 0, LR = 0, UD = 0;
  while (str[i]) {
    switch (str[i]) {
    case 'L':
      LR--;
      break;
    case 'R':
      LR++;
      break;
    case 'U':
      UD--;
      break;
    case 'D':
      UD++;
      break;
    }
    i++;
  }
  int K = abs(LR) + abs(UD);
  cout << (K % 2 == 1 ? -1 : K / 2) << endl;
}

int main ()
{
  solveCase();
  return 0;
}
