//   connect leaves of the binary tree into doubly linked list..in place...


#include<iostream>
#include<queue>
using namespace std;



typedef struct tnode
{
 int data;
 struct tnode *left;
 struct tnode *right;
};



tnode* createNode(int num)
{
 tnode *temp;
 temp=(tnode*)malloc(sizeof(tnode));
 temp->data=num;
 temp->left=NULL;
 temp->right=NULL;
 return temp;
}



int minimum(int a,int b)
{
 if(a<b)
  return a;
 else
  return b; 
}




int height(tnode *root)
{
 if(root==NULL)
  return 0;
  
int lheight,rheight;
lheight=height(root->left);  
rheight=height(root->right); 

if(lheight>rheight)
 return (lheight+1);
else
 return (rheight+1);
 }





int minDepth(tnode *root)
{
 if(root==NULL)
  return 0;
 
 if(root->left!=NULL  &&  root->right !=NULL)
 {
  return 1+minimum(minDepth(root->left),minDepth(root->right));
 } 
 
 return 1+minDepth(root->left)+minDepth(root->right);
}



void preorder(tnode *root)
{
 if(root==NULL)
  return ;
  
 cout<<root->data<<endl;
 preorder(root->left);
 preorder(root->right);  
}


tnode* findRight(tnode *root,tnode *x)
{
 if(root==NULL ||  root==x)
  return NULL;
 tnode *ans=NULL,*temp=NULL;
 tnode *dummy=createNode(100);
 int i,flag;
 queue<tnode*> myqueue;
 myqueue.push(root);
 
 cout<<"Level 1\n";
 i=2;flag=0;
 myqueue.push(dummy);
 
 while(myqueue.empty()==false)
 {
   temp=myqueue.front();
   myqueue.pop();
   
   if(temp==dummy)
   {
     flag=0;
     if(myqueue.empty()==false)
     {
      myqueue.push(dummy);   
     // cout<<"\nLevel "<<i++<<endl; 
     }
    
   }
   else
   {
  // cout<<temp->data<<" ";
   if(flag==1)
   {
    ans=temp;
    flag=0;
   }
   if(temp==x)
   {
    flag=1;
   }
   
   if(temp->left!=NULL)
    myqueue.push(root->left);
   if(temp->right!=NULL) 
    myqueue.push(temp->right);
   }
   
 } 


 return ans;
}



int main()
{
 int wait;   
 int min,max; 
 tnode *root;
 tnode *head;
 
 
 root=createNode(5);
 root->left=createNode(3);
 root->right=createNode(7);
 root->left->right=createNode(4);
 root->left->left=createNode(1);
 //root->right->left=createNode(6);
 
 head=findRight(root, root->left->left);
 if(head)
 cout<<"\nRight Node is "<<head->data<<endl;
 else
  cout<<"No right node exists...\n";
  
 cin>>wait;
 return 0;
}
