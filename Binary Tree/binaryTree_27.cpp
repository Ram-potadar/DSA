/*
    Childern Sum Property in Binary Tree
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

    void changeTree(TreeNode* root){

        if(!root) return;
        int child ;
        if(root->left) child += root->left->data;
        if(root->right) child += root->right->data;
        

        if(child >= root->data) root->data = child;
        else{
            if(root->left) root->left->data = root->data;
            else if(root->right) root->right->data = root->data;
        }

        changeTree(root->left);
        changeTree(root->right);
        
        
        int tot = 0;
        if(root->left) tot += root->left->data;
        if(root->right) tot += root->right->data;
        if(root->left || root->right) root->data = tot;
    }
    
};



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


    Solution obj;
    obj.changeTree(root);


return (0);
}