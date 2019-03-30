#ifndef __LINKEDLISTWITHSTRING_H__
#define __LINKEDLISTWITHSTRING_H__
#include <iostream>
using namespace std;

class StringNode {
public:
	enum StringNodeDefine {
		MAXLENGTH = 10,
	};
	StringNode() {}
	~StringNode() {}
	char* GetStringP() { return word; }
	unsigned int GetMaxlength() { return (unsigned int)MAXLENGTH; }
	unsigned int GetCnt() { return cnt; }
	unsigned int IncreaseCnt(unsigned int val) { return cnt += val; }
	unsigned int DecreaseCnt(unsigned int val) { return cnt -= val; }
	StringNode* GetPrevP() { return prev; }
	StringNode* GetNextP() { return next; }
	void SetPrevP(StringNode* val) { prev = val; }
	void SetNextP(StringNode* val) { next = val; }
	void SetValue(char* _word, unsigned int _cnt);
private:
	void StringCpy(char* dst, char* srt, unsigned int len);
	unsigned int GetStringLen(char* len);
	char word[MAXLENGTH];
	unsigned int cnt;
	StringNode* prev;
	StringNode* next;
};

class LinkedListWIthString {
public:
	LinkedListWIthString();
	~LinkedListWIthString();

private:
	StringNode* head;
	StringNode* tail;

};

LinkedListWIthString::LinkedListWIthString() {
	head = new StringNode();
	tail = new StringNode();
	head->SetNextP(tail);
	head->SetPrevP(tail);
	tail->SetNextP(head);
	tail->SetPrevP(head);

}
LinkedListWIthString::~LinkedListWIthString() {}



#endif // __LINKEDLISTWITHSTRING_H__
