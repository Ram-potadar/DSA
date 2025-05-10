/*

    In this code we will find the nth sqauare of a given numsber by using binary search.

*/


#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class  binary{

    public:

    int func(long x, long n){
        long ans = x; 
        for(int i = 1; i < n ; i ++){
            ans = ans * x;
        }
        return ans;
    }

    int nthSquareRoot(long x, long n){

        long sq = 0, low = 1, high = x, mid ;

        while(low<=high){

            mid = (low+high)/2;
            cout<<"mid: "<<mid<<"  ";
            cout<<"func: "<<func(mid,n)<<endl;
            sq = func(mid,n);
            if(sq == x)  return mid;

            else if (sq > x) high = mid - 1;

            else if (sq < x) low = mid + 1;
        }
        return -1;
    }
};

int main() {

    binary obj;
    cout<<"The nth square root of a given number is "<<obj.nthSquareRoot(81, 4);

    return 0;
}