#include <stdio.h>
#include <vector>

using namespace std;

typedef vector<long long int> SumArray;
long long int solveCase()
{
  int N, P;
  scanf("%d %d", &N, &P);

  SumArray sum(N + 1, 0);
  for (int i=1; i<=N; i++) {
    scanf("%d", &sum[i]);
    sum[i] += sum[i-1];
  }

  SumArray::iterator head, tail;
  tail = sum.begin();
  head = sum.begin() + 1;

  long long int answer = 0;
  while (head != sum.end()) {
    if (*head - *tail <= P) {
      answer += head - tail;
      head++;
    } else {
      tail++;
      if (tail == head) {
        head++;
      }
    }
  }

  return answer;
}

int main ()
{
  int T;
  scanf("%d", &T);
  for (int i=1; i<=T; i++) {
    printf("Case #%d: %lld\n", i, solveCase());
  }
  return 0;
}
