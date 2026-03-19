// Hashing.cpp
#include "Hashing.h"
#include "Node.h"
/***************************************
* Author: Catherine T
* Name: ~HashingLL()
* Description: Destructor for hashing using a linked list to free up space
* Incoming: None
* Outgoing: None
* Return Type: None
* Reference:Linked List with Methods Lab (CS 255)
***************************************/
HashingLL:: ~HashingLL() { // destructor
	Node* current = head; // set current to head
	while (current != nullptr) { // while not at the end of the list
		Node* temp = current; // set temp pointer to current
		current = current->next; // traverse list
		delete temp; // delete item
	}
	head = nullptr; // set head equal to nullptr. no hanging pointer
}

/***************************************
* Author: Catherine 
* Name: HashingLL()
* Description:
* Incoming: None
* Outgoing: None
* Return Type: None
* Reference:Linked List with Methods Lab (CS 255)
***************************************/
HashingLL:: HashingLL(): head(nullptr) {}

/***************************************
* Author: Catherine
* Name: Hashing_LL_Copy(const HashingLL& other)
* Description:
* Incoming:
* Outgoing:
* Return Type: Void
* Reference: Linked List with Methods Lab (CS 255)
***************************************/
// Reference: Linked list with Methods Lab (cs 255)
void HashingLL:: Hashing_LL_Copy(const HashingLL& other) {
	if (this == &other) { // am i equal to myself?
		return;
	}
	if (other.head == nullptr) { // is head empty?
		head = nullptr;
		return;
	}

	head = new Node(other.head->data, nullptr);
	Node* current = head;
	Node* copyCurr = other.head->next;

	while (copyCurr != nullptr) { // create copy
		current->next = new Node(copyCurr->data, nullptr);
		current = current->next;
		copyCurr = copyCurr->next;
	}
}

/***************************************
* Author:
* Name: Hashing_LL_Delete(int item)
* Description:
* Incoming: int item
* Outgoing: True if item has been removed, false if item has not been removed
* Return Type: Bool
* Reference: Linked List with Methods Lab (CS 255)
***************************************/
bool HashingLL::Hashing_LL_Delete(int item) {
	if (head == nullptr) { // check if the list is empty
		return false; 
	}
	if (head->data == item) { // if item is in the list
		Node* temp = head;
		head = head->next;
		delete temp; // delete item
		return true; // return item has been deleted
	}
	Node* current = head->next;
	Node* previous = head;

	while (current != nullptr) { // while not at the end of the list
		if (current->data == item) {
			previous->next = current->next;
			delete current;
			return true;
		}
		previous = current;
		current = current->next;
	}
	return false;
}

/***************************************
* Author: Adi
* Name: Search(int item) const
* Description:
* Incoming: int item
* Outgoing:
* Return Type: None
* Reference: Linked List with Methods Lab (CS 255)
***************************************/
int HashingLL::Hashing_LL_Search(int item) const { // search for item
	Node* current = head;
	int nodeCount = -1;
	while (current != nullptr)
	{
		nodeCount++; // move position forward
		if (current->data == item)
		{
			return nodeCount; // position in linked list
		}
		current = current->next;
	}
	return -1;
}

/***************************************
* Author:
* Name: Hashing_LL_Insert(int item)
* Description:
* Incoming: int item
* Outgoing: true if tem has been inserted
* Return Type: Bool
* Reference: Linked List with Methods Lab (CS 255)
***************************************/
bool HashingLL:: Hashing_LL_Insert(int item) {
	Node* newNode = new Node(item, head);
	head = newNode; // add item to head of the list
	return true; 
}

/***************************************
* Author:
* Name: Hashing_LL_Display()
* Description:
* Incoming: None
* Outgoing: None
* Return Type: Void
* Reference: Linked List with Methods Lab (CS 255)
***************************************/
void HashingLL:: Hashing_LL_Display() {
	Node* temp = head;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;

}