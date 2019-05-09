#include "Priority_Queue.h"


Priority_Queue::Priority_Queue()
{
    End = NULL;
    Front = NULL;
    Size = 0 ;
}

void Priority_Queue::enqueue(string value, int p)
{
    PriorityNode *Node = new PriorityNode(value , p , NULL , End );
    if(End == NULL){
        End = Node;
        Front = Node;
    }
    else{
        if(p > End->priority)
        {
            End->prevNode = Node;
            End = Node;
        }
        else if(p < Front ->priority )
        {
            Node = new PriorityNode(value , p ,Front , NULL );
            Front->nextNode = Node;
            Front = Node;
        }
        else{
            PriorityNode *cur = End ->nextNode;
            while( p <= cur->priority && cur->nextNode != 0){
                cur = cur->nextNode;
            }

            PriorityNode *n = new PriorityNode(value , p , cur->prevNode , cur );
            cur->prevNode->nextNode = n;
            cur->prevNode = n;
        }

   }
    Size++;
}

string Priority_Queue::dequeue()
{
     if (Size <= 0)
    {
        cout <<"there is nothing to remove!!\n";
        return "";
    }

    string Name = Front->info;

    PriorityNode *temp = Front ->prevNode;
    delete Front;
    Front = temp;
    Front->nextNode =NULL;

    Size--;
    return Name;
}


Priority_Queue::~Priority_Queue()
{
    PriorityNode *cur = End , *Next;
    while( cur->nextNode!= 0 )
    {
        Next = cur->nextNode;
        delete cur;
        cur = Next;
    }
    delete cur;

}
void Priority_Queue::print(){
    PriorityNode* cur = End;

    while(cur->nextNode != 0 ){
        cout <<cur ->info << " " ;
        cur = cur ->nextNode;
    }
    cout <<cur->info << "\n" ;
}

