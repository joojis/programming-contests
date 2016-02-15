#include <bits/stdc++.h>

using namespace std;

int main ()
{
  int N;
  scanf("%d", &N);
  long long int answer = 0;
  for (int i=1; i<=N; i++) {
    answer += i * (i+1);
    answer += i * (i+1) / 2;
#ifdef _DEBUG
    printf("i:%d ... %lld\n", i, answer);
#endif
  }
  printf("%lld\n", answer);
  return 0;
}
