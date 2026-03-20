// Node.h
#ifndef _NODE_H_
#define _NODE_H_

template<class Type>
class Node {
	Type data;
	Node* next;
	Node();
	Node(Type);
	Node(Type item, Node* n);
	template<class T> friend class HashingLL;
	};

// Node functions
/***************************************
* Author: Catherine
* Name: Node()
* Description:
* Incoming: None
* Outgoing:
* Return Type: None
* Reference: Linked List with Methods Lab (CS 255)
***************************************/
template<class Type>
Node<Type>::Node() : data(0), next(nullptr) {}

/***************************************
* Author: Catherine
* Name: Node(int item)
* Description:
* Incoming: int item
* Outgoing:
* Return Type: None
* Reference: Linked List with Methods Lab (CS 255)
***************************************/
template<class Type>
Node<Type>::Node(Type item) : data(item), next(nullptr) {}

/***************************************
* Author: Catherine
* Name: Node(int item, Node* n)
* Description:
* Incoming: int item, Node* n
* Outgoing:
* Return Type: None
* Reference: Linked List with Methods Lab (CS 255)
***************************************/
template<class Type>
Node<Type>::Node(Type item, Node* n) : data(item), next(n) {}

#endif