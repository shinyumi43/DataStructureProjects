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
	Node(int data);
	void setLeft(Node* node);
	void setRight(Node* node);

	friend class BST;
};

Node::Node(int data) {
	this->data = data;
	this->par = nullptr;
	this->left = nullptr;
	this->right = nullptr;
}

void Node::setLeft(Node* node) {
	if (node == nullptr) { this->left = nullptr; return; }
	else {
		this->left = node;
		node->par = this;
	}
}

void Node::setRight(Node* node) {
	if (node == nullptr) { this->right = nullptr; return; }
	else {
		this->right = node;
		node->par = this;
	}
}

class BST {
public:
	Node* root;

	BST();
	Node* search(int data);
	void insert(int data);
	void remove(int data);
	Node* findMin(Node* node);
	void depth(int data);
};

BST::BST() { this->root = nullptr; }

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

Node* BST::search(int data) {
	Node* node = this->root;
	while (node != nullptr) {
		if (data == node->data) return node;
		else if (data > node->data) node = node->right;
		else node = node->left;
	}
	return nullptr;
}

Node* BST::findMin(Node* node) {
	if (node == nullptr) { return nullptr; }

	if (node->left == nullptr) { return node; }
	else { return findMin(node->left); }
}

void BST::depth(int data) {
	int depth = 0;
	Node* node = this->root;
	while (node != nullptr) {
		if (data == node->data) {cout << depth << endl; return;}
		else if (data > node->data) { node = node->right; depth++; }
		else { node = node->left; depth++; }
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
	else if (node->left != nullptr && node->right == nullptr) {
		if (node == root) { root = node->left; return; }

		if (node->left->data > parN->data) { parN->setRight(node->left); }
		else { parN->setLeft(node->left); }
	}
	else if (node->left == nullptr && node->right != nullptr) {
		if (node == root) { root = node->right; return; }

		if (node->right->data > parN->data) { parN->setRight(node->right); }
		else { parN->setLeft(node->right); }
	}
	else {
		Node* minNode = this->findMin(node->right);
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
		else if (str == "delete") { cin >> x; BS.remove(x); }
		else if (str == "depth") { cin >> x; BS.depth(x); }
	}
	return 0;
}