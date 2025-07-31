/*
Stack using arrays-->


    Not dynamic in nature
    
*/

#include<iostream>
using namespace std;

class Stack{

    public:
    int top = -1, st[10];

    void push(int data){
        if(top>= 10) cout<<"Stack overflow!!\n";

        top += 1;
        st[top] = data;
    }

    int Top(){
        if(top == -1) cout<<"Sorry Stack is empty...\n";

        return st[top];
    }
    int pop(){
        if(top == -1) cout<<"Opps Stack is empty....\n";
        top = top - 1;
    }
    int size(){
        return top + 1;
    }

};

int main(){

    Stack stk;
    stk.push(10);
    stk.push(9);
    stk.push(12);
    stk.push(11);
    stk.pop();
    stk.pop();
    stk.pop();
    stk.pop();
    cout<<"Top: "<<stk.Top();
    



return (0);
}