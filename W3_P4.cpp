#include <iostream>
#include <string>
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
		if (empty()) return -1;
		else return arr[t];
	}

	void push(int e) {
		if (size() == capacity) cout << "FULL" << endl;
		else arr[++t] = e;
	}

	int pop() {
		if (empty()) return -1;
		else return arr[t--];
	}

	void init() {
		t = -1;
	}

	int eval(string str) {
		int x, y, val;
		char ch;
		init();
		for (int i = 0; i < str.length(); i++) {
			ch = str[i];
			if (ch != '+' && ch != '-' && ch != '*') {
				val = ch - '0';
				push(val);
			}
			else {
				y = pop();
				x = pop();
				switch (ch) {
				case '+':
					push(x + y);
					break;
				case '-':
					push(x - y);
					break;
				case '*':
					push(x * y);
					break;
				}
			}
		}
		return pop();
	}
};

int main() {
	int t, res = 0;
	cin >> t;
	string str;
	arrStack valStk(100);
	for (int i = 0; i < t; i++) {
		cin >> str;
		res = valStk.eval(str);
		cout << res << endl;
	}
	return 0;
}