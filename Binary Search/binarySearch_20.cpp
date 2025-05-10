/*
This is the solution for the below problem:

    We have to calculate the minimum capacity of sheep to load the weights and ship this in given dyas. Each element of an array represents the weight. 
*/


#include<iostream>
#include<algorithm>
#include<vector>
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

    int sumWeights(vector<int> &nums){
        int sum = 0;
        for(int i = 0; i <  nums.size(); i ++){
            sum +=nums[i] ;
        }
        return sum;
    }


    int daysRequried(vector<int> &nums, int cap){
        int load = 0, reqDays = 1;
        for(int i = 0; i < nums.size(); i ++){
            if(load + nums[i] > cap ){
                reqDays ++;
                load = nums[i];
            }
            else
                load += nums[i];
        }

        return reqDays;
    }

    int smallestCapcity(vector<int> &nums, int days){

        int low = findMax(nums), high = sumWeights(nums), mid , ans = -1, reqDays = 0;
        while(low<=high){
            mid = (low+high) / 2;

            reqDays = daysRequried(nums, mid);
            if(reqDays <= days){
                ans = mid;
                high = mid - 1;
            }
            else 
                low = mid + 1;
        }

        return mid;

    }
};

int main() {
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    binary obj;

    cout<<" capcity: "<<obj.smallestCapcity(nums, 5);
    return 0;
}   