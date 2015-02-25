//   check weather the linked list is palindrome or not...

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
};


node* createNode();
node* createList();
void printList(node*);
int findSize(node *start);
node* reverse(node *start);



bool isPalindrome(node *start)
{
 if(start==NULL || start->next==NULL)
  return true;
 
 
  node *prev,*second,*head,*rev;
  int i;

  head=start;
  int size=findSize(start); 
   
  for(i=0;i<size/2;i++)
  {            
   prev=start;
   start=start->next;
  }

  second=start;
  if(size%2)
   start=start->next;
   prev->next=NULL;
   rev=reverse(head);
   head=rev;
  while(start!=NULL)
  {
   if(start->data!=rev->data)
    return false;
    rev=rev->next;
    start=start->next;  
  } 
  
  rev=head;
  head=reverse(rev); 
  prev->next=second;

 return true;
}




bool isPalindrome3(node *start)
{
 if(start==NULL || start->next==NULL)
  return true;
 
 int i;
 stack<char> mystack;
 int size=findSize(start); 
   
  for(i=0;i<size/2;i++)
  {            
   mystack.push(start->data);
   start=start->next;
  }

  if(size%2)
   start=start->next;
  
  while(start!=NULL)
  {
   if(start->data!=mystack.top())
    return false;
    mystack.pop();
    start=start->next;  
  } 

 return true;
}





bool isPalindrome2(node *start)
{
 if(start==NULL || start->next==NULL)
  return true;
 stack<char> mystack;
 node *temp;
 
 temp=start;
 while(start)
 {
  mystack.push(start->data);
  start=start->next;
 }

 start=temp;
 
 while(start)
 {
  if(start->data!=mystack.top())
     return false;
  mystack.pop();
  start=start->next; 
 }

  return true;
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
  if(isPalindrome(start)==true)
  {
   cout<<"Palindrome  List....\n";
  }
  else
  {
  cout<<"Not A palindrome List....\n";
  }
  
 //  printList(start);
  
 printList(start);
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



