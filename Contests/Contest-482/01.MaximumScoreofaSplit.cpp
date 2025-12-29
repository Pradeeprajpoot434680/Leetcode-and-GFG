#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long>prefixSum(n);
        vector<long long>suffixMin(n);
        prefixSum[0] = nums[0];
        suffixMin[n-1] = nums[n-1];

        for(int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
            suffixMin[n-i-1] = min(suffixMin[n-i],(long long)nums[n-i-1]);
        }

        long long ans = LLONG_MIN;

        for(int i=0; i<n-1; i++){
            long long nextMax = suffixMin[i+1];
            long long upISum = prefixSum[i];

            ans = max(ans,(upISum - nextMax));
        }
        //ans = max(ans,prefixSum[n-1]);
        return ans;
    }
};

int main(){
    
}