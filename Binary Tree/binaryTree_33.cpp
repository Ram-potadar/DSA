/*
    Serialized and deserialized

*/


#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include <sstream>
using namespace std;


struct TreeNode
{
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

    string Serialize(TreeNode* root){

        if(!root) return "";

        string s = "";

        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            if(node == nullptr){
                s.append("#,");
            }
            else s.append(to_string(node->data)+',');
            if(node != nullptr){
                q.push(node->left);
                q.push(node->right);
            }
        }
        cout<<s;
        return s;
    }


    TreeNode* deserialized(string data){

        if(data.size() == 0) return nullptr;

        stringstream s(data);
        string str;
        getline(s, str, ',');

        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;

        q.push(root);
        while (!q.empty())
        {
            TreeNode* node = q.front();

            q.pop();

            getline(s, str, ',');
            if(str == "#"){
                node->left = nullptr;
            }else {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');
            if(str == "#"){
                node->right = nullptr;
            }else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
        
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
    string str = obj.Serialize(root);
    cout<<obj.deserialized(str);


return (0);
}
