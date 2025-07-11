#include<iostream>
#define EMPTY_STACK -1
using namespace std;

struct node
{
    int item;
    node *next;
};

class STACK
{
    private:
        node *top;
    public:
        STACK();
        STACK(STACK &);
        STACK& operator=(STACK &);
        void push(int);
        void pop();
        int peek();
        void reverse();
        
        ~STACK();
};

STACK::STACK()
{
    top=NULL;
}

STACK::STACK(STACK &s)
{
    node *t;
    s.reverse();
    t=s.top;
    while(t){
        push(t->item);
        t=t->next;
    }
    s.reverse();
    
}

STACK& STACK::operator=(STACK &s)
{
    if(top!=NULL){
        while(top)
            pop();
    }
    node *t;
    s.reverse();
    t=s.top;
    while(t){
        push(t->item);
        t=t->next;
    }
    s.reverse();
    return *this;
}

void STACK::push(int data)
{
    node *n;
    new node;
    n->item=data;
    n->next=top;
    top=n;
}

int STACK::peek()
{
    if(top==NULL)
        throw EMPTY_STACK;
    return top->item;
}

void STACK::pop()
{
    node *t;
    if(top){
        t=top;
        top=t->next;
        delete t;
    }
}

void STACK::reverse()
{
    STACK s1;
    while(top)
    {
        s1.push(peek());
        pop();
    }
    top=s1.top;
    s1.top=NULL;
}


STACK::~STACK()
{
    while(top)
        pop();
}

int main()
{
    STACK s1;
    s1.push(19);
    cout<<endl<<s1.peek()<<endl;
    s1.push(56);
    cout<<endl<<s1.peek()<<endl;
    s1.push(20);
    cout<<endl;
    cout<<endl<<s1.peek();
    return 0;
}