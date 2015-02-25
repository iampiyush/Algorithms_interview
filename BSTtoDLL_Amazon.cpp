 TreeNode *toBST(TreeNode *root)
    {
     if(root==NULL)
      return NULL;
   
     TreeNode *left=NULL,*right=NULL;
     TreeNode *temp=NULL;
     
     left=toBST(root->left);
     right=toBST(root->right);
     
     if(left)
     {
      temp=left;
      while(temp->right)
      {
       temp=temp->right;
      }
     
      temp->right=root;
      root->left=temp;
     
     }
     else
     {
     left=root;  
     }
    
     //  merge root and right subtree...
    
     if(right)
     {
      root->right=right;
      right->left=root;
     }
     else
      root->right=NULL;
    
    
     return left;
    }
   

    DLLNode *createNode(int data)
    {
     DLLNode *temp;
    
     temp=(DLLNode*)malloc(sizeof(DLLNode));
     temp->val=data;
     temp->prev=NULL;
     temp->next=NULL;
   
     return temp;
    }
   


    DLLNode *getSortedDLLFromBST(TreeNode *root)
    {
     if(root==NULL)
      return NULL;
     
     int data;
     
     TreeNode *start=NULL,*store=NULL;
      start=toBST(root);
      store=start;
   
     DLLNode *head=NULL,*temp=NULL;
     DLLNode *buf=NULL;
   
     while(start)
     {
      data=start->val;
      buf=createNode(data);
      if(temp==NULL)
      {
       temp=buf;
       head=temp;
      }
      else
      {
       temp->next=buf;
       buf->prev=temp;
       temp=temp->next;
      }
     
      start=start->right;
     }
   
   
     return head;
   
    }
