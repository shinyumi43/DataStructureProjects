#include <iostream>
#include <vector>
using namespace std;

class isLess {
public:
	bool operator()(const int a, const int b){
		if (a < b) return true;
		else return false;
	}
};

class PQ {
private:
	vector<int> v;
public:
	int size() { return v.size(); }
	bool empty() { return v.size() == 0; }
	void insert(int e) { v.push_back(e); }

	void removeMin() {
		vector<int>::iterator p = v.begin();
		isLess C;
		int m_value = *v.begin();
		for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
			if (!C(m_value, *iter)) {
				m_value = *iter;
				p = iter;
			}
		}
		v.erase(p);
	}

	int min() {
		vector<int>::iterator p = v.begin();
		isLess C;
		int m_value = *v.begin();
		for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
			if (!C(m_value, *iter)) {
				m_value = *iter;
				p = iter;
			}
		}
		return *p;
	}

	void print() {
		for (vector<int>::iterator iter = --v.end(); iter != v.begin(); --iter) {
			cout << *iter << ' ';
		}
		cout << *v.begin() << endl;
	}
};

int main() {
	int T, N, n;
	cin >> T;
	for (int i = 0; i < T; i++) {
		PQ P;
		PQ S;
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> n;
			P.insert(n);
		}
		for (int j = 0; j < N; j++) {
			S.insert(P.min());
			P.removeMin();
		}
		S.print();
	}
	return 0;
}

