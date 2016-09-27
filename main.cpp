#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tree.h"

using namespace std;

int main()
{
    Tree tree;
    srand(time(0));
    for(int i = 0; i < 1000; i++)
    {
        //int randnum = rand();
        //cout<<randnum<<",";
        //tree.add(randnum);
        tree.add(i+1);
    }
    //tree.print();
    cout<<"Tree's height : "<<tree.getHeight()<<endl;
    cout<<"Balancing..."<<endl;
    tree.balance();
    //tree.balance();
    cout<<"after balancing"<<endl;
    tree.print();
    cout<<"Tree's height : "<<tree.getHeight()<<endl;

    cout<<"Insertion(balance-ly)\n";
    for(int i = 0; i < 1000; i++)
    {
        tree.insert(i+1001);
        //tree.print();
        //cout<<endl;
    }
    tree.print();
    cout<<"Tree's height : "<<tree.getHeight()<<endl;

    /*for(int i = 0; i < 20; i++)
    {
        tree.insert(i+1);
        //tree.print();
        //cout<<endl;
    }
    cout<<"Tree's height : "<<tree.getHeight()<<endl;*/

    cout<<"Deletion(balance-ly)\n";
    for(int i = 0; i < 1000; i++)
    {
        int randnum = rand()%5000+1;
        cout<<randnum<<" was"<<(tree.search(randnum)?" ":" not ")<<"found"<<endl;
        tree.remove(randnum);
    }
    tree.print();

    /*tree.remove(19);
    tree.remove(3);
    tree.remove(5);
    tree.remove(6);
    tree.remove(11);
    tree.remove(8);*/
    //tree.print();

    return 0;
}
