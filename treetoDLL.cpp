//  Convert a Binary tree into doubly linked list...
//  In the changed list..
//   left pointer correspond to prev pointer...
//   right pointer correspond to next pointer..

/*
  Algorithm..
  
  first take left subtree..convert it into DLL
  then
  take right subtree... convert this into DLL...
   now merge both trees...with root node...
   
   
   left=f(root->left);
   right=f(root->right);
   //now merge left right,and root somehow....
   
*/
#include<iostream>
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


void inorder(tnode *root)
{
 if(root==NULL)
  return ;
 inorder(root->left);
 cout<<root->data<<" ";
 inorder(root->right); 
}



void preorder(tnode *root)
{
 if(root==NULL)
  return ;
 cout<<root->data<<" "; 
 preorder(root->left);
 preorder(root->right); 
}



void postorder(tnode *root)
{
 if(root==NULL)
  return ;
 postorder(root->left);
 postorder(root->right); 
 cout<<root->data<<" ";
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



int max(int a,int b,int c)
{
 if(a>=b && a>=c)
  return a;
 if(b>=c && b>=a)
  return b;
if(c>=a && c>=b)
 return c;
}


int DiameterUtill(tnode *root,int *height)
{
 if(root==NULL)
 {
  *height=0;
   return 0;
 }
 
 int leftHeight=0,rightHeight,leftDia,rightDia;
 
 leftDia=DiameterUtill(root->left,&leftHeight);    //   Diameter of left Subtree with its height in parameter..
 rightDia=DiameterUtill(root->right,&rightHeight);  //  Diameter of right Subtree with its height in parameter...

 *height=max(leftHeight,rightHeight,0)+1;

 return max(leftDia,rightDia,1+leftHeight+rightHeight);
}




bool checkBalancedUtill(tnode *root,int *height)
{
 if(root==NULL)
 {
  *height=0;
   return true;
 }

 int leftHeight=0,rightHeight=0;
 bool left,right;
 
 left=checkBalancedUtill(root->left,&leftHeight);
 right=checkBalancedUtill(root->right,&rightHeight);
 
  *height=max(leftHeight,rightHeight,0)+1;
 
  return ( abs(leftHeight-rightHeight)<=1  &&  left  &&  right );
  
}



bool checkBalanced(tnode* root)
{
 if(root==NULL)
  return true;
  
 int height=0;  

 return checkBalancedUtill(root,&height);
}




bool checkBalanced2(tnode* root)
{
 if(root==NULL)
  return true;

 int leftHeight=0,rightHeight=0;
 
 leftHeight=height(root->left);    //  inefficient step...
 rightHeight=height(root->right);  //  inefficient step again..
 
 return  ( abs(leftHeight-rightHeight)<=1  &&  checkBalanced2(root->left)  &&  checkBalanced2(root->right) );
}


void printTreeList(tnode *root)
{
 if(!root)
 {
  cout<<"Empty List..Nothing to print mate..\n";
  return ;
 }
 
 tnode *start;
 start=root;
 while(root->right)
 {
  cout<<root->data<<" ";
  root=root->right;
 }  
 
 cout<<root->data<<endl;
 
 while(root)
 {
   cout<<root->data<<" ";
   root=root->left;
 }
 
 cout<<endl; 

 return ;
}



tnode* toDLL(tnode *root)
{ 
 if(root==NULL)
  return NULL;
 
 tnode *left=NULL,*right=NULL;
 tnode *start;
 
 left=toDLL(root->left);
 right=toDLL(root->right);
 
 if(left==NULL) 
 {
  start=root;
  left=root;
  start->left=NULL;
 }
 else
 {
  start=left;
  while(left->right)
   left=left->right;
  
  left->right=root; 
  root->left=left;
  left=left->right;
 }
 //   left subtree and root  merged into DLL...

 //  now add list1(left+root DLL) and list2(right DLL).... 
  if(right==NULL)
  {
   left->right=NULL;
  }
  else
  {
   left->right=right; 
   right->left=left;
  }
  
  return start;
}



tnode *toDLLaux(tnode* root)
{
 if(root==NULL)
  return NULL;

 tnode *start,*head;
 head=toDLL(root); 
   return head;

 if(!head)
  return NULL;
 
 start=head;
 while(start->right)
  start=start->right;
 
  start->right=head;
  head->left=start;
 
 return head;
}




int main()
{
 int wait;   
 tnode *root,*start;
 root=createNode(3);
 root->left=createNode(1);
 //root->right=createNode(5);
 root->left->right=createNode(2);
 root->left->left=createNode(10);
 //root->right->left=createNode(4);

 
 inorder(root);
 cout<<endl;
 start=toDLLaux(root);
 printTreeList(start);  
 cout<<"Done..\n";
 cin>>wait;
 return 0;
}


