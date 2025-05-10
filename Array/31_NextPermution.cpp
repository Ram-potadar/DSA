#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:

    void nextPermutation(vector<int> &nums)
    {
        int piv = -1;
        int len = nums.size();

        for (int i = len - 1; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                piv = i;
                break;
            }
        }

        if (piv == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }


        for(int i = len - 1; i > piv; i --){
            if(nums[i] > nums[piv]){
                swap(nums[i], nums[piv]);
                break;
            }
        }


        reverse(nums.begin() + piv + 1, nums.end());
        
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
    }

    Solution obj;
    obj.nextPermutation(nums);
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    return (0);
}