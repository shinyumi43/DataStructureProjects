#include <iostream>
#include <vector>
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
	void preorder(Node*);
};

Tree::Tree(int data) {
	Node* node = new Node(data);
	this->root = node;
	this->node_v.push_back(node);
}

void Tree::insertNode(int par_data, int data) {
	for (int i = 0; i < node_v.size(); i++) {
		if (node_v[i]->data == par_data) {
			Node* node = new Node(data);
			node->par = node_v[i];
			node_v[i]->chi_v.push_back(node);
			node_v.push_back(node);
			return;
		}
	}
}

void Tree::preorder(Node* node) {
	if (!node) return;

	if (node->par == nullptr) cout << 0 << " ";
	else cout << node->par->data << " ";
	for (int i = 0; i < node->chi_v.size(); i++) {
		preorder(node->chi_v[i]);
	}
}

int main() {
	int T, N, x, y;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		Tree tree(1);
		for (int j = 0; j < N; j++) {
			cin >> x >> y;
			tree.insertNode(x, y);
		}
		tree.preorder(tree.root);
		cout << endl;
	}
	return 0;
}