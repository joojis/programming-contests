#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> A, T;
int N;
long long int cost = 0;

void merge_sort(int s, int e)
{
  if (s == e) {
    return;
  }

  int mid = (s + e) / 2;
  merge_sort(s, mid);
  merge_sort(mid + 1, e);

  int tPtr = s;
  int leftItr = s;
  int rightItr = mid + 1;

  while (tPtr <= e) {
    if (leftItr > mid) {
      T[tPtr++] = A[rightItr++];
      continue;
    } else if (rightItr > e) {
      T[tPtr++] = A[leftItr++];
      continue;
    }

    if (A[leftItr] <= A[rightItr]) {
      T[tPtr++] = A[leftItr++];
    } else {
      T[tPtr++] = A[rightItr++];
      cost += mid - leftItr + 1;
    }
  }

  for (int p = s; p <= e; p++) {
    A[p] = T[p];
  }
}

int main ()
{
  cin >> N;
  A = vector<int>(N);
  T = vector<int>(N);
  for (int i=0; i<N; i++) {
    cin >> A[i];
  }

#ifdef _DEBUG
  vector<int> bubble = A;
  for (int i=0; i<N; i++) {
    cout << A[i] << " ";
  }
  cout << endl;
#endif

  merge_sort(0, N-1);
  // cout << cost << endl;
  printf("%I64d\n", cost);

#if _DEBUG
  cost = 0;
  for (int i=N; i>0; i--) {
    for (int j=1; j<i; j++) {
      if (bubble[j] < bubble[j-1]) {
        int temp = bubble[j];
        bubble[j] = bubble[j-1];
        bubble[j-1] = temp;
        cost++;
      }
    }
  }
  cout << cost << endl;
#endif


  return 0;
}
