#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
   int f(int index,int buy,int k,vector<int> &prices,  vector<vector<vector<int>>>&dp)
    {
        if(index==prices.size())return 0;
        if(k==0)return 0;
        if(dp[index][buy][k] != -1)return dp[index][buy][k];
        int profit = 0;
        
        if(buy)
        {
            profit = max(-prices[index]+f(index+1,0,k,prices,dp),0+f(index+1,1,k,prices,dp));
        }else
        {
            profit = max(prices[index] + f(index+1,1,k-1,prices,dp),f(index+1,0,k,prices,dp));
        }
        
        return dp[index][buy][k] = profit;
        
    }
    int maxProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,2,prices,dp);
    }
int main(){
    std::vector<int>prices={7,1,5,3,6,4};
    std::cout<<maxProfit(prices);
    // cout<<maxProfileTabulation(prices);
    return 0;
}