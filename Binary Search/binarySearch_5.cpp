/*
    In this code we will fogure out the solution for inserting
 the given number into the sorted array
 
    To instert the number we need to find the index such that which
 is smaller and value at that index is greater than equal to the
 given number


 */

 #include<iostream>
 #include<algorithm>
 #include<vector>
 using namespace std;

 class  binary{
    public:
    int insertingNumber(vector<int> &nums, int number){
        int low= 0, high = nums.size()-1, ans = nums.size(), mid = 0;

        while(low<=high){
            mid = (low+high)/2;
            if(nums[mid] >=  number){
                ans = mid;
                high = mid - 1;
            }
            else 
                low = mid + 1;
        }
        return ans;
    }

 };
 
 int main() {
vector<int> nums={1,2,4,5};

binary obj;
cout<<"The given number can be insterted at idx "<<obj.insertingNumber(nums, 2);

     return 0;
 }