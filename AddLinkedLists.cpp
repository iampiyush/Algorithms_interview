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



void addLists(node *list1,node* list2)
{
 //  Base Cases..  
 
 if(list1==NULL  && list2==NULL)
 {
  cout<<"Both List Empty..\n";
  return ;
 }
 
 if(list1==NULL)
 {
  printList(list2);
  return ;
 }
 
 
  if(list2==NULL)
 {
  printList(list1);
  return ;
 }
  
   
 node *res=NULL,*temp=NULL;
 node *l1,*l2,*p=NULL,*q=NULL;
 int sum,carry;
 l1=reverse(list1);
 l2=reverse(list2);
 
 
// printList(l1);
 //printList(l2);
 
 list1=l1;
 list2=l2;
 
 sum=carry=0;
 while(l1 &&  l2 )
 {
  sum=l1->data+l2->data+carry;
  if(sum>9)
  {
   sum=sum%10;
   carry=1;
  }
  else
  {
   carry=0;   
  }
  
  if(res)
  {
   temp=createNode(sum);
   temp->next=res;
   res=temp;
  }
  else
  {
   res=createNode(sum);
  }
  
  l1=l1->next;
  l2=l2->next;
 
 }
 
 if(l1==NULL)
 {
  while(l2)
  {
   sum=l2->data+carry;
   if(sum==10)
   {
    sum=0;
    carry=1;
   }
   else
   {
    carry=0;
   }
   
   if(res)
  {
   temp=createNode(sum);
   temp->next=res;
   res=temp;
  }
  else
  {
   res=createNode(sum);
  }
   
  
   l2=l2->next;
  }
 }
  
  
  if(l2==NULL)
 {
  while(l1)
  {
   sum=l1->data+carry;
   if(sum==10)
   {
    sum=0;
    carry=1;
   }
   else
   {
    carry=0;
   }
   
   if(res)
  {
   temp=createNode(sum);
   temp->next=res;
   res=temp; 
  }
  else
  {
   res=createNode(sum);
  }
   
   l1=l1->next;
  }
 }
 
 //  nearly done..
 
 if(carry) 
 { 
   temp=createNode(carry);
   temp->next=res;
   res=temp;
 }
//  now done..


 cout<<"Resultant List..\n"; 
 printList(res);
 l1=reverse(list1);
 l2=reverse(list2);
 
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
 
 
 cout<<"Enter List 2..\n";
  list2=createList();
  
  if(list2==NULL)
 {
  printf("Insufficient Memory...\n");
  return 0;
 }
  
 
 //print the linked list..
   printf("LIST 1...\n");
   printList(list1);
   
    printf("LIST 2...\n");
   printList(list2);
      
  
   cout<<"Adding Two Lists....\n\n";
   addLists(list1,list2);
  
   printf("LIST 1...\n");
   printList(list1);
   
   printf("LIST 2...\n");
   printList(list2);
     

 cin>>state;
 return 0;
}


node *reverseK(node *start,int k)
{
 node *head,*tail,*temp;    
 int iter,i,j;
 int count;
 hl arr[100];
 
 count=CountNodes(start);
 if(count<=k)
  return start;
 cout<<"Count is "<<count<<endl;
 iter=count/k;
 i=0;
 int flag=1;
 while(i<iter)
 {
  if(flag==1)
  {
  tail=start;
  start=breaklist(start,k);
  head=reverse(tail);
  cout<<"tail's data "<<tail->data<<endl;
 
  arr[i].head=head;
  printList(arr[i].head);
  arr[i].tail=tail;
  flag=0;
 }
 else
 {
  head=start;
  start=breaklist(start,k);
  tail=reverse(head);
  reverse(tail);
  cout<<"tail's data "<<tail->data<<endl;
 
  arr[i].head=head;
  printList(arr[i].head);
  arr[i].tail=tail;
 
 flag=1;
 }
  
  i++;
 }


  head=arr[0].head;
 // printList(head);
 for(i=0;i<iter-1;i++)
 {
  arr[i].tail->next=arr[i+1].head;
 }
 
   arr[i].tail->next=start;
  // printList(head);

 return head;
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


