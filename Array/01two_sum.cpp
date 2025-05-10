#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target);
};

vector<int> Solution::twoSum(vector<int>& nums, int target) {
    vector<int> sol;

    // Preserve original indices before sorting
    vector<pair<int, int>> num_with_index;
    for (int i = 0; i < nums.size(); ++i) {
        num_with_index.push_back({nums[i], i});
    }

    // Sort by the value
    sort(num_with_index.begin(), num_with_index.end());

    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int sum = num_with_index[left].first + num_with_index[right].first;
        if (sum == target) {
            sol.push_back(num_with_index[left].second);
            sol.push_back(num_with_index[right].second);
            return sol;
        } else if (sum < target) {
            ++left;
        } else {
            --right;
        }
    }

    return sol;
}

int main(){

    int n , num = 0, target = 0; 

    vector<int> array;
    cin>>n;
    cin>>target;
    
    for(int i = 0; i < n; i ++){
        cin >> num ;
        array.push_back(num);
    }
    Solution obj;
    vector<int> sum_elements = obj.twoSum(array, target);
    for(int i = 0; i < sum_elements.size(); i ++){
        cout<<sum_elements[i]<<" ";
    }


}