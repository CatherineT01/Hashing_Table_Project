// Hashing.cpp
#include "Hashing.h"
#include "Node.h"

// Reference: Linked list with Methods Lab (cs 255)
HashingLL:: ~HashingLL() { // destructor
	Node* current = head; // set current to head
	while (current != nullptr) { // while not at the end of the list
		Node* temp = current; // set temp pointer to current
		current = current->next; // traverse list
		delete temp; // delete item
	}
	head = nullptr; // set head equal to nullptr. no hanging pointer
}

HashingLL:: HashingLL(): head(nullptr) {}

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

// Reference: Linked list with Methods Lab (cs 255) 
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


bool HashingLL:: Hashing_LL_Insert(int item) {
	Node* newNode = new Node(item, head);
	head = newNode; // add item to head of the list
	return true; 
	
}

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

// Reference: Linked list with Methods Lab (cs 255)
/*
bool HashingLL:: Hashing_LL_Search(int item)const {
	Node* current = head;
	while (current != nullptr){ // while not at the end of list
		if (current->data == item) { // if the current item is the item
			return true; // return true if found
		}
		current = current->next; // if not, move to next item
	}
	return false; // return false if not found
}
*/
void HashingLL:: Hashing_LL_Display() {
	Node* temp = head;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;

}