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
	vector<Node*> node_v;

	BST() { this->root = nullptr; }
	Node* search(int data);
	void insert(int data);
	void remove(int data);
	void inorder(Node* node);
	Node* findMin(Node* node);
	void sub(int data);
};

Node* BST::search(int data) {
	Node* curN = this->root;
	while (curN != nullptr) {
		if (curN->data == data) { return curN; }
		else if (curN->data < data) { curN = curN->right; }
		else { curN = curN->left; }
	}
	return nullptr;
}

void BST::insert(int data) {
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
	else { parN->setLeft(node); }
}

void BST::inorder(Node* node) {
	if (node != nullptr) {
		inorder(node->left);
		node_v.push_back(node);
		inorder(node->right);
	}
}

Node* BST::findMin(Node* node) {
	if (node == nullptr) { return nullptr; }

	if (node->left == nullptr) { return node; }
	else {
		return findMin(node->left);
	}
}

void BST::sub(int data) {
	if (this->search(data) == nullptr) { cout << 0 << endl; }
	else {
		Node* node = this->search(data);
		inorder(node);
		cout << node_v.size() << endl;
		node_v.clear();
	}
}

void BST::remove(int data) {
	Node* node = this->search(data);
	Node* parN = node->par;

	if (node->left == nullptr && node->right == nullptr) {
		if (node == root) { root = nullptr; return; }

		if (data > parN->data) { parN->setRight(nullptr); }
		else { parN->setLeft(nullptr); }
	}
	else if (node->left == nullptr && node->right != nullptr) {
		if (node == root) { root = node->right; return; }

		if (parN->data < node->right->data) { parN->setRight(node->right); }
		else { parN->setLeft(node->right); }
	}
	else if (node->left != nullptr && node->right == nullptr) {
		if (node == root) { root = node->left; return; }

		if (parN->data < node->left->data) { parN->setRight(node->left); }
		else { parN->setLeft(node->left); }
	}
	else {
		Node* minNode = findMin(node->right);
		remove(minNode->data);
		if (node == root) { root->data = minNode->data; }
		else { node->data = minNode->data; }
	}
}

int main() {
	int N, x;
	string str;
	BST BS;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "insert") { cin >> x; BS.insert(x); }
		else if (str == "sub") { cin >> x; BS.sub(x); }
		else if (str == "delete") { cin >> x; BS.remove(x); }
	}
	return 0;
}