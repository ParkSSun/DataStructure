#ifndef __QUICKSORTWITHLINKEDLIST_H__
#define __QUICKSORTWITHLINKEDLIST_H__
#include "LinkedListWithString.h"
#include "Util.h"
class QSortWithLinkedList {
public:
	QSortWithLinkedList() {}
	~QSortWithLinkedList() {}
	void sort(LinkedListWithString& list);
private:
	bool qSortWithCnt(StringNode* start, StringNode* end, LinkedListWithString& list);
	bool Swap(StringNode* rhs, StringNode* lhs);
};

void QSortWithLinkedList::sort(LinkedListWithString& list) {
	if (list.GetHead()->GetNextP() == list.GetTail())return;
	qSortWithCnt(list.GetHead()->GetNextP(), list.GetTail()->GetPrevP(), list);
	return;
}

bool QSortWithLinkedList::qSortWithCnt(StringNode* start, StringNode* end, LinkedListWithString& list) {
	//if (start == end || start == list.GetHead() || start == list.GetTail() || end == list.GetHead() || end == list.GetTail())return true;
	if (start == end)return true;
	StringNode* L = start;
	StringNode* T = start;
	StringNode* P = end;
	while (L != P) {
		if (L->GetCnt() < P->GetCnt()) {
			Swap(L, T);
			T = T->GetNextP();
		}
		L = L->GetNextP();
	}
	Swap(P, T);
	if (start == T)return true;
	qSortWithCnt(start, T->GetPrevP(), list);
	if (end == T)return true;
	qSortWithCnt(T->GetNextP(), end, list);
	return true;
}

bool QSortWithLinkedList::Swap(StringNode* rhs, StringNode* lhs) {
	char buffer[20] = { 0, };
	unsigned int buf = rhs->GetCnt(); rhs->SetCnt(lhs->GetCnt()); lhs->SetCnt(buf);
	mStrCpy(buffer, rhs->GetStringP(), mStrLen(rhs->GetStringP()));
	mStrCpy(rhs->GetStringP(), lhs->GetStringP(), mStrLen(lhs->GetStringP()));
	mStrCpy(lhs->GetStringP(), buffer, mStrLen(buffer));
	return true;
}



#endif
