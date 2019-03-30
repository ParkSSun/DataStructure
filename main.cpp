#include "LinkedList.h"
#include "hashing.h"
#include"quickSort.h"
int main() {
	/*
	LinkedList link;

	link.Insert(123);
	link.Insert(321);
	link.Insert(1456);
	link.Insert(1232141);

	Node* p1 = link.Search(23145);
	Node* p2 = link.Search(1232141);
	cout << "data: " << p2->data << endl;
	link.Delete(1232141);
	Node* p3 = link.Search(1232141);
	link.Delete(321);
	Node *p4 = link.Search(321);
	Hash table;
	table.Insert(123);
	table.Insert(1123);
	table.Insert(2123);
	table.Insert(5412312);
	table.Insert(54141235);
	
	table.Delete(423525);
	table.Delete(54141235);
	table.Delete(1123);
	table.Delete(1123);
	table.Delete(2123);
	table.Delete(2123);

	table.DeleteAllTable();

	table.Delete(5412312);
	*/
	quickSort SSrt;
	int data[10] = { 123,34,12,54,1,3,66,122,156564,124 };
	SSrt.sort(data, 10);
	for (int i = 0; i < sizeof(data) / sizeof(int); i++)
	{
		cout << "idx :" << i << " data" << data[i] << endl;
	}
}