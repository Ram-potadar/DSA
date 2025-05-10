#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


class Binary {
    public:
    int search(vector<int> &nums, int target){
        int low = 0, high = nums.size() - 1, mid = 0;

        while(low<=high){

        mid = (low + high)/2;

        if (nums[mid] == target)
            return mid;

        else if (nums[mid] > target)
            high = mid - 1;

        else 
            low = mid + 1;
        }
        return -1;
    }
};

int main(){
vector<int> nums = {1,2,3,5,6,8};

Binary obj;
cout<<"the target is at index "<<obj.search(nums, 2);

return 0;
}