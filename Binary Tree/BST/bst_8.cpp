/*
    Check the whether the given tree is binary tree or not 

    Validate the bianry Tree
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;

struct TreeNode{
    int data ;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        data = val;
        left = right = nullptr;
    }
};

class Solution{
    public:

    bool validateBST(TreeNode* root){
        return isBST(root, INT_MAX, INT_MIN);
    }


    bool isBST(TreeNode* root, int maxVal, int minVal){
        if(!root) return true;

        if(root->data >= maxVal || root->data <= minVal) return false;

        return isBST(root->left, root->data, minVal) && isBST(root->right, maxVal, root->data);
    }
   
};

int main(){


    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;

    cout << sol.validateBST(root);

return (0);
}