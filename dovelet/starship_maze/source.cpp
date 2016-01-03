#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main ()
{
  int N, M;
  scanf("%d %d", &N, &M);

  vector<int> door[100001];
  while (M--) {
    int a, b;
    scanf("%d %d", &a, &b);

    door[a].push_back(b);
    door[b].push_back(a);
  }

  for (int i=1; i<=N; i++) {
    sort(door[i].begin(), door[i].end(), greater<int>());
  }

  stack<int> dfs;
  bool visit[100001] = { false, };

  dfs.push(1);
  while (!dfs.empty()) {
    int current = dfs.top();
    dfs.pop();
    if (visit[current]) {
      continue;
    }

    visit[current] = true;
    printf("%d ", current);

    for (int i=0; i<door[current].size(); i++) {
      int j = door[current][i];
      if (!visit[j]) {
        dfs.push(j);
      }
    }
  }

  return 0;
}
