/*
    Time taken to burn the complete tree
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        right = left = nullptr;
    }
};

class Solution {
public:
    // This function maps each node to its parent and returns the target node
    TreeNode* parentTracker(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, int k) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res = nullptr;

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (k == current->data) res = current;

            if (current->left) {
                parent_track[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
        return res;
    }

    int timeTaken(TreeNode* root, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        TreeNode* targetNode = parentTracker(root, parent_track, k);

        if (!targetNode) return 0; 

        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;
        q.push(targetNode);
        visited[targetNode] = true;

        int maxi = 0;

        while (!q.empty()) {
            int size = q.size();
            bool flag = false;

            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();

                if (current->left && !visited[current->left]) {
                    flag = true;
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if (current->right && !visited[current->right]) {
                    flag = true;
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if (parent_track.find(current) != parent_track.end() && !visited[parent_track[current]]) {
                    flag = true;
                    q.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
            if (flag) maxi++;
        }
        return maxi;
    }
};

int main() {
    TreeNode* root = new TreeNode(23);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);

    Solution sol;
    cout << sol.timeTaken(root, 2);  // start burning from node with value 2

    return 0;
}
