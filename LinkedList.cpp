#include "LinkedList.h"
Node::Node()
	:data(0),
	prev(nullptr),
	next(nullptr) {}

Node::~Node() {
	//cout << "Node Destructed" << endl;
}

LinkedList::LinkedList()
	:head(),
	tail() {
	head.next = &tail;
	tail.prev = &head;
}
LinkedList::~LinkedList() {
	Node *p = head.next;
	while (p != &tail) {
		Node* pn = p;
		cout << "Delete:" << pn->data << endl;
		p = p->next;
		delete pn;
	}
}

void LinkedList::Insert(int data) {
	Node* p = new Node();
	p->data = data;
	p->prev = tail.prev;
	p->next = &tail;
	tail.prev->next = p;
	tail.prev = p;
	cout << "insert New data:" << p->data << "datat :  " << data << endl;
	return;
}

Node* LinkedList::Search(int data) {
	Node *p = head.next;
	while (p != &tail) {
		if (p->data == data) {
			cout << "find data :" << p->data << "data :" << data << endl;
			return p;
		}
		p = p->next;
	}
	cout << "can not find data" << endl;
	return nullptr;
}

void LinkedList::Delete(int data) {
	Node* p;
	if ((p = Search(data)) != nullptr) {
		p->prev->next = p->next;
		p->next->prev = p->prev;
		cout << "Delete: " << p->data << endl;
		delete p;
	}
	return;
}

void LinkedList::DeleteAll() {
	Node *p = head.next;
	while (p != &tail) {
		Node* pn = p;
		cout << "Delete:" << pn->data << endl;
		p = p->next;
		delete pn;
	}

}




