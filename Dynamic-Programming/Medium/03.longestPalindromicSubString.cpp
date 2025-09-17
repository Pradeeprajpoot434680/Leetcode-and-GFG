#include<iostream>
#include<vector>
#include<string>
using namespace std;
int countSubstrings(string s) {
    int n = s.size();
    int ans = 0;
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int i=0; i<n; i++){ 
        dp[i][i] = 1; 
        ans++;
        if(i>0){ 
            if(s[i]==s[i-1]){ 
                ans++;
                dp[i-1][i] = 1; 
            }
        } 
    }

        for(int i=3; i<=n; i++){ 
        int p = i-1; 
        int start = 0; 
        int end = p; 
        while(end<n){
            if(s[start]==s[end] && dp[start+1][end-1]>0){ 
                dp[start][end] = 1; ans++;
            } start++; end++; 
        } 
    }

        return ans;

}

int main(){
    string s = "aaaabaa";
    cout<<countSubstrings(s);
    return 0;
}