#include <iostream>
#include <string>
using namespace std;

class Array {
private:
	int* arr;
	int arrSize;
public:
	Array(int size) {
		this->arrSize = size;
		this->arr = new int[arrSize];
		for (int i = 0; i < arrSize; i++) {
			arr[i] = 0;
		}
	}

	int at(int idx) {
		return arr[idx];
	}

	void add(int idx, int val) {
		for (int i = arrSize - 2; i >= idx; i--) {
			arr[i + 1] = arr[i];
		}
		arr[idx] = val;
	}

	void remove(int idx) {
		for (int i = idx + 1; i < arrSize; i++) {
			arr[i - 1] = arr[i];
		}
		arr[arrSize - 1] = 0;
	}

	int set(int idx, int val) {
		arr[idx] = val;
		return arr[idx];
	}

	void print() {
		for (int i = 0; i < arrSize; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	void find_min() {
		int min = 10000;
		for (int i = 0; i < arrSize; i++) {
			if (arr[i] < min) min = arr[i];
		}
		cout << min << endl;
	}
};

int main() {
	int N, T, i, value;
	string str;
	cin >> N >> T;
	Array ar(N);
	for (int j = 0; j < T; j++) {
		cin >> str;
		if (str == "at") {
			cin >> i;
			cout << ar.at(i) << endl;
		}
		else if (str == "add") {
			cin >> i >> value;
			ar.add(i, value);
		}
		else if (str == "remove") {
			cin >> i;
			ar.remove(i);
		}
		else if (str == "set") {
			cin >> i >> value;
			cout << ar.set(i, value) << endl;
		}
		else if (str == "print") {
			ar.print();
		}
		else if (str == "find_min") {
			ar.find_min();
		}
	}
	return 0;
}