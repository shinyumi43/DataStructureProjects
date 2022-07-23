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

	int front() {
		if (isEmpty()) { cout << "Empty" << endl; return 0; }
		else {
			return Q->front->data;
		}
	}

	void rear() {
		if (isEmpty()) cout << "Empty" << endl;
		else {
			cout << Q->rear->data << endl;
		}
	}

	void enqueue(int e) {
		Q->addEnd(e);
		n++;
	}

	void dequeue() {
		if (isEmpty()) { cout << "Empty" << endl; }
		else {
			Q->removeFront();
			n--;
		}
	}

	void cards(int n) {
		int power;
		for (int i = 0; i < n; i++) {
			cin >> power;
			enqueue(power);
		}
	}

	void transform(int energy) {
		Node* curNode = Q->front;
		if (curNode->next != nullptr) {
			curNode->next->data += energy;
		}
		return;
	}
};

void battle() {
	int N;
	cin >> N;
	LinkedQueue P1;
	LinkedQueue P2;
	P1.cards(N);
	P2.cards(N);
	int E1, E2, getP1 = 0, getP2 = 0;
	for (int i = 0; i < N; i++) {
		E1 = P1.front();
		E2 = P2.front();
		if (E1 > E2) {
			getP1++;
			P1.transform(E1 - E2);
		}
		else if (E1 < E2) {
			getP2++;
			P2.transform(E2 - E1);
		}
		P1.dequeue();
		P2.dequeue();
	}

	if (getP1 > getP2) cout << 1 << endl;
	else if (getP1 < getP2) cout << 2 << endl;
	else cout << 0 << endl;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		battle();
	}
	return 0;
}