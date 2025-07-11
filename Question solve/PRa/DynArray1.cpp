#include<iostream>
using namespace std;

class DArray
{
    private:
       int capacity;
       int lastIndex;
       int *ptr;
    protected:
       void halfArray();
       void DoubleArray();
    public:
       DArray();
       DArray(DArray &);
       DArray& operator=(DArray &);
       
       void createArray(int );
       void append(int);
       void insert(int,int);
       int getItem(int);
       bool isFull();
       bool isEmpty();
       void del(int);
       void edit(int,int);
       int getCapacity();
       int count();
       void display();
       ~DArray();
};

DArray::DArray()
{
    ptr=NULL;
}

DArray::DArray(DArray &arr)
{
    capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    ptr=new int[capacity];
    for(int i=0 ; i <= lastIndex;i++)
       ptr[i]=arr.ptr[i];
}

DArray& DArray::operator=(DArray &arr)
{
   capacity=arr.capacity;
   lastIndex=arr.lastIndex;
   if(ptr!=NULL)
     delete []ptr;
   ptr=new int[capacity];
   for(int i=0;i<=lastIndex;i++)
      ptr[i]=arr.ptr[i];
   return (*this);
}


void DArray::createArray(int cap)
{
    capacity=cap;
    lastIndex=-1;
    if(ptr!=NULL)
       delete []ptr;
    ptr = new int[capacity];
}

bool DArray::isFull()
{
    return lastIndex==capacity-1;
}

bool DArray::isEmpty()
{
    return lastIndex==-1;
}

void DArray::append(int data)
{
    if(!isFull())
    {
        lastIndex++;
        ptr[lastIndex]=data;
    }
    else
      cout<<"List is full";
}

void DArray::insert(int index,int data)
{ 
    int i;
    try
    {
        if(index<0 || index>lastIndex+1)
          throw 1;
        if(isFull())
           DoubleArray();
        for(i=lastIndex;i>=index;i--)
            ptr[i+1]=ptr[i];
        ptr[index]=data;
        lastIndex++;
    }
    
    catch(int e)
    {
        if(e==1)
          cout<<"Invalid index";
    }
    
}

void DArray::edit(int index,int newData)
{
    try{
        if(index < 0 || index>lastIndex)
          throw 1;
        ptr[index]=newData;
        lastIndex++;
    }
    catch(int e)
    {
        if(e==1)
          cout<<"Invalid index";
    }
}

int DArray::getItem(int index)
{
    try{
        if(index<0 || index>lastIndex)
          throw 1;
        return ptr[index];
    }
    catch(int e)
    {
        if(e==1)
          cout<<"Invalid index or array is empty";
    }
}

void DArray::del(int index)
{
    try{
        if(index<0 || index>lastIndex)
          throw 1;
        for(int i=index;i>=lastIndex;i++)
           ptr[i]=ptr[i+1];
        lastIndex--;
        if(capacity>1 && lastIndex+1 <= capacity/2)
           halfArray();
    }
    catch(int e)
    {
        if(e==1)
          cout<<"Invalid index";
    }
}

int DArray::getCapacity()
{
    return capacity;
}

int DArray::count()
{
    return lastIndex+1;
}

void DArray::display()
{
    for(int i=0;i<=lastIndex ; i++)
       cout<<ptr[i]<<"  ";
    cout<<endl;
}
void DArray::halfArray()
{
    int *temp;
    temp=new int[capacity/2];
    for(int i=0 ; i <= lastIndex ; i++)
       temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
    capacity /= 2;
}

void DArray::DoubleArray()
{
    int *temp;
    temp=new int[capacity*2];
    for(int i=0 ; i<= lastIndex ; i++)
       temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
    capacity *= 2;
}
DArray::~DArray()
{
    delete []ptr;
}

// int main()
// {
//     DArray arr;
//     arr.createArray(5);
//     arr.append(5);
//     arr.append(5);
//     arr.append(5);
//     arr.display();
//     return 0;
// }