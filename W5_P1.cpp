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
	void erase(const Iterator& p);
	void print();
	void find(const int& e);
};

SequenceList::SequenceList() {
	n = 0;
	header = new Node;
	trailer = new Node;
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

void SequenceList::erase(const Iterator& p) {
	if (empty()) cout << "Empty" << endl;
	else {
		Node* v = p.v;
		Node* w = v->next;
		Node* u = v->prev;
		u->next = w; w->prev = u;
		delete v;
		this->n--;
	}
}

void SequenceList::print() {
	Node* temp = header->next;
	if (empty()) { cout << "Empty" << endl; }
	else {
		while (temp != trailer) {
			cout << temp->e << ' ';
			temp = temp->next;
		}
		cout << endl;
	}
}

void SequenceList::find(const int& e) {
	Iterator q = begin();
	int index = 0;
	if (empty()) cout << "Empty" << endl;
	else {
		while (q.v != trailer) {
			if (q.v->e == e) {
				cout << index << endl;
				return;
			}
			++q;
			++index;
		}
		cout << -1 << endl;
	}
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
	int M, e;
	string str;
	cin >> M;

	SequenceList dl;
	SequenceList::Iterator iter = dl.begin();

	for (int i = 0; i < M; i++) {
		cin >> str;
		if (str == "insert") {
			cin >> e;
			dl.insert(iter, e);
		}
		else if (str == "erase") {
			dl.erase(iter);
		}
		else if (str == "begin") {
			iter = dl.begin();
		}
		else if (str == "end") {
			iter = dl.end();
		}
		else if (str == "++") {
			iter.operator++();
		}
		else if (str == "--") {
			iter.operator--();
		}
		else if (str == "print") {
			dl.print();
		}
		else if (str == "find") {
			cin >> e;
			dl.find(e);
		}
	}
	return 0;
}
