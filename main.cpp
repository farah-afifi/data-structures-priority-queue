#include <iostream>
#include "Priority_Queue.h"
using namespace std;

int main()
{
    Priority_Queue Q;
    Q.enqueue("5" , 5);
    Q.enqueue("2" , 2);
    Q.enqueue("2-2" , 2);
    Q.enqueue("3" , 3);
    Q.print();


    cout<<Q.dequeue()<<endl;
    cout<<Q.dequeue()<<endl;
    cout<<Q.dequeue()<<endl;

    Q.print();

    return 0;
}
