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


int max(int a,int b,int c)
{
 if(a>=b && a>=c)
  return a;
 if(b>=c && b>=a)
  return b;
if(c>=a && c>=b)
 return c;
}



int min(int a,int b,int c)
{
 if(a<=b && a<=c)
  return a;
 if(b<=c && b<=a)
  return b;
if(c<=a && c<=b)
 return c;
}




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



//   Spiral order traversal...
void levelOrderUtill(tnode *root,int level,bool state)
{
 if(root==NULL  ||  level<1)
  return ;
 
 if(level==1)
  cout<<root->data<<" ";
 
 if(state==true)
 { 
  levelOrderUtill(root->left,level-1,state);
  levelOrderUtill(root->right,level-1,state); 
 }
 else
 {
 levelOrderUtill(root->right,level-1,state);  
 levelOrderUtill(root->left,level-1,state);
 }

 return ; 
}


void levelOrder(tnode *root)
{
 if(root==NULL)
  return ;    
 int h;
 int i;
 h=height(root);
 bool state=false;
 for(i=0;i<h;i++)
{
  cout<<"Level "<<i+1<<" \n";
  levelOrderUtill(root,i+1,state);
  state=!state;
  cout<<endl;
}  
}


void spiral(tnode *root)
{
 if(root==NULL)
  return ;
 stack<tnode*> s1,s2;
 tnode *temp;
 s1.push(root);
 
 while(1)
 {
  //  while s1 is not empty...       
  while(s1.size()!=0)
  {
   temp=s1.top();
   s1.pop();
   cout<<temp->data<<" ";
   if(temp->left)
    s2.push(temp->left);
   if(temp->right)
    s2.push(temp->right);
  }
  //  s1 is now empty..go for s2...
  cout<<endl;
  while(s2.size()!=0)
  {
   temp=s2.top();
   s2.pop();
   cout<<temp->data<<" ";
    if(temp->left)
     s1.push(temp->left);
    if(temp->right)
     s1.push(temp->right);
  
  } 
 
  if(s1.empty()==true   &&  s2.empty()==true)
   return ;
 
 cout<<endl;
 }
 

}



int main()
{
 int wait;   
 tnode *root;
 root=createNode(5);
 root->left=createNode(3);
 root->right=createNode(8);
 root->left->left=createNode(2);
 root->left->right=createNode(4);
 root->right->left=createNode(6);
 root->right->right=createNode(10);

 
spiral(root);
   
 cin>>wait;
 return 0;
}


