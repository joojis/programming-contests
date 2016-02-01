#include <stdio.h>
#include <vector>

using namespace std;

typedef long long int LL;
typedef vector<LL> VLL;

VLL fib;
VLL stack;

bool query(int n, int i)
{
  bool answer = false;
  stack.push_back(fib[i]);
  n -= fib[i];
  if (n < 0) {
    answer = false;
  } else if (n == 0) {
    answer = true;
    for (int j=stack.size() - 1; j>0; j--) {
      printf("%lld ", stack[j]);
    }
    printf("\n");
  } else {
    for (int j=i-1; j>0; j--) {
      if (query(n, j)) {
        answer = true;
        break;
      }
    }
  }
  stack.pop_back();
  return answer;
}

int main ()
{
  fib.push_back(0);
  fib.push_back(1);
  for (int i=2; fib[i-1] <= 1000000000; i++) {
    fib.push_back(fib[i-1] + fib[i-2]);
  }
  fib.push_back(0);
#ifdef _DEBUG
  printf("fib[%d] = %lld\n", fib.size() - 1, fib.back());
#endif

  int N;
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    int t;
    scanf("%d", &t);
    query(t, fib.size()-1);
  }

  return 0;
}
