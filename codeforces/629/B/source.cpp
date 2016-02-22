#include <bits/stdc++.h>

int main ()
{
  int N;
  scanf("%d\n", &N);
  char gender[5000];
  int start[5000];
  int end[5000];
  for (int i=0; i<N; i++) {
    scanf("%c %d %d\n", gender+i, start+i, end+i);
  }
  int answer = 0;
  for (int d=1; d<=366; d++) {
    int M=0, F=0;
    for (int i=0; i<N; i++) {
      if (start[i] <= d && d <= end[i]) {
        if (gender[i] == 'M') {
          M++;
        } else {
          F++;
        }
      }
    }
    answer = std::max(answer, std::min(M, F)*2);
  }
  printf("%d\n", answer);
  return 0;
}
