#ifndef _HASHING_H_
#define _HASHING_H_
#include <iostream>
using namespace std;

class Node; // Forward declaration

class HashingLL {
    Node* head;
public:
    ~HashingLL();
    HashingLL();
    void Hashing_LL_Copy(const HashingLL &other); // copy constructor
    bool Hashing_LL_Delete(int item); // delete item from LL
    bool Hashing_LL_Insert(int item); // insert item to linked list
    int Hashing_LL_Search(int item) const; // search item in linked list
    void Hashing_LL_Display(); // display
};
#endif

