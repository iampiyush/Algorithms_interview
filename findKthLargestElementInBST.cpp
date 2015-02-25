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



void kLargestUtill(tnode* root,tnode* (&ans),int &count,int k)
{
 if(root==NULL)
  return ;
 
 kLargestUtill(root->right,ans,count,k); 
 
 if(count==k)
 {
  ans=root;
  count++;
 }
 else
 count++;
 kLargestUtill(root->left,ans,count,k);
}


tnode *kthLargest(tnode *root,int k)
{
 if(root==NULL)  //  condition check...
 {
  return NULL;
 }
 
 tnode *ans=NULL;
 int count=1;
 
 kLargestUtill(root,ans,count,k);
 
 return ans;
}


int main()
{
 int wait;   
 tnode *root,*start;
 root=createNode(5);
 root->left=createNode(3);
 root->right=createNode(7);
 root->left->left=createNode(2);
 root->left->right=createNode(4);
 root->right->left=createNode(6);
 root->right->right=createNode(8);
 
 int k;
 //inorder(root);
 //cout<<endl;
 
 cout<<"Enter k..."<<endl;
 cin>>k;
 start=kthLargest(root,k);
 if(start)
 cout<<k<<"th Largest Nodes value is "<<start->data<<endl;
 else
 cout<<"Less Number of nodes than k in tree..\n";
 
 cout<<"Done..\n";
 
 cin>>wait;
 
 return 0;
}


