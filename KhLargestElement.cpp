#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void traversal(TreeNode<int>* root,int& k,int& ans)
{
    if(root==NULL)
    return;
    traversal(root->right,k,ans);
    k--;
    if(k==0)
    ans=root->data;
    traversal(root->left,k,ans);
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    int ans=-1;
    traversal(root ,k ,ans);
    return ans;
}
