 // HashTable.cpp
#include "HashTable.h"
HashTable::~HashTable(){ // destructor
	delete[] arr; // delete array
	arr = nullptr; // set equal to null pointer, no hanging pointers
}


HashTable::HashTable(int size) : size(size) {
    arr = new HashingLL[size]; // create dynamic array
}

bool HashTable::HashTable_Insert(int value) {
	// 1. need to compute the index. 2. get valid bucket index
	int num = value % size;
	return arr[num].Hashing_LL_Insert(value);
}

bool HashTable::HashTable_Remove(int value) {
	int num = value % size;
	return arr[num].Hashing_LL_Delete(value);

}

void HashTable:: HashTable_Print() {
	for (int i = 0; i < size; i++) {
		cout << "Index: " << i << ": ";
		arr[i].Hashing_LL_Display();
	}

}

pair<int, int> HashTable::HashTable_Search(int value)
{
	int num = value % size;
	int nodeCount=arr[num].Hashing_LL_Search(value);
	if (nodeCount == -1)
		return { -1, -1 };

	return {num, nodeCount};
}

//double HashTable::HashTable_LoadFactor() {
//	return 3.14;
//}
