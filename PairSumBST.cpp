#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
bool solve(BinaryTreeNode<int> * root, unordered_set<int>& st, int k){
    if(!root) return  0;
    int diff=k-root->data;
    if(st.find(diff)!=st.end()){ return true;}
    st.insert(root->data);
    return solve(root->left, st,k) || solve(root->right,st,k);


}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    unordered_set<int> st;
    return solve(root,st,k);

}