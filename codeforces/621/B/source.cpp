#include <stdio.h>
#include <vector>

using namespace std;

int main ()
{
  vector<int> plus, minus;
  int N;
  scanf("%d", &N);

  plus = vector<int>(2222);
  minus = vector<int>(2222);

  long long int answer = 0;
  for (int i=0; i<N; i++) {
    int x, y;
    scanf("%d %d", &x, &y);

    int a = x + y - 2;
    int b = (1000-1) + (x - y);

#ifdef _DEBUG
    printf("x:%d y:%d ... plus[a]:%d minus[b]:%d\n", x, y, plus[a], minus[b]);
#endif

    answer += plus[a] + minus[b];
    plus[a]++;
    minus[b]++;
  }
  printf("%I64d\n", answer);
  return 0;
}
