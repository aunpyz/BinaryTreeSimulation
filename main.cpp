#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tree.h"
/*
    * Insert 500 Random numbers into a binary tree – output the height of the tree.
    * Balance the tree – output the new height of the tree.

    * Add an interface which allows the user to decide how many ‘insertion’ operations should be done.

    * Allow the user to search to find out if a particular node is in the tree.
    * Allow the user to decide how many deletion operations should be performed
    (i.e. generate a random number, and if that number is in the tree, delete it).
*/
using namespace std;

int main ()
{
    Tree<int> mytree;

    srand(time(0));
    int randomNum;
    for(int i=0; i<500; i++)
    {
        randomNum = rand();
        //mytree.insert(randomNum);
        mytree.insert(i+1);
    }

    //mytree.inorder();
    cout<<"Height: "<<mytree.getHeight()<<endl;
    cout<<"\nBalance"<<endl;
    mytree.balance();
    mytree.inorder();
    cout<<"Height: "<<mytree.getHeight()<<endl;
    return 0;
}
