/*
    In this we find the minimum value in the rotated sorted array.

    1. Find the sorted array(either left side or right side)
    2. find the min value in soreted array and say,
        min_val = first element of soreted array
    3. Elemenate the sorted array as we found the minimum value from it.
    4. Repeate the 1st step on the either of array which unsorted.


*/

#include<iostream>
#include<algorithm>
#include<vector>
#include <limits.h> 

using namespace std;
class  binary {
    public:
        int search_minimum(vector<int> &nums){
            int low = 0, high = nums.size() - 1, mid , ans = INT_MAX;

            while(low<=high){
                mid = (low+high) / 2;

                if(nums[low] <= nums[mid]){                 // Tells whether left side is sorted or not
                    ans = min(ans, nums[low]);
                    low = mid + 1;
                }
                else{
                    ans = min(ans, nums[mid]);
                    high = mid - 1;
                }
            }
            return ans;
        }
};

int main() {

    vector<int> nums = {7, 8, 0, 1, 2, 3, 4, 5, 6};
    binary obj;
    cout<<"The minimum value in the array "<<obj.search_minimum(nums);
    
    return 0;
}