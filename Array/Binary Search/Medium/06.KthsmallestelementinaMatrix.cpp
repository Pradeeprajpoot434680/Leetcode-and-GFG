#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countSmallOrEqualEle(vector<vector<int>>&mat,int x){
        int row = 0;
        int n = mat.size();
        int col = mat[0].size()-1;
        int count=0;
        while(row < n && col >=0){
            if(mat[row][col] <= x){
                count+= (col+1);
                row++;
            }
            else {
                col--;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int start = mat[0][0];
        int end = mat[n-1][m-1];
        int ans = mat[n-1][m-1];
        while(start <= end){
            int mid = start + (end - start)/2;
            
            if(countSmallOrEqualEle(mat,mid) >= k){
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid+1;
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    int k = 8;
    cout << sol.kthSmallest(mat, k) << endl; // Output: 13
    return 0;
}
