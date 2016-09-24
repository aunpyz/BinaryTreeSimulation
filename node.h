#include <iostream>

using namespace std;

#ifndef NODE_H
#define NODE_H

class Node
{
public:
    Node();
    Node(int val, int height);
    Node *left, *right;
    int value;
    int height;
};

#endif // NODE
