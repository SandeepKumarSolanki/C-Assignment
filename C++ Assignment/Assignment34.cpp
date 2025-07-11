#include<iostream>
#include<string>
using namespace std;
class Cuboid
{
    private:
       int length,bredth,height;
    public:
       Cuboid(int l,int b,int h)
       {
        length=l;bredth=b;height=h;
       }
};
class Customer
{
    private:
       int cust_id;
       string name,email,mobile;
    public:
       Customer(int i,string n,string e,string m)
       {
        cust_id=i;
        name=n;
        email=e;
        mobile=m;
       }
       Customer()
       {
        cust_id=1;
        name="Anuj Maddheshiya";
        email="anuj@xxxxgmail.com";
        mobile="9102xxxxxx";
       }
};
class Time
{
    private:
       int hr,min,sec;
    public:
       Time(int hr,int min,int sec)
       {
        this->hr=hr;
        this->min=min;
        this->sec=sec;
       }
};
class Book
{
    private:
       int bookid;
       string title;
       float price;
    public:
       Book()
       {
        bookid=23;
        title="C++ by Bjarne Strostrap";
        price=353.23;
       }
       Book(int b,string t,float p)
       {
        bookid=b;
        title=t;
        price=b;
       }
};
class Complex
{
    private:
       int a,b;
    public:
       Complex(int a,int b)
       {
        this->a=a;
        this->b=b;
       }
       void showData()
       {
        cout<<endl<<"a="<<a<<" b="<<b;
       }
};
class Number 
{
   private:
      int size,*arr;
   public:
      Number(int size)
      {
          this->size=size;
          arr=new int[size];
      }
      Number(Number &N)
      {
         size=N.size;
         arr=new int[size];
         for(int i=0;i<size;i++)
             arr[i]=N.arr[i];
      }
      ~Number()
      {
         delete []arr;
      }
};
class Student
{
   private:
     int rollno;
     string name;
   public:
     Student()
     {
      cout<<"Enter roll no : ";
      cin>>rollno;
      cout<<"Enter name : ";
      cin>>name;
     }
     void showDetails()
     {
      cout<<endl<<rollno<<"   "<<name;
     }
};

class Date
{
   private:
     int d,m,y;
   public:
     Date(int a,int b,int c):d(a),m(b),y(c)
     {}
};
class Room
{
   private:
     int roomno;
     string roomtype;
     bool is_AC;
     double price;
   public:
     Room(int r,string rt,bool ac,double p)
     {
      roomno=r;
      roomtype=rt;
      is_AC=ac;
      price=p;
     }
};
class Circle
{
   private:
     int radius;
   public:
     Circle(int r){radius=r;}
     Circle(){radius=10;}
};
/*
int main()
{
    Complex c[5]={Complex(4,5),Complex(3,4),Complex(6,5),Complex(6,4),Complex(34,34)};
    for(int i=0;i<5;i++)
        c[i].showData();
}
*/
int main()
{
   Student s;
   s.showDetails();
   return 0;
   
}