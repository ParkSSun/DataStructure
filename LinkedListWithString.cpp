#include "LinkedListWithString.h"
#include "Util.h"
StringNode::StringNode()
:cnt(0),
prev(nullptr),
next(nullptr){
	for (int idx = 0; idx < MAXLENGTH; idx++)word[idx] = 0;
}

StringNode::StringNode(char* _word, unsigned int cnt){
	SetValue(_word, cnt);
}

void StringNode::SetValue(char* _word, unsigned int _cnt) {
	mStrCpy(word, _word, mStrLen(_word));
	cnt = _cnt;
	return;
}


LinkedListWithString::LinkedListWithString() {
	head = new StringNode();
	tail = new StringNode();
	head->SetNextP(tail);
	head->SetPrevP(tail);
	tail->SetNextP(head);
	tail->SetPrevP(head);
}

LinkedListWithString::~LinkedListWithString() {
	StringNode* p = head->GetNextP();
	cout << "Destructor of LinkedListWithString" << endl;
	while (p != tail){
		StringNode* pp = p->GetNextP();
		cout << "Delete This Node :" << p->GetStringP() << endl;
		delete p;
		p = pp;
	}
	delete head;
	delete tail;
}

void LinkedListWithString::Insert(char* str, unsigned int _cnt) {
	StringNode* newP = new StringNode(str, _cnt);
	newP->SetPrevP(tail->GetPrevP());
	newP->SetNextP(tail);
	tail->GetPrevP()->SetNextP(newP);
	tail->SetPrevP(newP);
	cout << "Insert  :" << newP->GetStringP() <<"Cnt : "<<newP->GetCnt()<< endl;
	return;
}

StringNode* LinkedListWithString::Search(char* str) {
	StringNode* p = head->GetNextP();
	while (p != tail) {
		if (mStrCmp(p->GetStringP(), str) == true) {
			cout << "find " << str << endl;
			return p;
		}
		p = p->GetNextP();
	}
	return nullptr;
}

void LinkedListWithString::Delete(char* str) {
	StringNode* p = nullptr;
	if ((p = Search(str)) != nullptr) {
		p->GetPrevP()->SetNextP(p->GetNextP());
		p->GetNextP()->SetPrevP(p->GetPrevP());
		delete p;
		cout << "Delete finish" << endl;
	}
}

void LinkedListWithString::PrintAll() {
	StringNode* p = head->GetNextP();
	while (p != tail) {
		cout << "String : " << p->GetStringP() << endl;
		p = p->GetNextP();
	}
	return;
}