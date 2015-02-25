
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
 struct node *arbit;
};


node* createNode(int);
node* createList();
void printList(node*);
int getCount(node*);
int detectLoop(node*);
node* getKthNode(node*,int);



node *create(int n)
{
    if (n == 0)
        return NULL;

    node *head = new node();
    node *p = head;

    cin >> (p -> data);

    p -> next = NULL;

    for (int i = 1; i < n; i++) {
        p -> next = new node();
        p = p -> next;

        cin >> (p -> data);

        p -> next = NULL;
    }

    return head;
}


void test(node *head, node *head1)
{
    while (head) {
        cout << "In list:\n"<< head -> data << " and copy = " << head1 -> data << endl << "Arbitrary Node:\n" << head -> arbit -> data << " and copy = " << head1 -> arbit -> data << endl;
        head = head -> next;
        head1 = head1 -> next;
    }
}



node *copy(node *start)
{
 if(start==NULL)
  return NULL;
       
 node *head=start;
 node *temp=NULL;
 node *next=NULL;
 node *copy=NULL,*copyhead=NULL;
 
 //  Duplicate The nodes of original List...
 while(start)
 {
  temp=createNode(start->data);
  next=start->next;
  start->next=temp;
  temp->next=next;
  start=next;
 }
 
 
 //   set arbit pointers.... for Duplicated nodes....
 start=head;
 while(start)
 {
  start->next->arbit=start->arbit->next;
  start=start->next->next;
 }

 //   now  Segregates/Separate Lists..
start=head;
temp=start;
copyhead=start->next;
start->next;
copy=copyhead;
copy->next=NULL;
temp=temp->next->next;

  copy=copyhead;
  while(temp)
  {
    //   remove original node from the list..         
    start->next=temp;
    start=start->next;
    temp=temp->next;
    start->next=NULL; 
   
   //  remove Copied node from the list...
   copy->next=temp;
   copy=copy->next;
   temp=temp->next;
   copy->next=NULL;
   
  } 

  return copyhead;
 
  

}




int main()
{
    node *head = NULL;
    node *head1 = NULL;
    head = create(5);

    head -> arbit = head -> next -> next;
    head -> next -> arbit = head -> next -> next -> next;
    head -> next -> next -> arbit = head;
    head -> next -> next -> next -> arbit = head -> next -> next;
    head -> next -> next -> next -> next -> arbit = head -> next -> next;

    head1 = copy(head);

    //
   // test(head, head1);

    cout << "\n";
  
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
