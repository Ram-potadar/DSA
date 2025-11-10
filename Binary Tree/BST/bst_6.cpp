/*
    Kth smallest element in BST
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

    int KthSmallest(TreeNode* root, int k){
        if(!root) return 0;
        int i = 0;
        return findkthSmallest(root, k, i);
    }

    int findkthSmallest(TreeNode* root, int k, int &i){

        if(!root) return -1;

        int left = findkthSmallest(root->left, k, i);
        if(left != -1) return left;

        i++;
        if(i == k) return root->data;

        return findkthSmallest(root->right, k, i);


    }
};

int main(){


    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;

    cout<<sol.KthSmallest(root, 3);
return (0);
}