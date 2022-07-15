#include <iostream>
#include <string>
using namespace std;

class Node {
	int elem;
	Node* prev;
	Node* next;

	Node();

	friend class DList;
};

Node::Node() {
	prev = next = nullptr;
	elem = 0;
}

class DList {
public:
	DList();
	bool Empty();
	int List_size();
	void Print();
	void Append(int);
	int Delete(int);
	void Print_reverse();
	void Max();
private:
	Node* header;
	Node* trailer;
};

DList::DList() {
	header = new Node();
	trailer = new Node();

	header->next = trailer;
	trailer->prev = header;
}

bool DList::Empty() {
	return (header->next == trailer && trailer->prev == header);
}

int DList::List_size() {
	int listSize = 0;
	if (Empty()) { return listSize; }
	else {
		Node* curNode = header->next;
		while (curNode->next != trailer) {
			listSize++;
			curNode = curNode->next;
		}
		listSize++;
		return listSize;
	}
}

void DList::Print() {
	if (Empty()) { cout << "empty" << endl; }
	else {
		Node* curNode = header->next;
		while (curNode->next != trailer) {
			cout << curNode->elem << ' ';
			curNode = curNode->next;
		}
		cout << curNode->elem << endl;
	}
}

void DList::Append(int elem) {
	Node* newNode = new Node();
	newNode->elem = elem;
	if (Empty()) {
		header->next = newNode;
		newNode->prev = header;
		trailer->prev = newNode;
		newNode->next = trailer;
	}
	else {
		Node* preNode = trailer->prev;
		newNode->prev = preNode;
		preNode->next = newNode;
		newNode->next = trailer;
		trailer->prev = newNode;
	}

	Print();
}

int DList::Delete(int idx) {
	int removeNum = 0, cnt = 0;
	Node* curNode;
	if (Empty() || List_size() <= idx) {
		return -1;
	}
	else if (idx == 0) {
		if (List_size() == 1) {
			removeNum = header->next->elem;
			header->next = trailer;
			trailer->prev = header;
		}
	}
	else {
		curNode = header->next;
		while (cnt != idx) {
			curNode = curNode->next;
			cnt++;
		}
		removeNum = curNode->elem;
		curNode->prev->next = curNode->next;
		curNode->next->prev = curNode->prev;
	}

	return removeNum;
}

void DList::Print_reverse() {
	if (Empty()) { cout << "empty" << endl; }
	else {
		Node* curNode = trailer->prev;
		while (curNode->prev != header) {
			cout << curNode->elem << ' ';
			curNode = curNode->prev;
		}
		cout << curNode->elem << endl;
	}
}

void DList::Max() {
	int max = -1;
	if (Empty()) { cout << "empty" << endl; }
	else {
		Node* curNode = header->next;
		while (curNode->next != trailer) {
			if (curNode->elem > max) { max = curNode->elem; }
			curNode = curNode->next;
		}
		if (curNode->elem > max) { max = curNode->elem; }
		cout << max << endl;
	}
}

int main() {
	DList* dlst = new DList();
	string str;
	int M, i, X;
	cin >> M;
	for (int j = 0; j < M; j++) {
		cin >> str;
		if (str == "Print") {
			dlst->Print();
		}
		else if (str == "Append") {
			cin >> X;
			dlst->Append(X);
		}
		else if (str == "Delete") {
			cin >> i;
			cout << dlst->Delete(i) << endl;
		}
		else if (str == "Print_reverse") {
			dlst->Print_reverse();
		}
		else if (str == "Max") {
			dlst->Max();
		}
	}
	return 0;
}