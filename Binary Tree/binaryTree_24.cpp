/*
    Root to node path

*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
        left = right = nullptr;
    }
};  

class Solution{

    public:

    vector<int> findPath(TreeNode* root, int target){
        vector<int> path;

        if(!root)   return path;
        rootToPath(root, target, path);
        return path;
    }


    bool rootToPath(TreeNode* node, int target, vector<int>& path){

        if(!node) return false;

        path.push_back(node->val);

        if(node->val == target) return true;

        if( rootToPath(node->left, target, path) || rootToPath(node->right, target, path))
            return true;

        path.pop_back();
        return false;
    }

};
int main(){

    TreeNode* root = new TreeNode(23);
    root->left = new TreeNode(12);
    root->right = new TreeNode(34);
    root->right->right = new TreeNode(25);


    Solution sol;
    vector<int> roottonodePath = sol.findPath(root, 25);
    for(int i : roottonodePath){
        cout<<i<<" ";
    }

return (0);
}