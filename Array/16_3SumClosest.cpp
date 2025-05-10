#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;
  

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target ) {
        sort(nums.begin(), nums.end());

        int sum = 0 ; 
        int prev_sum = 0;
        int difference = 0;
        int previous_difference = 0;
        int close_sum = 999999999;
        for(int i = 0 ; i < nums.size() - 1; i ++){

            if( i > 0 && nums[i] == nums[i - 1]){
                continue;
            }

            
            int left = i + 1;
            int right = nums.size() - 1;
            

            while(left < right ){
                sum = nums[i] + nums[left] + nums[right]; 

                
                difference = target - sum ;
                if(difference == 0 ){
                    
                   
                    while(left < right && nums[left]==nums[left + 1]) left ++;
                    while(left < right && nums[right]==nums[right - 1]) right --;

                    right --;
                    left ++;
                    return sum ;
                }

                if(difference > 0 ){
                    left ++;
                }
                if(difference < 0 ){
                    right --;
                }

                if(difference < previous_difference ){
                    close_sum = sum ;
                }
                previous_difference = difference ;
                
            }
        }
        return close_sum ;
    }
};

int main(){
int n = 0 ;
cin >> n;
int target = 0;
cin >>target ;

vector<int> nums(n);

for(int i = 0 ; i < n ; i ++){
    cin >> nums[i];
}

Solution sol;
cout<<"close sum"<<sol.threeSumClosest(nums, target);


return (0);
}