#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct _Node;
vector<_Node> nodePool;
int nodePoolCount;

struct _Result {
  int min, max;
} typedef Result;

struct _Node {
  Result result;
  int start, end;
  _Node *left, *right;

  Result query(int a, int b)
  {
    if (a <= start && end <= b) {
      return this->result;
    } else if (b < start || end < a) {
      Result result;
      result.min = 1000000001;
      result.max = 0;
      return result;
    } else {
      Result l, r, m;
      l = left->query(a, b);
      r = right->query(a, b);
      merge(m, l, r);
      return m;
    }
  }

  static _Node* build(vector<int>& v, int start, int end)
  {
    _Node* node = &nodePool[nodePoolCount++];
    node->start = start;
    node->end = end;

    if (start == end) {
      node->result.min = node->result.max = v[start];
      node->right = node->left = NULL;
      return node;
    }

    int mid = (start + end) / 2;
    node->left = build(v, start, mid);
    node->right = build(v, mid + 1, end);
    merge(node->result, node->left->result, node->right->result);

    return node;
  }

  static void merge(Result& parent, Result& left, Result& right)
  {
    parent.min = std::min(left.min, right.min);
    parent.max = std::max(left.max, right.max);
  }
} typedef Node;

int main ()
{
  nodePool = vector<Node>(220000);
  nodePoolCount = 0;

  int N, M;
  scanf("%d %d", &N, &M);
  vector<int> A(N, 0);
  for (int i=0; i<N; i++) {
    scanf("%d", &A[i]);
  }

  _Node* root = Node::build(A, 0, N-1);

  for (int i=0; i<M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    Result result = root->query(a - 1, b - 1);
    printf("%d %d\n", result.min, result.max);
  }

  return 0;
}
