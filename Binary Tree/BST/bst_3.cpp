/*
    floor in BST

    maximum possible smaller than the given val

    
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

    int findfloor(TreeNode* root, int val){
        int floor = -1;

        while(root){

            if(root->data == val){
                floor = root->data;
                return floor;
            }
            if(root->data > val){
                root = root->left;
            }else{
                floor = root->data;
                root = root->right;
            }

        }

        return floor;
    }
};

int main(){


    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;

    cout<<sol.findfloor(root, 6);
return (0);
}