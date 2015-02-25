
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
node *reverse(node*);



int main()
{
 node *temp,*head,*start,*list1,*list2;
 int i,k,state,len;
 int t;
 //create List..
 //head=createList();
 cout<<"Number of test cases..\n";
 cin>>t;
 
 while(t--)
 {
  list1=createList();
  start=list1; 
 //print the linked list..
  printList(start);
  start=reverse(start);
  printList(start);
  cout<<"\n\n\n  Time  For New List.. \n\n";
}

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


node* reverse(node *start)
{
 if(start==NULL ||start->next==NULL)
  return start;
 
  
 /*
 //  for two nodes linked list only...
 if(start->next->next==NULL)
 {
  node *temp;                          
  temp=start;
  start=start->next;
  temp->next=NULL;
  start->next=temp;
  return start;
 }  
 */
 
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

