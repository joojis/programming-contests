#include <bits/stdc++.h>

using namespace std;

struct _Rect {
  int sx, sy, ex, ey;
  bool contains(struct _Rect& other) {
    return this->sx <= other.sx && other.ex <= this->ex &&
      this->sy <= other.sy && other.ey <= this->ey;
  }

  bool operator< (const struct _Rect& other) const {
    int thisXSize = this->ex - this->sx;
    int otherXSize = other.ex - other.sx;
    int thisYSize = this->ey - this->sy;
    int otherYSize = other.ey - other.sy;
    if (thisXSize != otherXSize) {
      return thisXSize > otherXSize;
    } else {
      return thisYSize > otherYSize;
    }
  }
} typedef Rect;

void solveCase()
{
  int N, M, K;
  cin >> N >> M >> K;
  vector<Rect> rects(K);
  for (int i=0; i<K; i++) {
    cin >> rects[i].sx >> rects[i].sy >> rects[i].ex >> rects[i].ey;
  }
  sort(rects.begin(), rects.end());

  int ans = 0;
  vector<int> answer(K, 1);
  vector<int> lastJ(K, 0);
  for (int i=0; i<K; i++) {
    stack<int> dfs;
    dfs.push(i);
    while (!dfs.empty()) {
      int k = dfs.top();
      int j;
      for (j=max(k+1, lastJ[k]); j<K; j++) {
        if (!rects[k].contains(rects[j])) continue;
        if (lastJ[j] == K) {
          answer[k] = max(answer[k], 1 + answer[j]);
        } else {
          dfs.push(j);
          break;
        }
      }
      lastJ[k] = j;
      if (j < K) continue;
      else dfs.pop();
    }
    ans = max(ans, answer[i]);
  }
  cout << ans << endl;
}

int main()
{
  int T;
  scanf("%d\n", &T);
  for (int i=1; i<=T; i++) {
    printf("Case #%d\n", i);
    solveCase();
  }

  return 0;
}
