#include <stdio.h>

int main ()
{
  int N, P;
  int denom[100000], num[100000];
  scanf("%d %d", &N, &P);
  for (int i=0; i<N; i++) {
    int l, r;
    scanf("%d %d", &l, &r);

    int rr = r / P;
    int ll = (l-1) / P;
#ifdef _DEBUG
    printf("(%d,%d) => prob: %d / %d, %d %d\n", l, r,  rr-ll, r-l+1, rr, ll);
#endif
    num[i] = rr-ll;
    denom[i] = r-l+1;
  }

  double answer;

  for (int i=0; i<N; i++) {
    int a, b, c;
    a = (i + N - 1) % N;
    b = i;
    c = (i + 1) % N;

    double pa, pb, pc;
    pa = num[a] / (double) denom[a];
    pb = num[b] / (double) denom[b];
    pc = num[c] / (double) denom[c];

    answer += 2*pb + pa*(1-pb) + pc*(1-pb);
#ifdef _DEBUG
    // printf("%lf - %lf + %lf\n", pb * 2, pa * pb + pb * pc, pa * pb * pc * 2);
#endif
  }

  printf("%.8lf\n", answer * 1000);

  return 0;
}
