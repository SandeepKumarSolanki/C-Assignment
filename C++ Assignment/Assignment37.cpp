#include<iostream>
#include<string.h>
using namespace std;
class Person
{
    private:
      string name;
      int age;
    public:
      Person(string n,int a):name(n),age(a)
      {}

};
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
};

void f1()
{
    Complex *cptr=new Complex;
    cptr->setData(5,6);
    cptr->showData();
}

class Time
{
    private:
      int hr,min,sec;
    public:
      void setTime(int hr,int min,int sec)
      {
        this->hr=hr;
        this->min=min;
        this->sec=sec;
      }
      void showTime()
      {
        cout<<endl<<hr<<":"<<min<<":"<<sec;
      }
      void sethour(int hr)
      {
        this->hr=hr;
      }
      void setmin(int min)
      {
        this->min=min;
      }
      void setsec(int sec)
      {
        this->sec=sec;
      }
      int gethr()
      {
        return hr;
      }
      int getmin()
      {
        return min;
      }
      int getsec()
      {
        return  sec;
      }
      bool operator<(Time);
};
Time* createArrayTime(int size)
{
    return new Time[size];
}
bool Time::operator<(Time t)
{
    if(hr<t.hr)
      return true;
    else if(hr>t.hr)
      return false;
    else if(min<t.min)
      return true;
    else if(min>t.min)
      return false;
    else if(sec<t.sec)
      return true;
    else 
      return false;
}

void sort(Time t[],int size)
{
    Time temp;
    for(int r=1;r<size;r++)
    {
        for(int i=0;i<size-r;r++)
        {
            if(t[i]<t[i+1])
            {
                temp=t[i];
                t[i]<t[i+1];
                t[i+1]=temp;
            }
        }
    }
}

void printTimeArray(Time t[],int size)
{
    for(int i=0;i<size;i++)
        t[i].showTime();
}


class String
{
    private:
       char *s;
       int length;
    protected:
       int len(char str[])
       {
        int l;
        for(l=0;str[l];l++);
        return l;
       }

       char* inputString()
       {
        char ch,*p=NULL,*q=NULL;
        int i,size=1;
        cout<<"Enter text: ";
        p=new char[size];
        p[0]='\0';
        while(1)
        {
            ch=getchar();
            if(ch=='\n')
               break;
            q=new char[size+1];
            for(i=0;i<size;i++)
               q[i]=p[i];
            q[i-1]=ch;
            q[i]='\0';
            delete p;
            size++;
            p=new char[size];
            strcpy(p,q);
            delete q;
        }
        return p;
       } 
    public:
       String(){s=NULL;length=0;}
       void setString()
       {
        if(s!=NULL)
        {
            delete []s;
            length=0;
        }
        s=inputString();
        length=len(s);
       }
       void setString(char arr[])
       {
        if(s!=NULL)
           {
            delete []s;
            length=0;
           }
           strcpy(s,arr);
           length=len(arr);
       }
       void UPPER()
       {
        for(int i=0;i<length;i++)
        {
            if(s[i]>='a' && s[i]<='z')
               s[i]-=32;
        }
       }
       void lower()
       {
        for(int i=0;i<length;i++)
        {
            if(s[i]>='A' && s[i]<='Z')
                s[i]+=32;
        }
       }
       ~String()
       {
        delete []s;
        length=0;
       }
       int stringLength() { return length;}
       void printString() { cout<<s;}
       char* getString()  { return s; }

};