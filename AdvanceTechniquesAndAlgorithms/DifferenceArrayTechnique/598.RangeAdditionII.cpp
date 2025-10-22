#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        //vector<vector<int>>arr(m,vector<int>(n,0));
        if(ops.size()==0)return 1l*m*n;
        int xMin=INT_MAX,yMin=INT_MAX;
        for(int i=0; i<ops.size(); i++){
            xMin = min(xMin,ops[i][0]);
            yMin = min(yMin,ops[i][1]);
        }

        return (int)(1L*(xMin)*(yMin));
    }
};

int main(){
    Solution sol;
    int m = 3, n = 3;
    vector<vector<int>> ops = {{2,2},{3,3}};
    int result = sol.maxCount(m, n, ops);
    cout << "Maximum Count of Elements after Range Additions: " << result << endl;
    return 0;
}