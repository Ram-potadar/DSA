/*
    Inorder traversal(iterative approach)
        using stack:    
*/

#include<iostream>
#include<vector>
#include<stack>

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

vector<int> inorderTraversal(TreeNode* root){

        vector<int> inorder;
        stack<TreeNode*> st;
        TreeNode* node= root;
        while(true){

            if(node != nullptr){
                st.push(node);
                node = node -> left;
            }
            else{
                if(st.empty()) break;

                node = st.top();
                st.pop();
                inorder.push_back(node->data);
                node = node -> right;
            }
        }
        return inorder;

    }

int main(){

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(8);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(9);

    vector<int> order = inorderTraversal(root);
    for(int i : order){
        cout<<i<<" ";
    }
return (0);
}