#include <stdio.h>
#include <vector>

using namespace std;

struct _Unit {
  int x, y, r;
  bool operator== (const _Unit& other) const
  {
    int dx = x - other.x;
    int dy = y - other.y;
    int sr = r + other.r;
    return dx * dx + dy * dy <= sr * sr;
  }
} typedef Unit;


vector<int> uf_array;
int uf(int i)
{
  if (uf_array[i] == i) {
    return i;
  }
  uf_array[i] = uf(uf_array[i]);
  return uf_array[i];
}

void solveCase()
{
  int N;
  scanf("%d", &N);
  vector<Unit> units(N);
  uf_array = vector<int>(N);
  for (int i=0; i<N; i++) {
    scanf("%d %d %d", &units[i].x, &units[i].y, &units[i].r);
    uf_array[i] = i;
    for (int j=0; j<i; j++) {
      if (units[i] == units[j] && uf(i) != uf(j)) {
        uf_array[uf(i)] = uf(j);
      }
    }
  }

  int count = 0;
  vector<bool> check(N, false);
  for (int i=0; i<N; i++) {
    if (check[uf(i)] == false) {
      check[uf(i)] = true;
      count++;
    }
  }
  printf("%d\n", count);
}

int main ()
{
  int T;
  scanf("%d", &T);
  while (T--) {
    solveCase();
  }
  return 0;
}
