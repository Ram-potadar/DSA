/*
    Successor in the BST
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

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){

        TreeNode* successor ;

        while(root){

            if(root->data <= p->data){
                root = root->right;
            }else{
                successor = root;
                root = root->left;
            }
        }

        return successor;
    }
};bst_

int main(){


    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;

    cout << (sol.inorderSuccessor(root, root->left->right ))->data;

return (0);
}