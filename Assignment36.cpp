#include<iostream>
using namespace std;

class Complex
{
    private:
      int a,b;
    public:
      void setData(int a,int b)
      {
        this->a=a;
        this->b=b;
      }
      void showData()
      {
        cout<<endl<<"a="<<a<<" b="<<b;
      }
      friend Complex operator+(Complex,Complex);
      friend Complex operator-(Complex,Complex);
      friend Complex operator*(Complex,Complex);
      friend Complex operator-(Complex);
};
Complex operator+(Complex X,Complex Y)
{
  Complex temp;
  temp.a=X.a+Y.a;
  temp.b=X.b+Y.b;
  return temp;
}

Complex operator-(Complex X,Complex Y)
{
  Complex temp;
  temp.a=X.a+Y.a;
  temp.b=X.b+Y.b;
  return temp;
}

Complex operator*(Complex X,Complex Y)
{
  Complex temp;
  temp.a=X.a*Y.a-X.b*Y.b;
  temp.b=X.a*X.b+Y.b*Y.a;
  return temp;
}

Complex operator-(Complex X)
{
  Complex temp;
  temp.a=-X.a;
  temp.b=-X.b;
  return temp;
}
/*
int main()
{
  Complex c1,c2,c3;
  c1.setData(5,6);
  c2.setData(74,32);
  c3=c1+c2;
  c3.showData();
  return 0;
}
*/

/*
class Time
{
  private:
    int hr,min,sec;
  public:
    friend istream& operator>>(istream& ,Time&);
    friend ostream& operator<<(ostream&,Time);
    Time operator=(Time);
};

ostream& operator<<(ostream &dout,Time d)
{ 
  
  dout<<endl<<d.hr<<":"<<d.min<<":"<<d.sec;
  return dout;
}

istream& operator>>(istream &din,Time &d)
{
  din>>d.hr>>d.min>>d.sec;
  return din;
}

Time Time::operator=(Time t)
{
  hr=t.hr;
  min=t.min;
  sec=t.sec;
  return *this;
}
int main()
{
  Time t1;
  cout<<"Enter time ";
  cin>>t1;
  cout<<t1;
  return 0;
}
*/

/*
class Array
{
  private:
    int *p,size;
  public:
    Array(int n)
    {
      size=n;
      p=new int[n];
    }
    Array(Array &A)
    {
      size=A.size;
      p=new int[size];
      for(int i=0;i<size;i++)
          p[i]=A.p[i];
    } 
    ~Array()
    {
      delete []p;
    }
    int& operator[](int index)
    {
      if(index>=size)
      {
        cout<<"Array index out of bound";
        throw 1;
      }
      return p[index];
    }
    friend Array operator+(Array,Array);
};
Array operator+(Array A,Array B)
{
  Array temp(A.size+B.size);
  int i,j,k;
  for(i=0,j=0,k=0;i<temp.size;i++)
  {
    if(j<A.size)
    {
      temp[i]=A[j];
      j++;
    }
    else
    {
      temp[i]=B[k];
      k++;
    }
  } 
  return temp;
}
*/

class Integer
{
  private:
    int num;
  public:
    friend bool operator!(Integer);
    friend bool operator==(Integer,Integer);
};
bool operator!(Integer i)
{
  if(i.num!=0)
    return false;
  else
    return true;
}
bool operator==(Integer X,Integer Y)
{
   return X.num==Y.num;
}

class Coordinate
{
  private:
    int x,y;
  public:
    Coordinate(int x,int y):x(x),y(y)
    {  }
    void setData(int x,int y)
    {
      this->x=x;
      this->y=y;
    }
    void showData()
    {
      cout<<endl<<"("<<x<<","<<y<<")";
    }
    Coordinate operator,(Coordinate);
    friend ostream& operator<<(ostream&,Coordinate);
    friend istream& operator>>(istream&,Coordinate&);
};
Coordinate Coordinate::operator,(Coordinate X)
{
  Coordinate temp(0,0);
  temp.x=X.x;
  temp.y=X.y;
  return temp;
}

ostream& operator<<(ostream &dout,Coordinate d)
{
  dout<<endl<<"("<<d.x<<","<<d.y<<")";
  return dout;
}

istream& operator>>(istream &din,Coordinate &d)
{
  din>>d.x>>d.y;
  return din;
}


class Student
{
  private:
    int rollno;
    string name;
    int age;
  public:
    void setStudent(int r,string s,int a)
    {
      rollno=r;
      name=s;
      age=a;
    }
    void showStudent()
    {
      cout<<endl<<rollno<<" "<<name<<" "<<age;
    }
    bool operator==(Student);
};
bool Student::operator==(Student s)
{
  if(rollno==s.rollno || name==s.name || age==s.age)
      return true;
  else
     return false;

}