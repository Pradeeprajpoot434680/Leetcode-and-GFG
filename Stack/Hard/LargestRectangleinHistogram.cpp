#include<iostream>
using namespace std;
#include<vector>
#include<stack>

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


    int main(){
        vector<int>heights = {2,1,5,6,2,3};
        cout<<largestRectangleArea(heights);
        return 0;
    }