#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

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
    };

***********************************************************/

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    if(root1==NULL&&root2==NULL)
    return true;
    if(root1==NULL&&root2!=NULL) return false;
    if(root2==NULL&&root1!=NULL) return false;
    if(root1->data!=root2->data) return false;
    if(identicalTrees(root1->left,root2->left)==false||identicalTrees(root1->right,root2->right)==false)
    return false;
    return true;	 
}