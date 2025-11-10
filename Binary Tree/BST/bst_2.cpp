/*
    Ceil in BST

    minimum greater that a given value

    
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

    int findceil(TreeNode* root, int val){
        int ceil = -1;

        while(root){

            if(root->data == val){
                ceil = root->data;
                return ceil;
            }
            if(root->data > val){
                ceil = root->data;
                root = root->left;
            }else{
                root = root->right;
            }

        }

        return ceil;
    }
};

int main(){


    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;

    cout<<sol.findceil(root, 4);
return (0);
}