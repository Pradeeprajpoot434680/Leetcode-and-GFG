#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isPalindrom(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }

    int solve(int i, string &s, vector<int> &dp) {
        if (i >= (int)s.size()) return 0;   // no more chars → 0 pieces

        if (dp[i] != -1) return dp[i];

        int ans = INT_MAX;

        for (int j = i; j < (int)s.size(); j++) {
            if (isPalindrom(s, i, j)) {
                int temp = 1 + solve(j + 1, s, dp);  // 1 piece + rest
                ans = min(ans, temp);
            }
        }

        return dp[i] = ans;
    }

    int palPartition(string &s) {
        int n = s.size();
        vector<int> dp(n, -1);

        int pieces = solve(0, s, dp);
        return (pieces == 0 ? 0 : pieces - 1);
    }
};

