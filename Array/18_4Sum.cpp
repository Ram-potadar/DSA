#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        int left = 0 ; 
        int right = 0 ; 
        int sum = 0;

        for(int i = 0 ; i < nums.size() - 3 ; i ++){

            if(i > 0 && nums[i] == nums[i - 1]) continue;

            for(int j = i + 1 ; j < nums.size() - 2; j ++){
            
                if(j > (i + 1) && nums[j] == nums[j - 1]) continue;
            

            
        
                left = j + 1;
                right  = nums.size() - 1;

                while(left < right )
                {
                    sum = nums[i] + nums[j] + nums[left] + nums[right] ; 

                    if(sum == target ){
                            result.push_back({nums[i], nums[j], nums[left], nums[right]});
                            while (left < right && nums[left] == nums[left + 1]) left ++;
                            while (left < right && nums[right] == nums[right - 1]) right --;
                            
                            right --;
                            left ++;
                    }

                     if(sum < target ) left ++;

                     if(sum > target ) right --;
                

                }

            }
        }

        return result;
    
    }
};


int main(){

return (0);
}