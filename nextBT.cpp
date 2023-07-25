#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    vector<vector<BinaryTreeNode<int>*>>levels;
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    int j=-1;
    while(!q.empty())
    {
        int size=q.size();
        vector<BinaryTreeNode<int>*>temp;
        for(int i=0;i<size;i++)
        {
            BinaryTreeNode<int>* node=q.front();
            q.pop();
            temp.push_back(node);
            if(node->left)
            q.push(node->left);
            if(node->right)
            q.push(node->right);
        }
        levels.push_back(temp);
    }

    for(int i=0;i<levels.size();i++)
    {
        int j=0;
        for(j=0;j<levels[i].size()-1;j++)
        {
            levels[i][j]->next=levels[i][j+1];
        }
        levels[i][j]->next=NULL;

    }
    // return root;
}