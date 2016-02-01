#include <stdio.h>
#include <algorithm>

int N;

struct _Paper {
  int a, b;
  bool operator< (const _Paper& other) const
  {
    return a != other.a ? a > other.a : b > other.b;
  }
} typedef Paper;

int result[100] = {0,};
Paper papers[100];

int getMaxHeight (int i)
{
  if (result[i] > 0) {
    return result[i];
  }

  int max = 0;
  for (int j=i+1; j<N; j++) {
    if (papers[i].b >= papers[j].b ||
      (papers[i].a >= papers[j].b && papers[i].b >= papers[j].a)) {
      max = std::max(max, getMaxHeight(j));
    }
  }
  max += 1;
  result[i] = max;
  return max;
}

int main ()
{
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    papers[i].a = a > b ? a : b;
    papers[i].b = a > b ? b : a;
  }
  std::sort(papers, papers+N);

#ifdef _DEBUG
  for (int i=0; i<N; i++) {
    printf("%d %d\n", papers[i].a, papers[i].b);
  }
#endif

  int answer = 0;
  for (int i=0; i<N; i++) {
    answer = std::max(answer, getMaxHeight(i));
  }

  printf("%d\n", answer);

  return 0;
}
