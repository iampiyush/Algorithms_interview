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


typedef struct node
{
 int data;
 struct node *next;
};


node* createNode(int);
node* createList();
void printList(node*);
int getCount(node*);
int detectLoop(node*);
node* getKthNode(node*,int);






tnode* createNodeT(int num)
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



void reverseInorder(tnode *root)
{
 if(root==NULL)
  return ;

  reverseInorder(root->right); 
  cout<<root->data<<endl;
  reverseInorder(root->left);
  
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




int countNodes(node *start)
{
  int count=0;
  
  while(start)
  {
   count++;
   start=start->next;
  }    

  return count;
}



tnode *LinkedListtoBST(node **head,int n)
{
 if(n<=0)
   return NULL;
 
   tnode *left=NULL;
 
   left=LinkedListtoBST(head,n/2);   //   recur to left subtree first...
 
   tnode *root=createNodeT((*head)->data);
   
   root->left=left;
   *head=(*head)->next ;  //   move to next  node...
   
   root->right=LinkedListtoBST(head,n-n/2-1);
   
  return root;
}




int main()
{
 int wait;   
 node *temp,*start,*list1;
 int i,k,state,len,n;
 tnode *root=NULL;
 //create List..
 //head=createList();
 list1=createList();
 if(list1==NULL)
 {
  printf("Insufficient Memory...\n");
  return 0;
 }
   start=list1;

   printList(list1);
   n=countNodes(start);
   root=LinkedListtoBST(&start,n);
  
   cout<<"Inorder traversal of Tree.\n";
   inorder(root);
   
  cout<<"Preorder traversal of Tree.\n";
   preorder(root);
 
 
 cin>>wait;
 return 0;
}





node* getKthNode(node *start,int k)
{
 node *temp;
 temp=start;
 int count=0;
 
 while(start && count<k)
 {
  start=start->next;
  count++ ;
 }

   while(start!=NULL)
   {
    temp=temp->next;
    start=start->next;
   }



   return temp;
}




// function for creating the node..
node* createNode(int val)
{
 node* temp;
 temp=(node*)malloc(sizeof(struct node));  
 temp->data=val;   
 temp->next=NULL;
 return temp;
}


// function for creatting the list..
node* createList()
{
 node *start=NULL,*head=NULL;     
 char ch; 
 int value;    
 printf("Press y for adding a node or any other character for termination \n");
 scanf("%c",&ch);
 fflush(stdin);
 value=1;
 while(ch=='y')
 {
  // value=(rand()%10)+1;             
  if(start==NULL)
  {              
   start=createNode(value);
   head=start;
  }
  else
  {
   start->next=createNode(value);
   start=start->next;
  }
  printf("Press y for adding a node or any other character for termination \n");
  scanf("%c",&ch);
  fflush(stdin);
  value++;
 }
 
 return head;
}



//iterative method to print the list..
void printList(node *start)
{    
 if(!start)
 {
  printf("List is Empty..\n");
 }
 node *head;
 head=start;
 
 while(start)
 {
  printf("%d ",start->data);
  start=start->next;
 }

 printf("\n");
}




