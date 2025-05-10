#include<iostream>
using namespace std;

void klargest(int arr[], int k, int n){
   
        for(int i = 0 ; i < n ; i ++){
        for ( int j = 0 ; j < (n-1) ; j++){
            if ( arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }          
        }
    }

    for(int i = (n-k) ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}

int main(){
    int t = 0 , T;
    cin>>T;
    int n,k;
    while(t < T){
    std :: cin>>n;
    std :: cin>>k;
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        std::cin >> arr[i];
    }
    klargest(arr,  k,  n);
    t++;
    }
    return 0 ;
}