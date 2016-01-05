#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <memory.h>

using namespace std;

const int MAX_PLAYER = 12;
const int MAX_REMAINED_GAME = 100;

typedef pair<int, int> RemainedGame;

RemainedGame remainedGame[MAX_REMAINED_GAME];
int wins[MAX_PLAYER];
int N, M;

const int MAX_NODE = MAX_REMAINED_GAME + MAX_PLAYER + 2; // 0 ~ 99 game, 100 ~ 111 player, 112 SOURCE, 113 SINK;
const int SOURCE = MAX_NODE - 2;
const int SINK = MAX_NODE - 1;

int C[MAX_NODE][MAX_NODE];
int F[MAX_NODE][MAX_NODE];

bool useCapacityIfAvaliable(int from, int to, int* pathFrom, int* foundC)
{
  if (C[from][to] - F[from][to] > 0 && pathFrom[to] == -1) {
    pathFrom[to] = from;
    foundC[to] = min(foundC[from], C[from][to] - F[from][to]);
#if JOOJIS
    printf("Capacity Avaliable   %d -> %d ... min(%d, %d) = %d\n", from, to, foundC[from], C[from][to] - F[from][to], foundC[to]);
#endif
    return true;
  } else {
#if JOOJIS
    printf("Capacity Unavaliable %d -> %d\n", from, to);
#endif
    return false;
  }
}

bool isPossible(int targetWin)
{
  memset(F, 0, sizeof(F));
  int flow = 0;
  while (true) {
    queue<int> bfs;
    int foundC[MAX_NODE] = { 0, };
    int pathFrom[MAX_NODE] = { 0, };

    foundC[SOURCE] = 987654321;
    for (int i=0; i<MAX_NODE; i++) {
      pathFrom[i] = -1;
    }
    pathFrom[SOURCE] = -2;
    bfs.push(SOURCE);
    while (!bfs.empty()) {
      int curr = bfs.front();
      bfs.pop();

      if (curr == SOURCE) {
        for (int i=0; i<M; i++) {
          if (useCapacityIfAvaliable(curr, i, pathFrom, foundC)) {
            bfs.push(i);
          }
        }
      } else if (curr < MAX_REMAINED_GAME) {
        if (useCapacityIfAvaliable(curr, remainedGame[curr].first + MAX_REMAINED_GAME, pathFrom, foundC)) {
          bfs.push(remainedGame[curr].first + MAX_REMAINED_GAME);
        }
        if (useCapacityIfAvaliable(curr, remainedGame[curr].second + MAX_REMAINED_GAME, pathFrom, foundC)) {
          bfs.push(remainedGame[curr].second + MAX_REMAINED_GAME);
        }
      } else if (curr < MAX_REMAINED_GAME + MAX_PLAYER) {
        if (useCapacityIfAvaliable(curr, SINK, pathFrom, foundC)) {
          break;
        }
      }
    }

    if (foundC[SINK] == 0) {
      break;
    }

    flow += foundC[SINK];

    int curr = SINK;
    while (curr != SOURCE) {
      int prev = pathFrom[curr];
      F[prev][curr] += foundC[SINK];
      F[curr][prev] -= foundC[SINK];
      curr = prev;
    }
  }

#if JOOJIS
  printf("isPossible ... targetWin: %d, flow: %d, M: %d \n", targetWin, flow, M);
#endif

  return flow == M;
}

void solveCase ()
{
  memset(C, 0, sizeof(C));

  scanf("%d %d", &N, &M);

  for (int i=0; i<N; i++) {
    scanf("%d", wins + i);
  }

  int maxWin = wins[0];
  for (int i=0; i<M; i++) {
    scanf("%d %d", &remainedGame[i].first, &remainedGame[i].second);

    if (remainedGame[i].first == 0 || remainedGame[i].second == 0) {
      maxWin++;
    }

    C[SOURCE][i] = 1;
    C[i][remainedGame[i].first + MAX_REMAINED_GAME] = 1;
    C[i][remainedGame[i].second + MAX_REMAINED_GAME] = 1;
  }

  for (int tryWin = wins[0]; tryWin <= maxWin; tryWin++) {
    C[MAX_REMAINED_GAME + 0][SINK] = tryWin - wins[0];
    bool skip = false;
    for (int i=1; i<N; i++) {
      C[MAX_REMAINED_GAME + i][SINK] = tryWin - 1 - wins[i];

      if (C[MAX_REMAINED_GAME + i][SINK] < 0) {
        skip = true;
        break;
      }
    }
    if (skip) {
      continue;
    }

    if (isPossible(tryWin)) {
      printf("%d\n", tryWin);
      return;
    }
  }

  printf("-1\n");
}

int main ()
{
  int C;
  scanf("%d", &C);
  while (C--) {
    solveCase();
  }
  return 0;
}
