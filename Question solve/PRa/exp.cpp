#include<iostream>
using namespace std;

int main()
{
    char ch[]={'a','b','c','d','e','\0'};
    int i=0;
    while(ch[i]!='\0')
    {
        cout<<ch[i];
        i++;
    }
    return 0;
}