#include <iostream>
#include "node.h"

using namespace std;

#ifndef TREE_H
#define TREE_H

class Tree
{
public:
    Tree();
    void add(int val);
    void print();
    bool isEmpty();
    int getHeight()
    {
        return root->height;
    };

    //balance method
    void balance();
    void addB();
    void rmvB();
    void singleRotation();
    void doubleRotation();

private:
    Node *root;
    void print(Node *start);
    int height(Node *tmp);
    int max(int left, int right);
    void add(int val, Node *tmp, Node *prev);
};

#endif // TREE
