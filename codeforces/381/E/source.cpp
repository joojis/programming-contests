#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

class Node;
vector<Node> nodePool;
int nodeCount;

class Node {
public:
  int start, end;
  int unclosedOpen, unopenedClose, match;
  Node *left, *right;

  Node* query(int start, int end)
  {
    if (start <= this->start && this->end <= end) {
      return this;
    } else if (this->end < start || end < this->start) {
      return NULL;
    } else {
      Node* lhs = this->left->query(start, end);
      Node* rhs = this->right->query(start, end);
      if (lhs != NULL && rhs != NULL) {
        Node* res = &nodePool[nodeCount++];
        Node::merge(res, lhs, rhs);
        return res;
      } else if (lhs != NULL) {
        return lhs;
      } else if (rhs != NULL) {
        return rhs;
      } else {
        return NULL;
      }
    }
  }

  static Node* build(vector<char>& v, int start, int end)
  {
    Node* node = &nodePool[nodeCount++];
    node->start = start;
    node->end = end;
    if (start == end) {
      node->match = 0;
      node->left = node->right = NULL;
      if (v[start] == '(') {
        node->unclosedOpen = 1;
        node->unopenedClose = 0;
      } else if (v[start] == ')') {
        node->unclosedOpen = 0;
        node->unopenedClose = 1;
      }
    } else {
      int mid = (start + end) / 2;
      node->left = build(v, start, mid);
      node->right = build(v, mid + 1, end);
      Node::merge(node, node->left, node->right);
    }

    return node;
  }

  static void merge(Node* outParam, const Node* left, const Node* right)
  {
    int mergedMatch = min(left->unclosedOpen, right->unopenedClose);

    outParam->match = left->match + right->match + mergedMatch;
    outParam->unclosedOpen = left->unclosedOpen + right->unclosedOpen - mergedMatch;
    outParam->unopenedClose = left->unopenedClose + right->unopenedClose - mergedMatch;
  }
};

int main ()
{
  vector<char> str(1000001, 0);

  scanf("%s", &str[0]);

  nodePool = vector<Node>(str.size() * 4);
  nodeCount = 0;

  Node* root = Node::build(str, 0, strlen(&str[0]) - 1);

  int Q;
  scanf("%d", &Q);
  while (Q--) {
    int queryA, queryB;
    scanf("%d %d", &queryA, &queryB);

    nodeCount = str.size() * 2 + 100;
    Node* result = root->query(queryA - 1, queryB - 1);
    printf("%d\n", result->match * 2);
  }

  return 0;
}
