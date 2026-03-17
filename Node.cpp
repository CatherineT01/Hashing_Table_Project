// Node.cpp
#include "Node.h"
Node::Node(): data(0), next(nullptr) {}

Node::Node(int item): data(item), next(nullptr) {}

Node::Node(int item, Node* n): data(item), next(n) {}


