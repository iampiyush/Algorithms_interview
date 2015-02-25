// Detect loop in the link list...

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<stack>
using namespace std;




typedef struct node
{
 char data;
 struct node *next;
 struct node* prev;
};


node* createNode();
node* createList();
void printList(node*);
int findSize(node *start);
node* reverse(node *start);


node* reverseDLL(node *start)
{ 
  if(start==NULL)
   return start;
 
  node *temp;
  
  while(start->next)
  {
   temp=start->next;
   start->next=start->prev;
   start->prev=temp;
   start=temp; 
  }      
  
  start->next=start->prev;
  start->prev=NULL;
 
  return start;
}


int main()
{
 node *temp,*head,*start,*list1,*list2;
 int i,k,state,len;
 //create List..
 //head=createList();
 start=createList();

 
 //print the linked list..
  printList(start);
  // now create Loop...
 
 // reverseinKSize(start,k);

   start=reverseDLL(start);

   printList(start);
  
 // printList(start);
  //deleteList(list1);
 
 getch();
 return 0;
}



int getCount(node *start)
{
 int count=0;
 
 while(start!=NULL)
 {
  count++;
  start=start->next;
 }
  return count;
}



// function for creating the node..
node* createNode(char val)
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
 char ch; 
 char value;    
 printf("Press y for adding a node or any other character for termination \n");
 scanf("%c",&ch);
 fflush(stdin);
 while(ch=='y')
 {
   scanf("%c",&value);  
   fflush(stdin);              
           
  if(start==NULL)
  {              
   start=createNode(value);
   head=start;
  }
  else
  {
   start->next=createNode(value);
   start->next->prev=start;
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
  printf("%c ",start->data);
  start=start->next;
 }

 printf("\n");
}




node* reverse(node *start)
{
 if(start==NULL ||start->next==NULL)
  return start;

 node *prev,*cur,*next;
 
 //  the 3 pointer method...
 prev=NULL;
 cur=start;
 next=start->next;
 while(cur!=NULL)
 {
  cur->next=prev;
  prev=cur;
  cur=next;
  if(next)
  next=next->next;
 }//  sufficient????
 
 start=prev;
 
 return start;
}


int findSize(node *start)
{ 
 int count=0;
 
 while(start)
 {
  count++;
  start=start->next;           
 } 

 return count;
}



