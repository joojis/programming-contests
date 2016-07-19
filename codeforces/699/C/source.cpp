#include <bits/stdc++.h>

#define make_pair mp

using namespace std;

inline bool isGymOpen(int x) { return x&2; }
inline bool isContestOpen(int x) { return x&1; }

void solveCase()
{
  int N;
  int day[101];
  cin >> N;
  for (int i=1; i<=N; i++) {
    cin >> day[i];
  }

  const int DONOTHING = 0;
  const int DOSPORT = 1;
  const int DOCONTEST = 2;
  const int MAX = 321;
  int DP[101][3];

  DP[0][0] = DP[0][1] = DP[0][2] = 0;
  for (int i=1; i<=N; i++) {
    DP[i][DOSPORT] = isGymOpen(day[i]) ? min(DP[i-1][DOCONTEST], DP[i-1][DONOTHING]) : MAX;
    DP[i][DOCONTEST] = isContestOpen(day[i]) ? min(DP[i-1][DOSPORT], DP[i-1][DONOTHING]) : MAX;
    DP[i][DONOTHING] = 1 + min(DP[i-1][DONOTHING], min(DP[i-1][DOSPORT], DP[i-1][DOCONTEST]));
  }
  cout << min(DP[N][DONOTHING], min(DP[N][DOSPORT], DP[N][DOCONTEST])) << endl;
}

int main ()
{
  solveCase();

  return 0;
}
