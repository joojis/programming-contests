#include <stdio.h>
#include <algorithm>

struct _P {
  int x, y;
  int id;
  bool operator< (const _P& other) const
  {
    return x != other.x ? x < other.x : y < other.y;
    // return y != other.y ? y < other.y : x < other.x;
  }
} typedef P;

P p[900];

int main ()
{
  int N;
  scanf("%d", &N);
  for (int i=0; i<3*N; i++) {
    scanf("%d %d", &p[i].x, &p[i].y);
    p[i].id = i+1;
  }
  std::sort(p, p+(3*N));
#ifdef _DEBUG
  for (int i=0; i<3*N; i++) {
    printf("%d: %d %d\n", p[i].id, p[i].x, p[i].y);
  }
#endif

  for (int i=0; i<3*N; i++) {
    printf("%d ", p[i].id);
    if ((i+1)%3 == 0) {
      printf("\n");
    }
  }
  return 0;
}
