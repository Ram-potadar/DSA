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

    // cout<<"\nCalling left  child of "<<node->data;

    Node* leftresult = find(val, node->left);
    if(leftresult) return leftresult;

    // cout<<"\nCalling right child of "<<node->data;

    return find(val, node->right);

}

void addleft(Node* root){
    cout<<"Enter where to add left child: ";
    int parentNodeData ;
    cin>>parentNodeData;
    
    Node* parentNode = find(parentNodeData, root);

    int childNodeData;
    cout<<"\nEnter the data of child node: ";
    cin>>childNodeData;

    parentNode->left = new Node(childNodeData);
}


void addright(Node* root){
        cout<<"Enter where to add right child: ";
    int parentNodeData ;
    cin>>parentNodeData;
    
    Node* parentNode = find(parentNodeData, root);

    int childNodeData;
    cout<<"\nEnter the data of child node: ";
    cin>>childNodeData;

    parentNode->right = new Node(childNodeData);
}


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

    Node* root = nullptr;


    while(true){
    cout<<"\n\n||------- Binary Tree Menu-------------||\n\n";
    cout<<"Enter 1 to create root node.\n";
    cout<<"Enter 2 to create left node.\n";
    cout<<"Enter 3 to create right node.\n";
    cout<<"Enter 4 to print by using Inorder node.\n";
    cout<<"Enter 5 to print by using Preorder node.\n";
    cout<<"Enter 6 to print by using Postorder node.\n";
    cout<<"Enter 7 to exit.\n\n";
    cout<<"Enter your choice: ";

    int val ;
    cin>>val;
    cout<<endl;


    switch (val)
    {
    case 1:
        
        if(root != nullptr){
            cout<<"Oop's!! Root node already exist..\n!!";
        }else{
            int data;
            cout<<"Enter the data to store in root node: ";
            cin>>data;
            cout<<endl;
            root = new Node(data);
        }
        break;

        case 2:
            addleft(root);
            break;
        case 3:
            addright(root);
            break;
        case 4:
            cout<<"Inorder Traversal: ";
            inorder(root);
            cout<<endl;
            break;
        case 5:
            cout<<"Preorder Traversal: ";
            preorder(root);
            cout<<endl;
            break;
        case 6:
            cout<<"Postorder Traversal: ";
            postorder(root);
            cout<<endl;
            break;
        case 7:
            cout<<"Thank you!!\n";
            return 0;
        default:
            cout << "Invalid choice!\n";


    }

    }
return (0);
}