// Node.h
#ifndef _NODE_H_
#define _NODE_H_

class Node {
	int data;
	Node* next;
	Node();
	Node(int);
	Node(int item, Node* n);
	friend class HashingLL;
};
#endif
