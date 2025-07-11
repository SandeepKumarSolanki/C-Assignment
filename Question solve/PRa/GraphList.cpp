#include<iostream>
#include "DynArray1.cpp"
using namespace std;

struct node
{
    int item;
    int vertex;
    node *next;
};

class AdjList
{
    private:
        node *start;
        int vertex;
    public:
        AdjList();
        AdjList(int);
        node* getStart();
        void setVertex(int);
        void addNode(int,int);
        void removeFirstNode();
        void printList();
        ~AdjList();
};

AdjList::AdjList()
{
    start=NULL;
}


AdjList::AdjList(int v)
{
    start=NULL;
    vertex=v;
}


node* AdjList::getStart()
{
    return start;
}


void AdjList::setVertex(int v)
{
    vertex=v;
}

void AdjList::addNode(int v,int data)
{
    node *n=new node;
    n->item=data;
    n->vertex=v;
    n->next=start;
    start=n;
}

void AdjList::removeFirstNode()
{
    node *r;
    if(start==NULL)
        cout<<"List is empty";
    else
    {
        r=start;
        start=r->next;
        delete r;
    }
}


void AdjList::printList()
{
    node *ptr;
    ptr=start;
    while(ptr)
    {
        cout<<"("<<ptr->vertex<<","<<ptr->item<<")";
        ptr=ptr->next;
    }
}

AdjList::~AdjList()
{
    while(start)
        removeFirstNode();
}

class Graph
{
    private:
        int v_count;
        AdjList *arr;
    public:
        Graph();
        int getVCount();
        DArray& adjacentNodes(int);
        void createGraph(int);
        //void addEdge(int);
        void printGraph();
        ~Graph();

};

Graph::Graph()
{
    v_count=0;
    arr=NULL;
}

int Graph::getVCount()
{
    return v_count;
}


DArray& Graph::adjacentNodes( int n)
{
    DArray *p=new DArray();
    node *t=this->arr[n].getStart();
    while(t)
    {
        p->append(t->vertex);
        t=t->next;
    }
    return *p;
}


void Graph::createGraph(int vno)
{
    int n,v,data;
    v_count=vno;
    arr = new AdjList[v_count];

    for(int i=0 ; i<v_count ; i++)
    {
        arr[i].setVertex(i);
        cout<<endl<<"How many adjacent nodes of V"<<i<<":";
        cin>>n;

        for(int j=0 ; j<n ; j++)
        {
            cout<<endl<<"Enter vertex number:";
            cin>>v;
            //cout<<"Enter data to store: ";
            //cin>>data;
            data=10;
            arr[i].addNode(v,data);
        }
    }
}


void Graph::printGraph()
{
    for(int i=0; i<v_count ; i++)
    {
        cout<<endl;
        arr[i].printList();
    }
}

Graph::~Graph()
{
    delete []arr;
}

int main()
{
    Graph g;
    g.createGraph(6);
    g.printGraph();
    cout<<endl;
    return 0;
}

