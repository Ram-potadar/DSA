/*
    Construct the BST using preorder
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

    TreeNode* constructBST(vector<int> preorder){
        int i = 0;
        return buildTree(preorder, i, INT_MAX);
    }
    TreeNode* buildTree(vector<int> preorder, int& i, int bound){

        if(i == bound.size() || preorder[i] > bound) return nullptr;

        TreeNode* root = new TreeNode(preorder[i++]);

        root->left = buildTree(preorder, i, root->val);
        root->right = buildTree(preorder, i, bound);
        return root;
    }
};

int main(){


    vector<int> prorder = {8, 3, 1, 6, 4, 7, 10, 14, 13};

    Solution sol;

    cout << sol.constructBST(preorder);

return (0);
}