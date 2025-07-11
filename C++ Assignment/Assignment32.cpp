#include<iostream>
#include<string>
using namespace std;
class Circle
{
   private:
   int radius;
   public:
   void setRadius(int r)
   {
    radius=r;
   }
   int getRadius()
   {
    return radius;
   }
   double getArea()
   {
    return 3.14*getRadius()*getRadius();
   }
   double getCircumference()
   {
    return 2*3.14*getRadius();
   }
};
class Date
{
   private:
   int d,m,y;
   public:
   void setDate(int a,int b,int c)
   {
    d=a;m=b;y=c;
   }
   void showDate()
   {
    cout<<endl<<d<<"/"<<m<<"/"<<y;
   }
   void showDateFormat1()
   {
    cout<<endl<<d<<"-"<<m<<"-"<<y;
   }
   void showDateFormat2()
   {
    char *months[]={"jan",
                  "feb",
                  "mar"
                  "apr",
                  "may",
                  "jun",
                  "jul",
                  "aug",
                  "sep",
                  "oct",
                  "nov",
                  "dec"
                  };
    cout<<endl<<d<<"-"<<months[m-1]<<"-"<<y;
   }
};
class Time
{
   private:
   int hr,min,sec;
   public:
   void setTime(int h,int m,int s)
   {
    hr=h;min=m;sec=s;
   }
   void showTime()
   {
    cout<<endl<<hr<<" hr "<<min<<" min "<<sec<<" sec";
   }
};
class Complex
{
   private:
   int a,b;
   public:
   void setData(int x,int y)
   {
    a=x; b=y;
   }
   void showData()
   {
    cout<<endl<<"a="<<a<<" b="<<b;
   }
};
int main()
{
    Date d;
    d.setDate(31,12,2022);
    d.showDate();
    /*Time t;
    t.setTime(3,45,20);
    t.showTime();
    Complex c1;
    c1.setData(4,5);
    c1.showData();*/
    return 0;
}