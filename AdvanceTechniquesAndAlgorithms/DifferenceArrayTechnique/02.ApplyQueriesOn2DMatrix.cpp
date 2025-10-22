#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<vector<int>> applyQueries(int n, int m, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n, vector<int>(m, 0));

        for (const auto& query : queries) {
            int x = query[0], y = query[1];
            int inc = query[2];
           
            
            for(int i=0; i<y; i++){
                if(i+1 < m)
                diff[0][i]+=inc;
                if(x+1 < n)
                diff[x][i]-=inc;
               
            }
            
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                diff[i][j] += diff[i][j - 1];
            }
        }



        return diff;
    }

};

int main(){
    Solution sol;
    int n = 3, m = 3;
    vector<vector<int>> queries = {{2,2,5},{1,1,7},{3,3,1}}; // {x,y,incValue}
    vector<vector<int>> result = sol.applyQueries(n, m, queries);

    cout << "Resultant Matrix after applying Queries:" << endl;
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}