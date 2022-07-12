#include <iostream>
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

	void Insert() {
		for (int i = 0; i < arrSize; i++) {
			cin >> arr[i];
		}
	}

	void Print() {
		for (int i = 0; i < arrSize; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	void Shift() {
		int sf = arr[0];
		for (int i = 1; i < arrSize; i++) {
			arr[i - 1] = arr[i];
		}
		arr[arrSize - 1] = sf;
	}
};

int main() {
	int T, N, D;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> D;
		Array ar(N);
		ar.Insert();
		for (int j = 0; j < D; j++) {
			ar.Shift();
		}
		ar.Print();
	}
	return 0;
}