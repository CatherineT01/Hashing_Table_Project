//HashTable.h
#ifndef _HASHTABLE_
#define _HASHTABLE_
#include "Hashing.h"
class HashTable {
    int size;
    HashingLL* arr;
public:
    ~HashTable(); // Hash destructor 
    HashTable(int size); // constructor 
    bool HashTable_Insert(int value); // insert hash value
    bool HashTable_Remove(int value); // remove hash value
    void HashTable_Print(); // print hash table
    //double HashTable_LoadFactor();
};
#endif
