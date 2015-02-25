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
};


node* createNode();
node* createList();
void printList(node*);
int getCount(node*);
int detectLoop(node*);
node* getKthNode(node*,int);



void rotateList(node **head,int k)
{

 if((*head)==NULL  ||  (*head)->next==NULL)
  return ;
 node *start=NULL;
 node *newHead=NULL;
 

 start=*head; 
 int i;
 for(i=0;((i<k-1) && (start));i++)
  start=start->next;
  
 if(start==NULL)
 {
  cout<<"Less Nodes in the list than K...\n";
  return ;
 } 
 
 newHead=start->next;
 start->next=NULL; 
 start=newHead;
 //start=start->next;
 
  if(start==NULL)
 {
  cout<<"K is equal to the List Size so..nothing is required..\n";
  return ;
 } 
 
 
 while(start->next)
  start=start->next;
 
 start->next=*head;
 *head=newHead; 
  
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
  printList(list1);
  // now create Loop...
  cout<<"Enter Value of k..\n"; 
  scanf("%d",&k);
  rotateList(&start,k);
  printList(start);
  //printf("%d\n",temp->data);
  
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
