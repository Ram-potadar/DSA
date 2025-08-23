#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<iomanip> 
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data = val;
        left = right = nullptr;
    }
};

vector<int> levelOrderTraversal(TreeNode* root){
    vector<int> level;
    queue<TreeNode*> q;
    if (!root) return level;
    q.push(root);
    while(!q.empty()){

        int levelSize = q.size();
        for(int i = 0; i < levelSize; i ++){
            TreeNode* currentNode = q.front();
            q.pop();
            level.push_back(currentNode->data);
            if(currentNode->left) q.push(currentNode->left);
            if(currentNode->right) q.push(currentNode->right);
        }
    }

    return level;
}
void printTree(TreeNode* root, int space = 0, int gap = 5) {
    if(root == nullptr)
        return;

    // increase the distance between levels
    space += gap;

    // Process right child first
    printTree(root->right, space);

    // print current node after space
    cout << endl;
    cout << setw(space) << root->data << "\n";

    // Process left child
    printTree(root->left, space);
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

    printTree(root);

return (0);
}