#include<iostream>
using namespace std;
class TestResult
{
   private:
      int roll_no,right,wrong,net_score;
      static int right_weightage,wrong_weightage;
   public:
      void setRollNo(int r)
      {
         roll_no=r;
      }
      void setRight(int r)
      {
         right=r;
      }
       void setWrong(int w)
      {
         wrong=w;
      }
      void setNetScore(int n)
      {net_score=n;}
      int getRollNo()
      {return roll_no;}
      int getRight()
      {return right;}
      int getWrong()
      {return wrong;}
      int getNetScore(){return net_score;}
      static void setRightWeightage(int r){right_weightage=r;}
      static void setWrongWeightage(int w){wrong_weightage=w;}
      static int getRightWeightage(){return right_weightage;}
      static int getWrongWeightage(){return wrong_weightage;}

};
int TestResult::right_weightage=3;
int TestResult::wrong_weightage=1;
void setTestResult(TestResult tr,int a,int b,int c)
{
   tr.setRollNo(a);
   tr.setRight(b);
   tr.setWrong(c);
   tr.setNetScore(b*tr.getRightWeightage()-c*tr.getWrongWeightage());

}
void printTestResult(TestResult tr)
{
   cout<<endl<<tr.getRollNo()<<" "<<tr.getRight()<<" "<<tr.getWrong()<<" "<<tr.getNetScore();
}
void sortByNetScore(TestResult result[],int size)
{
   int i,r,temp;
   for(r=1;r<size;r++)
   {
      for(i=0;i<size-r;i++)
      {
         if(result[i].getNetScore() > result[i+1].getNetScore())
         {
             temp=result[i];
             result[i]=result[i+1];
             result[i+1]=temp;
         }
      }
   }
}
int main()
{
   TestResult result[5];
   setTestResult(result[0],100,80,20);
   setTestResult(result[1],101,70,10);
   setTestResult(result[2],102,90,0);
   setTestResult(result[3],103,60,15);
   setTestResult(result[4],104,50,12);
   sortByNetScore(result,5);
   for(int i=0;i<5;i++)
   {
      printTestResult(result[i]);
   }

}
class Complex
{
   private:
   int a,b;
   public:
   void setData(int x,int y)
   {
    a=x;b=y;
   }
   void showData()
   {
    cout<<endl<<"a="<<a<<" b="<<b;
   }
   Complex add(Complex c)
   {
      Complex temp;
      temp.a=a+c.a;
      temp.b=b+c.b;
      return temp;
   }
   Complex subtract(Complex c)
   {
      Complex temp;
      temp.a=a-c.a;
      temp.b=b-c.b;
      return temp;
   }
   Complex multiply(Complex c)
   {
      Complex temp;
      temp.a=a*c.a-b*c.b;
      temp.b=a*c.b+b*c.a;
      return temp;
   }
   
};

class Time
{
  private:
  int hr,min,sec;
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
  void normalize()
  {
   min=min+sec/60;
   sec=sec%60;
   hr=hr+min/60;
   min=min%60;
  }
  Time add(Time t)
  {
   Time temp;
   temp.sec=sec+t.sec;
   temp.min=min+t.min;
   temp.hr=hr+t.hr;
   return temp;
  }
  bool isgreater(Time t)
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
};
class Matrix
{
   private:
      int A[3][3];
   public:
      void setMatrix(int a[][3])
      {
         for(int i=0;i<3;i++)
         {
            for(int j=0;j<3;j++)
            {
               A[i][j]=a[i][j];
            }
         }
      }
      Matrix add(Matrix m)
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
      Matrix sub(Matrix m)
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
      Matrix multiply(Matrix m)
      {
         Matrix temp;
         int sum=0,i,j,k;
         for(i=0;i<3;i++)
         {
            for(j=0;j<3;j++)
            {
               for(k=0;k<3;k++)
               {
                  sum=sum+A[i][k]*m.A[k][j];
               }
               temp.A[i][j]=sum;
            }
         }
         return temp;         
      }
      Matrix transpose()
      {
         Matrix temp;
         for(int i=0;i<3;i++)
         {
            for(int j=0;j<3;j++)
            {
               temp.A[i][j]=A[j][i];
            }
         }
         return temp;
      }
      bool is_singular()
      {
          int d;
          d=A[0][0]*(A[1][1]*A[2][2]-A[2][1]*A[1][2])-A[0][1]*(A[1][0]*A[2][2]-A[2][0]*A[1][2])+A[0][2]*(A[1][0]*A[2][1]-A[2][0]*A[1][1]);
          return d==0;
      }
};