#include <iostream>
#define NOCHECK 0
#define ISCHECK 1
using namespace std;

struct Entry {
	int value;
	int valid;

	Entry() {
		value = 0;
		valid = NOCHECK;
	}

	Entry(int value) {
		this->value = value;
		this->valid = NOCHECK;
	}

	void Check() {
		valid = ISCHECK;
	}
};

class HashTable {
	int count, index;
	Entry* hash_table;
	int capacity;

	int hash_func(int key) {
		return key % capacity;
	}

	int hash_func2(int key) {
		return capacity - (key % capacity);
	}

public:
	HashTable(int N) {
		this->capacity = N;
		this->count = 1;
		this->index = 0;
		this->hash_table = new Entry[capacity];
		for (int idx = 0; idx < capacity; idx++) {
			hash_table[idx] = Entry(idx + 1);
		}
	}

	//getIndex, setIndex, counterClock, Clock, value, check, print
	void setIndex(int index) { this->index = index; }
	
	int getIndex() { return index; }

	void Print() {
		int index = getIndex();
		hash_table[index].Check();
		cout << hash_table[index].value << ' ';
	}

	int Check() {
		int index = getIndex();
		if (hash_table[index].valid == ISCHECK) { return ISCHECK; }
		else if (hash_table[index].valid == NOCHECK) { return NOCHECK; }
	}

	int Value() {
		int index = getIndex();
		return hash_table[index].value;
	}

	void CounterClock(int key) {
		int index = getIndex();
		if (key == 1) {
			if (index + 1 > capacity) { index = (index + 1) - capacity; index = hash_func(index); setIndex(index); return; }
			else { index = index + 1; index = hash_func(index); setIndex(index); return; }
		}

		if (count != 1) { index = hash_func(index + hash_func(key));}
		else { index = hash_func(key);}
		setIndex(index);
		count++;
	}

	void Clock(int key) {
		int index = getIndex();
		if (key == 1) {
			if (index - 1 < 0) { index = (index - 1) + capacity; index = hash_func(index); setIndex(index); return; }
			else { index = index - 1; index = hash_func(index); setIndex(index); return; }
		}

		if (count != 1) { index = hash_func(index + hash_func2(key));}
		else { index = hash_func2(key); }
		setIndex(index);
		count++;
	}
};

int main() {
	int T, X, Y, N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> X >> Y >> N;
		HashTable A(X);
		HashTable B(Y);
		int* K = new int[N];
		for (int j = 0; j < N; j++) {
			cin >> K[j];
		}
		for (int j = 0; j < N; j++) {
			A.CounterClock(K[j]);
			B.Clock(K[j]);
			if (A.Check() == NOCHECK) {
				A.Print();
			}
			else if (A.Check() == ISCHECK) {
				A.CounterClock(B.Value());
				B.Clock(B.Value());
				if (A.Check() == ISCHECK) {
					while (A.Check() != NOCHECK) {
						A.Clock(1);
						B.CounterClock(1);
					}
					A.Print();
				}
				else {
					A.Print();
				}
			}
		}
		cout << endl;
	}
	return 0;
}