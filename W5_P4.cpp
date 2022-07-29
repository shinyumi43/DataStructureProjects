#include <iostream>
using namespace std;

class SequenceList {
private:
	struct Node {
		int e;
		Node* next;
		Node* prev;
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
	void erase(const Iterator& p);
	int convolution(const Iterator& p);
};

SequenceList::SequenceList() {
	n = 0;
	header = new Node;
	trailer = new Node;
	header->e = trailer->e = 0;
	header->next = trailer;
	trailer->prev = header;
}

bool SequenceList::empty() const {
	return n == 0;
}

void SequenceList::insert(const Iterator& p, const int& e) {
	Node* w = p.v;
	Node* u = w->prev;
	Node* v = new Node;
	v->e = e;
	v->next = w; w->prev = v;
	v->prev = u; u->next = v;
	this->n++;
}

void SequenceList::erase(const Iterator& p) {
	Node* v = p.v;
	Node* u = v->prev;
	Node* w = v->next;
	u->next = w; w->prev = u;
	delete v;
	this->n--;
}

int SequenceList::convolution(const Iterator& p) {
	int value = 0;
	Iterator q = p;
	q.operator--();
	for (int i = 0; i < 3; i++) {
		if (q.v == p.v) value += 3 * q.v->e;
		else { value += 1 * q.v->e; }
		q.operator++();
	}
	return value;
}

SequenceList::Iterator SequenceList::begin() const {
	return Iterator(header->next);
}

SequenceList::Iterator SequenceList::end() const {
	return Iterator(trailer);
}

SequenceList::Iterator::Iterator(Node* u) {
	v = u;
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
	int T, N, e;
	cin >> T;

	for (int i = 0; i < T; i++) {
		SequenceList dl;
		SequenceList::Iterator iter = dl.begin();
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> e;
			dl.insert(iter, e);
		}
		iter = dl.begin();
		for (int j = 0; j < N; j++) {
			cout << dl.convolution(iter) << ' ';
			iter.operator++();
		}
		cout << endl;
	}
	return 0;
}