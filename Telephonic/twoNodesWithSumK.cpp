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




void iterativeInorder(tnode *root)
{
 if(root==NULL)
  return ;
 
 stack<tnode*> s;
 
 while(1)
 {
   if(root)
   {
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
    cout<<root->data<<" ";  
    root=root->right;
   }
 }
  //  end of infinite while loop 
 return ;
}



void iterativeReverseInorder(tnode *root)
{
 if(root==NULL)
  return ;
 
 stack<tnode*> s;
 
 while(1)
 {
   if(root)
   {
    s.push(root);
    root=root->right;
   }
   else
   {
    if(s.size()==0)
     return ;
    //cout<<s.top()<<" ";  
    root=s.top();   //  pop node...
    s.pop();
    cout<<root->data<<" ";  
    root=root->left;
   }
 }
  //  end of infinite while loop 
 return ;
}




bool checkSum(tnode *root,int k)
{
 if(root==NULL  &&  k==0)
  return true;
 if(root==NULL)
  return false;
 
 int x=0,y=0;
 bool done1=false;
 bool done2=false;
 tnode *first=NULL;
 tnode *second=NULL;
 
 stack<tnode*> s1,s2;
 
 
 first=second=root;
 while(1)
 {
 //   inorder..
 
 while(done1==false)
 {
   if(first)
   {
    s1.push(first);
    first=first->left;
   }
   
   else
   {
    
    if(s1.size()==0)
    {
     //   do something...will decide later..
     done1=true;
    } 
    else
    {
     first=s1.top();
     s1.pop();
     x=first->data;
     first=first->right;
     done1=true;
    }   
    
   }
 
 
 }
 
 //   now reverseInorder 
 
 while(done2==false)
 {
   if(second)
   {
    s2.push(second);
    second=second->right;
   }
   
   else
   {
    
    if(s2.size()==0)
    {
     //   do something...will decide later..
     done2=true;
    } 
    else
    {
     second=s2.top();
     s2.pop();
     y=second->data;
     second=second->left;
     done2=true;
    }   
    
   }
 
 
 }
 
 //   now moving decision...
 //  now check for stack empty condition...
 
 
  if(x!=y &&  x+y==k)   //   found both nodes
  {
   cout<<x<<" "<<y<<endl;
   //done1=false;
 //  done2=false;
   return true;
  }
  else if(x+y<k)
   done1=false;
  else if(x+y>k)
   done2=false;

 
  if(x>=y) 
   return false;
   
 }   //   end of infinite while
  
   

   return false;
}



int main()
{
 int wait;   
 tnode *root;
 bool state;
 int k;
 root=createNode(5);
 root->left=createNode(3);
 root->right=createNode(8);
 root->left->left=createNode(2);
 root->left->right=createNode(4);
 root->right->left=createNode(6);
 root->right->right=createNode(10);

 cout<<"Enter Sum K "<<endl;
 cin>>k;
 state=checkSum(root,k);
 
 if(state==true)
  cout<<"Sum present..\n";
 else
  cout<<"Sum not Present.\n";  
   
 cin>>wait;
 return 0;
}


