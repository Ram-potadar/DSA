/*
Allocate Books or Book Allocation 

*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>

using namespace std;

class  Binary{

    public:
    int cntStudents(vector<int> &nums, int pages){
        int students = 1, currentPages = 0;
        for(int i = 0; i < nums.size(); i ++){
            if(currentPages+nums[i] > pages){
                students ++;
                currentPages = nums[i];
            }
            else{
                currentPages += nums[i];
            }
        }
        return students;
    }
    int Min(vector<int> &nums){
        int mini = INT_MAX;
        for(int i = 0; i < nums.size(); i ++){
            mini = min(mini, nums[i]);
        }
        return mini;
    }

    int Sum(vector<int> &nums){
        int sum = 0;
        for(int i = 0; i < nums.size(); i ++){
            sum += nums[i];
        }
        return sum;
    }


    // int search(vector<int> &nums, int students){
    //     for(int i = Min(nums); i <= Sum(nums); i ++){
    //         int stu = cntStudents(nums, i);
    //         if(stu == students) return i;
    //     }
    // }

    int search(vector<int> &nums, int students){
        int low = Min(nums), high = Sum(nums);
        while(low<=high){
            int mid = (low+ high)/2;

            int student = cntStudents(nums, mid);
            if(student == students )  return mid;
            if(student > students)    low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};
   
int main() {

    vector<int> nums = {25,46,28,49,24};
    Binary obj;
    cout<<obj.search(nums, 4);
    return 0;
}