/*
    Inserting the node in the bst
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

    TreeNode* insertInto(TreeNode* root, int val){
        if(!root) return new TreeNode(val);

        TreeNode* curr = root;
        while(true){

            if(curr->data <= val){
                if(curr->right!=nullptr) curr = curr->right;

                else{
                    curr->right = new TreeNode(val);
                    break;
                }
            }else{
                if(curr->left != nullptr) curr= curr->left;
                else{
                    curr->left = new TreeNode(val);
                    break;
                }
            }
            
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

    cout<<sol.insertInto(root, 6);
return (0);
}