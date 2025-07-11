#include<iostream>
#include<math.h>
using namespace std;
bool prime(int n)
{
    for(int i=2; i<n ; i++)
        if(n%i==0)
           return false;
    return true;
}
int digit(int n)
{
    int count=0;
    while(n)
    {
       n/=10;
       count++;
    }
    return count;
}
int power(int x,int y)
{
    for(int i=0; i<y; i++)
    {
        x*=i;
    }
    return x;
}
int fact(int n)
{
    if(n==0||n==1)
       return 1;
    return n*fact(n-1);
       
}
int  combi(int n,int r)
{
    return fact(n)/fact(n-r)/fact(r);
}
void printPascal(int lines)
{
    int i,j,c,n,flag,r;
    for(i=1;i<=lines;i++)
    {
        flag=1;
        n=i-1;
        r=0;
        for(j=1;j<=2*lines-1;j++)
        {
            if(j>=lines+1-i && j<=lines-1+i)
            {
                if(flag)
                  cout<<combi(n,r++);
                else
                  cout<<" ";
                flag=1-flag;
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<endl;
    }
}
/*
int main()
{
    printPascal(10);
}*/
bool isInFib(int num)
{
   int a=-1,b=1,c=0;
   while(c<num)
   {
    c=a+b;
    if(num==c)
       return true;
    a=b;
    b=c;
   }
   return false;
}
void swap(int &x,int &y)
{
    x=x+y;
    y=x-y;
    x=x-y;
}
int add(int a,int b,int c=0)
{
    return a+b+c;
}
float area(float r)
{
    return 3.14*r*r;
}
int area(int l,int b)
{
    return l*b;
}
double area(int a,int b,int c)
{
    double s;
    s=(a+b+c)/2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
int big(int a,int b)
{
    if(a>b)
      return a;
    else 
      return b;
}
double big(double a,double b)
{
    if(a>b)
      return a;
    else
      return b;
}
int add(int x,int y)
{
    return x+y;
}
double add(double x,double y)
{
    return x+y;
}
int main()
{
    cout<<"Largest number is "<<big(654,46);
}