#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

       int l_m = nums1.size();
       int l_n = nums2.size();

       int i = 0 ;
       int j = 0; 
       int k = 0;
        vector<int> merged(l_m + l_n);


        while(i < l_m && j < l_n ){

            if(nums1[i] < nums2[j]){
                merged[k] = nums1[i];
                i ++;
            }
            else{
                merged[k] = nums2[j];
                j++;
            }

            k++;
       }
    while(i < l_m ){
        merged[k] = nums1[i];
        i++;
        k ++;
    }
    while(j < l_n ){
        merged[k] = nums2[j];
        j++;
        k ++;

    }
    double mid = 0;
    if (merged.size() % 2 == 0){
        double mid1 = merged[(merged.size() - 1)/2]; 
        double mid2 = merged[(merged.size() + 1)/2]; 

         mid =( mid1 + mid2 ) / 2;
         cout<<"mid1 "<<mid1<<endl;
         cout<<"mid2 "<<mid2<<endl;
    }else{
         
        mid = merged[merged.size()/2]; 
    }

    // int x = 0;
    // while(  x  <=  nums1.size() + 1 ){
    //     cout<<merged[x]<<" ";
    //     x++;
    // }
    // cout<<"mid: "<<mid;

    return mid ;
    }

};

int main(){
int m =  0;
int n = 0 ;

cin >> m;
cin >> n;

vector<int> nums1(m);
vector<int> nums2(n);

for(int i = 0 ; i < nums1.size() ; i++){
    cin >> nums1[i];
}

for(int i = 0 ; i < nums2.size()  ; i++){
    cin >> nums2[i];
}

Solution sol;
sol.findMedianSortedArrays(nums1, nums2);




return (0);
}