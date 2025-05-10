/*
    In this we find the how many times array rotated.
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include <limits.h> 

using namespace std;
class  binary {
    public:
        int search_minimum(vector<int> &nums){
            int low = 0, high = nums.size() - 1, mid , ans = INT_MAX, min_idx;

            while(low<=high){
                mid = (low+high) / 2;

                if(nums[low] <= nums[mid]){                 // Tells whether left side is sorted or not
                    if(nums[mid] < ans){
                        ans = nums[mid];
                        min_idx = mid;
                    }
                    ans = min(ans, nums[low]);
                    low = mid + 1;
                }
                else{
                    if(nums[low] < ans){
                        ans = nums[low];
                        min_idx = low;
                    }
                    high = mid - 1;
                }
            }
            return min_idx;
        }
};

int main() {

    vector<int> nums = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    binary obj;
    cout<<"The minimum value in the array "<<obj.search_minimum(nums);
    
    return 0;
}