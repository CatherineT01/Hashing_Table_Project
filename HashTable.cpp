 // HashTable.cpp
#include "HashTable.h"
/***************************************
* Author: Catherine
* Name: ~HashTable()
* Description: Destructor for the hash table to free up dynamically allocated memory
* Incoming: None
* Outgoing: None
* Return Type: None
* Reference:Linked List with Methods Lab (CS 255)
***************************************/
HashTable::~HashTable(){ // destructor
	delete[] arr; // delete array
	arr = nullptr; // set equal to null pointer, no hanging pointers
}

/***************************************
* Author: Catherine
* Name: HashTable(int size)
* Description:
* Incoming: int size
* Outgoing: None
* Return Type: None
* Reference:
***************************************/
HashTable::HashTable(int size) : size(size) {
    arr = new HashingLL[size]; // create dynamic array
}

/***************************************
* Author: Catherine
* Name: HashTable_Insert(int value)
* Description:
* Incoming: int value
* Outgoing:
* Return Type: Bool
* Reference:
***************************************/
bool HashTable::HashTable_Insert(int value) {
	// 1. need to compute the index. 2. get valid bucket index
	int num = value % size;
	return arr[num].Hashing_LL_Insert(value);
}

/***************************************
* Author: Catherine
* Name: HashTable_Remove(int value)
* Description:
* Incoming: int value
* Outgoing:
* Return Type: Bool
* Reference:
***************************************/
bool HashTable::HashTable_Remove(int value) {
	int num = value % size;
	return arr[num].Hashing_LL_Delete(value);
}

/***************************************
* Author: Adi
* Name: HashTable_Search(int value)
* Description:
* Incoming: int value
* Outgoing:
* Return Type: pair<int, int>
* Reference: W3 Schools Pair Data Type
***************************************/
pair<int, int> HashTable::HashTable_Search(int value)
{
	int num = value % size;
	int nodeCount = arr[num].Hashing_LL_Search(value);
	if (nodeCount == -1)
		return { -1, -1 };

	return { num, nodeCount };
}

/***************************************
* Author: Catherine
* Name: HashTable_Print()
* Description: Print hash table handling collision with linked lists
* Incoming: None
* Outgoing: None
* Return Type: Void
* Reference:
***************************************/
void HashTable:: HashTable_Print() {
	for (int i = 0; i < size; i++) {
		cout << "Index: " << i << ": ";
		arr[i].Hashing_LL_Display();
	}

}


//double HashTable::HashTable_LoadFactor() {
//	return 3.14;
//}
