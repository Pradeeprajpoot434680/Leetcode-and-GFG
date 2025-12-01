#include<bits/stdc++.h>
using namespace std;

int find(int x, vector<int>& parent, vector<int>& size) {
    if (x == parent[x]) {
        return x;
    }
    return parent[x] = find(parent[x], parent, size);  // Path compression
}

void combine(int u, int v, vector<int>& parent, vector<int>& size) {
    u = find(u, parent, size);
    v = find(v, parent, size);
    
    if (u == v) {
        return;
    }

    if (size[u] > size[v]) {
        parent[v] = u;
        size[u] += size[v];
    } else {
        parent[u] = v;
        size[v] += size[u];
    }
}

int main() {
    int n = 8;
    vector<int> parent(n);
    vector<int> size(n, 1);  // Initialize all sizes to 1

    // Initialize parent array
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    combine(0, 1, parent, size);
    combine(2, 3, parent, size);
    combine(4, 5, parent, size);
    combine(6, 7, parent, size);
    combine(0, 3, parent, size);
    combine(3, 6, parent, size);

    cout << "Parent of 3: " << find(3, parent, size) << endl;
    cout << "Parent of 6: " << find(6, parent, size) << endl;
    cout << "Parent of 7: " << find(7, parent, size) << endl;

    return 0;
}
