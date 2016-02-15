#include <bits/stdc++.h>

using namespace std;

struct _QueueItem {
  int i, j, count;
  _QueueItem(int i, int j, int count)
  {
    this->i = i;
    this->j = j;
    this->count = count;
  }
} typedef Item;

int main ()
{
  int N, M;
  scanf("%d %d\n", &N, &M);
  char map[100][100];
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      scanf("%c", &map[i][j]);
    }
    scanf("\n");
  }

  queue<Item> bfs;
  bfs.push(Item(0, 0, 0));
  while (!bfs.empty()) {
    Item curr = bfs.front();
    bfs.pop();

    int i = curr.i;
    int j = curr.j;

#ifdef _DEBUG
    printf("curr: %d %d\n", i, j);
#endif

    if (i == N-1 && j == M-1) {
      printf("%d\n", curr.count + 1);
      break;
    }

    if (map[i][j] == '0') {
      continue;
    }
    map[i][j] = '0';

    int ii[] = {1, -1, 0, 0};
    int jj[] = {0, 0, 1, -1};

    for (int k=0; k<4; k++) {
      if (i+ii[k] < 0 || i+ii[k] >= N) {
        continue;
      } else if (j+jj[k] < 0 || j+jj[k] >= M) {
        continue;
      }

      if (map[i+ii[k]][j+jj[k]] == '1') {
        bfs.push(Item(i+ii[k], j+jj[k], curr.count+1));
      }
    }
  }

  return 0;
}
