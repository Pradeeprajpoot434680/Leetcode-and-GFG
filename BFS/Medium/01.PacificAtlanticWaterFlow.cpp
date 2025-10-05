#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<bool>> solve(vector<vector<int>>& heights,int type){
        int n = heights.size();
        int m = heights[0].size();
        queue<pair<int,int>>q;
        vector<vector<bool>>visited(n,vector<bool>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(type==0 && ( i==0 || j==0)){
                    q.push({i,j});
                    visited[i][j]=1;
                }

                if(type==1 && (i==n-1 || j==m-1)){
                    q.push({i,j});
                    visited[i][j]=1;
                }
            }
        }
        int Row[4]={0,0,1,-1};
        int Col[4]={1,-1,0,0};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for(int k=0; k<4; k++){
                int row_ = row + Row[k];
                int col_ = col + Col[k];
                if(row_ >= 0 && col_>=0 && row_ <= n-1 && col_ <= m-1 && !visited[row_][col_] && heights[row_][col_]>=heights[row][col]){
                    visited[row_][col_]=1;
                    q.push({row_,col_});
                }
            }
        }
        return visited;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>>visited1,visited2;
        visited1 = solve(heights,0);
        visited2 = solve(heights,1);

        vector<vector<int>>ans;
        for(int i=0; i<heights.size(); i++){
            for(int j=0; j<heights[0].size(); j++){
                if(visited1[i][j] && visited2[i][j]){
                    ans.push_back({i,j});
                } 
            }
        }

        return ans;
    }


};

int main(){
    Solution s;
    vector<vector<int>>heights={{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
     vector<vector<int>> ans = s.pacificAtlantic(heights);
     for(int i=0; i<ans.size(); i++){
        cout<<ans[i][0]<<","<<ans[i][1]<<endl;
     }
}