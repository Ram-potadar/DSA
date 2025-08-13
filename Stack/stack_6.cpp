/*
    Next Greates Number - I

    1. Traverse the array from right to left, and use a stack to keep track of potential next greater elements.
    2. For each element, pop all smaller or equal elements from the stack (since they can't be the next greater for any previous elements).
    3. The top of the stack (if any) after popping is the next greater element; if the stack is empty, the next greater element is -1. Then, push the current element onto the stack.
    
*/


#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;



vector<int> nextGrearterEle(vector<int>& nums){
    stack<int> st;
    int n = nums.size();
    vector<int> ele(n);

    for(int i = n - 1; i >= 0; i --){

        while(!(st.empty()) && nums[i]>=st.top()){
            st.pop();
        }

        if(st.empty()){
            ele[i] = -1;
        }else{
            ele[i] = st.top();
        }
        st.push(nums[i]);
    }
    return ele;
}
      
int main(){

    vector<int> nums = {4, 12, 5, 3, 1 , 8, 5, 3, 1, 2, 4, 6};

    vector<int> el = nextGrearterEle(nums);

    for(int i = 0; i < nums.size(); i ++){
        cout<<el[i]<<" ";
    }

return (0);
}