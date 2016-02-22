#include <vector>
#include <cstdio>

using namespace std;

int main ()
{
  int n, k;
  scanf("%d %d\n", &n, &k);

  vector<char> str(n+1);
  scanf("%s", &str[0]);

  int a = 'a';
  int z = 'z';
  for (int i=0; i<n; i++) {
    if (str[i] < (a+z)/2) {
      int m = z - str[i];
      if (k > m) {
        str[i] = z;
        k -= m;
      } else {
        str[i] += k;
        k -= m;
        break;
      }
    } else {
      int m = str[i] - a;
      if (k > m) {
        str[i] = a;
        k -= m;
      } else {
        str[i] -= k;
        k -= m;
        break;
      }
    }
  }

  if (k>0) {
    printf("-1\n");
  } else {
    printf("%s\n", str.begin());
  }

  return 0;
}
