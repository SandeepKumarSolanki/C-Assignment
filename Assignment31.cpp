#include<iostream>
#include<string.h>
using namespace std;

void sorting(int a[],int size,bool asc=true);
void sortStrings(char *A[],int n,bool asc=true);
void rotate(int a[],int size,int pos,int d=1);
int lcm(int a,int b,int c);
int hcf(int a,int b);
void printString(char str[],int startindex,int endindex=-1);
void swapArrays(int A[],int B[],int N);
void merge(int A[],int B[],int N,int C[]);
void merge(int A[],int B[],int N,int C[])
{
    int i,j,k;
    for(i=0,j=0,k=0 ; i<N && j<N ; k++)
    {
        if(A[i]<B[j])
        {
            C[k]=A[i];
            i++;
        }
        else
        {
            C[k]=B[j];
            j++;
        }
    }
    while(i<N)
    {
        C[k]=A[i];
        i++;
        k++;
    }
    while(j<N)
    {
        C[k]=B[j];
        j++;
        k++;
    }
}
void swapArrays(int A[],int B[],int N)
{
    int t;
    for(int i=0;i<N;i++)
    {
        t=A[i];
        A[i]=B[i];
        B[i]=t;
    }
}
void printString(char str[],int startindex,int endindex)
{
    if(endindex==-1)
       endindex=strlen(str);
    for(int i=startindex;i<endindex;i++)
        cout<<str[i];
}
int hcf(int a,int b)
{
    for(int h=a<b?a:b ; h>=1;h++)
    {
        if(a%h==0 && b%h==0)
          return h;
    }
    return 1;
}
int lcm(int a,int b,int c)
{
    int L;
    for(L=a>b?a>c?a:c:b>c?b:c  ;  L<=a*b*c  ;  L++)
    {
        if(L%a==0 && L%b==0 && L%c==0)
           return L;
    }
    return 1;
}
void rotate(int a[],int size,int n,int d)
{
    int i,temp;
    if(d==1)
    {
        while(n)
        {
             temp=a[size-1];
             for(i=size-2;i>=0;i--)
             { 
                a[i+1]=a[i];
             }
             a[0]=temp;
             n--;
        }
    }
    else
    {
       while(n)
       {
        temp=a[0];
        for(i=1;i<size;i++)
        {
            a[i-1]=a[i];
        }
        a[size-1]=temp;
        n--;
       }
    }
    cout<<endl<<"Elements after rotation\n";
    for(i=0;i<size;i++)
    cout<<a[i]<<" ";
}
void sortStrings(char *A[],int n,bool asc)
{
    char temp[50];
    int i,r;
    if(asc)
    {
       for(r=1;r<n;r++)
       {
        for(i=0;i<n-r;i++)
        {
            if(strcmp(A[i],A[i+1])>0)
            {
                strcpy(temp,A[i]);
                strcpy(A[i],A[i+1]);
                strcpy(A[i+1],temp);
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
            if(strcmp(A[i],A[i+1])<0)
            {
                strcpy(temp,A[i]);
                strcpy(A[i],A[i+1]);
                strcpy(A[i+1],temp);
            }
        }
       }
    }
     
}
void sorting(int a[],int size,bool asc)
{
   int i,r,temp;
   if(asc)
     {
        for(r=1;r<size;r++)
        {
            for(i=0;i<size-r;i++)
            {
                if(a[i]>a[i+1])
                {
                    temp=a[i];
                    a[i]=a[i+1];
                    a[i+1]=temp;
                }
            }
        }
     }
     else
     {
        for(r=1;r<size;r++)
        {
            for(i=0;i<size-r;i++)
            {
                if(a[i] < a[i+1])
                {
                    temp=a[i];
                    a[i]=a[i+1];
                    a[i+1]=temp;
                }
            }
        }
    }
    cout<<"Elements after sorting :"<<endl;
    for(int i=0;i<size;i++)
    cout<<a[i]<<" ";
}
bool isPrime(int n)
{
   for(int i=2;i<n;i++)
       if(n%i==0)
          return false;
    return true;
}
int nextPrime(int n)
{
    n++;
    while(!isPrime(++n));
    return n;
        
}
void printPrime(int n)
{
    for(int i=2;i<n;i++)
    {
        if(isPrime(i));
          cout<<i<<" ";
    }
}
int volume(int l,int b,int h)
{
    return l*b*h;
}
float volume(float r,float h)
{
    return (3.14*r*r*h)*1/3;
}
double volume(double r)
{
    return 3.14*r*r*r*4/3;
}

int main()
{
    cout<<volume(10,11,21);
    // cout<<hcf(12,24);
    return 0;
}

/*int main()
{
    int a[9]={55,56,32,66,3,75,34,23,54};
    rotate(a,9,2,1);
    
    return 0;
}
*/
