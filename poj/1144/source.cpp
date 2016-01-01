#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <vector>

using namespace std;

void readEdges(vector<int> *A)
{
  char tempCh;

  int from;
  int to;

  do {
    scanf("%d", &from);
    if (from == 0) {
      break;
    }
    do {
      scanf("%c", &tempCh);
      if (tempCh == '\n') {
        break;
      }
      scanf("%d", &to);

      A[from].push_back(to);
      A[to].push_back(from);
    } while (true);
  } while (true);
}


int preorder = 0;
int answer = 0;

int findLow(vector<int>* edges, int* orders, int* lows, int* visits, int current, int parent)
{
  if (visits[current]) {
    return lows[current];
  }
  visits[current] = 1;
  lows[current] = ++preorder;
  orders[current] = lows[current];
  bool isAP = false;
  int child = 0;

  for (int i = 0; i < edges[current].size(); i++) {
    int tmp;
    int target = edges[current][i];
    if (target == parent) {
      continue;
    }

    if (visits[target] && target != parent) {
      tmp = orders[target];
    }
    else if (!visits[target]) {
      child++;
      tmp = findLow(edges, orders, lows, visits, target, current);

      if (lows[target] >= orders[current] && parent != 0) {
        isAP = true;
      }
    }
    if (lows[current] > tmp) {
      lows[current] = tmp;
    }
  }

  if (parent == 0 && child > 1) {
    isAP = true;
  }

  answer += isAP ? 1 : 0;

  return lows[current];
}

void solve(int N)
{
  vector<int> A[101];
  int low[101] = { 0, };
  int order[101] = { 0, };
  int visited[101] = { 0, };

  readEdges(A);

  preorder = 0;
  answer = 0;
  findLow(A, order, low, visited, 1, 0);

  printf("%d\n", answer);
}

int main()
{
  int n;

  do {
    scanf("%d", &n);
    if (n == 0) {
      break;
    }
    solve(n);
  } while (true);

  return 0;
}
