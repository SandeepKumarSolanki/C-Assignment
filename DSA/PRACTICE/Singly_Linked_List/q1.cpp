#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
      int data;
      Node *next;
};

class NodeOperation{
    public:
      
      //Function to add a new node
      void pushNode(class Node** head_ref,int data_value){

        //Allocate node
        class Node *new_node=new Node();

        //Put in the data
        new_node->data=data_value;

        //Link the old list of the new node
        new_node->next=*head_ref;

        //Move the head to point to the bew node
        *head_ref=new_node;
      }
};

int main()
{
    Node *head=NULL;
    NodeOperation *temp=new NodeOperation();
    for(int i=5;i>0;i--){
        temp->pushNode(&head,i);
    }
    vector<int>v;
    while(head!=NULL){
        v.push_back(head->data);
        head=head->next;
    }
    cout<<"Middle value of linked list is :";
    cout<<v[v.size()/2]<<endl;
    return 0;
}