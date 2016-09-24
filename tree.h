#include <iostream>
#include "node.h"

using namespace std;

#ifndef TREE
#define TREE

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
private:
    Node *root;
    void print(Node *start);
    int height(Node *tmp);
    int max(int left, int right);
    void add(int val, Node *tmp, Node *prev);
};

Tree::Tree()
{
    root = nullptr;
}


bool Tree::isEmpty()
{
    return root == nullptr;
}

void Tree::add(int val)
{
    add(val, root, root);
}

//work recursively
void Tree::add(int val, Node *tmp, Node *prev)
{
    //check if we're at the leaf
    if(tmp == nullptr)
    {
        if(isEmpty())
            root = new Node(val, 0);
        else if (prev->value > val)
            prev->left = new Node(val, 0);
        else if (prev->value < val)
            prev->right = new Node(val, 0);
    }
    //at other than leaf
    else
    {
        if(tmp->value > val)
        {
            add(val, tmp->left, tmp);
        }
        else if(tmp->value < val)
        {
            add(val, tmp->right, tmp);
        }

        tmp->height = 1+max(height(tmp->left),height(tmp->right));
    }
}

void Tree::print()
{
    print(root);
}

void Tree::print(Node *start)
{
    Node *tmp = start;
    if(tmp != nullptr)
    {
        print(tmp->left);
        cout<<tmp->value<<"\tat height of\t"<<tmp->height<<endl;
        print(tmp->right);
    }
}

int Tree::height(Node *tmp)
{
    if(tmp == nullptr)
        return -1;
    return tmp->height;
}

int Tree::max(int left, int right)
{
    return (left >= right)?left:right;
}

#endif // TREE
