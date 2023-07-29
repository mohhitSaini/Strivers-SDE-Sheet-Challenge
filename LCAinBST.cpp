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

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	if(root==NULL||root==P||root==Q)
    return root;
    while(root)
    {
        if(root->data>=P->data&&root->data<=Q->data||root->data>=Q->data&&root->data<=P->data)
        return root;
        else if(root->data>P->data&&root->data>Q->data)
        {
            root=root->left;
        }
        else
        root=root->right;
    }
    return root;

}
