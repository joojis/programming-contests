#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main ()
{
  vector<char> str(300001, 0);
  scanf("%s", &str[0]);

  long long int answer = 0;
  for (int i=strlen(&str[0])-1; i>=0; i--) {
    answer += (str[i] - '0') % 4 == 0 ? 1 : 0;
    if (i-1 >= 0) {
      int a = (str[i-1] - '0') * 10 + (str[i] - '0');
      answer += a % 4 == 0 ? i : 0;
    }
  }
  cout << answer << endl;
  return 0;
}
