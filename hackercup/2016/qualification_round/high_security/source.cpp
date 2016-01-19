#include <stdio.h>
#include <algorithm>
#include <vector>

struct _EmptyLocation {
  int position, size;
  _EmptyLocation(int position, int size)
  {
    this->position = position;
    this->size = size;
  }

  bool isConnectedWith (const _EmptyLocation& other) const {
    return (other.position <= this->position && this->position < other.position + other.size) ||
           (this->position <= other.position && other.position < this->position + this->size);
  }

  bool operator< (const _EmptyLocation& other) const {
    return this->position + this->size < other.position + other.size;
  }
} typedef EmptyLocation;

using namespace std;

int solveCase()
{
  int N;
  scanf("%d\n", &N);

  vector<EmptyLocation> emptyLocations[2];
  for (int i=0; i<2; i++) {
    int count = 0;
    int position;
    for (int j=0; j<N; j++) {
      char ch;
      scanf("%c", &ch);

      if (ch == '.') {
        count++;
        if (count == 1) {
          position = j;
        }
      } else { // ch == 'X'
        if (count > 0) {
          emptyLocations[i].push_back(EmptyLocation(position, count));
        }
        count = 0;
      }
    }
    scanf("\n");
    if (count > 0) {
      emptyLocations[i].push_back(EmptyLocation(position, count));
    }
  }

  int answer = 0;

  vector<EmptyLocation>::iterator a, b;
  a = emptyLocations[0].begin();
  b = emptyLocations[1].begin();

  while (a != emptyLocations[0].end() && b != emptyLocations[1].end()) {
    if (a->size >= 2 && b->size >= 2) {
      if (*a < *b) {
        a++;
      } else {
        b++;
      }
    } else { // a->size == 1 || b->size == 1
      if (a->isConnectedWith(*b)) {
        a++;
        b++;
      } else {
        if (*a < *b) {
          a++;
        } else {
          b++;
        }
      }
    }

    answer++;
  }

  answer += (emptyLocations[0].end() - a) + (emptyLocations[1].end() - b);

  return answer;
}
int main ()
{
  int T;
  scanf("%d", &T);
  for (int i=1; i<=T; i++) {
    printf("Case #%d: %d\n", i, solveCase());
  }
  return 0;
}
