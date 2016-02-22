#include <bits/stdc++.h>

int main ()
{
  int n, b, p;
  scanf("%d %d %d", &n, &b, &p);

  int y = n * p;
  int x = 0;
  while (n > 1) {
    x += (n/2) * (b*2 + 1);
    n -= n/2;
  }
  printf("%d %d\n", x, y);
  return 0;
}
