/*
    Left side view of binary Tree

*/


#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
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

    vector<int> leftView(TreeNode* root){
        
        vector<int> ans;
        if(!root) return ans;
        map<int, int> mpp;
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});

        while(!q.empty()){

            auto p = q.front();
            q.pop();
            TreeNode* node = p.second;
            int level = p.first;

            if(mpp.find(level) == mpp.end()) mpp[level] = node->data;
            
            if(node->left) q.push({level+1, node->left});
            if(node->right) q.push({level+1, node->right});
        }

        for(auto it: mpp){
            ans.push_back(it.second);
        }

        return ans;
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
    vector<int> traversal = obj.leftView(root);
/*
        1
     2      3
   4   5   6   7
      8         9


*/
    
    for(auto i: traversal){
            cout << i << " ";
    }

return (0);
}