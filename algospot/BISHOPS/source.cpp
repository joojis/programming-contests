#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

const int OFFSET = 1000;


int C[100][100];
int aCount;
int bCount;
int bMatch[100];
bool visited[100];

int dfs(int a)
{
  if (visited[a]) {
    return false;
  }
  visited[a] = true;
  for (int b=0; b<bCount; b++) {
    if (!C[a][b]) {
      continue;
    }
    if (bMatch[b] == -1 || dfs(bMatch[b])) {
      bMatch[b] = a;
      return true;
    }
  }

  return false;
}

int match()
{
  fill(bMatch, bMatch + bCount, -1);
  int answer = 0;
  for (int a=0; a<aCount; a++) {
    fill(visited, visited + aCount, false);
    answer += dfs(a);
  }
  return answer;
}

void solveCase ()
{
  memset(C, 0, sizeof(C));

  int N;
  int Map[10][10] = {0,};
  scanf("%d\n", &N);
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) {
      scanf("%c", Map[i] + j);
    }
    scanf("\n");
  }


  int id = OFFSET;
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) {
      int k = i, l = j;
      while (Map[k][l] == '.' && k <= N && l <= N) {
        Map[k][l] = id;
        k++;
        l++;
      }
      if (k != i)
        id++;
    }
  }
  bCount = id - OFFSET;

  id = 0;
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) {
      int k = i, l = j;
      while (Map[k][l] >= OFFSET && k <= N && l >= 1) {
        C[id][Map[k][l] - OFFSET] = 1;
        Map[k][l] = '.';
        k++;
        l--;
      }
      if (k != i)
        id++;
    }
  }
  aCount = id;

  printf("%d\n", match());
}

int main ()
{
  int T;
  scanf("%d", &T);
  while (T--) {
    solveCase();
  }
  return 0;
}
