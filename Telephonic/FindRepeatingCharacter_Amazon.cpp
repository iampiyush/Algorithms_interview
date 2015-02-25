
void findRepeatCharacters(string a) {
    
    int i;
    int count[256];
    int length;
    int index;
    
    length=a.length();
    
    
    for(i=0;i<256;i++)
     count[i]=0;
    
   for(i=0;i<length;i++)
   {
    index=((int)a[i]);
    count[index]=count[index]+1;
   }   
         

     
   for(i=0;i<256;i++)
   {
    if(count[i]>1)
     cout<<(char)i<<endl;   
   }   
    
    
   return ;
}

