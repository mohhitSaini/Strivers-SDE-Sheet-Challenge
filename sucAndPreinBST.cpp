#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int pre=-1;
    BinaryTreeNode<int>* temp=root;
    while(temp)
    {
        if(temp->data<key)
        {
            pre=temp->data;
            temp=temp->right;
        }
        else
        temp=temp->left;
    }
    temp=root;
    int suc=-1;
    while(temp)
    {
        if(temp->data>key)
        {
            suc=temp->data;
            temp=temp->left;
        }
        else
        temp=temp->right;
    }
    return {pre,suc};
}
