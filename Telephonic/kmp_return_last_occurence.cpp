#include<iostream>
#include<cstring>
#define MAX_SZ 1000
using namespace std;
 
/* Function_name: construct_lps
   parameters_type : char pat[],int lps[]
   Return_type: void 
   Function_Description: Calculates the length of the longest prefix that is also a sufix and store it in integer lps array
*/
void construct_lps(char pat[],int lps[]);

/* Function_name: get_index_lastOccurence
   parameter_type: char text[],char pat[]
   Return_type: int
   Function_Dexcription: Calculate the index of last occurence of pattern, pat array by searching it in text
*/
int get_index_lastOccurence(char text[],char pat[]); 

  
void construct_lps(char pat[],int lps[])
{
 int iterator,len,pat_length;
 
 pat_length=strlen(pat);

 len=0;
 lps[0]=0;
 iterator=1;
 while(iterator<pat_length)
 { 
    if(pat[iterator]==pat[len])
    {
     len++;
     lps[iterator]=len;
     iterator++;
    }
    else 
    {
     if(len!=0)
     {
      len=lps[len-1];
     }
     else
     {
      lps[iterator]=0;
      iterator++; 
     }
    }
 }   
}
 
int get_index_lastOccurence(char text[],char pat[])
{
    int textLen,patLen,textIndex,patIndex,result=-1;
  
    textLen=strlen(text);
    patLen=strlen(pat);
   
    int lps[patLen+1];
  
    construct_lps(pat,lps);
  
    patIndex=0;
    for(textIndex=0;textIndex<textLen;)  
    {
      if(text[textIndex]==pat[patIndex])
      {
       textIndex++;
       patIndex++;
      }
   
      if(patIndex==patLen)
      {
       result=textIndex-patIndex;
      // ans=textIndex;
       patIndex=lps[patIndex-1];
      }
      else if(pat[patIndex]!=text[textIndex])
      {
        if(patIndex!=0)
        {
         patIndex=lps[patIndex-1];
        }
        else
        {
         textIndex=textIndex+1; 
        }
      }
    }  
 return result;
}
 
 
int main()
{
int testcase;
int lastIndex;
char text[MAX_SZ],pat[MAX_SZ]; 
cin>>testcase;
 
while(testcase--)
{
    /* Get the text, with size limit. */
    fflush(stdin);
    fgets (text, MAX_SZ, stdin);

    /* Remove trailing newline, if there. */
    if ((strlen(text)>0) && (text[strlen (text) - 1] == '\n'))
    {
        text[strlen (text) - 1] = '\0';
    }

    /* Get the pattern, with size limit. */
    fflush(stdin);
    fgets (pat, MAX_SZ, stdin);

    /* Remove trailing newline, if there. */
    if ((strlen(pat)>0) && (pat[strlen (pat) - 1] == '\n'))
    {
        pat[strlen (pat) - 1] = '\0';
    }
        
    //Get the lastIndex using Search function
    lastIndex=get_index_lastOccurence(text,pat);
    if(lastIndex==-1)
    cout<<"The pattern cannot be found in the given text"<<endl;
    else
    cout<<"The last occurence of pattern in text Is at index "<<lastIndex<<endl;
}
  
 return 0;
}
