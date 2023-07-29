#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int cnt=0;
long long maxPathSum(TreeNode<int>* root,long long& maxi)
{
    if(root==NULL)
    return 0;
        if(root->left==NULL && root->right==NULL)
      cnt++;
    long long leftSum=maxPathSum(root->left,maxi);
    long long rightSum=maxPathSum(root->right,maxi);

    maxi=max(maxi,leftSum+rightSum+1ll*root->val);

    return 1ll*root->val+ max(leftSum,rightSum);
}


long long int findMaxSumPath(TreeNode<int> *root)
{
     if(root==NULL || root->left==NULL || root->right==NULL) return -1;
    long long maxi=0;
    maxPathSum(root,maxi);
    if(cnt<=1)
    return -1;
    return maxi;
}