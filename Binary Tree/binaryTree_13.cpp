/*
    Calculating the Diameter of the tree-->>


*/

#include<iostream>
#include<algorithm>
#include<vector>
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

int maxi = 0;
int diameterOfTree(TreeNode* root) {
    if(root == nullptr) return 0;

    int l = diameterOfTree(root->left);
    int r = diameterOfTree(root->right);
    maxi = max(maxi, l+r);

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

    cout<<diameterOfTree(root);

return (0);
}