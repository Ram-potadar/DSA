/*
    Max area in the Histogram  

    

*/



#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
vector<int> findNSE(vector<int>& nums){
    int n = nums.size();
    vector<int> NSE(n);
    stack<int> st;

    for(int i = n-1; i >= 0; i --){

        while(!(st.empty()) && nums[st.top()] >= nums[i])
            st.pop();

        NSE[i] = st.empty() ? n:st.top();

        st.push(i);
    }
    return NSE;
}


vector<int> findPSEE(vector<int>& nums){
    int n = nums.size();
    vector<int> PSEE(n);
    stack<int> st;

    for(int i = 0;i < n; i ++){

        while(!(st.empty()) && nums[st.top()] > nums[i])
            st.pop();

        PSEE[i] = st.empty() ? -1:st.top();

        st.push(i);
    }
    return PSEE;
}

int maxArea(vector<int>& nums){
    int n = nums.size();
    vector<int> nse = findNSE(nums);
    vector<int> pse = findPSEE(nums);
    int maxarea = 0;
    for(int i = 0; i < n; i ++){
        int area = nums[i] * (nse[i] - pse[i] - 1);
        maxarea = max(area, maxarea);
    }
    return maxarea;
}
int main(){
vector<int> nums = {2, 1, 5, 6, 2, 3};

cout<<maxArea(nums);
return (0);
}