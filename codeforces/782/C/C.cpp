#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct item {
  int node;
  int color;
  int parent_color;
  item(int a, int b, int c) {
    node = a;
    color = b;
    parent_color = c;
  }
};

typedef vector<int> vi;
typedef pair<int, int> pii;

void solveCase()
{
  int N;
  cin >> N;
  vector<vi> edges(N);
  for (int i=0; i<N-1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  int max = 0;
  int root = 0;
  for (int i=0; i<N; i++) {
    if (max < edges[i].size()) {
      max = edges[i].size();
      root = i;
    }
  }
  cout << max + 1 << endl;
  stack<item> stk;
  stk.push(item(root, 1, 0));
  vector<int> colors(N);
  vector<bool> visited(N, false);
  while (!stk.empty()) {
    item curr = stk.top();
    stk.pop();
    visited[curr.node] = true;
    int nextColor = 1;
    colors[curr.node] = curr.color;
    for (int i=0; i<edges[curr.node].size(); i++) {
      if (visited[edges[curr.node][i]]) continue;
      if (nextColor == curr.parent_color || nextColor == curr.color) nextColor++;
      if (nextColor == curr.parent_color || nextColor == curr.color) nextColor++;
      stk.push(item(edges[curr.node][i], nextColor++, colors[curr.node]));
    }
  }
  for (int i=0; i<N; i++) {
    cout << colors[i] << " ";
  }
  cout << endl;
}

int main ()
{
#ifdef _DEBUG
  int T;
  cin >> T;
  while (T--) {
#endif
    solveCase();
#ifdef _DEBUG
  }
#endif
  return 0;
}
