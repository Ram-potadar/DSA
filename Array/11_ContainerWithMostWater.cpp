#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

        int size = height.size();
        int right = size - 1 ;
        int left = 0;
        int max_area = 0;
        int width =  0;
        int area = 0;
        while(left < right){
            width = right - left;
            area = width * min(height[right], height[left]);
            if( max_area < area)
            {
                max_area = area ;
            }

            if ( height[left]< height[right]){
                left ++;
            }
            else{
                right --;
            }
        }
        return max_area;
    }
};
  
int main(){

    int n = 0;
    cin >> n;


    vector<int> height(n);

    for(int i = 0; i < n; i ++){
        cin >> height[i];
    }

  
    Solution sol;
    cout<<sol.maxArea(height);


    
return (0);
}