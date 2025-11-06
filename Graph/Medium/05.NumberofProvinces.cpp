#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int node, int parent, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[node] = 1;

        for (int i = 0; i < isConnected.size(); i++) {
            if (i == node || i == parent || isConnected[node][i] == 0) continue;

            if (!visited[i]) {
                dfs(i, node, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;
        vector<bool> visited(n, 0);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans++;
                dfs(i, -1, isConnected, visited);
            }
        }

        return ans;
    }
};

int main() {
    // Example input: a 3x3 matrix representing the isConnected graph.
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    Solution sol;
    int result = sol.findCircleNum(isConnected);

    cout << "Number of provinces: " << result << endl;  // Expected output: 2

    return 0;
}
