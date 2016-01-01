#include <stdio.h>

int main ()
{
  int N;
  scanf("%d\n", &N);
  while (N--) {
    for (int i = 3; i >= 0; i--) {
      int num = 0;
      for (int k = 128; k > 0; k >>= 1) {
        char ch;
        scanf("%c", &ch);
        num += ch == '1' ? k : 0;
      }
      if (i) {
        printf("%d.", num);
      } else {
        scanf("\n");
        printf("%d\n", num);
      }
    }
  }

  return 0;
}
