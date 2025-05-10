#include<iostream>

using namespace std ;

void largest(int n, int arr[]){
     int first, second , third;

    first = 0;  
    second = 0;  
    third = 0;  


    for(int i = 0 ; i < n; i++){
        if(first < arr[i]){
            third = second;
            second = first;
            first = arr[i]; 
          
        }
        else if(second < arr[i]){
            third = second;
            second = arr[i];
        }
        else if(third < arr[i]){
            third = arr[i];
        }
    }
    cout<<first<<", "<<second<<", "<<third<<endl;
}

int main(){
    int n ;
    cout<<"Enter the size of array : ";
    cin>>n;
    int k = 0;
    int arr[n];
   
    for (int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    largest(n,arr);
    return 0;
}