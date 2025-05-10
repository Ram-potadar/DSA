#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


class  binary{

    public:

    int searchSquareRoot(int x){
        int low = 1, high = x, mid, ans;

        while(low<=high){
            mid = (low+high)/2;

            if((mid*mid) <= x){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans; 
    }
};

int main() {

    binary obj;
    cout<<"The square root of given numsber is "<<obj.searchSquareRoot(17);
    return 0;
}