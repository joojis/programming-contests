#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void solveCase()
{
  int N;
  cin >> N;
  vector<int> X(N);
  vector<int> V(N);
  for (int i=0; i<N; i++) {
    cin >> X[i];
  }
  for (int i=0; i<N; i++) {
    cin >> V[i];
  }

  double a = 0, b = 500000000;
  while (b-a >= 0.0000001) {
    double time = (a+b)/2;

    double inter_a = 1;
    double inter_b = 1000000000;
    int i;
    for (i=0; i<N; i++) {
      double current_a = X[i] - V[i] * time;
      double current_b = X[i] + V[i] * time;
      if (inter_b < current_a || current_b < inter_a) {
        break;
      }
      inter_a = max(inter_a, current_a);
      inter_b = min(inter_b, current_b);
    }
    if (i==N) {
      b = time;
    } else {
      a = time;
    }
  }
  printf("%.10lf\n", b);
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
