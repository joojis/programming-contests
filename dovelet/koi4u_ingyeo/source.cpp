#include <stdio.h>

#define LL long long int

const int MOD = 100000000;

int fastSquaring(LL N, LL M, int mod)
{
  LL ans = 1;
  int tmp = 1;

  N %= mod;
  for (LL i=1; i<=M; i<<=1) {
    if ((i&M) > 0) {
      ans *= tmp;
      ans %= mod;
    }
    tmp *= tmp;
    tmp %= mod;
  }
  return ans;
}

int last8_pow(int a, int b)
{
  LL answer = 1;
  LL sqr = a;

  while (b > 0) {
    if (b & 1) {
      answer *= sqr;
      answer %= MOD;
    }
    sqr *= sqr;
    sqr %= MOD;
    b >>= 1;
  }

  return answer;
}

int main ()
{
  int N;
  scanf("%d", &N);
  LL answer = 0;
  for (int i=1; i<=N; i++) {
    answer += last8_pow(i, i);
  }
  printf("%08lld\n", answer % MOD);
  return 0;
}
