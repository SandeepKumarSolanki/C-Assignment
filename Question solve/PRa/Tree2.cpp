#include<iostream>
using namespace std;

struct node
{
    node *left;
    int item;
    node *right;
    int height;
};

class Tree
{
    private:
        node *root;
        node* insertion(node*,int);
        node* deletion(node*,int);
        void recPreorder(node *);
        void recInorder(node *);
        void recPostorder(node *);
        node* minValueNode(node *);
    public:
        Tree();
        //Tree(Tree &);
        //Tree& operator=(Tree &);
        int getBalanceFactor(node *);

        void updateAnscestorsHeights(node*,int);
        node* leftRotate(node *);
        node* rightRotate(node *);
        void insert(int);
        void del(int);

        void preorder();
        void inorder();
        void postorder();
        int getHeight(node*);
        //~Tree();
};

Tree::Tree()
{
    root=NULL;
}

int max(int a,int b)
{
    return (a>b?a:b);
}

//Find the left most leaf
node* Tree::minValueNode(node *ptr)
{
    node *current=ptr;//loop down to find the left most leaf

    while(current->left!=NULL)
        current = current->left;
    
    return current;
}

void Tree::updateAnscestorsHeights(node *ptr,int data)
{
    if(data==ptr->item)
    {
        ptr->height=  1;
    }
    else
    {
        if(data < ptr->item)
        {
            updateAnscestorsHeights(ptr->left,data);
        }
        else if(data > ptr->item)
        {
            updateAnscestorsHeights(ptr->right,data);
        }
        ptr->height=max(getHeight(ptr->left),getHeight(ptr->right))+1;
    }
}
node* Tree::insertion(node *ptr,int data)
{
   node *n;
   if(ptr==NULL)//when tree is empty
   {
        n=new node;
        n->left=NULL;
        n->item=data;
        n->right=NULL;
        n->height=1;
        return n;
   } 

   if(data < ptr->item)
   {
    ptr->left=insertion(ptr->left,data);
   }
   else if(data > ptr->item)
   {
    ptr->right=insertion(ptr->right,data);
   }
   else     //Dulicate values not allowed
    return ptr;
   
   /*Update the height of anscestors node*/
   ptr->height=1+max(getHeight(ptr->left),getHeight(ptr->right));

   /* 
      3.Get the balance factor of this ancestor node
      to check whether this node become unbalanced
   */
   int balance=getBalanceFactor(ptr);
   
   /*If this node becomes unbalanced*/

   //Then there are 4 cases

   //left left case
   if(balance > 1 && data < ptr->left->item)
        return rightRotate(ptr);

    //Right Right Case
    if(balance < -1 && data > ptr->right->item)
        return leftRotate(ptr);
    
    //Left Right Case
    if(balance > 1 && data > ptr->left->item)
    {
        ptr->left = leftRotate(ptr->left);
        return rightRotate(ptr);
    }

    //Right Left Case
    if(balance < -1 && data < ptr->right ->item)
    {
        ptr->right=rightRotate(ptr->right);
        return leftRotate(ptr);
    }

    /*Return the (unchanged) node pointer*/
    return ptr;

}

void Tree::insert(int data)
{
    root=insertion(root,data);
}


node* Tree::deletion(node *ptr,int data)
{
    if(ptr==NULL)
        return ptr;
    
    if(data < ptr->item)
        ptr->left=deletion(ptr->left,data);
    
    else if(data > ptr->item)
        ptr->right=deletion(ptr->right,data);
    
    else
    {
        /*node with only one child or no child*/
        if((ptr->left==NULL) || (ptr->right==NULL))
        {
            node *temp=ptr->left ? ptr->left : ptr->right;
            //no child

            if(temp==NULL)
            {
                temp=ptr;
                ptr=NULL;
            }
            else    //one child case
                *ptr=*temp;
            delete temp;
        }
        else   
        /*
             node with two children :Get the inorder 
             successor (smallest in the right subtree)
        */
       {
        node *temp=minValueNode(ptr->right);
        ptr->item=temp->item;
        //Delete the inorder successor
        ptr->right=deletion(ptr->right,temp->item);
       }

    }
    //If the tree had only one node then return
    if(ptr==NULL)
        return ptr;
    ptr->height=1+max(getHeight(ptr->left),getHeight(ptr->right));
       
    int balance=getBalanceFactor(ptr);

    //Left Left Case
    if(balance > 1 && getBalanceFactor(ptr->left)>=0)
        return rightRotate(ptr);

    //Left Right Case
    if(balance > 1 && getBalanceFactor(ptr->left)<0)
    {
        ptr->left = leftRotate(ptr->left);
        return rightRotate(ptr);
    }

    //Right Right case
    if(balance < -1 && getBalanceFactor(ptr->right)<=0)
        return leftRotate(ptr);

    //Right Left Case
    if(balance < -1 && getBalanceFactor(ptr->right)>0)
    {
        ptr->right=rightRotate(ptr->right);
        return leftRotate(ptr);
    }
    return ptr;
      
}

void Tree::del(int data)
{
    root=deletion(root,data);
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

void Tree::preorder()
{
    recPreorder(root);
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

void Tree::inorder()
{
    recInorder(root);
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

void Tree::postorder()
{
    recPostorder(root);
}


//Find height of Tree
int Tree::getHeight(node *ptr)
{
    if(ptr==NULL)
        return 0;
    return ptr->height;
}

//Get Balance Factor of tree
int Tree::getBalanceFactor(node *ptr)
{
    if(ptr==NULL)
        return 0;
    return getHeight(ptr->left)-getHeight(ptr->right);
}


node* Tree::leftRotate(node *A)
{
    node *B=A->right;
    node *LR=B->left;

    B->left=A;
    A->right=LR;

    //edit heights
    A->height=1+max(getHeight(A->left),getHeight(A->right));
    B->height=1+max(getHeight(B->left),getHeight(B->right));

    return B;
}

node* Tree::rightRotate(node *A)
{
    node *B=A->left;
    node *RR=B->right;

    B->right=A;
    A->left=RR;

    A->height=1+max(getHeight(A->left),getHeight(A->right));
    B->height=1+max(getHeight(B->left),getHeight(B->right));

    return B;
}


int main()
{
    Tree t;
    cout<<endl;
    t.preorder();
    t.insert(50);
    t.insert(30);
    t.insert(70);
    t.insert(10);
    t.insert(60);
    // t.insert(90);
    // t.insert(20);
    // t.insert(15);
    // t.insert(25);
    // t.insert(75);
    // t.insert(85);
    cout<<endl<<"Print in preorder way:"<<endl;
    t.preorder();

    cout<<endl<<"Print in inorder way:"<<endl;
    t.inorder();

    cout<<endl<<"print in postorder way:"<<endl;
    t.postorder();
    return 0;
}

























































