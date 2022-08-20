#include <iostream>
#include <vector>
using namespace std;

class Node {
private:
	int data;
	Node* par;
	Node* left;
	Node* right;

public:
	Node(int data) {
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
		this->par = nullptr;
	}

	void setLeft(Node* node) {
		if (node == nullptr) { this->left = nullptr; }
		else {
			this->left = node;
			node->par = this;
		}
	}

	void setRight(Node* node) {
		if (node == nullptr) { this->right = nullptr; }
		else {
			this->right = node;
			node->par = this;
		}
	}

	friend class BST;
};

class BST {
public:
	Node* root;
	vector<int> node_v;

	BST() { this->root = nullptr; }

	void insert(int data) {
		Node* node = new Node(data);
		if (this->root == nullptr) { this->root = node; return; }

		Node* parN = nullptr;
		Node* curN = this->root;

		while (curN != nullptr) {
			if (data > curN->data) {
				parN = curN;
				curN = curN->right;
			}
			else {
				parN = curN;
				curN = curN->left;
			}
		}

		if (data > parN->data) { parN->setRight(node); }
		else if (data < parN->data) { parN->setLeft(node); }
	}

	void inorder(Node* node) {
		if (node != nullptr) {
			inorder(node->left);
			node_v.push_back(node->data);
			inorder(node->right);
		}
	}
};

int main() {
	int T, N, n, m;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		BST BS;
		for (int j = 0; j < N; j++) {
			cin >> n;
			BS.insert(n);
		}
		cin >> m;
		BS.inorder(BS.root);
		cout << BS.node_v[m - 1] << endl;
	}
	return 0;
}