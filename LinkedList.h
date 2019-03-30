#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__
#include<iostream>
using namespace std;

class Node {
public:
	Node();
	~Node();
	int data;
	Node* prev;
	Node* next;
};


class LinkedList {
public:
	LinkedList();
	~LinkedList();
	void Insert(int data);
	Node* Search(int data);
	void Delete(int data);
	void DeleteAll();
private:
	Node head;
	Node tail;
};

#endif //__LINKEDLIST_H__
