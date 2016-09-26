#include "node.h"

Node::Node()
{
    Node(0);
}

Node::Node(int val)
{
    value = val;
    height = 0;
    left = right = nullptr;
}
