#include <bits/stdc++.h>

using namespace std;

bool visit[200001] = {0, };
int uf[200001];
set<int> cycles;
int find(int i)
{
  visit[i] = true;
  if (uf[i] != i) {
    if (visit[uf[i]]) { // cycle
      cycles.insert(i);
      uf[i] = i;
    } else {
      uf[i] = find(uf[i]);
    }
  }
  visit[i] = false;
  return uf[i];
}

void solveCase()
{
  int N;
  int parents[200001];
#ifdef _DEBUG
  cycles.clear();
#endif
  cin >> N;
  for (int i=1; i<=N; i++) {
    cin >> parents[i];
    uf[i] = parents[i];
  }
  set<int> roots;
  for (int i=1; i<=N; i++) {
    roots.insert(find(i));
  }

  vector<bool> isRoot(N+1, false);
  int root = 0;
  for (set<int>::iterator iter = roots.begin(); iter != roots.end(); iter++) {
    isRoot[*iter] = true;
    if (cycles.find(*iter) == cycles.end()) root = *iter;
  }
  if (root == 0) root = *roots.begin();

  vector<int> fixed(N+1);
  for (int i=1; i<=N; i++) {
    fixed[i] = (isRoot[i] ? root : parents[i]);
  }

  int diffCount = 0;
  for (int i=1; i<=N; i++) {
    diffCount += parents[i] != fixed[i] ? 1 : 0;
  }

  cout << diffCount << endl;
  for (int i=1; i<=N; i++) {
    cout << fixed[i] << " ";
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
