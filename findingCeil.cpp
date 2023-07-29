#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *root, int x){
    if(root==NULL) return -1;
    int ans=-1;
    while(root!=NULL)
    {
      if (x == root->data) {
        ans = x;break;root=root->right;
      } else if (x < root->data) {
        ans=root->data;
        root = root->left;
      } else {
        root = root->right;
      }
    }
    return ans;
}