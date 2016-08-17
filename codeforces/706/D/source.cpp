#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Node {
public:
	Node *zeroChild = NULL, *oneChild = NULL, **self = NULL;
	int depth = 0;
	int count = 0;
};

void add (Node* node, int x)
{
	if (node->depth == 31) {
		node->count++;
		return;
	}

	if (x & (1 << (30 - node->depth))) { // insert 1
		if (node->oneChild != NULL) {
			add(node->oneChild, x);
		}
		else {
			Node *temp = new Node();
			temp->depth = node->depth + 1;
			temp->self = &node->oneChild;
			node->oneChild = temp;
			add(node->oneChild, x);
		}
	}
	else {
		if (node->zeroChild != NULL) {
			add(node->zeroChild, x);
		}
		else {
			Node *temp = new Node();
			temp->depth = node->depth + 1;
			temp->self = &node->zeroChild;
			node->zeroChild = temp;
			add(node->zeroChild, x);
		}
	}
}

void erase (Node* node, int x)
{
	if (node->depth == 31) {
		node->count--;
		if (node->count == 0) {
			*node->self = NULL;
			delete node;
		}
		return;
	}
	if (x & (1 << (30 - node->depth))) {
		erase(node->oneChild, x);
	}
	else {
		erase(node->zeroChild, x);
	}

	if (node->oneChild == NULL && node->zeroChild == NULL) {
		*node->self = NULL;
		delete node;
	}
}

int query (Node* node, int x)
{
	if (node->zeroChild == NULL) {
		if (node->depth == 30) {
			return 1;
		}
		return (1 << (30 - node->depth)) | query(node->oneChild, x);
	}
	else if (node->oneChild == NULL) {
		if (node->depth == 30) {
			return 0;
		}
		return (0 << (30 - node->depth)) | query(node->zeroChild, x);
	}

	if (x & (1 << (30 - node->depth))) { // look 0
		if (node->depth == 30) {
			return 0;
		}
		return (0 << (30 - node->depth)) | query(node->zeroChild, x);
	}
	else { // look 1
		if (node->depth == 30) {
			return 1;
		}
		return (1 << (30 - node->depth)) | query(node->oneChild, x);
	}
}

void solveCase()
{
	int N;
	cin >> N;

	Node root;
	root.depth = 1;

	add(&root, 0);
	for (int i = 0; i < N; i++) {
		char cmd;
		int x;
		cin >> cmd >> x;
		if (cmd == '+') {
			add(&root, x);
		}
		else if (cmd == '-') {
			erase(&root, x);
		}
		else if (cmd == '?') {
			cout << (x ^ query(&root, x)) << endl;
		}
		else {
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!! input error" << endl;
			vector<int> a(1000000000);
			while (1);
		}
	}

}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	solveCase();
	return 0;
}