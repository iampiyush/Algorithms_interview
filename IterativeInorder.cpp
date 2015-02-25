//  Traversals...

#include<iostream>
#include<stack>
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



void IterativePreorder(tnode *root)
{
 if(root==NULL)
  return;


 stack<tnode*> mystack; 
 bool done=false;
 
 while(done==false)
 {
  if(root!=NULL)
  {
   cout<<root->data<<" ";
   mystack.push(root);
   root=root->left;
  }
  else
  {
   if(mystack.empty()==true)
    done=true;
   else
   {
    root=mystack.top();
    mystack.pop();
    root=root->right;
   } 
  
  }
 }  





 return ;
}



void IterativeInorder(tnode *root)
{
 if(root==NULL)
  return ;
 
 bool done=false;
 stack<tnode*> mystack;
 
 
 
 //    while not done...  i.e there is more elements to be visited...
 while(done==false)
 {
  if(root!=NULL)
  {
   mystack.push(root); 
   root=root->left;
  }
  else
  {
   if(mystack.empty()==true)
    done=true;
   else
   {
    root=mystack.top();
    mystack.pop();
    cout<<root->data<<" ";
    root=root->right;
   } 
   
  }
 }
 //  end of while loop...  
  
  return ;
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




int main()
{
 int wait;   
 tnode *root;
 root=createNode(3);
 root->left=createNode(1);
 root->right=createNode(5);
 root->left->right=createNode(2);
 root->left->left=createNode(10);
 root->right->left=createNode(4);
 //   Desired Function Call....
// IterativeInorder(root);
 IterativePreorder(root);
 cin>>wait;
 return 0;
}



/*
         3
    1         5
      2     4

*/
