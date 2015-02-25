#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<unistd.h>
#include<algorithm>
#include<stack>
#include<deque>
#include<map>

using namespace std;




typedef struct node
{
 int data;
 struct node *next;
 struct node *arbit;
};


node* createNode(int);
node* createList();
void printList(node*);
int getCount(node*);
int detectLoop(node*);
node* getKthNode(node*,int);


void duplicateList(node *start)
{
 if(start==NULL)
  return ;
 
 node *temp=NULL;
 
 while(start)
 {
  temp=start->next;
  start->next=createNode(start->data);
  start->next->next=temp;
  start=temp;
 } 
//  done..

return ;
}


node *segregate(node *start)
{
 if(start == NULL  ||  start->next == NULL)
  return NULL;
 
 node *temp=NULL;
 node *copy=NULL,*copyHead=NULL;
 
 //  detach alternate Nodes from the List...
 //  And Create New List Using same detached nodes..
 
 while(start)
 {
  temp=start->next;
  start->next=start->next->next;
  temp->next=NULL;
  if(copy==NULL)
  {
   copyHead=copy=temp;
  }
  else
  {
   copy->next=temp;
   copy=copy->next;
  } 
  start=start->next;
 }
 
//  we done yet?? 

 return copyHead;
}


node *copyListInplace(node *start)
{
 //  Base Case...
 if(start==NULL)
  return NULL;
  
  node *copy=NULL;
  node *temp=NULL;
 //   first create copy List By Duplicating the nodes of the list...  
 duplicateList(start); 
 //  now fix arbit pointers..
 printList(start);
 int wait;
 temp=start;
 
 while(start)
 {
  start->next->arbit=start->arbit->next;
  start=start->next->next;
 }
//  time to segregate the lists..
  cin>>wait;
 start=temp;
 copy=segregate(start);
 return copy;
}


//  Method Where List can not be modified/ or list is read only..Using Map/hash...
node *copyList(node *start)
{
 if(start==NULL)
  return NULL;
 
 node *temp=NULL,*copy=NULL,*orignalHead=NULL,*copyHead=NULL;
 map<node*,int> first;
 map<int,node*> second;
 int pos=0;
 
 orignalHead=start;
 int count=1;     //  create mapping between node *  and their position in list....
 
 while(start!=NULL)
 {
  first[start]=count;
  if(copy==NULL)
  {
   copyHead=copy=createNode(start->data);
  }
  else
  {
  copy->next=createNode(start->data);
  copy=copy->next;
  }
  second[count]=copy;
  count++;
  start=start->next;
 }
//   maps created....for both lists...
 
//  now time to fix arbit pointer 
start=orignalHead;
copy=copyHead;

while(start)
{
 temp=start->arbit;
 pos=first[temp];  
 copy->arbit=second[pos];
 start=start->next;
 copy=copy->next;
}

 return copyHead;
}


void check(node *start, node *copy)
{
 
 while(start)
 {
  if(start->data!= copy->data  ||  start->arbit->data !=  copy->arbit->data)
  {
   cout<<"Not Same Lists..u screwed up..."<<endl;
   return ;
  }
  else
  {
   cout<<"start and copy's data  "<<start->data<<" "<<copy->data<<endl;
   cout<<"start and copy's arbit data "<<start->arbit->data<<" "<<copy->arbit->data<<endl; 
  }
 
 start=start->next;
 copy=copy->next;
 }

 
 cout<<"Both List are similar..hence..done..\n"; 
 return ;
}



int main()
{
  node *temp,*start,*copy=NULL,*head;
  int i,k,state,len;
  int wait;
  
 //create List..
 //head=createList();
   start=createList();  
 //print the linked list..
   printList(start);
  
  
  // now create Loop...
    head=start;
    head -> arbit = head -> next -> next;
    head -> next -> arbit = head -> next -> next -> next;
    head -> next -> next -> arbit = head;
    head -> next -> next -> next -> arbit = head -> next -> next;
    head -> next -> next -> next -> next -> arbit = head -> next -> next;
 
   temp=start; 
   copy=copyListInplace(start);
  
   check(start,copy);
//  printf("%d\n",temp->data);
 
 
  cout<<"Modification done..\n";
  cin>>wait;
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
 temp->arbit=NULL;
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

