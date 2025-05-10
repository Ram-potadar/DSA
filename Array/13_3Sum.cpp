#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int sum = 0 ;
        int target = 0;
        vector<vector<int>> result ;
        for(int i = 0 ; i < nums.size() - 1; i ++){

            if( i > 0 && nums[i] == nums[i - 1]){
                continue;
            }

            
            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right ){
                sum = nums[i] + nums[left] + nums[right];

                if(sum == target ){
                    
                    result.push_back({nums[i],  nums[left], nums[right]});
                    while(left < right && nums[left]==nums[left + 1]) left ++;
                    while(left < right && nums[right]==nums[right - 1]) right --;

                    right --;
                    left ++;
                }

                if(sum < target ){
                    left ++;
                }
                if(sum > target ){
                    right --;
                }
            }
        }
        return result;
    }
};

  
int main(){
int n = 0 ;
cin >> n;

vector<int> nums(n);

for(int i = 0 ; i < n ; i ++){
    cin >> nums[i];
}

Solution sol;
sol.threeSum(nums);


return (0);
}




