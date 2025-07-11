#include<iostream>
using namespace std;
#define EMPTY_LIST -1;

struct node
{
    int item;
    node *next;
};

class CLL
{
    private:
        node *last;
    public:
        CLL();
        CLL(CLL&);
        CLL& operator=(CLL&);
        void insertAtFirst(int);
        void insertAtLast(int);
        void insertAfter(node*,int);
        node* search(int);
        void deleteFirst();
        void deleteLast();
        void deleteAfterNode(node*);
        void deleteAfter(int);
        void display();
        ~CLL();
};

CLL::CLL()
{
    last=NULL;
}

CLL::CLL(CLL &c)
{
   node *temp;
   if(c.last==NULL)
    last=NULL;
   else{
    temp=c.last->next;
    while(temp!=c.last)
    insertAtLast(temp->item);
    temp=temp->next;
   }
   insertAtLast(temp->item);
}

CLL& CLL::operator=(CLL &c)
{
    while(last)
        deleteFirst();
    node *temp;
    if(c.last==NULL)
        last=NULL;
    else
    {
        temp=c.last->next;
        while(temp!=c.last){
            insertAtLast(temp->item);
            temp=temp->next;
        }
        insertAtLast(temp->item);
    }
    return *this;
}

void CLL::insertAtFirst(int data)
{
    node *n=new node;
    n->item=data;
    if(last==NULL)
    {
        n->next=last;
        last=n;
    }
    else{
        n->next=last->next;
        last->next=n;
    }
}

void CLL::insertAtLast(int data)
{
    node *n=new node;
    n->item=data;
    if(last==NULL)
    {
        n->next=n;
        last=n;
    }
    else
    {
        n->next=last->next;
        last->next=n;
        last=n;
    }
}

node* CLL::search(int data)
{
    node *temp;
    if(last==NULL)
        return NULL;
    temp=last->next;
    while(temp!=last){
        if(temp->item==data){
            return temp;
        }
         temp=temp->next;
    }
    if(last->item==data)
        return last;
    return NULL;
}

void CLL::insertAfter(node *t,int data)
{
    node *n;
    if(t==last)
        insertAtLast(data);
    else if(t){
        n=new node;
        n->item=data;
        n->next=t->next;
        t->next=n;
    }
}
void CLL::deleteFirst()
{
    node *temp;
    if(last){
        temp=last->next;
        last->next=temp->next;
        if(last==temp)
            last=NULL;
        delete temp;
    }
}

void CLL::deleteLast()
{
    node *temp,*r;
    temp=last->next;
    if(last){
        r=last;
        if(r->next==r)
            last=NULL;
        
        else
        {
            while(temp->next!=last){
                temp=temp->next;
            }
            temp->next=last->next;
            last=temp;
        }
        delete r;
    }
}

void CLL::deleteAfterNode(node *t)
{
    node *r;
    if(t!=NULL){
        if(t==last)
            deleteLast();
        else if(t==last->next)
            deleteFirst();
        else{
            r=last->next;
            while(r->next!=t)
                r=r->next;
            r->next=t->next;
            delete t;
        }
    }
}

// void CLL::deleteAfter(int data)
// {
//     node *temp;
//     if(last==NULL){
//         cout<<"list is empty deletion not performed";
//     }
//     else{
//         temp=last->next;
//         while(temp==last){
//             if(temp->item==data)
//             {
//                 temp->next=
//             }
//         }
//     }
// }

void CLL::display()
{
    node *temp;
    if(last->next==NULL)
        cout<<"List is empty";
    else
    {
        temp=last->next;
        do{
            cout<<temp->item<<" ";
            temp=temp->next;
        }while(temp!=last->next);
        cout<<last->next;
    }
    
}

CLL::~CLL()
{
    while(last)
        deleteFirst();
}

int main()
{
    CLL c;
    c.insertAtFirst(20);
    c.insertAtFirst(39);
    c.insertAtFirst(67);
    c.display();
    return 0;

}