#include<iostream>
using namespace std;

class  Array{
   private:
     int capacity;
     int lastIndex;
     int *ptr;
    public:
     Array();
     Array(Array&);
     Array& operator=(Array&);
     void createArray(int);
     void append(int);
     void insert(int,int);
     int getItem(int);
     bool isEmpty();
     bool isFull();
     int getCapacity();
     int count();
     void del(int data);
     void edit(int,int);
     void search(int);
     ~Array();
} ;

Array::Array()
{
    ptr=NULL;
}

Array::Array(Array &arr)
{
    capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    ptr=new int[capacity];
    for(int i=0 ; i<=lastIndex ; i++)
       ptr[i]=arr.ptr[i];
}

bool Array::isEmpty()
{
    return lastIndex==-1;
}

bool Array::isFull()
{
    return lastIndex==capacity-1;
}

Array& Array::operator=(Array &arr)
{
    capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    if(ptr!=NULL)
      delete ptr;
    ptr=new int[capacity];
    for(int i=0 ; i<=lastIndex ; i++)
    {
        ptr[i]=arr.ptr[i];
    }
    return (*this);
}

void Array::createArray(int c){
    capacity=c;
    lastIndex=-1;
    if(ptr!=NULL)
      delete ptr;
    ptr=new int[capacity];
}

void Array::append(int data)
{
    if(!isFull())
    {
      lastIndex++;
      ptr[lastIndex]=data;
    }
    else
    {
        cout<<"Array Overflow";
    }
}

void Array::insert(int index,int newdata)
{
    try{
        if(index<0  || index > lastIndex+1)
           throw 1;
        if(isFull())
           throw 2;
        for(int i=lastIndex ; i>=index ; i--){
            ptr[i+1]=ptr[i];
        ptr[index]=newdata;
        lastIndex++;
        }
    } 
    catch(int e){
        if(e==1)
          cout<<"Invalid index";
        if(e==2)
          cout<<"Overflow";
    }
}

int Array::getItem(int index)
{
    try{
        if(index<0 || index > lastIndex)
          throw 1;
        return ptr[index];
    }
    catch(int e){
        if(e==1)
          cout<<"\nInvalid index or Array is Empty";
    }
    return -1;
}

int Array::getCapacity()
{
    return capacity;
}

int Array::count()
{
    return lastIndex+1;
}

void Array::edit(int index,int newdata)
{
    try{
        if(index>0|| index>lastIndex)
          throw 1;
        ptr[index]=newdata;
    }
    catch(int e){
        if(e==1)
          cout<<"Invalid index ";
    }
}
void Array::del(int index)
{
    try{
        if(index<0 || index > lastIndex)
          throw 1;
        if (isEmpty())
          throw 2;
        for(int i=index;i<lastIndex ; i++)
        {
            ptr[i]=ptr[i+1];

        }
        lastIndex--;
    }
    catch(int e){
        if(e==1)
          cout<<"Invalid index";
        if(e==2)
           cout<<"Array is Empty";
    }
}

Array::~Array()
{
    delete []ptr;
}

int main()
{
    Array a;
    a.createArray(4);
    a.append(5);
    a.append(66);
    a.append(63);
    
    

    cout<<a.count();
}