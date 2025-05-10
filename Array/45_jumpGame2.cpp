#include <bits/stdc++.h>
using namespace std;
  
class Solution {
    public:
        int jump(vector<int>& nums) {
            int n = nums.size();
            if (n == 1) return 0; 
            
            int maxIdx = 0, jumps = 0, currentEnd = 0;
    
            for (int i = 0; i < n - 1; i++) { 
                maxIdx = max(maxIdx, i + nums[i]);
    
                if (i == currentEnd) { 
                    jumps++;
                    currentEnd = maxIdx;
                    if (currentEnd >= n - 1) break;
                }
            }
            return jumps;
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
    int jumps = obj.jump(nums);
    cout<<"Mnimum no. of jumps: "<<jumps;

return (0);
}