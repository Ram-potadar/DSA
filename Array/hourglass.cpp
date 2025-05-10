#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
int main()
{

    int j , i, max = 0;

    int n = 0, sum = 0, temp = 0, k = 0;


    vector<vector<int>> arr(6, vector<int>(6));

    for (int i = 0; i < 6; i++) {
        // string line;
        // getline(cin, line);
        // istringstream iss(line);
        for (int j = 0; j < 6; j++) {
            // iss >> arr[i][j];
            // one more option is std::cin>>arr[i][j] just do this
            std::cin>>arr[i][j];
        }
    }


    while (k < 4)
    {
        while (n < 4) 
        {
            for ( i = k; i < (k + 3); i++)
            {
                for ( j = n; j < (n + 3); j++)
                {
                    sum = sum + arr[i][j];
                }
            }
            sum = sum - arr[k+1][n] - arr[k+1][n+2];
            // cout << " the sum is " << k << "  " << sum << endl;
            
            if(max < sum ){
                max = sum ;
            }
            sum = 0;
            n++;
        }
        k++;
        n = 0;
        sum = 0;
    }
            cout<<max <<endl;

    return 0;
}

