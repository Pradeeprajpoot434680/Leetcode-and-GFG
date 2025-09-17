#include <bits/stdc++.h>
using namespace std;
string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<int>>dp(n,vector<int>(n,0));

    int ans = 1;
    int startingIndex=0;
        for (int i = 0; i < n; i++) {
    dp[i][i] = 1;
}

// Check for two consecutive characters
for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1]) {
        dp[i - 1][i] = 2;
        startingIndex = i - 1;
        ans = 2;
    }
}
    for(int i=3; i<=n; i++){
        int p = i-1;
        int start = 0;
        int end = p;
        while(end<n){
            if(s[start]==s[end] && dp[start+1][end-1]>0){
                dp[start][end] = dp[start+1][end-1] + 2;
                if(ans < dp[start][end]){
                startingIndex = start;
                ans = dp[start][end];
                }
            }
            start++;
            end++;
        }
    }

    return s.substr(startingIndex,ans);
}


int main(){
    string s = "babad";
    cout<<longestPalindrome(s);
    return 0;
}