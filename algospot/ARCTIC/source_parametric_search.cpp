#include <cstdio>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

class P {
public:
  double x, y;
  double operator- (const P& rhs) {
    double ax = this->x;
    double bx = rhs.x;
    double ay = this->y;
    double by = rhs.y;
    return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
  }
};

void solve()
{
  int N;
  P p[100];
  double dist[100][100];
  scanf("%d", &N);

  for (int i=0; i<N; i++) {
    scanf("%lf %lf", &p[i].x, &p[i].y);
    for (int j=0; j<i; j++) {
      dist[i][j] = dist[j][i] = p[i] - p[j];
    }
  }

  double low = 0, high = 1444, mid;
  while (low < high && high - low > 0.0001) {
    mid = (low + high) / 2;
    bool isConnected = false;

    vector<bool> isVisited(N, false);
    queue<int> que;
    int visitCount = 0;


    que.push(0);
    while (!que.empty()) {
      int current = que.front();
      que.pop();

      if (isVisited[current]) {
        continue;
      }

      isVisited[current] = true;
      visitCount++;

      if (visitCount == N) {
        isConnected = true;
        break;
      }

      for (int i=0; i<N; i++) {
        if (dist[current][i] <= mid && !isVisited[i]) {
          que.push(i);
        }
      }
    }

    if (isConnected) {
      high = mid;
    } else {
      low = mid;
    }
  }

  printf("%.2lf\n", low, high);
}

int main ()
{
  int N;

  scanf("%d\n", &N);

  while (N--) {
    solve();
  }

  return 0;
}

