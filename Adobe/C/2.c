#include<stdio.h>

int main()
{
 char *s[]={"department","Information","Technology","National"};
 char **ptr[]={s+3,s+1,s+2,s};
 char ***p;
 p=ptr;
 printf("%s \n",*(*(p)));
 getchar();
 return 0;
}
