#include <iostream>
#include <vector>
using namespace std;

class isLess {
public:
	bool operator()(const int a, const int b) const{
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
	void insert(int e) {
		vector<int>::iterator p = v.begin();
		isLess C;

		if (v.empty()) { v.insert(p, e); }
		else {
			while (p != v.end() && C(e, *p)) {
				++p;
			}
			v.insert(p, e);
		}
	}
	int min() { return v.back(); }
	void removeMin() { v.pop_back(); }
	void print() {
		for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
			cout << *iter << ' ';
		}
		cout << endl;
	}
};

int main() {
	int T, N, n;
	cin >> T;
	for (int i = 0; i < T; i++) {
		PQ S;
		PQ P;
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