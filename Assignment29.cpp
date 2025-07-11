#include<iostream>
using namespace std;

void printHello()
{
    cout<<endl<<"Hello MySirG";
}
void printFirst()
{
    cout<<endl<<"Hello\nMySirG";
}
int sum()
{
    cout<<"Enter two number";
    int a,b;
    cin>>a>>b;
    return a+b;
}
float Area_Circle()
{
    int r;
    cout<<"Enter radius of circle: ";
    cin>>r;
    return 3.14*r*r;
}
int volume()
{
    int l,b,h;
    cout<<"Enter length breadth and height of cuboid ";
    cin>>l>>b>>h;
    return l*b*h;
}
int avg()
{
    int a,b,c;
    cout<<"Enter three number ";
    cin>>a>>b>>c;
    return (a+b+c)/3;
}
int square()
{
    int x;
    cout<<"Enter a number ";
    cin>>x;
    return x*x;
}
void swap()
{
    int a,b;
    cout<<"Enter two number ";
    cin>>a>>b;
    cout<<endl<<"Data before swapping ";
    cout<<"a="<<a<<" b="<<b;
    a=a+b;
    b=a-b;
    a=a-b;
    cout<<endl<<"Data after swapping ";
    cout<<endl<<"a="<<a<<" b="<<b;    
}
int max()
{
    int a,b;
    cout<<"Enter two number ";
    cin>>a>>b;
    if(a>b)
      return a;
    else
      return b;
}
int sum_Array()
{
    int a[10],i,sum=0;
    cout<<"Enter elements of array: ";
    for(i=0 ; i<10 ; i++)
        cin>>a[i];
    for(i=0 ; i<10 ; i++)
        sum=sum+a[i];
    return sum;
}