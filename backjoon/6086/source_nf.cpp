#include <bits/stdc++.h>

using namespace std;

int C[200][200] = { 0, };

int nf(int source, int sink)
{
  int F[200][200] = { 0, };
  int totalFlow = 0;
  while (true) {
    int from[200] = { 0, };
    int flow[200] = { 0, };
    queue<int> bfs;
    bfs.push(source);
    from[source] = source;
    flow[source] = 987654321;

    while (!bfs.empty() && flow[sink] == 0) {
      int curr = bfs.front();
      bfs.pop();
      for (int next = 'A'; next <= 'Z'; next++) {
        if (C[curr][next] > F[curr][next] && from[next] == 0) {
          from[next] = curr;
          flow[next] = min(flow[curr], C[curr][next] - F[curr][next]);
          bfs.push(next);
        }
      }
      for (int next = 'a'; next <= 'z'; next++) {
        if (C[curr][next] > F[curr][next] && from[next] == 0) {
          from[next] = curr;
          flow[next] = min(flow[curr], C[curr][next] - F[curr][next]);
          bfs.push(next);
        }
      }
    }

    if (flow[sink] == 0) {
      return totalFlow;
    }
    totalFlow += flow[sink];

    int curr = sink;
    while (curr != source) {
      int prev = from[curr];
      F[prev][curr] += flow[sink];
      F[curr][prev] -= flow[sink];
      curr = prev;
    }
  }
}

int main ()
{
  int N;
  scanf("%d\n", &N);
  for (int i=0; i<N; i++) {
    char s, t;
    int cap;
    scanf("%c %c %d\n", &s, &t, &cap);
    C[s][t] = C[t][s] += cap;
  }

  printf("%d\n", nf('A', 'Z'));

  return 0;
}
