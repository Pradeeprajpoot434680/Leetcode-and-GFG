#include<iostream>
#include<vector>
#include<stack>
using namespace std;

 int longestSubarray(vector<int>& arr) {
    // code here
    int ans = 0;
    int n = arr.size();
    vector<int>nextGreaterRight(n,n);
    vector<int>nextGreaterLeft(n,-1);
    stack<int>st;
    for(int i=n-1; i>=0; i--){
        
        while(!st.empty() && arr[st.top()] <= arr[i]){
            st.pop();
        }
        
        if (!st.empty()) {
            nextGreaterRight[i] = st.top(); 
        }
            st.push(i);
    }
    
    while(!st.empty())st.pop();
    for (int i = 0; i < n; i++) {
        
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();  
        }
        
        if (!st.empty()) {
            nextGreaterLeft[i] = st.top();  
        }
        
        st.push(i); 
    }
    
    for(int i=0; i<n; i++){
        int window = nextGreaterRight[i]-nextGreaterLeft[i]-1;
        if(window >= arr[i]){
            ans = max(ans,window);
        }
    }
    
    return ans;
}
int main(){
    vector<int>arr = {1,2,3,4,5};
    cout<<longestSubarray(arr);
    return 0;
}