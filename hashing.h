#include "LinkedList.h"



class Hash {
public:
	Hash();
	~Hash();
	void Delete(int data);
	LinkedList* Search(int data);
	void Insert(int data);
	void DeleteAllTable();

private:
	int hashfunction(int data);
};
