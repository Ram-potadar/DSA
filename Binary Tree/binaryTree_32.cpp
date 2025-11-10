/*
    Construct the binary tree using postorder and inorder
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    TreeNode* constructTree(vector<int> &postorder, vector<int> &inorder) {
        map<int, int> inMpp;


        for (int i = 0; i < inorder.size(); i++) {
            inMpp[inorder[i]] = i;
        }

        return buildBT(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, inMpp);
    }

private:
    TreeNode* buildBT(vector<int> &postorder, int ps, int pe,
                      vector<int> &inorder, int is, int ie,
                      map<int, int> &inMpp) {
        if (ps > pe || is > ie) {
            return nullptr;
        }


        TreeNode* root = new TreeNode(postorder[pe]);

        int iR = inMpp[postorder[pe]];   
        int nl = iR - is;              


        root->left = buildBT(postorder, ps, ps + nl - 1, inorder, is, iR - 1, inMpp);
        root->right = buildBT(postorder, ps + nl, pe - 1, inorder, iR + 1, ie, inMpp);

        return root;
    }
};


int main() {
    Solution sol;

    vector<int> inorder   = {-1};
    vector<int> postorder = {-1};

    TreeNode* root = sol.constructTree(postorder, inorder);


    return 0;
}
