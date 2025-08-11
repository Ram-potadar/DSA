/*
    Inorder traversal(iterative approach)
        using stack:
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

vector<int> preorderTraversal(TreeNode *root)
{

    stack<TreeNode *> st;
    vector<int> preorder;
    if (root == nullptr)
        return preorder;


    st.push(root);
    while (!st.empty())
    {
        root = st.top();
        preorder.push_back(root->data);
        st.pop();

        if (root->right != nullptr)
        {
            st.push(root->right);
        }
        if (root->left != nullptr)
        {
            st.push(root->left);
        }
    }

    return preorder;
}

int main()
{

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(8);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(9);

    vector<int> order = preorderTraversal(root);
    for (int i : order)
    {
        cout << i << " ";
    }

    return (0);
}