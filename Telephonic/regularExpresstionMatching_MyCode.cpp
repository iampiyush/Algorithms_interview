//  Regular Expression matching ...

#include<iostream>
#include<cstdio>
#include<ctime>
#include<unistd.h>
#include<algorithm>


using namespace std;



// swap two variables...

void swap(int &x,int &y)
{
 int temp;
 temp=x;
 x=y;
 y=temp;
}



bool match(char *first,char *second)
{
 if((*first=='\0'  &&  *second=='\0'))
  return true;      //   both strings match..
  
  if(*first=='*'  && *(first+1)=='\0')
   return true;
  
  if((*first=='*' && *(first+1)!='\0' &&  *second=='\0'))
    return false;
 
 if(*first=='?'  || *first==*second)
  return match(first+1,second+1);
 
 if(*first=='*')
  return (match(first,second+1) || match(first+1,second));
  
  return false;
 
}



void test(char *first, char *second)
{  match(first, second)? puts("Yes"): puts("No"); }



int main()
{
    test("g*ks", "geeks"); // Yes
   // puts("Why??");
    test("*","Avi");
    test("ge?ks*", "geeksforgeeks"); // Yes
    test("g*k", "gee");  // No because 'k' is not in second
    test("*pqrs", "pqrst"); // No because 't' is not in first
    test("abc*bcd", "abcdhghgbcd"); // Yes
    test("abc*c?d", "abcd"); // No because second must have 2 instances of 'c'
    test("*c*d", "abcd"); // Yes
    test("*?c*d", "abcd"); // Yes
    getchar();
    return 0;


 return 0;
}

