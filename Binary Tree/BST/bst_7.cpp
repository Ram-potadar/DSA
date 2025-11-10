/*
    LCA in BST

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

    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if (root == nullptr) return nullptr;
        int curr = root->data;

        if(curr < p->data && curr < q->data){
            return lca(root->right, p, q);
        }
        if(curr > p->data && curr > q->data){
            return lca(root->left, p, q);
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

    TreeNode* ans = sol.lca(root, root->left->left, root->left->right);

    cout<<ans->data;
return (0);
}