#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
/*
class Person
{
    private:
       string name;
       int age;
    protected:
       void setname(string name)
       { this->name=name; }
       void setage(int age)
       { this->age=age; }
       string getname()
       { return name; }
       int getage()
       { return age; }

};

class Employee:public Person
{
   private:
      double salary;
   public:
      void setEmployee(string n,int a,double s)
      {
         setname(n);
         setage(a);
         salary=s;
      }
      void showEmployee()
      {
         cout<<endl<<getname()<<"  "<<getage()<<"  "<<salary;
      }
};

int main()
{
   Employee e;
   e.setEmployee("Sandeep kumar",20,98000000.456);
   e.showEmployee();
   return 0;
}
*/
/*
class Circle
{
   private:
      int radius;
   public:
      void setRadius(int r)
      {radius=r;}
      int getRadius(){return radius;}
      float getArea(){return 3.14*getRadius()*getRadius();}

};
class ThickCircle:public Circle
{
   private:
      int thickness;
   public:
      void setThickness(int t)
      {thickness=t;}
      int getThickness(){return thickness;}
      float getArea()
      {return 3.14*((getRadius()+thickness)*(getRadius()+thickness)-getRadius()*getRadius());}
};
*/

class Coordinate
{
   private:
      int x,y;
   public:
      void setCoordinate(int x,int y)
      {
         this->x=x;
         this->y=y;
      }
      int getx(){return x;}
      int gety(){return y;}
      float getDistance()
      {
         return sqrt(x*x+y*y);
      }
      float getDistance(Coordinate C)
      {
         return sqrt((x-C.x)*(x-C.x)+(y-C.y)*(y-C.y));
      }
      void showCoordinate()
      {
         cout<<"("<<x<<","<<y<<")";
      }
};
class Shape
{
   private:
      string shapeName;
   public:
      void setShapeName(string shapeName)
      {this->shapeName=shapeName;}
      string getShapeName()
      {return shapeName;}
};

class StraightLine:public Shape
{
   private:
      Coordinate A,B;
   public:
      void setLine(Coordinate A,Coordinate B)
      {
         this->A=A;
         this->B=B;
      }
      int getDistance()
      {
         return A.getDistance(B);
      }
      void showLine()
      {
         A.showCoordinate();
         B.showCoordinate();
      }
};

class Game
{
   private:
      int A[5];
   public:
      void setScore(int round,int score)
      {
         A[round]=score;
      }
      int getScore(int round)
      {return A[round];}
};

class Gameresult:public Game
{
   private:
      int result[5];
   public:
      void setResult(int round,int r)
      { result[round]=r; }
      int getResult(int round)
      { return result[round]; }
      int getFinalResult()
      {
         int s=0;
         for(int i=0;i<5;i++)
            s=s+result[i];
         return s;
      }
};

class Actor
{
   private:
     string name;
     int age;
   public:
     void setName(string name)
     { this->name=name;}
     void setAge(int age)
     { this->age=age; }
     string getName()
     { return name; }
     int getAge()
     { return age; }
};
class TVActor:virtual public Actor
{
   private:
      int TVProject;
   public:
      void setTVProject(int TVProject)
      { this->TVProject=TVProject;}
      int getTVProject()
      { return TVProject; }
      void setTVActor(string n,int a,int p)
      {
         setName(n);
         setAge(a);
         setTVProject(p);
      }
      void showTVProject()
      {
         cout<<endl;
         cout<<getName()<<endl;
         cout<<getAge()<<endl;
         cout<<getTVProject();
      }
};

class MovieActor:virtual public Actor
{
   private:
      int movie;
   public:
      void setMovieActor(int movie)
      { this->movie=movie;}
      int getMovieActor()
      { return movie;}
      void setMovieActor(string n,int a,int m)
      {
         setName(n);
         setAge(a);
         setMovieActor(m);
      }
      void showMovieActor()
      {
         cout<<endl;
         cout<<getName()<<endl;
         cout<<getAge()<<endl;
         cout<<getMovieActor();
      }
};

class AllScreenActor:public TVActor,public MovieActor
{
   public:
      void setActorData(string n,int a,int tc,int mc)
      {
         setName(n);
         setAge(a);
         setTVProject(tc);
         setMovieActor(mc);
      }
      void showActorData()
      {
         cout<<endl;
         cout<<getName()<<endl;
         cout<<getAge()<<endl;
         cout<<getTVProject()<<endl;
         cout<<getMovieActor();
      }
};
int main()
{
   
}