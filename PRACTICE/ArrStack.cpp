#include<iostream>
using namespace std;

class Array 
{
    private:
        int capacity;
        int top;
        int *ptr;
    public:
        Array();
        void createArray(int);
        void push(int);
        bool isFull();
        bool isEmpty();
        void pop();
        int peek();


};

Array::Array()
{
    ptr=NULL;
}

void Array::createArray(int cap)
{
    if(ptr!=NULL)
        delete []ptr;
    capacity=cap;
    top=-1;
    ptr=new int[cap];
}

bool Array::isFull()
{
    return top==capacity-1;
}

bool Array::isEmpty()
{
    return top==-1;
}

void Array::push(int data)
{
    if(isFull())
        cout<<"Stack Overflow";
    {
        top++;
        ptr[top]=data;
    }
}

void Array::pop()
{
    if(isEmpty())
    {
        cout<<"Deletion not perfomed stack is empty";
    }
    else
    {
        top--;
    }
}

int Array::peek()
{
    if(top!=-1)
        return  ptr[top] ;
    else
        return NULL;
}

Array::~Array()
{
    if(ptr!=NULL)
        delete []ptr;
}

int main()
{
    Array a;
    return 0;
}