#include<iostream>

using namespace std ;

int main(){
    int n ;
    cout<<"Enter the size of array";
    cin>>n;
    int max = 0 ;
    int arr[n];
    for (int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }

    for(int i = 0 ; i < n; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    cout<<max;
    return 0;
}