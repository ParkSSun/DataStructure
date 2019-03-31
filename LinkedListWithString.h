#ifndef __LINKEDLISTWITHSTRING_H__
#define __LINKEDLISTWITHSTRING_H__
#include <iostream>
using namespace std;

class StringNode {
public:
	enum StringNodeDefine {
		MAXLENGTH = 10,
	};
	StringNode();
	StringNode(char* word, unsigned int cnt);
	~StringNode() {}
	char* GetStringP() { return word; }
	unsigned int GetMaxlength() { return (unsigned int)MAXLENGTH; }
	unsigned int GetCnt() { return cnt; }
	void SetCnt(unsigned int _cnt) { cnt = _cnt; }
	unsigned int IncreaseCnt(unsigned int val) { return cnt += val; }
	unsigned int DecreaseCnt(unsigned int val) { return cnt -= val; }
	StringNode* GetPrevP() { return prev; }
	StringNode* GetNextP() { return next; }
	void SetPrevP(StringNode* val) { prev = val; }
	void SetNextP(StringNode* val) { next = val; }
	void SetValue(char* _word, unsigned int _cnt);
private:
	char word[MAXLENGTH];
	unsigned int cnt;
	StringNode* prev;
	StringNode* next;
};

class LinkedListWithString {
public:
	LinkedListWithString();
	~LinkedListWithString();
	void Insert(char* str, unsigned int _cnt);
	StringNode* Search(char* str);
	void Delete(char* str);
	StringNode* GetHead() { return head; }
	StringNode* GetTail() { return tail; }
	void PrintAll();
private:
	StringNode* head;
	StringNode* tail;
};

#endif // __LINKEDLISTWITHSTRING_H__
