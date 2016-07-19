#include <bits/stdc++.h>

#define mp make_pair

using namespace std;

bool isPossible(int bombX, int bombY, vector<pair<int, int> >& walls)
{
  for (int i=0; i<walls.size(); i++) {
    if (bombX == walls[i].first || bombY == walls[i].second) {
      continue;
    }
    return false;
  }
  return true;
}

void solveCase()
{
  int N, M;
  vector<pair<int, int> > walls;
  scanf("%d %d\n", &N, &M);
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      char ch;
      scanf("%c", &ch);
      if (ch == '*') {
        walls.push_back(make_pair(i+1, j+1));
      }
    }
    scanf("\n");
  }

  if (walls.size() == 0) {
    printf("YES\n1 1\n");
    return;
  } else if (walls.size() == 1) {
    printf("YES\n%d %d\n", walls[0].first, walls[0].second);
    return;
  } else if (walls.size() == 2) {
    printf("YES\n%d %d\n", walls[0].first, walls[1].second);
    return;
  }

  int ax = walls[0].first, ay = walls[0].second;
  int i, bx, by;
  for (i=1; i<walls.size(); i++) {
    bx = walls[i].first, by = walls[i].second;
    if (ax != bx && ay != by) break;
  }
  if (i == walls.size()) {
    printf("YES\n%d %d\n", ax, ay);
    return;
  }
  if (isPossible(bx, ay, walls)) {
    printf("YES\n%d %d\n", bx, ay);
    return;
  }
  if (isPossible(ax, by, walls)) {
    printf("YES\n%d %d\n", ax, by);
    return;
  }
  printf("NO\n");
}

int main ()
{
  solveCase();

  return 0;
}
