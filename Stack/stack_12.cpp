/*

Maximum Rectangle

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

int maxRectangle(vector<vector<int>>& mat){
    int n = mat.size(), m = mat[0].size(), sum = 0, maxA = 0;

    vector<vector<int>> prefixSum(n, vector<int>(m));

    for(int i = 0; i < n; i ++){
        sum = 0;
        for(int j = 0; j < m; j ++){

            sum += mat[i][j];
            if(mat[i][j]== 0) sum = 0;
            prefixSum[i][j] = sum;
        }
    }

    for(int i = 0; i < n;i ++){

        maxA = max(maxA, maxArea(prefixSum[i]));
    }
    return maxA;


}
int main(){

    vector<vector<int>> matrix = {{1, 0, 1, 0, 1},
                                  {1, 0, 1, 1, 1},
                                  {1, 1, 1, 1, 1},
                                  {1, 0, 0, 1, 0}};

    cout<<maxRectangle(matrix);

return (0);
}