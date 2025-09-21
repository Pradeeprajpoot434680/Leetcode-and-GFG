#include<iostream>
#include<vector>
#include<stack>
using namespace std;


int largestRectangleArea(vector<int>& heights) {
int n = heights.size();
vector<int>v1(n,n);
vector<int>v2(n,-1);
stack<int>st;
for(int i=0; i<n; i++)
{
    while(!st.empty() && heights[i] < heights[st.top()])
    {
        v1[st.top()] = i;
        st.pop();
    }
    st.push(i);
}
while(!st.empty())
{
    st.pop();
}
for(int i=n-1; i>=0; i--)
{
    while(!st.empty() && heights[i] < heights[st.top()])
    {
        v2[st.top()] = i;
        st.pop();
    }
    st.push(i);
}
int ans = 0;
for(int i=0; i<n; i++)
{
    int width = v1[i]-v2[i]-1;
    int area = heights[i]*width;
    ans = max(ans,area);
}
return ans;
}
int maxArea(vector<vector<int>> &mat) {
// code here
int ans=0;
int n = mat.size();
int m = mat[0].size();
vector<int>prev,curr;
ans = max(ans,largestRectangleArea(mat[0]));
prev = mat[0];

for(int i=1; i<n; i++){
    curr = mat[i];
    for(int  j=0; j<m; j++){
        if(mat[i][j]==1){
            curr[j] = curr[j] + prev[j];

        }
        
    }
    ans = max(ans,largestRectangleArea(curr));
    prev = curr;
    
    
}

    return ans;

}

int main(){
    vector<vector<int>>mat = {{0,1,1,0},{1,1,1,1},{1,1,1,0},{1,1,0,0}};
    cout<<maxArea(mat);
    return 0;
}