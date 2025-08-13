/*

    Maximum depth of tree-->
        - Recursive 
        - Level order traversal
    
*/

#include<iostream>

#include<queue>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        data = val;
        left = right = nullptr;
    }
};


int maxDepthRecursive(TreeNode* root){

    if (root == nullptr) return 0;

    int lh = maxDepthRecursive(root->left);
    int rh = maxDepthRecursive(root->right);

    return 1+max(lh, rh);
}

int maxDepthLevlOrder(TreeNode* root){
    queue<TreeNode*> q;
    int depth = 0;
    if (!root) return 0;
    q.push(root);

    while(!q.empty()){

        int levelSize = q.size();
        for(int i = 0; i < levelSize; i ++){
            TreeNode* currentNode = q.front();
            q.pop();

            if(currentNode->left) q.push(currentNode->left);
            if(currentNode->right) q.push(currentNode->right);
        }
        depth++;
    }

    return depth;

}

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

    cout<<maxDepthRecursive(root)<<endl;
    cout<<maxDepthLevlOrder(root);

return (0);
}