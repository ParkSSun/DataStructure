#pragma once
#include "quickSort.h"
quickSort::quickSort() {}
quickSort::~quickSort() {}

void quickSort::sort(int data[], int size) {
	QSort(data, 0, size - 1);
	return;
}

void quickSort::QSort(int data[], int startIdx, int endIdx) {
	if (startIdx == endIdx)return;
	int Lidx = startIdx;
	int Tidx = startIdx;
	int Pidx = endIdx;
	while (Lidx != Pidx) {
		if (data[Lidx] < data[Pidx]) {
			if (Lidx != Pidx) {
				int buf = data[Lidx];
				data[Lidx] = data[Tidx];
				data[Tidx++] = buf;
			}
		}
		Lidx++;
	}
	int buf = data[Tidx];
	data[Tidx] = data[Pidx];
	data[Pidx] = buf;
	if (startIdx == Tidx) return;
	QSort(data, startIdx, Tidx - 1);
	if (endIdx == Tidx)return;
	QSort(data, Tidx + 1, endIdx);
	return;

}