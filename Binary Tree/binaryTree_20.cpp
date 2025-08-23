/*
    Symmetric Binary Tree --> it form a mirror of itself
                                ariund the center on root.

*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
struct TreeNode{
    int data;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int val){
        data = val;
        right=left = nullptr;
    }
};


class Solution{
    public:

bool isSymmetric(TreeNode* root){
    if(!root) return true;  // empty tree is symmetric
    return checkSymmetry(root->left, root->right);
}

bool checkSymmetry(TreeNode* leftnode, TreeNode* rightnode){
    if(!leftnode && !rightnode) return true;
    if(!leftnode || !rightnode) return false;
    if(leftnode->data != rightnode->data) return false;

    return checkSymmetry(leftnode->left, rightnode->right) &&
           checkSymmetry(leftnode->right, rightnode->left);
}


};


int main(){

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);

    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(4);
    root->right->left->right = new TreeNode(6);

    Solution obj;
    cout<<obj.isSymmetric(root);
/*
        1
     2     2
   4   5 5   4
      6    6

*/

return (0);
}