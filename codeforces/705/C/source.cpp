#include <bits/stdc++.h>

using namespace std;

void solveCase()
{
  int N, Q;
  scanf("%d %d", &N, &Q);
  vector<int> unreads(N+1, 0);
  vector<int> notifications;
  vector<int> lastRead(N+1, -1);
  int lastT = -1;
  int answer = 0;
  for (int i=0; i<Q; i++) {
    int type, x;
    scanf("%d %d", &type, &x);
    if (type == 1) {
      notifications.push_back(x);
      unreads[x]++;
      answer++;
    } else if (type == 2) {
      answer -= unreads[x];
      unreads[x] = 0;
      lastRead[x] = notifications.size() - 1;
    } else if (type == 3) {
      x--;
      if (lastT < x) {
        for (int k = lastT + 1; k <= x; k++) {
          if (lastRead[notifications[k]] < k) {
            unreads[notifications[k]]--;
            answer--;
            lastRead[notifications[k]] = k;
          }
        }
        lastT = x;
      }
    }
    printf("%d\n", answer);
  }
}

int main()
{
#ifdef _DEBUG
  int T;
  scanf("%d\n", &T);
  while (T--) {
#endif
    solveCase();
#ifdef _DEBUG
  }
#endif
  return 0;
}
