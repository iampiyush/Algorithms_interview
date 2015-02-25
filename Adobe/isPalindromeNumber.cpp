//    Find Wheather A Given Number is palindrome or not.....

#include<iostream>
using namespace std;




bool isPalindrome(int number)
{
 if((number/10)==0)
  return true;
 
 int left=1;
 int tempNumber=number;
 int leftDigit,rightDigit;
 
 tempNumber=number/10;
 
 while(tempNumber)
 {
  left=left*10;
  tempNumber=tempNumber/10;
 }
 
 //cout<<left<<" is left for number "<<number<<endl;
 
 tempNumber=number;
 while(left && left!=1)
 {
  leftDigit=tempNumber/left;
  rightDigit=tempNumber%10;
//  cout<<" LeftDigit is "<<leftDigit<<" rightDigit is "<<rightDigit<<endl;
  if(leftDigit!=rightDigit)
   return false;
  tempNumber=tempNumber/10;
  left=left/10;
  tempNumber=tempNumber%left;
  left=left/10;
  
 // cout<<"Left is "<<left<<endl;
 }
 //  i think we are done here...
 
  return true;
}




int main()
{
 int t;
 int n;
 bool check=false;
 
 cin>>t;
 while(t--)
 {
  cin>>n;
  check=isPalindrome(n);
  if(check)
   cout<<"Number iS palindrome..\n";
  else
   cout<<"Number is not palindrome..\n";
 }


  return 0;
}


