#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

const int MAX_N = 12;
const int MAX_M = 100;

const int MAX_V = MAX_N + MAX_M + 2;
const int SOURCE = 0;
const int SINK = 1;

int N, M;
int wins[MAX_N];
int match[MAX_M][2];

int C[MAX_V][MAX_V];
int F[MAX_V][MAX_V];
vector<int> list[MAX_V];

bool NF()
{
  int flow = 0;
  memset(F, 0, sizeof(F));
  while (true) {
    int parent[MAX_V] = {0,};
    int capacity[MAX_V] = {0,};

    for (int i=0; i<MAX_V; i++) {
      parent[i] = -1;
    }
    parent[SOURCE] = SOURCE;
    capacity[SOURCE] = 2000;

    queue<int> bfs;
    bfs.push(SOURCE);
    while (!bfs.empty() && parent[SINK] == -1) {
      int i = bfs.front(); bfs.pop();
      for (int j=0; j<2+N+M; j++) {
        if (C[i][j] > F[i][j] && parent[j] == -1) {
          bfs.push(j);
          parent[j] = i;
          capacity[j] = min(capacity[i], C[i][j] - F[i][j]);

          if (j == SINK) {
            break;
          }
        }
      }
    }
    int argumentPathFlow = capacity[SINK];
    if (argumentPathFlow == 0) {
      break;
    }
    flow += argumentPathFlow;
    int curr = SINK;
    while (curr != SOURCE) {
      int prev = parent[curr];
      F[prev][curr] += argumentPathFlow;
      F[curr][prev] -= argumentPathFlow;
      curr = prev;
    }
  }

  return flow == M;
}

void solveCase()
{
  memset(C, 0, sizeof(C));
  for (int i=0; i<MAX_V; i++) {
    list[i].clear();
  }

  scanf("%d %d", &N, &M);
  for (int i=0; i<N; i++) {
    scanf("%d", wins+i);
    C[2 + i][SINK] = 1;
    list[2 + i].push_back(SINK);
    list[SINK].push_back(2 + i);
  }

  int maxWin = wins[0];
  for (int i=0; i<M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    match[i][0] = a;
    match[i][1] = b;

    C[SOURCE][2 + N + i] = 1;
    list[SOURCE].push_back(2 + N + i);
    list[2 + N + i].push_back(SOURCE);

    C[2 + N + i][2 + a] = 1;
    list[2 + N + i].push_back(2 + a);
    list[2 + a].push_back(2 + N + i);

    C[2 + N + i][2 + b] = 1;
    list[2 + N + i].push_back(2 + b);
    list[2 + b].push_back(2 + N + i);

    if (a == 0 || b == 0) {
      maxWin++;
    }
  }


  for (int i=wins[0]; i<=maxWin; i++) {
    bool cannotWinFlag = false;

    C[2 + 0][SINK] = i - wins[0];
    for (int j=1; j<N; j++) {
      C[2 + j][SINK] = i - wins[j] - 1;
      if (C[2 + j][SINK] < 0) {
        cannotWinFlag = true;
        break;
      }
    }
    if (cannotWinFlag) {
      continue;
    }
    if (NF()) {
      printf("%d\n", i);
      return;
    }
  }

  printf("-1\n");
}

int main ()
{
  int C;
  scanf("%d", &C);
  while(C--) {
    solveCase();
  }
  return 0;
}
