#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:

    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=n-1; i>=0; i--)
        {
            for(int j=i+1; j<n; j++)
            {
                 int mini = INT_MAX;
        
                for(int k=i; k<j; k++)
                {
                    int part = arr[i-1]*arr[k]*arr[j] + dp[i][k] +  dp[k+1][j];
                    mini = min(mini,part);
                }
                
                 dp[i][j] = mini;
            }
        }
        
        return dp[1][n-1];
        
    }
};



// User function Template for C++

class Solution1 {
  public:
    int f(int i,int j,vector<int>&arr,vector<vector<int>>&dp)
    {
        if(i==j)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int mini = 1e8;
        for(int k=i; k<j; k++)
        {
            int steps = arr[i-1]*arr[k]*arr[j] + f(i,k,arr,dp)  + f(k+1,j,arr,dp);
            mini = min(steps,mini);
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
       vector<vector<int>>dp(n,vector<int>(n,-1));
       return f(1,n-1,arr,dp);
    }
};
