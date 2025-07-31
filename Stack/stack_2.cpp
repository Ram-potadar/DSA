/*
Implementing Stack using linked list ->

*/

#include<iostream>
using namespace std;


class S{

    public:
    struct Node{
        int data;
        Node* next;
        Node(int val){
            data = val;
            next = nullptr;
        }
    };

    Node* top ;
    int size = 0;
    void push(int x){
        Node* temp = new Node(x);
        temp -> next = top;
        top = temp;
        size ++;
    }

    void pop(){
        Node* temp = top;
        top = top -> next;
        delete temp;
        size --;
    }

    int getTop(){
        return top->data;
    }
    int getSize()
    { 
        return size;
    }
};


int main(){

    S st;

    st.push(23);
    st.push(2);
    st.push(21);
    st.pop();
    st.pop();
    cout<<st.getTop();


return (0);
}