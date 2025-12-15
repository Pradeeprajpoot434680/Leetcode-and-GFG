#include<bits/stdc++.h>
using namespace std;

class Solution {
    
  public:
    bool helper(int sum1 ,int sum2,vector<int>&b){
        int  n = b.size();
        
        int start = 0;
        int end = n-1;
        
        while(start <= end){
            int mid = start + (end - start)/2;
            
            int midEle = b[mid];
            
            int aSum = sum1 + midEle;
            int bSum = sum2 - midEle;
            
            if(aSum == bSum){
                return 1;
            }
            else if(aSum < bSum){
                start = mid+1;
            }
            else {
                end = mid - 1;
            }
        }
        
        return 0;
    }
    bool findSwapValues(vector<int>& a, vector<int>& b) {
        // Your code goes here
        int n1 = a.size();
        int n2 = b.size();
        
        sort(b.begin(),b.end());
        int sum1 = 0, sum2 = 0;
        
        for(int i:a)sum1+=i;
        for(int i:b)sum2+=i;
        
        for(int i=0; i<n1; i++){
            int x = sum1- a[i];
            int y = sum2 + a[i];
            
            if(x >= y)continue;
            if(helper(x,y,b)){
                return 1;
            }
        }
        
        
        return 0;
        
    }
};

int main(){
    Solution sol;
    vector<int> a = {4, 1, 2, 1, 1, 2};
    vector<int> b = {3, 6, 3, 3};
    cout << (sol.findSwapValues(a, b) ? "True" : "False") << endl; // Output the result
    return 0;
}