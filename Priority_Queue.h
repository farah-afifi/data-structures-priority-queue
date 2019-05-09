#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include <iostream>
using namespace std;

struct PriorityNode{
    string info;
	int priority;
	PriorityNode *nextNode  ,*prevNode;

    PriorityNode (string val = "" ,int p = 0 , PriorityNode * pNode = NULL, PriorityNode * nNode = NULL){
        info = val;
        priority = p;
        nextNode = nNode;
        prevNode = pNode;
    }
};

class Priority_Queue
{
    public:
        Priority_Queue();
        void enqueue(string value, int p);
        string dequeue();
        void print();
        ~Priority_Queue();

    private:
        PriorityNode *End, *Front;
        int Size;
};

#endif // PRIORITY_QUEUE_H
