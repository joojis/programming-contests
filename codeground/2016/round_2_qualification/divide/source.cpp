#include <bits/stdc++.h>

using namespace std;

const int IRON = 1;
const int COOPER = 0;

struct _Mine {
  int x, y;
  int type;
  bool operator< (const struct _Mine& other) const {
    // assert(this->y != other.y);
    return this->y < other.y;
  }
} typedef Mine;

struct _Penwick {
  vector<int> arr;
  _Penwick(int N) {
    int power = 1;
    while (power < N) power *= 2;
    arr = vector<int>(power + 1, 0);
  }
  void add(int k) {
    while (k < arr.size()) {
      arr[k] += 1;
      k += k & -k;
    }
  }
  int sum(int k) {
    int sum = 0;
    while (k > 0) {
      sum += arr[k];
      k -= k & -k;
    }
    return sum;
  }
} typedef Penwick;

void solveCase()
{
  int N;
  cin >> N;
  vector<Mine> mines(N);
  vector<int> ironX(N+1, 0);
  vector<int> ironY(N+1, 0);
  vector<int> cooperX(N+1, 0);
  vector<int> cooperY(N+1, 0);

  set<int> northIron, northCooper;

  for (int i=0; i<N; i++) {
    cin >> mines[i].x >> mines[i].y >> mines[i].type;
    if (mines[i].type == IRON) {
      ironX[mines[i].x] = 1;
      ironY[mines[i].y] = 1;
      northIron.insert(mines[i].x);
    } else {
      cooperX[mines[i].x] = 1;
      cooperY[mines[i].y] = 1;
      northCooper.insert(mines[i].x);
    }
  }

  for (int i=1; i<=N; i++) {
    ironX[i] += ironX[i-1];
    ironY[i] += ironY[i-1];
    cooperX[i] += cooperX[i-1];
    cooperY[i] += cooperY[i-1];
  }

  sort(mines.begin(), mines.end());

#ifdef _DEBUG
  for (int i=0; i<N; i++) {
    printf("mines[%2d]: %2d %2d %s\n", i, mines[i].x, mines[i].y, mines[i].type ? "IRON" : "COOPER");
  }
#endif

  Penwick bit[2] = { Penwick(N), Penwick(N) };

  int answer = 0;
  for (int x=0; x<=N; x++) { // y = 0;
    answer = max(answer, ironX[x] + (cooperX[N] - cooperX[x]));
  }

  set<int> southIron, southCooper;

  for(int y=1; y<=N; y++) {
    int south = ironY[y] - cooperY[y];

    bit[mines[y-1].type].add(mines[y-1].x);

    if (mines[y-1].type == IRON) {
      northIron.erase(mines[y-1].x);
      southIron.insert(mines[y-1].x);
    } else {
      northCooper.erase(mines[y-1].x);
      southCooper.insert(mines[y-1].x);
    }

    for (set<int>::iterator iter = northIron.begin(); iter != northIron.end(); iter++) {
      int x = *iter;
      int west = ironX[x] - cooperX[x];
      int southWest = bit[COOPER].sum(x) - bit[IRON].sum(x);
      int profit = cooperX[N] + south + west + 2*southWest;
      answer = max(answer, profit);
    }

    for (set<int>::iterator iter = southCooper.begin(); iter != southCooper.end(); iter++) {
      int x = *iter;
      int west = ironX[x] - cooperX[x];
      int southWest = bit[COOPER].sum(x) - bit[IRON].sum(x);
      int profit = cooperX[N] + south + west + 2*southWest;
      answer = max(answer, profit);
    }

    {
      int x = 0;
      int west = ironX[x] - cooperX[x];
      int southWest = bit[COOPER].sum(x) - bit[IRON].sum(x);
      int profit = cooperX[N] + south + west + 2*southWest;
      answer = max(answer, profit);
    }

    {
      int x = N;
      int west = ironX[x] - cooperX[x];
      int southWest = bit[COOPER].sum(x) - bit[IRON].sum(x);
      int profit = cooperX[N] + south + west + 2*southWest;
      answer = max(answer, profit);
    }

#ifdef _DEBUG
      // printf("y:%2d x:%2d profit:%3d ... south:%d, west:%d, southWest:%d\n", y, x, profit, south, west, southWest);
    printf("\n");
#endif
  }

  cout << answer << endl;
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
