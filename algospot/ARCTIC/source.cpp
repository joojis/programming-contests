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

class D {
public:
  int a, b;
  double length;

  bool operator< (const D& rhs) {
    return this->length < rhs.length;
  }
};


int UF[100];
int uf(int n)
{
  if (UF[n] != n) {
    UF[n] = uf(UF[n]);
  }
  return UF[n];
}

bool compare(D* a, D* b)
{
  return *a < *b;
}

void solve()
{
  int N;
  P p[100];
  D d[6000];
  int dc = 0;
  scanf("%d", &N);

  vector<D*> pq;

  for (int i=0; i<N; i++) {
    scanf("%lf %lf", &p[i].x, &p[i].y);
    UF[i] = i;
    for (int j=0; j<i; j++) {
      D* dist = d + (dc++);

      dist->a = i;
      dist->b = j;
      dist->length = p[dist->a] - p[dist->b];

      pq.push_back(dist);
    }
  }

  sort(pq.begin(), pq.end(), compare);
  int count = 0;

  for (int i=0; i<pq.size(); i++) {
    if (uf(pq[i]->a) != uf(pq[i]->b)) {
      UF[pq[i]->a] = UF[pq[i]->b];
      count++;
    }

    if (count == N - 1) {
      printf("%.2lf\n", pq[i]->length);
      return;
    }
  }

  printf("0.00\n");
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

