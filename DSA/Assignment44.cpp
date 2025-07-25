#include<iostream>
using namespace std;

struct node{
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
     DLL(DLL&);
     DLL& operator=(DLL&);
     void insertAtFirst(int);
     void insertAtLast(int);
     node* searchNode(int);
     void insertAfter(node*,int);
     void deleteFirst();
     void deleteLast();
     void deleteAfter(node*);
     ~DLL();
};

DLL::DLL()
{
    start=NULL;
}

DLL::DLL(DLL &d)
{
   node *t;
   if(d.start!=NULL)
   {
    t=d.start;
    while(t->next!=NULL)
        t=t->next;
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

DLL& DLL::operator=(DLL &d)
{
    while(start)
       deleteFirst();
    node *t;
    if(d.start!=NULL)
    {
        t=d.start;
        while(t->next!=NULL)
        {
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
    node *t,*n=new node;
    n->item=data;
    n->next=NULL;
    if(start!=NULL)
    {
        t=start;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        n->prev=t;
        t->next=n;
    }
    else
    {
        n->prev=NULL;
        start=n;
    }
}

node* DLL::searchNode(int data)
{
    node *t;
    t=start;
    while(t){
        if(t->item==data)
           return t;
        t=t->next;
    }
    return NULL;
}

void DLL::insertAfter(node *t,int data)
{
    node *n=new node;
    n->prev=t;
    n->item=data;
    n->next=t->next;
    if(t->next!=NULL)
       t->next->prev=n;
    t->next=n;
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
     node *t;
     if(start==NULL)
     {
        cout<<"List Underflow";
     }
     else
     {
        if(start->next==NULL)
        {
            delete start;
            start=NULL;
        }
        else{
            t=start;
            while(t->next!=NULL)
            {
                t=t->next;
            }
            t->prev->next=NULL;
            delete t;
        }
     }
}

void DLL::deleteAfter(node *t)
{
   if(start==NULL)
      cout<<"List is Underflow";
   else if(start==t)
      deleteFirst();
   else if(t->next==NULL)
      deleteLast();
   else{
    t->next->prev=t->prev->next;
    t->prev->next=t->next;
    delete t;
   }
}
DLL::~DLL()
{
    while(start)
       deleteFirst();
}
int main()
{
    return 0;
}