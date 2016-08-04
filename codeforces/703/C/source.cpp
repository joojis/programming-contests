#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

void solveCase()
{
  int N, W, V, U;
  cin >> N >> W >> V >> U;

  pair<int, int> vertices[10000], leftTop, rightBottom;
  leftTop.x = 1987654321;
  leftTop.y = -1987654321;
  rightBottom.x = -1987654321;
  rightBottom.y = 1987654321;
  int leftTopIndex, rightBottomIndex;
  for (int i=0; i<N; i++) {
    cin >> vertices[i].x >> vertices[i].y;
    if ((vertices[i].x < leftTop.x) ||
        (vertices[i].x == leftTop.x && vertices[i].y > leftTop.y)) {
      leftTop = vertices[i];
      leftTopIndex = i;
    }
    if ((vertices[i].y < rightBottom.y)||
        (vertices[i].y == rightBottom.y && vertices[i].x > rightBottom.x)) {
      rightBottom = vertices[i];
      rightBottomIndex = i;
    }
  }

  bool isPossibleToCrossSimple = true;
  int curr = leftTopIndex;
  int beforeY;
  do {
    if ((double)vertices[curr].x / V < (double)vertices[curr].y / U) {
      isPossibleToCrossSimple = false;
      break;
    }

    beforeY = vertices[curr].y;
    curr = (curr + N - 1) % N;
  } while (beforeY < vertices[curr].y);

  if (isPossibleToCrossSimple) {
    printf("%.8lf\n", (double)W / U);
    return;
  }

  curr = rightBottomIndex;
  int waitingIndex = -1;
  int beforeX = 0;
  beforeY = 0;
  double answer = 0;
  do {
    if ((double)vertices[curr].x / V > ((double)beforeX / V) + (double)(vertices[curr].y - beforeY) / U) {
      waitingIndex = curr;
    }
    beforeX = vertices[curr].x;
    beforeY = vertices[curr].y;
    curr = (curr + 1) % N;
  } while (beforeX < vertices[curr].x);

  if (waitingIndex == -1) {
    printf("%.8lf\n", (double)W / U);
  } else {
    printf("%.8lf\n", ((double)vertices[waitingIndex].x / V) + ((double)(W - vertices[waitingIndex].y) / U));
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
