#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
vector<int> findSpiral(BinaryTreeNode<int> *root)
{
    vector<int>ans;
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    int level=0;
    while(!q.empty())
    {
        int size=q.size();
        vector<int>temp;
        for(int i=0;i<size;i++)
        {
            BinaryTreeNode<int>* node=q.front();
            q.pop();
            temp.push_back(node->data);
            if(node->left)
            q.push(node->left);
            if(node->right)
            q.push(node->right);
        }
        if(level%2==0)
        {
           for(int i=0;i<temp.size();i++)
           ans.push_back(temp[i]);
        }
        else
        {
            for(int i=temp.size()-1;i>=0;i--)
           ans.push_back(temp[i]);
        }
        level++;
    }
    return ans;
}

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    if(root==NULL) return {};
   return findSpiral(root);
}
