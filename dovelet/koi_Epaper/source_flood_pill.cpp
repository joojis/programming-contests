#include <bits/stdc++.h>

int main ()
{
  int A[101][101] = {0, };
  int N;
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    int X, Y;
    scanf("%d %d", &X, &Y);
    for (int x=X; x<X+10; x++) {
      for (int y=Y; y<Y+10; y++) {
        A[x][y] = 1;
      }
    }
  }
  int answer = 0;
  for (int i=1; i<=100; i++) {
    for (int j=1; j<=100; j++) {
      if (A[i][j]) {
        answer++;
      }
    }
  }
  printf("%d\n", answer);
  return 0;
}
