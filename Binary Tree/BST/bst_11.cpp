/*
    BST Iterator
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<Stack>

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
    private:
    stack<TreeNode* > st;

    public:
    Solution(TreeNode* root){
        pushAll(root);
    }

    bool hasNext(){
        return !st.empty();
    }

    int next(){
        TreeNode* tempNode = st.top();
        st.pop();
        pushAll(tempNode->right);
        return tempNode->data;
    }


    private:

        void pushAll(TreeNode* node){
            for(; node != nullptr ; st.push(node), node = node->left);
        }
};



int main(){


    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol(root);

    cout<<sol.next()<<endl;
    cout<<sol.next()<<endl;
    cout<<sol.next()<<endl;
    cout<<sol.hasNext();


return (0);
}