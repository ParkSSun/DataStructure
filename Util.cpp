#include"Util.h"

unsigned int mStrLen(char* word) {
	unsigned int len = 0;
	while (word[len] != '\0')len++;
	return len;
}

void mStrCpy(char* dst, char* src, unsigned int len) {
	unsigned int idx = 0;
	while (len != idx)dst[idx] = src[idx++];
	dst[idx] = '\0';
	return;
}

bool mStrCmp(char* rhs, char*lhs) {
	unsigned int rhs_len = mStrLen(rhs);
	unsigned int lhs_len = mStrLen(lhs);
	if (lhs_len != rhs_len)return false;
	unsigned int idx = 0;
	while (idx < lhs_len) {
		if (rhs[idx] != lhs[idx++])return false;
	}
	return true;
}
