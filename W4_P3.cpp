#include <iostream>
#include <string>
using namespace std;

class arrQ {
private:
	int* Q;
	int rear;
	int front;
	int capacity;
public:
	arrQ(int capacity) {
		this->capacity = capacity + 1;
		Q = new int[this->capacity];
		front = rear = 0;

		for (int i = 0; i < this->capacity; i++) {
			Q[i] = 0;
		}
	}

	bool isFull() {
		return front == (rear + 1) % capacity;
	}

	bool isEmpty() {
		return front == rear;
	}

	int size() {
		return (rear - front + capacity) % capacity;
	}

	void _front() {
		if (isEmpty()) cout << "Empty" << endl;
		else cout << Q[(front + 1) % capacity] << endl;
	}

	void _rear() {
		if (isEmpty()) cout << "Empty" << endl;
		else cout << Q[rear] << endl;
	}

	void enqueue(int value) {
		if (isFull()) cout << "Full" << endl;
		else {
			rear = (rear + 1) % capacity;
			Q[rear] = value;
		}
	}

	void dequeue() {
		if (isEmpty()) cout << "Empty" << endl;
		else {
			front = (front + 1) % capacity;
			int elem = Q[front];
			Q[front] = 0;
			cout << elem << endl;
		}
	}
};

int main() {
	int N, T, value;
	cin >> N >> T;
	string str;
	arrQ Q(N);
	for (int i = 0; i < T; i++) {
		cin >> str;
		if (str == "enqueue") { cin >> value; Q.enqueue(value); }
		else if (str == "dequeue") { Q.dequeue(); }
		else if (str == "isEmpty") {
			if (Q.isEmpty() == 1) cout << "True" << endl;
			else if (Q.isEmpty() == 0) cout << "False" << endl;
		}
		else if (str == "size") { cout << Q.size() << endl; }
		else if (str == "front") { Q._front(); }
		else if (str == "rear") { Q._rear(); }
	}
	return 0;
}