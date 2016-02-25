#include <cstdio>

void solveCase (int N) {
  int k=1;
  int cnt=1;
  k %= N;
  while (k) {
    cnt++;
    k = (k*10 + 1) % N;
  }
  printf("%d\n", cnt);
}

int main ()
{
  int N;
  while (scanf("%d", &N) > 0) {
    solveCase(N);
  }
  return 0;
}
