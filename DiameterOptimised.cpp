//  Traversals...

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



int Diameter(tnode* root)
{
 if(root==NULL)
  return 0;
 int height;
 
 return DiameterUtill(root,&height);
}




int Diameter2(tnode* root)
{
 if(root==NULL)
  return 0;
 
 int leftD,rightD,lh,rh;
 
 leftD=Diameter(root->left);
 rightD=Diameter(root->right); 
 lh=height(root->left); 
 rh=height(root->right);
 
return max(leftD,rightD,1+lh+rh);
}


int main()
{
 int wait;   
 tnode *root;
 root=createNode(3);
 root->left=createNode(1);
 root->right=createNode(5);
 root->left->left=createNode(2);
 root->left->right=createNode(7);
 root->left->left->left=createNode(8);
  root->left->left->left->left=createNode(11);
  root->left->right->right=createNode(9);
  root->left->right->right->right=createNode(10);
 //root->right->left=createNode(4);
 //   Desired Function Call....
 //preorder(root);
// printf("\n\n\n\n\n\n");
 cout<<"Diameter of the tree is "<<Diameter(root)<<endl;
 cin>>wait;
 return 0;
}



/*
         3
    1         5
      2     4

*/
