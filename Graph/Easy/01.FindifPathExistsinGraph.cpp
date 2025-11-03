#include <vector>
#include<iostream>  
using namespace std;

class Solution {
public:
    bool dfs(int source, int dest, vector<int> adj[], vector<bool>& visited) {
        if (source == dest) return true; // If source equals destination, we found the path

        visited[source] = true;  // Mark the current node as visited
        for (int neighbor : adj[source]) {
            if (!visited[neighbor]) {  // If the neighbor hasn't been visited
                if (dfs(neighbor, dest, adj, visited)) {
                    return true;  // If we find a path, return true
                }
            }
        }
        return false;  // No path found from source to destination
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        
        // Build the adjacency list
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        return dfs(source, destination, adj, visited);
    }
};



int main() {
    Solution solution;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 3}, {3, 4}};
    int n = 5;
    int source = 0;
    int destination = 4;
    
    bool result = solution.validPath(n, edges, source, destination);
    cout << (result ? "Path exists" : "No path") ;  // Output: Path exists

    return 0;
}
