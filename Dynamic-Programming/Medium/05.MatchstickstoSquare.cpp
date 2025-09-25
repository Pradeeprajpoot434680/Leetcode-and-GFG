#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<string,bool> memo;

    string makeKey(int idx, vector<int>& sides){
        return to_string(idx) + "|" + to_string(sides[0]) + "|" + to_string(sides[1]) + "|" + to_string(sides[2]) + "|" + to_string(sides[3]);
    }
    bool f(int idx,vector<int>&matchsticks,vector<int>&sides){
        if(idx == matchsticks.size()){
            return sides[0]==0 && sides[1]==0 && sides[2]==0 && sides[3]==0;
        }
            string key = makeKey(idx, sides);
            if(memo.count(key)) return memo[key];

        for(int i=0; i<4; i++){
            if(matchsticks[idx] > sides[i])continue;

            sides[i]-=matchsticks[idx];
            if(f(idx+1,matchsticks,sides))return memo[key]=1;
             sides[i]+=matchsticks[idx];
        }

        return memo[key] = 0;
    }
    bool makesquare(vector<int>& matchsticks) {
        int n=matchsticks.size();
        sort(matchsticks.begin(),matchsticks.end());
        if(n<4)return 0;
        int sum=0;
        for(int i:matchsticks){
            sum+=i;
        }
        if(sum%4 != 0)return 0;
         memo.clear();
        int target = sum/4;
        vector<int>sides(4,target);
        return f(0,matchsticks,sides);
    }
};


//using sorting and without memoization and backtracking
class Solution {
public:
    // unordered_map<string,bool> memo;

    // string makeKey(int idx, vector<int>& sides){
    //     return to_string(idx) + "|" + to_string(sides[0]) + "|" + to_string(sides[1]) + "|" + to_string(sides[2]) + "|" + to_string(sides[3]);
    // }
    bool f(int idx,vector<int>&matchsticks,vector<int>&sides){
        if(sides[0]<0 || sides[1]<0 || sides[2]<0 || sides[3]<0)return 0;
        if(idx == matchsticks.size()){
            return sides[0]==0 && sides[1]==0 && sides[2]==0 && sides[3]==0;
        }
            // string key = makeKey(idx, sides);
            // if(memo.count(key)) return memo[key];

        for(int i=0; i<4; i++){
            if(matchsticks[idx] > sides[i])continue;

            sides[i]-=matchsticks[idx];
            if(f(idx+1,matchsticks,sides))return 1;
             sides[i]+=matchsticks[idx];
        }

        return   0;
    }
    bool makesquare(vector<int>& matchsticks) {
        int n=matchsticks.size();
        sort(matchsticks.rbegin(),matchsticks.rend());
        if(n<4)return 0;
        int sum=0;
        for(int i:matchsticks){
            sum+=i;
        }
        if(sum%4 != 0)return 0;
        //  memo.clear();
        int target = sum/4;
        vector<int>sides(4,target);
        return f(0,matchsticks,sides);
    }
};