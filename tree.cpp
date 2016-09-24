#include <iostream>
#include "tree.h"
#include "node.h"

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

void Tree::balance()
{
    //go to node where depth = height
    Node *tmp = root;
    while(tmp->height != 0)
    {
        if(tmp->left == nullptr)//left node is null, go right
            tmp = tmp->right;
        else if(tmp->right == nullptr)//right node is null, go left
            tmp = tmp->left;
        else if(tmp->left->height - tmp->height == 1)
            tmp = tmp->left;
        else
            tmp = tmp->right;
        //just for checking..
        cout<<tmp->height<<"\t"<<tmp->value<<endl;
    }

    //balancing
}
