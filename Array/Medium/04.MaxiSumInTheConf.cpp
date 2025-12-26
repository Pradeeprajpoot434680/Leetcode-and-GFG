#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int sum=0;
        int ans = -1;
        int totalCalSum=0;
        int n = arr.size();
        for(int i=0; i<n; i++){
            sum+=arr[i];
            totalCalSum += arr[i]*i;
        }
        ans = totalCalSum;
        for(int i=0; i<n; i++){
            totalCalSum = totalCalSum - (sum - arr[i]) + (arr[i]*(n-1));
            ans = max(ans,totalCalSum);
        }
        
        return ans;
    }
};

int main(){
    
}