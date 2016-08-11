#include <bits/stdc++.h>

using namespace std;

void solveCase()
{
  int a, b;
  cin >> a >> b;
  int N;
  cin >> N;

  double answer = 987654321;
  for (int i=0; i<N; i++) {
    int x, y, v;
    cin >> x >> y >> v;

    int dx = abs(x - a);
    int dy = abs(y - b);

    double cand = sqrt(dx*dx + dy*dy) / (double)(v);
    if (answer > cand) {
      answer = cand;
    }
  }
  printf("%.8lf\n", answer);
}

int main()
{
#ifdef _DEBUG
  int T;
  scanf("%d\n", &T);
  while (T--) {
#endif
    solveCase();
#ifdef _DEBUG
  }
#endif
  return 0;
}
