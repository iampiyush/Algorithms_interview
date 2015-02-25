//   Ceil and Floor Of BST

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





int Max(int a,int b)
{
if(a>b)
 return a;
else
 return b; 
}

tnode *pruneTreeUtill(tnode *root,int k,int *sum)
{
 if(root==NULL)
  return NULL;
  
  int lsum,rsum;
  
  lsum=(root->data)+(*sum);
  rsum=(root->data)+(*sum);
  
  //  go to left..and ...right...
  root->left=pruneTreeUtill(root->left,k,&lsum);
  root->right=pruneTreeUtill(root->right,k,&rsum);
 
  *sum=Max(lsum,rsum);
 
  if(k> (*sum))
  {
   free(root);
   return NULL;
  }
  

  return root;

}


void pruneTree(tnode *root,int k)
{
 if(root==NULL)
  return ;
  
  int sum=0;
  
  pruneTreeUtill(root,k,&sum);
 
  return ;

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
 
 
 inorder(root);
 cout<<"Enter The Value Of k..\n";
 cin>>k;

 pruneTree(root,k);
 inorder(root);

 cin>>wait;
 return 0;
}


