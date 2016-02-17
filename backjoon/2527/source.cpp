#include <cstdio>

const int LINE = 2;
const int POINT = 1;
const int NO = 0;

int intersection(int a, int b, int c, int d)
{
  if (b == c || a == d) {
    return POINT;
  } else if (b < c || d < a) {
    return NO;
  } else {
    return LINE;
  }
}

void solveCase ()
{
  int a, b, c, d;
  int w, x, y, z;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  scanf("%d %d %d %d", &w, &x, &y, &z);

  switch (intersection(a, c, w, y) * intersection(b, d, x, z)) {
  case NO:
    puts("d");
    break;
  case POINT * POINT:
    puts("c");
    break;
  case LINE * POINT:
    puts("b");
    break;
  case LINE * LINE:
    puts("a");
    break;
  }
}

int main ()
{
  int T = 4;
  while (T--) {
    solveCase();
  }
  return 0;
}
