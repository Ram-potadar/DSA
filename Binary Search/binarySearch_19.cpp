/*
In this problem statement we need to find the smallest devisior of all the array such such that the sum is is equal to the given sum.
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include <cmath>
using namespace std;

class  binary{
    public:
    int findMax(vector<int> &nums){
        int maxi = 0;
        for(int i = 0; i < nums.size() ; i ++){
            maxi = max(maxi, nums[i]);
        }
        return maxi ;
    }

    int sumByD(vector<int> &nums, int devsior){
        int sum = 0;
        for(int i = 0; i <  nums.size(); i ++){
            sum += ceil(nums[i] / devsior);
        }
        return sum;
    }

    int findSmallestDivisor(vector<int> &nums, int thr){

        int low = 1, high = findMax(nums), mid, ans = -1 ;
        while(low<=high){
            mid = (low+high) / 2;
            if(sumByD(nums, mid) <= thr){


                ans =  mid;
                high = mid - 1;
            }
            else   
                low = mid + 1;
        }
        return ans ;
    }
};

int main() {
    vector<int> nums = {1,2,5,9};
    binary obj;
    cout<<"Smallest devisior is: "<<obj.findSmallestDivisor(nums, 6);
    return 0;
}