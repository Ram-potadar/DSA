#include<iostream>
#include<vector> 
#include<set>

using namespace std;

class Solution {
public:

    set<vector<int>> s;
    void getAllCombinstions(vector<int>& arr, vector<vector<int>> &ans,int idx, vector<int> &combin, int target ){\
    

    if (  idx = arr.size() || target < 0 ){
        return;
    }

    if (target == 0){

        if(s.find(combin) == s.end()){
        ans.push_back(combin);
        s.insert(combin);
        }
        return;
    }
    
    combin.push_back(arr[idx]);
    getAllCombinstions(arr, ans, idx + 1, combin, target - arr[idx]);
    getAllCombinstions(arr, ans, idx, combin, target - arr[idx]);
    combin.pop_back();
    getAllCombinstions(arr, ans, idx+1, combin, target);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> combin;

        getAllCombinstions(arr, ans, 0, combin, target);

        return ans;
    }
};


int main(){

return (0);
}