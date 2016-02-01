#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_M = 1000;
const int MAX_N = 100;
const int MAX_V = 2 + MAX_M + MAX_N;
const int SOURCE = 0, SINK = 1;

const int INF = 987654321;

int pigs[MAX_M];
int customers[MAX_N];
vector<int> keys[MAX_N];

int M, N;

vector<int> edges[MAX_V];
int F[MAX_V][MAX_V];
int C[MAX_V][MAX_V];

void setCapacity(int from, int to, int capacity)
{
  C[from][to] = capacity;
  edges[from].push_back(to);
  edges[to].push_back(from);
}

int NF ()
{
  int flow = 0;

  while (true) {
    vector<int> path(MAX_V, -1);
    vector<int> capacity(MAX_V, 0);
    queue<int> bfs;

    path[SOURCE] = SOURCE;
    capacity[SOURCE] = INF;
    bfs.push(SOURCE);
    while (!bfs.empty() && path[SINK] == -1) {
      int curr = bfs.front();
      bfs.pop();
      for (int i=0; i<edges[curr].size(); i++) {
        int target = edges[curr][i];
        if (C[curr][target] > F[curr][target] && path[target] == -1) {
          path[target] = curr;
          capacity[target] = min(C[curr][target] - F[curr][target], capacity[curr]);
          bfs.push(target);
        }
      }
    }

    if (capacity[SINK] == 0) {
      break;
    }
    flow += capacity[SINK];

    int curr = SINK;
    while (curr != SOURCE) {
      int prev = path[curr];
      F[prev][curr] += capacity[SINK];
      F[curr][prev] -= capacity[SINK];
      curr = prev;
    }
  }

  return flow;
}

int main ()
{
  scanf("%d %d", &M, &N);
  for (int i=0; i<M; i++) {
    scanf("%d", &pigs[i]);
    int pighouseIndex = 2 + i;
    setCapacity(SOURCE, pighouseIndex, pigs[i]);
  }

  vector<int> from(M+1, -1);
  for (int i=0; i<N; i++) {
    int a, b, k;
    scanf("%d", &a);
    int customerIdx = 2+M+i;
    for (int j=0; j<a; j++) {
      scanf("%d", &k);
      if (from[k] == -1) {
        from[k] = customerIdx;
        int pighouseIndex = 2+k-1;
        setCapacity(pighouseIndex, customerIdx, INF);
      } else {
        setCapacity(from[k], customerIdx, INF);
      }
    }
    scanf("%d", &b);
    setCapacity(customerIdx, SINK, b);
  }

  printf("%d\n", NF());

  return 0;
}
