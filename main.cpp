#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tree.h"

using namespace std;

int main()
{
    Tree tree;
    srand(time(0));
    /*for(int i = 0; i < 500; i++)
    {
        int randnum = rand();
        //cout<<randnum<<",";
        tree.add(randnum);
    }
    //tree.print();
    cout<<"Tree's height : "<<tree.getHeight()<<endl;
    cout<<"Balancing..."<<endl;
    tree.balance();
    cout<<"after balancing"<<endl;
    //tree.print();
    cout<<"Tree's height : "<<tree.getHeight()<<endl;*/

    /*
    cout<<"Insertion(balance-ly)\n";
    for(int i = 0; i < 50; i++)
    {
        tree.insert(rand());
        //tree.print();
        cout<<endl;
    }
    cout<<"Tree's height : "<<tree.getHeight()<<endl;*/

    for(int i = 0; i < 20; i++)
    {
        tree.insert(i+1);
        tree.print();
        cout<<endl;
    }
    cout<<"Tree's height : "<<tree.getHeight()<<endl;

    int testlist[] = {1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31};
    for(int i = 0; i < sizeof(testlist)/sizeof(int); i++)
    {
        cout<<testlist[i]<<" was"<<(tree.search(testlist[i])?" ":" not ")<<"found"<<endl;
    }

    return 0;
}
