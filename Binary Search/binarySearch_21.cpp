/*

Kth missing positive intiger

*/


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class  binary{

    public:
    int missingK(vector<int> &nums, int k ){
        int low = 0, high = nums.size() -1;

        while(low<=high){
            int mid = (low+high)/2;

            int missing  = nums[mid] - (mid + 1);

            if(missing<k){
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return k + high + 1;
    }

};

int main() {


    return 0;
}