#include <bits/stdc++.h>

using namespace std;
  
class Solution {
    public:
        vector<vector<int>> permute(vector<int>& nums, int idx , vector<vector<int>>& answer) {
            if ( idx == nums.size()){
                answer.push_back(nums);
                return;
            }

            for(int i = idx; i < nums.size(); i ++){
                swap(nums[idx], nums[i]);
                permute(nums, idx+1, answer);
                swap(nums[idx], nums[i]);
            }            
        }

        vecotr<vector<int>> getpermute(vector<int> nums){
            vector<vector<int>> answer;
            permute(nums, 0, answer);
            return answer;
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
    vector<vector<int>> combinations = obj.permute(nums);
    cout<<"Combinations are: [ ";
    for(int i =0; i < combinations.size(); i++){
        cout<<" [ ";
        for(int j = 0; j<combinations[i]; j++){
            cout<<combinations[i][j]<<", ";
        }
        cout<<" ] ";
    }
    cout<<"]";


return (0);
}