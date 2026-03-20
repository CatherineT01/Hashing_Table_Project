//HashTable.h
#ifndef _HASHTABLE_
#define _HASHTABLE_
#include "Hashing.h"
#include<iostream>
using namespace std;

template<class Type>
class HashTable {
	int size;
	int count; //counts the number of occupied nodes
	HashingLL<Type>* arr;
public:
	~HashTable(); // Hash destructor 
	HashTable(int size); // constructor 
	bool HashTable_Insert(Type value); // insert hash value
	bool HashTable_Remove(Type value); // remove hash value
	void HashTable_Print(); // print hash table
	pair<int, int> HashTable_Search(Type value);//returns the location of the value if found
	double HashTable_LoadFactor();
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
		count = 0; //setting count to 0 as no data is stored in the table anymore
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
	HashTable<Type>::HashTable(int size) : size(size) {
		arr = new HashingLL<Type>[size]; // create dynamic array
		count = 0; //during initialization as no data is present, set count to 0
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
		count++; //increment count
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
		bool result = arr[num].Hashing_LL_Delete(value);
		if (result == true) {
			count--;//if value is removed, update the count
		}
		return result;  
	}

	/***************************************
	* Author: Adi
	* Name: HashTable_Search(int value)
	* Description:
	* Incoming: int value
	* Outgoing: Location pair
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
	* Author: Adi
	* Name: HashTable_LoadFactor()
	* Description: Returns the Loadfactor of the hashtable
	* Incoming: None
	* Outgoing: LoadFactor
	* Return Type: double
	* Reference:
	***************************************/
	template<class Type>
	double HashTable<Type>::HashTable_LoadFactor()
	{
		double result= (double)count/(double)size; //casting the size and count to double to get the correct value
		return result;
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
