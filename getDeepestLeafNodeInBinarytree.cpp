//   print the difference between odd Level and Even Level nodes in tree...
// 
//

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





void getDeep(tnode *root,tnode* (&ans),int level,int& maxlevel)
{
 if(root==NULL)
  return ;
 
 if(root->left==NULL  && root->right==NULL  && level>maxlevel)
 {
  maxlevel=level;
  ans=root;   //  assign this as current max level...
 }
 else
 {
  getDeep(root->left,ans,level+1,maxlevel);
  getDeep(root->right,ans,level+1,maxlevel);
 }
 
 return ;
}


tnode* getDeepestLeafNode(tnode *root)
{
 int maxLevel=0;
 tnode *ans;
 getDeep(root,ans,1,maxLevel);
 return ans;
}





int main()
{
 int wait;   
 tnode *root,*start;
 root=createNode(3);
 root->left=createNode(1);
 root->right=createNode(5);
 root->left->left=createNode(10);
 root->left->right=createNode(2);
 root->right->left=createNode(4);

 
 inorder(root);
 cout<<endl;
 start=getDeepestLeafNode(root);
 cout<<start->data<<endl;
 cout<<"Done..\n";
 cin>>wait;
 
 return 0;
}


