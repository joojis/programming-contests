#include <bits/stdc++.h>

using namespace std;

struct Comp {
  bool operator() (const char* a, const char* b) const
  {
    return strcmp(a, b) < 0;
  }
};

int main ()
{
  char str[5001];
  scanf("%s", str);
  vector<char*> suffix;
  int len = strlen(str);
  for (int i=0; i<len; i++) {
    suffix.push_back(str+i);
  }
  sort(suffix.begin(), suffix.end(), Comp());
#ifdef _DEBUG
  for (int i=0; i<suffix.size(); i++) {
    printf("%s\n", suffix[i]);
  }
#endif
  int max = 0;
  for (int i=0; i<suffix.size()-1; i++) {
    int k=0;
    while (suffix[i][k] == suffix[i+1][k]) k++;
    max = std::max(max, k);
  }
  printf("%d\n", max);
  return 0;
}
