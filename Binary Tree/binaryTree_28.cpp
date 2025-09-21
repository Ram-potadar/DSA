/*
    Nodes at distance k
*/


#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val ){
        data = val;
        right = left = nullptr;
    }
};

class Solution{

    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track){

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* current = q.front(); 
            q.pop();

            if(current->left){
                parent_track[current->left] = current;
                q.push(current->left);
            }

            if(current->right){
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }

    public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k){

        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParents(root, parent_track);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        int curr_level=0;
        visited[target] = true;

        while(!q.empty()){

            int size = q.size();
            if(curr_level++ == k) break;

            for(int i = 0; i < size; i ++){
                TreeNode* current = q.front();
                q.pop();

                if(current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if(parent_track.find(current) != parent_track.end() && !visited[parent_track[current]]){
                    q.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->data);
            q.pop();
        }

        return ans;
    }
};


int main(){

    TreeNode* root = new TreeNode(23);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);

    Solution sol;
    vector<int> ans =  sol.distanceK(root, root->left, 2);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}
