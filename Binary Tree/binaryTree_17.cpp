/*
Boundary Traversal

*/

#include<iostream>
#include<stack>
#include<vector>
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



class Solution{

    bool isLeaf(TreeNode* node){
        return (!node->left && !node->right);
    }

    void addLeftNodes(TreeNode* node, vector<int>& res){
            TreeNode* currentNode = node->left;
            while(!isLeaf(currentNode) && currentNode){
                res.push_back(currentNode->data);
                if(currentNode->left) currentNode = currentNode->left;
                else currentNode = currentNode->right;
            }

    }

    void addLeafNodes(TreeNode* node, vector<int>& res){
        if(isLeaf(node)){
            res.push_back(node->data);
            return;
        }
        if(node->left) addLeafNodes(node->left, res);
        if(node->right) addLeafNodes(node->right, res);
    }

    void addRightNodes(TreeNode* node, vector<int>& res){
            TreeNode* currentNode = node->right;
            vector<int> temp;

            while(!isLeaf(currentNode) && currentNode){
                temp.push_back(currentNode->data);
                if(currentNode->right) currentNode = currentNode->right;
                else currentNode = currentNode->left;
            }

            for(int i = temp.size() - 1; i >= 0; i --){
                res.push_back(temp[i]);            
            }
    }

    public:
    vector<int> boundaryTraversal(TreeNode* root){
        vector<int> res;
        if(root){
            res.push_back(root->data);
            addLeftNodes(root, res);
            addLeafNodes(root, res);
            addRightNodes(root, res);
            return res;
        }
        return res;
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
    vector<int> traversal = obj.boundaryTraversal(root);
/*
        1
     2      3
   4   5   6   7
      8         9


*/
    for(int i = 0; i < traversal.size(); i++){
        cout<<traversal[i]<<" ";
    }
return (0);
}