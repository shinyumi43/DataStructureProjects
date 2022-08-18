#include <iostream>
#include <vector>
#include <string>
using namespace std;
enum direction { MIN = 1, MAX = -1 };

class Heap {
private:
	vector<int> v;
	int heap_size;
	int direction;
	int root_index;
public:
	Heap(int direction) {
		v.push_back(-1);
		this->heap_size = 0;
		this->root_index = 1;
		this->direction = direction;
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

	bool isEmpty() { return heap_size == 0; }

	int size() { return heap_size; }

	void insert(int e) {
		v.push_back(e);
		heap_size++;
		upHeap(heap_size);
	}

	int pop() {
		if (isEmpty()) return -1;
		else {
			int top = v[root_index];
			v[root_index] = v[heap_size]; heap_size--;
			v.pop_back();
			downHeap(root_index);
			return top;
		}
	}

	void eval() {
		int res = 0;
		for (int i = 0; i < 2; i++) {
			res += pop();
		}
		insert(res / 2);
	}

	bool isCheck(int P) {
		for (int i = 1; i <= heap_size; i++) {
			if (v[i] < P) return false;
		}
		return true;
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
	int T, K, N, P;
	bool flag;
	cin >> T;
	for (int i = 0; i < T; i++) {
		Heap S(MIN);
		cin >> N >> P;
		for (int j = 0; j < N; j++) {
			cin >> K;
			S.insert(K);
		}
		flag = true;
		while (!S.isCheck(P)) {
			if (S.size() == 1) { cout << "False" << endl; flag = false; break; }
			S.eval();
		}
		if (flag) {
			cout << "True" << endl;
			S.print();
		}
	}
	return 0;
}