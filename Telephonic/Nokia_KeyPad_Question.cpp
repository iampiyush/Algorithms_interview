#include<iostream>
#include<stdlib.h>
using namespace std;

char hash[10][5]={"","abc","def","ghi","jkl","mno","pqr","stu","wxyz"};

void printutil(char* tmp,char* str,int n,int start,int index)
{
     if(index==n)
     {
      tmp[n]='\0';           
      printf("%s\n",tmp);
      return;
     }
     
     if(index>n)
     return;
     
     for(int i=0;i<3;i++)
     {
            
     tmp[index]=hash[str[start]-'0'][i];
     printutil(tmp,str,n,start+1,index+1);
     }
    // printutil(tmp,str,n,start,index+1);
     
}

void print(char* str)
{
     int n=strlen(str);
     int index=0;
     char* tmp=(char*)malloc(sizeof(char)*n);
     printutil(tmp,str,n,0,index);
}

main()
{
      char arr[4]="123";
      print(arr);
      getchar();
      return 0;
}
