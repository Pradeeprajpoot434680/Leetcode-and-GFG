#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int f(int index , vector<int>&arr, vector<int>&dp){
    if(arr.size()==index)return 0;
    if(dp[index]!=-1)return dp[index];
    int pick = arr[index] + f(index+2,arr,dp);
    int notpick = 0 + f(index+1,arr,dp);
    return dp[index] = max(pick,notpick);
}
int Tabulation(vector<int>arr){
    vector<int>dp(arr.size()+1,0);
    dp[arr.size()-1] = arr[arr.size()-1];
    for(int i=arr.size()-2; i>=0; i--){
        dp[i] = max(dp[i+2]+arr[i],dp[i+1]);
    }
    return dp[0];
    
}
int main(){
    vector<int>arr = {1,2,3,1};
    vector<int>dp(arr.size(),-1);   
    cout<<f(0,arr,dp);
    return 0;
}
