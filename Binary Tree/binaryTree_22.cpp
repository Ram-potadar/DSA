/*
    Right View of Binary Tree

*/


#include<iostream>
#include<algorithm>
#include<vector>
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

    vector<int> rightView(TreeNode* root){

        vector<int> ans;
        if(!root) return ans;
        // map<int, int> mpp;
        queue< TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            
            int levelSize = q.size();
            
            for(int i = 0; i < levelSize; i ++){
                
                TreeNode* node = q.front();
                q.pop();

                if(i == levelSize-1) ans.push_back(node->data);
                
                if(node->left) q.push(node->left);
                if(node->right) q.push( node->right);
            }   
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
    vector<int> traversal = obj.rightView(root);
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