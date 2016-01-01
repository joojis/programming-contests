#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <set>

using namespace std;

const int MAX_N = 10000;

typedef int NodeId;
class Node {
public:
  vector<NodeId> in, out;
  vector<NodeId>::iterator dfsIter;
};

class SCCNode : public Node {
public:
  set<NodeId> nodeIdSet;
};

Node node[MAX_N + 1];
SCCNode sccNode[MAX_N + 1];

int main()
{
  int N, M;

  scanf("%d %d", &N, &M);
  for (int i = 0; i < M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    node[a].out.push_back(b);
    node[b].in.push_back(a);
  }

  int order = 0;
  int nodeIdsOnOrder[MAX_N] = { 0, };
  bool isVisited[MAX_N] = { 0, };

  stack<NodeId> dfs;
  for (int i = 1; i <= N; i++) {
    if (isVisited[i]) {
      continue;
    }
    dfs.push(i);
    while (!dfs.empty()) {
      NodeId current = dfs.top();
      if (!isVisited[current]) {
        isVisited[current] = true;
        node[current].dfsIter = node[current].out.begin();
      }

      while (node[current].dfsIter != node[current].out.end() && isVisited[*node[current].dfsIter]) {
        node[current].dfsIter++;
      }

      if (node[current].dfsIter == node[current].out.end()) {
        nodeIdsOnOrder[++order] = current;
        dfs.pop();
      } else {
        dfs.push(*node[current].dfsIter);
      }
    }
  }

  int uf[MAX_N + 1] = { 0, };

  for (int i = order; i >= 1; i--) {
    NodeId startingPoint = nodeIdsOnOrder[i];

    queue<NodeId> bfs;
    if (uf[startingPoint] != 0) {
      continue;
    }

    uf[startingPoint] = startingPoint;
    bfs.push(startingPoint);
    while (!bfs.empty()) {
      NodeId current = bfs.front();
      bfs.pop();

      uf[current] = startingPoint;
      vector<NodeId>::iterator iter = node[current].in.begin();
      while (iter != node[current].in.end()) {
        if (uf[*iter] == 0) {
          bfs.push(*iter);
        }
        ++iter;
      }
    }
  }

  set<int> test;
  for (int i = 1; i <= N; i++) {
    test.insert(uf[i]);
  }

  for (int i = 1; i <= N; i++) {
    for (unsigned j = 0; j < node[i].in.size(); j++) {
      if (uf[i] != uf[node[i].in[j]]) {
        test.erase(uf[node[i].in[j]]);
      }
    }
  }

  if (test.size() > 1) {
    printf("0\n");
    return 0;
  }

  int most_popular = *test.begin();
  int count = 0;
  for (int i = 1; i <= N; i++) {
    if (uf[i] == most_popular) {
      count++;
    }
  }

  printf("%d\n", count);

  return 0;
}

