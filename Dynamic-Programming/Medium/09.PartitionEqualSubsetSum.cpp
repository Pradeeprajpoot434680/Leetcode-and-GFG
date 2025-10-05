#include<bits/stdc++.h>
using namespace std;
class Solution {
public: 
    bool solve(int index,vector<int>&nums,int sum,vector<vector<int>>&dp){
        if(sum==0)return 1;
        if(index<0 || sum < 0)return 0;
        if(dp[index][sum] != -1)return dp[index][sum];

        bool pick = 0;
        if(sum-nums[index] >= 0){
            pick = solve(index-1,nums,sum-nums[index],dp);
        }
        bool not_pick = solve(index-1,nums,sum,dp);

        return dp[index][sum] = pick || not_pick;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i:nums){
            sum+=i;
        }
        if(sum % 2)return 0;
        int target = sum / 2;
        vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
        return solve(nums.size()-1,nums,target,dp);
    }
};
int main(){
    Solution s;
    vector<int>arr={3,2,4,1,5};
    cout<<s.canPartition(arr);
}