#include<bits/stdc++.h>
using namespace std;
int solve(int index,int mod, vector<int>&arr,int prevIndex, vector<vector<vector<long long>>>&dp){
        if(index==arr.size()-1){
            if(prevIndex != -1 && ((arr[index]%2) + (arr[prevIndex]%2))%2==mod){
                return 1;
            }
            return 0;
        }
        if(prevIndex != -1 && dp[index][prevIndex][mod] != -1)return dp[index][prevIndex][mod];
        int pick=0;
        int not_pick=0;
        if(mod==-1 || prevIndex ==-1){
            if(prevIndex==-1){
                pick = 1 + solve(index+1,-1,arr,index,dp);
            }
            else{
                pick = 1 + solve(index+1,((arr[index]%2) + (arr[prevIndex]%2))%2,arr,index,dp);
            }
        }
        else{
            if(((arr[index]%2) + (arr[prevIndex]%2))%2 == mod){
               pick = 1 + solve(index+1,mod,arr,index,dp);
            }
        }

        not_pick = solve(index+1,mod,arr,prevIndex,dp);

        if(prevIndex!=-1){
            dp[index][prevIndex][mod] = max(not_pick,pick);
        }
        return max(not_pick,pick);
    }
    int maximumLength(vector<int>& nums) {
        if(nums.size()==2)return 2;
        int n = nums.size();
        vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(n+1,vector<long long>(3,-1)));
        return solve(0,-1,nums,-1,dp);
    }

    int main(){
        vector<int> arr = {1,2,3,4};
        cout<<maximumLength(arr);
        return 0;
    }
    /*
        int maximumLength(vector<int>& nums) 
    {
        // Step 1: Initialize counters
        int evenCount = 0, oddCount = 0;
        int altEven = 0, altOdd = 0;

        // Step 2: Loop through each number
        for (int num : nums) 
        {
            int p = num % 2;  // Step 2: Check parity

            // Step 3: Update counters
            if (p == 0) 
            {
                evenCount++;           // Same-parity subsequence (even)
                altEven = altOdd + 1;  // Alternating sequence ending in even
            } 
            else 
            {
                oddCount++;            // Same-parity subsequence (odd)
                altOdd = altEven + 1;  // Alternating sequence ending in odd
            }
        }

        // Step 4 & 5: Return maximum length
        return max({evenCount, oddCount, altEven, altOdd});
    }*/