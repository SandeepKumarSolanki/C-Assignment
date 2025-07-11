#include<iostream>
using namespace std;

struct node
{
    int item;
    node *next;
};

class SLL
{
    private:
       node *start;
    public:
       SLL();
       SLL(SLL&);
       SLL& operator=(SLL&);
       void insertAtFirst(int);
       void insertAtLast(int);
       node* search(int);
       void insertAfter(node*,int);
       void deleteFirst();
       void deleteLast();
       void deleteAfter(node*);
       ~SLL();
};

SLL::SLL()
{ 
    start=NULL;
}

SLL::SLL(SLL &list)
{
    node *t;
    t=list.start;
    start=NULL;
    while(t){
         insertAtLast(t->item);
         t=t->next;
    }

}

SLL& SLL::operator=(SLL &list)
{
    node *t;
    t=list.start;
    while(start){
        deleteFirst();
        t=t->next;
    }

    while(t){
        insertAtLast(t->item);
        t=t->next;
    }
    return *this;
}

void SLL::insertAtFirst(int data)
{
    node *n=new node;
    n->item=data;
    if(start!=NULL)
    {
        n->next=start;
        start=n;
    }
    else
    {
        n->next=NULL;
        start=n;
    }
}

void SLL::insertAtLast(int data)
{
    node *temp,*n=new node;
    n->item=data;
    n->next=NULL;
    if(start!=NULL)
    {
        temp=start;
        while(temp->next!=NULL)
              temp=temp->next;
        temp->next=n;
    }
    else
    {
        start=n;
    }
}

node* SLL::search(int data)
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

void SLL::insertAfter(node *t,int data)
{
   node *n;
   if(t){
    n=new node;
    n->item=data;
    n->next=t->next;
    t->next=n;
   }
}

void SLL::deleteFirst()
{
    node *t;
    if(start==NULL)
    {
        delete start;
        start=NULL;
    }
    else
    {
        t=start;
        start=t->next;
        delete t;
    }
}

void SLL::deleteLast()
{
    node *t;
    try{
        if(start==NULL)
          throw 1;
        if(start->next==NULL)
        {
            delete start;
            start=NULL;
        }
        else
        {
            t=start;
            while(t->next->next!=NULL)
                  t=t->next;
            delete t->next;
            t->next=NULL;
        }
    }
    catch(int e){
        if(e==1){
            cout<<"List is Empty";
        }
    }
}

void SLL::deleteAfter(node *t)
{
    node *r;
    try{
        if(start==NULL)
          throw 1;
        if(start==t)
          deleteFirst();
        else
        {
            r=start;
            while(r->next!=t)
                r=r->next;
            r->next=t->next;
            delete t;
        }
    }
    catch(int e){
        if(e==1){
            cout<<"List is empty";
        }
    }
}

SLL::~SLL()
{
    while(start)
       deleteFirst();
}

int main()
{ 
    node n;
    SLL s1;
    s1.insertAtFirst(5);
    s1.insertAtFirst(39);
    return 0;
}