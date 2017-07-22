#include <iostream>
#include <vector>

using namespace std;

int main ()
{
  int N;
  cin >> N;
  vector<bool> socks(N, false);
  int cnt = 0;
  int answer = 0;
  for (int i=0; i<N*2; i++) {
    int num;
    cin >> num;
    if (socks[num-1] == false) {
      socks[num-1] = true;
      cnt++;
      answer = max(answer, cnt);
    } else {
      cnt--;
    }
  }
  cout << answer << endl;
  return 0;
}
