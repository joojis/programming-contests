#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int N, K;
int M[333][333] = {0,};

char strings[333][100011];
int lengths[333];

struct _Word {
  int offset;
  int length;
  int id;

  char ch() const
  {
    return ch(0);
  }

  char ch(int i) const
  {
    return offset + i < length ? strings[id][offset + i] : '\0';
  }

  const char* ptr() const
  {
    return strings[id];
  }

  bool operator< (const _Word& other) const
  {
    return this->length < other.length;
  }
} typedef Word;

Word words[333];

struct _Trie;
vector<_Trie> triePool;
int poolCount;

struct _Trie {
  Word word;
  vector<_Trie*> children;
  vector<int> result;
  bool terminal;

  void calculateDistance(Word newWord, int distance)
  {
    if (terminal) {
      M[word.id][newWord.id] = M[newWord.id][word.id] = word.length - word.offset + newWord.length - newWord.offset + distance;
      return;
    }
    for (unsigned i=0; i<this->children.size(); i++) {
      _Trie* child = this->children[i];
      child->calculateDistance(newWord, distance + word.length - word.offset);
    }
  }

  void insert(Word newWord)
  {
    if (terminal) {
      M[word.id][newWord.id] = M[newWord.id][word.id] = newWord.length - newWord.offset;
    }
    _Trie* matchedChild = NULL;
    for (unsigned i=0; i<this->children.size(); i++) {
      _Trie* child = this->children[i];
      if (child->word.ch() == newWord.ch()) {
        matchedChild = child;
      } else {
        child->calculateDistance(newWord, 0);
      }
    }

    if (matchedChild == NULL) {
      _Trie* newChild = &triePool[poolCount++];

      newChild->word = newWord;
      newChild->terminal = true;
      newChild->children.clear();

      this->children.push_back(newChild);

      return;
    }

    int i=0;
    while (matchedChild->word.ch(i) == newWord.ch(i)) i++;

    // ASSERT(newWord.ch(i) != '\0'); // since the length of the word is inserted in non-decreasing order.

    if (matchedChild->word.ch(i) != '\0') { // Case of aX -> aY
      // Make a non-terminal node of 'a' and Add children of X and Y
      _Trie* splittedWordChild = &triePool[poolCount++];

      splittedWordChild->word = matchedChild->word;
      splittedWordChild->word.offset += i;
      splittedWordChild->children.clear();
      splittedWordChild->children.assign(matchedChild->children.begin(), matchedChild->children.end());
      splittedWordChild->terminal = matchedChild->terminal;

      matchedChild->word.length = matchedChild->word.offset + i;
      matchedChild->terminal = false;
      matchedChild->children.clear();
      matchedChild->children.push_back(splittedWordChild);

      newWord.offset += i;
      matchedChild->insert(newWord);
    } else { // Case of aaX -> aa
      newWord.offset += i;
      matchedChild->insert(newWord);
    }
  }
} typedef Trie;

vector<int>& dc (Trie* current)
{
  for (unsigned i=0; i<current->children.size(); i++) {
    vector<int>& v = dc(current->children[i]);

    current->result.insert(current->result.end(), v.size(), 333 * 300000);

    vector<int> u(current->result.size(), 333 * 300000);
    for (unsigned vCount = 0; vCount < v.size(); vCount++) {
      for (unsigned uCount = vCount; uCount < u.size(); uCount++) {
        u[uCount] = min(u[uCount], v[vCount] + (uCount - vCount == 0 ? 0 : current->result[uCount - (vCount + 1)]));
      }
    }

    for (unsigned uCount = 0; uCount < u.size(); uCount++) {
      current->result[uCount] = min(current->result[uCount], u[uCount]);
    }
  }

  int cost = (current->word.length - current->word.offset) * 2 + (current-> terminal ? 1 : 0);

  for (unsigned i=0; i<current->result.size(); i++) {
    current->result[i] += cost;
  }
  if (current->terminal) {
    current->result.insert(current->result.begin(), cost);
  }

  return current->result;
}

int solveCase()
{
  triePool = vector<Trie>(1000);
  poolCount = 0;

  scanf("%d %d\n", &N, &K);
  for (int i=0; i<N; i++) {
    scanf("%s\n", strings[i]);
    lengths[i] = strlen(strings[i]);
    words[i].id = i;
    words[i].offset = 0;
    words[i].length = lengths[i];
    fill(M[i], M[i] + N + 1, 333 * 200000 + 1);
  }
  strings[N][0] = '\0'; // strings[N] == "";
  lengths[N] = 0;
  words[N].id = N;
  words[N].offset = 0;
  words[N].length = 0;

  Trie root = triePool[poolCount++];
  root.word = words[N];
  root.terminal = true;

  sort(words, words + N);

  for (int i=0; i<N; i++) {
    root.insert(words[i]);
  }

  root.terminal = false;
  vector<int>& result = dc(&root);

  return result[K - 1];
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
