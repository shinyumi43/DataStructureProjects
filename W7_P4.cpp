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
	void preorder(Node*);
};

Tree::Tree(int data) {
	Node* node = new Node(data);
	this->root = node;
	node_v.push_back(node);
}

void Tree::insertNode(int N) {
	//���� �Է¹ް� �ش� ���� ���� ��带 ����
	int data;
	for (int i = 0; i < N; i++) {
		cin >> data;
		if (data != 1) {
			Node* node = new Node(data);
			node_v.push_back(node);
		}
	}

	//���̸� �迭�� �Է¹����鼭(���� ����� ���̿��� �񱳸� ����) �ִ� ���̸� �ľ�
	int depth, max = -1;
	vector<int> dep_v;
	dep_v.push_back(0);
	for (int i = 0; i < N; i++) {
		cin >> depth;
		if (depth != 0) {
			dep_v.push_back(depth);
		}

		if (depth > max) max = depth;
	}

	//Ư�� ���̿� �����ϴ� ��带 ���� ���� ����(�ϴ� Ư�� ���� ����� �ڽ� ���� ���� ����)
	vector<Node*> temp(max + 1);

	for (int index = 0; index < temp.size(); index++) {
		temp[index] = new Node(index);
	}

	Node* parNode;
	Node* curNode;
	//node_v[0], dep_v[0]���� root�� ������ ��������Ƿ� 1���� ��ȸ
	//dep_v[i]�� dep_v[i + 1]�� ���ϹǷ� N - 2������ ����
	for (int i = 1; i < N - 1; i++) {
		curNode = node_v[i];
		if (dep_v[i] > dep_v[i + 1]) { //���� ����� ���̰� ���� ����� ���̺��� ũ�ٸ�, ���� ��尡 �θ� ��尡 �ǹǷ� �ڽ����� ����
			temp[dep_v[i]]->chi_v.push_back(curNode); //���� ���, �켱������ ���̰� 5�� ����� temp[5]�� �ڽ� ���� ����
			if (dep_v[i] != 1) parNode = node_v[i + 1]; //�θ� ��� ����, ���̰� 1�� �� �̿ܿ��� ���� ���� ����
			else parNode = root;
			for (Node* child : temp[dep_v[i]]->chi_v) { //���̰� ���� ��带 ���� ���� �θ� ��忡 ����
				parNode->chi_v.push_back(child); //�θ��� �ڽ�����, �ڽ��� �θ�� ���� ����
				child->par = parNode;
			}
			temp[dep_v[i]]->chi_v.clear(); //�ռ� ���̰� ���� ��带 ���� �θ�� ���������Ƿ� �ش� ���̿� ����ִ� ��带 ��ü ����
		}
		else {
			temp[dep_v[i]]->chi_v.push_back(curNode);
		}
	}

	//dep_v[i]�� dep_v[i + 1]�� �����־��� ������ ������ ���� ���������� ó��
	//�ǳ��� ��� ���� �ݵ�� ���̰� 1�̹Ƿ� ���̰� 1�� ��带 ��� ���� ���� root�� �ڽ����� �����������ν� ��� ������ ����
	temp[dep_v[N - 1]]->chi_v.push_back(node_v[N - 1]);
	for (Node* child : temp[dep_v[N - 1]]->chi_v) {
		root->chi_v.push_back(child);
		child->par = root;
	}
}

void Tree::preorder(Node* node) {
	if (!node) return;

	cout << node->data << " ";
	for (int i = 0; i < node->chi_v.size(); i++) {
		preorder(node->chi_v[i]);
	}
}

int main() {
	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		Tree tree(1);
		cin >> N;
		tree.insertNode(N);
		tree.preorder(tree.root);
		cout << endl;
	}
	return 0;
}