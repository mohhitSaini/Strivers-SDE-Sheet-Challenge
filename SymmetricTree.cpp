/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/
#include <bits/stdc++.h>
void traversal(BinaryTreeNode<int>* root,vector<int>&ans)
{
    if(root==NULL)
    return;
    traversal(root->left,ans);
    ans.push_back(root->data);
    traversal(root->right,ans);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    vector<int>ans;
    traversal(root,ans);
    vector<int>ans1=ans;
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i]!=ans1[i])
        return false;
    }
    return true;
}