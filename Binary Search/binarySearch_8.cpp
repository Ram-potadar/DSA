/*
    In this code we fill find the count of the occurance of the given
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

    int count(vector<int> &nums, int x){
        if (first_occurance(nums, x) == -1) return 0; 
        return last_occurance(nums, x) - first_occurance(nums, x) + 1;
    }
};

int main() {

    vector<int> nums = {2, 4, 6, 8, 8, 8, 10, 11, 12};
    binary obj;
    cout<<"Count of occurance of the given element are "<<obj.count(nums, 9);
    
    return 0;
}