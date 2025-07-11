#include<iostream>
#define UNDERFLOW 1
using namespace std;

struct node{
    node *prev;
    int item;
    node *next;
};

class deque
{
    private:
        node *rear,*front;
    public:
        deque();
        deque(deque &);
        deque& operator=(deque &);
        void insertionAtFront(int);
        void insertionAtRear(int);
        void deleteFront();
        void deleteRear();
        int getFront();
        int getRear();
        bool isEmpty();
        void display();
        ~deque();
};

deque::deque()
{
    front=NULL;
    rear=NULL;
}

deque::deque(deque &d)
{
    node *temp;
    if(d.front==NULL){
        front=NULL;
        rear=NULL;
    }
    else{
        temp=d.front;
        while(temp!=NULL){
            insertionAtRear(temp->item);
            temp=temp->next;
        }
    }
   
    

}

deque& deque::operator=(deque  &d)
{
    while(front)
        deleteFront();
    node *temp;
    if(d.front==NULL){
        rear=NULL;
        front=NULL;
    }
    else{
        temp=d.front;
        while(temp!=NULL){
            insertionAtRear(temp->item);
            temp=temp->next;
        }
    }
    return *this;
}

void deque::insertionAtFront(int data)
{
    node *n=new node;
    n->prev=NULL;
    n->item=data;
    n->next=front;
    if(front==NULL){
        front=rear=n;
    }
    else{
        front->prev=n;
        front=n;
    }
}

void deque::insertionAtRear(int data)
{
    node *n=new node;
    n->next=NULL;
    n->item=data;
    n->prev=rear;
    if(rear==NULL)
    {
        front=rear=n;
    }
    else
    {
        rear->next=n;
        rear=n;
    }
}

void deque::deleteFront()
{
    if(front==NULL)
        throw UNDERFLOW;
    if(front==rear){
        delete front;
        front=NULL;
    }
    else{
        front=front->next;
        delete front->prev;
        front->prev=NULL;

    }
}

void deque::deleteRear()
{
    if(rear==NULL)
        throw UNDERFLOW;
    if(rear==front){
        delete rear;
        rear=NULL;
    }
    else{
        rear=rear->prev;
        delete rear->next;
        rear->next=NULL;
    }
}

int deque::getFront()
{
    if(front==NULL)
        throw UNDERFLOW;
    return front->item;
}

int deque::getRear()
{
    if(rear==NULL)
        throw UNDERFLOW;
    return rear->item;
}

bool deque::isEmpty()
{
    return (front==NULL);
}

void deque::display()
{
    node *ptr;
    if(front==NULL)
        cout<<"The Dequeue is Empty."<<endl;
    else{
        ptr=front;
        while(ptr){
            cout<<ptr->item<<" ";
            ptr=ptr->next;
        }
    }
}
deque::~deque()
{
    while(front)
        deleteFront();
}

int main()
{
    deque d;
    d.insertionAtRear(1);
    d.insertionAtRear(2);
    d.insertionAtFront(3);
    d.insertionAtRear(14);
    d.display();
    
    cout<<endl;

    d.deleteFront();

    d.display();
    
    cout<<endl;

    d.deleteRear();

    d.display();

    cout<<endl;
    d.insertionAtRear(25);
    d.insertionAtFront(36);

    cout<<endl<<d.getFront()<<endl;
    cout<<endl<<d.getRear()<<endl;

    d.insertionAtRear(11);
    d.insertionAtRear(232);
    d.insertionAtFront(367);

    cout<<endl;
    d.display();

    cout<<endl;

    d.deleteRear();
    d.display();

    cout<<endl;

    d.deleteRear();
    d.display();
    
    cout<<endl;

    cout<<d.getFront()<<endl;
    cout<<d.getRear()<<endl;
    cout<<endl;
    d.display();
    return 0;
}