#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>

using namespace std;

class  binary{
    public:

    int findMin(vector<int> &nums){
        int mini = INT_MAX;
        for(int i = 0 ; i < nums.size() ; i ++){
            mini = min(mini, nums[i]);
        }
        return mini;
    }

    int findMax(vector<int> &nums){
        int maxi = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i ++){
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }
    
    int countBookets(vector<int> &nums, int pair, int  days ){
        int count = 0, bookets =0;
        for(int i = 0 ; i < nums.size(); i ++){
            if (days >= nums[i]){
                count ++;
            }
            if(days<nums[i] || i == nums.size() - 1){
                bookets += count / pair;
                count = 0;
            }
        } 
        cout<<endl;
        return bookets;
    }

    int flowerBookets(vector<int> &nums, int m, int n){

        if((m*n) > nums.size() )    return -1;

        int low = findMin(nums), high = findMax(nums), mid, ans=0;
        int bookets = 0;

        while(low<=high)
        {
            mid = (low+high)/2;

            bookets = countBookets(nums, n, mid);
            if(bookets >= m){
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {7,7,7,7,13,11,12,7};

    binary obj;
    cout<<"No of days requried is "<<obj.flowerBookets(nums, 2,3);

    return 0;
}