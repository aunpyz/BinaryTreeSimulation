#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tree.h"

using namespace std;

int main()
{
    Tree tree;
    srand(time(0));
    for(int i = 0; i < 10; i++)
    {
        tree.add(rand());
    }
    tree.print();
    cout<<"Tree's height : "<<tree.getHeight()<<endl;
    cout<<"Balancing..."<<endl;
    tree.balance();
    tree.print();
    cout<<"Tree's height : "<<tree.getHeight()<<endl;
    return 0;
}
