#include <iostream>

using namespace std;

#ifndef NODE
#define NODE

class Node
{
public:
    Node();
    Node(int val, int height);
    Node *left, *right;
    int value;
    int height;
};

Node::Node()
{
    Node(0, 0);
}

Node::Node(int val, int hi)
{
    value = val;
    height = hi;
    left = right = nullptr;
}

#endif // NODE
