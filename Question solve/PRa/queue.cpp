#include<iostream>
using namespace std;
#define EMPTY_LIST -1

struct node
{
    int item;
    node *next;
};

class queue
{
    private:
        node *front;
        node *rear;
    public:
    queue();
    queue(queue &);
    queue& operator=(queue &);
    void insertionAtRear(int);
    int viewRear();
    int viewFront();
    void deleteFront();
    int countElement();
    void display();
    ~queue();


};

queue::queue()
{
    front=NULL;
    rear=NULL;
}

queue::queue(queue &q)
{
    front=NULL;
    rear=NULL;
    node *temp;
    temp=q.front;
    while(temp!=NULL)
    {
        insertionAtRear(temp->item);
        temp=temp->next;
    }
}

queue& queue::operator=(queue &q)
{
    while(front)
        deleteFront();
    front=NULL;
    rear=NULL;
    node *temp;
    temp=q.front;
    while(temp!=NULL){
        insertionAtRear(temp->item);
        temp=temp->next;
    }
    return *this;
}

void queue::insertionAtRear(int data)
{
    node *n;
    n=new node;
    n->item=data;
    n->next=NULL;
    if(rear==NULL){
        front=n;
        rear=n;
    }
    else{
        rear->next=n;
        rear=n;
    }
}

int queue::viewRear()
{
    if(rear==NULL)
        throw EMPTY_LIST;
    return rear->item;
}

int queue::viewFront()
{
    if(front==NULL)
        throw EMPTY_LIST;
    return front->item;
}

void queue::deleteFront()
{
    if(front==NULL)
        throw EMPTY_LIST;
    if(front==rear){
        delete front;
        front=NULL;
        rear=NULL;
    }
    else
    {
        node *t=front;
        front=front->next;
        delete t;
    }
        
}

int queue::countElement()
{
    int count=0;
    node *temp;
    temp=front;
    while(temp){
        count++;
        temp=temp->next;
    }
    return count;
}

void queue::display()
{
    node *temp;
    
    if(front==NULL)
        cout<<"The Queue is Empty!"<<endl;
    else{
        temp=front;
        while(temp!=NULL)
        {
            cout<<temp->item<<" ";
            temp=temp->next;
        }
    }
}

queue::~queue()
{
    while(front)
        deleteFront();
}

int main()
{
    queue q;
    q.insertionAtRear(1);
    q.insertionAtRear(2);
    q.insertionAtRear(3);

    q.display();

    q.deleteFront();
    cout<<endl;
    q.display();

    cout<<endl;
    cout<<q.countElement();
    q.insertionAtRear(34);

    cout<<endl;

    cout<<q.viewFront();
    
    cout<<endl;

    cout<<q.viewRear();
    return 0;
}