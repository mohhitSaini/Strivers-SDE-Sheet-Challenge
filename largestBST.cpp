#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
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

class NodeValue{
    public:
  int minValue;
  int maxValue;
  int maxSize;
  NodeValue(int minValue,int maxValue,int maxSize)
  {
      this->minValue=minValue;
      this->maxValue=maxValue;
      this->maxSize=maxSize;
  }
};
NodeValue* rec(TreeNode<int>* root)
{
    if (!root) return new NodeValue(INT_MAX,INT_MIN,0);
    auto l=rec(root->left);
    auto r=rec(root->right);
    if (root->data<r->minValue && root->data>l->maxValue) return 
    new NodeValue(min(root->data,l->minValue),max(root->data,r->maxValue),l->maxSize+r->maxSize+1);
    return new NodeValue(INT_MIN,INT_MAX,max(l->maxSize,r->maxSize));
}
int largestBST(TreeNode<int>* root) 
{
    return rec(root)->maxSize;
}
