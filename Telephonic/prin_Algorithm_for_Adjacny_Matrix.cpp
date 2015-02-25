//    minimum Spanning tree...prin's Algorithm...
//  0(v*v)  implementation...
//  Works for only +ve weight Edges...

#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
#define inf 100000


int graph[100][100];



void input(int v,int e)
{
 int i,j;
 int source,dest,weight;
 
 
 for(i=0;i<=v;i++) 
  for(j=0;j<=v;j++)
   graph[i][j]=0;   //  initialise this shit....
   
 cout<<"Enter "<<e<<" Edges "<<endl;
 
 for(i=0;i<e;i++)
 {
  cin>>source;
  cin>>dest;
  cin>>weight;
  
  graph[source][dest]=weight;
  graph[dest][source]=weight;   // this step for undirected graph only..
  
 }
   

/*
 for(i=0;i<=v;i++) 
 {
  for(j=0;j<=v;j++)
  cout<<graph[i][j]<<" ";
  cout<<endl;
} 

*/


//  done with the input..

 return ;
}



int findMin(int key[],bool inMST[],int V)
{
 int i;
 int min,minVertex;
 
 min=INT_MAX;
 minVertex=-1;
 
 
 
 for(i=1;i<=V;i++)
 {
 // cout<<key[i]<<" ";
  if(inMST[i]==false   &&  key[i]<min )
  {
   min=key[i];
   minVertex=i;
  }
 
 }
 
 cout<<endl;

 return minVertex;
}



void printMST(int parent[],int V)
{
 int i;
 
 cout<<"MST With Edges Weights are "<<endl;
 
 for(i=1;i<=V;i++)
 {
  if(parent[i]==-1)
   cout<<"Parent/Source  Node "<<i<<endl;
  else 
  cout<<parent[i]<<" "<<i<<" "<<graph[i][parent[i]]<<endl;
 }

}



void prinMST(int V,int E,int source)
{
 bool inMST[V+1];
 int key[V+1];
 int parent[V+1];
 int i,j;
 int curVertex;
 
 //  initialise the data..
 for(i=1;i<=V;i++)
 {
  inMST[i]=false;
  key[i]=inf;
  parent[i]=-1;
 }
 
 
 
 //inMST[source]=true;
 key[source]=0;
 parent[source]=-1;
 
 
 
 for(i=1;i<=V;i++)
 {
  curVertex=findMin(key,inMST,V);   
  
  
  cout<<"current Vertex is "<<curVertex<<endl;
 // if(curVertex!=-1)
 // {
   inMST[curVertex]=true;
   for(j=1;j<=V;j++)
  {
   if(graph[curVertex][j]  &&  inMST[j]==false   &&   key[j]> graph[curVertex][j] )
    {
     key[j]= graph[curVertex][j] ;
     parent[j]=curVertex;
    }
  }                 
 }  // outer for loop..
 
 
  printMST(parent,V);   //  print MST...       
  return ;  
}


int main()
{
 int t;
 int i,j;
 int V,E;
 int source;

 cin>>t;
 
 while(t--)
 {
  cout<<"Enter number Of Vertices"<<endl;
  cin>>V;
  cout<<"Enter number of Edges "<<endl;
  cin>>E;
  
  input(V,E);
  
  cout<<"Enter Source vertex ."<<endl;
  cin>>source; 
 
  prinMST(V,E,source); 
  
 //   done...wtih this case.. 
 }



 return 0;
}
