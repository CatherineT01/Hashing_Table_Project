// Node.cpp
#include "Node.h"
/***************************************
* Author: Catherine
* Name: Node()
* Description:
* Incoming: None
* Outgoing:
* Return Type: None
* Reference: Linked List with Methods Lab (CS 255)
***************************************/
Node::Node(): data(0), next(nullptr) {}

/***************************************
* Author: Catherine
* Name: Node(int item)
* Description:
* Incoming: int item
* Outgoing:
* Return Type: None
* Reference: Linked List with Methods Lab (CS 255)
***************************************/
Node::Node(int item): data(item), next(nullptr) {}

/***************************************
* Author: Catherine
* Name: Node(int item, Node* n)
* Description:
* Incoming: int item, Node* n
* Outgoing:
* Return Type: None
* Reference: Linked List with Methods Lab (CS 255)
***************************************/
Node::Node(int item, Node* n): data(item), next(n) {}


