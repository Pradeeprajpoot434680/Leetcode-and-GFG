#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> parent, size;

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);   
    }

    bool Union(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);

        if (root_u == root_v) return true;   

        // union by size
        if (size[root_u] > size[root_v]) {
            parent[root_v] = root_u;
            size[root_u] += size[root_v];
        } else {
            parent[root_u] = root_v;
            size[root_v] += size[root_u];
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        size.assign(n+1, 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            if (Union(u, v))
                return e;  
        }
        return {};
    }
};
