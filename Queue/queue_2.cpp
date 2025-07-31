/*
Implimenting Queue using linkedlist ->
*/

#include <iostream>
using namespace std;

class Q
{

    public:
    struct Node
    {
        int data;
        Node *next;
        Node(int val)
        {
            data = val;
            next = nullptr;
        }
    };

    Node* start=nullptr;
    Node* end=nullptr;
    int size=0;

    void push(int val){
        Node* temp = new Node(val);
        if(start == nullptr)
            start = end = temp;
        else 
            {end -> next = temp;
            end = temp;}
        size ++;
    }

    int pop(){
        if(start == nullptr){
            cout<<"Opps Queue is Empty...";
            return -1;
        }
        Node* temp;
        temp = start;
        start = start->next;
        int val = temp->data;
        size--;
        delete temp;
        return val;
    }

    int top(){
        if(start == nullptr){
            cout<<"Opps queue is empty";
            return -1;
        }
        return start->data;
    }
    int getsize(){
        return size;
    }


};

int main()
{

    Q q;
    q.push(5);
    q.push(6);
    q.push(7);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.top()<<endl;
    

    return (0);
}