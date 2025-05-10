/*
    In this code we fill find the first and last occurance of the given
number in asorted array by using the plane binary search. 

*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


class binary{
    public:
    int first_occurance(vector<int> &nums, int x){
        int low = 0, high = nums.size()-1, first = -1, mid = 0;

        while(low<=high){
            mid = (low+high)/2;

            if(nums[mid] == x){
                first = mid;
                high = mid - 1;
            }
            else if(nums[mid] < x)
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return first;
    }

    int last_occurance(vector<int> &nums, int x){
        int low = 0, high = nums.size()-1, last = -1, mid = 0;

        while(low<=high){
            mid = (low+high)/2;

            if(nums[mid] == x){
                last = mid;
                low = mid + 1;
            }
            else if(nums[mid] < x)
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return last;
    }
};

int main() {

    vector<int> nums = {2, 4, 6, 8, 8, 8, 8, 11, 12};
    binary obj;
    cout<<"First and last occurance of the given element are "<<obj.first_occurance(nums, 8)<<" and "<<obj.last_occurance(nums, 8);

    return 0;
}