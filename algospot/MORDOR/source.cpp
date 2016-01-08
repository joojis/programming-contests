#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Node;

int MAX_NODE;
vector<Node> nodes;
int nodeCount;
int N, Q;

int depth = 0;

class Node {
public:
  int min, max;
  int a, b;
  Node *left, *right;

  pair<int, int> difficulty(int a, int b) {
    pair<int, int> answer;

    if (a <= this->a && this->b <= b) {
      answer = make_pair(this->max, this->min);
    } else if (this->b < a || b < this->a) {
      answer = make_pair(0, 20000);
    } else {
      pair<int, int> lh = this->left->difficulty(a, b);
      pair<int, int> rh = this->right->difficulty(a, b);
      answer = make_pair(std::max(lh.first, rh.first), std::min(lh.second, rh.second));
    }

    return answer;
  }

  static Node* build(vector<int>& v, int s, int e)
  {
    Node* node = &nodes[nodeCount++];
    node->a = s;
    node->b = e;

    if (s == e) {
      node->left = node->right = NULL;
      node->min = v[s];
      node->max = v[s];
      return node;
    }

    int mid = (s + e) / 2;
    node->left = build(v, s, mid);
    node->right = build(v, mid + 1, e);
    Node::merge(*node, *node->left, *node->right);

    return node;
  }

  static void merge(Node& node, const Node& lhs, const Node& rhs)
  {
    node.min = std::min(lhs.min, rhs.min);
    node.max = std::max(lhs.max, rhs.max);
  }
};


void solveCase()
{
  scanf("%d %d", &N, &Q);

  vector<int> H(N, 0);
  for (int i=0; i<N; i++) {
    scanf("%d", &H[i]);
  }

  MAX_NODE = N * 2;
  nodes = vector<Node>(MAX_NODE);
  nodeCount = 0;
  Node* root = Node::build(H, 0, N - 1);

  for (int i=0; i<Q; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    pair<int, int> maxmin = root->difficulty(a, b);
    printf("%d\n", maxmin.first - maxmin.second);
  }
}

int main ()
{
  int C;
  scanf("%d", &C);
  while (C--) {
    solveCase();
  }
  return 0;
}
