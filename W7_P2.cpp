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
	void insertNode(int);
	void postorder(Node*);
};

Tree::Tree(int data) {
	Node* node = new Node(data);
	root = node;
	node_v.push_back(node);
}

void Tree::insertNode(int N) {
	int data, depth;
	vector<int> dep_v;
	for (int i = 0; i < N; i++) {
		cin >> data;
		if (data != 1) {
			Node* node = new Node(data);
			node_v.push_back(node);
		}
	}

	for (int i = 0; i < N; i++) {
		cin >> depth;
		dep_v.push_back(depth);
	}

	Node* parNode = root;

	for (int i = 1; i < N; i++) {
		Node* curNode = node_v[i];
		if (dep_v[i - 1] < dep_v[i]) {
			parNode = node_v[i - 1];
		}
		else if (dep_v[i - 1] > dep_v[i]) {
			for (int j = 0; j < (dep_v[i - 1] - dep_v[i]); j++) {
				parNode = parNode->par;
			}
		}
		curNode->par = parNode;
		parNode->chi_v.push_back(curNode);
	}
}

void Tree::postorder(Node* node) {
	if (!node) return;

	for (int i = 0; i < node->chi_v.size(); i++) {
		postorder(node->chi_v[i]);
	}
	cout << node->data << " ";
}

int main() {
	int T, N;;
	cin >> T;
	for (int i = 0; i < T; i++) {
		Tree tree(1);
		cin >> N;
		tree.insertNode(N);
		tree.postorder(tree.root);
		cout << endl;
	}
	return 0;
}