#include <stdio.h>

bool solveCase ()
{
  char str[100];
  char *itr;

  scanf("%s\n", str);
#ifdef _DEBUG
  printf("%s\n", str);
#endif

  itr = str;
  int depth = 0;
  while (*itr != '\0') {
    if (*itr == '(') {
      depth++;
    } else { // if *itr == ')'
      depth--;
    }

    if (depth < 0) {
      return false;
    }
    itr++;
  }

  return depth == 0;
}

int main ()
{
  int N;
  scanf("%d\n", &N);
  for (int i=0; i<N; i++) {
    printf("%s\n", solveCase() ? "YES" : "NO");
  }
  return 0;
}
