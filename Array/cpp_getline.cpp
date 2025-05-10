#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {

    vector<vector<int>> arr(6, vector<int>(6)); // 2D vector to store the array
    cout<<"Enter the values...";
    for(int i = 0; i < 6;  i++){
        for(int j = 0; j < 6; j ++){
            cin>>arr[i][j];
        }
    }

    // Print the 2D array
    cout << "The 2D array is:" << endl;
    for (const auto& row : arr) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

    return 0;
}
