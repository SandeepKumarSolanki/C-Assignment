#include<iostream>
#include<stack>
using namespace std;

class TwoStack{
    private:
        int *arr;
        int top1;
        int top2;
        int size;
    public:
    //Initialize two stack
        TwoStack(int s)
        {
            this->size=s;
            top1=-1;
            top2=s;
            arr=new int[s];
        }

        //Push in stack1
        void push1(int num){
            //atleast a empty space present
            if(top2-top1 > 1){
                top1++;
                arr[top1]=num;
            }
           
        }

        //Push in stack2
        void push2(int num){
            if(top2-top1 >1){
                top2--;
                arr[top2]=num;
            }
           
        }
        
        //Pop for stack1
        int pop1(){
            if(top1 >= 0){
                int ans= arr[top1];
                top1--;
                return ans;
            }
            else{
                return -1;
            }
        }

        //Pop for stack2
        int pop2(){
            if(top2<size){
                int ans=arr[top2];
                top2++;
                return ans;
            }
            else{
                return -1;
            }
        }
};
int main()
{
    TwoStack s(4);
    s.push1(4);
    s.push2(5);
    s.push2(7);
    s.push2(56);
    s.push2(56);
    cout<<endl;
    cout<<s.pop2()<<endl;
    cout<<s.pop2()<<endl;
    cout<<s.pop2()<<endl;
    cout<<s.pop2()<<endl;
    cout<<s.pop1()<<endl;
    
    
/*
    //Creation of stack
    stack<int> s;
    s.push(45);
    s.push(56);

    //pop 
    s.pop();

    cout<<endl<<"Top element of stack is : "<<s.top();

    if(s.empty()){
        cout<<endl<<"Stack is empty"<<endl;
    }
    else
        cout<<endl<<"Stack is not empty";
        */
    return 0; 
}