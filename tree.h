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
    bool search(int val);
    int getHeight()
    {
        return root->height;
    };

    //balance method
    void balance()
    {
        balance(root);
    }
    void insert(int val)
    {
        insert(val, root);
    }
    void remove(int val)
    {
        remove(val, root);
    }

private:
    Node *root;
    void print(Node *start);
    int height(Node *tmp);
    int max(int left, int right);
    void add(int val, Node *tmp, Node *prev);
    void balance(Node *&tmp);
    /*void Lbalance(Node *&tmp);
    void Rbalance(Node *&tmp);*/
    void rotate(Node *&tmp);
    void singleRotateL(Node *&tmp);
    void singleRotateR(Node *&tmp);
    void doubleRotateL(Node *&tmp);
    void doubleRotateR(Node *&tmp);
    void insert(int val, Node *&tmp);
    void remove(int val, Node *&tmp);
};

#endif // TREE
