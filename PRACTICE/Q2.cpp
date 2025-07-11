#include<iostream>
using namespace std;

int isTrue(int a,int b)
{
     if(a==b)
        return 1;
    return 0;
}
int main()
{
    float a=2.134;
    float b=2.134;
    cout<<isTrue(a,b);
    return 0;
}