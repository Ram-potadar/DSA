/*

Maximum path sum

*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;

class Solution{
    public:

    struct TreeNode
    {
        int data ;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int val){
            data = val;
            left = right = nullptr;
        }
    };
    
    int maxPathSum(TreeNode* root){
        int maxi = INT_MIN;
        maxPathDown(root, maxi);
        return maxi;
    }


    int maxPathDown(TreeNode* node, int& maxi){

        if(!node) return 0;

        int leftSum = max(0, maxPathDown(node->left, maxi));
        int rightSum = max(0, maxPathDown(node->right, maxi));


        maxi = max(maxi, leftSum + rightSum + node->data);

        return (node->data + max(leftSum , rightSum));

    } 

};


int main(){

    using TreeNode = Solution::TreeNode;

    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution obj;
    cout<<obj.maxPathSum(root);

return (0);
}