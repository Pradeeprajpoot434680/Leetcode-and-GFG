#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
        int n;
    vector<vector<vector<int>>> dp;

    int solve(vector<vector<int>>& mat, int r1, int c1, int r2) {
        int c2 = r1 + c1 - r2;
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n ||
            mat[r1][c1] == -1 || mat[r2][c2] == -1)
            return INT_MIN;

        if (r1 == n - 1 && c1 == n - 1)
            return mat[r1][c1];

        if (dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];

        int curr = mat[r1][c1];
        if (r1 != r2 || c1 != c2)
            curr += mat[r2][c2];

        int ans = max({
            solve(mat, r1 + 1, c1, r2 + 1),   // down, down
            solve(mat, r1, c1 + 1, r2),       // right, right
            solve(mat, r1 + 1, c1, r2),       // down, right
            solve(mat, r1, c1 + 1, r2 + 1)    // right, down
        });

        if (ans == INT_MIN)
            return dp[r1][c1][r2] = INT_MIN;

        return dp[r1][c1][r2] = curr + ans;
    }

    int chocolatePickup(vector<vector<int>>& mat) {
        n = mat.size();
        dp.assign(n, vector<vector<int>>(n, vector<int>(n, -1)));

        int result = solve(mat, 0, 0, 0);
        return result < 0 ? 0 : result;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        return chocolatePickup(grid);
    }
};

