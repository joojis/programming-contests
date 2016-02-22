#include <bits/stdc++.h>

using namespace std;

int main ()
{
  int N;
  int R[100] = {0,}, C[100] = {0,};
  scanf("%d\n", &N);
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      char temp;
      scanf("%c", &temp);
      if (temp == 'C') {
        R[i]++;
        C[j]++;
      }
    }
    scanf("\n");
  }

  int answer = 0;
  for (int i=0; i<N; i++) {
    answer += R[i] * (R[i]-1) / 2;
    answer += C[i] * (C[i]-1) / 2;
  }
  printf("%d\n", answer);
  return 0;
}
