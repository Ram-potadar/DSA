#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if ( nums.empty()) return 0;

        int i = 0;

        for(int j = 0 ; j < nums.size(); j ++ ){

            if( nums[i] != nums[j]){

                i ++;
                nums[i] = nums[j];

            }
        }   
        
        return i+1;


}
};

int main(){

    int n;
    cin >> n;
    vector<int> nums(n);

    for(int i = 0 ; i < nums.size(); i ++){
        cin >> nums[i];
    }


    Solution obj;
    int len = obj.removeDuplicates(nums);
    cout<<" i: "<<len<<endl;

    for(int i = 0 ; i < len ; i++){

        cout<<nums[i]<<" ";
    }

return (0);
}