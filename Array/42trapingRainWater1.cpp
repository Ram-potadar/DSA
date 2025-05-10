#include <bits/stdc++.h>
using namespace std;
  

class Solution {
    public:
        int trap(vector<int>& nums) {
            int total = 0;
            int n = nums.size();
            vector<int> prefixMax(n);
            vector<int> suffixMax(n);

            prefixMax[0] = nums[0]; 
            suffixMax[n-1] = nums[n-1]; 

            for(int i = 1; i < n; i ++ ){
                if(prefixMax[i - 1] < nums[i])
                    prefixMax[i] = nums[i];
                else
                    prefixMax[i] =  prefixMax[i-1];
            }
            suffixMax[n-1] = nums[n-1];

            for(int i = n - 2; i >= 0; i --){
                if(suffixMax[i+1] < nums[i])
                    suffixMax[i] = nums[i];
                else 
                    suffixMax[i] = suffixMax[i+1];
                
            }
            
            // cout<<"PrefixMax: "<<endl;
            // for(auto i:prefixMax)
            //     cout<<i<<" ";

            // cout<<endl<<"suffixMax: "<<endl;
            // for(auto i:suffixMax)
            //     cout<<i<<" ";
            // cout<<endl;


            for(int i = 0 ; i < nums.size(); i ++){
                total += min(prefixMax[i], suffixMax[i]) - nums[i];
            }


            return total;
        }
    };


int main(){
    int n = 0;
    cin >> n;
    vector<int> nums(n);

    for(int i = 0; i < nums.size(); i ++){
        cin >> nums[i];
    }

    // for(auto i:nums)
    // cout<<i<<" ";
    // cout<<endl;

    Solution obj;
    int trapedWater = obj.trap(nums);
    cout<<trapedWater;

    return (0);
}