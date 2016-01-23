#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
  int N, K;
  scanf("%d %d", &N, &K);
  vector<int> coins(N);
  for (int i=0; i<N; i++) {
    scanf("%d", &coins[i]);
  }
  sort(coins.begin(), coins.end());
  vector<int> answers(K+1, -1);
  answers[0] = 0;
  for (int i=0; i<N; i++) {
    int coin = coins[i];
    for (int k=coin; k<=K; k++) {
      if (answers[k - coin] != -1) {
        answers[k] = answers[k] == -1 ? answers[k - coin] + 1 : min(answers[k], answers[k - coin] + 1);
      }
    }
  }
  printf("%d\n", answers[K]);

  return 0;
}
