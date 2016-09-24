#include "node.h"

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
