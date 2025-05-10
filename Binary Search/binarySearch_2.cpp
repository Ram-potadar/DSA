#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


class Binary {
    public:
        int search(vector<int> &nums, int low, int high, int target){
            int mid = 0;
            if(low>high)
                return -1;

            mid = (low+high)/2;
            
            if(nums[mid] == target)
                return mid;

            else if(nums[mid] > target)
                search(nums, low, mid - 1, target);
            
            else 
                search(nums, mid + 1, high, target);
        }

};

int main() {
    vector<int> nums = {1,2,3,5,6,8};

    Binary obj;
    cout<<"the target is at index "<<obj.search(nums, 0, nums.size()-1, 2);
    return 0;
}