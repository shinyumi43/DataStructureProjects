#include <iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		this->next = nullptr;
	}
};

class LinkedList {
public:
	Node* front;
	Node* rear;

	LinkedList() {
		this->front = nullptr;
		this->rear = nullptr;
	}

	void addEnd(int data) {
		Node* newNode = new Node(data);
		if (front == nullptr) {
			front = rear = newNode;
		}
		else {
			rear->next = newNode;
			rear = newNode;
		}
	}

	void removeFront() {
		if (front != nullptr) {
			Node* tmp = front;
			front = front->next;
			cout << tmp->data << endl;
			delete tmp;
		}
	}
};

class LinkedQueue {
public:
	LinkedList* Q;
	int n;

	LinkedQueue() {
		this->Q = new LinkedList();
		this->n = 0;
	}

	int size() {
		return n;
	}

	bool isEmpty() {
		return n == 0;
	}

	void front() {
		if (isEmpty()) {
			cout << "Empty" << endl;
		}
		else {
			cout << Q->front->data << endl;
		}
	}

	void rear() {
		if (isEmpty()) {
			cout << "Empty" << endl;
		}
		else {
			cout << Q->rear->data << endl;
		}
	}

	void enqueue(int e) {
		Q->addEnd(e);
		n++;
	}

	void dequeue() {
		if (isEmpty()) cout << "Empty" << endl;
		else {
			Q->removeFront();
			n--;
		}
	}
};

int main() {
	LinkedQueue LQ;
	int T, value;
	cin >> T;
	string str;
	for (int i = 0; i < T; i++) {
		cin >> str;
		if (str == "enqueue") { cin >> value; LQ.enqueue(value); }
		else if (str == "dequeue") { LQ.dequeue(); }
		else if (str == "isEmpty") {
			if (LQ.isEmpty() == 1) { cout << "True" << endl; }
			else if (LQ.isEmpty() == 0) { cout << "False" << endl; }
		}
		else if (str == "size") { cout << LQ.size() << endl; }
		else if (str == "front") { LQ.front(); }
		else if (str == "rear") { LQ.rear(); }
	}
	return 0;
}