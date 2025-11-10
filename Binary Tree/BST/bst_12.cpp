/*
    2 Sum Problem in BST
*/


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

class BSTiterator{
    private:
    stack<TreeNode* > st;
    bool reverse = true;

    // reverse -> true -> next
    // reverse -> false -> before


    public:
        BSTiterator(TreeNode* root, bool isReverse ){
            reverse = isReverse;
            pushAll(root);

        }

        bool hasNext(){
            return !st.empty();
        }

        int next(){
            TreeNode* tempNode = st.top();
            st.pop();
            if(reverse){
                pushAll(tempNode->right);
            }else{
                pushAll(tempNode->left);
            }
            return tempNode->data;
        }


    private:

        void pushAll(TreeNode* node){
            while(node){
                
                st.push(node);
                if(reverse){
                    node = node->left;
                }else{
                    node = node->right;
                }
            }
        }
};

class Solution{


    public:

    bool findTarget(TreeNode* root, int target){

        if(!root ) return false;
        BSTiterator l(root, true); // next
        BSTiterator r(root, false); // before
        
        int i = l.next();
        int j = r.next();
        while(i < j){
            if(i+j == target) return true;

            else if(i + j < target) i = l.next();

            else j = r.next();
        }

        return false;
    }

};

int main(){


    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;

    cout<<sol.findTarget(root, 30);


return (0);
}