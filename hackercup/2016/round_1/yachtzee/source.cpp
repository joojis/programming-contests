#include <stdio.h>
#include <algorithm>

typedef long long unsigned llu;

int N, A, B;
llu C[100001];
llu CSqr[100001];
llu CSqrSum[100001];

double getCumulativeDistribution (int k)
{
  llu quotient = k / C[N];
  llu remainder = k % C[N];

  int index = std::upper_bound(C, C+N+1, remainder) - C - 1;

  CSqrSum[0] = CSqr[0] * CSqr[0];
  for (int i=1; i <= (quotient > 0 ? N : index); i++) {
    CSqrSum[i] = CSqrSum[i-1] + CSqr[i];
#ifdef _DEBUG
    printf("   CSqrSum[%d] = %llu\n", i, CSqrSum[i]);
#endif
  }

  llu answer = 0;

  answer += CSqrSum[index];
  answer += quotient * CSqrSum[N];
  answer += (remainder - C[index]) * (remainder - C[index]);

#ifdef _DEBUG
  printf("   quotient: %llu, remainder: %llu\n", quotient, remainder);
  printf("     answer: %llu\n", answer);
#endif

  return answer / (double) 2;
}

double solveCase ()
{
  scanf("%d %d %d", &N, &A, &B);
  C[0] = CSqr[0] = 0;
  for (int i=1; i<=N; i++) {
    scanf("%d", C+i);
    CSqr[i] = C[i] * C[i];
    C[i] += C[i-1];
  }

  return (getCumulativeDistribution(B) - getCumulativeDistribution(A)) / (B - A);
}

int main ()
{
  int T;
  scanf("%d", &T);
  for (int i=1; i<=T; i++) {
    printf("Case #%d: %.9lf\n", i, solveCase());
  }
  return 0;
}
