
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int node,vector<vector<int>>& rooms,vector<bool>&visited){
        visited[node]=1;

        for(int i=0; i<rooms[node].size(); i++){
            int neighbour = rooms[node][i];
            if(!visited[neighbour]){
                dfs(neighbour,rooms,visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>visited(n,0);
        visited[0]=1;
        dfs(0,rooms,visited);
        for(int i=0; i<n; i++){
            if(!visited[i])return 0;
        }

        return 1;
    }
};


int main() {
    Solution solution;
    vector<vector<int>> rooms = {{1}, {2}, {3}, {0, 4}, {5}, {}};
    
    bool result = solution.canVisitAllRooms(rooms);
    cout << (result ? "Yes" : "No") << endl;  // Output: Yes
    
    return 0;
}