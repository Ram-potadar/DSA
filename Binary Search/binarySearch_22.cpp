#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;

class binary{

    public:
    int Min(vector<int> &nums){
        int mini = INT_MAX;
        for(int i = 0; i < nums.size(); i ++){
            mini = min(mini, nums[i]);
        }
        return mini;
    }

    int Max(vector<int> &nums){
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i ++){
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }
    bool canWePlace(vector<int> &nums, int dist, int cows){
        int cntCows = 1, last = nums[0];
        for(int i  = 1; i < nums.size(); i ++){
            if(nums[i] - last >= dist){
                cntCows ++;
                last = nums[i];
            }
        }

        if(cntCows >= cows) return true;
        else return false;



    }
    int search(vector<int> &nums, int cows){

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 1, high = nums[n-1] - nums[0], ans = -1;

        while(low<=high){
            int mid = (low+high)/2;

            if(canWePlace(nums, mid, cows)){
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

        return ans;
    }


};

int main() {
    vector<int> nums = {0,3,4,7,9,10};
    binary obj;
    cout<<obj.search(nums, 4);
    return 0;
}