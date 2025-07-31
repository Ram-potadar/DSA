#include<iostream>
using namespace std;
  

struct Node{

    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left=right=nullptr;
    }
};

void inorder(Node* node){
    if(node == nullptr) return;

    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

void preorder(Node* node){
    if(node == nullptr) return;

    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}

void postorder(Node* node){
    if(node == nullptr) return;

    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<" ";
}


int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);

    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(9);

    cout<<"Printing the tree using Inorder traversal: ";
    inorder(root);

    cout<<"\nPrinting the tree using Preorder traversal: ";
    preorder(root);

    cout<<"\nPrinting the tree using Postorder traversal: ";
    postorder(root);

return (0);
}