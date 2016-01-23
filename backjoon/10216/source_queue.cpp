#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>

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


void solveCase()
{
  int N;
  scanf("%d", &N);
  vector<Unit> units(N);
  for (int i=0; i<N; i++) {
    scanf("%d %d %d", &units[i].x, &units[i].y, &units[i].r);
  }

  int nodeCount = 0;
  int bfsCount = 0;
  vector<bool> nodeCheck(N, false);

  while (nodeCount < N) {
    bfsCount++;
    int i=0;
    while (nodeCheck[i]) i++;

    queue<int> bfsQueue;
    bfsQueue.push(i);
    while (!bfsQueue.empty()) {
      int i = bfsQueue.front();
      bfsQueue.pop();

      if (nodeCheck[i]) {
        continue;
      }

      nodeCheck[i] = true;
      nodeCount++;

      for (int j=0; j<N; j++) {
        if ((nodeCheck[j] == false) && (units[i] == units[j])) {
          bfsQueue.push(j);
        }
      }
    }
  }
  printf("%d\n", bfsCount);
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
