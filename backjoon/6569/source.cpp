#include <bits/stdc++.h>

using namespace std;

typedef long long int LLI;

void solveCase(int H, int W)
{
  vector<vector<LLI> > D(W+1);
  const int FULL = (1<<H) - 1;
  for (int i=0; i<=W; i++) {
    D[i] = vector<LLI>(FULL + 1, 0);
  }
  vector<int> B;
  for (int i=3; i<=FULL; i++) {
    int t = i;
    while (t) {
      int lsb = t & -t;
      lsb *= 3;
      if (t == (t | lsb)) {
        t -= lsb;
      } else {
        break;
      }
    }
    if (t == 0) {
      B.push_back(i);
    }
  }
  D[0][FULL] = 1;
  for (int w=1; w<=W; w++) {
    queue<pair<int, LLI> > q;
    for (int c=0; c<=FULL; c++) {
      int notC = FULL - c;
      D[w][c] += D[w-1][notC];

      for (int b=0; b<B.size(); b++) {
        if ((c & B[b]) == 0) {
          q.push(make_pair(c|B[b], D[w][c]));
          // D[w][c|B[b]] += D[w][c];
        }
      }
    }
    while (!q.empty()) {
      D[w][q.front().first] += q.front().second;
      q.pop();
    }
  }
  cout << D[W][FULL] << endl;
}

int main ()
{
  int H, W;
  while (true) {
    scanf("%d %d", &H, &W);
    if (!(H * W)) break;
    solveCase(H, W);
  }
  return 0;
}
