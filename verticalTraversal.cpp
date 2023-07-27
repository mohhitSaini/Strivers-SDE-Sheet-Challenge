#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    map<int,vector<int>>mp;
    queue<pair<TreeNode<int>*,int>>q;
    q.push({root,0});
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            TreeNode<int>* node=q.front().first;
            int x=q.front().second;
            q.pop();
            vector<int>temp=mp[x];
            temp.push_back(node->data);
            mp[x]=temp;
            if(node->left)
            {
                q.push({node->left,x-1});
            }
            if(node->right)
            {
                q.push({node->right,x+1});
            }
        }
    }
    vector<int>ans;
    for(auto it:mp)
    {
        vector<int>temp=it.second;
        for(int i=0;i<temp.size();i++)
        {
            ans.push_back(temp[i]);
        }
    }
    return ans;








}