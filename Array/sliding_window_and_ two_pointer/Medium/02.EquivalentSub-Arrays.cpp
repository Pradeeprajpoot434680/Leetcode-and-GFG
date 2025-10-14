#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int countDistinctSubarray(int arr[], int n) {
        // code here.
        int ans=0;
        int start=0;
        int end = 0;
        unordered_set<int>s;
        for(int i=0; i<n; i++){
            s.insert(arr[i]);
        }
        // int ans=0;
        int dist = s.size();
        int curr =0;
        unordered_map<int,int>m;
        while(end < n){
            if(m[arr[end]]==0){
                curr++;
            }
            
            m[arr[end]]++;
            
            while(curr == dist){
                ans += n-end;
                m[arr[start]]--;
                if(m[arr[start]] == 0){
                    curr--;
                }
                   
                start++;
               
            }
          
                end++;
            
            
        }
        
        return ans;
    }
};

int main(){
    Solution sol;
    int arr[] = {1,2,1,3,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = sol.countDistinctSubarray(arr,n);
    cout << result << endl;
}