#include <cstdio>
#include <cstring>

long long int M[100];

long long int toggle(char* str, int len)
{
  // printf("toggle: %s %d\n", str, len);
  *str = *str == '0' ? '1' : '0';

  if (len == 1) {
    return 1;
  }

  bool flag = true;
  for (int i = 1; i < len; i++) {
    if (str[i] == '1') {
      flag = false;
      break;
    }
  }
  if (flag) {
    return M[len];
  }


  long long int answer = 1;
  if (str[1] == '0') {
    answer += toggle(str + 1, len - 1);
  }
  for (int i = 2; i < len; i++) {
    if (str[i] == '1') {
      answer += toggle(str + i, len - i);
    }
  }

  return answer;
}

void solveCase ()
{
  char B[100];
  int len;

  scanf("%s\n", B);
  len = strlen(B);

  M[0] = 0;
  M[1] = 1;
  for (int i=2; i<=32; i++) {
    M[i] = M[i-1] * 2 + 1;
  }

  long long int answer = 0;
  for (int i=0; i<len; i++) {
    if (B[i] == '1') {
      answer += toggle(B + i, len - i);
    }
  }

  printf("%lld\n", answer);
}

int main ()
{
  int T;
  scanf("%d\n", &T);
  while (T--) {
    solveCase();
  }
  return 0;
}
