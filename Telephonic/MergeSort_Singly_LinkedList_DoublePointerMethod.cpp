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


node *splitLists(node *start)
{
 if(start==NULL ||  start->next==NULL )
  return NULL;
 
 node *mid=NULL;
 
 int count=0;
 mid=start;
 start=start->next;
 while(start!=NULL)
 {
  if(count%2==1)
   mid=mid->next;
  
  count++;
  start=start->next;
 } 
 
 //  now we have middle element..
 
 node *secondList=NULL;
 secondList=mid->next;
 mid->next=NULL;
 
  
  return secondList;
}



void merge(node **first,node **second)
{
 
 if((*first)==NULL)
 {
  *first=*second;
  return ;
 }
 else if((*second)==NULL)
  return ;
  
 node *start=NULL;
 node *temp=NULL;
 node *head=NULL;
 node *a=NULL,*b=NULL;
 

  a=*first;
  b=*second;
 
 
 while(a   &&  b)
 {
  if(a->data < b->data)
  {
   temp=a;
   a=a->next;
  }
  else
  {
   temp=b;
   b=b->next;
  }
    temp->next=NULL;
  
  //    Append in Sorted Merge List...
   if(start==NULL)
   {
    *first=temp;              
    start=temp;
    head=temp;
   }
   else
   {
    start->next=temp;
    start=start->next;
   }
 }
 //   end of while.... 
  
   
   //   Append Remaining List...
   if(a)
   {
    start->next=a;
   }
   else
   {
   start->next=b;    
   }
   
   
   
   return ; 
   //  end of this function..
}





//  overall time complexity...  (0(2*n)*logn)==  (0(nlogn))   //  space complexity...   0(logn)...
void mergeSort(node **start)
{
  //   for empty list and one node list...   
  if((*start)==NULL  ||  (*start)->next == NULL)
   return ;

  node *first=NULL;
  node *second=NULL;
 
  first=*start;
  second=splitLists(first);   //  0(n)  step..
  
  //  sort this lists  ..individually...Divide step....
  mergeSort(&first);
  mergeSort(&second);
  
  merge(&first,&second);    //   0(n)   step.... 

  
  *start=first;

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
 
  //   Merge Sort...
  mergeSort(&start);
  
  //  Now Print this List...
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
