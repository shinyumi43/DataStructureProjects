#include <iostream>
#include <string>
using namespace std;

class Node {
	int elem;
	Node* next;

	friend class List;
};

class List {
public:
	List();
	bool Empty();
	int List_size();
	void Print();
	void Append(int);
	int Delete(int);
	void Insert(int, int);
	void Min();
private:
	Node* head;
	Node* tail;
};

List::List() {
	head = new Node;
	tail = new Node;
	head = tail = nullptr;
}

bool List::Empty() {
	return (head == nullptr && tail == nullptr);
}

int List::List_size() {
	int listSize = 0;
	if (Empty()) {
		return listSize;
	}
	else {
		Node* curNode = head;
		while (curNode->next != nullptr) {
			listSize++;
			curNode = curNode->next;
		}
		listSize++;
		return listSize;
	}
}

void List::Print() {
	if (Empty()) { cout << "empty" << endl; }
	else {
		Node* curNode = head;
		while (curNode->next != nullptr) {
			cout << curNode->elem << ' ';
			curNode = curNode->next;
		}
		cout << curNode->elem << endl;
	}
}

void List::Append(int elem) {
	Node* newNode = new Node;
	newNode->elem = elem;
	newNode->next = nullptr;

	if (Empty()) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = tail->next;
	}

	Print();
}

int List::Delete(int idx) {
	int removeNum = 0, cnt = 0;
	Node* curNode;
	Node* preNode;

	if (Empty() || List_size() <= idx) {
		return -1;
	}
	else if (idx == 0) {
		if (List_size() == 1) {
			removeNum = head->elem;
			tail = nullptr;
			head = nullptr;
		}
		else {
			curNode = head;
			removeNum = curNode->elem;
			head = curNode->next;
		}
	}
	else {
		preNode = curNode = head;
		while (cnt != idx) {
			preNode = curNode;
			curNode = curNode->next;
			cnt++;
		}
		removeNum = curNode->elem;
		preNode->next = curNode->next;

		if (curNode == tail) { tail = preNode; }
	}

	return removeNum;
}

void List::Insert(int idx, int elem) {
	Node* newNode = new Node;
	newNode->elem = elem;

	Node* curNode;
	Node* preNode;
	int curIdx = 0;

	if (idx == 0) {
		if (Empty()) {
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
		Print();
	}
	else if (idx < 0 || List_size() < idx) {
		cout << "Index Error" << endl;
	}
	else if (idx == List_size()) {
		Append(elem);
	}
	else {
		preNode = curNode = head;
		while (curIdx != idx) {
			preNode = curNode;
			curNode = curNode->next;
			curIdx++;
		}
		preNode->next = newNode;
		newNode->next = curNode;
		Print();
	}
}

void List::Min() {
	int min = 10000;
	Node* curNode = head;
	if (Empty()) { cout << "empty" << endl; }
	else {
		while (curNode->next != nullptr) {
			if (curNode->elem < min) { min = curNode->elem; }
			curNode = curNode->next;
		}
		if (curNode->elem < min) min = curNode->elem;
		cout << min << endl;
	}
}

int main() {
	int M, i, X;
	string str;
	List lst;
	cin >> M;
	for (int j = 0; j < M; j++) {
		cin >> str;
		if (str == "Print") {
			lst.Print();
		}
		else if (str == "Append") {
			cin >> X;
			lst.Append(X);
		}
		else if (str == "Delete") {
			cin >> i;
			cout << lst.Delete(i) << endl;
		}
		else if (str == "Insert") {
			cin >> i >> X;
			lst.Insert(i, X);
		}
		else if (str == "Min") {
			lst.Min();
		}
	}
	return 0;
}