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
        map<int, int> mpp;
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});

        while(!q.empty()){

            auto p = q.front();
            q.pop();
            TreeNode* node = p.second;
            int level = p.first;

            if(mpp.find(level) == mpp.end()) mpp[level] = node->data;
            
            if(node->left) q.push({y+1, node->left});
            if(node->right) q.push({y+1, node->right});
        }

        for(auto it: mpp){
            ans.push_back(it.second);
        }

        return ans;
    }

};