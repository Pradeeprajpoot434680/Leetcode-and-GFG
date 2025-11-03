#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        // code here
        vector<int>adj[n];
        vector<int>inDegree(n,0);
        for(int i=0; i<prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            inDegree[u]++;
            
            adj[v].push_back(u);
        }
        
        queue<int>q;
        for(int i=0; i<inDegree.size(); i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int i=0; i<adj[node].size(); i++){
                inDegree[adj[node][i]]--;
                if(inDegree[adj[node][i]]==0){
                    q.push(adj[node][i]);
                }
            }
        }
        
        return ans;
    }
};

int main(){
    
}