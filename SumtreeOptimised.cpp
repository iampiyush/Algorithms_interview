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


bool SumTreeUtill(tnode *root,int *sum)
{
 if(root==NULL)
 {
  *sum=0;
  return true;
 }
 
 if(root->left==NULL  &&  root->right==NULL)
 {
  *sum=root->data;
  return true;
 }
 
 bool left,right;
 int leftSum=0,rightSum=0;
 
 left=SumTreeUtill(root->left,&leftSum);    //   Diameter of left Subtree with its height in parameter..
 right=SumTreeUtill(root->right,&rightSum);  //  Diameter of right Subtree with its height in parameter...
 
  *sum=leftSum+rightSum+root->data;

 return (leftSum+rightSum==root->data   &&  left  &&  right)  ; 
}



int SumTree(tnode* root)
{
 if(root==NULL)
  return true;
 int sum=0;
 
 return SumTreeUtill(root,&sum);
}






int main()
{
 int wait;   
 tnode *root;
 root=createNode(11);
 root->left=createNode(3);
 root->right=createNode(5);
 root->left->left=createNode(2);

 //root->right->left=createNode(4);
 //   Desired Function Call....
 //preorder(root);
// printf("\n\n\n\n\n\n");

if(SumTree(root)==true)
 cout<<"Given tree is Sum tree "<<endl;
else
cout<<"Given tree is not  Sum tree "<<endl;


 cin>>wait;
 return 0;
}



/*
         3
    1         5
      2     4

*/
