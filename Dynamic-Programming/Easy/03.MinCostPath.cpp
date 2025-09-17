#include<iostream>
#include<vector>
using namespace std;
int n,m;
int f(int i,int j,vector<vector<int>>arr){
    if(i>=n || j>=m){
        return 1e7;
    }
    if(i==n-1 && j==m-1)return arr[i][j];

    int right = f(i,j+1,arr);
    int down = f(i+1,j,arr);
    int dia = f(i+1,j+1,arr);

    return arr[i][j] + min(right,min(down,dia));
}

void Tabulation(vector<vector<int>>arr){
    vector<vector<int>>dp(n,vector<int>(m,0));
    dp[n-1][m-1] = arr[n-1][m-1];
    for(int i=n-2; i>=0; i--){
        dp[i][m-1] = dp[i+1][m-1] + arr[i][m-1];
    }
    for(int j=m-2; j>=0; j--){
        dp[n-1][j] = dp[n-1][j+1] + arr[n-1][j];
    }
    for(int i=n-2; i>=0; i--){
        for(int j=m-2; j>=0; j--){
            dp[i][j] = arr[i][j] + min(dp[i+1][j],min(dp[i][j+1],dp[i+1][j+1]));
        }
    }
    cout<<dp[0][0];
}
int main(){
    vector<vector<int>>arr = {{1,2,3},{4,8,2},{1,5,3}};
    n = arr.size();
    m = arr[0].size();
    // cout<<f(0,0,arr);
    Tabulation(arr);
    return 0;
}