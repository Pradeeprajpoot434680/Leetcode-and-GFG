#include <iostream>
#include <vector>
using namespace std;
/*
class Solution {
public:
    void DFS(int node, vector<bool>& visited, vector<int> adj[], vector<int>& temp) {
        visited[node] = 1;
        temp.push_back(node);
        for (int i = 0; i < adj[node].size(); i++) {
            if (!visited[adj[node][i]]) {
                DFS(adj[node][i], visited, adj, temp);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<bool> visited(n, 0);
        vector<vector<int>> ans;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            if (!visited[i]) {
                DFS(i, visited, adj, temp);
                ans.push_back(temp);
            }
        }

        for (auto& component : ans) {
            bool isComplete = true;
            for (int node : component) {
                if (adj[node].size() != component.size() - 1) {
                    isComplete = false;
                    break;
                }
            }
            if (isComplete) count++;
        }

        return count;
    }
};

*/
class Solution {
public:
    void DFS(int node, vector<bool>& visited, vector<int> adj[], int& nodes, int& edges) {
        visited[node] = true;
        nodes++; 
        edges += adj[node].size(); 
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                DFS(neighbor, visited, adj, nodes, edges);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int nodes = 0;
                int edges = 0;
                DFS(i, visited, adj, nodes, edges);

               
                if (edges / 2 == (nodes * (nodes - 1)) / 2) {
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {
    Solution solution;

    // Example test case
    int n = 6;  // Number of nodes
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {3, 4}, {4, 5}, {5, 3}};  // Edges between nodes

    // Count complete components in the graph
    int result = solution.countCompleteComponents(n, edges);

    // Output the result
    cout << "Number of complete components: " << result << endl;

    return 0;
}
