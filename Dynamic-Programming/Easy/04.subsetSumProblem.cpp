#include<iostream>
#include<vector>
using namespace std;


int f(int index,int sum,int target,vector<int>arr, vector<vector<int>>&dp){
    if(index>=arr.size())return 0;
    if(sum==target)return 1;
    if(sum>target)return 0;


    bool pick = f(index+1,sum+arr[index],target,arr,dp);
    bool not_pick = f(index+1,sum,target,arr,dp);


    // return dp[][] = pick || not_pick;
}


int main(){
    vector<int>arr = {2,3,5,6,8,10};
    int target = 10;
    vector<vector<int>>dp(arr.size()+1,vector<int>(target+1,-1));
    cout<<f(0,0,target,arr,dp);
    return 0;
}