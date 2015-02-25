//  Traversals...

#include<iostream>
#include<stack>
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


void inorder(tnode *root)
{
 if(root==NULL)
  return ;
 inorder(root->left);
 cout<<root->data<<endl;
 inorder(root->right); 
}



void preorder(tnode *root)
{
 if(root==NULL)
  return ;
 cout<<root->data<<endl; 
 preorder(root->left);
 preorder(root->right); 
}



void postorder(tnode *root)
{
 if(root==NULL)
  return ;
 postorder(root->left);
 postorder(root->right); 
 cout<<root->data<<endl;
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




void iterativeInorder(tnode *root)
{
 if(root==NULL)
  return ;
 
 stack<tnode*> s;
 
 while(1)
 {
   if(root)
   {
    s.push(root);
    root=root->left;
   }
   else
   {
    if(s.size()==0)
     return ;
    //cout<<s.top()<<" ";  
    root=s.top();   //  pop node...
    s.pop();
    cout<<root->data<<" ";  
    root=root->right;
   }
 }
  //  end of infinite while loop 
 return ;
}



void iterativeReverseInorder(tnode *root)
{
 if(root==NULL)
  return ;
 
 stack<tnode*> s;
 
 while(1)
 {
   if(root)
   {
    s.push(root);
    root=root->right;
   }
   else
   {
    if(s.size()==0)
     return ;
    //cout<<s.top()<<" ";  
    root=s.top();   //  pop node...
    s.pop();
    cout<<root->data<<" ";  
    root=root->left;
   }
 }
  //  end of infinite while loop 
 return ;
}

int countMatches(tnode *root,tnode *p,tnode *q)
{
 if(root==NULL)
  return 0;
 if(root==p  ||  root==q)
  return 1+countMatches(root->left,p,q)+countMatches(root->right,p,q);
 else
  return  countMatches(root->left,p,q)+countMatches(root->right,p,q);
}




tnode *LCAOptimised(tnode *root,tnode *p,tnode *q)
{
 //  base case...
 if(root==NULL  ||  p==NULL  ||  q==NULL )
  return NULL;

 if(root==p  ||  root == q)
  return root;
//  else  ...
 tnode *l=NULL,*r=NULL;

 l=LCAOptimised(root->left,p,q);
 r=LCAOptimised(root->right,p,q);

 if(l &&  r)
  return root;
 
 if(l!=NULL)
  return l;
 else
  return r;
   
}







tnode *LCA(tnode *root,tnode *p,tnode *q)
{
 //  base case...
 if(root==NULL  ||  p==NULL  ||  q==NULL )
  return NULL;

 if(root==p  ||  root == q)
  return root;
//  else  ...
int match;

match=countMatches(root->left,p,q);
if(match==1)
 return root;  
else if(match==0)
 return LCA(root->right,p,q);
else
 return LCA(root->left,p,q);  
 
}


int main()
{
 int wait;   
 tnode *root=NULL;
 tnode *temp=NULL;
 bool state;
 int k;
 root=createNode(5);
 root->left=createNode(3);
 root->right=createNode(8);
 root->left->left=createNode(2);
 root->left->right=createNode(4);
 root->right->left=createNode(6);
 root->right->right=createNode(10);

 tnode *p=NULL,*q=NULL;
 
 p=root->right->right;
 q= root->right->left;
 temp=LCA(root,p,q);
 if(temp)
 cout<<"LCA is "<<temp->data<<endl; 
 else
 cout<<"Nodes are Not present in tree..\n";  
 cin>>wait;
 return 0;
}


