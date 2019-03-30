#pragma once


class quickSort {
public:
	quickSort();
	~quickSort();
	void sort(int data[], int size);

private:
	void QSort(int data[], int startIdx, int endIdx);

};
