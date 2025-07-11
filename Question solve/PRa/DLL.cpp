#include<iostream>
using namespace std;

struct node
{
    node *prev;
    int item;
    node *next;
};

class DLL 
{
    private: 
       node *start;
    public:
       DLL();
       DLL(DLL &);
       DLL& operator=(DLL &);
       void insertAtFirst(int);
       void insertAtLast(int);
       void insertAfter(node *,int);
       node* search(int);
       void deleteFirst();
       void deleteLast();
       void deleteAfter(node*);
       void display();
       ~DLL();
};

DLL::DLL()
{
    start=NULL;
}

DLL::DLL(DLL &list)
{
    node *t;
    if(list.start!=NULL){
        t=list.start;
        while(t->next!=NULL){
            t=t->next;
        }
        while(t)
        {
            insertAtFirst(t->item);
            t=t->prev;
        }
    }
    else
    {
        start=NULL;
    }
}

DLL& DLL::operator=(DLL &list)
{
    while(start)
       deleteFirst();
    
    node *t;
    if(list.start!=NULL)
    {
        t=list.start;
        while(t->next!=NULL){
            t=t->next;
        }
        while(t)
        {
            insertAtFirst(t->item);
            t=t->prev;
        }
    }
    else{
        start=NULL;
    }
    return *this;
}

void DLL::insertAtFirst(int data)
{
    node *n=new node;
    n->prev=NULL;
    n->item=data;
    n->next=start;
    if(start!=NULL)
        start->prev=n;
    start=n;
}

void DLL::insertAtLast(int data)
{
    node *temp,*n=new node;
    n->item=data;
    n->next=NULL;
    if(start==NULL)
    {
        n->prev=NULL;
        start=n;
    }
    else
    {
        temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        n->prev=temp;
        temp->next=n;

    }
}

void DLL::insertAfter(node *t,int data)
{
    node *n=new node;
    n->prev=t;
    n->item=data;
    n->next=t->next;
    if(t->next!=NULL)
    {
        t->next->prev=n;
    }
    t->next=n;

}

node* DLL::search(int data)
{
    node *t;
    t=start;
    while(t)
    {
        if(t->item==data)
           return t;
        t=t->next;
    }
    return NULL;
}

void DLL::deleteFirst()
{
    node *r;
    if(start!=NULL)
    {
        r=start;
        start=r->next;
        start->prev=NULL;
        delete r;
    }
}

void DLL::deleteLast()
{
    node *r;
    if(start==NULL)
    {
        cout<<endl<<"List Underflow";
    }
    else
    {
        if(start->next==NULL)
        {
            delete start;
            start=NULL;
        }
        else{
            r=start;
            while(r->next!=NULL)
                r=r->next;
            r->prev->next=NULL;
            delete r;
        }
    }
}

void DLL::deleteAfter(node *t)
{
    if(start==NULL)
       cout<<endl<<"LIST UNDERFLOW";
    else if(start==t)
       deleteFirst();
    else if(t->next==NULL)
       deleteLast();
    else{
        t->next->prev=t->prev;
        t->prev->next=t->next;
        delete t;
    }
}

void DLL::display()
{
    node *temp=start;
    cout<<endl<<"All elements of doubly linked list: ";
    while(temp)
    {
        cout<<temp->item<<"  ";
        temp=temp->next;
    }
}

DLL::~DLL()
{
    while(start)
        deleteFirst();
}


int main()
{
    DLL d;
    d.insertAtFirst(20);
    d.insertAtFirst(30);
    d.insertAtFirst(40);
    d.insertAtFirst(50);
    d.insertAtFirst(60);
    d.insertAtFirst(70);
    d.insertAtFirst(80);
    d.insertAtFirst(90);
    d.display();
    return 0;
}