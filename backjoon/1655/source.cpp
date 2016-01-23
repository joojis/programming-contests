#include <stdio.h>
#include <functional>
#include <queue>

using namespace std;

int main ()
{
  priority_queue<int, vector<int>, less<int> > left;
  priority_queue<int, vector<int>, greater<int> > right;
  int N;
  scanf("%d", &N);

  for (int i=0; i<N; i++) {
    int temp;
    scanf("%d", &temp);
    if (left.empty() || temp <= left.top()) {
      left.push(temp);
    } else {
      right.push(temp);
    }

    while (left.size() < right.size()) {
      left.push(right.top());
      right.pop();
    }

    while (left.size() - 1 > right.size()) {
      right.push(left.top());
      left.pop();
    }

    printf("%d\n", left.top());
  }
  return 0;
}
