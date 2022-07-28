#include <iostream>
using namespace std;

class SequenceList {
private:
	struct Node {
		int data;
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
	Iterator begin() const;
	Iterator end() const;
	bool empty() const;
	void insert(const Iterator& p, const int& elem);
	void erase(const Iterator& p);
	void reversePrint();
	void find(const int& elem);
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

void SequenceList::insert(const SequenceList::Iterator& p, const int& elem) {
	Node* w = p.v;
	Node* u = w->prev;
	Node* v = new Node;
	v->data = elem;
	v->next = w; w->prev = v;
	v->prev = u; u->next = v;
	this->n++;
}

void SequenceList::erase(const SequenceList::Iterator& p) {
	if (empty()) cout << "Empty" << endl;
	else {
		Node* v = p.v;
		Node* u = v->prev;
		Node* w = v->next;
		u->next = w; w->prev = u;
		delete v;
		this->n--;
	}
}

void SequenceList::reversePrint() {
	if (empty()) cout << "Empty" << endl;
	else {
		Node* temp = trailer->prev;
		while (temp != header) {
			cout << temp->data << ' ';
			temp = temp->prev;
		}
		cout << endl;
	}
}

void SequenceList::find(const int& elem) {
	if (empty()) cout << "Empty" << endl;
	else {
		Iterator q = begin();
		int index = 0;
		while (q.v != trailer) {
			if (q.v->data == elem) {
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

	SequenceList dl;
	SequenceList::Iterator iter = dl.begin();

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> str;
		if (str == "begin") { iter = dl.begin(); }
		else if (str == "end") { iter = dl.end(); }
		else if (str == "insert") { cin >> e; dl.insert(iter, e); }
		else if (str == "erase") { dl.erase(iter); }
		else if (str == "reversePrint") { dl.reversePrint(); }
		else if (str == "find") { cin >> e; dl.find(e); }
		else if (str == "++") { iter.operator++(); }
		else if (str == "--") { iter.operator--(); }
	}
	return 0;
}