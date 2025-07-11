#include<iostream>
#include<stack>
using namespace std;


/*
    //Redundant Brackets
    
    bool findRedundantBrackets(string &s)
    {
        stack<char> st;
        for(int i=0 ; i<s.length ; i++)
        {
            char ch=s[i];

            if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/')
            {
                st.push(ch);
            }
            else
            {
                //ch ya to ')' hai or lowercase letter
                if(ch==')' )
                {
                    bool isRedundant=true;
                    while(st.top()!='(' )
                    {
                        char top=st.top();
                        if(top=='+' || top=='-' || top '*' || top=='/')
                        {
                            ifRedundant = false;
                        }
                        st.pop();
                    }
                    if(isRedundant == true)
                        return true;
                    st.pop();
                }
            }
        }
        return false;
    }
*/

/*
void sortedInsert(stack<int> &stack,int num)
{
    if(stack.empty() || (!stack.empty() && stack.top() < num) )
    {
        stack.push(num);
        return ;
    }

    int n=stack.top();
    stack.pop();

    //recursive call
    sortedInsert(stack,num);

    stack.push(n);
}

void sortStack(stack<int> &stack)
{
    //base case
    if(stack.empty()){
        return ;
    }

    int num=stack.top();
    stack.pop();

    //recursive call
    sortStack(stack);

    sortedInsert(stack,num);
}
*/


/*
//VALID PARENTHESIS
bool isValidParenthesis(string expression)
{
    stack<char> s;
    
    for(int i=0 ; i < expression.length() ; i++)
    {
        char ch=expression[i];

        //if opening bracket stack push

        //if close brackedt stack top check and top

        if(ch=='(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else
        {
            //for closing bracket
            if(!s.empty())
            {
                char top=s.top();
                if( (ch==')' && top == '(' ) ||
                    (ch=='}' && top == '}' )||
                    (ch==']' && top == '[' ) )
                    {
                    s.pop();
                    }
                    else
                    {
                        return false;
                    }
            }
            else
            { 
                return false;
            }
        }
    }
    if(s.empty())
        return true;
    else
        return false;
}

*/

/*
//Delete Middle element of stack
void solve(stack<int>&inputStack, int count ,int size)
{
    //base case
    if(count==size/2){
        inputStack.pop();
        return;
    }

    int num=inputStack.top();
    inputStack.pop();

    //RECURSIVE CALL

    solve(inputStack , count+1, size);

    inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack,int N){
    int count=0;
    solve(inputStack, count, N); 
}

*/
/*
int main()
{
    string str="Sandeep kumar solanki";
    stack<char> s;

    for(int i=0;str[i];i++)
    {
        char ch=str[i];
        s.push(ch);
    }

    string ans="";

    while(!s.empty())
    {
        char ch = s.top();
        ans.push_back(ch);

        s.pop();
    }

    cout<<" answer is : "<<ans<<endl;
    return 0;
}

*/