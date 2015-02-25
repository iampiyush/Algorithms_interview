

void nLargestUtil(node* root,int &ans,int &count,int N)
{
 if(root==NULL)
  return ;
 
 nLargestUtil(root->right,ans,count,N); 
 
 if(count==N)
 {
  ans=root->data;
  count++;
 }
 else
 count++;
 nLargestUtil(root->left,ans,count,N);
}

int nLargeBST(node* root, int N) {
{
 if(root==NULL)  //  condition check
 {
  return NULL;
 }
 
 int ans=-1;
 int count=1;
 
 nLargestUtil(root,ans,count,N);
 
 return ans;
}
