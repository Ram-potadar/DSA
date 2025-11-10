/*
    Construct the binary tree using inorder and preorder
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
    TreeNode* buildTree(vector<int> preorder, vector<int> inorder){

        map<int, int> inMpp;


        for(auto i = 0; i < inorder.size(); i ++){
            inMpp[i] = i;
        } 

        TreeNode* root = buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size(), inMpp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preoder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &inMpp){

        if(preStart>preEnd || inStart>inEnd) return nullptr;

        TreeNode* root = preoder[preStart];

        int inRoot = inMpp[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildTree(preoder,  preStart + 1, preStart + numsLeft, inorder, inStart, inRoot-numsLeft, inMpp);

        return root;
    }

};


int main(){


    

return (0);
}