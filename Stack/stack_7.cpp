/* 
                
                   
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
    for(int i = (2*n - 1); i >= 0; i --){
        
        while(!(st.empty()) && nums[i%n]>=st.top())   
            st.pop();
        
        if( i < n){
            ele[i] = st.empty()? -1: st.top();
        }
        st.push(nums[i%n]);
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