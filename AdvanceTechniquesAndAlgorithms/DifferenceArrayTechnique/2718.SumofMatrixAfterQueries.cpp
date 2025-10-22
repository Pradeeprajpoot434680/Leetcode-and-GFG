#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        vector<bool> rowDone(n, false), colDone(n, false);
        long long ans = 0;
        long long doneRows = 0, doneCols = 0;

        for (int i = queries.size() - 1; i >= 0; i--) {
            int type = queries[i][0];
            int index = queries[i][1];
            int val = queries[i][2];

            if (type == 0) {
                if (!rowDone[index]) {
                    ans += 1LL * (n - doneCols) * val;
                    rowDone[index] = true;
                    doneRows++;
                }
            } else {
                if (!colDone[index]) {
                    ans += 1LL * (n - doneRows) * val;
                    colDone[index] = true;
                    doneCols++;
                }
            }
        }

        return ans;
    }
};


int main(){
    Solution sol;
    int n = 3;
    vector<vector<int>> queries = {{0,0,1},{1,2,2},{0,2,3},{1,0,4}};
    long long result = sol.matrixSumQueries(n, queries);
    cout << "Sum of Matrix after Queries: " << result << endl;
    return 0;
}