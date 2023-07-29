/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
#include <bits/stdc++.h>
TreeNode<int>* buildTree(int is,int ie,vector<int>&inOrder,int ps,int pe,vector<int>&postOrder,map<int,int>&hash)
{
     if(is>ie||ps>pe) return NULL;
     TreeNode<int>* root=new TreeNode<int>(postOrder[pe]);

     int inRoot=hash[postOrder[pe]];
     int x=inRoot-is;

     root->left=buildTree(is,is+x-1,inOrder,ps,ps+x-1,postOrder,hash);
     root->right=buildTree(is+x+1,ie,inOrder,ps+x,pe-1,postOrder,hash);
     return root;
}


TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	map<int,int>hash;
     for(int i=0;i<inOrder.size();i++)
     {
          hash[inOrder[i]]=i;
     }

     TreeNode<int>* root=buildTree(0,inOrder.size()-1,inOrder,0,postOrder.size()-1,postOrder,hash);
     return root;
}
