#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }

};


int main() {

    Node* root = new Node(1);
    root->left = new Node(19);
    root->left->left = new Node(29);
    root->right = new Node(10);

    /*
                1
            19      10
        29
    
    */

    cout<<"Data at root node "<<root->data<<endl;
    cout<<"data at root->left "<<root->left->data<<endl;
    cout<<"data at root->left->left "<<root->left->left->data<<endl;

    return 0;
}