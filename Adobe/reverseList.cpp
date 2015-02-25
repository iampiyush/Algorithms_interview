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





node *reverseList(node *start)
{
 if(start ==NULL  || start->next ==NULL )
  return start;

 node *ans=NULL;
 
 ans=reverseList(start->next); 
 
 start->next->next=start;
 start->next=NULL;  
 
 return ans; 
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
   
    list1=reverseList(list1);   
  
   
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


node *breaklist(node *start,int k)
{
 node *x;
 int i;
 
 for(i=1;i<k;i++)
  start=start->next;

  x=start;
  start=start->next;
  x->next=NULL;
  
 return start;
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
   //value=(rand()%10)+1;   
    cin>>value;          
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


