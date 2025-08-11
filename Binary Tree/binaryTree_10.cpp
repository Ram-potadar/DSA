/*
    MAximum Depth of Binarry Tree
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        data = val;
        left = right = nullptr;
    }
};


int maxDepth(TreeNode* root) {
    if(root == nullptr) return 0;

    int l = maxDepth(root->left);
    int r = maxDepth(root->right);

    return 1 + max(l, r);
}


int main(){

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(8);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(9);

    cout<<maxDepth(root);

return 0;
}