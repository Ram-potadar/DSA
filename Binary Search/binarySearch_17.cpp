#include<iostream>
#include<algorithm>
#include<vector>
#include <limits.h> 
#include <cmath>
using namespace std;

class  binary{
    public:

    int findMax(vector<int> &nums){
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size()-1; i++){
            maxi = max(nums[i], maxi);
        }
        return maxi;
    }

    int findTotalHours(vector<int> &nums, int k){
        int totalHr = 0;
        for(int i = 0; i < nums.size(); i ++){
            totalHr += ceil((double)nums[i] / (double)k);
        }
        return totalHr;
    }

    int search(vector<int> &nums, int x){
        int low = 0, high = findMax(nums), mid, ans ;

        while(low<=high){
            mid = (low+high) / 2;

            ans = findTotalHours(nums, mid);
            if(ans <= x){
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
    vector<int> nums={3,4,7,11};
    binary obj;
  
    cout<<"The speed at which banana can be eaten is "<<  obj.search(nums, 8);
    return 0;
}