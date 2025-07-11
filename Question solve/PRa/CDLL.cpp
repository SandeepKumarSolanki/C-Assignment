#include<iostream>
using namespace std;

struct node
{
    node *prev;
    int item;
    node *next;
};

class CDLL
{
    private:
        node *start;
    public:
        CDLL();
        CDLL(CDLL &);
        CDLL& operator=(CDLL &);
        void insertAtFirst(int);
        void insertAtLast(int);
        void insertAfter(node *,int);
        node* search(int);
        void deleteFirst();
        void deleteLast();
        void deleteAfter(node*);
        void display();
        ~CDLL();
};

CDLL::CDLL()
{
    start=NULL;
}

CDLL::CDLL(CDLL &c)
{
    node *temp;
    if(c.start==NULL)
       start=NULL;
    else
    {
        temp=c.start;
        do{
            insertAtLast(temp->item);
            temp=temp->next;
        }while(temp!=c.start);
    }
}

CDLL& CDLL::operator=(CDLL &c)
{
    while(start)
        deleteFirst();
    node *temp;
    if(c.start==NULL)
        start=NULL;
    else
    {
        temp=c.start;
        do{
            insertAtFirst(temp->item);
            temp=temp->next;
        }while(temp!=c.start);
    }
    return *this;
}

void CDLL::insertAtFirst(int data)
{
    node *n=new node;
    n->item=data;
    if(start==NULL)
    {
        n->prev=n;
        n->next=n;
        start=n;
    }
    else
    {
        n->prev=start->prev;
        n->next=start;
        start->prev->next=n;
        start->prev=n;
        start=n;
    }
}

void CDLL::insertAtLast(int data)
{
    node *n=new node;
    n->item=data;
    if(start==NULL)
    {
        n->prev=n;
        n->next=n;
        start=n;
    }
    else
    {
        n->prev=start->prev;
        n->next=start;
        start->prev->next=n;
        start->prev=n;
    }
}

void CDLL::insertAfter(node *temp,int data)
{
    node *n,*t;
    if(start==NULL || temp==NULL)
        cout<<"Insertion cannot be performed";
    else{
        n=new node;
        n->prev=temp;
        n->item=data;
        n->next=temp->next;
        temp->next->prev=n;
        temp->next=n;
    }
}

node* CDLL::search(int data)
{
    node *temp;
    if(start==NULL)
       return NULL;
    temp=start;
    do{
        if(temp->item==data)
           return temp;
        temp=temp->next;
    }while(temp!=start);
    return NULL;
}

void CDLL::deleteFirst()
{
    node *t;
    if(start!=NULL)
    {
        t=start;
        if(start->next==start)
        {
            delete start;
            start=NULL;
        }
        else
        {
            start->prev->next=start->next;
            start=start->next;
            start->prev=t->prev;
            delete t;
        }
    }

}
void CDLL::deleteLast()
{
    node *temp;
    if(start!=NULL)
    {
        if(start->next==start)
        {
            delete start;
            start=NULL;
        }
        else{
            temp=start->prev;
            temp->prev->next=start;
            start->prev=temp->prev;
            delete temp;
        }
    }
}

void CDLL::deleteAfter(node *temp)
{
    if(start==NULL || temp==NULL)
    {
        cout<<"Deletion cannot be performed";
    }
    else
    {
        if(start==temp){
            deleteFirst();
        }
        else
        {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            delete temp;
        }
    }
}

void CDLL::display()
{
    node *t;
    if(start==NULL)
        cout<<"List is empty";
    else
    {
        t=start;
        do{
            cout<<t->item<<" ";
            t=t->next;
        }while(t!=start);
    }
}

CDLL::~CDLL()
{
    while(start)
        deleteFirst();
}

int main()
{
    CDLL c;
    c.insertAtFirst(20);
    c.insertAtFirst(30);
    c.insertAtFirst(40);
    c.insertAtLast(55);
    c.deleteFirst();
    c.deleteLast();
    c.display();
    return 0;
}