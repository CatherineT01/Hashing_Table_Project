//HashTable.h
#ifndef _HASHTABLE_
#define _HASHTABLE_
#include "Hashing.h"
#include<iostream>
using namespace std;

template<class Type>
class HashTable {
	int size;
	HashingLL<Type>* arr;
public:
	~HashTable(); // Hash destructor 
	HashTable(Type size); // constructor 
	bool HashTable_Insert(Type value); // insert hash value
	bool HashTable_Remove(Type value); // remove hash value
	void HashTable_Print(); // print hash table
	pair<int, int> HashTable_Search(Type value);//returns the location of the value if found

	//double HashTable_LoadFactor();
};

/***************************************
* Author: Catherine
* Name: ~HashTable()
* Description: Destructor for the hash table to free up dynamically allocated memory
* Incoming: None
* Outgoing: None
* Return Type: None
* Reference:Linked List with Methods Lab (CS 255)
***************************************/
	template<class Type>
	HashTable<Type>::~HashTable() { // destructor
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
	template<class Type>
	HashTable<Type>::HashTable(Type size) : size(size) {
		arr = new HashingLL<Type>[size]; // create dynamic array
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
	template<class Type>
	bool HashTable<Type>::HashTable_Insert(Type value) {
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
	template<class Type>
	bool HashTable<Type>::HashTable_Remove(Type value) {
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
	template<class Type>
	pair<int, int> HashTable<Type>::HashTable_Search(Type value)
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
	template<class Type>
	void HashTable<Type>::HashTable_Print() {
		for (int i = 0; i < size; i++) {
			cout << "Index: " << i << ": ";
			arr[i].Hashing_LL_Display();
		}

	}


	//double HashTable::HashTable_LoadFactor() {
	//	return 3.14;
	//}

#endif
