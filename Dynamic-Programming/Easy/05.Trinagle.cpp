#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int>lower(n,0),curr(n,0);
    for(int j=0; j<n; j++)
    {
        lower[j] = triangle[n-1][j];
    }

    for(int i = n-2; i>=0; i--)
    {
        for(int j=i; j>=0; j--)
        {
            int d = triangle[i][j] + lower[j];
            int dg = triangle[i][j] + lower[j+1];
            curr[j] = min(d,dg);
        }
        lower = curr;
    }
    return lower[0];
    }
};
int main(){
    Solution s;
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout<<s.minimumTotal(triangle);
    return 0;
}