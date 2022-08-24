#include <iostream>
#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2
using namespace std;

struct Entry {
	int key;
	string value;
	int valid;

	Entry(){
		key = 0;
		value = "";
		valid = NOITEM;
	}

	Entry(int key, string value) {
		this->key = key;
		this->value = value;
		this->valid = ISITEM;
	}

	void erase() {
		valid = AVAILABLE;
	}
};

class HashTable {
	int capacity;
	Entry* hash_table;

	int hash_func(int key) {
		return key % capacity;
	}

public:
	HashTable(int N) {
		this->capacity = N;
		this->hash_table = new Entry[capacity];
	}

	void put(int key, string value) {
		int index = hash_func(key);
		int probing = 1;

		while (hash_table[index].valid == ISITEM && probing <= capacity) {
			index = hash_func(index + 1);
			probing++;
		}

		if (probing > capacity) { cout << probing << endl; return; }
		hash_table[index] = Entry(key, value);
		cout << probing << endl;
		return;
	}

	void erase(int key) {
		int index = hash_func(key);
		int probing = 1;

		while (hash_table[index].valid != NOITEM && probing <= capacity) {
			if (hash_table[index].valid == ISITEM && hash_table[index].key == key) {
				hash_table[index].erase();
				return;
			}
			index = hash_func(index + 1);
			probing++;
		}
		cout << "None" << endl;
		return;
	}

	string find(int key) {
		int index = hash_func(key);
		int probing = 1;

		while (hash_table[index].valid != NOITEM && probing <= capacity) {
			if (hash_table[index].valid == ISITEM && hash_table[index].key == key) {
				return hash_table[index].value;
			}
			index = hash_func(index + 1);
			probing++;
		}
		return "None";
	}
};

int main() {
	int T, K, N;
	string str, S;
	cin >> T >> N;
	HashTable HT(N);
	for (int i = 0; i < T; i++) {
		cin >> str;
		if (str == "put") { cin >> K >> S; HT.put(K, S); }
		else if (str == "erase") { cin >> K; HT.erase(K); }
		else if (str == "find") { cin >> K; cout << HT.find(K) << endl; }
	}
	return 0;
}

