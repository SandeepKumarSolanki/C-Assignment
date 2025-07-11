#include<iostream>
using namespace std;
#define ARRAY_INDEX_OUT_OF_BOUND 1
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
      Complex operator+(Complex);
      Complex operator-(Complex);
      Complex operator*(Complex);
      bool operator==(Complex);
};

Complex Complex::operator+(Complex c)
{
    Complex temp;
    temp.a=a+c.a;
    temp.b=b+c.b;
    return temp;
}
Complex Complex::operator-(Complex c)
{
    Complex temp;
    temp.a=a-c.a;
    temp.b=b-c.b;
    return temp;
}
Complex Complex::operator*(Complex c)
{
    Complex temp;
    temp.a=a*c.a-b*c.b;
    temp.b=a*c.b+b*c.a;
    return temp;
}
bool Complex::operator==(Complex c)
{
    if(a==c.a && b==c.b)
       return true;
    else 
        false;
}
/*
int main()
{
    Complex c1,c2,c3;
    c1.setData(4,5);
    c1.showData();
    c2.setData(7,8);
    c2.showData();
    c3=c1+c2;
    c3.showData();
    return 0;
}
*/
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
       bool operator>(Time t)
       
       {
         if(hr>t.hr)
            return true;
         else if(hr<t.hr)
            return false;
         else if(min>t.min)
            return true;
         else if(min<t.min)
            return false;
         else if(sec>t.sec)
            return true;
         else
           return false;
       }
       /*Time operator++()//pre-increment
       {
        sec++;
        min=min+sec/60;
        sec%=60;
        hr=hr+min/60;
        min%=60;
        return this*;
       }*/
       Time operator++(int)//post-increment
       {
        Time temp=*this;
        sec++;
        min=min+sec/60;
        sec%=60;
        hr=hr+min/60;
        min%=60;
        return temp;
       }
       Time operator+(Time t)
       {
        Time temp;
        temp.sec=sec+t.sec;
        temp.min=min+t.min+t.sec/60;
        temp.sec%=60;
        temp.hr=hr+temp.hr+t.min/60;
        temp.min%60;
        return temp;
       }
};
bool Time::operator>(Time t)
{
    if(hr>t.hr)
       return true;
    else if(hr<t.hr)
       return false;
    else if(min>t.min)
       return true;
    else if(min<t.min)
       return false;
    else if(sec>t.sec)
       return true;
    else
       return false;
}
/*
int main()
{
    Time t;
    t.setTime(5,55,56);
    t.showTime();
    return 0;
}
*/
class Matrix
{
    private:
       int A[3][3];
    public:
       void setData(int a[][3])
       {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                A[i][j]=a[i][j];
            }
        }
       }
       void showData()
       {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cout<<A[i][j]<<" ";
            }
            cout<<endl;
        }
       }
       Matrix operator+(Matrix);
       Matrix operator-(Matrix);
       Matrix operator*(Matrix);
};
Matrix Matrix::operator+(Matrix m)
{
    Matrix temp;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            temp.A[i][j]=A[i][j]+m.A[i][j];
        }
    }
    return temp;
}
Matrix Matrix::operator-(Matrix m)
{
    Matrix temp;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            temp.A[i][j]=A[i][j]-m.A[i][j];
        }
    }
    return temp;
}
Matrix Matrix::operator*(Matrix m)
{
    Matrix temp;
    int sum;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0,sum=0;k<3;k++)
            {
                sum=sum+A[i][k]*m.A[k][j];
            }
            temp.A[i][j]=sum;
        }
    }
    return temp;
}

class Number
{
    private:
       int x,y,z;
    public:
       void setNumber(int x,int y,int z)
       {
        this->x=x;
        this->y=y;
        this->z=z;
       }
       void showNumber()
       {
        cout<<endl<<"x="<<x<<" y="<<y<<" z="<<z;
       }
       Number operator-()
       {
        Number temp;
        temp.x=-x;
        temp.y=-y;
        temp.z=-z;
        return temp;
       }
};

class fraction
{
    private:
       long numerator;
       long denominator;
    protected:
       long lcm(int x,int y)
       {
        int L;
        for(L=x>y?x:y ; L<=x*y ; L++)
            if(L%x==0 && L%y==0)
                return L;
       }
    public:
       fraction(long n=0,long d=0)
       {
        numerator=n;
        denominator=d;
       }
       fraction operator+(fraction f)
       {
        fraction temp;
        long L=lcm(denominator,f.denominator);
        temp.numerator=numerator*(L/denominator)+f.numerator*(L/f.denominator);
        temp.denominator=L;
        return temp;
       }
       bool operator<(fraction f)
       {
        return numerator*f.denominator > f.numerator*denominator;
       }
};

class Distance
{
    private:
       int km,m,cm;
    public:
       void setDistance(int km,int m,int cm)
       {
        this->km=km;
        this->m=m;
        this->cm=cm;
       }
       void showDistance()
       {
        cout<<endl<<km<<"km "<<m<<"m "<<cm<<"cm";
       }
       Distance operator+(Distance d)
       {
        Distance temp;
        temp.cm=cm+d.cm;
        temp.m=m+d.m+temp.cm/100;
        temp.m%=100;
        temp.km=km+d.km+temp.m/1000;
        temp.m%=1000;
        return temp;
       }
       Distance operator--()//pre-increment
       {
        if(cm>0)
          cm--;
        else
        {
            cm=99;
            if(m>0)
               m--;
            else
            {
                m=999;
                km--;
            }
        }
        return *this;
       }
       Distance operator--(int)//post-increment
       {
         Distance temp=*this;
         if(cm>0)
            cm--;
         else
         {
            cm=99;
            if(m>0)
               m--;
            else
            {
                m=999;
                km--;
            }
         }
         return temp;
       }
};

class Array
{
    private:
       int *p;
       int size;
    public:
       Array(int n)
       {
        size=n;
        p=new int[n];
       }
       int& operator[](int index)
       {
        if(index>=size)
        {
            cout<<"Array index out of bond";
            throw ARRAY_INDEX_OUT_OF_BOUND;
        }
        return p[index];
       }
       ~Array()
       {
        delete []p;
       }
};