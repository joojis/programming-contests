#include <bits/stdc++.h>

using namespace std;

int N;
struct _BinaryIndexedTree {
  vector<int> arr;
  _BinaryIndexedTree (int N)
  {
    arr = vector<int>(N+1, 0);
  }
  void add(int k)
  {
    while (k<=N) {
      arr[k]++;
      k += k & -k;
    }
  }
  int sum(int k)
  {
    int result = 0;
    while (k>0) {
      result += arr[k];
      k -= k & -k;
    }
    return result;
  }
} typedef BIT;

void solveCase ()
{
  scanf("%d", &N);
  BIT bit1(N);
  BIT bit2(N);
  int H[100000];
  for (int i=0; i<N; i++) {
    scanf("%d", H+i);
  }
  int T[100001];
  for (int i=1; i<=N; i++) {
    scanf("%d", T+i);
  }

  sort(H, H+N);
  stack<int> answer;
  for (int i=N; i>0; i--) {
    int prev = 0, curr = bit1.sum(T[i]+1);
    while (prev != curr) {
      prev = curr;
      curr = bit2.sum(T[i]+curr+1);
    }
    answer.push(H[T[i]+curr]);
    bit1.add(T[i]+1);
    bit2.add(T[i]+curr+1);
  }

  while (!answer.empty()) {
    printf("%d\n", answer.top());
    answer.pop();
  }
}

int main ()
{
#ifdef _TC
  int T;
  scanf("%d", &T);
  while (T--) {
#endif
    solveCase();
#ifdef _TC
    printf("\n");
  }
#endif
  return 0;
}
