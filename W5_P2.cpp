#include <iostream>
using namespace std;

class SequenceList {
private:
	struct Node {
		int e;
		Node* prev;
		Node* next;
	};

public:
	class Iterator {
	private:
		Node* v;
		Iterator(Node* u);
	public:
		Iterator& operator++();
		Iterator& operator--();
		friend class SequenceList;
	};

private:
	int n;
	Node* header;
	Node* trailer;
public:
	SequenceList();
	bool empty() const;
	Iterator begin() const;
	Iterator end() const;
	void insert(const Iterator& p, const int& e);
	void MaxPooling(const Iterator& p);
};

SequenceList::SequenceList() {
	n = 0;
	header = new Node;
	trailer = new Node;
	header->e = 0;
	trailer->e = 0;
	header->next = trailer;
	trailer->prev = header;
}

bool SequenceList::empty() const {
	return (n == 0);
}

void SequenceList::insert(const SequenceList::Iterator& p, const int& e) {
	Node* w = p.v;
	Node* u = w->prev;
	Node* v = new Node;
	v->e = e;
	v->next = w; w->prev = v;
	v->prev = u; u->next = v;
	this->n++;
}

void SequenceList::MaxPooling(const SequenceList::Iterator& p) {
	Iterator q = p;
	q.operator--();
	int max = q.v->e;
	for (int i = 0; i < 3; i++) {
		if (q.v->e > max) { max = q.v->e; }
		q.operator++();
	}
	cout << max << ' ';
}

SequenceList::Iterator::Iterator(Node* u) {
	v = u;
}

SequenceList::Iterator SequenceList::begin() const {
	return Iterator(header->next);
}

SequenceList::Iterator SequenceList::end() const {
	return Iterator(trailer);
}

SequenceList::Iterator& SequenceList::Iterator::operator++() {
	v = v->next;
	return *this;
}

SequenceList::Iterator& SequenceList::Iterator::operator--() {
	v = v->prev;
	return *this;
}

int main() {
	int T, N, P;
	cin >> T;

	for (int i = 0; i < T; i++) {
		SequenceList dl;
		SequenceList::Iterator iter = dl.begin();
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> P;
			dl.insert(iter, P);
		}
		iter = dl.begin();
		for (int j = 0; j < N; j++) {
			dl.MaxPooling(iter);
			iter.operator++();
		}
		cout << endl;
	}
	return 0;
}