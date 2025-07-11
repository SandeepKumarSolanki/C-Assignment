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
      SLL(SLL &);
      SLL& operator=(SLL &);
      void insertAtFirst(int);
      void insertAtLast(int);
      void insertAfter(node*,int);
      node* search(int);
      void deleteFirst();
      void deleteLast();
      void deleteAfter(node*);
      void display();
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
    while(start)
       deleteFirst();
    
    while(t){
        insertAtLast(t->item);
        t=t->next;
    }
    return (*this);
}

void SLL::insertAtFirst(int data)
{
    node *n=new node;
    n->item=data;
    n->next=start;
    start=n;
   
}

void SLL::insertAtLast(int data)
{
    node *temp,*n=new node;
    n->item=data;
    n->next=NULL;
    if(start==NULL)
    {
        start=n;
    }
    else
    {
        temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
    }
}

void SLL::insertAfter(node *t,int data)
{
    node *n;
    if(t)
    {
        n=new node;
        n->item=data;
        n->next=t->next;
        t->next=n;
    }
}

node* SLL::search(int data)
{
    node *temp;
    
    temp=start;
    while(temp)
    {
        if(temp->item==data)
        {
            return temp;
        }
        temp=temp->next;
    }
        
    return NULL;
}

void SLL::deleteFirst()
{
    node *temp;
    if(start==NULL)
    {
        delete start;
        start=NULL;
    }
    else
    {
        temp=start;
        start=temp->next;
        delete temp;
    }
}

void SLL::deleteLast()
{
    node *temp;
    try{
        if(start==NULL)
          throw 1;
        if(start->next==NULL)
        {
            delete start;
            start=NULL;
        }
        else{
            temp=start;
            while(temp->next->next!=NULL)
                 temp=temp->next;
            delete temp->next;
            temp->next=NULL;
        }
    }
    catch(int e)
    {
        if(e==1)
          cout<<"Deletion not performed list is empty";
    }
}

void SLL::deleteAfter(node *t)
{
    node  *r;
    try{
        if(start==NULL)
          throw 1;
        if(start==t)
        {
            deleteFirst();
        }
        else
        {
            r=start;
            while(r->next!=t)
                r=r->next;
            r->next=t->next;
            delete t;
        }
    }
    catch(int e)
    {
        if(e==1)
           cout<<endl<<"Deletion not performed list is empty.";
    }
}

void SLL::display()
{
    node *t;
    t=start;
    cout<<endl<<"All elements of linked list"<<endl;
    while(t)
    {
        cout<<t->item<<" ";
        t=t->next;
    }
}
SLL::~SLL()
{
    while(start)
       deleteFirst();
}


int main()
{
    SLL s;
    s.insertAtFirst(1);
    s.insertAtFirst(2);
    s.insertAtFirst(3);
    s.insertAtFirst(4);
    s.insertAtFirst(5);
    s.insertAtFirst(6);
    s.display();
    //s.insertAfter();
    return 0;
}