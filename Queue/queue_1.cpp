/*
    Queue using array -->

*/

#include<iostream>
using namespace std;

class Queue{

    public:
    int start = -1, end = -1, currSize = 0, size = 10, qu[10];
 

    void push(int data){
        if(currSize==size)
        {cout<<"Queue overflow..";
        return;}
       if(currSize==0)
       {
        start = end = 0;
        qu[end] = data;
       }else{
        end = (end+1)%size;
        qu[end] = data;
        currSize+=1;
       }
    }

  int pop() {
    if(currSize == 0) {
        cout << "Oops queue is empty..\n";
        return -1; // or handle appropriately
    }
    int el = qu[start];
    if(currSize == 1) {
        start = end = -1;
    } else {
        start = (start + 1) % size;
    }
    currSize -= 1;
    return el;
}

    int top(){
        if(currSize==0) cout<<"Queue is empty..";

        return qu[start];
    }
    int getSize(){
        return currSize;
    }
   
};
  
int main(){

    Queue q;
    q.push(12);
    q.push(13);
    q.push(3);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.top();
return (0);
}