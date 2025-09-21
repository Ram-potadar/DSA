/*

*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

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
    int maxWidth(TreeNode* root){
        if(!root) return 0;
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){

            int size = q.size();
            int mmin = q.front().second;
            int first, last;
            for(int i = 0; i < size; i ++){
                int curr_id = q.front().second-mmin;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0) first = curr_id;
                if(i==size-1) last = curr_id;
                if(node->left)
                    q.push({node->left, curr_id*2+1});
                if(node->right)
                    q.push({node->right, curr_id*2+2});
            }

            ans = max(ans, last-first+1);

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

    /*
        1
     2      3
   4   5   6   7
      8         9


*/
    Solution obj;
    cout<<obj.maxWidth(root);
return (0);
}