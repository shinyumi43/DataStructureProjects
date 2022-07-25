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

	void addEnd(int elem) {
		Node* newNode = new Node(elem);
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

	int front() {
		return Q->front->data;
	}

	void enqueue(int elem) {
		Q->addEnd(elem);
		n++;
	}

	void dequeue() {
		Q->removeFront();
		n--;
	}

	void cards(int N) {
		int power;
		for (int i = 0; i < N; i++) {
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
	int N, E1, E2, getP1 = 0, getP2 = 0;
	LinkedQueue P1;
	LinkedQueue P2;
	cin >> N;
	P1.cards(N);
	P2.cards(N);
	for (int i = 0; i < N; i++) {
		E1 = P1.front();
		E2 = P2.front();
		if (E1 > E2) { getP1++; P2.transform(E1 - E2); }
		else if (E1 < E2) { getP2++;  P1.transform(E2 - E1); }
		P1.dequeue();
		P2.dequeue();
	}

	if (getP1 > getP2) cout << getP1 << endl;
	else if (getP1 < getP2) cout << getP2 << endl;
	else cout << getP1 << endl;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		battle();
	}
	return 0;
}