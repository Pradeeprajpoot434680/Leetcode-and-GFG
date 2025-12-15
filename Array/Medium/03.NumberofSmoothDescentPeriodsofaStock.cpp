#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        long long len = 1;  

        for (int i = 0; i < prices.size(); i++) {
            if (i > 0 && prices[i-1] == prices[i] + 1) {
                len++;
            } else {
                len = 1;
            }
            ans += len;
        }

        return ans;
    }
};


int main(){
    Solution sol;
    vector<int> prices = {3,2,1,4};
    cout << sol.getDescentPeriods(prices) << endl; // Output the result
    return 0;
}