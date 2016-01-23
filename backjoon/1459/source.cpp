#include <stdio.h>

int main ()
{
  long long int X, Y, W, S;
  long long int answer = 0;
  scanf("%lld %lld %lld %lld", &X, &Y, &W, &S);

  long long int min = X < Y ? X : Y;
  long long int max = X > Y ? X : Y;

  if (2 * W <= S) {
    answer = (X + Y) * W;
  } else if (W <= S) {
    answer = min * S + (max-min) * W;
  } else {
    answer = ((min + ((max-min)&(0xFFFFFFFFFFFFFFFE))) * S) + (((max-min)&1) * W);
  }

  printf("%lld\n", answer);

  return 0;
}
