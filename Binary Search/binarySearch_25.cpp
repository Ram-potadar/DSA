#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


class  binary {
public:
vector<int>  search(vector<vector<int>> &nums, int target){
    int row = nums.size() - 1, col = 0;
    vector<int> ans;
    while(row >= 0  && col < nums[0].size()){
        if(nums[row][col] == target ) {
            ans.push_back(row);
            ans.push_back(col);
            return ans;
        }
        if(target < nums[row][col]) row --;
        else col ++;
    }
    ans.push_back(-1);
    ans.push_back(-1);
    return ans;
}
};

int main() {
    vector<vector<int>> nums = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};

    binary obj;
    vector<int> ans = obj.search(nums, 34);
    for(int x : ans)
        cout<<x<<" ";
    return 0;
}