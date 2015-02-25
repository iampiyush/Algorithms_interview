// Detect loop in the link list...
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;


typedef struct node
{
 int data;
 struct node *next;
 struct node *prev;
};


node* createNode(int);
node* createList();
void printList(node*);
int getCount(node*);
int detectLoop(node*);
node* getKthNode(node*,int);


void reverseDLL(node **head)
{
 if((*head)==NULL  ||  (*head)->next==NULL)
  return ;    
 
 node *temp=NULL;
 node *prev=NULL;
 node *start=*head;
  
  
 while(start)
 {
  temp=start->next;
  start->next=start->prev;
  start->prev=temp;
  prev=start;
  start=temp;
 }


 *head=prev;
 //  update head pointer..
 
 return ;
}



int main()
{
 node *temp,*start,*list1;
 int i,k,state,len;
 //create List..
 //head=createList();
 list1=createList();
 if(list1==NULL)
 {
  printf("Insufficient Memory...\n");
  return 0;
 }
 start=list1;

 
 //print the linked list..
  printList(start);
  // now create Loop...
   reverseDLL(&start);
   
   cout<<"Now reverse the linked list..\n";
   printList(start);
   
 // printf("%d\n",temp->data);
  
  getch();
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
 temp->prev=NULL;
 return temp;
}


// function for creatting the list..
node* createList()
{
 node *start=NULL,*head=NULL;     
 node *temp=NULL;
 char ch; 
 int value;    
 printf("Press y for adding a node or any other character for termination \n");
 scanf("%c",&ch);
 fflush(stdin);
 while(ch=='y')
 {
  value=(rand()%10)+1;             
  if(start==NULL)
  {              
   start=createNode(value);
   head=start;
  }
  else
  {
   temp=createNode(value);
   start->next=temp;   
   temp->prev=start;
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
 node *head=NULL,*prev;
 head=start;
 
 while(start)
 {
  printf("%d ",start->data);
  prev=start;
  start=start->next;
 }

  printf("\n");

  while(prev)
 {
  printf("%d ",prev->data);
 // prev=start;
  prev=prev->prev;
}

 printf("\n");
}
