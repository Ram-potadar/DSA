#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;

class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            int max_profit = 0;
            int profit = 0;
            int best_buy = INT_MAX;
        
            for(int i = 0; i < prices.size() ; i ++){
              if(prices[i] > best_buy){
                max_profit = max(max_profit, (prices[i] - best_buy));
              }
              best_buy = min(best_buy, prices[i]);
            }
            return max_profit;
        }
    };


int main() {
    vector<int> nums = {1,2};
    Solution obj;
    cout<<" Max profit:" <<obj.maxProfit(nums);
    return 0;
}