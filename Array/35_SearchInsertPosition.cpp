#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

class Solution{

public :
         int searchInsert(vector<int>& nums, int target){

            int len = nums.size();

            int l = 0, r = len - 1, mid = 0;
            while(l <= r){

                mid = (l + r)/2;
              
                if(nums[mid] == target){
                    cout<<" numd[mid ] == target "<<endl;
                    return mid;
                }
                if(target < nums[mid]){
                 
                    r = mid - 1 ;
                }else{
                    l = mid + 1;
                }  

            }
            return l;

         }
};


int main(){
 int n;
    cin >> n;
    vector<int> nums(n);
    cout<<" Enter elements: ";

    for(int i = 0 ; i < nums.size(); i ++){
        cin >> nums[i];
    }

    int target ;
    cout<<" Enter target: ";
    cin >> target;



    Solution obj;
    int len = obj.searchInsert(nums, target);
    cout<<" i: "<<len<<endl;


return (0);
}