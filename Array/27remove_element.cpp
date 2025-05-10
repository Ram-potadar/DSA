#include<iostream>
#include <vector>

using namespace std;
  


class solution{
    public:
    int removeElement(vector<int>& nums, int val) {

        int k  = 0 ; 
        for(int i = 0 ; i < nums.size(); i ++){
            if(nums[i] != val){
                nums[k] = nums[i];
                k ++;
            }
        }
        return k;
    }
};

int main(){
    int n ;
    cin >> n;
    vector<int> nums(n);

    for(int i = 0 ; i < n; i ++)
    {   
        cin >> nums[i];
    }
    int val ;
    cin >> val;

    solution sol;
    int k = sol.removeElement(nums, val);
    cout<<k<<"      ";
    for(int i = 0; i < k; i++){
        cout<<nums[i]<<" ";
    }
return (0);
}