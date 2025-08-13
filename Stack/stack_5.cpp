/*
Implementing Min elemnet using stack ->
    1. write the push() funciton for this 
    2. write the pop()funciton 
    3. write the top and getMin() funciton 

    -> Maintain a variable minVal to store the current minimum.
    -> When pushing a new value that is less than the current min, encode it and update minVal.
    -> During pop, if the top is encoded, decode the previous minimum.


*/


#include<iostream>
#include<stack>
#include<limits.h>
using namespace std;
  
class Stack{
    public:
    stack<int> st;
    int minVal = INT_MAX;

    void push(int val){
        if((st.empty())){
            st.push(val);
            minVal = val;
        }
        else{
            if(val>minVal){
                st.push(val);
            }else{
                st.push(2*val - minVal);
                minVal = val;
            }
        }
  }

  void pop(){
    if(st.empty()) return;

    int x = st.top();
    st.pop();

    if(x<minVal){
        minVal = 2*minVal - x;
    }
  }

  int top(){
    int x = st.top();
    if(x<minVal) return minVal;
    else return st.top();
  }

  int getMin(){
    return minVal;
  }

};

int main(){
Stack s;
s.push(-2);
s.push(0);
s.push(-3);
cout<<"min: "<<s.getMin()<<endl;
s.pop();
cout<<"top: "<<s.top()<<endl;
cout<<"min: "<<s.getMin()<<endl;


return (0);
}