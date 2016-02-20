#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

bool hasIntersection1D(int a, int b, int i, int j)
{
  // Line for a-b, i-j
  return !(b<=i || j<=a);
}

bool hasIntersection2D(int a, int b, int c, int d, int i, int j, int k, int l)
{
  // Rectangle for ab-cd, ij-kl;
  return hasIntersection1D(a, c, i, k) && hasIntersection1D(b, d, j, l);
}

int main ()
{
  int N;
  scanf("%d", &N);
  set<int> xSet, ySet;
  vector<PII> papers;
  for (int i=0; i<N; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    papers.push_back(make_pair(x, y));
    xSet.insert(x);
    xSet.insert(x + 10);
    ySet.insert(y);
    ySet.insert(y + 10);
  }

  vector<int> xx, yy;
  xx.insert(xx.end(), xSet.begin(), xSet.end());
  yy.insert(yy.end(), ySet.begin(), ySet.end());

  int answer = 0;
  for (int i=0; i+1<xx.size(); i++) {
    for (int j=0; j+1<yy.size(); j++) {
      for (int k=0; k<papers.size(); k++) {
        if (hasIntersection2D(xx[i], yy[j], xx[i+1], yy[j+1], papers[k].first, papers[k].second, papers[k].first+10, papers[k].second+10)) {
          answer += (xx[i+1] - xx[i]) * (yy[j+1] - yy[j]);
          break;
        }
      }
    }
  }
  printf("%d\n", answer);

  return 0;
}
