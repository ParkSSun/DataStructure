#include "LinkedListWithString.h"

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