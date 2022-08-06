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
	//값을 입력받고 해당 값을 지닌 노드를 생성
	int data;
	for (int i = 0; i < N; i++) {
		cin >> data;
		if (data != 1) {
			Node* node = new Node(data);
			node_v.push_back(node);
		}
	}

	//깊이를 배열로 입력받으면서(다음 노드의 깊이와의 비교를 위해) 최대 깊이를 파악
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

	//특정 깊이에 존재하는 노드를 받을 곳을 생성(일단 특정 깊이 노드의 자식 노드로 받을 예정)
	vector<Node*> temp(max + 1);

	for (int index = 0; index < temp.size(); index++) {
		temp[index] = new Node(index);
	}

	Node* parNode;
	Node* curNode;
	//node_v[0], dep_v[0]에는 root의 정보가 담겨있으므로 1부터 순회
	//dep_v[i]를 dep_v[i + 1]과 비교하므로 N - 2까지만 수행
	for (int i = 1; i < N - 1; i++) {
		curNode = node_v[i];
		if (dep_v[i] > dep_v[i + 1]) { //현재 노드의 깊이가 다음 노드의 깊이보다 크다면, 다음 노드가 부모 노드가 되므로 자식으로 삽입
			temp[dep_v[i]]->chi_v.push_back(curNode); //예를 들어, 우선적으로 깊이가 5인 노드라면 temp[5]의 자식 노드로 삽입
			if (dep_v[i] != 1) parNode = node_v[i + 1]; //부모 노드 지정, 깊이가 1인 것 이외에만 다음 노드로 한정
			else parNode = root;
			for (Node* child : temp[dep_v[i]]->chi_v) { //깊이가 같은 노드를 전부 실제 부모 노드에 삽입
				parNode->chi_v.push_back(child); //부모의 자식으로, 자식의 부모로 서로 연결
				child->par = parNode;
			}
			temp[dep_v[i]]->chi_v.clear(); //앞서 깊이가 같은 노드를 전부 부모와 연결했으므로 해당 깊이에 담겨있는 노드를 전체 삭제
		}
		else {
			temp[dep_v[i]]->chi_v.push_back(curNode);
		}
	}

	//dep_v[i]와 dep_v[i + 1]을 비교해주었기 때문에 마지막 노드는 예외적으로 처리
	//맨끝에 담긴 것은 반드시 깊이가 1이므로 깊이가 1인 노드를 모두 담은 것을 root의 자식으로 연결해줌으로써 노드 삽입은 종료
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