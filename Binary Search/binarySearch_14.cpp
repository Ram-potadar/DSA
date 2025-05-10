/*

    In this code we will figure out the peak element from the array.(This is for array contaning single peak element)

    Peak element -> is the element from the array such that (arr[i-1] < arr[i] > arr[i+1])

*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class binary{

    public:
    int searchPeakElement(vector<int> &nums){
        int n = nums.size();

        if(n == 1) return nums[0];
        if(nums[0] > nums[1]) return nums[0];
        if(nums[n-1] > nums[n-2]) return nums[n-1];
        int low = 1, high = n - 2 , mid;

        while(low<=high){
            mid = (low+high)/2;

            if(nums[mid - 1] < nums[mid] && nums[mid] > nums[mid+1]) return nums[mid];

            else if(nums[mid] > nums[mid-1])    low = mid + 1;

            else if(nums[mid] < nums[mid-1])    high = mid -  1;

            else low = mid - 1;
        }
        return -1;
    }
};

int main() {

    vector<int> nums ={1, 10, 13, 7, 6, 5, 4, 3, 2, 1, 0};
    // vector<int> nums ={5, 4, 3, 2, 1};
    binary obj;
    cout<<"The peak element in the array is "<<obj.searchPeakElement(nums);
    
    return 0;
}