/*
    Counting no of nodes of complete binary tree
*/


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
 
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        right = left = nullptr;
    }
};

class Solution{
    public:
    int heightleft(TreeNode* root){
        int height = 0;
        while(root){
            height++;
           root =  root->left;
        }

        return height;
    }

    int heightright(TreeNode* root){
        int height = 0;
        while(root){
            height++;
            root = root->right;
        }

        return height;
    }

    int countNodes(TreeNode* root){
        if(!root) return 0;

        int lh = heightleft(root);
        int rh = heightright(root);

        if(lh == rh) return (1 << lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

};

int main(){

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;

    cout<<sol.countNodes(root);
    return (0);
}
