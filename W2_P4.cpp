#include <iostream>
#include <string>
using namespace std;

class Node {
	int elem;
	Node* next;
	Node* prev;

	Node();

	friend class DList;
};

Node::Node() {
	elem = 0;
	prev = nullptr;
	next = nullptr;
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
	void Sum();
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
		preNode->next = newNode;
		newNode->prev = preNode;
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

void DList::Sum() {
	int sumNum = 0;
	Node* curNode = header->next;
	if (Empty()) { cout << 0 << endl; }
	else {
		while (curNode->next != trailer) {
			sumNum += curNode->elem;
			curNode = curNode->next;
		}
		sumNum += curNode->elem;
		cout << sumNum << endl;
	}
}

int main() {
	int M, i, X;
	cin >> M;
	string str;
	DList* dlst = new DList();
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
		else if (str == "Sum") {
			dlst->Sum();
		}
	}
	return 0;
}