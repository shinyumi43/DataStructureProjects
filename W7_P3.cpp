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
	void postorder(Node*);
};

Tree::Tree(int data) {
	Node* node = new Node(data);
	this->root = node;
	node_v.push_back(node);
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
}

void Tree::postorder(Node* node) {
	if (!node) return;

	for (int i = 0; i < node->chi_v.size(); i++) {
		postorder(node->chi_v[i]);
	}
	if (node->par == nullptr) cout << 0 << " ";
	else cout << node->par->data << " ";
}

int main() {
	int T, N, x, y;
	cin >> T;
	for (int i = 0; i < T; i++) {
		Tree tree(1);
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> x >> y;
			tree.insertNode(x, y);
		}
		tree.postorder(tree.root);
		cout << endl;
	}
	return 0;
}