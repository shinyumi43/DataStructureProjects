#include <iostream>
using namespace std;

class arrStack {
public:
	int* arr;
	int capacity;
	int t;

	arrStack(int capacity) {
		this->capacity = capacity;
		this->arr = new int[capacity];
		this->t = -1;
	}

	int size() {
		return t + 1;
	}

	bool empty() {
		return t == -1;
	}

	int top() {
		if (empty()) { return -1; }
		else { return arr[t]; }
	}

	void push(int e) {
		if (size() == capacity) { cout << "FULL" << endl; }
		else { arr[++t] = e; }
	}

	int pop() {
		if (empty()) { return -1; }
		else { return arr[t--]; }
	}
};

int main() {
	int t, N, X;
	string str;
	cin >> t >> N;
	arrStack arr(t);
	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "empty") { cout << arr.empty() << endl; }
		else if (str == "top") { cout << arr.top() << endl; }
		else if (str == "push") { cin >> X; arr.push(X); }
		else if (str == "pop") { cout << arr.pop() << endl; }
	}
	return 0;
}