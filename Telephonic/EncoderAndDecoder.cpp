//   The Google Problem...  Encoder And Decoder...

#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;


bool isNumeric(char ch)
{
 if(ch < '0'   ||    ch >'9')
  return false;

 return true;
}




string encoder(string text)
{
string buffer;
int i,j;
int length;
int count;
char temp[100];
char key[2];

length=text.length();

i=0;
key[1]='\0';
while(i<length)
{
 count=1;
 key[0]=text[i];
 j=i+1;
 while(j<length && key[0]==text[j])
 {
  j++;
  count++;
 }

if(count>1)
{
 buffer.append(itoa(count,temp,10));
 buffer.append("x");
}

buffer.append(key);
i=j;
}
  
  return buffer;
 //   return Encoded String....
}


string decoder(string encodedText)
{
 string decodedText;
 int i,j,k;
 int len;
 char key[2];
 char ch;
 char buffer[100];
 int number;
 
 
 i=0;
 key[1]='\0';
 while(i<len)
 {
  //   read Current Character..
  key[0]=encodedText[i];
  
  if(isNumeric(key[0]))
  {
                       
   j=i+1;
   k=0;
   buffer[k++]=key[0];
   while(j<len  &&  isNumeric(encodedText[j]))
  {
  //  Do Something intersting here..make number out of it...
   buffer[k++]=encodedText[j];
   j++;
  } 
  
   if(j!=len)
  {
   buffer[k]='\0';
   number=atoi(buffer);
   ch=encodedText[j+1];    //   May throw Run Time Error....
   for(k=0;k<number;k++)
     buffer[k]=ch;
    buffer[k]='\0'; 
    decodedText.append(buffer);
  
    i=j+2;
  }
  else
  {
   return decodedText;
  }
}
 //  Proceed in Normal Way   i.e Simply Copy/append The Char
 else
 {
  decodedText.append(key);
  i++;   //  Increment i
 }
 
 }  //  end of while loop..
 
  return decodedText;

}




int main()
{
 string text;
 string encodedText,decodedText;
 int i,j;
 int t;
 
 
 cin>>t;
 while(t--)
 {
   cout<<"Enter Text to be Encoded..\n";
   cin>>text;
   
   //  Encode text..
   encodedText=encoder(text); 
  
   cout<<"The Encoded text is \n";
   cout<<encodedText<<endl;
   
   cout<<"Now decode The String..\n";
   decodedText=decoder(encodedText);
   cout<<decodedText;
  
    if(text.compare(decodedText)==0)
     {
      cout<<"this Works..\n";
     }
    else
    {
     cout<<"this Does Not Work..\n";  
    } 
    
 
 }


 return 0;

}
