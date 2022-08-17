#include <iostream>
#include <vector>
#include <string>
using namespace std;
enum direction { MIN = 1, MAX = -1 };

class Heap {
private:
	vector<int> v;
	int direction;
	int heap_size;
	int root_index;
public:
	Heap(int direction) {
		v.push_back(-1);
		this->root_index = 1;
		this->direction = direction;
		this->heap_size = 0;
	}

	void swap(int idx1, int idx2) {
		v[0] = v[idx1];
		v[idx1] = v[idx2];
		v[idx2] = v[0];
	}

	void upHeap(int idx) {
		if (idx == root_index) return;
		else {
			int parent = idx / 2;
			if (v[parent] * direction > v[idx] * direction) {
				swap(parent, idx);
				upHeap(parent);
			}
		}
	}

	void downHeap(int idx) {
		int left = idx * 2;
		int right = idx * 2 + 1;
		if (right <= heap_size) {
			if (v[left] * direction <= v[right] * direction) {
				if (v[left] * direction < v[idx] * direction) {
					swap(left, idx);
					downHeap(left);
				}
				else return;
			}
			else {
				if (v[right] * direction < v[idx] * direction) {
					swap(right, idx);
					downHeap(right);
				}
				else return;
			}
		}
		else if (left <= heap_size) {
			if (v[left] * direction < v[idx] * direction) {
				swap(left, idx);
				downHeap(left);
			}
			else return;
		}
		else return;
	}

	void insert(int e) {
		v.push_back(e);
		heap_size++;
		upHeap(heap_size);
	}

	int size() { return heap_size; }

	bool isEmpty() { return heap_size == 0; }

	int pop() {
		if (isEmpty()) { return -1; }
		else {
			int top = v[root_index];
			v[root_index] = v[heap_size]; heap_size--;
			v.pop_back();
			downHeap(root_index);
			return top;
		}
	}

	int top() {
		if (isEmpty()) return -1;
		else { return v[root_index]; }
	}

	void print() {
		if (isEmpty()) cout << -1 << endl;
		else {
			for (int i = 1; i <= heap_size; i++) {
				cout << v[i] << ' ';
			}
			cout << endl;
		}
	}
};

int main() {
	int T, i;
	string str;
	Heap heapPQ(MIN);
	cin >> T;
	for (int j = 0; j < T; j++) {
		cin >> str;
		if (str == "insert") { cin >> i;  heapPQ.insert(i); }
		else if (str == "print") { heapPQ.print(); }
		else if (str == "isEmpty") { cout << heapPQ.isEmpty() << endl; }
		else if (str == "pop") { cout << heapPQ.pop() << endl; }
		else if (str == "top") { cout << heapPQ.top() << endl; }
		else if (str == "size") { cout << heapPQ.size() << endl; }
	}
	return 0;
}