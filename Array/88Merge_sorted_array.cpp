#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;


        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

  
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
        
        for (int i = 0; i < m + n; i++) {
            cout << nums1[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int m, n;

    cin >> m;
    cin >> n;

    vector<int> num1(m + n);
    vector<int> num2(n);

    for (int i = 0; i < m; i++) {
        cin >> num1[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> num2[i];
    }

    Solution obj;
    obj.merge(num1, m, num2, n);

    return 0;
}
