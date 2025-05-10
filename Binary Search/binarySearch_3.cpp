/*
  Lower bound -> samallest index such that (arr[idx] >= x) following 
is the code for finding the lower boiund of the a given array
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Binary {
    public:

    int search(vector<int> &nums, int target){
        int ans = nums.size(), low = 0, high = nums.size() - 1;
        int mid =0;

        while (low<=high)
        {
            mid = (low+high)/2;
            if(nums[mid] >= target){
                ans = mid;
                high = mid -1;
            }
            else 
                low = mid + 1;
        }
        
    }

};
int main() {
    vector<int> nums = {1,2,3,5,6,8};

    Binary obj;
    cout<<"the lower bound of is at index "<<obj.search(nums,4);
    return 0;
}