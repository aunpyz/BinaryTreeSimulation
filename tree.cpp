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
        cout<<tmp->value<<"\tat height of\t"<<tmp->height<<"\t";
        int diff = height(tmp->left)-height(tmp->right);
        cout<<(diff<0?diff*-1:diff)<<endl;
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

void Tree::balance(Node *&tmp)
{
    /*if(height(tmp->left) != -1)//balancing left subtree if exists
    {
        Lbalance(tmp->left);
    }
    if(height(tmp->right) != -1)//balancing right subtree if exists
    {
        Rbalance(tmp->right);
    }*/

    //left-handed traversal
    if(height(tmp->left) >-1)
    {
        if(height(tmp->left)>-1)
            balance(tmp->left);
        if(height(tmp->right)>-1)
            balance(tmp->right);
    }

    //right-handed traversal
    if(height(tmp->right) > -1)
    {
        if(height(tmp->right)>-1)
            balance(tmp->right);
        if(height(tmp->left)>-1)
            balance(tmp->left);
    }

    rotate(tmp);
    //update tree's height
    tmp->height = 1 + max(height(tmp->left), height(tmp->right));
    //print(tmp);
    //cout<<height(tmp)<<endl;
}

//Lbalance and Rbalance are symmetrical methods

/*void Tree::Lbalance(Node *&tmp)
{
    if(height(tmp) != 0)
    {
        //go to the child where height < its parent = 1
        if(height(tmp)-height(tmp->left) == 1)
        {
            Lbalance(tmp->left);
        }
        else
        {
            Rbalance(tmp->right);
        }


        if(height(tmp->left)-height(tmp->right) > 1)//left-subtree higher than right-subtree, cause unbalanced tree
        {
            if(height(tmp->left->left) != -1 && height(tmp->left->right) == -1)//do single rotation
            {
                singleRotateL(tmp);
            }
            else
            {
                doubleRotateL(tmp);
            }
        }
        else if(height(tmp->right)-height(tmp->left) > 1)
        {
            if(height(tmp->right->right) != -1 && height(tmp->right->left) == -1)
            {
                singleRotateR(tmp);
            }
            else
            {
                doubleRotateR(tmp);
            }
        }

        //testing
        rotate(tmp);

    }
}

void Tree::Rbalance(Node *&tmp)
{
    if(height(tmp) != 0)
    {
        if(height(tmp)-height(tmp->right) == 1)
        {
            Rbalance(tmp->right);
        }
        else
        {
            Lbalance(tmp->left);
        }

        if(height(tmp->left)-height(tmp->right) > 1)//left-subtree higher than right-subtree, cause unbalanced tree
        {
            if(height(tmp->left->left) != -1 && height(tmp->left->right) == -1)//do single rotation
            {
                singleRotateL(tmp);
            }
            else
            {
                doubleRotateL(tmp);
            }
        }
        else if(height(tmp->right)-height(tmp->left) > 1)
        {
            if(height(tmp->right->right) != -1 && height(tmp->right->left) == -1)
            {
                singleRotateR(tmp);
            }
            else
            {
                doubleRotateR(tmp);
            }
        }

        //testing
        rotate(tmp);
    }
}*/

void Tree::singleRotateL(Node *&k2)
{
    Node *k1=k2->left;

    k2->left = k1->right;
    k1->right = k2;

    //update height
    k2->height = 1 + max(height(k2->left), height(k2->right));
    k1->height = 1 + max(height(k1->left), height(k1->right));

    //place k2 at k1's address
    k2 = k1;
}

void Tree::singleRotateR(Node *&k2)
{
    Node *k1=k2->right;

    k2->right = k1->left;
    k1->left = k2;

    k2->height = 1 + max(height(k2->left), height(k2->right));
    k1->height = 1 + max(height(k1->left), height(k1->right));

    k2 = k1;
}

void Tree::doubleRotateL(Node *&k3)
{
    singleRotateR(k3->left);
    singleRotateL(k3);
}

void Tree::doubleRotateR(Node *&k3)
{
    singleRotateL(k3->right);
    singleRotateR(k3);
}

void Tree::rotate(Node *&tmp)
{
    while(height(tmp->left)-height(tmp->right)>1 || height(tmp->right)-height(tmp->left)>1)//continue to balance if the tree still unbalance
    {
        if(height(tmp->left)-height(tmp->right)>1)//left-subtree is higher
        {
            if(height(tmp->left->right) != -1)//has right-subtree of left-subtree
            {
                if(height(tmp->left->left) > height(tmp->left->right))
                {
                    singleRotateL(tmp);
                }
                else//height(tmp->left->right) >= height(tmp->left->left)
                    doubleRotateL(tmp);
            }
            else
                singleRotateL(tmp);
        }
        else if(height(tmp->right)-height(tmp->left)>1)//right-subtree is higher
        {
            if(height(tmp->right->left) != -1)//has left-subtree of right-subtree
            {
                if(height(tmp->right->right) > height(tmp->right->left))
                {
                    singleRotateR(tmp);
                }
                else
                    doubleRotateR(tmp);
            }
            else
                singleRotateR(tmp);
        }
    }
    //print(tmp);
}
