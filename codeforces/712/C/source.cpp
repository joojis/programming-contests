#include <bits/stdc++.h>

using namespace std;

int max(int a, int b, int c)
{
  return max(a, max(b, c));
}

int min(int a, int b, int c)
{
  return min(a, min(b, c));
}

int mid(int a, int b, int c)
{
  return a + b + c - max(a, b, c) - min(a, b, c);
}


void solveCase()
{
  int x, y;
  cin >> x >> y;

  int a, b, c;
  a = b = c = y;
  int count = 0;

  while (a < x || b < x || c < x) {
    int A = max(a, b, c);
    int B = mid(a, b, c);
    int C = min(a, b, c);

    C = min(x, A+B-1);

    a = A; b = B; c = C;
    count++;
  }

  cout << count << endl;
}

int main()
{
  solveCase();
  return 0;
}
