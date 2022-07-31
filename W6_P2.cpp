#include <vector>
#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* par;
	vector<Node*> chi_v;

	Node(int data) {
		this->data = data;
		this->par = nullptr;
	}
};

class Tree {
public:
	Node* root;
	vector<Node*> node_v;

	Tree(int);
	void insertNode(int, int);
	void printDepth(int);
};

Tree::Tree(int data) {
	Node* node = new Node(data);
	this->root = node;
	this->node_v.push_back(node);
}

void Tree::insertNode(int par_data, int data) {
	Node* node = new Node(data);
	for (int i = 0; i < node_v.size(); i++) {
		if (node_v[i]->data == par_data) {
			node_v[i]->chi_v.push_back(node);
			node_v.push_back(node);
			node->par = node_v[i];
			return;
		}
	}
	cout << -1 << endl;
}

void Tree::printDepth(int data) {
	Node* curNode;
	Node* parNode;
	int depth = 0;
	for (int i = 0; i < node_v.size(); i++) {
		if (node_v[i]->data == data) {
			if (node_v[i] == root) {
				cout << depth << endl;
				return;
			}
			else {
				curNode = node_v[i];
				parNode = curNode->par;
				while (parNode != nullptr) {
					depth++;
					parNode = parNode->par;
				}
				cout << depth << endl;
				return;
			}
		}
	}
	cout << -1 << endl;
}

int main() {
	int N, M, x, y;
	cin >> N >> M;
	Tree tree(1);

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		tree.insertNode(x, y);
	}

	for (int i = 0; i < M; i++) {
		cin >> x;
		tree.printDepth(x);
	}

	return 0;
}