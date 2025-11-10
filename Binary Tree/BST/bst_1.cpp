/*
    Search in BST

*/

#include<iostream>
#include<algorithm>
#include<vector>

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

    TreeNode* searchBST(TreeNode* root, int val){
        while(root != nullptr && root->data != val){

            root = val < root->data? root->left:root->right;
        }
        return root;
    }
};


int main(){
TreeNode* root = new TreeNode(4);
root->left = new TreeNode(2);
root->right = new TreeNode(7);

root->left->left = new TreeNode(1);
root->left->right = new TreeNode(3);


    Solution sol;

    cout<<sol.searchBST(root, 4);

return 0;
}