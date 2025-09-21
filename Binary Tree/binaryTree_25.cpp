/*
    Lowest Comman Ancestor
*/


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct TreeNode{
    int val ;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
        left = right = nullptr;
    }
};


class Solution{
    public:
        TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q){
            // Base Condition
            if(root == nullptr || root == p || root == q){
                return root;
            }

            TreeNode* left = findLCA(root->left, p, q);
            TreeNode* right = findLCA(root->right, p , q);
            if(left == nullptr){
                return right;
            }
            else if(right == nullptr){
                return left;
            }
            else{
                return root;
            }
            
        }
};

int main(){
    TreeNode*  root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new  TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left = new TreeNode(6);
    
    Solution sol;

    TreeNode* ans = sol.findLCA(root, root->left, root->left->left);

    cout<<ans->val;

return (0);
}

