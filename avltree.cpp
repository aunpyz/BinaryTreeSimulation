#include <iostream>
#include "tree.h"

void Tree::insert(int val, Node *&tmp)
{
    if(isEmpty())
    {
        root = new Node(val);
    }
    else//tree is not empty
    {
        //not working with same value insertion
        if(height(tmp->left) == -1)//has blank adjacent-spaced at left
        {
            if(val < tmp->value)
            {
                tmp->left = new Node(val);
                tmp->height = 1 + max(height(tmp->left), height(tmp->right));
            }
        }
        if(height(tmp->right) == -1)//has blank adjacent-spaced at right
        {
            if(val > tmp->value)
            {
                tmp->right = new Node(val);
                tmp->height = 1 + max(height(tmp->left), height(tmp->right));
            }
        }
        else //at somewhere other than leaf
        {
            if(val > tmp->value)
            {
                insert(val, tmp->right);

                //check if unbalance
                if(height(tmp->right) - height(tmp->left) == 2)
                {
                    if(val > tmp->right->value)
                    {
                        singleRotateR(tmp);
                    }
                    else
                        doubleRotateR(tmp);
                }
                else
                {
                    tmp->height = 1 + max(height(tmp->left), height(tmp->right));
                }
            }
            else if(val < tmp->value)
            {
                insert(val, tmp->left);

                //check if unbalanced
                if(height(tmp->left) - height(tmp->right) == 2)
                {
                    if(val < tmp->left->value)
                    {
                        singleRotateL(tmp);
                    }
                    else
                        doubleRotateL(tmp);
                }
                else
                {
                    tmp->height = 1 + max(height(tmp->left), height(tmp->right));
                }
            }
        }
    }
}

void Tree::remove(int val, Node *&tmp)
{

}
