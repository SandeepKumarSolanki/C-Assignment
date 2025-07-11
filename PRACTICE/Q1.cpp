#include<iostream>
#include<string.h>
using namespace std;

void sortStrings(char str[][20],int n,bool asc)
{
    char temp[50];
    int i,r;
    if(asc)
    {
       for(r=1;r<n;r++)
       {
        for(i=0;i<n-r;i++)
        {
            if(strcmp(str[i],str[i+1])>0)
            {
                strcpy(temp,str[i]);
                strcpy(str[i],str[i+1]);
                strcpy(str[i+1],temp);
            }
        }
       }
    }
    else
    {
        for(r=1;r<n;r++)
       {
        for(i=0;i<n-r;i++)
        {
            if(strcmp(str[i],str[i+1])<0)
            {
                strcpy(temp,str[i]);
                strcpy(str[i],str[i+1]);
                strcpy(str[i+1],temp);
            }
        }
       }
    }
    cout<<endl<<"Strings after sorting:<<endl";
    for(i=0;i<n;i++)
        cout<<endl<<str[i];
     
}

int main()
{
    char str[4][20]={"Sohit","Amit","Deepak","Rohit"};
    sortStrings(str,4,true);
    return 0;
}