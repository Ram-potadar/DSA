/*
    Zig-Zag Traversal

*/


#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode{
    int data;
    TreeNode* left ;
    TreeNode* right ;

    TreeNode(int val){
        data = val;
        left = right = nullptr;
    }
};

class Solution{
    public:

    vector<vector<int>> zigzag(TreeNode* root){
        vector<vector<int>> result;
        if(!root) return {};
        queue<TreeNode*> q;
        int levelSize = 0;
        bool leftToright = true;
        q.push(root);
        while(!q.empty()){
            levelSize = q.size();
            vector<int> row(levelSize);
            
            for(int i = 0; i  < levelSize; i ++){
                
                TreeNode* node = q.front();
                q.pop();
                int idx = leftToright ? i:levelSize - 1 - i;

                row[idx] = node->data;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            leftToright = ! leftToright;
            result.push_back(row);
        }

        return result;
    }
    

};
int main(){

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(12);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(11);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    Solution obj;
    vector<vector<int>> res = obj.zigzag(root);

    for(auto &row : res){
    for(int val : row){
        cout << val << " ";
    }
    cout << endl;
}

return (0);
}

