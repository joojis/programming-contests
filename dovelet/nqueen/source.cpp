#include <stdio.h>

int N;
int A[3][30] = {0,};
int answer = 0;
int column[30] = {0,};

void printColumn()
{
  for (int j=1; j<=N; j++) {
    printf("%d ", column[j]);
  }
  printf("\n");
}

void bt(int i)
{
  if (i > N) {
    answer++;
    if (answer <= 3) {
      printColumn();
    }
    return;
  }
  for (int j=1; j<=N; j++) {
    if (A[0][j] || A[1][N+i-j] || A[2][i+j]) continue;
    A[0][j] = A[1][N+i-j] = A[2][i+j] = 1;
    column[i] = j;
    bt(i+1);
    A[0][j] = A[1][N+i-j] = A[2][i+j] = 0;
  }
}

int main ()
{
  scanf("%d", &N);

  bt(1);

  printf("%d\n", answer);

  return 0;
}
