
// Search in sorted 2D matrix 
    // In order to find the idexing we can use the below formula 
    // for columns we should use idx%m
    // for rows we should use idx/m


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class  binary{
public:
int search(vector<vector<int>> nums, int target){

    int min = 0, n = nums.size(), m = nums[n-1].size(), max = (n * m) - 1;

    while(min <= max ){
        int mid = (min + max) / 2;

        int n_idx = mid  /  m, m_idx = mid  %  m;
        if(target == nums[n_idx][m_idx]) return 1;
        if(target < nums[n_idx][m_idx] ) max = mid -1;
        else min = mid + 1;
    }
    return 0;
}
};

int main(){
    vector<vector<int>> nums = {{1,2,3},{3,4,5},{6,7,8}};

    for(int i = 0; i < nums.size(); i ++){
        for(int j = 0; j < nums[i].size(); j ++){
            cout<<" "<<nums[i][j];
        }cout<<"\n";
    }
    binary obj;
    cout<<obj.search(nums, 9);
    return 0;
}