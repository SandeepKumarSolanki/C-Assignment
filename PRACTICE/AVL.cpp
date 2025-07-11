#include<iostream>
using namespace std;

struct node
{
    node *left;
    int item;
    node *right;
    int height;
};

class AVL
{
    private:
        node *root;
        node* insertion(node*,int);
        node* deletion(node*,int);
        node* minValueNode(node*);
        void recInorder(node *);
        void recPostorder(node *);
        void recPreorder(node *);
        // void inorderCopy(node *);
    public:
        AVL();
        // AVL(AVL &);
        // AVL& operator=(AVL &);
        int getBalanceFactor(node*);
        int getHeight(node*);
        node* leftRotate(node*);
        node* rightRotate(node*);
        void insertElement(int);
        void updateAnscestorsHeights(node*,int);
        void del(int);
        void preorder();
        void inorder();
        void postorder();
        ~AVL();
        node* search(int);
};

AVL::AVL()
{
    root=NULL;
}

node* AVL::insertion(node *ptr,int data)
{
    node *n;
    if(ptr==NULL)
    {
        n=new node;
        n->left=NULL;
        n->item=data;
        n->right=NULL;
        n->height=1;
        return n;
    }
    
    if(data < ptr->item)
        ptr->left=insertion(ptr->left,data);
    else if(data > ptr->item)
        ptr->right=insertion(ptr->right,data);

    else   // 1.duplicate values are not allowed./
        return ptr;
    
    //2.Update the height of ancestors node
    ptr->height=1+max(getHeight(ptr->left),getHeight(ptr->right));

    /*3.Get the Balance Factor of this ancestors
    node to check whether this node become 
    unbalanced*/
    int balance = getBalanceFactor(ptr);

    /*
        4.If this node becomes unbalanced then there
        are 4 cases
    */

   //Left Left Case
    if(balance > 1 && data < ptr->left->item)
        return rightRotate(ptr);
    
    //Right Right Case
    if(balance < -1 && data > ptr->right->item)
        return leftRotate(ptr);

    //Left Right Case
    if(balance > 1 && data > ptr->left->item)
    {
        ptr->left=leftRotate(ptr->left);
        return rightRotate(ptr);
    }

    //Right Left Case
    if(balance < -1 && data < ptr -> right -> item)
    {
        ptr->right=rightRotate(ptr->right);
        return leftRotate(ptr);
    }

    /*
    return the (unchanged) node pointer
    */

    return ptr;


}

void AVL::insertElement(int data)
{
    root=insertion(root,data);
}

node* AVL::rightRotate(node *A)
{
    node *B=A->left;
    node *RT=B->right;

    B->right=A;
    A->left=RT;

    //edit heights
    A->height=1+max(getHeight(A->left),getHeight(A->right));
    B->height=1+max(getHeight(B->left),getHeight(B->right));

    return B;
}

node* AVL::leftRotate(node *A)
{
    node *B=A->right;
    node *LT=B->left;

    B->left=A;
    A->right=LT;

    A->height=1+max(getHeight(A->left),getHeight(A->right));
    B->height=1+max(getHeight(B->left),getHeight(B->right));

    return B;
}

node* AVL::deletion(node *ptr,int data)
{
    if(ptr==NULL)
        return ptr;
    
    if(data < ptr->item)
        ptr->left = deletion(ptr->left,data);
    else
        if(data > ptr->item)
            ptr->right=deletion(ptr->right,data);
    else
    {
        //node with only one child or no child
        if((ptr->left==NULL) || (ptr->right==NULL))
        {
            node *temp=ptr->left ? ptr->left:ptr->right;

            //no child
            if(temp == NULL)
            {
                temp=ptr;
                ptr=NULL;
            }
            else //one child case
                *ptr=*temp;
            delete temp;
        }
        else
        {
            //node with two children:Get the inorder successor
            //smallest in the right subtree
            node *temp=minValueNode(ptr->right);

            ptr->item=temp->item;

            //Delete the inorder successor

            ptr->right=deletion(ptr->right,temp->item);
        }
        
    }

    //if tree had only one node then return 
    if(ptr==NULL)
        return ptr;

    ptr->height=1+max(getHeight(ptr->left),getHeight(ptr->right));

    int balance=getBalanceFactor(ptr);

    //left left case
    if(balance > 1 && getBalanceFactor(ptr -> left)>=0)
        return rightRotate(ptr);
    
    //left Right case
    if(balance > 1 && getBalanceFactor(ptr->left)<0)
    {
        ptr->left=leftRotate(ptr->left);
        return rightRotate(ptr);
    }

    //Right Right Case
    if(balance < -1 && getBalanceFactor(ptr -> right)<=0)
    {
        return leftRotate(ptr);
    }

    //Right Left Case
    if(balance < -1 && getBalanceFactor(ptr -> right)>0)
    {
        ptr->right = rightRotate(ptr->right);
        return leftRotate(ptr);
    }

    return ptr;

}


void AVL::del(int data)
{
    deletion(root,data);
}
void AVL::recPreorder(node *ptr)
{
    
    if(ptr)
    {
        cout<<ptr->item<<" ";
        recPreorder(ptr->left);
        recPreorder(ptr->right);
    }
}

void AVL::preorder()
{
    cout<<endl<<"Elements traversing in preorder way:"<<endl;
    recPreorder(root);
}

void AVL::recInorder(node *ptr)
{
    
    if(ptr)
    {
        recInorder(ptr->left);
        cout<<ptr->item<<" ";
        recInorder(ptr->right);
    }
}

void AVL::inorder()
{
    cout<<endl<<"Elements traversing in inorder way:"<<endl;
    recInorder(root);
}

void AVL::recPostorder(node *ptr)
{
    
    if(ptr)
    {
        recPostorder(ptr->left);
        recPostorder(ptr->right);
        cout<<ptr->item<<" ";
    }
}

void AVL::postorder()
{
    cout<<endl<<"Elements traversing in postorder way:"<<endl;
    recPostorder(root);
}



int max(int a,int b)
{
    return (a>b ? a:b);
}


int AVL::getHeight(node *ptr)
{
    if(ptr==NULL)
        return 0;

    return ptr->height;
}


node* AVL::minValueNode(node *ptr)
{
    node *current =ptr;
    /* loop down to find the least value node: 
    the one with the NULL pointer in the left*/
    while(current->left!=NULL)
        current = current->left;
    
    return current;
}


int AVL::getBalanceFactor(node *ptr)
{
    if(ptr==NULL)
        return 0;
    return getHeight(ptr->left)-getHeight(ptr->right);
}


void AVL::updateAnscestorsHeights(node *ptr,int data)
{
    if(data == ptr->item)
        ptr->height==1;
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
            ptr->height = max(getHeight(ptr->left),getHeight(ptr->right))+1;
        }
}



AVL::~AVL()
{
    while(root)
        del(root->item);
}

// int main()
// {
//     AVL a;
//     // cout<<endl<<a.getHeight();
//     return 0;
// }

int main()
{
    AVL tree;
    tree.insertElement(50);
    tree.insertElement(30);
    tree.insertElement(70);
    tree.insertElement(90);
    tree.insertElement(110);
    cout<<endl;
    tree.inorder();

    tree.del(110);
    cout<<endl;
    tree.inorder();

    cout<<endl;
    tree.del(10);
    tree.inorder();

    // cout<<endl<<getBalanceFactor(tree.root);
    return 0;
    

}