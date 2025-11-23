#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int ans = 0;
        
        for(int i=1; i<n+1; i++){
            
            for(int j=1; j<m+1; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    
                    ans = max(ans,dp[i][j]);
                }
                else{
                    dp[i][j]=0;
                }
                
            }
        }
        
        return  ans;
    }
};

int main(){
    Solution s;
    string s1 = "dnosagdwdh",s2="ndasboda";
    s.longestCommonSubstr(s1,s2);
}