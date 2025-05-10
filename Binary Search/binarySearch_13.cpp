/*
nums = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6}
       (even, odd)           (odd, even)    


(even , odd) -> you are on the left part and the answer is at right side.
(odd , even) -> you are on the right part and the answer is at left side.

*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class binary{

    public:
    int search_singleElement(vector<int> &nums){
        int n = nums.size();
        if( n = 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        int low = 1, high = nums.size() - 2, mid;


        while(low<=high){
            mid = (low + high) / 2;

            if(nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1])    return nums[mid];
            else 
            // now elemenate eiither part of array using following condition 
            if( mid % 2 == 1 && nums[mid] == nums[mid - 1] )
                    low = mid + 1;
            else 
                high = mid - 1;
        }
        return - 1;
    }
};

int main() {
    
    vector<int> nums ={1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6};
    binary obj;
    cout<<"The single element in the array is "<<obj.search_singleElement(nums);
    
    return 0;
}