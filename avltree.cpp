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

void Tree::remove(int val, Node *&tmp, Node *&prev)
{
    if(height(tmp) != -1)
    {
        if(val > tmp->value)
        {
            if(height(tmp->right) == -1)
            {
                cout<<"Don't have "<<val<<" in this avl tree"<<endl;
                return;
            }
            else
                remove(val, tmp->right, tmp);
        }
        else if(val < tmp->value)
        {
            if(height(tmp->left) == -1)
            {
                cout<<"Don't have "<<val<<" in this avl tree"<<endl;
                return;
            }
            else
                remove(val, tmp->left, tmp);
        }
        else//found
        {
            //check if tree has two subtrees
            if(height(tmp->left) != -1 && height(tmp->right) != -1)
            {
                //go finding right-subtree's smallest value
                findmin(tmp, tmp->right, prev);
            }
            else if(height(tmp->left) == -1 && height(tmp->right) == -1)//leaf or 1-node tree, root
            {
                if(tmp == prev)//tree contains only root
                {
                    tmp = nullptr;
                }
                else if(val > prev->value)
                {
                    prev->right = nullptr;
                    delete tmp;
                }
                else
                {
                    prev->left = nullptr;
                    delete tmp;
                }
            }
            else if(height(tmp->left) == -1)//no left-subtree
            {
                if(val > prev->value)
                {
                    prev->right = tmp->right;
                }
                else
                {
                    prev->left = tmp->right;
                }
            }
            else//no right-subtree
            {
                if(val > prev->value)
                {
                    prev->right = tmp->left;
                }
                else
                {
                    prev->left = tmp->left;
                }
            }
        }
    }
    prev->height = 1 + max(height(prev->left), height(prev->right));
    rotate(prev);
}

void Tree::findmin(Node *&toDel, Node *&tmp, Node *&prev)
{
    //cout<<tmp->left->value<<endl;
    if(height(tmp->left) == -1)//is actually minimum number
    {
        Node *pTmp = tmp, *pToDel = toDel->right;
        prev->left = tmp->right;//prev->left means tmp, prev->left = tmp->right means tmp is replaced with its child.
        toDel->value = pTmp->value;//copy just value; harmless
        prev->height = 1 + max(height(prev->left), height(prev->right));
    }
    else
    {
        findmin(toDel, tmp->left, tmp);
    }
    rotate(prev);
}
