#include <bits/stdc++.h>

using namespace std;

void solveCase()
{
  int N;
  cin >> N;
  vector<int> C(N);
  for (int i=0; i<N; i++) {
    cin >> C[i];
  }
  vector<string> words(N), reverses(N);
  for (int i=0; i<N; i++) {
    cin >> words[i];
    reverses[i].assign(words[i].rbegin(), words[i].rend());
    // cout << words[i] << " : " << reverses[i] << endl;
  }
  const int W = 0, R = 1;
  long long int answer[2][100000];
  answer[W][0] = 0;
  answer[R][0] = C[0];
  for (int i=1; i<N; i++) {
    const long long int MAX = 123456987654321;
    answer[W][i] = answer[R][i] = MAX;

    if (words[i].compare(words[i-1]) >= 0) {
      answer[W][i] = min(answer[W][i], answer[W][i-1]);
    }
    if (words[i].compare(reverses[i-1]) >= 0) {
      answer[W][i] = min(answer[W][i], answer[R][i-1]);
    }
    if (reverses[i].compare(words[i-1]) >= 0) {
      answer[R][i] = min(answer[R][i], answer[W][i-1] + C[i]);
    }
    if (reverses[i].compare(reverses[i-1]) >= 0) {
      answer[R][i] = min(answer[R][i], answer[R][i-1] + C[i]);
    }

    if (answer[W][i] == MAX && answer[R][i] == MAX) {
      cout << -1 << endl;
      return;
    }
  }
  cout << min(answer[W][N-1], answer[R][N-1]) << endl;
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
