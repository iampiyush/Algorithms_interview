// Detect loop in the link list...

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
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




//  sort link list of 0,1,2...in one pass..
void sort(node **head)
{
 if((*head)==NULL  ||  (*head)->next==NULL)
   return ;
 
 node *start=NULL;
 node *temp=NULL;
 node *cur=NULL;
 node *prev=NULL;
 node *zeroList=NULL,*oneList=NULL,*twoList=NULL;
 node *ar[5];
 
 start=*head;
 
 
 ar[0]=ar[1]=ar[2]=NULL;
 
 while(start)
 {
  temp=start;
  start=start->next;
  temp->next=NULL;
 
  if(temp->data==0)
  {
   if(zeroList==NULL)
   {
     zeroList=temp;
     (*head)=zeroList;
     ar[0]=zeroList;
   }
   else
   {
    zeroList->next=temp;
    zeroList=zeroList->next;
   } 
  
  }
  else if(temp->data == 1)
  {
   if(oneList==NULL)
   {
     oneList=temp;
     ar[1]=oneList;
   }
   else
   {
    oneList->next=temp;
    oneList=oneList->next;
   } 
  }
  else
  {
    if(twoList==NULL)
   {
     twoList=temp;
     ar[2]=twoList;
   }
   else
   {
    twoList->next=temp;
    twoList=twoList->next;
   }  
  }
 
 }   //  end of while loop...time 
 // to connect this lists...
 
 
 ///   u suck...
// if(zeroList)


 if(zeroList)
 {
  (*head)=ar[0];
  
   if(oneList)
   { 
    zeroList->next=ar[1];
    oneList->next=ar[2]; 
   }
   else
   {
    zeroList->next=ar[2];
   }
  }
 else if(oneList)
 {
  (*head)=ar[1];
   oneList->next=ar[2];
 }
 else
 {
  *head=ar[2];
 }

 


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
  sort(&start);
  printList(start);
  //printf("%d\n",temp->data);
  
  getch();
  return 0;
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
 time_t t;
 srand((unsigned) time(&t)); 
 printf("Press y for adding a node or any other character for termination \n");
 scanf("%c",&ch);
 fflush(stdin);
 while(ch=='y')
 {
   value=(rand()%3);             
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
