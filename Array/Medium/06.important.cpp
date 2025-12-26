#include<bits/stdc++.h>
using namespace std;

// Sum of permutations gfg


class Solution {
public:
    int getSum(vector<int>& arr) {
        const long long MOD = 1000000007;
        int n = arr.size();

        long long sum = 0;
        for(int x : arr) 
            sum = (sum + x) % MOD;

        long long fact = 1;              
        for(int i = 1; i < n; i++)
            fact = (fact * i) % MOD;

        long long ones = 0;            
        long long p10 = 1;
        for(int i = 0; i < n; i++){
            ones = (ones + p10) % MOD;
            p10 = (p10 * 10) % MOD;
        }

        return (sum * fact % MOD * ones) % MOD;
    }
};


int main(){
    Solution sol;
    vector<int> arr = {1, 2, 3};
    cout << sol.getSum(arr) << endl;
    return 0;
}