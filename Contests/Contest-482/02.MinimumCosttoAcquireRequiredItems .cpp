#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = (long long)cost1;
        long long c2 = (long long)cost2;
        long long cb = (long long)costBoth;
        long long n1 = (long long)need1;
        long long n2 = (long long)need2;

        // Scenario 1: Only single items
        long long opt1 = n1 * c1 + n2 * c2;

        // Scenario 2: Combo items for the minimum requirement, then singles
        long long minN = min(n1, n2);
        long long remainingNeed = max(n1, n2) - minN;
        long long remainingCost = (n1 > n2) ? c1 : c2;
        long long opt2 = minN * cb + remainingNeed * remainingCost;

        // Scenario 3: Combo items for the maximum requirement
        long long opt3 = max(n1, n2) * cb;

        return min({opt1, opt2, opt3});
    }
};



int main(){
    Solution sol;
    cout << sol.minimumCost(50, 55, 72, 5, 3) << endl;
    return 0;
}