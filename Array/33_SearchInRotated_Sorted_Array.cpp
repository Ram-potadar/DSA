#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int len = nums.size();
        int flag = 0, initial = 0, end = 0;
        for(int i = 0 ; i < len; i ++){
           if(target == nums[i] && flag == 0){
                initial = i ;
                flag = 1;
           }
           if(nums[i] == target && flag == 1){
            end = i;
           }
        }
        if(flag == 0){
            initial = -1 ;
            end = -1;
        }
        result.push_back(initial);
        result.push_back(end);
        return result;
       
    }
};

int main()
{

    return (0);
}