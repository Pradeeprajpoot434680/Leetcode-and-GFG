#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    /*
    int usingBitset(vector<vector<int>>& mat, int target){
        bitset<4901>p(1);//value of p = 1
        for(auto row:mat){
            bitset<4901>pp;
            for(int col:row){
                pp |= (p<<col);
            }
            swap(p,pp);
        }
        int ans=INT_MAX;
        for(int i=0; i<=4900; i++){
           if(p[i]){
            ans =min(ans,abs(i-target));
           }
        }

        return ans;
    }*/

    int row,col;
    int solve(vector<vector<int>>& mat, int target,int sum,int r,vector<vector<int>>&dp){
        if(r==row){
            return abs(target-sum);
        }
        if(dp[r][sum] != -1)return dp[r][sum];
        int ans  = INT_MAX;

        for(int j=0; j<col; j++){
            ans = min(ans,solve(mat,target,sum+mat[r][j],r+1,dp));
        }

        return  dp[r][sum]= ans;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        row = mat.size();
        col = mat[0].size();
        vector<vector<int>>dp(71,vector<int>(4901,-1));
        return solve(mat,target,0,0,dp);

    }
};


