#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        sort(arr.begin(),arr.end());
        vector<int>ans;
        
        for(int i=0; i<queries.size(); i++){
            int left = queries[i][0];
            int right = queries[i][1];
            
            int index1 = lower_bound(arr.begin(),arr.end(),left) - arr.begin();
            int index2 = upper_bound(arr.begin(),arr.end(),right) - arr.begin();
            
            ans.push_back(index2 - index1);
        }
        
        return ans;
    }
};

int main(){
    
}