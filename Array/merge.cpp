#include<iostream>
using namespace std;

int sort(int size , int arr[]){
    for(int i = 0 ; i < (size-1); i ++){}

}
int main(){

    int n1 , n2 ;
    // cout <<"enter the size of arr_1 : \n";
    // cin>>n1;
    // cout <<"enter the size of arr_2 : \n";
    // cin>>n2;
    n1 =  5, n2 = 5;
    int arr1[] = {1,12,15,26,38};
    int arr2[] = {2,13,17,30,35};

    int arr3[n1 + n2];
    for(int i = 0 ; i < ( n1 ); i++){
        
        arr3[i] = arr1[i];
        arr3[2*n1 - 1 - i] = arr2[n1 - i - 1];
        // cout<<arr1[i]<<" , "<<arr2[n1 - 1 - i]<<endl;
    }

    for(int i = 0 ; i < ( n1+n2 ); i ++){
        cout<<arr3[i]<<endl;
    }
}