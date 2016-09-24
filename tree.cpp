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

void Tree::balance(Node *tmp)
{
    cout<<tmp->left->height<<"\t"<<tmp->right->height<<endl;
    if(height(tmp->left) != -1)
        Lbalance(tmp->left);
    if(height(tmp->right) != -1)
        Rbalance(tmp->right);
    cout<<tmp->left->height<<"\t"<<tmp->right->height<<endl;
}

void Tree::Lbalance(Node *tmp)
{
    if(height(tmp) != 0)
    {
        if(height(tmp)-height(tmp->left) == 1)
            Lbalance(tmp->left);
        else
            Lbalance(tmp->right);

        if(height(tmp->left) - height(tmp->right) > 1)
        {
            if(height(tmp->left->left) != -1 && height(tmp->left->right) == -1)
                singleRotateL(tmp);
            else
                doubleRotateL(tmp);
        }
        else if(height(tmp->right) - height(tmp->left) > 1)
        {
            if(height(tmp->right->right) != -1 && height(tmp->right->left) == -1)
                singleRotateR(tmp);
            else
                doubleRotateR(tmp);
        }
    }
}

void Tree::Rbalance(Node *tmp)
{
    if(height(tmp) != 0)
    {
        if(height(tmp)-height(tmp->right) == 1)
            Rbalance(tmp->right);
        else
            Rbalance(tmp->left);

        if(height(tmp->right) - height(tmp->left) > 1)
        {
            if(height(tmp->right->right) != -1 && height(tmp->right->left) == -1)
                singleRotateR(tmp);
            else
                doubleRotateR(tmp);
        }
        else if(height(tmp->left) - height(tmp->right) > 1)
        {
            if(height(tmp->left->left) != -1 && height(tmp->left->right) == -1)
                singleRotateL(tmp);
            else
                doubleRotateL(tmp);
        }
    }
}
//errors downward
void Tree::singleRotateL(Node *tmp)
{
    Node *tmp2 = tmp->left;
    tmp->left = tmp2->right;
    tmp2->right = tmp;
    tmp = tmp2;

    tmp->height = 1+max(height(tmp->left), height(tmp->right));
    tmp2->height = 1+max(height(tmp2->left), height(tmp2->right));
}

void Tree::singleRotateR(Node *tmp)
{
    Node *tmp2 = tmp->right;
    tmp->right = tmp2->left;
    tmp2->left = tmp;
    tmp = tmp2;

    tmp->height = 1+max(height(tmp->left), height(tmp->right));
    tmp2->height = 1+max(height(tmp2->left), height(tmp2->right));
}

void Tree::doubleRotateL(Node *tmp)
{
    /*singleRotateR(tmp);
    singleRotateL(tmp);*/
}

void Tree::doubleRotateR(Node *tmp)
{
    /*singleRotateL(tmp);
    singleRotateR(tmp);*/
}
