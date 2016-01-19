#include <stdio.h>
#include <queue>

using namespace std;

struct _J {
  int weight;
  int value;

  bool operator< (const _J& other) const
  {
    return this->value / (double)this->weight < other.value / (double)other.weight;
  }
} typedef J;

int main ()
{
  int K, N;
  scanf("%d", &K);
  scanf("%d", &N);

  priority_queue<J> pq;
  for (int i=0; i<N; i++) {
    J j;
    scanf("%d %d", &j.weight, &j.value);
    pq.push(j);
  }

  double answer = 0;

  while (!pq.empty() && K > 0) {
    J j = pq.top();
    pq.pop();

    if (K >= j.weight) {
      answer += j.value;
      K -= j.weight;
    } else {
      answer += K * (j.value / (double)j.weight);
      K = 0;
    }
  }

  printf("%.2lf\n", answer);

  return 0;
}
