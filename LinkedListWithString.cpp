#include "LinkedListWithString.h"


StringNode::StringNode()
:cnt(0),
prev(nullptr),
next(nullptr){
	for (int idx = 0; idx < MAXLENGTH; idx++)word[idx] = 0;
}

StringNode::StringNode(char* _word, unsigned int cnt){
	SetValue(_word, cnt);
}

unsigned int StringNode::GetStringLen(char* word) {
	unsigned int len = 0;
	while (word[len] != '\0')len++;
	cout << "String Length : " << len << endl;
	return len;
}

void StringNode::StringCpy(char* dst, char* src, unsigned int len) {
	unsigned int idx = 0;
	while (len != idx)dst[idx] = src[idx++];
	return;
}

void StringNode::SetValue(char* _word, unsigned int _cnt) {
	StringCpy(word, _word, GetStringLen(_word));
	cnt = _cnt;
	return;
}


LinkedListWIthString::LinkedListWIthString() {
	head = new StringNode();
	tail = new StringNode();
	head->SetNextP(tail);
	head->SetPrevP(tail);
	tail->SetNextP(head);
	tail->SetPrevP(head);

}

LinkedListWIthString::~LinkedListWIthString() {
	StringNode* p = head->GetNextP();
	while (p != tail){
		StringNode* pp = p->GetNextP();
		delete p;
		p = pp;
	}
	delete head;
	delete tail;
}

