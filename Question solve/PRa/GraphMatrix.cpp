#include<iostream>
#include"DynArray1.cpp"
using namespace std;



class GraphMatrix
{
    private:
        int v_count;
        int e_count;
        int **adj;
    public:
        void createGraph(int,int);
        int getVCount();
        void printGraphMatrix();
        void printAllAdjacencyNode(int);
        bool isIsolated(int);
        DArray& adjacentNodes(int);
        ~GraphMatrix();

};

void GraphMatrix::createGraph(int vno,int eno)
{
    int u,v;
    v_count=vno;
    e_count=eno;

    adj=new int*[v_count];

    for(int i=0 ; i<v_count ; i++)
        adj[i]=new int[v_count];
    
    for(int i=0 ; i<v_count ; i++)
    {
        for (int j=0 ; j<v_count ; j++)
        adj[i][j]=0;  //instantly all edges of graph are 0
    }

    for(int k=1 ; k<=e_count ; k++)
    {
        cout<<"Enter nodes number connection edges:";
        cin>>u>>v;
        adj[u][v]=1;   //if edge is present then value will be 1 else it remains 0.
        adj[v][u]=1;
    }
}

int GraphMatrix::getVCount()
{
    return v_count;
}

void GraphMatrix::printGraphMatrix()
{
    if(v_count==0)
        cout<<"Graph has no node";
    else
    {
        for(int i=0 ; i<v_count ; i++)
        {
            for(int j=0 ; j<e_count ; j++)
            {
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}

void GraphMatrix::printAllAdjacencyNode(int v)
{
    if(v < v_count && v >= 0)
    {
        for(int i=0 ; i<v_count ; i++)
        {
            if( adj[v][i] == 1 )
                cout<<endl<<"V"<<i;
        }
    }
}

bool GraphMatrix::isIsolated(int v)
{
    bool flag=true;
    if(v < v_count && v >= 0)
    {
        for(int i=0 ; i<v_count ; i++)
        {
            if(adj[v][i]==1)
            {
                flag=false;
                break;
            }
        }
    }
    return flag;
}

DArray& GraphMatrix::adjacentNodes(int n)
{
    DArray *p=new DArray();
    if(n < v_count && n >= 0)
    {
        for(int i=0 ; i<v_count ; i++)
        {
            if(adj[n][i]==1)
                p->append(i);
        }
    }
    return *p;
}

GraphMatrix::~GraphMatrix()
{
    for(int i=0 ; i<v_count ; i++)
        delete []adj[i];
    delete []adj;
}

int main()
{
    GraphMatrix g;
    g.createGraph(5,6);
    g.printGraphMatrix();
    g.printAllAdjacencyNode(2);
    cout<<endl;
    return 0;
}