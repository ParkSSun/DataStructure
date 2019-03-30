#include "hashing.h"
enum dataDefine {
	HASHTABLESIZE = 1000,
};
LinkedList hashTable[HASHTABLESIZE];
/*
int hashFunctionStringType(char* keyValue) {
	long long int hashIdx = 0;
	int g = 3;
	while (*keyValue)
	{
		hashIdx = g * hashIdx + *keyValue;
		keyValue++;
	}
	return hashIdx;
}
*/
Hash::Hash() {}
Hash::~Hash() {}

void Hash::DeleteAllTable() {
	for (int i = 0; i < HASHTABLESIZE; i++) {
		hashTable[i].DeleteAll();
	}
}

int Hash::hashfunction(int data) {
	return data % HASHTABLESIZE;
}


void Hash::Delete(int data) {
	LinkedList* p;
	if ((p = Search(data)) != nullptr) {
		cout << "Data Deleted : " << data << endl;
		p->Delete(data);
		p->Search(data);
	}else {
		cout << "������ data�� ����" << endl;
	}
}

LinkedList* Hash::Search(int data) {
	Node* p;
	if ((p = hashTable[hashfunction(data)].Search(data)) == nullptr) {
		cout << "ã�� data���� :" << data << endl;
		return nullptr;
	}
	else {
		cout << "ã�� data���� : " << data << endl;
		return &hashTable[hashfunction(data)];
	}
}

void Hash::Insert(int data) {
	LinkedList* p;
	if ((p = Search(data)) != nullptr) {
		cout << "data�̹� ������" << endl;
	}
	else {
		hashTable[hashfunction(data)].Insert(data);
		cout << "data �־��� :" << hashTable[hashfunction(data)].Search(data)->data << endl;
	}

}

