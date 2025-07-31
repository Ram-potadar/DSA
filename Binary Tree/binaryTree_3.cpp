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

Node* find(int val, Node* node){

    if(node == nullptr) return nullptr;
    if(node->data == val) return node;
    cout<<"\nCalling left  child of "<<node->data;
    Node* leftresult = find(val, node->left);
    if(leftresult) return leftresult;
    cout<<"\nCalling right child of "<<node->data;
    return find(val, node->right);

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

    cout<<"Node found at node: ";

    Node* found = find(4, root);
    cout<<"\nData at node is: "<<found->data;
    return (0);
}