#include<iostream>
using namespace std;

class Array
{
   private:
      int capacity;
      int lastIndex;
      int *ptr;
    public:
      Array();
      Array(Array &);
      Array& operator=(Array&);
      void createArray(int);
      void insert(int,int);
      void append(int);
      int getItem(int);
      bool isFull();
      bool isEmpty();
      void del(int);
      void edit(int,int);
      int count();
      int getCapacity();
      void display();
      ~Array();


};

Array::Array()
{
    ptr=NULL;
}

Array::Array(Array &arr)
{
   capacity=arr.capacity;
   lastIndex=arr.lastIndex;
//    if(ptr!=NULL)
//       delete []ptr;
   ptr=new int[capacity];
   for(int i=0;i<=lastIndex;i++)
       ptr[i]=arr.ptr[i];
}

Array& Array::operator=(Array &arr)
{
   
    capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    if(ptr!=NULL)
     delete []ptr;
    ptr = new int[capacity];
    for(int i=0;i<=lastIndex;i++)
        ptr[i]=arr.ptr[i];
    return (*this);
}
void Array::createArray(int size)
{
    capacity=size;
    lastIndex=-1;
    if(ptr!=NULL)
       delete []ptr;
    ptr = new int[capacity];
}

void Array::insert(int index,int data)
{
    int i;
    try
    {
        if(index < 0 || index > lastIndex+1)
           throw 1;
        if(isFull())
           throw 2;
        for(i=lastIndex ; i >= index ; i--)
        {
            ptr[i+1]=ptr[i];
        }
        ptr[index]=data;
        lastIndex++;
    }
    catch(int e)
    {
        if(e==1)
          cout<<"Invalid index";
        if(e==2)
          cout<<"Array is Full";
    }
    
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
        cout<<"Array is Full";
    }
}

int Array::getItem(int index)
{
    int i;
    try
    {
        if(index < 0 || index >lastIndex)
          throw 1;
        
        return ptr[index];
    }
    catch(int e)
    {
        if(e==1)
          cout<<"Invalid index or list Underflow";
    }
    return -1;
    
}

bool Array::isFull()
{
    return (lastIndex==capacity-1);
}

bool Array::isEmpty()
{
    return lastIndex==-1;
}

void Array::del(int index)
{
    int i;
    try
    {
        if(index<0||index>lastIndex)
          throw 1;
      
        for(i=index;i<lastIndex;i++)
           ptr[i]=ptr[i+1];
        lastIndex--;
    }
    catch(int e)
    {
        if(e==1)
        cout << "Invalid index";
      
        
    }
    
}

void Array::edit(int index,int newData)
{
    try{
        if(index<0||index>lastIndex)
      throw 1;
    ptr[index]=newData;
    }
    catch(int e)
    {
        if(e==1)
        cout<<"Invalid index";
    }
}

int Array::getCapacity()
{
    return capacity;
}

int Array::count()
{
    return lastIndex+1;
}

void Array::display()
{
    for(int i=0;i<lastIndex+1;i++)
    cout<<ptr[i]<<" ";
}
Array::~Array()
{
    delete []ptr;
}


int main()
{
    Array arr;
    arr.createArray(5);
    arr.append(100);
    arr.append(120);
    arr.append(200);
    arr.append(245);
    arr.append(369);
    arr.append(34);
    arr.display();
    return 0;
}