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



void swapData(tnode *a,tnode *b)
{
 int temp;
 
 temp=a->data;
 a->data=b->data;
 b->data=temp;

 return ;
}


int findSize(tnode *root)
{
 if(root==NULL)
  return 0;
  
  return 1+findSize(root->left)+findSize(root->right);

}



void modifiedInorder(tnode *root,int &count,int considered,tnode* &orderNode,tnode* &minNode)
{
 if(root==NULL)
  return ;
  
 modifiedInorder(root->left,count,considered,orderNode,minNode); 
 
 count++;
 if(count==considered+1)
 {
  orderNode=root;
  minNode=root;
 }
 else if(count>considered+1   && root->data  <  minNode->data )
 {
  minNode=root;
 }
 //   else   do not consider this element...
 
 modifiedInorder(root->right,count,considered,orderNode,minNode);

 return ;
}




void convertBTToBST(tnode *root)
{
 if(root==NULL   ||  (root->left==NULL  &&  root->right==NULL))
  return ;
 
 int size;
 int i;
 int count;
 tnode *minNode=NULL;
 tnode *orderNode=NULL;
 
 size=findSize(root);

 for(i=0;i<size-1;i++)
 {
  count=0;
  modifiedInorder(root,count,i,orderNode,minNode);
  
  swapData(minNode,orderNode);
 }
 
 //  Done..
  
  return ; 
}





int main()
{
 int wait;   
 tnode *root;
 root=createNode(2);
 root->left=createNode(4);
 root->right=createNode(1);
 root->left->left=createNode(5);
 root->left->right=createNode(3);
 root->right->left=createNode(7);
 root->right->right=createNode(0);


 inorder(root);
 

 convertBTToBST(root);
 

 cout<<"NEW TREE Inorder"<<endl; 
 inorder(root);
 
   
 cin>>wait;
 return 0;
}


