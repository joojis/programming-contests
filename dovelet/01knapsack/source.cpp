#include <stdio.h>
#include <algorithm>
#include <vector>

int main ()
{
  int N, W;
  int Wi[100], Vi[100];
  scanf("%d %d", &W, &N);
  for (int i=0; i<N; i++) {
    scanf("%d %d", Wi+i, Vi+i);
  }
  std::vector<int> K[2];
  K[1] = std::vector<int>(W+1, -987654321);
  K[1][0] = 0;
  int answer = 0;
  for (int i=0; i<N; i++) {
    int k = i % 2;
    K[k] = std::vector<int>(W+1, -987654321);
    K[k][0] = 0;
    for (int j=1; j<=W; j++) {
      if (j - Wi[i] < 0) {
        K[k][j] = K[k^1][j];
      } else {
        K[k][j] = std::max(K[k^1][j], K[k^1][j-Wi[i]] + Vi[i]);
      }
      answer = std::max(answer, K[k][j]);
    }
  }
  printf("%d\n", answer);
  return 0;
}
