#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int e) {
		this->data = e;
		this->next = nullptr;
	}
};

class linkedStack {
public:
	Node* head;
	Node* tail;
	int n;

	linkedStack() {
		this->head = nullptr;
		this->tail = nullptr;
		this->n = 0;
	}

	int size() {
		return n;
	}

	bool empty() {
		return n == 0;
	}

	int top() {
		if (empty()) return -1;
		else return head->data;
	}

	void push(int e) {
		Node* newNode = new Node(e);
		if (empty()) {
			head = tail = newNode;
			n++;
		}
		else {
			newNode->next = head;
			head = newNode;
			n++;
		}
	}

	int pop() {
		if (empty()) { return -1; }
		else {
			Node* temp = head;
			head = head->next;
			n--;
			return temp->data;
		}
	}
};

int main() {
	int N, X;
	string str;
	linkedStack lstk;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "empty") cout << lstk.empty() << endl;
		else if (str == "top") cout << lstk.top() << endl;
		else if (str == "push") { cin >> X; lstk.push(X); }
		else if (str == "pop") cout << lstk.pop() << endl;
	}
	return 0;
}