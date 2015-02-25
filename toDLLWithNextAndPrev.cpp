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
 struct tnode *prev;
 struct tnode *next;
};


tnode* createNode(int num)
{
 tnode *temp;
 temp=(tnode*)malloc(sizeof(tnode));
 temp->data=num;
 temp->left=NULL;
 temp->right=NULL;
 temp->prev=NULL;
 temp->next=NULL;
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



tnode* toDLL(tnode* root)
{
 if(root==NULL)
  return NULL;
 
 tnode* left=NULL;
 tnode* right=NULL;
 tnode *tmp=NULL;
 
 left=toDLL(root->left);
 right=toDLL(root->right);
 
// now merge this
  
  //  first merge root and left..
  if(left==NULL)
  {
   left=root;
   root->prev=NULL;
   tmp=left;
  } 
  else
  {
   tmp=left;
   while(left->next)
    left=left->next;
    
   
   left->next=root; 
   root->prev=left;
   left=left->next;
  }

  //   merge left and right now...
  
   if(right==NULL)
   {
    left->next=NULL;
   }
   else
   {
    left->next=right;
    right->prev=left;
   }


  left=tmp;
  
  
  return left;
}

void printList(tnode *root)
{
 if(root==NULL)
   return ;
   
   tnode *start;
   start=root;
   
   while(start)
   {
    cout<<start->data<<"  ";            
    start=start->next;
   }

 cout<<endl;
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
// root->right->left=createNode(6);
// root->right->right=createNode(8);
 
 int k;
 //inorder(root);
 //cout<<endl;
 

 start=toDLL(root);
 if(start)
{
 cout<<"List is  \n"<<endl;
 printList(start);
} 
 else
 cout<<"Empty Tree..\n";
 
 cout<<"Done..\n";
 
 cin>>wait;
 
 return 0;
}


