#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

vector<bool> visited;
vector<vector<int> > E;

void solveCase ()
{
  int N;
  scanf("%d", &N);
  visited = vector<bool>(N, false);
  E = vector< vector<int> >(N);
  for (int i=1; i<N; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    E[a-1].push_back(b-1);
    E[b-1].push_back(a-1);
  }
  int answer = 0;
  visited[0] = true;
  for (int i=0; i<E[0].size(); i++) {
    vector<int> depths;
    queue<PII> bfs;
    bfs.push(make_pair(E[0][i], 1));
    while (!bfs.empty()) {
      PII curr = bfs.front(); bfs.pop();
      visited[curr.first] = true;
      if (E[curr.first].size() == 1 && visited[E[curr.first][0]]) {
        depths.push_back(curr.second);
        continue;
      }

      for (int i=0; i<E[curr.first].size(); i++) {
        if (visited[E[curr.first][i]])
          continue;
        bfs.push(make_pair(E[curr.first][i], curr.second+1));
      }
    }

#ifdef _DEBUG
    printf("%d ", depths[0]);
#endif
    for (int k=1; k<depths.size(); k++) {
      depths[k] = max(depths[k], depths[k-1]+1);
#ifdef _DEBUG
      printf("%d ", depths[k]);
#endif
    }
#ifdef _DEBUG
    printf("\n");
#endif
    answer = max(answer, depths.back());
  }
  printf("%d\n", answer);
}

int main ()
{
#ifdef _TC
  int T = _TC;
  while (T--) {
#endif
    solveCase();
#ifdef _TC
  }
#endif
  return 0;

}
