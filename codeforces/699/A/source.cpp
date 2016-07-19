#include <bits/stdc++.h>

#define make_pair mp

using namespace std;

void solveCase()
{
  int N;
  char dir[200000];
  int pos[200000];
  scanf("%d\n", &N);
  for (int i=0; i<N; i++) {
    scanf("%c", dir+i);
  }
  for (int i=0; i<N; i++) {
    scanf("%d", pos+i);
  }

  const int init = 987654321;
  int ans = init;
  for (int i=1; i<N; i++) {
    if (dir[i-1] == 'R' && dir[i] == 'L') {
      ans = min(ans, (pos[i] - pos[i-1])/2);
    }
  }
  printf("%d\n", ans == init ? -1 : ans);
}

int main ()
{
  solveCase();

  return 0;
}
