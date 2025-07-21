/*
Finding peak element in the 2D Matrix

*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>

using namespace std;

class Binary{
    public:
    int findMax(vector<vector<int>> &nums, int rows, int cols, int mid){
        int maxi = INT_MIN;
        int maxi_row = 0;
        for(int i = 0; i < rows; i ++){
            if(nums[i][mid] > maxi){
                maxi_row = i;
                maxi = nums[i][mid];
            }
        }
        return maxi_row;
    }


    vector<int> search(vector<vector<int>> &nums){
        int rows = nums.size(), cols = nums[0].size(), low = 0, high = nums[0].size();
        vector<int> ans;
        while(low<=high){
            int mid = (low+high) / 2;

            int row = findMax(nums, rows, cols, mid);
            int left = mid - 1 >= 0 ? nums[row][mid-1]:-1;
            int right = mid - 1 >= 0 ? nums[row][mid+1]:-1;
            if(nums[row][mid] > left && nums[row][mid] > right){
                ans.push_back(row);
                ans.push_back(mid);
                return ans;
            }else if(left > nums[row][mid]) high = mid - 1;
            else low = mid + 1;
        }
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }

    };

int main() {
    vector<vector<int>> nums = {{4,2,5,1,4,5}, {2,9,3,2,3,2}, {1,7,6,0,1,3}, {3,6,2,3,7,2}};

    Binary obj;

    vector<int> ans = obj.search(nums);
    for(int i : ans)
        cout<<i<<" ";
    return 0;
}