/*
Neareast Smaller integer 
    Same as of NGE

*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;
  
vector<int> nereastSmallerEle(vector<int>& nums){

    stack<int> st;
    vector<int> ele(nums.size());
    for(int i = 0;i < nums.size(); i ++){
        while(!(st.empty()) && st.top() >= nums[i]){
            st.pop();
        }

        if(st.empty()){
            ele[i] = -1;
        }
        else{
            ele[i] = st.top();
        }
        st.push(nums[i]);

    }
    return ele;

}


int main(){

        vector<int> nums = {4, 12, 5, 3, 1 , 8, 5, 3, 1, 2, 4, 6};

    vector<int> el = nereastSmallerEle(nums);

    for(int i = 0; i < nums.size(); i ++){
        cout<<el[i]<<" ";
    }

return (0);
}