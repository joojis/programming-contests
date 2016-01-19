#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class H {
public:
  int type;
  long long int size;
  long long int position;
  int repeat;

  static struct _Comparer {
    bool operator() (const H& left, const H& right) const
    {
      return left.position < right.position;
    }
    bool operator() (long long int left, const H& rightH) const
    {
      return left < rightH.position;
    }
    bool operator() (const H& leftH, long long int right) const
    {
      return leftH.position < right;
    }
  } Comparer;
};

void re()
{
  re();
}

const int ANSWERS = 100000;
int Answers[ANSWERS] = {0,};
vector<H> seq;
int findSeq(long long int position)
{
  if (position < ANSWERS && Answers[position]) {
    return Answers[position];
  }

  vector<H>::iterator iter = upper_bound(seq.begin(), seq.end(), position, H::Comparer) - 1;

  int answer;
  if (iter->type == 1)
    answer = iter->repeat;
  else if (iter->repeat == 1)
    answer = findSeq((position - iter->position) + 1);
  else
    answer = findSeq((position - iter->position) % (iter->size / iter->repeat) + 1);

  if (position >= ANSWERS) {
    return answer;
  }

  Answers[position] = answer;
  return answer;
}

int main ()
{
  int M, N;
  scanf("%d", &M);

  long long int length = 0;
  for (int i=0; i<M; i++) {
    int type;
    scanf("%d", &type);

    H h;
    h.type = type;
    h.position = length + 1;
    if (type == 1) {
      int newNumber;
      scanf("%d", &newNumber);

      h.repeat = newNumber;
      h.size = 1;
    } else { // type == 2
      int l, c;
      scanf("%d %d", &l, &c);

      h.repeat = c;
      h.size = (long long int)l * c;
    }

    length += h.size;
    seq.push_back(h);
  }

  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    long long int target;
    cin >> target;
    printf("%d ", findSeq(target));
  }

  return 0;
}
