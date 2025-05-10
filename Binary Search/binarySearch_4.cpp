#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


class binary {
    public:

    int upperBond_search( vector<int> &nums, int target){
        int low = 0, high = nums.size()-1, mid = 0, ans = nums.size();

        while(low<=high){
            mid = (low + high) / 2;

            if (nums[mid] > target){
                ans = mid;
                high = mid - 1;
            }
            else 
                low = mid + 1 ;
        }

        return ans;
    }
};

int main() {

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9};

    binary obj;
    cout<<" the upper bound of the given element is "<<obj.upperBond_search(nums,9 );
    return 0;
}