#include<iostream>
using namespace std;

class DynamicArray
{
    private:
       int capacity;
       int lastIndex;
       int *ptr;
    protected:
       void doubleArray();
       void halfArray();
    public:
       DynamicArray(int);
       DynamicArray(DynamicArray&);
       DynamicArray& operator=(DynamicArray&);
       bool isFull();
       bool isEmpty();
       int getCapacity();
       void append(int);
       void insert(int,int);
       void edit(int,int);
       void del(int);
       int getElement(int);
       int count();
       ~DynamicArray();
       int findElement(int);


};

DynamicArray::DynamicArray(int c)
{
    capacity=c;
    lastIndex=-1;
    if(ptr!=NULL)
       delete ptr;
    ptr=new int[capacity];

}

DynamicArray::DynamicArray(DynamicArray &arr)
{
    capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    ptr=new int[capacity];
    for(int i=0;i<=lastIndex;i++)
      ptr[i]=arr.ptr[i];
    
}

DynamicArray& DynamicArray::operator=(DynamicArray &arr)
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

void DynamicArray::doubleArray()
{
   int *temp=new int[capacity*2];
   for(int i=0 ; i<=lastIndex ; i++)
       temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
    capacity*=2;
   
}

void DynamicArray::halfArray()
{
    int *temp;
    temp=new int[capacity/2];
    for(int i=0;i<=lastIndex;i++)
        temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
    capacity /=2;
}
bool DynamicArray::isFull()
{
    return lastIndex==capacity-1;
}

bool DynamicArray::isEmpty()
{
    return lastIndex==-1;
}


void DynamicArray::append(int data)
{
    if(isFull())
        doubleArray();
    lastIndex++;
    ptr[lastIndex]=data;
}

void DynamicArray::insert(int index,int data)
{
    try{
        if(index<0 || index>lastIndex+1)
          throw 1;
        if(isFull())
           doubleArray();
        for(int i=lastIndex ; i>=index ; i++)
            ptr[i+1]=ptr[i];
        ptr[index]=data;
        lastIndex++;
    } 
    catch(int e){
        if(e==1)
          cout<<"Invalid Index";
    }
}

void DynamicArray::edit(int index,int newdata)
{
    try{
        if(index<0 || index > lastIndex+1)
          throw 1;
        ptr[index]=newdata;
    }
    catch(int e){
        if(e==1)
          cout<<"Invalid index";
    }
}

void DynamicArray::del(int index)
{
    try{
        if(isEmpty())
           throw 1;
        if(index<0 || index > lastIndex+1)
           throw 2;
        for(int i=index;i<=lastIndex ; i++)
            ptr[i]=ptr[i+1];
        lastIndex--;
    }
    catch(int e){
        if(e==1)
          cout<<"Underflow";
        if(e==2)
          cout<<"Invalid Index";
    }
}

int DynamicArray::count()
{
    return lastIndex+1;
}

int DynamicArray::getElement(int index)
{
    try{
        if(index<0 || index > lastIndex+1)
          throw 1;
        if(isEmpty())
          throw 2;
        return ptr[index];
    }
    catch(int e){
        if(e==1){
            cout<<"Invalid index";
        }
        if(e==2){
            cout<<"Array Underflow";
        }
    }
    return -1;
}

int DynamicArray::getCapacity()
{
    return capacity;
}

int DynamicArray::findElement(int data)
{
    for(int i=0 ; i < lastIndex+1 ; i++)
        if(data == ptr[i])
           return i;
        
    return -1;
}
DynamicArray::~DynamicArray()
{
    delete []ptr;
}

int main()
{
    DynamicArray a(2);
    a.append(5);
    a.append(3);
    cout<<a.getElement(1);
}