#include <bits/stdc++.h>

using namespace std;

bool isIncluding1D(double a, double b, double w, double x)
{
  return !(x<=a || b<=w);
}

bool isIncluding(double a, double b, double c, double d,
                 double w, double x, double y, double z)
{
  return isIncluding1D(a, c, w, y) && isIncluding1D(b, d, x, z);
}

struct _Rect {
  double a, b, c, d;
} typedef Rect;

int main ()
{
  int N;
  scanf("%d", &N);
  Rect rects[30];
  set<double> xs, ys;
  for (int i=0; i<N; i++) {
    double a, b, c, d;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    rects[i].a = a;
    rects[i].b = b;
    rects[i].c = a + c;
    rects[i].d = b + d;
    xs.insert(a);
    xs.insert(a+c);
    ys.insert(b);
    ys.insert(b+d);
  }

  vector<double> xv, yv;
  xv.insert(xv.end(), xs.begin(), xs.end());
  yv.insert(yv.end(), ys.begin(), ys.end());

  double answer = 0;
  for (int x=0; x<xv.size()-1; x++) {
    for (int y=0; y<yv.size()-1; y++) {
      for (int r=0; r<N; r++) {
        if (
          isIncluding(
            rects[r].a, rects[r].b, rects[r].c, rects[r].d,
            xv[x], yv[y], xv[x+1], yv[y+1]
          )
        ) {
          answer += (xv[x+1] - xv[x]) * (yv[y+1] - yv[y]);
          break;
        }
      }
    }
  }
  if (answer - (long long unsigned)answer > 0) {
    printf("%.2lf\n", answer);
  } else {
    printf("%llu\n", (long long unsigned)answer);
  }
  return 0;
}
