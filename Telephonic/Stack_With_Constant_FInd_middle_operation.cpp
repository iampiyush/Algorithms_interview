//   implement a stack With Constant push,pop  and findMin  Operations  0(1)...

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


class myStack
{
 node *head;
 node *mid;
 int count;
 public:
 myStack();
 void push(int);
 int pop();
 int findMid();
 int size();
};



myStack::myStack()
{
 head=NULL;
 mid=NULL;
 count=0;
}


void myStack::push(int key)
{
 node *temp=NULL;
 temp=createNode(key);
 if(temp==NULL)
 {
  cout<<"Stack OverFlow..\n";
  return ;
 }

 if(head==NULL)
 {
  head=temp;
 }
 else
 {
  temp->next=head;
  head->prev=temp; 
  head=temp;
 }

 count++;
 if((count%2)==1)
 {
  if(mid)
  mid=mid->prev;
  else 
  mid=head;
 }

return ;
}  //  Done With Push..


//   Now pop Element...
int myStack::pop()
{
 if(head==NULL)
 {
  cout<<"No ELements to pop..\n";
  return -1;
 } 

 int temp;
 if(head->next == NULL)
 {
  temp=head->data;
  free(head);
  head=NULL;
  mid=NULL;
  count--;
  return temp;
 }
 else  //   Maintain min also...
 {
  node *p=NULL;
  temp=head->data;
  p=head;
  head=head->next;
  head->prev=NULL;
  free(p);
 }
 
 count--;
 
 if(count%2==0)
 {
  mid=mid->next;
 }
 
 
  //  pop value from Stack...
  return temp;
}


int myStack::findMid()
{
 if(head==NULL)
 {
  cout<<"Empty Stack..can not query for middle element.."<<endl;
  return -1;
 }
 
 return mid->data;
}



int myStack::size()
{
 return count;
}


int main()
{
 node *temp,*start,*list1;
 int i,k,state,len;
 int choice;
 int val;
 myStack ms;
 int mid;
 
 cout<<"Stack Size is "<<ms.size()<<endl;
 
 while(1)
 {
  /*
  cout<<"Enter Your Choice "<<endl;
  cout<<"Enter 1 for Push "<<endl;
  cout<<"Enter 2 for pop "<<endl;
  cout<<"Enter 3 for Find Min "<<endl;
  cout<<"Enter 4 to termination "<<endl;       
 */
  cin>>choice;
  cout<<endl;
  if(choice==4)
   break;
  if(choice==1)
  {
   cout<<"Enter Value you want to Add..\n";            
   cin>>val;
   ms.push(val);
  }
  else if(choice==2)
  {
   val=ms.pop();
   if(val!=-1)
    cout<<"The Popped Value is "<<val<<endl;
   else
    cout<<"Stack is Empty.."<<endl;
  }
  else if(choice==3)
  {
   mid=ms.findMid();
   if(mid!=-1)
   cout<<"Middle Elemnt's Value is "<<mid<<endl;
   else
   cout<<"Empty Stack..."<<endl;
  }
 }
  
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
