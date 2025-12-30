#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {

        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();

        long long best = 0;

        
        vector<int> r0, r1, r2;

        for(int x : nums){
            if(x % 3 == 0) r0.push_back(x);
            else if(x % 3 == 1) r1.push_back(x);
            else r2.push_back(x);
        }

        // try patterns
        auto tryTake = [&](vector<int> a, vector<int> b, vector<int> c){
            if(a.size() && b.size() && c.size())
                best = max(best, (long long)a[0] + b[0] + c[0]);
        };

        if(r0.size() >= 3)
            best = max(best, (long long)r0[0] + r0[1] + r0[2]);

        if(r1.size() >= 3)
            best = max(best, (long long)r1[0] + r1[1] + r1[2]);

        if(r2.size() >= 3)
            best = max(best, (long long)r2[0] + r2[1] + r2[2]);

        if(r0.size() >= 1 && r1.size() >= 1 && r2.size() >= 1)
            best = max(best, (long long)r0[0] + r1[0] + r2[0]);

        return best;
    }
};

int main()
{
    
}