#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int cntWays(vector<int>& arr) {
        // code here
         int n = arr.size();
        int totalEven = 0, totalOdd = 0;

        // Step 1: total sums
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) totalEven += arr[i];
            else totalOdd += arr[i];
        }

        int leftEven = 0, leftOdd = 0;
        int count = 0;

        // Step 2: try removing each index
        for (int i = 0; i < n; i++) {

            int rightEven, rightOdd;

            if (i % 2 == 0) {
                rightEven = totalOdd - leftOdd;
                rightOdd  = totalEven - leftEven - arr[i];
            } else {
                rightEven = totalOdd - leftOdd - arr[i];
                rightOdd  = totalEven - leftEven;
            }

            if (leftEven + rightEven == leftOdd + rightOdd)
                count++;

            if (i % 2 == 0) leftEven += arr[i];
            else leftOdd += arr[i];
        }

        return count;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {2, 1, 6, 4};
    cout << sol.cntWays(arr) << endl; // Output the result
    return 0;
}