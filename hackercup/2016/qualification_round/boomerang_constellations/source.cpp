#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int solveCase()
{
  int N;
  int X[2000], Y[2000];
  vector<int> E[2000];

  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    scanf("%d %d", &X[i], &Y[i]);

    for (int j=0; j<i; j++) {
      int dx = X[i] - X[j];
      int dy = Y[i] - Y[j];
      int length = dx * dx + dy * dy;
      E[i].push_back(length);
      E[j].push_back(length);
    }
  }

  int answer = 0;
  for (int i=0; i<N; i++) {
    sort(E[i].begin(), E[i].end());

    int count = 0;
    int prev = -1;
    for (int j=0; j<E[i].size(); j++) {
      int current = E[i][j];

      if (prev == current) {
        answer += count;
        count++;
      } else {
        count = 1;
      }
      prev = current;
    }
  }
  return answer;
}

int main ()
{
  int T;
  scanf("%d", &T);
  for (int i=1; i<=T; i++) {
    printf("Case #%d: %d\n", i, solveCase());
  }
  return 0;
}
