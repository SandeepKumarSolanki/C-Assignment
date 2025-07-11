#include<iostream>
#include<math.h>
using namespace std;
struct node{
    node *left;
    int item;
    node *right;
};
class Tree{
    private:
        node *root;
    protected:
        node* insertion(node*,int);
        node* createNode(int);
        node* show(node*);
        void recPreorder(node*);
        void recInorder(node*);
        void recPostorder(node*);
        node* deletion(node*,int);
        node* minValueNode(node*);
    public:
        Tree();
        void insert();
        void display();
        void preorder();
        void inorder();
        void postorder();
        void del(int);
        void min();
        void max();
};
Tree::Tree(){
    root=NULL;
}
node* Tree::createNode(int data)
{
    node *n=new node;
    n->item=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
void Tree::insert(){
    cout<<endl<<"Enter data: ";
    int data;
    cin>>data;
    while(data!=-1)
    {
        root=insertion(root,data);
        cin>>data;
    }
}
node* Tree::insertion(node *ptr,int data)
{
    if(ptr==NULL)
    {
        node *n=createNode(data);
        return n;
    }
    if(data<ptr->item)
        ptr->left=insertion(ptr->left,data);
    else if(data>ptr->item)
        ptr->right=insertion(ptr->right,data);
    else
        return ptr;     //duplicate value
}
void Tree::del(int data)
{
    root=deletion(root,data);
}
node* Tree::deletion(node *ptr,int data)
{
    if(ptr==NULL)
        return ptr;
    if(ptr->item==data)
    {
        if(ptr->left==NULL && ptr->right==NULL)     //no child
        {
            delete ptr;
            return NULL;
        }
        if(ptr->left!=NULL && ptr->right==NULL)  //one child
        {
            node *temp=root->left;
            delete ptr;
            return temp;
        }
        if(ptr->left==NULL && ptr->right!=NULL)
        {
            node *temp=root->right;
            delete ptr;
            return temp;
        }
        if(ptr->left!=NULL && ptr->right!=NULL)
        {
            node *temp=minValueNode(ptr->right);
            ptr->item=temp->item;
            ptr->right=deletion(ptr->right,temp->item);
        }
    }
    else if(data<ptr->item)
        ptr->left=deletion(ptr->left,data);
    else 
        ptr->right=deletion(ptr->right,data);
}
void Tree::display()
{
    root=show(root);
}
node* Tree::show(node *ptr)
{
    while(ptr!=NULL)
    {
        cout<<ptr->item<<" ";
        show(ptr->left);
        show(ptr->right);
        
    }
    return ptr;
}
void Tree::preorder()
{
    recPreorder(root);
}
void Tree::inorder()
{
    recInorder(root);
}
void Tree::postorder()
{
    recPostorder(root);
}
void Tree::recPreorder(node *ptr)
{
    if(ptr)
    {
        cout<<ptr->item<<" ";
        recPreorder(ptr->left);
        recPreorder(ptr->right);
    }
}
void Tree::recInorder(node *ptr)
{
    if(ptr)
    {
        recInorder(ptr->left);
        cout<<ptr->item<<" ";
        recInorder(ptr->right);
    }
}
void Tree::recPostorder(node *ptr)
{
    if(ptr)
    {
        recPostorder(ptr->left);
        recPostorder(ptr->right);
        cout<<ptr->item<<" ";
    }
}
node* Tree::minValueNode(node *ptr)
{
    node *temp=ptr;
    while(temp->left!=NULL)
        temp=temp->left;
    return temp;
}
void Tree::min()
{
    node *t;
    t=root;
    while(t->left!=NULL)
        t=t->left;
    cout<<endl<<"Minimum value in the tree is:"<<t->item;
}
void Tree::max()
{
    node *t;
    t=root;
    while(t->right!=NULL)
        t=t->right;
    cout<<endl<<"Maximum value in the tree is: "<<t->item;
}
int main()
{
    Tree t;
    t.insert();   
    cout<<endl;
    cout<<endl<<"Pre - Order : ";
    t.preorder();
    cout<<endl<<"In - Order : ";
    t.inorder();
    cout<<endl<<"Post - Order : ";
    t.postorder();
    // t.del(30);
    //  cout<<endl<<"Pre - Order : ";
    // t.preorder();
    
    // t.del(60);
    //  cout<<endl<<"Pre - Order : ";
    // t.preorder();
    // t.del(70);
    //  cout<<endl<<"Pre - Order : ";
    // t.preorder();
    // t.min();
    // t.max();
    cout<<endl;
    t.display();
    // t.del(30);
    // cout<<endl;
    // t.display();
    // cout<<endl<<"Pre - Order : ";
    // t.preorder();
    // cout<<endl<<"In - Order : ";
    // t.inorder();
    // cout<<endl<<"Post - Order : ";
    // t.postorder();
    // t.min();
    // t.max();
    return 0;
}