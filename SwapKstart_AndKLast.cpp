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


node* startKNode(node *start,int k)
{
 int i,j;
 
 i=1;
 for(;i<k;i++)
  start=start->next;

 return start;
}



node* endKNode(node *start,int k,int count)
{
 int i,j;
 
 i=1;
 k=count-k;
 for(;i<=k;i++)
  start=start->next;

 return start;
}





void swapKthNode(node *start,int k)
{
 if(start==NULL ||   k<1)
 {
  cout<<"Invalid Size...\n";
  return ;
 }  
   
 node* head;
 head=start;
 int count;
 
 count=CountNodes(start);
 
 if(count<2*k)
 {
  cout<<"Invalid Size...\n";
  return ;
 }
 
 node *st,*end;


 st=startKNode(start,k);
 cout<<"Error point.\n"; 
 end=endKNode(start,k,count);
 
 
  
 
 int temp;
 
 //   swap   two node values....
 temp=st->data;
 st->data=end->data;
 end->data=temp; 
 
 
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
   

   cin>>k;
   //addLists(list1,list2);
  swapKthNode(list1,k);
   
   printf("LIST 1...\n");
   printList(list1);
   

     

 cin>>state;
 return 0;
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
   // cin>>value;          
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


