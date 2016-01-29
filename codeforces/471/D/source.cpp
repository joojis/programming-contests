#include <cstdio>
#include <vector>

using namespace std;

int N, W;
vector<int> A, B;

vector<int> preKMP (vector<int>& B)
{
  int b = 1, m = 0;

  vector<int> res = vector<int>(B.size());
  res[0] = 0;

  while (B.size() > b+m) {
    if (B[m] == B[b+m]) {
      res[b+m] = m+1;
      m++;
    } else {
      if (m == 0) {
        res[b+m] = 0;
        b++;
      } else {
        int nextM = res[m-1];
        b += m - nextM;
        m = nextM;
      }
    }
  }
  return res;
}

int KMP (vector<int>& A, vector<int>& B, vector<int> P)
{
  int b = 0, m = 0;
  int res = 0;

  while (A.size() > b+m) {
    if (A[b+m] == B[m]) {
      m++;
      if (m == B.size()) {
        res++;
        int nextM = P[m - 1];
        b += m - nextM;
        m = nextM;
      }
    } else {
      if (m == 0) {
        b++;
      } else {
        int nextM = P[m-1];
        b += m - nextM;
        m = nextM;
      }
    }
  }

  return res;
}

int main ()
{
  scanf("%d %d", &N, &W);
  A = vector<int>(N-1);
  B = vector<int>(W-1);

  int a, b;

  scanf("%d", &a);
  for (int i=0; i<N-1; i++) {
    scanf("%d", &b);
    A[i] = a - b;
    a = b;
  }

  scanf("%d", &a);
  for (int i=0; i<W-1; i++) {
    scanf("%d", &b);
    B[i] = a - b;
    a = b;
  }

  if (W == 1) {
    printf("%d\n", N);
  } else {
    printf("%d\n", KMP(A, B, preKMP(B)));
  }

  return 0;
}
