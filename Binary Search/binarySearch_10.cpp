/*
 In this code we are searching a given target in an rotated sorted array(duplicate values)

    1. Identify the which side(left side or right side) is sorted and perform the search operation only on that side 
    2. If its not present in the sorted side then search on the either side of array
    
*/


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class binary {
    public:
    int search(vector<int> &nums, int target){
        int low = 0, high = nums.size() - 1, mid = 0;

        while(low<=high){
            mid = (low+high) / 2;

            if(nums[mid] == target) return mid;
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low ++;
                high --;
                continue;
            }
            // Identify the which side is sorted 

            if(nums[low] <= nums[mid]){                 // Check weather left half is sorted or not 

                if(nums[low] <= target && target <= nums[mid]){         //To check weather target is present in the sortef array or not 
                    high = mid - 1;
                }
                else 
                    low = mid + 1;
            }
            else {                                    
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid + 1;
                }
                else 
                    high = mid - 1;
            }
        }
        return -1;
    }
};

int main() {

    vector<int> nums = {3, 3, 9, 1, 3, 3, 3, 3, 4, 3, 3};
    binary obj;
    cout<<"The given element is present at index "<<obj.search(nums, 9);
    
    return 0;
}