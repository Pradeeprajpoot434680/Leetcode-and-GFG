#include<bits/stdc++.h>
using namespace std;

int longestCommanSubsequence(string &s1,string &s2){
    int n= s1.size(),m= s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            if(s1[i]==s2[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
            }
            else {
                dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }

    return dp[0][0];

}
int main(){
    string s1="pradejofsdf";
    string s2 = "deandahgpresd";

    cout<<"Longest comman subsequence is : length"<<longestCommanSubsequence(s1,s2);
    return 0;
}