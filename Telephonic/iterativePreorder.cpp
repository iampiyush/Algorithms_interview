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




int Diameter2(tnode* root)
{
 if(root==NULL)
  return 0;
 
 int leftD,rightD,lh,rh;
 
 leftD=Diameter2(root->left);
 rightD=Diameter2(root->right); 
 lh=height(root->left); 
 rh=height(root->right);
 
return max(leftD,rightD,1+lh+rh);
}



void iterativePreorder(tnode *root)
{
 if(root==NULL)
  return ;
 
 stack<tnode*> s;
 
 while(1)
 {
   if(root)
   {
    cout<<root->data<<" "; 
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
    root=root->right;
   }
 }
  //  end of infinite while loop 
 return ;
}



int main()
{
 int wait;   
 tnode *root;
 root=createNode(5);
 root->left=createNode(3);
 root->left->left=createNode(2);
 root->right=createNode(8);
 root->left->right=createNode(4);
 root->right->left=createNode(6);
 root->right->right=createNode(10);

 
 iterativePreorder(root);
   
 cin>>wait;
 return 0;
}


