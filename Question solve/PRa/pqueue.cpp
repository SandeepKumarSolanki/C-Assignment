#include<iostream>
#define EMPTY_LIST -1
using namespace std;

struct node
{
    int pn;
    int item;
    node *next;
};

class pqueue
{
    private:
        node *start;
    public:
        pqueue();
        pqueue(pqueue &);
        pqueue& operator=(pqueue &);
        void insertItem(int,int);
        void deleteHighest();
        int getHighest();
        int getHighestPriority();
        bool isEmpty();
        void display();
        ~pqueue();

};

pqueue::pqueue()
{
    start=NULL;
}

pqueue::pqueue(pqueue &p)
{
    node *temp;
        start=NULL;
    if(p.start){
        temp=p.start;
        while(temp!=NULL){
            insertItem(temp->pn,temp->item);
            temp=temp->next;
        }
    }
}

pqueue& pqueue::operator=(pqueue &p)
{
    while(start)
        deleteHighest();
    node *temp;
    if(p.start){
        temp=p.start;
        while(temp!=NULL){
            insertItem(temp->pn,temp->item);
            temp=temp->next;
        }
    }
    return *this;
}

void pqueue::insertItem(int num,int data)
{
    node *temp,*n=new node;
    n->pn=num;
    n->item=data;
    if(start==NULL || start->pn < n->pn){
        n->next=start;
        start=n;
    }
    else{
        temp=start;
        while((temp->next!=NULL)){
            if(temp->next->pn < n->pn){
               break;
            }
            temp=temp->next;
        }
        n->next=temp->next;
        temp->next=n;
    }
}

void pqueue::deleteHighest()
{
    node *temp;
    if(start==NULL)
    {
        cout<<"List underflow";
    }
    else
    {
        temp=start;
        start=start->next;
        delete temp;
    }
}

int pqueue::getHighest()
{
    if(start==NULL)
        return EMPTY_LIST;
    return start->item;
}

int pqueue::getHighestPriority()
{
    if(start)
        return start->pn;
    return EMPTY_LIST;
}

bool pqueue::isEmpty()
{
    return start==NULL;
}

void pqueue::display()
{
    if(start==NULL)
        cout<<"Priority queue is empty";
    else{
        node *ptr=start;
        while(ptr!=NULL){
            cout<<endl<<"Priority-number="<<ptr->pn<<" data="<<ptr->item;
            ptr=ptr->next;
        }
    }
}
pqueue::~pqueue()
{
    while(start)
        deleteHighest();
}

int main()
{
    pqueue p;
    p.insertItem(3,36);
    p.insertItem(5,32);
    
    p.insertItem(1,40);
    p.display();
    cout<<endl;
    p.insertItem(7,3);

    p.display();

    cout<<endl;

    p.insertItem(4,897);
    p.display();
    return 0;
}