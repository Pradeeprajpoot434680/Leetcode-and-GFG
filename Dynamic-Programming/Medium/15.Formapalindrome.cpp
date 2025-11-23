#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int solve(int i,int j,string &s,vector<vector<int>>&dp){
        if( i >= j){
            return 0;
        }
        
        int ans = INT_MAX;
        if(dp[i][j] != -1)return dp[i][j];
        if(s[i]==s[j]){
            ans = solve(i+1,j-1,s,dp);
        }
        else {
            int take_left = 1 + solve(i,j-1,s,dp);
            int take_right = 1 + solve(i+1,j,s,dp);
            
            ans = min(take_left,take_right);
        }
        
        return dp[i][j] = ans;
    }
    int countMin(string str) {
        // complete the function here
        int n = str.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,n-1,str,dp);
    }
};

int main(){
    Solution s;
    cout<<s.countMin("dnsoubfsa");
    
}