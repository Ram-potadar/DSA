/*


*/

#include<iostream>
#include<stack>
#include<vector>
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

int totalSum(vector<int>& nums){
    int n = nums.size();
    vector<int> nse = findNSE(nums);
    vector<int> pse = findPSEE(nums);

    for(int i : nse){
        cout<<i<<", "; 
    }
    cout<<endl;
    for(int i : pse){
        cout<<i<<", ";
    }
    cout<<endl;
    int sum = 0;
    for(int i = 0; i < n; i ++){
        int left = i - pse[i];
        int right =  nse[i] - i;
        sum = sum + (nums[i] * left * right );
    }

    return sum;
}
int main(){

    vector<int> nums = {5, 1, 2, 7};
    cout<<totalSum(nums);
return (0);
}