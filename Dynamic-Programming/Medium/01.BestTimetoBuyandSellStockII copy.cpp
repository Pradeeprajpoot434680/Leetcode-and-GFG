#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int f(int index,bool buy,vector<int>&prices, vector<vector<int>>&dp){
    if(index==prices.size()){
        return 0;
    }
    if(dp[index][buy]!=-1)return dp[index][buy];

    int ans = 0;
    if(buy){
        ans = max(-prices[index]+f(index+1,0,prices,dp),f(index+1,1,prices,dp));
    }
    else
    {
        ans = max(prices[index]+f(index+1,1,prices,dp),f(index+1,0,prices,dp));
    }

    return dp[index][buy] = ans;
}
int maxProfit(vector<int>& prices) {
    vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
    return f(0,1,prices,dp);   
}

int maxProfileTabulation(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>>dp(n+1,vector<int>(2,0));

    for(int index=n-1;index>=0;index--){
        for(int buy=0;buy<=1;buy++){
            int ans = 0;
            if(buy){
                ans = max(-prices[index]+dp[index+1][0],dp[index+1][1]);
            }
            else
            {
                ans = max(prices[index]+dp[index+1][1],dp[index+1][0]);
            }
            dp[index][buy] = ans;
        }
    }

    return dp[0][1];   
}
int main(){
    std::vector<int>prices={7,1,5,3,6,4};
    std::cout<<maxProfit(prices);
    cout<<maxProfileTabulation(prices);
    return 0;
}