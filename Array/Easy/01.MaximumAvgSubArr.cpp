#include <bits/stdc++.h>
#include<iostream>

using namespace std;

int findMaxAverage(int arr[], int n, int k) {
// code here
int sum = 0;
int ans = 0;
for(int i=0; i<k; i++){
    sum+= arr[i];
}
int maxiSum=INT_MIN;
if(maxiSum<sum){
    ans = 0;
    maxiSum = sum;
}
for(int i=k; i<n; i++){
    sum-= arr[i-k];
    sum+= arr[i];
    if(sum > maxiSum){
            ans = i-k+1;
        maxiSum = sum;
    }
}

return ans;
}

int main() {
    int arr[] = {1, 12, -5, -6, 50, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    cout << "The starting index of the subarray with maximum average is: " << findMaxAverage(arr, n, k) << endl;
    return 0;
}
// Time Complexity: O(N)
// Space Complexity: O(1)
