/*
    Max area in the Histogram  

    --> Optimised approach 
    

*/



#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int maxArea(vector<int>& nums){
    int n = nums.size();
    stack<int> st;
    int maxArea = 0;
    int nse, pse;
    for(int i = 0; i< n; i++){

        while(!(st.empty()) && nums[st.top()] > nums[i]){

            int ele = st.top();
            st.pop();

            nse = i;
            pse = st.empty() ? -1:st.top();
            maxArea = max((nums[ele] * (nse - pse - 1)), maxArea);
        }

        st.push(i);
    }

    while(!(st.empty())){
        int ele = st.top();
        st.pop();

        nse = n;
        pse = st.empty() ? -1:st.top();

        maxArea = max((nums[ele] * (nse - pse - 1)), maxArea);

    }

    return maxArea;

}
int main(){
vector<int> nums = {3, 2, 10, 11, 5, 10, 6, 3};

cout<<maxArea(nums);
return (0);
}