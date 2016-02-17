#include <bits/stdc++.h>

using namespace std;

void solveCase ()
{
  int V, E;
  scanf("%d %d", &V, &E);

  vector< vector<int> > e(V);
  for (int i=0; i<E; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--; b--;
    e[a].push_back(b);
    e[b].push_back(a);
  }

  vector<int> group(V, 0);
  queue<pair<int, int> > bfs;

  for (int i=0; i<V; i++) {
    if (group[i] > 0) {
      continue;
    }

    group[i] = 1;
    bfs.push(make_pair(i, 1));
    while (!bfs.empty()) {
      int currentV = bfs.front().first;
      int currentG = bfs.front().second;
      int nextG = currentG == 1 ? 2 : 1;
      bfs.pop();

      for (int j=0; j<e[currentV].size(); j++) {
        int nextV = e[currentV][j];
        if (group[nextV] == 0) {
          group[nextV] = nextG;
          bfs.push(make_pair(nextV, nextG));
        } else if (group[nextV] != nextG) {
          printf("NO\n");
          return;
        }
      }
    }
  }

  printf("YES\n");
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
