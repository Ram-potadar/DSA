#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
    public:
    int firstMissingPositive(vector<int>& nums) {
    auto max_it = max_element(nums.begin(), nums.end()); 
    int max = *max_it;
        int missing_element =0;
    vector<int> hash(max + 1 , 0);

    for(int i = 0 ; i < nums.size(); i ++){
        if(nums[i] > 0)
            hash[nums[i] - 1] = nums[i];
    }

    for(int i = 0; i < (max + 1); i ++){
        
        if(hash[i] == 0){
            missing_element = i + 1;
            break ;
        }
    }
        return missing_element;
    }

};
    
int main(){

    int n =0;
    cin >> n;

    vector<int> nums(n);

    for (auto &i : nums)
    cin >> i;
    cout<<endl;

    Solution obj;
    int miss = obj.firstMissingPositive(nums);
    cout<<"Missing element: "<<miss<<endl;
return (0);
}

