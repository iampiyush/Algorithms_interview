// comapre two linked list..

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<conio.h>
using namespace std;



typedef struct node
{
 int data;
 struct node *next;
};


typedef struct hl
{
  struct node *head;
  struct node* tail;
};


node* createNode(int);
node* createList();
void printList(node*);
int compare(node*,node*);
node *reverseK(node*,int);
node *breaklist(node*,int);
int CountNodes(node*);
node* reverse(node*);


void makeCircular(node *start)
{
 int count=0;
 node *mid;
 count=CountNodes(start);
 int i;
 
  i=0;
  cout<<"count is  "<<count<<endl;
 while(start->next)
  {
   if(i++==(count/2))
    mid=start;                
   start=start->next;
  }


  cout<<"Loop starting node  \n"<<mid->data<<endl;
  start->next=mid;

 return ;
}



node* detectLoop(node *start)
{
 node *slow,*fast;
 
 slow=start;
 fast=slow;
 
 while(fast!=NULL &&  fast->next!=NULL)
 {
   slow=slow->next;
   fast=fast->next->next;
   if(slow==fast || fast->next==slow)
   {
    cout<<"fast to data.."<<fast->data<<endl;
    return fast;
   }
  }

 return NULL;
}



int countCircularListNodes(node *start)
{
node *head;

head=start;

 int count=1;
 while(start->next!=head)
  {
  count++;
  start=start->next;
  }

 return count;
}


void detectAndRemove(node *start)
{
 if(start==NULL )
 {
  cout<<"Empty List..hence no loops..."<<endl;
  return ;
 }
 
 if(start->next==start ||  start->next==NULL)  //  remove loop from 1 list node...
 {
   start->next=NULL;
   return ;
 }
 node *tmp;
 tmp=detectLoop(start);
  
 if(tmp==NULL)
 {
  cout<<"No loop present..Nothing to do.."<<endl;
  return ;
 }
 
 int count=countCircularListNodes(tmp);   //  got loop length...???
  
  
  cout<<"Number of nodes in the loop..."<<count<<endl;
  node *a,*b;
  
  a=b=start;
  
  int i;
  for(i=1;i<count;i++)
  {
   a=a->next;
  }
  
  while(1)
  {
   if(a->next==b )   //  loop  removal...
    { 
     a->next=NULL;   
     break;
    }
   a=a->next;
   b=b->next;
  }
  
  
  cout<<"from function...\n"<<b->data<<endl;
  
  return ;
}


int main()
{
 node *temp,*head,*start,*list1,*list2;
 int i,k,state;
 //create List..
 //head=createList();
 
 cout<<"Enter List 1..\n";
 list1=createList();
 
 if(list1==NULL)
 {
  printf("Insufficient Memory...\n");
  return 0;
 }
 
 

 
 //print the linked list..
   printf("LIST 1...\n");
   printList(list1);
   
   cout<<"making list Circular \n";
   makeCircular(list1);    
  
 
  
   detectAndRemove(list1);
  
   printf("LIST 1...\n");
   printList(list1);
   

     

 cin>>state;
 return 0;
}



int CountNodes(node *start)
{
    
 int count=0;
 
 while(start)
 {
  count++;
  start=start->next;
 } 
  
 return count;
}



node* reverse(node* start)
{
 node *temp,*last,*head;
//   first go to last node...
 head=start;
 
 while(start->next!=NULL)
  start=start->next;
 
 last=start;
 start=head;
 
 while(start!=last)
 {
  temp=start->next;
  start->next=NULL;
  start->next=last->next;
  last->next=start;
  start=temp;
 }
 
 head=last;

 return head;
}



// function for creating the node..
node* createNode(int val)
{
 node* temp;
 temp=(node*)malloc(sizeof(struct node));  
 temp->data=val;   
 temp->next=NULL;
}


// function for creatting the list..
node* createList()
{
 node *start=NULL,*head=NULL;     
 char ch; 
 int value,i;    
 printf("Press y for adding a node or any other character for termination \n");
 scanf("%c",&ch);
 fflush(stdin);
 i=1;
 while(ch=='y')
 {
   value=(rand()%10)+1;   
    //cin>>value;          
    fflush(stdin);
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


