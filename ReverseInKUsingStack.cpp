// Detect loop in the link list...

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<stack>
using namespace std;




typedef struct node
{
 int data;
 struct node *next;
};


node* createNode();

node* createList();
void printList(node*);



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



node* recursiveReverse(node *start,int k)
{
 if(k<2)
  return start;
  
 int i;
 node *head,*temp;
 head=start;
 //temp=start;
 for(i=0;i<k;i++)
 {
  if(start==NULL)
   return head;
  temp=start;
  start=start->next;
 }
 
 temp->next=NULL;
 temp=reverse(head);
 
 head->next=recursiveReverse(start,k); 
 return temp;
}



void reverseinKSize(node *start,int k)
{
 if(start==NULL)
  return ;
  
 stack<int> mystack;
 node *head,*temp; 
 int size;
 int iter;
 int i,j;
 
 size=findSize(start);
 iter=size/k;
 
 head=start;
 
 
 for(i=0;i<iter;i++)  
 {
  temp=start;       
  
  //   loop 1 for pushing in stack...             
  for(j=0;j<k;j++)
  {
   mystack.push(start->data);
   start=start->next; 
  }
  
  //  loop 2 for popping out from the stack....hence reversing in k size...
  for(j=0;j<k;j++)
  {
    temp->data=mystack.top();
    mystack.pop();
    temp=temp->next;
  }
 
 }
 
 //  done.. 
 
   return ;
}



int main()
{
 node *temp,*head,*start,*list1,*list2;
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
  cout<<"Enter the value of K..\n";
  cin>>k;
 // reverseinKSize(start,k);
  list1=recursiveReverse(start,k);
  printList(list1);
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
