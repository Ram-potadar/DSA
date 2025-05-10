/* 
    In this code we will find the floor and ceil of the given element using 
binary search    

*/


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


class  binary{
    public:
        int floor(vector<int> &nums, int x){
            int low = 0, high = nums.size() - 1, ans = -1, mid  =0;

            while(low<=high){
                mid = (low+high) / 2;

                if (nums[mid] <= x){
                    ans = mid;
                    low  = mid + 1;
                }
                else 
                    high = mid - 1;
            }

            return ans;
        }

        int ceil(vector<int> &nums, int x){
            int low = 0, high = nums.size() - 1, ans = -1, mid  =0;

            while(low<=high){
                mid = (low+high) / 2;

                if (nums[mid] >= x){
                    ans = mid;
                    high  = mid - 1;
                }
                else 
                    low = mid + 1;
            }

            return ans;
        }

        
};

int main() {
    vector<int> nums = {10, 20, 30, 40};

    binary obj;
    cout<<"Floor of the given element is "<<obj.floor(nums, 25)<<endl;
    cout<<"Ceil of the given element is "<<obj.ceil(nums, 25);
    
    return 0;
}