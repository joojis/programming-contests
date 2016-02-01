#include <stdio.h>
#include <queue>

using namespace std;

int main ()
{
  long long int answer = 0;
  int N;
  priority_queue<int> odds;
  scanf("%d\n", &N);
  for (int i=0; i<N; i++) {
    int t;
    scanf("%d", &t);
    if (t%2 == 0) {
      answer += t;
    } else {
      odds.push(t);
    }
  }

  while (odds.size() > 1) {
    int a, b;
    a = odds.top();
    odds.pop();
    b = odds.top();
    odds.pop();
    answer += a + b;
  }

  printf("%I64d\n", answer);
  return 0;
}
